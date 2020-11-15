VERSION 4.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6570
   ClientLeft      =   1140
   ClientTop       =   915
   ClientWidth     =   8310
   Height          =   6975
   Left            =   1080
   LinkTopic       =   "Form1"
   ScaleHeight     =   6570
   ScaleWidth      =   8310
   Top             =   570
   Width           =   8430
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   1080
      Top             =   360
   End
   Begin VB.Frame inputregs 
      Caption         =   "INPUT REGS"
      Height          =   4575
      Left            =   4320
      TabIndex        =   8
      Top             =   1440
      Width           =   1695
      Begin VB.TextBox inregsaddress 
         Height          =   285
         Left            =   480
         TabIndex        =   9
         Text            =   "1"
         Top             =   360
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   9
         Left            =   480
         TabIndex        =   20
         Top             =   4080
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   8
         Left            =   480
         TabIndex        =   19
         Top             =   3720
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   7
         Left            =   480
         TabIndex        =   18
         Top             =   3360
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   6
         Left            =   480
         TabIndex        =   17
         Top             =   3000
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   5
         Left            =   480
         TabIndex        =   16
         Top             =   2640
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   4
         Left            =   480
         TabIndex        =   15
         Top             =   2280
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   3
         Left            =   480
         TabIndex        =   14
         Top             =   1920
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   2
         Left            =   480
         TabIndex        =   13
         Top             =   1560
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   1
         Left            =   480
         TabIndex        =   12
         Top             =   1200
         Width           =   735
      End
      Begin VB.Label inputreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   0
         Left            =   480
         TabIndex        =   11
         Top             =   840
         Width           =   735
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "HOLDING REGS"
      Height          =   4575
      Left            =   6360
      TabIndex        =   4
      Top             =   1440
      Width           =   1455
      Begin VB.TextBox holdingregsaddress 
         Height          =   285
         Left            =   360
         TabIndex        =   7
         Text            =   "1"
         Top             =   360
         Width           =   855
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   9
         Left            =   360
         TabIndex        =   29
         Top             =   4080
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   8
         Left            =   360
         TabIndex        =   28
         Top             =   3720
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   7
         Left            =   360
         TabIndex        =   27
         Top             =   3360
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   6
         Left            =   360
         TabIndex        =   26
         Top             =   3000
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   5
         Left            =   360
         TabIndex        =   25
         Top             =   2640
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   4
         Left            =   360
         TabIndex        =   24
         Top             =   2280
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   3
         Left            =   360
         TabIndex        =   23
         Top             =   1920
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   2
         Left            =   360
         TabIndex        =   22
         Top             =   1560
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   1
         Left            =   360
         TabIndex        =   21
         Top             =   1200
         Width           =   735
      End
      Begin VB.Label holdingreg 
         Alignment       =   2  'Center
         Caption         =   "0000"
         Height          =   255
         Index           =   0
         Left            =   360
         TabIndex        =   10
         Top             =   840
         Width           =   735
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "COILS"
      Height          =   4575
      Left            =   2520
      TabIndex        =   3
      Top             =   1440
      Width           =   1455
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   9
         Left            =   600
         TabIndex        =   50
         Top             =   4080
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   8
         Left            =   600
         TabIndex        =   49
         Top             =   3720
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   7
         Left            =   600
         TabIndex        =   48
         Top             =   3360
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   6
         Left            =   600
         TabIndex        =   47
         Top             =   3000
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   5
         Left            =   600
         TabIndex        =   46
         Top             =   2640
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   4
         Left            =   600
         TabIndex        =   45
         Top             =   2280
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   3
         Left            =   600
         TabIndex        =   44
         Top             =   1920
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   2
         Left            =   600
         TabIndex        =   43
         Top             =   1560
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   1
         Left            =   600
         TabIndex        =   42
         Top             =   1200
         Width           =   255
      End
      Begin VB.CheckBox coilstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   0
         Left            =   600
         TabIndex        =   41
         Top             =   840
         Width           =   255
      End
      Begin VB.TextBox coiladdress 
         Height          =   285
         Left            =   360
         TabIndex        =   6
         Text            =   "1"
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "INPUTS"
      Height          =   4575
      Left            =   600
      TabIndex        =   2
      Top             =   1440
      Width           =   1575
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   9
         Left            =   600
         TabIndex        =   40
         Top             =   4080
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   8
         Left            =   600
         TabIndex        =   39
         Top             =   3720
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   7
         Left            =   600
         TabIndex        =   38
         Top             =   3360
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   6
         Left            =   600
         TabIndex        =   37
         Top             =   3000
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   5
         Left            =   600
         TabIndex        =   36
         Top             =   2640
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   4
         Left            =   600
         TabIndex        =   35
         Top             =   2280
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   3
         Left            =   600
         TabIndex        =   34
         Top             =   1920
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   2
         Left            =   600
         TabIndex        =   33
         Top             =   1560
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   1
         Left            =   600
         TabIndex        =   32
         Top             =   1200
         Width           =   255
      End
      Begin VB.CheckBox inputstatus 
         Enabled         =   0   'False
         Height          =   255
         Index           =   0
         Left            =   600
         TabIndex        =   31
         Top             =   840
         Width           =   255
      End
      Begin VB.TextBox inputaddress 
         Height          =   285
         Left            =   360
         TabIndex        =   5
         Text            =   "1"
         Top             =   360
         Width           =   735
      End
   End
   Begin VB.TextBox Device 
      Height          =   285
      Left            =   3720
      TabIndex        =   1
      Text            =   "1"
      Top             =   720
      Width           =   855
   End
   Begin VB.Label statusline 
      Alignment       =   2  'Center
      ForeColor       =   &H000000FF&
      Height          =   255
      Left            =   840
      TabIndex        =   30
      Top             =   1080
      Width           =   6735
   End
   Begin VB.Label Label1 
      Caption         =   "Device"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   700
         size            =   13.5
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   3600
      TabIndex        =   0
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Public m_svr As IModSca

