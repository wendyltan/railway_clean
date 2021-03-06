// 轨道清洁检测车监控系统Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "轨道清洁检测车监控系统.h"
#include "轨道清洁检测车监控系统Dlg.h"

#include "ExtraInclude.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

struct IDINFO{
	int nID;
}info[4];

struct TEXTINFO{
	int nID;
}textinfo[13];

struct TYPE{
	CString TableTypeName;
	int TableTypeID;
}tabletype[10];


struct teeType{
	int teeID;
	CString tchartname;
}teechart[4];


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_frontWind = _T("");
	m_frontRight = _T("");
	m_frontLeft = _T("");
	m_backRight = _T("");
	m_backLeft = _T("");
	m_dirtyWater = _T("");
	m_cleanWater = _T("");
	m_backWind1 = _T("");
	m_backWind2 = _T("");
	m_longitude = _T("");
	m_latitude = _T("");
	m_highpre = _T("");
	m_lowpre = _T("");
	m_AlarmTime = _T("");
	m_AlarmArea = _T("");
	m_AlarmCurrent = _T("");
	m_AlarmFlag = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	//type init----------------------------------------------------------
	tabletype[0].TableTypeName = "清洁车经纬度表"; //current position
	tabletype[0].TableTypeID = 0;
	tabletype[1].TableTypeName = "清洁车位置表"; //position
	tabletype[1].TableTypeID = 1;
	tabletype[2].TableTypeName = "清水箱表"; //clean water box
	tabletype[2].TableTypeID = 2;
	tabletype[3].TableTypeName = "水泵压力表"; //water pressure
	tabletype[3].TableTypeID = 3;
	tabletype[4].TableTypeName = "温度表"; //temperature
	tabletype[4].TableTypeID = 4;
	tabletype[5].TableTypeName = "污水箱表"; //dirty water box
	tabletype[5].TableTypeID = 5;
	tabletype[6].TableTypeName = "吸尘口压力表"; //wind pressure
	tabletype[6].TableTypeID = 6;
	tabletype[7].TableTypeName = "逆变器电压";//volt
	tabletype[7].TableTypeID = 7;

	tabletype[8].TableTypeName = "上限表";//maximum,for alarm raising
	tabletype[8].TableTypeID = 8;

	tabletype[9].TableTypeName = "报警表";//store alarm data
	tabletype[9].TableTypeID = 9;

	

	
	

	//text info init-------------------------
	
	//wind pre
	textinfo[0].nID = IDC_FRONT_WIND_TEXT;
	textinfo[1].nID = IDC_BACK_WIND_TEXT1;
	textinfo[2].nID = IDC_BACK_WIND_TEXT2;
	
	//water pre
	textinfo[3].nID = IDC_LOW_WATER_PRE;
	textinfo[4].nID = IDC_HIGH_WATER_PRE;

	//water box
	textinfo[5].nID = IDC_CLEAN_WATER_TEXT;
	textinfo[6].nID = IDC_DIRTY_WATER_TEXT;

	//current position
	textinfo[7].nID = IDC_LONGITUDE_TEXT;
	textinfo[8].nID = IDC_LATITUDE_TEXT;

	//position with other object
	textinfo[9].nID = IDC_EDIT_FRONT_LEFT;
	textinfo[10].nID = IDC_EDIT_FRONT_RIGHT;
	textinfo[11].nID = IDC_EDIT_BACK_LEFT;
	textinfo[12].nID = IDC_EDIT_BACK_RIGHT;

	//teechart init-------------------------
	teechart[0].teeID = 0;
	teechart[0].tchartname = "车外环境温度";
	teechart[1].teeID = 1;
	teechart[1].tchartname = "车内温度";
	teechart[2].teeID = 2;
	teechart[2].tchartname = "副发动机水温";
	teechart[3].teeID = 3;
	teechart[3].tchartname = "逆变器电压";

	//database init--------------------------
	tcount = 0;
	vcount = 0;
	
	DatabaseConnect();


	

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_FRONT_WIND_TEXT, m_frontWind);
	DDX_Text(pDX, IDC_EDIT_FRONT_RIGHT, m_frontRight);
	DDX_Text(pDX, IDC_EDIT_FRONT_LEFT, m_frontLeft);
	DDX_Text(pDX, IDC_EDIT_BACK_RIGHT, m_backRight);
	DDX_Text(pDX, IDC_EDIT_BACK_LEFT, m_backLeft);
	DDX_Text(pDX, IDC_DIRTY_WATER_TEXT, m_dirtyWater);
	DDX_Text(pDX, IDC_CLEAN_WATER_TEXT, m_cleanWater);
	DDX_Text(pDX, IDC_BACK_WIND_TEXT1, m_backWind1);
	DDX_Text(pDX, IDC_BACK_WIND_TEXT2, m_backWind2);
	DDX_Text(pDX, IDC_LONGITUDE_TEXT, m_longitude);
	DDX_Text(pDX, IDC_LATITUDE_TEXT, m_latitude);
	DDX_Text(pDX, IDC_HIGH_WATER_PRE, m_highpre);
	DDX_Text(pDX, IDC_LOW_WATER_PRE, m_lowpre);
	DDX_Text(pDX, IDC_ALARM_TIME, m_AlarmTime);
	DDX_Text(pDX, IDC_ALARM_CURRENT, m_AlarmCurrent);
	DDX_Text(pDX, IDC_ALARM_AREA, m_AlarmArea);
	
	//}}AFX_DATA_MAP
	DDX_Control(pDX,IDC_INSIDE_MAIN,m_iChart);
	DDX_Control(pDX,IDC_OUTSIDE_MAIN,m_oChart);
	DDX_Control(pDX,IDC_WATER_MAIN,m_wChart);
	DDX_Control(pDX,IDC_VOLT_MAIN,m_vChart);

	
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_BUTTON_OUTSIDE_TEM, OnButtonOutsideTem)
	ON_BN_CLICKED(IDC_BUTTON_INSIDE_TEMP, OnButtonInsideTemp)
	ON_BN_CLICKED(IDC_BUTTON_WATER_TEMP, OnButtonWaterTemp)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_COMMAND(IDM_CLEAN_WATER, OnCleanWater)
	ON_COMMAND(IDM_DIRTY_WATER, OnDirtyWater)
	ON_COMMAND(IDM_WATER_TEMP, OnWaterTemp)
	ON_WM_DESTROY()
	ON_COMMAND(IDM_WIND_PRE, OnWindPre)
	ON_COMMAND(IDM_MAXIMUM, OnMaximum)
	ON_COMMAND(IDM_ALARM, OnAlarm)
	ON_COMMAND(IDM_ANALIZE,OnAnalize)
	ON_BN_CLICKED(IDC_BUTTON_VOLT, OnButtonVolt)
	ON_BN_CLICKED(IDC_BUTTON_WATCH_VIDEO, OnButtonWatchVideo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	

	for(int i=0;i<10;i++)
	{
		m_pCurrentset[i] = JudgeType(i);
	}

	
	ReadTemp();

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}


	
		

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnButtonInsideTemp()
{

	m_insideTempDlg.DoModal();

}

