// first.cpp : 实现文件
//

#include "stdafx.h"
#include "project2.h"
#include "first.h"
#include "afxdialogex.h"

#include <iostream>
#include <stdio.h>
#include<fstream>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h> 
#include <cstdlib> 
#include <string>
#include <math.h>
using namespace std;

#define CLRSCR	system("cls")
#define PRINT_TITLE "\n序号\t考号\t\t姓名\t语文\t数学\t英语\t总分\n"
#define PRINT_FORMAT "%d\t%s\t%s\t%d\t%d\t%d\t%d\n",i,p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define WRITE_FORMAT "%s\t%s\t%d\t%d\t%d\t%d\n",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define READ_FORMAT "%s %s %d %d %d %d",&p->stu.num,&p->stu.name,&p->stu.Chinese,&p->stu.math,&p->stu.English,&p->stu.count_score
// first 对话框

IMPLEMENT_DYNAMIC(first, CDialogEx)

first::first(CWnd* pParent /*=NULL*/)
	: CDialogEx(first::IDD, pParent)
	, m_value10(_T(""))
{

}

first::~first()
{
}

void first::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value10);
}


BEGIN_MESSAGE_MAP(first, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &first::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &first::OnBnClickedButton2)
END_MESSAGE_MAP()


// first 消息处理程序
//定义学生类
class student_bx
{	
public:
	char	num[40];
	char    name[20];//三个汉字长度为6个字节，应多定义一个字节来存放字符串结束符'\0'
	int	Chinese;
	int	math;
	int	English;
	int	count_score;
};

//定义单链表类
class node	 
{	
public:
	 student_bx stu;
	 node *next;
};

int MySelect(node * head,node *temp)   
{	
	int  i=0; 
	node *p,*tp=temp;
	p=head->next;
	FILE *fp;
	char file[15]="f:\\English.txt";
	if((fp=fopen(file,"w+"))==NULL)
	{
		printf("\n\t文件创建失败\n");

		exit(0);
	}


	while (NULL!=p)
	{
		if(p->stu.English>100&&p->stu.count_score>300)
		{
			node *end;
			end = (node *)malloc(sizeof(node));
			tp->next=end;
			tp=end;
			tp->next=NULL;
			tp->stu=p->stu;
		
			if(i==0)
				printf (PRINT_TITLE);
			i++;
			printf(PRINT_FORMAT);
			if(p->next==NULL)//不要最后一行的回车，这样的话导入该文件时就不会有末尾的乱码
				fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
			else
				fprintf(fp,WRITE_FORMAT);				

		}
		p=p->next;
	}
	fclose(fp);	
	if(i==0)
		printf("\n\t英语超过100分且总分成绩超过300分的学生人数为零\n");
	return i;
}



void Fprintf(node *head)
{
	char file[40]={"f:\\boxiang_stu.txt"};
	FILE *fp;
	if((fp=fopen(file,"w"))==NULL)
	{
		printf("\n\t文件打开失败，按任意键退出\n");
		getch();
		exit(0);
	}
	
	node *p=head->next;
	while(NULL!=p)
	{	
		if(p->next==NULL)//不要最后一行的回车，这样的话导入该文件时就不会有末尾的乱码
			fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
		else
			fprintf(fp,WRITE_FORMAT);
		p=p->next;
	}		
		fclose(fp);
}
void InsertSort(node *head)//总分从大到小排序
{ 
	node *p,*q,*u,*h,*w,*n;
	int j=0;
    p=head->next;
    while(p!=NULL)
    {
		j++;
		p=p->next;
	}
	for(int i=0;i<j-1;i++)
	{
		p=head;
		q=p->next;
		for(int z=0;z<=j-2-i;z++)
		{
			int y=0;
			if((q->next->stu.count_score)>(p->next->stu.count_score))
			{
				n=q->next;
				u=n->next;
				w=p->next;
				p->next=n;
				n->next=w;
				q->next=u;
				p=p->next;
				y=1;
			}
			if(y==0)
			{
			p=p->next;
			q=q->next;		
			}
		}
	}
}


