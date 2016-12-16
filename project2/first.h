#pragma once


// first 对话框

class first : public CDialogEx
{
	DECLARE_DYNAMIC(first)

public:
	first(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~first();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_value10;
	afx_msg void OnBnClickedButton2();
};
