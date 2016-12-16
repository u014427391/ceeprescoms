// five.cpp : 实现文件
//

#include "stdafx.h"
#include "project2.h"
#include "five.h"
#include "afxdialogex.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// five 对话框

IMPLEMENT_DYNAMIC(five, CDialogEx)

five::five(CWnd* pParent /*=NULL*/)
	: CDialogEx(five::IDD, pParent)
	, m_count1(0)
	, m_count2(0)
	, m_count3(0)
	, m_count4(0)
	, m_count5(0)
	, m_x(0)
	, m_y(0)
	, m_width(0)
	, m_height(0)
	, m_n1(0)
	, m_n2(0)
	, m_n3(0)
	, m_n4(0)
	, m_n5(0)
	, m_sum1(0)
	, m_sum2(0)
	, m_sum3(0)
	, m_sum4(0)
	, m_sum5(0)
	, m_sum(0)
	, m_height0(0)
	, m_height2(0)
	, m_height3(0)
	, m_height4(0)
	, m_height5(0)
	, m_scroe(0)
{

}

five::~five()
{
}

void five::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_count1);
	DDX_Text(pDX, IDC_EDIT2, m_count2);
	DDX_Text(pDX, IDC_EDIT3, m_count3);
	DDX_Text(pDX, IDC_EDIT4, m_count4);
	DDX_Text(pDX, IDC_EDIT5, m_count5);
	DDX_Text(pDX, IDC_EDIT6, m_scroe);
}


BEGIN_MESSAGE_MAP(five, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &five::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &five::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &five::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &five::OnBnClickedButton4)
END_MESSAGE_MAP()


// five 消息处理程序


void five::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	
	 	  UpdateData(TRUE);
	  ///UpdateData(TRUE); 
	  ifstream in,in2;

		string num;
		string name;
		string sex;
		int age;
		string address;
		double chinese;
		double math;
		double english;
		double history;
		double art;
		double geograpy;
		double physics;
		double sum;
		string category;
		string subject;
		m_n1=m_n2=m_n3=m_n4=m_n5=0.0;
		m_sum1=m_sum2=m_sum3=m_sum4=m_sum5=0.0;
	  in.open("f:\\student_bo.txt",ios::in);

	   in2.open("f:\\student_bo.txt",ios::in);
	  while(!in.eof())
	{
	    in>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

		        if((address=="湛江")&&(category=="理科"))
				{
					m_sum1++;
				}
				else if((address=="广州")&&(category=="理科"))
				{
					m_sum2++;
				}
				else if((address=="珠海")&&(category=="理科"))
				{
					m_sum3++;
				}
				else if((address=="汕头")&&(category=="理科"))
				{
					m_sum4++;
				}
				else if((address=="深圳")&&(category=="理科"))
				{
					m_sum5++;
				}

	 }

	  		while(!in2.eof())
		{
		
        	  in2>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

			if((sum>=m_scroe))
			{
      //   cout<<num<<" "<<name<<" "<<sex<<" "<<age<<" "<<address<<" "<<category<<
       //      " "<<chinese<<" "<<math
	  //     <<" "<<english<<" "<<history<<" "<<geograpy<<" "<<sum<<endl;
			
				if((address=="湛江")&&(category=="理科"))
				{
					m_n1++;
				}
				else if((address=="广州")&&(category=="理科"))
				{
					m_n2++;
				}
				else if((address=="珠海")&&(category=="理科"))
				{
					m_n3++;
				}
				else if((address=="汕头")&&(category=="理科"))
				{
					m_n4++;
				}
				else if((address=="深圳")&&(category=="理科"))
				{
					m_n5++;
				}
			
			}
		  
	    }

	//int width;
	GetDlgItem(IDC_IMG)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG3)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG4)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG5)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG6)->ShowWindow(TRUE);

	GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);

	m_height0=600.0;//总高度
	m_count1=m_n1;
	m_count2=m_n2;
	m_count3=m_n3;
	m_count4=m_n4;
	m_count5=m_n5;

	//m_count1=m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;
		m_sum=100;
			//m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;

	m_height=(m_n1/m_sum)*m_height0;
	m_height2=(m_n2/m_sum)*m_height0;
	m_height3=(m_n3/m_sum)*m_height0;
	m_height4=(m_n4/m_sum)*m_height0;
	m_height5=(m_n5/m_sum)*m_height0;
	//GetDlgItem (IDC_IMG)->GetWindow(width);
	//m_width=width;
	//GetDlgItem(IDC_BUTTON1)->MoveWindow( x, y, width, height );
 GetDlgItem(IDC_IMG)->MoveWindow( 120,(m_height0-150-m_height), 40, m_height );
GetDlgItem(IDC_IMG3)->MoveWindow( 170,(m_height0-150-m_height2), 40, m_height2 );
GetDlgItem(IDC_IMG4)->MoveWindow( 220,(m_height0-150-m_height3), 40, m_height3 );
GetDlgItem(IDC_IMG5)->MoveWindow( 270,(m_height0-150-m_height4), 40, m_height4 );
GetDlgItem(IDC_IMG6)->MoveWindow( 320,(m_height0-150-m_height5), 40, m_height5 );