void FscanfFromFile(node *head)//cdsgfdgfhhhhhhhhhhhhhhhhhhhhhhh
{	
	char file[20]="f:\\student1.txt";
	char file2[20]="f:\\student2.txt";
	FILE *fp,*fp2;
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("\n\t文件打开失败，按任意键退出\n");
		getch();
		exit(0);
	}
	
	if((fp2=fopen(file2,"r"))==NULL)
	{
		printf("\n\t文件打开失败，按任意键退出\n");
		getch();
		exit(0);
	}

	node *p=head;
	while(!feof(fp))
	{	
		node *end; 	
		end = (node *)malloc(sizeof(node));
		p->next=end;

		p=end;
     	p->next=NULL;	
		fscanf(fp,READ_FORMAT);		
	}

	while(!feof(fp2))
	{	
		node *end; 	
		end = (node *)malloc(sizeof(node));
		p->next=end;

		p=end;
		p->next=NULL;	
		fscanf(fp2,READ_FORMAT);		
	}
	
	printf("\n\t信息导入成功\n");

		

	InsertSort(head);
	Fprintf(head);
	fclose(fp);
}

void ShowList(node *head)//带头结点的链表
{
	node *p=head->next;
	int i=0;
	printf ("\t\t\t成绩汇总排序表\n");
	printf (PRINT_TITLE);
	while(NULL!=p )
	{	i++;
		printf (PRINT_FORMAT);
		p=p->next;
	}

}

void FprintfToFile(node *head)
{
	char file[50]={"f:\\boxiang_stu.txt"};

	//printf("\n输入要写入的文件名:");
	//scanf("%s",file);

	FILE *fp;
	if((fp=fopen(file,"w+"))==NULL)
	{
		printf("\n\t文件创建失败\n");

		exit(0);
	}
	node *p=head->next;
	while(NULL!=p)
	{	
		if(p->next==NULL)//不要最后一行的回车，这样的话导入该文件时就不会有末尾的乱码
			fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
		else
			fprintf(fp,WRITE_FORMAT);
		p=p->next;
	}
	fclose(fp);
	printf("\n\t数据写入成功\n",file);//printf输出双引号要用转义字\"

}


node *ClearList(node *head)
{
	node *p=head->next;
	while(NULL!=p)
	{
		node *tp=p->next;
		free(p);
		p=tp;
	}
	return head->next=NULL;

}


void first::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	  UpdateData(TRUE);   
	 node *head;
	int i=0;
	head = (node *)malloc(sizeof(node));
	strcpy(head->stu.num," ");
	strcpy(head->stu.name," ");
	head->stu.Chinese=0;
	head->stu.math=0;
	head->stu.English=0;
	head->stu.count_score=0;
	node *temp= (node *)malloc(sizeof(node));//保存查找结果的头结点

	FscanfFromFile(head);
	ShowList(head);

	ifstream in;

	string str,str2;
	m_value10="";
	in.open("f:\\boxiang_stu.txt",ios::in);
	while(!in.eof())
	{
		getline(in,str,'\n');
		str2+=str+"\r\n";
		CString cstr(str2.c_str());
		cstr=str2.c_str();
		m_value10=cstr;
	}

	  UpdateData(FALSE);   
}


void first::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	 UpdateData(TRUE);   
	 node *head;
	int i=0;
	head = (node *)malloc(sizeof(node));
	strcpy(head->stu.num," ");
	strcpy(head->stu.name," ");
	head->stu.Chinese=0;
	head->stu.math=0;
	head->stu.English=0;
	head->stu.count_score=0;
	node *temp= (node *)malloc(sizeof(node));//保存查找结果的头结点

	FscanfFromFile(head);

	MySelect(head,temp);

	ifstream in;
	m_value10="";
	string str="",str2="";
	in.open("f:\\English.txt",ios::in);
	while(!in.eof())
	{
		getline(in,str,'\n');
		str2+=str+"\r\n";
		CString cstr(str2.c_str());
		cstr=str2.c_str();
		m_value10=cstr;
	}

	  UpdateData(FALSE);   
}
