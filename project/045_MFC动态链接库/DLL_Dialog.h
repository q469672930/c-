#pragma once


// CDLL_Dialog 对话框

class CDLL_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDLL_Dialog)

public:
	CDLL_Dialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDLL_Dialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
