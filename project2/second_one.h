#pragma once


// second_one 对话框

class second_one : public CDialogEx
{
	DECLARE_DYNAMIC(second_one)

public:
	second_one(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~second_one();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_stu;
};
