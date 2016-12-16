// second_two.cpp : 实现文件
//

#include "stdafx.h"
#include "project2.h"
#include "second_two.h"
#include "afxdialogex.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// second_two 对话框

IMPLEMENT_DYNAMIC(second_two, CDialogEx)

second_two::second_two(CWnd* pParent /*=NULL*/)
	: CDialogEx(second_two::IDD, pParent)
	, m_seek(_T(""))
	, m_seek2(_T(""))
{

}

second_two::~second_two()
{
}

void second_two::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_seek);
	DDX_Text(pDX, IDC_EDIT2, m_seek2);
}


BEGIN_MESSAGE_MAP(second_two, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &second_two::OnBnClickedButton1)
END_MESSAGE_MAP()


// second_two 消息处理程序


void second_two::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 UpdateData(TRUE); 

	string num;
	string name;
	string chinese;
	string math;
	string english;
	string sum;
	string num1;

	ifstream in;
	string str,str2;
	
	num1=m_seek;
	in.open("f:\\boxiang_stu.txt",ios::in);
	while(!in.eof())
	{

	//	getline(in,str,'\n');
	///	str2+=str+"\r\n";
		in>>num>>name>>chinese>>math>>english>>sum;
		if(num==num1)
		{
			str2+=num+" "+name+" "+chinese+" "+math+" "+english+" "+sum+"\r\n";

			CString cstr(str2.c_str());
			cstr=str2.c_str();
			m_seek2=cstr;
		}
	}
	 UpdateData(FALSE);   
}
