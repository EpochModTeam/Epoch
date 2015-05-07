# -*- encoding: utf-8 -*-

#============================================================
__version__ 		= "0.16"
__license__ 		= "Gpl v2"
__copyright__ 		= "Copyright 2014, Stian Mikalsen"
__author__ 			= "Stian Mikalsen"
__description__ 	= 'File Reloader for Bec 1.596+'
__author_email__	= "stianmikalsen@hotmail.com"
__maintainer__ 		= "You and yourself. ;), me if you gimme a beer ;)"
#============================================================

# This Plugin will reloade current files if they change, get edited etc.
# Admins.xml, Commands.xml, WhiteList.txt, BadWords.txt, BadNames.txt

# This means that you can edit your Admins.xml or WhiteList.txt ,..., without restarting Bec.exe for it to have effect.
# The plugin is set to watch over the files every 5th second.

# Note. its unknown if the plugin will work if the file(s) are stored on network drive(s). 
# I am unsure is os.stat(filename).st_mtime will work on them.
# Nor do i know if it will work with linux/wine. 

#--------------------------------------------------------------------------------------------------

#
# If you want it to start no matter what server, then leave it empty
# Default set to start on any configuration...
# Else put in the name of the config file you want to start this on. remember the quotes around the name. ["myconf.cfg"]
SERVERS = []


# Include your mission filter file if you are using mission BE filters. include the full name. but not the path,
#MISSIONS = [
#	"test.altis",
#	"warfare.altis"]
MISSIONS = []




##############################################################################################
# Unless you know what you are doing.. 
# Do not edit anything below this line.
##############################################################################################

BE_FILTER_FILES = [
"addbackpackcargo.txt",
"addmagazinecargo.txt",
"addweaponcargo.txt",
"attachto.txt",
"createvehicle.txt",
"deleteVehicle.txt",
"mpeventhandler.txt",
"publicvariable.txt",
"publicvariableval.txt",
"remotecontrol.txt",
"remoteexec.txt",
"scripts.txt",
"selectplayer.txt",
"setdamage.txt",
"setpos.txt",
"setvariable.txt",
"setvariableval.txt",
"teamswitch.txt",
"waypointcondition.txt",
"waypointstatement.txt"]


# Import some common modules.
import os
import sys
import thread
import time

# Import custom modules
sys.path.append(os.getcwd()+"\\Plugins\\\WatchDog")
from Lib.BecClasses import Timec as CT
from Lib.BecClasses import File_Logging as FL
from Lib.Bec_XmlHandler import XmlParser as XP


# Debug mode
Debug = True
#Debug = False

