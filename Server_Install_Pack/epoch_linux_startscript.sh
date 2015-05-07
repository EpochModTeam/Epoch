#!/bin/bash
# armaserver: ArmA 3 Linux Dedicated Server Control Script
#
# original was:
# armaserver: ArmA 2 Linux Dedicated Server Control Script
#  (c) 2010 BIStudio
#  ArmA 2 binary version must be 1.04 or later
#
##
### modified by Nasdero
### V 1.01 - 28.03.2015
### added BEPATH and changed handling of logfiles in ${ARMA_DIR}
#### modified by [VB]AWOL for Official Epoch Linux Support
#=======================================================================
#========               CONFIGURATION PARAMETERS                ========
#======== MUST BE EDITED MANUALLY TO FIT YOUR SYSTEM PARAMETERS ========
#=======================================================================
export LD_LIBRARY_PATH=.:$HOME/epoch:$HOME/epoch/@epochhive:$LD_LIBRARY_PATH;
ARMA_DIR=/home/arma3
PORT=2302
NAME=sc
#NAME= your game name, if you run a Team Death Match server Name=tdm
#but you need a folder called tdm in the ${CFG_DIR} folder
#run the "check" parameter on this file here, it will give you all infos
DELDAYS=7
#DELDAYS=7 => old logfiles will be deleted after 7 days
#
OTHERPARAMS="-maxMem=2047 -nosound -exthreads=1 -noCB -autoinit -loadMissionToMemory"
# sample in the next row
#OTHERPARAMS="-cpucount=4 -maxMem=2047 -nosound -exthreads=1 -noCB"
#MODS=
# sample in the next row
#MODS=@CBA_A3\;@tmr_alt\;@a3mp
MODS=@epoch
SERVERMODS=@epochhive
#=======================================================================
# !!!!!!!!!! DO NOT EDIT ANYTHING BELOW THIS LINE !!!!!!!!!!
#=======================================================================
CFG_DIR=${ARMA_DIR}
CONFIG=${CFG_DIR}/${NAME}/config.cfg
CFG=${CFG_DIR}/${NAME}/basic.cfg
LOG_DIR=${ARMA_DIR}/logs
BEPATH=${CFG_DIR}/${NAME}/battleye/
#PROFILES= not working on linux as far as I know, arma 3 uses Player
#what ever we try until now, don't use -profiles= in startcmd !!!!!
#PROFILES=${CFG_DIR}/${NAME}
PROFILES=${NAME}
PIDFILE=${ARMA_DIR}/${PORT}.pid
RUNFILE=${ARMA_DIR}/${PORT}.run
LOGFILE=${LOG_DIR}/port_${PORT}.`date +%d.%m.%y_%H%M`.log
SERVER=${ARMA_DIR}/arma3server
#=======================================================================
ulimit -c 1000000
 
case "$1" in
 
 
start)
# check if there is a server running or not
ps ax | grep ${SERVER} | grep ${PORT}  > /dev/null
if [ $? -eq 0 ]; then
echo -e "\033[31mThere is a Server already running (${SERVER} at Port ${PORT})\033[0m"
echo -e "\033[31mIt can happen, when you started a Server and stopped it to fast!\033[0m"
echo -e "\033[31mJust stop the Server again and it should be good to start!\033[0m"
echo $output | ps ax | grep ${SERVER} | grep ${PORT}
else
echo -e "Starting A3 server @PORT \033[35m${PORT}\033[0m..."
# file to mark we want server running...
echo "go" >${RUNFILE}
# launch the background watchdog process to run the server
nohup </dev/null >/dev/null $0 watchdog &
fi
;;
 
stop)
echo -e "Stopping A3 server if there is one (Port=\033[35m${PORT}\033[0m)..."
if [ -f ${RUNFILE} ]; then
# ask watcher process to exit by deleting its runfile...
rm -f ${RUNFILE}
else
echo -e "\033[31mThere is no runfile (${RUNFILE}), Server shouldn't be up, will shut it down if it is up!\033[0m"
fi
# and terminate ArmA 3 server process
if [ -f ${PIDFILE} ]; then
kill -TERM $(< ${PIDFILE})
if [ -f ${PIDFILE} ]; then
rm -f ${PIDFILE}
fi
fi
;;
 
