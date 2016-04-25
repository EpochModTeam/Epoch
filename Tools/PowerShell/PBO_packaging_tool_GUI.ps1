#region Script Settings
#<ScriptSettings xmlns="http://tempuri.org/ScriptSettings.xsd">
#  <ScriptPackager>
#    <process>powershell.exe</process>
#    <arguments />
#    <extractdir>%TEMP%</extractdir>
#    <files />
#    <usedefaulticon>true</usedefaulticon>
#    <showinsystray>false</showinsystray>
#    <altcreds>false</altcreds>
#    <efs>true</efs>
#    <ntfs>true</ntfs>
#    <local>false</local>
#    <abortonfail>true</abortonfail>
#    <product />
#    <version>1.0.0.1</version>
#    <versionstring />
#    <comments />
#    <company />
#    <includeinterpreter>false</includeinterpreter>
#    <forcecomregistration>false</forcecomregistration>
#    <consolemode>false</consolemode>
#    <EnableChangelog>false</EnableChangelog>
#    <AutoBackup>false</AutoBackup>
#    <snapinforce>false</snapinforce>
#    <snapinshowprogress>false</snapinshowprogress>
#    <snapinautoadd>2</snapinautoadd>
#    <snapinpermanentpath />
#    <cpumode>1</cpumode>
#    <hidepsconsole>false</hidepsconsole>
#  </ScriptPackager>
#</ScriptSettings>
#endregion

#region ScriptForm Designer

#region Constructor