Dim PollHandle(4) As Integer
Dim status(4) As Integer
Dim SlaveDevice As Integer
Dim StartAddress(4) As Long

Dim Modbus_Id(4) As Long
Dim Counter As Integer
Dim temp As Integer
Dim Modbus_Addr As Long



Private Sub Text4_Change()

End Sub


Private Sub coiladdress_Change()

If (IsNumeric(coiladdress.Text)) Then
    StartAddress(1) = coiladdress.Text
    Modbus_Addr = Modbus_Id(1) + StartAddress(1)
    status(1) = m_svr.ModifyPollRequest(PollHandle(1), SlaveDevice, Modbus_Addr, 10)
    StatusMsg (status(1))
End If
    
End Sub

Private Sub Device_Change()

If (IsNumeric(Device.Text)) Then
    SlaveDevice = Device.Text

    Modbus_Addr = Modbus_Id(0) + StartAddress(0)
    temp = m_svr.ModifyPollRequest(PollHandle(0), SlaveDevice, Modbus_Addr, 10)

    Modbus_Addr = Modbus_Id(1) + StartAddress(1)
    temp = m_svr.ModifyPollRequest(PollHandle(1), SlaveDevice, Modbus_Addr, 10)

    Modbus_Addr = Modbus_Id(2) + StartAddress(2)
    temp = m_svr.ModifyPollRequest(PollHandle(2), SlaveDevice, Modbus_Addr, 10)

    Modbus_Addr = Modbus_Id(3) + StartAddress(3)
    temp = m_svr.ModifyPollRequest(PollHandle(3), SlaveDevice, Modbus_Addr, 10)
End If

End Sub

Private Sub Form_Load()

Set m_svr = CreateObject("ModScan32.Document")

    
Modbus_Id(0) = 10000   'input status prefix
Modbus_Id(1) = 0        'coil status prefix
Modbus_Id(2) = 30000    'input register prefix
Modbus_Id(3) = 40000    'holding register prefix

