#pragma once


// five 对话框

class five : public CDialogEx
{
	DECLARE_DYNAMIC(five)

public:
	five(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~five();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	double m_count1;
	double m_count2;
	double m_count3;
	double m_count4;
	double m_count5;
	double m_x;
	double m_y;
	double m_width;
	double m_height;
	double m_n1;
	double m_n2;
	double m_n3;
	double m_n4;
	double m_n5;
	double m_sum1;
	double m_sum2;
	double m_sum3;
	double m_sum4;
	double m_sum5;
	double m_sum;
	double m_height0;
	double m_height2;
	double m_height3;
	double m_height4;
	double m_height5;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	int m_scroe;
};
