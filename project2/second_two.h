#pragma once


// second_two 对话框

class second_two : public CDialogEx
{
	DECLARE_DYNAMIC(second_two)

public:
	second_two(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~second_two();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_seek;
	CString m_seek2;
};