status)
if [ -f ${RUNFILE} ]; then
echo -e "\033[32mRunfile exist, Server should be up or is starting...\033[0m"
echo -e "\033[35mIf the Server is \033[31mnot done\033[35m with its start, you will \033[31mnot get\033[35m a PID file info in the next rows.\033[0m"
echo -e "\033[35mIf the Server is \033[32mdone\033[35m with its start, you will \033[32mget\033[35m a PID file and process info in the next rows.\033[0m"
else
echo -e "\033[31mRunfile doesn't exist, Server should be down or is going down...\033[0m"
fi
if [ -f ${PIDFILE} ]; then
PID=$(< ${PIDFILE})
echo -e "\033[32mPID file exists (PID=\033[35m${PID}\033[0m)..."
if [ -f /proc/${PID}/cmdline ]; then
echo -e "\033[32mServer process seems to be running...\033[0m"
echo $output | ps ax | grep ${SERVER} | grep ${PORT}
fi
fi
;;
 
restart)
$0 stop
sleep 5s
$0 start
;;
 
watchdog)
# zip old logfile and move it to old directory
cd ${LOG_DIR}
if [ -f port_${PORT}*.log ]; then
for i in port_${PORT}*.log; do tar -cvzf $i.tgz $i; rm $i; done
mv port_${PORT}*.tgz old/
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Zipping logfiles from ${LOG_DIR} to ${LOG_DIR}/old"
else
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] No old logfile to zip in ${LOG_DIR}"
fi
 
