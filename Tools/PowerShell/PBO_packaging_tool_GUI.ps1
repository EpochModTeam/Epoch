#region Script Settings
#<ScriptSettings xmlns="http://tempuri.org/ScriptSettings.xsd">
#  <ScriptPackager>
#    <process>powershell.exe</process>
#    <arguments />
#    <extractdir>%TEMP%</extractdir>
#    <files />
#    <usedefaulticon>false</usedefaulticon>
#    <icon>F:\ARCHIVE\Downloads\logo_only_1024.ico</icon>
#    <showinsystray>false</showinsystray>
#    <tooltip>Epoch Mod PBO Packer</tooltip>
#    <altcreds>false</altcreds>
#    <efs>true</efs>
#    <ntfs>true</ntfs>
#    <local>false</local>
#    <abortonfail>true</abortonfail>
#    <product>Epoch PBO Packing Tool</product>
#    <internalname>Epoch PBO Packing Tool </internalname>
#    <version>1.0.0.1</version>
#    <versionstring>1.0</versionstring>
#    <description>Tool to aid in the packing of Epoch Mod source files</description>
#    <comments>By Raimonds Virtoss and Aaron Clark</comments>
#    <company>EpochMod.com</company>
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
$Form1.ClientSize = New-Object System.Drawing.Size(832, 593)
$Form1.Text = "Epoch PBO Packing Tool"
#~~< ProgressBar1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ProgressBar1 = New-Object System.Windows.Forms.ProgressBar
$ProgressBar1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$ProgressBar1.Location = New-Object System.Drawing.Point(12, 565)
$ProgressBar1.Size = New-Object System.Drawing.Size(808, 16)
$ProgressBar1.TabIndex = 2
$ProgressBar1.Text = ""
#~~< Label4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label4 = New-Object System.Windows.Forms.Label
$Label4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$Label4.Location = New-Object System.Drawing.Point(12, 9)
$Label4.Size = New-Object System.Drawing.Size(808, 18)
$Label4.TabIndex = 1
$Label4.Text = ""
$Label4.TextAlign = [System.Drawing.ContentAlignment]::MiddleCenter
$Label4.add_Click({Label4Click($Label4)})
#~~< TabControl1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabControl1 = New-Object System.Windows.Forms.TabControl
$TabControl1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TabControl1.Location = New-Object System.Drawing.Point(12, 30)
$TabControl1.Size = New-Object System.Drawing.Size(808, 529)
$TabControl1.TabIndex = 0
$TabControl1.Text = ""
#~~< TabPage1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage1 = New-Object System.Windows.Forms.TabPage
$TabPage1.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage1.Location = New-Object System.Drawing.Point(4, 22)
$TabPage1.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage1.Size = New-Object System.Drawing.Size(800, 503)
$TabPage1.TabIndex = 0
$TabPage1.Text = "Packager"
$TabPage1.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button16 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button16 = New-Object System.Windows.Forms.Button
$Button16.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button16.Location = New-Object System.Drawing.Point(717, 64)
$Button16.Size = New-Object System.Drawing.Size(75, 23)
$Button16.TabIndex = 4
$Button16.Text = "Selected"
$Button16.UseVisualStyleBackColor = $true
#~~< Button6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button6 = New-Object System.Windows.Forms.Button
$Button6.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button6.Location = New-Object System.Drawing.Point(717, 472)
$Button6.Size = New-Object System.Drawing.Size(75, 23)
$Button6.TabIndex = 3
$Button6.Text = "Create PBO"
$Button6.UseVisualStyleBackColor = $true
#~~< Button5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button5 = New-Object System.Windows.Forms.Button
$Button5.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button5.Location = New-Object System.Drawing.Point(717, 35)
$Button5.Size = New-Object System.Drawing.Size(75, 23)
$Button5.TabIndex = 2
$Button5.Text = "Select none"
$Button5.UseVisualStyleBackColor = $true
#~~< Button7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button7 = New-Object System.Windows.Forms.Button
$Button7.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button7.Location = New-Object System.Drawing.Point(717, 6)
$Button7.Size = New-Object System.Drawing.Size(75, 23)
$Button7.TabIndex = 1
$Button7.Text = "Select all"
$Button7.UseVisualStyleBackColor = $true
#~~< ListView1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListView1 = New-Object System.Windows.Forms.ListView
$ListView1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$ListView1.Location = New-Object System.Drawing.Point(6, 6)
$ListView1.Size = New-Object System.Drawing.Size(705, 489)
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
$ColumnHeader2.Width = 659
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
$TabPage1.Controls.Add($Button16)
$TabPage1.Controls.Add($Button6)
$TabPage1.Controls.Add($Button5)
$TabPage1.Controls.Add($Button7)
$TabPage1.Controls.Add($ListView1)
#~~< TabPage2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage2 = New-Object System.Windows.Forms.TabPage
$TabPage2.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage2.Location = New-Object System.Drawing.Point(4, 22)
$TabPage2.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage2.Size = New-Object System.Drawing.Size(800, 503)
$TabPage2.TabIndex = 1
$TabPage2.Text = "Settings"
$TabPage2.BackColor = [System.Drawing.SystemColors]::Control
#~~< Label19 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label19 = New-Object System.Windows.Forms.Label
$Label19.Location = New-Object System.Drawing.Point(7, 372)
$Label19.Size = New-Object System.Drawing.Size(145, 14)
$Label19.TabIndex = 38
$Label19.Text = "BIPrivatekey Location:"
#~~< TextBox13 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox13 = New-Object System.Windows.Forms.TextBox
$TextBox13.Location = New-Object System.Drawing.Point(139, 349)
$TextBox13.ReadOnly = $true
$TextBox13.Size = New-Object System.Drawing.Size(96, 20)
$TextBox13.TabIndex = 33
$TextBox13.Text = ""
$TextBox13.add_TextChanged({TextBox13TextChanged($TextBox13)})
#~~< Label18 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label18 = New-Object System.Windows.Forms.Label
$Label18.Font = New-Object System.Drawing.Font("Stencil Std", 12.0, [System.Drawing.FontStyle]::Bold, [System.Drawing.GraphicsUnit]::Point, ([System.Byte](0)))
$Label18.Location = New-Object System.Drawing.Point(6, 223)
$Label18.Size = New-Object System.Drawing.Size(235, 29)
$Label18.TabIndex = 37
$Label18.Text = "Sign File Settings"
$Label18.add_Click({Label18Click($Label18)})
#~~< Label16 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label16 = New-Object System.Windows.Forms.Label
$Label16.Location = New-Object System.Drawing.Point(6, 292)
$Label16.Size = New-Object System.Drawing.Size(643, 14)
$Label16.TabIndex = 34
$Label16.Text = "Path to Arma 3 Tools (DSCreateKey):"
$Label16.add_Click({Label16Click($Label16)})
#~~< Label15 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label15 = New-Object System.Windows.Forms.Label
$Label15.Location = New-Object System.Drawing.Point(139, 332)
$Label15.Size = New-Object System.Drawing.Size(145, 14)
$Label15.TabIndex = 32
$Label15.Text = "Sign Version:"
$Label15.add_Click({Label15Click($Label15)})
#~~< Label13 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label13 = New-Object System.Windows.Forms.Label
$Label13.Location = New-Object System.Drawing.Point(6, 386)
$Label13.Size = New-Object System.Drawing.Size(785, 15)
$Label13.TabIndex = 29
$Label13.Text = ""
$Label13.add_Click({Label13Click($Label13)})
#~~< Label17 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label17 = New-Object System.Windows.Forms.Label
$Label17.Location = New-Object System.Drawing.Point(6, 252)
$Label17.Size = New-Object System.Drawing.Size(145, 14)
$Label17.TabIndex = 36
$Label17.Text = "PBO prefix:"
$Label17.add_Click({Label17Click($Label17)})
#~~< Button17 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button17 = New-Object System.Windows.Forms.Button
$Button17.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button17.Location = New-Object System.Drawing.Point(738, 309)
$Button17.Size = New-Object System.Drawing.Size(54, 21)
$Button17.TabIndex = 28
$Button17.Text = "Browse"
$Button17.UseVisualStyleBackColor = $true
#~~< Label14 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label14 = New-Object System.Windows.Forms.Label
$Label14.Location = New-Object System.Drawing.Point(7, 332)
$Label14.Size = New-Object System.Drawing.Size(145, 14)
$Label14.TabIndex = 31
$Label14.Text = "Authority Name Prefix:"
$Label14.add_Click({Label14Click($Label14)})
#~~< TextBoxBISignPrefix >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBoxBISignPrefix = New-Object System.Windows.Forms.TextBox
$TextBoxBISignPrefix.Location = New-Object System.Drawing.Point(7, 349)
$TextBoxBISignPrefix.Size = New-Object System.Drawing.Size(100, 20)
$TextBoxBISignPrefix.TabIndex = 30
$TextBoxBISignPrefix.Text = "epoch"
#~~< Button14 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button14 = New-Object System.Windows.Forms.Button
$Button14.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button14.Location = New-Object System.Drawing.Point(738, 185)
$Button14.Size = New-Object System.Drawing.Size(54, 21)
$Button14.TabIndex = 18
$Button14.Text = "Browse"
$Button14.UseVisualStyleBackColor = $true
#~~< TextBoxPboPrefix >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBoxPboPrefix = New-Object System.Windows.Forms.TextBox
$TextBoxPboPrefix.Location = New-Object System.Drawing.Point(6, 269)
$TextBoxPboPrefix.Size = New-Object System.Drawing.Size(365, 20)
$TextBoxPboPrefix.TabIndex = 35
$TextBoxPboPrefix.Text = "x\addons"
#~~< Label12 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label12 = New-Object System.Windows.Forms.Label
$Label12.Location = New-Object System.Drawing.Point(6, 167)
$Label12.Size = New-Object System.Drawing.Size(230, 15)
$Label12.TabIndex = 17
$Label12.Text = "Server PBO Output Folder:"
#~~< TextBox11 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox11 = New-Object System.Windows.Forms.TextBox
$TextBox11.Location = New-Object System.Drawing.Point(7, 309)
$TextBox11.Size = New-Object System.Drawing.Size(725, 20)
$TextBox11.TabIndex = 27
$TextBox11.Text = ""
#~~< TextBox10 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox10 = New-Object System.Windows.Forms.TextBox
$TextBox10.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox10.Location = New-Object System.Drawing.Point(6, 185)
$TextBox10.Size = New-Object System.Drawing.Size(726, 20)
$TextBox10.TabIndex = 16
$TextBox10.Text = ""
#~~< Button13 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button13 = New-Object System.Windows.Forms.Button
$Button13.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button13.Location = New-Object System.Drawing.Point(738, 144)
$Button13.Size = New-Object System.Drawing.Size(54, 21)
$Button13.TabIndex = 15
$Button13.Text = "Browse"
$Button13.UseVisualStyleBackColor = $true
#~~< Label11 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label11 = New-Object System.Windows.Forms.Label
$Label11.Location = New-Object System.Drawing.Point(6, 126)
$Label11.Size = New-Object System.Drawing.Size(230, 15)
$Label11.TabIndex = 14
$Label11.Text = "Output Folder MpMissions:"
#~~< TextBox9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox9 = New-Object System.Windows.Forms.TextBox
$TextBox9.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox9.Location = New-Object System.Drawing.Point(6, 144)
$TextBox9.Size = New-Object System.Drawing.Size(726, 20)
$TextBox9.TabIndex = 13
$TextBox9.Text = ""
#~~< Button9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button9 = New-Object System.Windows.Forms.Button
$Button9.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button9.Location = New-Object System.Drawing.Point(678, 464)
$Button9.Size = New-Object System.Drawing.Size(54, 21)
$Button9.TabIndex = 12
$Button9.Text = "Save"
$Button9.UseVisualStyleBackColor = $true
#~~< Button8 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button8 = New-Object System.Windows.Forms.Button
$Button8.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button8.Location = New-Object System.Drawing.Point(738, 464)
$Button8.Size = New-Object System.Drawing.Size(54, 21)
$Button8.TabIndex = 11
$Button8.Text = "Delete"
$Button8.UseVisualStyleBackColor = $true
#~~< Label7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label7 = New-Object System.Windows.Forms.Label
$Label7.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left))
$Label7.Location = New-Object System.Drawing.Point(6, 446)
$Label7.Size = New-Object System.Drawing.Size(230, 15)
$Label7.TabIndex = 10
$Label7.Text = "Save Settings:"
#~~< TextBox5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox5 = New-Object System.Windows.Forms.TextBox
$TextBox5.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox5.Enabled = $false
$TextBox5.Location = New-Object System.Drawing.Point(6, 464)
$TextBox5.Size = New-Object System.Drawing.Size(666, 20)
$TextBox5.TabIndex = 9
$TextBox5.Text = ""
#~~< Button3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button3 = New-Object System.Windows.Forms.Button
$Button3.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button3.Location = New-Object System.Drawing.Point(738, 62)
$Button3.Size = New-Object System.Drawing.Size(54, 21)
$Button3.TabIndex = 8
$Button3.Text = "Browse"
$Button3.UseVisualStyleBackColor = $true
#~~< Label3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label3 = New-Object System.Windows.Forms.Label
$Label3.Location = New-Object System.Drawing.Point(6, 44)
$Label3.Size = New-Object System.Drawing.Size(230, 15)
$Label3.TabIndex = 7
$Label3.Text = "Path to Arma 3 Addon builder:"
#~~< TextBox3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox3 = New-Object System.Windows.Forms.TextBox
$TextBox3.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox3.Location = New-Object System.Drawing.Point(6, 62)
$TextBox3.Size = New-Object System.Drawing.Size(726, 20)
$TextBox3.TabIndex = 6
$TextBox3.Text = ""
#~~< Button2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button2 = New-Object System.Windows.Forms.Button
$Button2.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button2.Location = New-Object System.Drawing.Point(738, 103)
$Button2.Size = New-Object System.Drawing.Size(54, 21)
$Button2.TabIndex = 5
$Button2.Text = "Browse"
$Button2.UseVisualStyleBackColor = $true
#~~< Label2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label2 = New-Object System.Windows.Forms.Label
$Label2.Location = New-Object System.Drawing.Point(6, 85)
$Label2.Size = New-Object System.Drawing.Size(230, 15)
$Label2.TabIndex = 4
$Label2.Text = "Path to Epoch Public Github:"
#~~< TextBox2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox2 = New-Object System.Windows.Forms.TextBox
$TextBox2.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox2.Location = New-Object System.Drawing.Point(6, 103)
$TextBox2.Size = New-Object System.Drawing.Size(726, 20)
$TextBox2.TabIndex = 3
$TextBox2.Text = ""
#~~< Button1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button1 = New-Object System.Windows.Forms.Button
$Button1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button1.Location = New-Object System.Drawing.Point(738, 21)
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
$TextBox1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox1.Location = New-Object System.Drawing.Point(6, 21)
$TextBox1.Size = New-Object System.Drawing.Size(726, 20)
$TextBox1.TabIndex = 0
$TextBox1.Text = ""
$TabPage2.Controls.Add($Label19)
$TabPage2.Controls.Add($TextBox13)
$TabPage2.Controls.Add($Label18)
$TabPage2.Controls.Add($Label16)
$TabPage2.Controls.Add($Label15)
$TabPage2.Controls.Add($Label13)
$TabPage2.Controls.Add($Label17)
$TabPage2.Controls.Add($Button17)
$TabPage2.Controls.Add($Label14)
$TabPage2.Controls.Add($TextBoxBISignPrefix)
$TabPage2.Controls.Add($Button14)
$TabPage2.Controls.Add($TextBoxPboPrefix)
$TabPage2.Controls.Add($Label12)
$TabPage2.Controls.Add($TextBox11)
$TabPage2.Controls.Add($TextBox10)
$TabPage2.Controls.Add($Button13)
$TabPage2.Controls.Add($Label11)
$TabPage2.Controls.Add($TextBox9)
$TabPage2.Controls.Add($Button9)
$TabPage2.Controls.Add($Button8)
$TabPage2.Controls.Add($Label7)
$TabPage2.Controls.Add($TextBox5)
$TabPage2.Controls.Add($Button3)
$TabPage2.Controls.Add($Label3)
$TabPage2.Controls.Add($TextBox3)
$TabPage2.Controls.Add($Button2)
$TabPage2.Controls.Add($Label2)
$TabPage2.Controls.Add($TextBox2)
$TabPage2.Controls.Add($Button1)
$TabPage2.Controls.Add($Label1)
$TabPage2.Controls.Add($TextBox1)
#~~< TabPage3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage3 = New-Object System.Windows.Forms.TabPage
$TabPage3.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage3.Location = New-Object System.Drawing.Point(4, 22)
$TabPage3.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage3.Size = New-Object System.Drawing.Size(800, 503)
$TabPage3.TabIndex = 2
$TabPage3.Text = "Developers"
$TabPage3.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button15 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button15 = New-Object System.Windows.Forms.Button
$Button15.Location = New-Object System.Drawing.Point(6, 240)
$Button15.Size = New-Object System.Drawing.Size(96, 21)
$Button15.TabIndex = 26
$Button15.Text = "Reload Versions"
$Button15.UseVisualStyleBackColor = $true
#~~< Button12 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button12 = New-Object System.Windows.Forms.Button
$Button12.Location = New-Object System.Drawing.Point(6, 267)
$Button12.Size = New-Object System.Drawing.Size(96, 21)
$Button12.TabIndex = 25
$Button12.Text = "Update Versions"
$Button12.UseVisualStyleBackColor = $true
#~~< Label6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label6 = New-Object System.Windows.Forms.Label
$Label6.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Label6.Location = New-Object System.Drawing.Point(508, 9)
$Label6.Size = New-Object System.Drawing.Size(141, 21)
$Label6.TabIndex = 15
$Label6.Text = "Arma 3 Mod Output Folder:"
$Label6.add_Click({Label6Click($Label6)})
#~~< TextBox8 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox8 = New-Object System.Windows.Forms.TextBox
$TextBox8.Location = New-Object System.Drawing.Point(6, 214)
$TextBox8.Size = New-Object System.Drawing.Size(96, 20)
$TextBox8.TabIndex = 24
$TextBox8.Text = ""
#~~< ComboBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ComboBox1 = New-Object System.Windows.Forms.ComboBox
$ComboBox1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$ComboBox1.FormattingEnabled = $true
$ComboBox1.Location = New-Object System.Drawing.Point(655, 6)
$ComboBox1.SelectedIndex = -1
$ComboBox1.Size = New-Object System.Drawing.Size(137, 21)
$ComboBox1.TabIndex = 14
$ComboBox1.Text = "Select Arma Mod"
#~~< TextBox7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox7 = New-Object System.Windows.Forms.TextBox
$TextBox7.Location = New-Object System.Drawing.Point(6, 173)
$TextBox7.Size = New-Object System.Drawing.Size(96, 20)
$TextBox7.TabIndex = 22
$TextBox7.Text = ""
$TextBox7.add_TextChanged({TextBox7TextChanged($TextBox7)})
#~~< Label10 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label10 = New-Object System.Windows.Forms.Label
$Label10.Location = New-Object System.Drawing.Point(6, 197)
$Label10.Size = New-Object System.Drawing.Size(145, 14)
$Label10.TabIndex = 21
$Label10.Text = "Public Build:"
#~~< Label9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label9 = New-Object System.Windows.Forms.Label
$Label9.Location = New-Object System.Drawing.Point(6, 156)
$Label9.Size = New-Object System.Drawing.Size(145, 14)
$Label9.TabIndex = 18
$Label9.Text = "Private Build:"
$Label9.add_Click({Label9Click($Label9)})
#~~< TextBox6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox6 = New-Object System.Windows.Forms.TextBox
$TextBox6.Location = New-Object System.Drawing.Point(6, 92)
$TextBox6.Size = New-Object System.Drawing.Size(96, 20)
$TextBox6.TabIndex = 16
$TextBox6.Text = ""
#~~< Label8 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label8 = New-Object System.Windows.Forms.Label
$Label8.Location = New-Object System.Drawing.Point(6, 74)
$Label8.Size = New-Object System.Drawing.Size(145, 14)
$Label8.TabIndex = 15
$Label8.Text = "Mod Version:"
#~~< CheckBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$CheckBox1 = New-Object System.Windows.Forms.CheckBox
$CheckBox1.Location = New-Object System.Drawing.Point(6, 6)
$CheckBox1.Size = New-Object System.Drawing.Size(66, 24)
$CheckBox1.TabIndex = 14
$CheckBox1.Text = "Enable"
$CheckBox1.UseVisualStyleBackColor = $true
#~~< Label5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label5 = New-Object System.Windows.Forms.Label
$Label5.Location = New-Object System.Drawing.Point(6, 33)
$Label5.Size = New-Object System.Drawing.Size(230, 15)
$Label5.TabIndex = 12
$Label5.Text = "Path to Epoch Private Github"
#~~< TextBox4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox4 = New-Object System.Windows.Forms.TextBox
$TextBox4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox4.Location = New-Object System.Drawing.Point(6, 51)
$TextBox4.Size = New-Object System.Drawing.Size(726, 20)
$TextBox4.TabIndex = 11
$TextBox4.Text = ""
#~~< Button4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button4 = New-Object System.Windows.Forms.Button
$Button4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button4.Location = New-Object System.Drawing.Point(738, 51)
$Button4.Size = New-Object System.Drawing.Size(54, 21)
$Button4.TabIndex = 13
$Button4.Text = "Browse"
$Button4.UseVisualStyleBackColor = $true
$TabPage3.Controls.Add($Button15)
$TabPage3.Controls.Add($Button12)
$TabPage3.Controls.Add($Label6)
$TabPage3.Controls.Add($TextBox8)
$TabPage3.Controls.Add($ComboBox1)
$TabPage3.Controls.Add($TextBox7)
$TabPage3.Controls.Add($Label10)
$TabPage3.Controls.Add($Label9)
$TabPage3.Controls.Add($TextBox6)
$TabPage3.Controls.Add($Label8)
$TabPage3.Controls.Add($CheckBox1)
$TabPage3.Controls.Add($Label5)
$TabPage3.Controls.Add($TextBox4)
$TabPage3.Controls.Add($Button4)
$TabControl1.Controls.Add($TabPage1)
$TabControl1.Controls.Add($TabPage2)
$TabControl1.Controls.Add($TabPage3)
$TabControl1.SelectedIndex = 0
$Form1.Controls.Add($ProgressBar1)
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
#~~< FolderBrowserDialog1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$FolderBrowserDialog1 = New-Object System.Windows.Forms.FolderBrowserDialog
#~~< components >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$components = New-Object System.ComponentModel.Container
#~~< Timer1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Timer1 = New-Object System.Windows.Forms.Timer($components)