class WatchDogs(object):
	
	def __init__(self, instance):
		self.bec = instance
		self.checkinterval = 5 # never set 0
		self.dogs_sniff_my_files()

	# function to start the monitor threads.
	# we create one thread for each file we want to monitor.
	def dogs_sniff_my_files(self):

		###############################
		# Admins.xml
		try:
			thread.start_new_thread(self.sniff_admins,())
			if Debug:
				Logstring = CT().GetTime()+' : Creating watchdog for admin file...'
				FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				print Logstring
		except Exception, WatchDog_admins_threadtask_error:
			if Debug:
				Logstring = CT().GetTime()+" : Can't create watchdog for admin file"
				print Logstring,":\n",WatchDog_admins_threadtask_error
				FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
			pass		
		
		###############################
		# Commands.xml
		try:
			thread.start_new_thread(self.sniff_commands,())
			if Debug:
				Logstring = CT().GetTime()+' : Creating watchdog for command file...'
				FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				print Logstring
		except Exception, WatchDog_commands_threadtask_error:
			if Debug:
				Logstring = CT().GetTime()+" : Can't create watchdog for command file"
				print Logstring,":\n",WatchDog_commands_threadtask_error
				FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
			pass
		
		###############################
		# Whitelist file
		if self.bec.Bec_Cfg_Misc_WhiteListFile:
			
			if not self.bec._Bec_whitelist:
				self.bec._Bec_whitelist.append('ffffffffffffffffffffffffffffffff')
				
			try:
				thread.start_new_thread(self.sniff_whitelist,())
				if Debug:
					Logstring = CT().GetTime()+' : Creating watchdog for whitelist file...'
					FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					print Logstring	
			except Exception, WatchDog_whitelist_threadtask_error:
				if Debug:
					Logstring = CT().GetTime()+" : Can't create watchdog for whitelist file"
					print Logstring,":\n",WatchDog_whitelist_threadtask_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				pass

		###############################
		# Badwords file
		if self.bec._Bec_unwantedwords:
			try:
				thread.start_new_thread(self.sniff_badwords,())
				if Debug:
					Logstring = CT().GetTime()+' : Creating watchdog for badwords file...'
					FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					print Logstring					
			except Exception, WatchDog_badwords_threadtask_error:
				if Debug:
					Logstring = CT().GetTime()+" : Can't create watchdog for badwords file"
					print Logstring,":\n",WatchDog_badwords_threadtask_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				pass

		###############################
		# Badnames file
		if self.bec._Bec_unvalidnicks:
			try:
				thread.start_new_thread(self.sniff_badnames,())
				if Debug:
					Logstring = CT().GetTime()+' : Creating watchdog for badnames file...'
					FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					print Logstring
			except Exception, WatchDog_badnames_threadtask_error:
				if Debug:
					Logstring = CT().GetTime()+" : Can't create watchdog for badnames file"
					print Logstring,":\n",WatchDog_badnames_threadtask_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				pass

		###############################
		# BE filter files
		try:
			thread.start_new_thread(self.sniff_be_filters,())
			if Debug:
				Logstring = CT().GetTime()+' : Creating watchdog for BE filter files...'
				FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
				print Logstring		
		except Exception, WatchDog_BeFilter_threadtask_error:
			if Debug:
				Logstring = CT().GetTime()+" : Can't create watchdog for be filter files"
				print Logstring,":\n",WatchDog_BeFilter_threadtask_error
				FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
			pass		
		
	########################################################################
	# Sniffing thread jobs..
	########################################################################
	def sniff_whitelist(self):
		while True:
			try:
				sniff_old = os.stat( self.bec.Bec_Cfg_Misc_WhiteListFile ).st_mtime
				time.sleep( self.checkinterval )
				sniff_new = os.stat( self.bec.Bec_Cfg_Misc_WhiteListFile ).st_mtime
			except:
				# so many issue. ifile removed etc..
				sniff_old = False
				sniff_new = False
				if Debug:
					Logstring = CT().GetTime()+" Error in checking Whitelist file"
					print Logstring,":\n",WatchDog_fileread_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
		
			if sniff_old != sniff_new:
				try:
					self.bec._Bec_whitelist	= FL().ReadWhiteListFile( self.bec.Bec_Cfg_Misc_WhiteListFile )

					if Debug:
						Logstring = CT().GetTime()+' : Whitelist file changed. reloading data...'
						FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
						print Logstring	
				except Exception, WatchDog_fileread_error:
					# if an error occures when reading the whitelist file.
					# disable the whitelist system until the file is valid.
					# self.bec._Bec_whitelist	= False
					
					# we may not want to do that since the list may already contain guids of players...
					# and the data from the file is read to mem. the onconnect will use this as the checkpoint.
					# we can validate the list instead.
					
					
					
					if Debug:
						Logstring = CT().GetTime()+" Error in reading Whitelist file"
						print Logstring,":\n",WatchDog_fileread_error
						FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)	
	
	def sniff_badwords(self):
		while True:
			try:
				sniff_old = os.stat( self.bec.Bec_Cfg_Misc_WordFilterFile ).st_mtime
				time.sleep( self.checkinterval )
				sniff_new = os.stat( self.bec.Bec_Cfg_Misc_WordFilterFile ).st_mtime
			except:
				# so many issue. ifile removed etc..
				sniff_old = False
				sniff_new = False
				if Debug:
					Logstring = CT().GetTime()+" Error in checking Badwords file"
					print Logstring,":\n",WatchDog_fileread_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)				
		
			if sniff_old != sniff_new:
				try:
					self.bec._Bec_unwantedwords	= FL().ReadFile( self.bec.Bec_Cfg_Misc_WordFilterFile )
					if Debug:
						Logstring = CT().GetTime()+' : Badwords file changed. reloading data...'
						FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
						print Logstring						
				
				except Exception, WatchDog_fileread_error:
					self.bec._Bec_unwantedwords	= False
					if Debug:
						Logstring = CT().GetTime()+" Error loading Badwords file"
						print Logstring,":\n",WatchDog_fileread_error
						FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					pass
	
	def sniff_badnames(self):
		while True:
			try:
				sniff_old = os.stat( self.bec.Bec_Cfg_Misc_NickFilterFile ).st_mtime
				time.sleep( self.checkinterval )
				sniff_new = os.stat( self.bec.Bec_Cfg_Misc_NickFilterFile ).st_mtime
			except:
				# so many issue. ifile removed etc..
				sniff_old = False
				sniff_new = False
				if Debug:
					Logstring = CT().GetTime()+" Error in checking Badnames file"
					print Logstring,":\n",WatchDog_fileread_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)	
			
			if sniff_old != sniff_new:
				try:
					self.bec._Bec_unvalidnicks	= FL().ReadFile( self.bec.Bec_Cfg_Misc_NickFilterFile )
					if Debug:
						Logstring = CT().GetTime()+' : Badnames file changed. reloading data...'
						FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
						print Logstring							
				except Exception, WatchDog_fileread_error:
					self.bec._Bec_unvalidnicks	= False
					if Debug:
						Logstring = CT().GetTime()+" Error loading Badnames file"
						print Logstring,":\n",WatchDog_fileread_error
						FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					pass
	
	def sniff_admins(self):
		while True:
			try:
				sniff_old = os.stat( self.bec.Bec_Cfg_Main_Admins ).st_mtime
				time.sleep( self.checkinterval )
				sniff_new = os.stat( self.bec.Bec_Cfg_Main_Admins ).st_mtime	
			except:
				# so many issue. ifile removed etc..
				sniff_old = False
				sniff_new = False
				if Debug:
					Logstring = CT().GetTime()+" Error in checking Admin file"
					print Logstring,":\n",WatchDog_fileread_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)	
			
			if sniff_old != sniff_new:
				try:
					# Get the updated file.
					test = XP()._admin( self.bec.Bec_Cfg_Main_Admins )
					
					# If we have admins, continue...
					if len(test) > 0:
						
						# if we removed an admin from the file that was online. update this too.
						for key in self.bec.Bec_adminsconnected.keys():
							guid = self.bec.Bec_adminsconnected[key][1]
							
							if not guid in test.keys():
								del self.bec.Bec_adminsconnected[key]

						self.bec._Bec_admins = test
						
						if Debug:
							Logstring = CT().GetTime()+' : Admin file changed. reloading data...'
							FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
							print Logstring								
					
					# we removed all our admins from the admins.xml file...
					else:
						# set the dict empty...
						self.bec._Bec_admins = {}
						self.bec.Bec_adminsconnected = {}
					
						if Debug:
							Logstring = CT().GetTime()+' : Admin file changed. But no admins defined...'
							FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
							print Logstring										
				
				except Exception, WatchDog_fileread_error:
					if Debug:
						Logstring = CT().GetTime()+" Error Parsing Admin file"
						print Logstring,":\n",WatchDog_fileread_error
						FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					pass

	def sniff_commands(self):
		while True:
			try:
				sniff_old = os.stat( self.bec.Bec_Cfg_Main_Commands ).st_mtime
				time.sleep( self.checkinterval )
				sniff_new = os.stat( self.bec.Bec_Cfg_Main_Commands ).st_mtime	
			except:
				# so many issue. ifile removed etc..
				sniff_old = False
				sniff_new = False
				if Debug:
					Logstring = CT().GetTime()+" Error in checking Command file"
					print Logstring,":\n",WatchDog_fileread_error
					FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)	

			if sniff_old != sniff_new:
				try:
					
					# Get the updated command file
					test = XP()._commands( self.bec.Bec_Cfg_Main_Commands )
					
					# If we have commands, continue...
					if len(test) > 0:
						
						self.bec._Bec_commands = test

						if Debug:
							Logstring = CT().GetTime()+' : Command file changed. reloading data...'
							FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
							print Logstring							
					
					# We have removed all commands form the commands.xml file.
					else:
						
						# set the dict empty...
						self.bec._Bec_commands = {}
						
						if Debug:
							Logstring = CT().GetTime()+' : Command file changed. But no commands defined...'
							FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
							print Logstring
							
				except Exception, WatchDog_fileread_error:
					if Debug:
						Logstring = CT().GetTime()+" Error Parsing Command file"
						print Logstring,":\n",WatchDog_fileread_error
						FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
					pass

	def sniff_be_filters(self):
		
		# Append the mission prefix to the list of filters.
		befilters = BE_FILTER_FILES[:]
		bemf = []
		if len(MISSIONS) > 0:
			for mission in MISSIONS:
				for filter in befilters:
					missionfilter = mission+"\\"+filter
					bemf.append(missionfilter)
		
		# Validate the file path. see which exists..
		befilters = befilters + bemf
		vaild_befilters = []
		for file in befilters:
			if os.path.isfile(self.bec.Bec_Cfg_Main_BePath+"\\"+file):
				vaild_befilters.append(file)
		
		run = True
		if len(vaild_befilters) == 0:
			run = False
			Logstring = CT().GetTime()+" : No BE filter files found or is not defined.. Skipping watchdog for BE filter files."
			print Logstring
			FL().LogBecError(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
		
		while run:
			check_list = {}
			for file in vaild_befilters:
				try:
					sniff_old = os.stat( self.bec.Bec_Cfg_Main_BePath+"\\"+file ).st_mtime
					check_list[file] = sniff_old
				except:
					check_list[file] = False

			time.sleep( self.checkinterval )
			
			for file in vaild_befilters:
				try:
					sniff_old = os.stat( self.bec.Bec_Cfg_Main_BePath+"\\"+file ).st_mtime
				except:
					sniff_old = False
					
				if sniff_old != check_list[file]:
					
					if file.endswith("scripts.txt"):
						self.bec._Bec_queuelist.append("loadScripts")
					else:
						self.bec._Bec_queuelist.append("loadEvents")

					if Debug:
						Logstring = CT().GetTime()+' : BE Filter file:'+file+' was changed. reloading data...'
						FL().LogBeClient(self.bec.Bec_Cfg_Main_LogDirPath, Logstring)
						print Logstring	
						
				
# start function for the plugin that Bec uses.
def start(x):
	WatchDogs(x)