[void][System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")
[void][System.Reflection.Assembly]::LoadWithPartialName("System.Drawing")

#endregion

#region Post-Constructor Custom Code

#endregion

#region Form Creation
#Warning: It is recommended that changes inside this region be handled using the ScriptForm Designer.
#When working with the ScriptForm designer this region and any changes within may be overwritten.
#~~< Form1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Form1 = New-Object System.Windows.Forms.Form
$Form1.ClientSize = New-Object System.Drawing.Size(1095, 738)
$Form1.FormBorderStyle = [System.Windows.Forms.FormBorderStyle]::FixedSingle
$Form1.Text = "Epoch PBO Packing Tool"
#~~< Label4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label4 = New-Object System.Windows.Forms.Label
$Label4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Label4.Location = New-Object System.Drawing.Point(983, 8)
$Label4.Size = New-Object System.Drawing.Size(100, 23)
$Label4.TabIndex = 1
$Label4.Text = "Version"
$Label4.TextAlign = [System.Drawing.ContentAlignment]::MiddleCenter
#~~< TabControl1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabControl1 = New-Object System.Windows.Forms.TabControl
$TabControl1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TabControl1.Location = New-Object System.Drawing.Point(12, 12)
$TabControl1.Size = New-Object System.Drawing.Size(1071, 714)
$TabControl1.TabIndex = 0
$TabControl1.Text = ""
#~~< TabPage1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage1 = New-Object System.Windows.Forms.TabPage
$TabPage1.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage1.Location = New-Object System.Drawing.Point(4, 22)
$TabPage1.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage1.Size = New-Object System.Drawing.Size(1063, 688)
$TabPage1.TabIndex = 0
$TabPage1.Text = "Packager"
$TabPage1.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button6 = New-Object System.Windows.Forms.Button
$Button6.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button6.Location = New-Object System.Drawing.Point(980, 657)
$Button6.Size = New-Object System.Drawing.Size(75, 23)
$Button6.TabIndex = 3
$Button6.Text = "Create PBO"
$Button6.UseVisualStyleBackColor = $true
#~~< Button5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button5 = New-Object System.Windows.Forms.Button
$Button5.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button5.Location = New-Object System.Drawing.Point(980, 35)
$Button5.Size = New-Object System.Drawing.Size(75, 23)
$Button5.TabIndex = 2
$Button5.Text = "Select none"
$Button5.UseVisualStyleBackColor = $true
#~~< Button7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button7 = New-Object System.Windows.Forms.Button
$Button7.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button7.Location = New-Object System.Drawing.Point(980, 6)
$Button7.Size = New-Object System.Drawing.Size(75, 23)
$Button7.TabIndex = 1
$Button7.Text = "Select all"
$Button7.UseVisualStyleBackColor = $true
#~~< ListView1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListView1 = New-Object System.Windows.Forms.ListView
$ListView1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$ListView1.Location = New-Object System.Drawing.Point(6, 6)
$ListView1.Size = New-Object System.Drawing.Size(968, 674)
$ListView1.TabIndex = 0
$ListView1.Text = "ListView1"
$ListView1.UseCompatibleStateImageBehavior = $false
$ListView1.View = [System.Windows.Forms.View]::Details
#~~< ColumnHeader1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ColumnHeader1 = New-Object System.Windows.Forms.ColumnHeader
$ColumnHeader1.Text = "Source"
$ColumnHeader1.Width = 205
#~~< ColumnHeader2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ColumnHeader2 = New-Object System.Windows.Forms.ColumnHeader
$ColumnHeader2.Text = "Full Path"
$ColumnHeader2.Width = 679
$ListView1.Columns.AddRange([System.Windows.Forms.ColumnHeader[]](@($ColumnHeader1, $ColumnHeader2)))
#~~< ListViewGroup11 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListViewGroup11 = New-Object System.Windows.Forms.ListViewGroup("Server", [System.Windows.Forms.HorizontalAlignment]::Left)
$ListViewGroup11.Header = "Server"
#~~< ListViewGroup12 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListViewGroup12 = New-Object System.Windows.Forms.ListViewGroup("Client", [System.Windows.Forms.HorizontalAlignment]::Left)
$ListViewGroup12.Header = "Client"
#~~< ListViewGroup13 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListViewGroup13 = New-Object System.Windows.Forms.ListViewGroup("Missions", [System.Windows.Forms.HorizontalAlignment]::Left)
$ListViewGroup13.Header = "Missions"
$ListView1.Groups.AddRange([System.Windows.Forms.ListViewGroup[]](@($ListViewGroup11, $ListViewGroup12, $ListViewGroup13)))
$TabPage1.Controls.Add($Button6)
$TabPage1.Controls.Add($Button5)
$TabPage1.Controls.Add($Button7)
$TabPage1.Controls.Add($ListView1)
#~~< TabPage2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage2 = New-Object System.Windows.Forms.TabPage
$TabPage2.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage2.Location = New-Object System.Drawing.Point(4, 22)
$TabPage2.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage2.Size = New-Object System.Drawing.Size(629, 398)
$TabPage2.TabIndex = 1
$TabPage2.Text = "Settings"
$TabPage2.BackColor = [System.Drawing.SystemColors]::Control
#~~< Label6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label6 = New-Object System.Windows.Forms.Label
$Label6.Location = New-Object System.Drawing.Point(6, 214)
$Label6.Size = New-Object System.Drawing.Size(230, 15)
$Label6.TabIndex = 15
$Label6.Text = "Addon:"
#~~< ComboBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ComboBox1 = New-Object System.Windows.Forms.ComboBox
$ComboBox1.FormattingEnabled = $true
$ComboBox1.Location = New-Object System.Drawing.Point(6, 232)
$ComboBox1.SelectedIndex = -1
$ComboBox1.Size = New-Object System.Drawing.Size(121, 21)
$ComboBox1.TabIndex = 14
$ComboBox1.Text = ""
#~~< Button4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button4 = New-Object System.Windows.Forms.Button
$Button4.Location = New-Object System.Drawing.Point(242, 143)
$Button4.Size = New-Object System.Drawing.Size(54, 21)
$Button4.TabIndex = 13
$Button4.Text = "Browse"
$Button4.UseVisualStyleBackColor = $true
#~~< Label5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label5 = New-Object System.Windows.Forms.Label
$Label5.Location = New-Object System.Drawing.Point(6, 126)
$Label5.Size = New-Object System.Drawing.Size(230, 15)
$Label5.TabIndex = 12
$Label5.Text = "Path to Epoch Private Github (Devs only):"
#~~< TextBox4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox4 = New-Object System.Windows.Forms.TextBox
$TextBox4.Location = New-Object System.Drawing.Point(6, 144)
$TextBox4.Size = New-Object System.Drawing.Size(230, 20)
$TextBox4.TabIndex = 11
$TextBox4.Text = ""
#~~< CheckBox2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$CheckBox2 = New-Object System.Windows.Forms.CheckBox
$CheckBox2.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left))
$CheckBox2.Location = New-Object System.Drawing.Point(6, 366)
$CheckBox2.Size = New-Object System.Drawing.Size(290, 24)
$CheckBox2.TabIndex = 1
$CheckBox2.Text = "Increase Build Number (Devs only)"
$CheckBox2.UseVisualStyleBackColor = $true
#~~< CheckBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$CheckBox1 = New-Object System.Windows.Forms.CheckBox
$CheckBox1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left))
$CheckBox1.Location = New-Object System.Drawing.Point(6, 331)
$CheckBox1.Size = New-Object System.Drawing.Size(290, 29)
$CheckBox1.TabIndex = 10
$CheckBox1.Text = "Save settings locally (%temp%\EPPTsettings.txt)"
$CheckBox1.UseVisualStyleBackColor = $true
#~~< Button3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button3 = New-Object System.Windows.Forms.Button
$Button3.Location = New-Object System.Drawing.Point(242, 102)
$Button3.Size = New-Object System.Drawing.Size(54, 21)
$Button3.TabIndex = 8
$Button3.Text = "Browse"
$Button3.UseVisualStyleBackColor = $true
#~~< Label3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label3 = New-Object System.Windows.Forms.Label
$Label3.Location = New-Object System.Drawing.Point(6, 85)
$Label3.Size = New-Object System.Drawing.Size(230, 15)
$Label3.TabIndex = 7
$Label3.Text = "Path to Arma 3 Addon builder"
#~~< TextBox3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox3 = New-Object System.Windows.Forms.TextBox
$TextBox3.Location = New-Object System.Drawing.Point(6, 103)
$TextBox3.Size = New-Object System.Drawing.Size(230, 20)
$TextBox3.TabIndex = 6
$TextBox3.Text = ""
#~~< Button2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button2 = New-Object System.Windows.Forms.Button
$Button2.Location = New-Object System.Drawing.Point(242, 61)
$Button2.Size = New-Object System.Drawing.Size(54, 21)
$Button2.TabIndex = 5
$Button2.Text = "Browse"
$Button2.UseVisualStyleBackColor = $true
#~~< Label2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label2 = New-Object System.Windows.Forms.Label
$Label2.Location = New-Object System.Drawing.Point(6, 44)
$Label2.Size = New-Object System.Drawing.Size(230, 15)
$Label2.TabIndex = 4
$Label2.Text = "Path to Epoch Public Github:"
#~~< TextBox2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox2 = New-Object System.Windows.Forms.TextBox
$TextBox2.Location = New-Object System.Drawing.Point(6, 62)
$TextBox2.Size = New-Object System.Drawing.Size(230, 20)
$TextBox2.TabIndex = 3
$TextBox2.Text = ""
#~~< Button1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button1 = New-Object System.Windows.Forms.Button
$Button1.Location = New-Object System.Drawing.Point(242, 20)
$Button1.Size = New-Object System.Drawing.Size(54, 21)
$Button1.TabIndex = 2
$Button1.Text = "Browse"
$Button1.UseVisualStyleBackColor = $true
#~~< Label1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label1 = New-Object System.Windows.Forms.Label
$Label1.Location = New-Object System.Drawing.Point(6, 3)
$Label1.Size = New-Object System.Drawing.Size(230, 15)
$Label1.TabIndex = 1
$Label1.Text = "Path to Arma 3:"
#~~< TextBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox1 = New-Object System.Windows.Forms.TextBox
$TextBox1.Location = New-Object System.Drawing.Point(6, 21)
$TextBox1.Size = New-Object System.Drawing.Size(230, 20)
$TextBox1.TabIndex = 0
$TextBox1.Text = ""
$TabPage2.Controls.Add($Label6)
$TabPage2.Controls.Add($ComboBox1)
$TabPage2.Controls.Add($Button4)
$TabPage2.Controls.Add($Label5)
$TabPage2.Controls.Add($TextBox4)
$TabPage2.Controls.Add($CheckBox2)
$TabPage2.Controls.Add($CheckBox1)
$TabPage2.Controls.Add($Button3)
$TabPage2.Controls.Add($Label3)
$TabPage2.Controls.Add($TextBox3)
$TabPage2.Controls.Add($Button2)
$TabPage2.Controls.Add($Label2)
$TabPage2.Controls.Add($TextBox2)
$TabPage2.Controls.Add($Button1)
$TabPage2.Controls.Add($Label1)
$TabPage2.Controls.Add($TextBox1)
$TabControl1.Controls.Add($TabPage1)
$TabControl1.Controls.Add($TabPage2)
$TabControl1.SelectedIndex = 0
$Form1.Controls.Add($Label4)
$Form1.Controls.Add($TabControl1)
#region$Form1.Icon = ([System.Drawing.Icon](...)
$Form1.Icon = ([System.Drawing.Icon](New-Object System.Drawing.Icon((New-Object System.IO.MemoryStream(($$ = [System.Convert]::FromBase64String(
"AAABAAEAEBAAAAEAIABoBAAAFgAAACgAAAAQAAAAIAAAAAEAIAAAAAAAAAQAABILAAASCwAAAAAA"+
                                "AAAAAAD///8AAAAAAAAAAAAAAAAAAAAACQAAAHEAAADLAAAA6wAAAOkAAADHAAAAbwAAAAcAAAAA"+
                                "AAAAAAAAAAAAAAAA////AAAAAAAAAAAAAAAAKQAAANgAAACLAAAAKgAAAAEAAAABAAAALQAAAJYA"+
                                "AADSAAAAJgAAAAAAAAAAAAAAAP///wAAAAAAAAAAIAAAANoAAAA7AAAAAAAAAAAAAAAAAAAAAAAA"+
                                "AAAAAAAAAAAAQQAAAN0AAAAaAAAAAAAAAAD///8AAAAAygAAAOgAAADcAAAAqgAAAJ4AAACEAAAA"+
                                "dQAAAF8AAABDAAAAOwAAAB4AAABeAAAArwAAAAAAAAAA////AAAAAOEAAAD/AAAA/wAAAP8AAAD/"+
                                "AAAA/AAAAP0AAADgAAAA1wAAAMEAAACwAAAAlQAAAM4AAACQAAAAN////wAAAADAAAAAdAAAAEcA"+
                                "AAAwAAAAJgAAAA8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABIAAAAmgAAAAD///8AAAAA0wAA"+
                                "AAUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACQAAAM8AAAAA////"+
                                "AAAAAPQAAADgAAAAzQAAALkAAACmAAAAkQAAAH4AAABjAAAAUQAAAD8AAAArAAAAAQAAAAAAAADT"+
                                "AAAAAP///wAAAAD3AAAAzwAAAMkAAACjAAAAoAAAAIwAAABzAAAAYwAAAFAAAAA9AAAAHgAAAAQA"+
                                "AAAAAAAA1QAAAAD///8AAAAA0wAAAAUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"+
                                "AAAAAAAAAAAACQAAAMcAAAAA////AAAAALkAAABhAAAAGwAAAA0AAAABAAAAAAAAAAAAAAAAAAAA"+
                                "AAAAAAAAAAAAAAAAAAAAAEoAAACUAAAAAP///wAAAADhAAAA/wAAAP8AAAD/AAAA/QAAAOYAAADV"+
                                "AAAAwQAAAK4AAACYAAAAfQAAAG8AAAC9AAAAewAAABr///8AAAAA3wAAAPoAAADwAAAAzQAAALwA"+
                                "AACpAAAAlQAAAIEAAABpAAAAWgAAAEYAAAB7AAAAuAAAAAkAAAAA////AAAAAAoAAAAgAAAA1AAA"+
                                "AD0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABDAAAA3QAAABkAAAAAAAAAAP///wAAAAAAAAAA"+
                                "AAAAACkAAADXAAAAkgAAACkAAAABAAAAAgAAAC4AAACWAAAA0wAAACkAAAAAAAAAAAAAAAD///8A"+
                                "AAAAAAAAAAAAAAAAAAAACAAAAF0AAADLAAAA6gAAAOYAAADHAAAAbgAAAAEAAAAAAAAAAAAAAAAA"+
                                "AAAA8A8AAOAHAADH4wAAgAMAAIAAAACB+QAAn/kAAIAFAACABQAAn/kAAIP5AACAAAAAgAEAAIfj"+
                                "AADgBwAA8A8AAA==")),0,$$.Length)))))
