
// 037_MFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "037_MFC.h"
#include "037_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHelp1();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_32776, &CAboutDlg::OnHelp1)
END_MESSAGE_MAP()


// CMy037_MFCDlg 对话框



CMy037_MFCDlg::CMy037_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy037_MFCDlg::IDD, pParent)
	, EDIT_CS(_T(""))
	, m_nPlanNum(0)
	, m_nowNum(0)
	, m_nPreOperator(ONull)
	, LastPressIsOperater(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy037_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EDIT);
	DDX_Text(pDX, IDC_EDIT1, EDIT_CS);
}

BEGIN_MESSAGE_MAP(CMy037_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


ON_BN_CLICKED(IDC_BUTTON_BS, &CMy037_MFCDlg::OnBnClickedButtonBs)
ON_BN_CLICKED(IDC_BUTTON_CE, &CMy037_MFCDlg::OnBnClickedButtonCe)
ON_BN_CLICKED(IDC_BUTTON_C, &CMy037_MFCDlg::OnBnClickedButtonC)
ON_EN_CHANGE(IDC_EDIT1, &CMy037_MFCDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON_0, &CMy037_MFCDlg::OnBnClickedButton0)
ON_BN_CLICKED(IDC_BUTTON_1, &CMy037_MFCDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON_2, &CMy037_MFCDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON_3, &CMy037_MFCDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_5, &CMy037_MFCDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON_6, &CMy037_MFCDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON_7, &CMy037_MFCDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON_8, &CMy037_MFCDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON_9, &CMy037_MFCDlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON_4, &CMy037_MFCDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON_ZF, &CMy037_MFCDlg::OnBnClickedButtonZf)
ON_BN_CLICKED(IDC_BUTTON_DIAN, &CMy037_MFCDlg::OnBnClickedButtonDian)
ON_BN_CLICKED(IDC_BUTTON_CHU, &CMy037_MFCDlg::OnBnClickedButtonChu)
ON_BN_CLICKED(IDC_BUTTON_CHENG, &CMy037_MFCDlg::OnBnClickedButtonCheng)
ON_BN_CLICKED(IDC_BUTTON_JIAN, &CMy037_MFCDlg::OnBnClickedButtonJian)
ON_BN_CLICKED(IDC_BUTTON_JIA, &CMy037_MFCDlg::OnBnClickedButtonJia)
ON_BN_CLICKED(IDC_BUTTON_DENG, &CMy037_MFCDlg::OnBnClickedButtonDeng)
ON_BN_CLICKED(IDC_BUTTON_MC, &CMy037_MFCDlg::OnBnClickedButtonMc)
ON_BN_CLICKED(IDC_BUTTON_MR, &CMy037_MFCDlg::OnBnClickedButtonMr)
ON_BN_CLICKED(IDC_BUTTON_MS, &CMy037_MFCDlg::OnBnClickedButtonMs)
ON_BN_CLICKED(IDC_BUTTONMJIA, &CMy037_MFCDlg::OnBnClickedButtonmjia)
ON_BN_CLICKED(IDC_BUTTON_SQRT, &CMy037_MFCDlg::OnBnClickedButtonSqrt)
ON_BN_CLICKED(IDC_BUTTON_BAIFEN, &CMy037_MFCDlg::OnBnClickedButtonBaifen)
ON_BN_CLICKED(IDC_BUTTON_ONE_X, &CMy037_MFCDlg::OnBnClickedButtonOneX)
ON_COMMAND(ID_32777, &CMy037_MFCDlg::OnAbout)
END_MESSAGE_MAP()


// CMy037_MFCDlg 消息处理程序
BOOL CMy037_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	/*HWND h = ::GetDlgItem(m_hWnd, IDC_EDIT1);
	::SetWindowText(h, L"0.");*/
	EDIT.SetWindowText(L"");
	//this->GetDlgItem(IDC_EDIT1)->SetWindowText(L"0.");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy037_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy037_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy037_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//显示Edit
void CMy037_MFCDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}

//数字0
void CMy037_MFCDlg::OnBnClickedButton0()
{
	PressNum(0);
}

//数字1
void CMy037_MFCDlg::OnBnClickedButton1()
{
	PressNum(1);
}

//数字2
void CMy037_MFCDlg::OnBnClickedButton2()
{
	PressNum(2);
}

//数字3
void CMy037_MFCDlg::OnBnClickedButton3()
{
	PressNum(3);
}

//数字4
void CMy037_MFCDlg::OnBnClickedButton4()
{
	PressNum(4);
}

//数字5
void CMy037_MFCDlg::OnBnClickedButton5()
{
	PressNum(5);
}

//数字6
void CMy037_MFCDlg::OnBnClickedButton6()
{
	PressNum(6);
}

//数字7
void CMy037_MFCDlg::OnBnClickedButton7()
{
	PressNum(7);
}

//数字8
void CMy037_MFCDlg::OnBnClickedButton8()
{
	PressNum(8);
}

