
// project2Dlg.h : 头文件
//

#pragma once

class Cproject2DlgAutoProxy;


// Cproject2Dlg 对话框
class Cproject2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Cproject2Dlg);
	friend class Cproject2DlgAutoProxy;

// 构造
public:
	Cproject2Dlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~Cproject2Dlg();

// 对话框数据
	enum { IDD = IDD_PROJECT2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	Cproject2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