# zip old logfiles and move them to old directory
cd ${ARMA_DIR}
if  find ./*.log -type f; then
for i in *.log; do tar -cvzf $i.`date +%d.%m.%y_%H%M`.tgz $i; rm $i; done
mv *.tgz log ${LOG_DIR}/old
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Zipping logfiles from ${ARMA_DIR} to ${LOG_DIR}/old"
else
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] No old logfiles to zip in ${ARMA_DIR}"
fi
 
# delete old logs when older then ${DELDAYS} days
find ${LOG_DIR}/old -iname "*log.tgz" -mtime +${DELDAYS} -delete
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Deleting all zipped logfile in ${LOG_DIR}/old when older then ${DELDAYS} days."
 
# this is a background watchdog process. Do not start directly
while [ -f ${RUNFILE} ]; do
# launch the server...
cd ${ARMA_DIR}
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Starting server (port ${PORT})..."
export LD_LIBRARY_PATH=.:${ARMA_DIR}:${ARMA_DIR}/@epochhive:$LD_LIBRARY_PATH
 
${SERVER} >>${LOGFILE} 2>&1 -config=${CONFIG} -cfg=${CFG} -port=${PORT} -name=${NAME} -pid=${PIDFILE} -mod=${MODS} -servermod=${SERVERMODS}  -bepath=${BEPATH} ${OTHERPARAMS}
 
if [ -f ${RUNFILE} ]; then
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Server died, waiting to restart..."
sleep 5s
else
echo >>${LOGFILE} "WATCHDOG ($$): [$(date)] Server shutdown intentional, watchdog terminating"
fi
done
;;
 
check)
clear
echo -ne "\033[33mArmA 3 directory:\033[0m ${ARMA_DIR} "
if [ -d ${ARMA_DIR} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= Check your settings (ARMA_DIR)! =========\n"
fi
 
echo -ne "\033[33mServer executable:\033[0m ${SERVER} "
if [ -x ${SERVER} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= Server executable not found, arma3server should be in that folder when path is right =========\n"
fi
 
echo -ne "\033[33mCFG directory:\033[0m ${CFG_DIR}/${NAME} "
if [ -d ${CFG_DIR}/${NAME} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need that folder for the config files! You can use the next row to create it: ========="
echo -e "\033[35mmkdir ${CFG_DIR}/${NAME}\033[0m\n"
fi
 
echo -ne "\033[33mConfig file:\033[0m ${CONFIG} "
if [ -f ${CONFIG} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need this file in that folder =========\n"
fi
 
echo -ne "\033[33mBasic file:\033[0m ${CFG} "
if [ -f ${CFG} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need this file in that folder =========\n"
fi
 
echo -ne "\033[33mBattleye directory:\033[0m ${BEPATH} "
if [ -d ${BEPATH} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need that folder for the Battleye files! You can use the next row to create it: ========="
echo -e "\033[35mmkdir ${BEPATH}\033[0m\n"
fi
 
echo -ne "\033[33mArma3Profile:\033[0m ${CFG_DIR}/${NAME}/users/${NAME}/${NAME}.arma3profile "
if [ -f ${CFG_DIR}/${NAME}/users/${NAME}/${NAME}.arma3profile ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need that file! You can create it like this, edit it then for your need later: ========="
echo -e "========= ( https://community.bistudio.com/wiki/Arma_3_Dedicated_Server) ****.Arma3Profile  =========\033[35m"
echo -n 'echo -e "version=2;\nviewDistance=3000;\npreferredObjectViewDistance=3000;\nterrainGrid=12.5;\nactiveKeys[]=\n{\n};" > '
echo -n "${CFG_DIR}/${NAME}/users/${NAME}/${NAME}.arma3profile"
echo -e "\n\033[0m"
fi
 
echo -ne "\033[33mLog directory:\033[0m ${LOG_DIR} "
if [ -d ${LOG_DIR} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need that folder. You can use the next row to create it: ========="
echo -e "\033[35mmkdir ${LOG_DIR}\033[0m\n"
fi
 
echo -ne "\033[33mOld Log directory:\033[0m ${LOG_DIR}/old "
if [ -d ${LOG_DIR}/old ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= We need that folder. You can use the next row to create it: ========="
echo -e "\033[35mmkdir ${LOG_DIR}/old\033[0m\n"
fi
 
echo -ne "\033[33mProfile directory:\033[0m ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME} "
if [ -d ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME} ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= You should create this folder. You can use the next row for that: ========="
echo -e "=========       ( Not sure if we need this? Capital letters are ok ?)       ========="
echo -e "\033[35mmkdir -p ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME}\033[0m\n"
fi
 
echo -ne "\033[33mArma3Profile symlink:\033[0m ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME}/${NAME}.Arma3Profile "
if [ -L ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME}/${NAME}.Arma3Profile ]; then
echo -e "\033[32mOK\033[0m"
else
echo -e "\033[31mMISSING!\033[0m"
echo -e "========= You should creat this symlink. You can use the next row for that: ========="
echo -e "=========       ( Capital letters are ok in ~/.local/share/Arma 3.. !)      ========="
echo -e "\033[35mln -s ${CFG_DIR}/${NAME}/${NAME}.arma3profile ~/.local/share/Arma\ 3\ -\ Other\ Profiles/${NAME}/${NAME}.Arma3Profile\033[0m\n"
fi
 
echo -e "\n\033[33mPort number will be: \033[0m${PORT}"
echo -e "\033[33mPID file will be: \033[0m${PIDFILE}"
echo -e "\033[33mRUN file will be: \033[0m${RUNFILE}"
 
echo -e "\n\033[33mStart cmd will be:\033[0m"
echo -e "${SERVER} >>${LOGFILE} 2>&1 -config=${CONFIG} -cfg=${CFG} -port=${PORT} -name=${NAME} -pid=${PIDFILE} -mod=${MODS} ${OTHERPARAMS}"
 
echo -e "\n\033[31mIf you got something MISSING, you have to work from the top to the bottom, fix the top issue and start the check again!\033[0m"
;;
 
log)
# you can see the logfile in realtime, no more need for screen or something else
clear
echo "To stop viewing the logfile press CTRL+C"
echo "========================================"
sleep 1s
tail -f ${LOG_DIR}/port_${PORT}*.log
;;
 
*)
echo "$0 (start|stop|restart|status|check|log)"
;;
esac