void CMyDlg::OnButtonWaterTemp()
{

	m_waterTempDlg.DoModal();

}

void CMyDlg::OnButtonVolt()
{
 
	m_voltDlg.DoModal();

}



void CMyDlg::OnButtonOutsideTem() 
{
	// TODO: Add your control notification handler code here
	m_outsideTempDlg.DoModal();
	
}




HBRUSH CMyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	if(nCtlColor == CTLCOLOR_DLG||CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(213,229,243));
		HBRUSH B = CreateSolidBrush(RGB(213,229,243));
		return B;
	}
	return hbr;
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default


	if(m_RecordNum==9) {m_pCurrentset[4]->Move((long)m_RecordNum++);m_pCurrentset[7]->Move((long)m_RecordNum++);}	
	if(nIDEvent == 1)
	{	
		if(!m_pCurrentset[4]->adoEOF||!m_pCurrentset[7]->adoEOF)
		{

			dealTimer(0,teechart[0].tchartname);
			dealTimer(1,teechart[1].tchartname);
			dealTimer(2,teechart[2].tchartname);
			dealTimer(3,teechart[3].tchartname);
			CurTime+= tmSpan;

			
			//raise alarm
			RaiseAlarm(4,"副发动机水温");
			RaiseAlarm(4,"车外环境温度");
			RaiseAlarm(4,"车内温度");
			RaiseAlarm(7,"逆变器电压");

			m_pCurrentset[4]->MoveNext();
			m_pCurrentset[7]->MoveNext();
			m_RecordNum++;
		}
		else if(m_pCurrentset[4]->adoEOF)
		{
		  KillTimer(1);m_pCurrentset[4]->Close();
		}
		else if(m_pCurrentset[7]->adoEOF)
		{
			KillTimer(1);m_pCurrentset[7]->Close();
		}
	}
	

	if(nIDEvent == 2){	
		
		
		if(!m_pCurrentset[0]->adoEOF) 
		{
		
			CString longitude = (char*)(_bstr_t)m_pCurrentset[0]->GetCollect(_variant_t("清洁车经度"));
				
			CString latitude = (char*)(_bstr_t)m_pCurrentset[0]->GetCollect(_variant_t("清洁车纬度"));
				
			m_longitude = longitude;
			m_latitude = latitude;

			UpdateData(FALSE);	

			//raise alarm
			RaiseAlarm(0,"清洁车纬度");
			RaiseAlarm(0,"清洁车经度");

			m_pCurrentset[0]->MoveNext();
		}
		else{
			KillTimer(2);m_pCurrentset[0]->Close();//MessageBox("END OF RECORD1!");
		}
		  
	
					
		  
	}
	if(nIDEvent == 3){	
			
		
		if(!m_pCurrentset[1]->adoEOF) 
		{
			
		
	
			CString frontLeft = (char*)(_bstr_t)m_pCurrentset[1]->GetCollect(_variant_t("车左前位置"));
			CString frontRight = (char*)(_bstr_t)m_pCurrentset[1]->GetCollect(_variant_t("车右前位置"));
			CString backLeft = (char*)(_bstr_t)m_pCurrentset[1]->GetCollect(_variant_t("车左后位置"));
			CString backRight = (char*)(_bstr_t)m_pCurrentset[1]->GetCollect(_variant_t("车右后位置"));

			m_frontLeft = frontLeft;
			m_frontRight =  frontRight;
			m_backLeft = backLeft;
			m_backRight = backRight;

			UpdateData(FALSE);

			//raise alarm
			RaiseAlarm(1,"车左前位置");
			RaiseAlarm(1,"车右前位置");
			RaiseAlarm(1,"车左后位置");
			RaiseAlarm(1,"车右后位置");

			m_pCurrentset[1]->MoveNext();

		}
		else{
			KillTimer(3);m_pCurrentset[1]->Close();//MessageBox("END OF RECORD2!");
		}

		  
						
		  
	}
	if(nIDEvent == 4){	
		
	
		if(!m_pCurrentset[2]->adoEOF){
			
			
			CString cleanwater = (char*)(_bstr_t)m_pCurrentset[2]->GetCollect(_variant_t("清水箱水位"));
				
			float cleannum = atof(cleanwater);
			CString newclean;
			if(cleannum>0&&cleannum<1) {newclean.Format("0%s",cleanwater);m_cleanWater = newclean;}
			else m_cleanWater = cleanwater;
	
			
			UpdateData(FALSE);
			
			//raise alarm
			RaiseAlarm(2,"清水箱水位");


			m_pCurrentset[2]->MoveNext();
		}
		else{
			KillTimer(4);m_pCurrentset[2]->Close();//MessageBox("END OF RECORD3!");
		}

		
					
		  
	}
	if(nIDEvent == 5){	
		
	
		if(!m_pCurrentset[3]->adoEOF){
			
			
			CString highpre = (char*)(_bstr_t)m_pCurrentset[3]->GetCollect(_variant_t("高压水泵压力"));
			CString lowpre = (char*)(_bstr_t)m_pCurrentset[3]->GetCollect(_variant_t("低压水泵压力"));


			m_highpre = highpre;
			m_lowpre = lowpre;
			UpdateData(FALSE);

			//raise alarm
			RaiseAlarm(3,"高压水泵压力");
			RaiseAlarm(3,"低压水泵压力");

			m_pCurrentset[3]->MoveNext();
		}
		else{
			KillTimer(5);m_pCurrentset[3]->Close();//MessageBox("END OF RECORD4!");
		}		
							  
	}
	if(nIDEvent == 6){	
		
	
		if(!m_pCurrentset[5]->adoEOF){
			
			
			CString dirtywater = (char*)(_bstr_t)m_pCurrentset[5]->GetCollect(_variant_t("污水箱水位"));
			float dirtynum = atof(dirtywater);
			CString newdirty;
			if(dirtynum>0&&dirtynum<1) {newdirty.Format("0%s",dirtywater);m_dirtyWater = newdirty;}
			else m_dirtyWater = dirtywater;
	
			

			UpdateData(FALSE);
			//raise alarm
			RaiseAlarm(5,"污水箱水位");

			m_pCurrentset[5]->MoveNext();
		}
		else{
			KillTimer(6);m_pCurrentset[5]->Close();//MessageBox("END OF RECORD5!");
		}		
							  
	}

	if(nIDEvent == 7){
			
		if(!m_pCurrentset[6]->adoEOF){
			
			CString frontwind = (char*)(_bstr_t)m_pCurrentset[6]->GetCollect(_variant_t("前吸尘口压力"));
			CString backwind1 = (char*)(_bstr_t)m_pCurrentset[6]->GetCollect(_variant_t("后吸尘口1压力"));
			CString backwind2 = (char*)(_bstr_t)m_pCurrentset[6]->GetCollect(_variant_t("后吸尘口2压力"));


			m_frontWind = frontwind;
			m_backWind1 = backwind1;
			m_backWind2 = backwind2;

			UpdateData(FALSE);

			//raise alarm
			RaiseAlarm(6,"前吸尘口压力");
			RaiseAlarm(6,"后吸尘口1压力");
			RaiseAlarm(6,"后吸尘口2压力");

			m_pCurrentset[6]->MoveNext();
		}
		else{
			KillTimer(7);m_pCurrentset[6]->Close();//MessageBox("END OF RECORD6!");
		}		
		
	}






	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnCleanWater() 
{
	// TODO: Add your command handler code here
	CCleanWaterChart cwc;
	cwc.DoModal();
	
}

