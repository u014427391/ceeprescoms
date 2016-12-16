#pragma once


// four 对话框

class four : public CDialogEx
{
	DECLARE_DYNAMIC(four)

public:
	four(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~four();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_seek1;
	CString m_value2;
};