//数字9
void CMy037_MFCDlg::OnBnClickedButton9()
{
	PressNum(9);
}

//退格
void CMy037_MFCDlg::OnBnClickedButtonBs()
{
	// TODO:  在此添加控件通知处理程序代码
	EDIT_CS.GetBuffer()[EDIT_CS.GetLength() - 1] = 0;
	EDIT_CS.ReleaseBuffer();
	UpdateData(false);
}

//CE
void CMy037_MFCDlg::OnBnClickedButtonCe()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	EDIT_CS = _T("");
	UpdateData(false);
}

//C
void CMy037_MFCDlg::OnBnClickedButtonC()
{	
	//清零代码
	LastPressIsOperater = 0; //表示未按下运算符
	m_nPlanNum = 0;
	m_nowNum = 0;
	m_nPreOperator = this -> ONull;
	OnBnClickedButtonCe();
}

//正负+-
void CMy037_MFCDlg::OnBnClickedButtonZf()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	const TCHAR* ps = EDIT_CS.GetBuffer();
	if (ps[0] == '-'){
		ps++;
		EDIT_CS = ps;
	}
	else{
		CString s;
		s = _T("-");
		s += EDIT_CS;
		EDIT_CS = s;
	}
	EDIT_CS.ReleaseBuffer();
	UpdateData(false);
}

//点.
void CMy037_MFCDlg::OnBnClickedButtonDian()
{
	UpdateData(TRUE);
	// TODO:  在此添加控件通知处理程序代码
	if (-1 == EDIT_CS.Find(L'.'))
	{
		EDIT_CS += L".";
	}
	UpdateData(false);
}

//除法
void CMy037_MFCDlg::OnBnClickedButtonChu()
{
	plan(ODiv);
}

//乘法
void CMy037_MFCDlg::OnBnClickedButtonCheng()
{
	plan(OMul);
}

//减法
void CMy037_MFCDlg::OnBnClickedButtonJian()
{
	plan(OSub);
}

//加法
void CMy037_MFCDlg::OnBnClickedButtonJia()
{
	plan(OAdd);
}

//MC
void CMy037_MFCDlg::OnBnClickedButtonMc()
{

}

//MR
void CMy037_MFCDlg::OnBnClickedButtonMr()
{

}

//MS
void CMy037_MFCDlg::OnBnClickedButtonMs()
{

}

//M+
void CMy037_MFCDlg::OnBnClickedButtonmjia()
{
	
}

//Sqrt
void CMy037_MFCDlg::OnBnClickedButtonSqrt()
{
	
}

//取模
void CMy037_MFCDlg::OnBnClickedButtonBaifen()
{
	plan(OMod);
}

//1/x
void CMy037_MFCDlg::OnBnClickedButtonOneX()
{
	
}

//等于
void CMy037_MFCDlg::OnBnClickedButtonDeng()
{
	plan(m_nPreOperator);
}

// 用于计算四则运算
int CMy037_MFCDlg::plan(OperatorNum nOperator)
{
	//如果上次按下的是运算符,则更新m_nPreOperator的值,并退出此函数
	if (LastPressIsOperater){
		m_nPreOperator = nOperator;
		/*EDIT_CS.Format(L"%d", nOperator);
		UpdateData(false);*/
		return 1;
	}
	m_nowNum = _wtoi(EDIT_CS);	//字符转数字
	switch (m_nPreOperator){
	case ONull:	//空运算
		m_nPlanNum = m_nowNum;	//当前编辑框的值
		break;
	case OAdd:	//+
		m_nPlanNum += m_nowNum;
		break;
	case OSub:	//-
		m_nPlanNum = m_nPlanNum - m_nowNum;
		break;
	case OMul:	//*
		m_nPlanNum = m_nPlanNum * m_nowNum;
		break;
	case ODiv:	//  /
		m_nPlanNum = m_nPlanNum / m_nowNum;
		break;
	case OMod:	//  取模
		m_nPlanNum = m_nPlanNum % m_nowNum;
		break;
	}
	m_nPreOperator = nOperator;
	LastPressIsOperater = 1;
	EDIT_CS.Format(L"%d", m_nPlanNum);
	UpdateData(false);
	return 0;
}


// 表示按下了0-9
int CMy037_MFCDlg::PressNum(int nNum)
{
	CString ts;
	ts.Format(L"%d", nNum);
	if (LastPressIsOperater){	//上次按下的是运算符,重新赋值
		EDIT_CS = ts;
	}
	else{
		EDIT_CS += ts;	//上次按下不是运算符
	}
	LastPressIsOperater = 0;
	UpdateData(false);
	return 0;
}
CAboutDlg about; //全局变量

//关于窗口
void CMy037_MFCDlg::OnAbout()
{
	if (about.m_hWnd == 0){	//0就是没被创建
		about.Create(IDD_ABOUTBOX, this);
	}
	about.ShowWindow(SW_SHOW);
}


void CAboutDlg::OnHelp1()
{
	MessageBox(L"21111");
}
