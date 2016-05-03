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
$Form1.ClientSize = New-Object System.Drawing.Size(793, 555)
$Form1.Text = "Epoch PBO Packing Tool"
#~~< Label4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label4 = New-Object System.Windows.Forms.Label
$Label4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$Label4.Location = New-Object System.Drawing.Point(12, 7)
$Label4.Size = New-Object System.Drawing.Size(551, 20)
$Label4.TabIndex = 1
$Label4.Text = "Info bar"
$Label4.TextAlign = [System.Drawing.ContentAlignment]::MiddleCenter
#~~< TabControl1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabControl1 = New-Object System.Windows.Forms.TabControl
$TabControl1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TabControl1.Location = New-Object System.Drawing.Point(12, 30)
$TabControl1.Size = New-Object System.Drawing.Size(769, 513)
$TabControl1.TabIndex = 0
$TabControl1.Text = ""
#~~< TabPage1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TabPage1 = New-Object System.Windows.Forms.TabPage
$TabPage1.BorderStyle = [System.Windows.Forms.BorderStyle]::FixedSingle
$TabPage1.Location = New-Object System.Drawing.Point(4, 22)
$TabPage1.Padding = New-Object System.Windows.Forms.Padding(3)
$TabPage1.Size = New-Object System.Drawing.Size(761, 487)
$TabPage1.TabIndex = 0
$TabPage1.Text = "Packager"
$TabPage1.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button6 = New-Object System.Windows.Forms.Button
$Button6.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button6.Location = New-Object System.Drawing.Point(678, 456)
$Button6.Size = New-Object System.Drawing.Size(75, 23)
$Button6.TabIndex = 3
$Button6.Text = "Create PBO"
$Button6.UseVisualStyleBackColor = $true
#~~< Button5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button5 = New-Object System.Windows.Forms.Button
$Button5.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button5.Location = New-Object System.Drawing.Point(678, 35)
$Button5.Size = New-Object System.Drawing.Size(75, 23)
$Button5.TabIndex = 2
$Button5.Text = "Select none"
$Button5.UseVisualStyleBackColor = $true
#~~< Button7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button7 = New-Object System.Windows.Forms.Button
$Button7.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button7.Location = New-Object System.Drawing.Point(678, 6)
$Button7.Size = New-Object System.Drawing.Size(75, 23)
$Button7.TabIndex = 1
$Button7.Text = "Select all"
$Button7.UseVisualStyleBackColor = $true
#~~< ListView1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ListView1 = New-Object System.Windows.Forms.ListView
$ListView1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$ListView1.Location = New-Object System.Drawing.Point(6, 6)
$ListView1.Size = New-Object System.Drawing.Size(666, 473)
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
$TabPage2.Size = New-Object System.Drawing.Size(761, 487)
$TabPage2.TabIndex = 1
$TabPage2.Text = "Settings"
$TabPage2.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button14 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button14 = New-Object System.Windows.Forms.Button
$Button14.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button14.Location = New-Object System.Drawing.Point(699, 185)
$Button14.Size = New-Object System.Drawing.Size(54, 21)
$Button14.TabIndex = 18
$Button14.Text = "Browse"
$Button14.UseVisualStyleBackColor = $true
#~~< Label12 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label12 = New-Object System.Windows.Forms.Label
$Label12.Location = New-Object System.Drawing.Point(6, 167)
$Label12.Size = New-Object System.Drawing.Size(230, 15)
$Label12.TabIndex = 17
$Label12.Text = "Save packed server files in:"
#~~< TextBox10 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox10 = New-Object System.Windows.Forms.TextBox
$TextBox10.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox10.Location = New-Object System.Drawing.Point(6, 185)
$TextBox10.Size = New-Object System.Drawing.Size(687, 20)
$TextBox10.TabIndex = 16
$TextBox10.Text = "\\server\a3server\@epochhive\addons"
#~~< Button13 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button13 = New-Object System.Windows.Forms.Button
$Button13.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button13.Location = New-Object System.Drawing.Point(699, 144)
$Button13.Size = New-Object System.Drawing.Size(54, 21)
$Button13.TabIndex = 15
$Button13.Text = "Browse"
$Button13.UseVisualStyleBackColor = $true
#~~< Label11 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label11 = New-Object System.Windows.Forms.Label
$Label11.Location = New-Object System.Drawing.Point(6, 126)
$Label11.Size = New-Object System.Drawing.Size(230, 15)
$Label11.TabIndex = 14
$Label11.Text = "Save Packed Missions in:"
#~~< TextBox9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox9 = New-Object System.Windows.Forms.TextBox
$TextBox9.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox9.Location = New-Object System.Drawing.Point(6, 144)
$TextBox9.Size = New-Object System.Drawing.Size(687, 20)
$TextBox9.TabIndex = 13
$TextBox9.Text = "\\server\a3server\@epochserver\mpmissions\"
#~~< Button9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button9 = New-Object System.Windows.Forms.Button
$Button9.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button9.Location = New-Object System.Drawing.Point(639, 448)
$Button9.Size = New-Object System.Drawing.Size(54, 21)
$Button9.TabIndex = 12
$Button9.Text = "Save"
$Button9.UseVisualStyleBackColor = $true
#~~< Button8 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button8 = New-Object System.Windows.Forms.Button
$Button8.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button8.Location = New-Object System.Drawing.Point(699, 448)
$Button8.Size = New-Object System.Drawing.Size(54, 21)
$Button8.TabIndex = 11
$Button8.Text = "Delete"
$Button8.UseVisualStyleBackColor = $true
#~~< Label7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label7 = New-Object System.Windows.Forms.Label
$Label7.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left))
$Label7.Location = New-Object System.Drawing.Point(6, 430)
$Label7.Size = New-Object System.Drawing.Size(230, 15)
$Label7.TabIndex = 10
$Label7.Text = "Save Settings:"
#~~< TextBox5 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox5 = New-Object System.Windows.Forms.TextBox
$TextBox5.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Bottom -bor [System.Windows.Forms.AnchorStyles]::Left -bor [System.Windows.Forms.AnchorStyles]::Right))
$TextBox5.Enabled = $false
$TextBox5.Location = New-Object System.Drawing.Point(6, 448)
$TextBox5.Size = New-Object System.Drawing.Size(627, 20)
$TextBox5.TabIndex = 9
$TextBox5.Text = ""
#~~< Button3 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button3 = New-Object System.Windows.Forms.Button
$Button3.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button3.Location = New-Object System.Drawing.Point(699, 62)
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
$TextBox3.Size = New-Object System.Drawing.Size(687, 20)
$TextBox3.TabIndex = 6
$TextBox3.Text = ""
#~~< Button2 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button2 = New-Object System.Windows.Forms.Button
$Button2.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button2.Location = New-Object System.Drawing.Point(699, 103)
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
$TextBox2.Size = New-Object System.Drawing.Size(687, 20)
$TextBox2.TabIndex = 3
$TextBox2.Text = ""
#~~< Button1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button1 = New-Object System.Windows.Forms.Button
$Button1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button1.Location = New-Object System.Drawing.Point(699, 21)
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
$TextBox1.Size = New-Object System.Drawing.Size(687, 20)
$TextBox1.TabIndex = 0
$TextBox1.Text = ""
$TabPage2.Controls.Add($Button14)
$TabPage2.Controls.Add($Label12)
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
$TabPage3.Size = New-Object System.Drawing.Size(761, 487)
$TabPage3.TabIndex = 2
$TabPage3.Text = "Developers"
$TabPage3.BackColor = [System.Drawing.SystemColors]::Control
#~~< Button12 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button12 = New-Object System.Windows.Forms.Button
$Button12.Location = New-Object System.Drawing.Point(97, 172)
$Button12.Size = New-Object System.Drawing.Size(54, 21)
$Button12.TabIndex = 25
$Button12.Text = "Update"
$Button12.UseVisualStyleBackColor = $true
#~~< TextBox8 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox8 = New-Object System.Windows.Forms.TextBox
$TextBox8.Location = New-Object System.Drawing.Point(6, 173)
$TextBox8.Size = New-Object System.Drawing.Size(85, 20)
$TextBox8.TabIndex = 24
$TextBox8.Text = ""
#~~< Button11 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button11 = New-Object System.Windows.Forms.Button
$Button11.Location = New-Object System.Drawing.Point(97, 131)
$Button11.Size = New-Object System.Drawing.Size(54, 21)
$Button11.TabIndex = 23
$Button11.Text = "Update"
$Button11.UseVisualStyleBackColor = $true
#~~< TextBox7 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox7 = New-Object System.Windows.Forms.TextBox
$TextBox7.Location = New-Object System.Drawing.Point(6, 132)
$TextBox7.Size = New-Object System.Drawing.Size(85, 20)
$TextBox7.TabIndex = 22
$TextBox7.Text = ""
#~~< Label10 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label10 = New-Object System.Windows.Forms.Label
$Label10.Location = New-Object System.Drawing.Point(6, 156)
$Label10.Size = New-Object System.Drawing.Size(145, 14)
$Label10.TabIndex = 21
$Label10.Text = "Build 2 Version:"
#~~< Label9 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label9 = New-Object System.Windows.Forms.Label
$Label9.Location = New-Object System.Drawing.Point(6, 115)
$Label9.Size = New-Object System.Drawing.Size(145, 14)
$Label9.TabIndex = 18
$Label9.Text = "Build Version:"
#~~< Button10 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button10 = New-Object System.Windows.Forms.Button
$Button10.Location = New-Object System.Drawing.Point(97, 91)
$Button10.Size = New-Object System.Drawing.Size(54, 21)
$Button10.TabIndex = 17
$Button10.Text = "Update"
$Button10.UseVisualStyleBackColor = $true
#~~< TextBox6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$TextBox6 = New-Object System.Windows.Forms.TextBox
$TextBox6.Location = New-Object System.Drawing.Point(6, 92)
$TextBox6.Size = New-Object System.Drawing.Size(85, 20)
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
$TextBox4.Size = New-Object System.Drawing.Size(687, 20)
$TextBox4.TabIndex = 11
$TextBox4.Text = ""
#~~< Button4 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Button4 = New-Object System.Windows.Forms.Button
$Button4.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Button4.Location = New-Object System.Drawing.Point(699, 51)
$Button4.Size = New-Object System.Drawing.Size(54, 21)
$Button4.TabIndex = 13
$Button4.Text = "Browse"
$Button4.UseVisualStyleBackColor = $true
$TabPage3.Controls.Add($Button12)
$TabPage3.Controls.Add($TextBox8)
$TabPage3.Controls.Add($Button11)
$TabPage3.Controls.Add($TextBox7)
$TabPage3.Controls.Add($Label10)
$TabPage3.Controls.Add($Label9)
$TabPage3.Controls.Add($Button10)
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
#~~< Label6 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$Label6 = New-Object System.Windows.Forms.Label
$Label6.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$Label6.Location = New-Object System.Drawing.Point(569, 9)
$Label6.Size = New-Object System.Drawing.Size(69, 21)
$Label6.TabIndex = 15
$Label6.Text = "Arma 3 Mod:"
#~~< ComboBox1 >~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
$ComboBox1 = New-Object System.Windows.Forms.ComboBox
$ComboBox1.Anchor = ([System.Windows.Forms.AnchorStyles]([System.Windows.Forms.AnchorStyles]::Top -bor [System.Windows.Forms.AnchorStyles]::Right))
$ComboBox1.FormattingEnabled = $true
$ComboBox1.Location = New-Object System.Drawing.Point(644, 6)
$ComboBox1.SelectedIndex = -1
$ComboBox1.Size = New-Object System.Drawing.Size(137, 21)
$ComboBox1.TabIndex = 14
$ComboBox1.Text = ""
$Form1.Controls.Add($Label4)
$Form1.Controls.Add($TabControl1)
$Form1.Controls.Add($Label6)
$Form1.Controls.Add($ComboBox1)
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
		
	# Static development vars, DELETE ON RELEASE
	#$TextBox1.Text = "E:\Steam\steamapps\common\Arma 3"
	$TextBox2.Text = "F:\github\Epoch_public"
	#$TextBox3.Text = "P:\AddonBuilder"
	$TextBox4.Text = "F:\github\EPOCHMOD"
	$ver = "0.3.8"
	
	# Defines
	$ListView1.CheckBoxes = $true
	$FolderBrowserDialog1.ShowNewFolderButton = $false
		
	$OS = (Get-WmiObject Win32_OperatingSystem).OSArchitecture
		
	$armaPathArr = switch($OS) #gets array of objects from registry
	{
		"64-bit" { Get-ChildItem "HKLM:\SOFTWARE\WOW6432Node\Bohemia Interactive\" | ForEach-Object { Get-ItemProperty $_.pspath } }
		"32-bit" { Get-ChildItem "HKLM:\SOFTWARE\Bohemia Interactive Studio\" | ForEach-Object { Get-ItemProperty $_.pspath } }
		default { @() } #OS Architecture not recognized, might need to update Powershell version, should work with 2.0 (win7)
	}
		
	$TextBox1.Text = $armaPathArr.main | ForEach-Object { if ($_ -match "Arma 3") { return $_ } }
	$TextBox3.Text = $armaPathArr.path | ForEach-Object { if ($_ -match "AddonBuilder") { return $_ } }
		
	
	# Functions
		
	function fnc_populateListView
	{	
		$Script:listarr = @() #empty arr
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
		$c3 = Test-Path (Join-Path $TextBox3.Text "\AddonBuilder.exe") -ErrorAction SilentlyContinue
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
		
	function fnc_selectAll($boo)
	{
		foreach ($x in $Script:listarr)
		{
			$x.checked = $boo
		}
	}
	
	# Event Handlers
	$Button1.Add_Click({ fnc_getSetPath(1) })
	$Button2.Add_Click({ fnc_getSetPath(2) })
	$Button3.Add_Click({ fnc_getSetPath(3) })
	$Button4.Add_Click({ fnc_getSetPath(4) })
	$Button7.Add_Click({ fnc_selectAll($true) })
	$Button5.Add_Click({ fnc_selectAll($false) })
	
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