GetDlgItem(IDC_EDIT1)->MoveWindow( 120,(m_height0-m_height-175.0), 30, 20 );
GetDlgItem(IDC_EDIT2)->MoveWindow( 170,(m_height0-m_height2-175.0), 30, 20 );
GetDlgItem(IDC_EDIT3)->MoveWindow( 220,(m_height0-m_height3-175.0), 30, 20 );
GetDlgItem(IDC_EDIT4)->MoveWindow( 270,(m_height0-m_height4-175.0), 30, 20 );
GetDlgItem(IDC_EDIT5)->MoveWindow( 320,(m_height0-m_height5-175.0), 30, 20 );
//	CRect rect;
// GetDlgItem(IDC_IMG)->GetWindowRect(&rect);
 /// m_width=rect.Width();
 // m_height=rect.Height();
     UpdateData(FALSE);   

}


void five::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	  UpdateData(TRUE);
	  ///UpdateData(TRUE); 
	  ifstream in,in2;

		string num;
		string name;
		string sex;
		int age;
		string address;
		double chinese;
		double math;
		double english;
		double history;
		double art;
		double geograpy;
		double physics;
		double sum;
		string category;
		string subject;
		m_n1=m_n2=m_n3=m_n4=m_n5=0;
		m_sum1=m_sum2=m_sum3=m_sum4=m_sum5=0;
	  in.open("f:\\student_bo.txt",ios::in);

	   in2.open("f:\\student_bo.txt",ios::in);
	  while(!in.eof())
	{
	    in>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

		        if((address=="湛江")&&(category=="文科"))
				{
					m_sum1++;
				}
				else if((address=="广州")&&(category=="文科"))
				{
					m_sum2++;
				}
				else if((address=="珠海")&&(category=="文科"))
				{
					m_sum3++;
				}
				else if((address=="汕头")&&(category=="文科"))
				{
					m_sum4++;
				}
				else if((address=="深圳")&&(category=="文科"))
				{
					m_sum5++;
				}

	 }

	  		while(!in2.eof())
		{
		
        	  in2>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

			if((sum>=m_scroe))
			{
      //   cout<<num<<" "<<name<<" "<<sex<<" "<<age<<" "<<address<<" "<<category<<
       //      " "<<chinese<<" "<<math
	  //     <<" "<<english<<" "<<history<<" "<<geograpy<<" "<<sum<<endl;
			
				if((address=="湛江")&&(category=="文科"))
				{
					m_n1++;
				}
				else if((address=="广州")&&(category=="文科"))
				{
					m_n2++;
				}
				else if((address=="珠海")&&(category=="文科"))
				{
					m_n3++;
				}
				else if((address=="汕头")&&(category=="文科"))
				{
					m_n4++;
				}
				else if((address=="深圳")&&(category=="文科"))
				{
					m_n5++;
				}
			
			}
		  
	    }

	//int width;
	GetDlgItem(IDC_IMG)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG3)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG4)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG5)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG6)->ShowWindow(TRUE);

	GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);

	m_height0=600;//总高度
	m_count1=m_n1;
	m_count2=m_n2;
	m_count3=m_n3;
	m_count4=m_n4;
	m_count5=m_n5;

	//m_count1=m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;
		m_sum=100;
			//m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;
	 m_height=(m_n1/m_sum)*m_height0;
	
	m_height2=(m_n2/m_sum)*m_height0;
	m_height3=(m_n3/m_sum)*m_height0;
	m_height4=(m_n4/m_sum)*m_height0;
	m_height5=(m_n5/m_sum)*m_height0;

	//GetDlgItem (IDC_IMG)->GetWindow(width);
	//m_width=width;
	//GetDlgItem(IDC_BUTTON1)->MoveWindow( x, y, width, height );
 GetDlgItem(IDC_IMG)->MoveWindow( 120,(m_height0-150-m_height), 40, m_height );
GetDlgItem(IDC_IMG3)->MoveWindow( 170,(m_height0-150-m_height2), 40, m_height2 );
GetDlgItem(IDC_IMG4)->MoveWindow( 220,(m_height0-150-m_height3), 40, m_height3 );
GetDlgItem(IDC_IMG5)->MoveWindow( 270,(m_height0-150-m_height4), 40, m_height4 );
GetDlgItem(IDC_IMG6)->MoveWindow( 320,(m_height0-150-m_height5), 40, m_height5 );