SlaveDevice = 1
For Counter = 0 To 3
    StartAddress(Counter) = 1
    Modbus_Addr = Modbus_Id(Counter) + StartAddress(Counter)
    PollHandle(Counter) = m_svr.CreatePollRequest(SlaveDevice, Modbus_Addr, 10)
   Next Counter

statusline = "** UNINITIALIZED **"
End Sub


Private Sub Form_Terminate()

For Counter = 0 To 4
    m_svr.DeletePollRequest (PollHandle(Counter))
    Next Counter
    
End Sub


Public Sub StatusMsg(Index As Integer)
If Index = 0 Then statusline = ""
If Index > 0 And Index < 256 Then statusline = "Slave Device Exception Response"
If Index = 256 Then statusline = "Invalid Handle"
If Index = 257 Then statusline = "Modbus Message Overrun"
If Index = 258 Then statusline = "Invalid Address"
If Index = 259 Then statusline = "Invalid Device Address"
If Index = 260 Then statusline = "Invalid Length Specification"
If Index = 261 Then statusline = "Invalid modbus command"
If Index = 262 Then statusline = "Driver Out-Of-Memory"
If Index = 263 Then statusline = "** Time-Out **"
If Index = 264 Then statusline = "Invalid Protocol Specification"
If Index = 265 Then statusline = "** Bad Checksum **"
If Index = 266 Then statusline = "Server NOT Connected"
If Index = 267 Then statusline = "Invalid Response from Driver"
If Index = 268 Then statusline = "Modbus Write Failure"
If Index = 269 Then statusline = "Remote Server not Connected"
If Index = 270 Then statusline = "** UNINITIALIZED **"
If Index = 271 Then statusline = "ModScan Demo Time Expired"


End Sub

Private Sub holdingregsaddress_Change()

If (IsNumeric(holdingregsaddress.Text)) Then
    StartAddress(3) = holdingregsaddress.Text
    Modbus_Addr = Modbus_Id(3) + StartAddress(3)
    status(3) = m_svr.ModifyPollRequest(PollHandle(3), SlaveDevice, Modbus_Addr, 10)
    StatusMsg (status(3))
End If
    
End Sub

Private Sub inputaddress_Change()

If (IsNumeric(inputaddress.Text)) Then
    StartAddress(0) = inputaddress.Text
    Modbus_Addr = Modbus_Id(0) + StartAddress(0)
    status(0) = m_svr.ModifyPollRequest(PollHandle(0), SlaveDevice, Modbus_Addr, 10)
    StatusMsg (status(0))
End If
    
End Sub

Private Sub inregsaddress_Change()

If (IsNumeric(inregsaddress.Text)) Then
    StartAddress(2) = inregsaddress.Text
    Modbus_Addr = Modbus_Id(2) + StartAddress(2)
    status(2) = m_svr.ModifyPollRequest(PollHandle(2), SlaveDevice, Modbus_Addr, 10)
    StatusMsg (status(2))
End If
    
End Sub

Private Sub Timer1_Timer()

For Counter = 0 To 9
    status(0) = m_svr.ReadValue(PollHandle(0), Counter, temp)
    StatusMsg (status(0))
If temp = 0 Then
    inputstatus(Counter).Value = 0
    Else
    inputstatus(Counter).Value = 1
    End If
Next Counter

For Counter = 0 To 9
    status(1) = m_svr.ReadValue(PollHandle(1), Counter, temp)
    StatusMsg (status(1))
If temp = 0 Then
    coilstatus(Counter).Value = 0
    Else
    coilstatus(Counter).Value = 1
    End If
Next Counter

For Counter = 0 To 9
    status(2) = m_svr.ReadValue(PollHandle(2), Counter, temp)
    StatusMsg (status(2))
    inputreg(Counter).Caption = temp
Next Counter
    
    
For Counter = 0 To 9
    status(3) = m_svr.ReadValue(PollHandle(3), Counter, temp)
    StatusMsg (status(3))
    holdingreg(Counter).Caption = temp
Next Counter


End Sub