void CMyDlg::OnDirtyWater() 
{
	// TODO: Add your command handler code here
	CDirtyWaterChart dwc;
	dwc.DoModal();
	
}

void CMyDlg::OnWaterTemp() 
{
	// TODO: Add your command handler code here
	CWaterTempChart wtc;
	wtc.DoModal();
	
}


void CMyDlg::OnWindPre() 
{
	// TODO: Add your command handler code here
	CWindPreChart wpc;
	wpc.DoModal();
	
}

void CMyDlg::OnMaximum() 
{
	// TODO: Add your command handler code here
	CMaximumChart mxc;
	mxc.DoModal();
	
}

void CMyDlg::OnAlarm() 
{
	// TODO: Add your command handler code here
	CAlarmChart ac;
	ac.DoModal();
	
}
void CMyDlg::OnAnalize() 
{
	// TODO: Add your command handler code here
	CParaCal adlg;
	adlg.DoModal();
	
}



void CMyDlg::DatabaseConnect()
{
	//初始化com环境
	::CoInitialize(NULL);
	//创建连接对象和记录集对象
	HRESULT hr;
	try
	{
		hr = m_pConnection.CreateInstance("ADODB.Connection");//创建Connection对象
		if(SUCCEEDED(hr))
		{
			hr = m_pConnection->Open(
				"Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=清洁车;Data Source=WENDY-PC",
				"","",adModeUnknown);///连接数据库
		}
	}
	catch(_com_error e)///捕捉异常
	{
		CString errormessage;
		errormessage.Format("连接数据库失败!\r\n错误信息:%s",e.ErrorMessage());
		AfxMessageBox(errormessage);///显示错误信息
	}
}