GetDlgItem(IDC_EDIT1)->MoveWindow( 120,(m_height0-m_height-175), 30, 20 );
GetDlgItem(IDC_EDIT2)->MoveWindow( 170,(m_height0-m_height2-175), 30, 20 );
GetDlgItem(IDC_EDIT3)->MoveWindow( 220,(m_height0-m_height3-175), 30, 20 );
GetDlgItem(IDC_EDIT4)->MoveWindow( 270,(m_height0-m_height4-175), 30, 20 );
GetDlgItem(IDC_EDIT5)->MoveWindow( 320,(m_height0-m_height5-175), 30, 20 );
//	CRect rect;
// GetDlgItem(IDC_IMG)->GetWindowRect(&rect);
 /// m_width=rect.Width();
 // m_height=rect.Height();
     UpdateData(FALSE);   

}


void five::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

		 UpdateData(TRUE);
	  ///UpdateData(TRUE); 
	  ifstream in,in2;

		string num;
		string name;
		string sex;
		int age;
		string address;
		double chinese;
		double math;
		double english;
		double history;
		double art;
		double geograpy;
		double physics;
		double sum;
		string category;
		string subject;
     m_n1=m_n2=m_n3=m_n4=m_n5=0;
		m_sum1=m_sum2=m_sum3=m_sum4=m_sum5=0;
	  in.open("f:\\student_bo.txt",ios::in);

	   in2.open("f:\\student_bo.txt",ios::in);
	  while(!in.eof())
	{
	    in>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

		        if((address=="湛江")&&(category=="艺术"))
				{
					m_sum1++;
				}
				else if((address=="广州")&&(category=="艺术"))
				{
					m_sum2++;
				}
				else if((address=="珠海")&&(category=="艺术"))
				{
					m_sum3++;
				}
				else if((address=="汕头")&&(category=="艺术"))
				{
					m_sum4++;
				}
				else if((address=="深圳")&&(category=="艺术"))
				{
					m_sum5++;
				}

	 }

	  		while(!in2.eof())
		{
		
        	  in2>>num>>name>>sex>>age>>address>>category>>
		chinese>>math
		>>english>>history>>geograpy>>sum;

			if((sum>=m_scroe))
			{
      //   cout<<num<<" "<<name<<" "<<sex<<" "<<age<<" "<<address<<" "<<category<<
       //      " "<<chinese<<" "<<math
	  //     <<" "<<english<<" "<<history<<" "<<geograpy<<" "<<sum<<endl;
			
				if((address=="湛江")&&(category=="艺术"))
				{
					m_n1++;
				}
				else if((address=="广州")&&(category=="艺术"))
				{
					m_n2++;
				}
				else if((address=="珠海")&&(category=="艺术"))
				{
					m_n3++;
				}
				else if((address=="汕头")&&(category=="艺术"))
				{
					m_n4++;
				}
				else if((address=="深圳")&&(category=="艺术"))
				{
					m_n5++;
				}
			
			}
		  
	    }

	//int width;
	GetDlgItem(IDC_IMG)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG3)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG4)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG5)->ShowWindow(TRUE);
	GetDlgItem(IDC_IMG6)->ShowWindow(TRUE);

	GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);

	m_height0=600;//总高度
	m_count1=m_n1;
	m_count2=m_n2;
	m_count3=m_n3;
	m_count4=m_n4;
	m_count5=m_n5;

	//m_count1=m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;
		m_sum=100;
			//m_sum1+m_sum2+m_sum3+m_sum4+m_sum5;
	 m_height=(m_n1/m_sum)*m_height0;
	
	m_height2=(m_n2/m_sum)*m_height0;
	m_height3=(m_n3/m_sum)*m_height0;
	m_height4=(m_n4/m_sum)*m_height0;
	m_height5=(m_n5/m_sum)*m_height0;

	//GetDlgItem (IDC_IMG)->GetWindow(width);
	//m_width=width;
	//GetDlgItem(IDC_BUTTON1)->MoveWindow( x, y, width, height );
 GetDlgItem(IDC_IMG)->MoveWindow( 120,(m_height0-150-m_height), 40, m_height );
GetDlgItem(IDC_IMG3)->MoveWindow( 170,(m_height0-150-m_height2), 40, m_height2 );
GetDlgItem(IDC_IMG4)->MoveWindow( 220,(m_height0-150-m_height3), 40, m_height3 );
GetDlgItem(IDC_IMG5)->MoveWindow( 270,(m_height0-150-m_height4), 40, m_height4 );
GetDlgItem(IDC_IMG6)->MoveWindow( 320,(m_height0-150-m_height5), 40, m_height5 );

GetDlgItem(IDC_EDIT1)->MoveWindow( 120,(m_height0-m_height-175), 30, 20 );
GetDlgItem(IDC_EDIT2)->MoveWindow( 170,(m_height0-m_height2-175), 30, 20 );
GetDlgItem(IDC_EDIT3)->MoveWindow( 220,(m_height0-m_height3-175), 30, 20 );
GetDlgItem(IDC_EDIT4)->MoveWindow( 270,(m_height0-m_height4-175), 30, 20 );
GetDlgItem(IDC_EDIT5)->MoveWindow( 320,(m_height0-m_height5-175), 30, 20 );
 UpdateData(FALSE);  
}


void five::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