#endregion
#~~< components >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$components = New-Object System.ComponentModel.Container
#~~< Timer1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Timer1 = New-Object System.Windows.Forms.Timer($components)
#~~< FolderBrowserDialog1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$FolderBrowserDialog1 = New-Object System.Windows.Forms.FolderBrowserDialog

#endregion

#region Custom Code
		
	# Static development vars, DELETE ON RELEASE
	$TextBox1.Text = "E:\Steam\steamapps\common\Arma 3"
	$TextBox2.Text = "F:\github\Epoch_public"
	$TextBox3.Text = "P:\AddonBuilder"
	$TextBox4.Text = "F:\github\EPOCHMOD"
	$ver = "0.3.8"
	
	# Defines
	$ListView1.CheckBoxes = $true
	$FolderBrowserDialog1.ShowNewFolderButton = $false
	
	# Functions
		
	function fnc_populateListView
	{
		#$ListView1.Clear()
				
		$listarr = @() #empty arr
		$folders = Get-ChildItem $TextBox2.Text -directory
				
		if (Test-Path $TextBox4.Text)
		{
			$priv = Get-ChildItem $TextBox4.Text -directory
			$folders += ,$priv
		}
		
		foreach ($x in $folders)
		{
			$y = Get-ChildItem $x.fullname -directory
			
			if ($y) #If subfolders exist
			{
				foreach ($z in $y)
				{
					switch($z.name)
					{
						#Groups: 11 server 12 client 13 mission
						{ $_.contains("server") } 
						{
							$tmp = New-Object System.Windows.Forms.ListViewItem([System.String[]] ( @($_, $z.fullname) ), -1)
							$tmp.Name = $_
							$tmp.Group = $ListViewGroup11
							$listarr +=, $tmp
						}
						{ $_.contains("mpmissions") } 
						{
							$missions = Get-ChildItem $z.fullname -directory
							foreach ($mission in $missions)
							{
								$tmp = New-Object System.Windows.Forms.ListViewItem([System.String[]] ( @($mission.name, $mission.fullname) ), -1)
								$tmp.Name = $_
								$tmp.Group = $ListViewGroup13
								$listarr +=, $tmp
							}
						}
						default
						{
							$ok = Test-Path(Join-Path $z.fullname "\config.cpp")
							if ($ok)
							{
								$tmp = New-Object System.Windows.Forms.ListViewItem([System.String[]] ( @($_, $z.fullname) ), -1)
								$tmp.Name = $_
								$tmp.Group = $ListViewGroup12
								$listarr +=, $tmp
							}
						}
					}
				}
			}
		}
		$ListView1.Items.AddRange([System.Windows.Forms.ListViewItem[]] ( $listarr ))
	}
	
	function fnc_populateCombo
	{
				
	}

		
	function fnc_getVersion
	{
		
	}
	
	function fnc_enableControls
	{
		$c1 = Test-Path (Join-Path $TextBox1.Text "\Arma3.exe")
		$c2 = Test-Path (Join-Path $TextBox2.Text "\Sources")
		$c3 = Test-Path (Join-Path $TextBox3.Text "\AddonBuilder.exe")
		$c4 = Test-Path (Join-Path $TextBox4.Text "\Source_APL")
		$c5 = Test-Path "P:\"
	
		if ($c1 -and $c2 -and $c3 -and $c5)
		{
			$Button5.Enabled = $true
			$Button6.Enabled = $true
			$Button7.Enabled = $true
			$ListView1.Enabled = $true
		}
		else
		{
			$Button5.Enabled = $false
			$Button6.Enabled = $false
			$Button7.Enabled = $false
			$ListView1.Enabled = $false
		}
		$Label4.Text = if (!$c5) { "P:\ drive not mounted" } else { $ver }
	}
	
	function fnc_getSetPath($switch)
	{
		$FolderBrowserDialog1.ShowDialog()
		if ($FolderBrowserDialog1.SelectedPath)
		{
			$p = $FolderBrowserDialog1.SelectedPath
			$tb = switch($switch)
			{
				1 # Location of Arma 3
				{ 
					$TextBox1.Text = $p
					$tp = Join-Path $p "\Arma3.exe"
					if (!(Test-Path $tp))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
				}
				
				2 # Location of Public Github
				{ 
					$TextBox2.Text = $p
					$tp = Join-Path $p "\Sources"
					if (!(Test-Path $tp))
					{
						$Script:PathGPu = $tp
					}
				}
				
				3 # Location of Addob Builder
				{ 
					$TextBox3.Text = $p
					$tp = Join-Path $p "\AddonBuilder.exe"
					if (!(Test-Path $tp))
					{
						$Script:PathAB = $tp
					}
				}
				
				4 # Location of Private Github
				{ 
					$TextBox4.Text = $p
					$tp = Join-Path $p "\Source_APL"
					if (!(Test-Path $tp))
					{
						$Script:PathGPr = $tp
					}
				}
			}
			$FolderBrowserDialog1.SelectedPath = $null
		}
	}
	# Event Handlers
	$Button1.Add_Click({ fnc_getSetPath(1) })
	$Button2.Add_Click({ fnc_getSetPath(2) })
	$Button3.Add_Click({ fnc_getSetPath(3) })
	$Button4.Add_Click({ fnc_getSetPath(4) })
	
	# Main code
		
	# Fake endless loop, spawned thread
	$Timer1.Start()
	$Timer1.Interval = 1000
	$Timer1.Add_tick({ fnc_enableControls })
		
	if ($TextBox2.Text)
	{
		fnc_populateListView
	}

#endregion

#region Event Loop

function Main{
	[System.Windows.Forms.Application]::EnableVisualStyles()
	[System.Windows.Forms.Application]::Run($Form1)
}

#endregion

#endregion

#region Event Handlers

Main # This call must remain below all other event functions

#endregion
# ========================================================
#
# 	Script Information
#
#	Title:					Epoch PBO Packing Tool
#	Author:					Raimonds Virtoss - Raymix @ Epoch UI code
#	Originally created:	4/24/2016 - 17:56:19
#	Description:			Form based (GUI) Tool to Pack or binarize Epoch PBOs. Scans your github repos and automatically creates a list of relevant folders for packaging
#	Usage:					.EXE file will be provided when script is done, for now simply right click it and run with powershell.
#	
# ========================================================

