
// 045_2_MFC动态链接库Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "045_2_MFC动态链接库.h"
#include "045_2_MFC动态链接库Dlg.h"
#include "afxdialogex.h"

#pragma comment(lib,"045_MFC动态链接库.lib")

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
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy045_2_MFC动态链接库Dlg 对话框



CMy045_2_MFC动态链接库Dlg::CMy045_2_MFC动态链接库Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy045_2_MFC动态链接库Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy045_2_MFC动态链接库Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy045_2_MFC动态链接库Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy045_2_MFC动态链接库Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy045_2_MFC动态链接库Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy045_2_MFC动态链接库Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy045_2_MFC动态链接库Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy045_2_MFC动态链接库Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMy045_2_MFC动态链接库Dlg 消息处理程序

BOOL CMy045_2_MFC动态链接库Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy045_2_MFC动态链接库Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy045_2_MFC动态链接库Dlg::OnPaint()
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
HCURSOR CMy045_2_MFC动态链接库Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


extern void _declspec(dllimport) showdlg1(void);
extern void _declspec(dllimport) showdlg2(void);
extern void _declspec(dllimport) showdlg3(void);
extern void _declspec(dllimport) showdlg4(void);
extern void _declspec(dllimport) showdlg5(void);
void CMy045_2_MFC动态链接库Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	showdlg1();
}


void CMy045_2_MFC动态链接库Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	showdlg2();
}


void CMy045_2_MFC动态链接库Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	showdlg3();
}


void CMy045_2_MFC动态链接库Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	showdlg4();
}


void CMy045_2_MFC动态链接库Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	showdlg5();
}
