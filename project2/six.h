#pragma once


// six 对话框

class six : public CDialogEx
{
	DECLARE_DYNAMIC(six)

public:
	six(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~six();

// 对话框数据
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_seek_six;
	CString m_value_six;
	afx_msg void OnBnClickedButton1();
};