void CMyDlg::ReadTemp()
{
	
	 m_RecordNum = 0;
	 for(int i=0;i<4;i++)
	 {
		ChartInit(i,teechart[i].tchartname);
	 }
	 	 
	 SetTimer(1,1000,NULL);
	
}

_RecordsetPtr CMyDlg::JudgeType(int type)
{
	
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	CString sqlstr;
	sqlstr.Format("SELECT * FROM %s",tabletype[type].TableTypeName);
		

	HRESULT hr = m_pRecordset->Open(sqlstr.AllocSysString(),
			m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			
	m_pRecordset->MoveFirst();

	switch(type){
		//经纬度
		case 0:
			{
				 CString longitude = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("清洁车经度"));
				
				 CString latitude = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("清洁车纬度"));
				
				 m_longitude = longitude;
				 m_latitude = latitude;

				 UpdateData(FALSE);

				 SetTimer(2,1000,NULL);
		   		//return m_pRecordset;
				break;
			}
		//位置
		case 1:
			{
			
				CString frontLeft = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("车左前位置"));
				CString frontRight = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("车右前位置"));
				CString backLeft = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("车左后位置"));
				CString backRight = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("车右后位置"));

				m_frontLeft = frontLeft;
				m_frontRight =  frontRight;
				m_backLeft = backLeft;
				m_backRight = backRight;

			
				UpdateData(FALSE);

				SetTimer(3,1500,NULL);
				//return m_pRecordset;
				break;
			}

		//清水位
		case 2:
			{
			
				CString cleanwater = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("清水箱水位"));

				float cleannum = atof(cleanwater);
				CString newclean;
				if(cleannum>0&&cleannum<1) {newclean.Format("0%s",cleanwater);m_cleanWater = newclean;}
				else m_cleanWater = cleanwater;
	
				UpdateData(FALSE);

				SetTimer(4,500,NULL);
				//return m_pRecordset;
				break;
			}
		//水压
		case 3:
			{

				CString highpre = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("高压水泵压力"));
				CString lowpre = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("低压水泵压力"));


				m_highpre = highpre;
				m_lowpre = lowpre;

				UpdateData(FALSE);

				SetTimer(5,1000,NULL);
				//return m_pRecordset;
				break;

			}
		//温度 case4

		//污水位
		case 5:
			{
				CString dirtywater = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("污水箱水位"));


				float dirtynum = atof(dirtywater);
				CString newdirty;
				if(dirtynum>0&&dirtynum<1) {newdirty.Format("0%s",dirtywater);m_dirtyWater = newdirty;}
				else m_dirtyWater = dirtywater;
	

				UpdateData(FALSE);

				SetTimer(6,1000,NULL);
				//return m_pRecordset;
				break;
			}
		//吸尘口压力
		case 6:
			{
				CString frontwind = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("前吸尘口压力"));
				CString backwind1 = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("后吸尘口1压力"));
				CString backwind2 = (char*)(_bstr_t)m_pRecordset->GetCollect(_variant_t("后吸尘口2压力"));


				m_frontWind = frontwind;
				m_backWind1 = backwind1;
				m_backWind2 = backwind2;

				UpdateData(FALSE);

				SetTimer(7,1000,NULL);

				break;
			}
		//电压 case7
		//上限值 case8
		//报警 case9

	}

	return m_pRecordset;
	
}