#endregion

#region Custom Code
	
	# Defines
		
	$Label4.Text = Get-Random -InputObject "Bug? That's not a bug, that's a feature.", "A bug in the code is worth two in the documentation."
	
	$ListView1.CheckBoxes = $true
	$FolderBrowserDialog1.ShowNewFolderButton = $false
	$TextBox1.Text = "Arma 3 not found"
	$TextBox3.Text = "Arma Tools not found"
	$TextBox11.Text = "Arma Tools not found"
	$TextBox2.Text = "C:\"
	$TextBox4.Text = "C:\"
	$TextBox5.Text = (Join-Path $env:APPDATA "\Epoch_PBO.ini")
	
	$OS = (Get-WmiObject Win32_OperatingSystem).OSArchitecture
		
	$armaPathArr = switch($OS) #gets array of objects from registry
	{
		"64-bit" { Get-ChildItem "HKLM:\SOFTWARE\WOW6432Node\Bohemia Interactive\" | ForEach-Object { Get-ItemProperty $_.pspath } }
		"32-bit" { Get-ChildItem "HKLM:\SOFTWARE\Bohemia Interactive Studio\" | ForEach-Object { Get-ItemProperty $_.pspath } }
		default { @( ) } #OS Architecture not recognized, might need to update Powershell version, should work with 2.0 (win7)
	}
		
	$TextBox1.Text = $armaPathArr.main | ForEach-Object { if ($_ -match "Arma 3") { return $_ } }
	$TextBox3.Text = $armaPathArr.path | ForEach-Object { if ($_ -match "AddonBuilder") { return $_ } }
	$TextBox11.Text = (Get-ItemProperty 'HKCU:\SOFTWARE\Bohemia Interactive\dscreatekey').path
	
	
	# Functions
		
	function fnc_populateListView
	{	
		$Script:listarr = @() #empty arr
		$folders = Get-ChildItem $TextBox2.Text -directory
				
		if ($Checkbox1.Checked)
		{
			if (Test-Path $TextBox4.Text)
			{
				$priv = Get-ChildItem $TextBox4.Text -directory
				$folders +=, $priv
			}
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
							$Script:listarr +=, $tmp
						}
						{ $_.contains("mpmissions") } 
						{
							$missions = Get-ChildItem $z.fullname -directory
							foreach ($mission in $missions)
							{
								$tmp = New-Object System.Windows.Forms.ListViewItem([System.String[]] ( @($mission.name, $mission.fullname) ), -1)
								$tmp.Name = $_
								$tmp.Group = $ListViewGroup13
								$Script:listarr +=, $tmp
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
								$Script:listarr +=, $tmp
							}
						}
					}
				}
			}
		}
		$ListView1.Items.AddRange([System.Windows.Forms.ListViewItem[]] ( $Script:listarr ))
	}
	
	function fnc_enableControls
	{
		$c1 = Test-Path (Join-Path $TextBox1.Text "\Arma3.exe")
		$c2 = Test-Path (Join-Path $TextBox2.Text "\Sources")
		$c3 = Test-Path (Join-Path $TextBox3.Text "\AddonBuilder.exe") -ErrorAction SilentlyContinue
		$c5 = Test-Path "P:\"

		if ($c1 -and $c2 -and $c3 -and $c5)
		{
			$Button5.Enabled = $true
			$Button6.Enabled = $true
			$Button7.Enabled = $true
			$Button16.Enabled = $true
			$ListView1.Enabled = $true
		}
		else
		{
			$Button5.Enabled = $false
			$Button6.Enabled = $false
			$Button7.Enabled = $false
			$Button16.Enabled = $false
			$ListView1.Enabled = $false
		}
		$Label4.Text = if (!$c5) 
		{ 
			"P:\ drive not mounted" 
		}
		elseif (Get-Process Arma3 -ErrorAction SilentlyContinue) #not a boolean, but any variable equals true and null equals false
		{
			"(WARNING) Arma 3 is running" 
		}
		else 
		{ 
			#"EPOCH_CODE and EPOCH_CONFIG are automatically merged into MPMissions PBO packs"
			"Tool is Ready! Please check items from the list you want to PBO"
		}
	}
		
	function fnc_reloadVersions
	{
		$p6 = Join-Path $Textbox4.Text "\version.txt"
		$p7 = Join-Path $Textbox4.Text "\build.txt"
		$p8 = Join-Path $Textbox2.Text "\build.txt"
		$Textbox6.Text = if (Test-Path $p6) { Get-Content $p6 } else { "Path not set" }
		$Textbox7.Text = if (Test-Path $p7) { Get-Content $p7 } else { "Path not set" }
		$Textbox8.Text = if (Test-Path $p8) { Get-Content $p8 } else { "Path not set" }
		$Textbox13.Text = if (Test-Path $p6) { (Get-Content $p6) -replace '[.]','' } else { "" }
	}
		
	function fnc_updateBuildNumber($inpath, $outpath, $increment)
	{
		if ($Checkbox1.Checked)
		{
			$path = Join-Path $inpath "\build.txt"				
			if (Test-Path $path)
			{
				$in = Get-Content $path
													
				$newBuild = [int]$in + $increment
				$Out = @(
					'build=' + [string]$newBuild + ';'
				)
												
				$Out | Out-File(Join-Path $outpath "\build.hpp") -Encoding "UTF8"
				$newBuild | Out-File $path -Encoding "UTF8"
				if ($increment -eq 1)
				{
					fnc_reloadVersions
				}
			}
		}
	}
		
	function fnc_updateVersions
	{
		$p6 = Join-Path $Textbox4.Text "\version.txt"
		$p7 = Join-Path $Textbox4.Text "\build.txt"
		$p8 = Join-Path $Textbox2.Text "\build.txt"
				
		if (($Textbox6.Text -ne "Path not set") -and (Test-Path $p6))
		{
			$TextBox6.Text | Out-File $p6 -Encoding "UTF8"
		}
		if (($Textbox7.Text -ne "Path not set") -and (Test-Path $p7))
		{
			$TextBox7.Text | Out-File $p7 -Encoding "UTF8"
		}
		if (($Textbox8.Text -ne "Path not set") -and (Test-Path $p8))
		{
			$TextBox8.Text | Out-File $p8 -Encoding "UTF8"
		}
	}
	
	function fnc_getSetPath($switch)
	{
		$FolderBrowserDialog1.ShowNewFolderButton = $true
		$FolderBrowserDialog1.ShowDialog()
		if ($FolderBrowserDialog1.SelectedPath)
		{
			$p = $FolderBrowserDialog1.SelectedPath
			switch($switch)
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
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
					else
					{
						$ListView1.Items.Clear()
						fnc_populateListView
					}
				}
								
				3 # Location of Addob Builder
				{ 
					$TextBox3.Text = $p
					$tp = Join-Path $p "\AddonBuilder.exe"
					if (!(Test-Path $tp))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
				}
								
				4 # Location of Private Github
				{ 
					$TextBox4.Text = $p
					$tp = Join-Path $p "\Source_CC_BY-NC-ND"
					if (!(Test-Path $tp))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
					else
					{
						$ListView1.Items.Clear()
						fnc_populateListView
					}
				}
								
				5 # Location of Packed missions
				{ 
					$TextBox9.Text = $p
					if (!(Test-Path $p))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
				}
								
				6 # Location of Packed missions
				{ 
					$TextBox10.Text = $p
					if (!(Test-Path $p))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
				}
				
				7 # Location of Addob Builder
				{ 
					$TextBox11.Text = $p
					$tp = Join-Path $p "\DSCreateKey.exe"
					if (!(Test-Path $tp))
					{
						[System.Windows.Forms.MessageBox]::Show(($tp + " Not found."), "Warning")
					}
				}
			}
			$FolderBrowserDialog1.SelectedPath = $null
		}
	}
		
	function fnc_selectAll($boo)
	{
		foreach ($x in $Script:listarr)
		{
			$x.checked = $boo
		}
	}
		
	function fnc_selectSelected
	{
		foreach ($x in $Script:listarr)
		{
			$x.checked = $x.selected
		}
	}
		
	function fnc_devEnableDisable
	{
		$cbstate = $CheckBox1.Checked
										
		$TextBox4.Enabled = $cbstate
		$TextBox6.Enabled = $cbstate
		$TextBox7.Enabled = $cbstate
		$TextBox8.Enabled = $cbstate
		$TextBox13.Enabled = $cbstate			
		$TextBox11.Enabled = $cbstate
		$TextBoxPboPrefix.Enabled = $cbstate
		$TextBoxBISignPrefix.Enabled = $cbstate
						
		$Button4.Enabled = $cbstate
		$Button15.Enabled = $cbstate
		$Button12.Enabled = $cbstate
		$Button17.Enabled = $cbstate
								
		$ComboBox1.Enabled = $cbstate
						
		$ListView1.Items.Clear()
		fnc_populateListView
	}
	
	function fnc_outputmodcpp
	{
		$Output = Join-Path $TextBox1.Text $ComboBox1.SelectedItem
		$Out = @(					
			'dir = "@Epoch";'
			'name = "Epoch Mod ' + $Textbox6.Text + '";'
			'actionName = "Website";'
			'picture = "mod.paa";'
			'action = "http://www.epochmod.com";'
			'overview = "Open world survival mod set in the year 2035, Just two years after the mass extinction of billions of people. Those that remain are left with remnants of a once technological society. Try to survive, build, or explore your way through the harsh dynamic environment.";'
		)
		
		$Out | Out-File (Join-Path $Output "mod.cpp")
	}
		
	function fnc_settingsSave
	{
		$Out = @(
					
			$ComboBox1.SelectedIndex
			$TextBox1.Text
			$TextBox3.Text
			$TextBox2.Text
			$TextBox9.Text
			$TextBox1.Text
			$TextBox10.Text
			$TextBox4.Text
			$CheckBox1.Checked
			$TextBox11.Text
			$TextBoxPboPrefix.Text
			$TextBoxBISignPrefix.Text
		)
				
		$Out | Out-File $TextBox5.Text
	}
		
	function fnc_settingsLoad
	{
		if (Test-Path $TextBox5.Text)
		{
			$in = Get-Content $TextBox5.Text
										
			$ComboBox1.SelectedIndex = $in[0]
			$TextBox1.Text = $in[1]
			$TextBox3.Text = $in[2]
			$TextBox2.Text = $in[3]
			$TextBox9.Text = $in[4]
			$TextBox1.Text = $in[5]
			$TextBox10.Text = $in[6]
			$TextBox4.Text = $in[7]
						
			#Hacky Convert str to bool
			$state = if ($in[8] -eq "True") { $true } else { $false }
			$CheckBox1.Checked = $state
			
			$TextBox11.Text = $in[9]
						
			$TextBoxPboPrefix.Text = if ($in[10]) { $in[10] } else { "x\addons" }
			$TextBoxBISignPrefix.Text = if ($in[11]) { $in[11] } else { "epoch" }
			
		}
	}
		
	function fnc_CreatePBO
	{
		
		#
		$signName = ($TextBoxBISignPrefix.Text + $TextBox13.Text)
		$signFileName = ($signName + ".biprivatekey")
		$signfile = Join-Path $TextBox11.Text $signFileName
				
		# make privatekey if it does not exist
		if (!(Test-Path $signfile))
		{ 
			$createKeyExecutable = Join-Path $TextBox11.Text "DSCreateKey.exe"
			$argz = @($signName)												
			Start-Process -FilePath $createKeyExecutable -WorkingDirectory $TextBox11.Text -ArgumentList $argz -WindowStyle Minimized -Wait
			$Label4.Text = "Making Private Key... Please wait"
			$Label4.Refresh()
		}
				
		fnc_outputmodcpp				
		# increase build numbers
				
		$incrementClientBuild = 1
		$incrementServerBuild = 1
		
		
		$Bob = Join-Path $TextBox3.Text "\AddonBuilder.exe"
		$includes = "P:\includes.txt"
		if (!(Test-Path $includes)) { "*.xml;*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.rvmat;*.sqm;*.ext;*.hpp" | Out-File $includes -Encoding "UTF8"}		
		
		foreach ($i in $Script:listarr) {if ($i.checked) { $ct++ }}
		$cnt = 100 / $ct
				
		$Label4.Text = "Building PBO ... Please wait"
		$Label4.Refresh()
		
		foreach ($x in $Script:listarr)
		{										
			if ($x.checked)
			{
				$name = $x.subitems[0].Text
				$tmp = "P:\$name"
				$ProgressBar1.Value = $ProgressBar1.Value + [Math]::Floor($cnt)
				$ProgressBar1.Refresh()
				
				switch($x.group.header)
				{
					"Server" 
					{
						$Output = $TextBox10.Text
						if (Test-Path $tmp) { Remove-Item -Path $tmp -Recurse }														
						Copy-Item -Path $x.subitems[1].Text -Destination $tmp -Recurse
												
						fnc_updateBuildNumber $TextBox2.Text ($x.subitems[1].Text) $incrementServerBuild
						$incrementServerBuild = 0
																		
						$argz = @($tmp, ( '"' + $Output + '"' ), "-packonly", "-clear", "-prefix=$name", "-project=P:\", "-include=$includes")
												
						$Label4.Text = "Building Server PBO (" + $x.subitems[0].Text + ".pbo) ... Please wait"
						$Label4.Refresh()
						
						Start-Process -FilePath $Bob -ArgumentList $argz -WindowStyle Minimized -Wait
					}
					"Client" 
					{ 
						$name = Join-Path $TextBoxPboPrefix.Text $name
						$tmp = "P:\$name"						
						
						fnc_updateBuildNumber $TextBox4.Text ($x.subitems[1].Text) $incrementClientBuild
						$incrementClientBuild = 0
												
						$Output = $TextBox1.Text + "\" + $ComboBox1.SelectedItem + "\Addons"
						if (Test-Path $tmp) { Remove-Item -Path $tmp -Recurse }														
						Copy-Item -Path $x.subitems[1].Text -Destination $tmp -Recurse
																		
						$signFlag = ""
						if (Test-Path $signfile) { $signFlag = ('-sign="' + $signfile + '"') }
																		
						$argz = @($tmp, ( '"' + $Output + '"' ), "-clear", "-prefix=$name", "-project=P:\", "-include=$includes", $signFlag)
												
						$Label4.Text = "Building Client PBO (" + $x.subitems[0].Text +  ".pbo) ... Please wait"
						$Label4.Refresh()
						
						Start-Process -FilePath $Bob -ArgumentList $argz -WindowStyle Minimized -Wait
					}
					"Missions" 
					{
						$Output = $TextBox9.Text
						$src = $TextBox2.Text + "\Sources\"
												
						fnc_updateBuildNumber $TextBox2.Text ($src + "epoch_config") $incrementServerBuild
						$incrementServerBuild = 0
						
						if (Test-Path $tmp) { Remove-Item -Path $tmp -Recurse }
						Copy-Item -Path $x.subitems[1].Text -Destination $tmp -Recurse
						Copy-Item($src + "epoch_code") -Destination $tmp -Recurse
						Copy-Item($src + "epoch_config") -Destination $tmp -Recurse
						Copy-Item($src + "description.ext") -Destination $tmp
																		
						$argz = @($tmp, ( '"' + $Output + '"' ), "-clear", "-prefix=\", "-project=P:\", "-include=$includes")
												
						$Label4.Text = "Building MPMission PBO (" + $x.subitems[0].Text + ".pbo) ... Please wait"
						$Label4.Refresh()
						
						Start-Process -FilePath $Bob -ArgumentList $argz -WindowStyle Minimized -Wait
					}
				}
				#cleanup
				if (Test-Path $tmp) { Remove-Item -Path $tmp -Recurse }
				if (Test-Path($env:temp + "\" + $name)) { Remove-Item -Path($env:temp + "\" + $name) -Recurse }
			}
		}
		$ProgressBar1.Value = 0
		$ProgressBar1.Refresh()
	}
	
	
	# Event Handlers
	$Button1.Add_Click({ fnc_getSetPath(1) })
	$Button2.Add_Click({ fnc_getSetPath(2) })
	$Button3.Add_Click({ fnc_getSetPath(3) })
	$Button4.Add_Click({ fnc_getSetPath(4) })
	$Button13.Add_Click({ fnc_getSetPath(5) })
	$Button14.Add_Click({ fnc_getSetPath(6) })
	$Button17.Add_Click({ fnc_getSetPath(7) })
	$Button6.Add_Click({ fnc_CreatePBO })
	
	$Button7.Add_Click({ fnc_selectAll($true) })
	$Button5.Add_Click({ fnc_selectAll($false) })
	$Button12.Add_Click({ fnc_updateVersions })
	$Button15.Add_Click({ fnc_reloadVersions })
	$Button16.Add_Click({ fnc_selectSelected })
	$Button8.Add_Click({ Remove-Item -Path $TextBox5.Text -ErrorAction SilentlyContinue })
	$Button9.Add_Click({ fnc_settingsSave })
	$CheckBox1.Add_CheckedChanged({ fnc_devEnableDisable })
	
	
	# Main code
	
	$mods = Get-ChildItem $TextBox1.Text -directory
	$modsarr = @()	
	foreach ($x in $mods)
	{
		if (Test-Path($x.fullname + "\mod.cpp"))
		{
			$modsarr += ,$x.name
		}
	}
	
	$ComboBox1.Items.AddRange([System.Object[]] ( $modsarr ))
		
	fnc_settingsLoad
	
	# Fake endless loop, spawned thread
	$Timer1.Start()
	$Timer1.Interval = 1000
	$Timer1.Add_tick({ fnc_enableControls })
		
	if ($TextBox2.Text)
	{
		fnc_populateListView
	}
		
	fnc_devEnableDisable
	fnc_reloadVersions
		
		
	$signName = ($TextBoxBISignPrefix.Text + $TextBox13.Text)
	$signFileName = ($signName + ".biprivatekey")
	$signfile = Join-Path $TextBox11.Text $signFileName
	$signFlag = ""
	if (Test-Path $signfile) { 
		$Label13.Text = $signfile
		$signFlag = ('-sign="' + $signfile + '"') 
	}
	else
	{
		$Label13.Text = "Path Not Found!"
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

function Label16Click( $object ){

}

function TextBox13TextChanged( $object ){

}

function Label15Click( $object ){

}

function Label14Click( $object ){

}

function Label13Click( $object ){

}

function Label6Click( $object ){

}

function TextBox7TextChanged( $object ){

}

function Label9Click( $object ){

}

function Label4Click( $object ){

}

function Label17Click( $object ){

}

function Label18Click( $object ){

}

Main # This call must remain below all other event functions

#endregion
# ========================================================
#
# 	Script Information
#
#	Title:					Epoch PBO Packing Tool - EpochMod.com
#	Author:					Raimonds Virtoss - Raymix @ Epoch UI code
#  Contributors: 			Aaron Clark - [VB]AWOL
#	Originally created:	4/24/2016 - 17:56:19
#	Description:			Form based (GUI) Tool to Pack or binarize Epoch PBOs. Scans your github repos and automatically creates a list of relevant folders for packaging
#	Usage:					.EXE file will be provided when script is done, for now simply right click it and run with powershell.
#	
# ========================================================

