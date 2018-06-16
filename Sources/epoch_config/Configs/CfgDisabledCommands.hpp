/*
    COMMANDS: LOADFILE, SETFRIEND, SETAMMO, ENABLEFATIGUE, SETUNITRECOILCOEFFICIENT, CALLEXTENSION, ENABLECOLLISIONWITH, REMOVEALLITEMS, REMOVEALLACTIONS, CREATETEAM, FORCEADDUNIFORM, REMOVEALLMPEVENTHANDLERS, SETDAMMAGE, DISPLAYSETEVENTHANDLER, ADDMPEVENTHANDLER, REMOVEALLMISSIONEVENTHANDLERS, CTRLCLASSNAME, CTRLMODEL, SETGROUPICONSVISIBLE, SETGROUPICONSSELECTABLE, SETGROUPICONPARAMS, ADDGROUPICON
*/

class CfgDisabledCommands
{
    class LOADFILE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"STRING"}};
        };
    };

    class SETFRIEND
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"SIDE"},{"ARRAY"}};
        };
    };

    class SETAMMO
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"ARRAY"}};
        };
    };

    class ENABLEFATIGUE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"BOOL"}};
        };
    };

    class SETUNITRECOILCOEFFICIENT
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"SCALAR"}};
        };
    };

    class CALLEXTENSION
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"STRING"},{"STRING"}};
        };

        class SYNTAX2
        {
            targets[] = {1,0,1};
            args[] = {{"STRING"},{"ARRAY"}};
        };
    };

    class ENABLECOLLISIONWITH
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"OBJECT"}};
        };
    };

    class REMOVEALLITEMS
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"OBJECT"}};
        };
    };

    class REMOVEALLACTIONS
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"OBJECT"}};
        };
    };

    class CREATETEAM
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"ARRAY"}};
        };
    };

    class FORCEADDUNIFORM
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"STRING"}};
        };
    };

    class REMOVEALLMPEVENTHANDLERS
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"STRING"}};
        };
    };

    class SETDAMMAGE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"SCALAR"}};
        };
    };

    class DISPLAYSETEVENTHANDLER
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"DISPLAY"},{"ARRAY"}};
        };
    };

    class ADDMPEVENTHANDLER
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"OBJECT"},{"ARRAY"}};
        };
    };

    class REMOVEALLMISSIONEVENTHANDLERS
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"STRING"}};
        };
    };

    class CTRLCLASSNAME
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"CONTROL"}};
        };
    };

    class CTRLMODEL
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"CONTROL"}};
        };
    };

    class SETGROUPICONSVISIBLE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"ARRAY"}};
        };
    };

    class SETGROUPICONSSELECTABLE
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{},{"BOOL"}};
        };
    };

    class SETGROUPICONPARAMS
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"GROUP"},{"ARRAY"}};
        };
    };

    class ADDGROUPICON
    {
        class SYNTAX1
        {
            targets[] = {1,0,1};
            args[] = {{"GROUP"},{"ARRAY"}};
        };
    };
};