void CMyDlg::DatabaseDisconnect()
{
	::CoUninitialize();
	m_pRecordset->Close();
	//m_pCurrentset[8]->Close();
	//m_pCurrentset[9]->Close();
}

void CMyDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	DatabaseDisconnect();
	
}

void CMyDlg::ChartInit(int teeID,CString chartname)
{
	
	 CTChart *tchart;
	 if(teeID ==0) tchart = &m_oChart;
	 else if(teeID == 1) tchart = &m_iChart;
	 else if(teeID == 2) tchart = &m_wChart;
	 else if(teeID == 3) tchart = &m_vChart;


	 tchart->SetVisible(true);
	 tchart->GetLegend().SetVisible(false);
	 tchart->GetAspect().SetView3D(FALSE);  
     tchart->GetAxis().GetLeft().GetTitle().SetCaption(chartname);
	 

	 //定义坐标系空间
	 CSeries mycs0 =(CSeries)tchart->Series(0);
     CAxes coord = (CAxes)tchart->GetAxis();
     CAxis left0 = (CAxis)coord.GetLeft();
     left0.SetMinimum(0);
	 if(teeID == 3) left0.SetMaximum(10);
     else left0.SetMaximum(40);
	 if(teeID == 3) left0.SetIncrement(0.1);
     else left0.SetIncrement(1);
     left0.SetStartPosition(0);
     left0.SetEndPosition(100);
     left0.SetPositionPercent(0);
	 

	
	 CurTime = COleDateTime::GetCurrentTime();  
	 tmSpan = COleDateTimeSpan(0,0,0,1); //1s  
  
 	 

	 
	 CString str;

	 if(teeID == 3) m_pCurrentset[7]->MoveFirst();
	 else m_pCurrentset[4]->MoveFirst();
	 //先用前十条记录初始化
	 for(int i =0;i<10;i++){

		if(teeID == 3) str = (char*)(_bstr_t)m_pCurrentset[7]->GetCollect(_variant_t(chartname));
		else str = (char*)(_bstr_t)m_pCurrentset[4]->GetCollect(_variant_t(chartname));	

		csTime= CurTime.Format("%H:%M:%S");
		mycs0.Add(atof(str),csTime,RGB(255,0,0));
		CurTime+= tmSpan;

		if(teeID == 3) m_pCurrentset[7]->MoveNext();
        else m_pCurrentset[4]->MoveNext();
		m_RecordNum++;
		

	 }
	 //m_RecordNum为9,已经初始化前十条记录

	tchart->SetWindowPos(&this->wndTop, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
}

void CMyDlg::dealTimer(int teeID,CString chartname)
{

	CString csTime = CurTime.Format("%H:%M:%S");
	CString str;
	
	
	if(teeID == 3)	str = (char*)(_bstr_t)m_pCurrentset[7]->GetCollect(_variant_t(chartname));
	else str = (char*)(_bstr_t)m_pCurrentset[4]->GetCollect(_variant_t(chartname));	

	CTChart *tchart;
	if(teeID ==0) tchart = &m_oChart;
	else if(teeID == 1) tchart = &m_iChart;
	else if(teeID == 2) tchart = &m_wChart;
	else if(teeID == 3) tchart = &m_vChart;

	
	tchart->Series(0).Add(atof(str),csTime,RGB(255,0,0));
	
	tchart->GetAxis().GetBottom().Scroll(1.0,TRUE);
   
}




void CMyDlg::OnButtonWatchVideo() 
{
	// TODO: Add your control notification handler code here
	CVideo vlog;
	vlog.DoModal();
}

void CMyDlg::RaiseAlarm(int setID,CString paraType)
{
	//compara current para's data to standard
	CString currentParaData =(char*)(_bstr_t)m_pCurrentset[setID]->GetCollect(_variant_t(paraType));
	m_pCurrentset[8]->MoveFirst();
	CString ParaMax;

	do
	{
		ParaMax = (char*)(_bstr_t)m_pCurrentset[8]->GetCollect(_variant_t("参数名称"));
		m_pCurrentset[8]->MoveNext();
	}while(ParaMax != paraType);

	//have found it
	m_pCurrentset[8]->MovePrevious();
	ParaMax = (char*)(_bstr_t)m_pCurrentset[8]->GetCollect(_variant_t("当前上限值"));

	//if not found
	

	//if somethings goes wrong,raise the alarm,change the text and beep once!
	if(atof(currentParaData)>atof(ParaMax))
	{
		m_AlarmArea = paraType;
		m_AlarmCurrent.Format("参数当前值：%s\n参数上限值：%s",currentParaData,ParaMax);
		m_AlarmTime = CurTime.Format("%Y-%m-%d %H:%M:%S");
		UpdateData(FALSE);
		MessageBeep(MB_ICONASTERISK);


		
		//记录进报警表
		//如果没有重复的记录，记录；否则不记录并且提示
		CString recordCurrent;
		m_pCurrentset[9]->MoveFirst();
		while(!m_pCurrentset[9]->adoEOF){
			recordCurrent = (char*)(_bstr_t)m_pCurrentset[9]->GetCollect(_variant_t("当前值"));
			if(recordCurrent == currentParaData) {m_AlarmFlag=1;break;}	
			m_pCurrentset[9]->MoveNext();
		}

		m_pCurrentset[9]->MoveLast();
		if(m_AlarmFlag!=1)
		{
			//记录进报警表
			m_pCurrentset[9]->AddNew();
					
			m_pCurrentset[9]->PutCollect("时间",_variant_t(m_AlarmTime));
			m_pCurrentset[9]->PutCollect("参数名称",_variant_t(m_AlarmArea));
			m_pCurrentset[9]->PutCollect("当前值",_variant_t(currentParaData));

			m_pCurrentset[9]->PutCollect("参数上限值",_variant_t(ParaMax));

				
			m_pCurrentset[9]->Update();

		}
		m_AlarmFlag = 0;
	


	}

	
	

}
