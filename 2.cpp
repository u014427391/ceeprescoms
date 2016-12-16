
#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#define CLRSCR	system("cls")
#define PRINT_TITLE "\n序号\t考号\t\t姓名\t语文\t数学\t英语\t总分\n"
#define PRINT_FORMAT "%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",i,p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define WRITE_FORMAT "%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define READ_FORMAT "%s %s %lf %lf %lf %lf",&p->stu.num,&p->stu.name,&p->stu.Chinese,&p->stu.math,&p->stu.English,&p->stu.count_score
#include<sstream>

string DoubleToString(double d)
{
    //Need #include <sstream> 
    using namespace std;
    string str;
    stringstream ss;
    ss<<d;
    ss>>str;
    return str;
}
//定义学生类
class student
{	
public:
	char	num[9];
	char    name[7];//三个汉字长度为6个字节，应多定义一个字节来存放字符串结束符'\0'
	double	Chinese;
	double	math;
	double	English;
	double	count_score;
};

//定义单链表类
class node	 
{	
public:
	 student stu;
	 node *next;
};
int MySelect(node * head,node *temp)   //返回查找到符合条件的项目数
{	
	int equal,N;
	char CHAR[10];


	printf("----------------------------------------------\n\n");
	printf("查找模式:1是相等查找,0是不相等查找\n");
	printf("列名编号:1是考号,2是姓名,3是语文成绩,4是数学成绩，5是英语成绩,6是总分\n");
	printf("\n--------------------------------------------\n");

	do
	{
	printf("\n选择查找模式:");
	equal=getche();
	if((equal!='1')&&(equal!='0'))
		printf("\n\t输入错误\n");
	}while((equal!='1')&&(equal!='0'));
	equal=equal-48;


	
	do 
	{
	printf("\n输入列名编号:");
	N=getche();
	if(N!='1'&&N!='2'&&N!='3'&&N!='4'&&N!='5'&&N!='6')
		printf("\n\t输入错误\n");
	}while(N!='1'&&N!='2'&&N!='3'&&N!='4'&&N!='5'&&N!='6');
	switch(N)
	{
	case '1':	N=0;break;//N为字节数
	case '2':	N=9;break;
	case '3':	break;
	case '4':	break;
	case '5':	break;
	case '6':	break;
	}

	

	printf("\n输入关键字:");
	scanf("%s",CHAR);

	int  i=0,flag; 
	node *p,*tp=temp;
	p=head->next;
	
	while (NULL!=p)
	{	
		if(N==0||N==9)
		{
		flag=strcmp((char *)p+N,CHAR);//(char *)p+N为指针位置,比较每一条记录中的考号、姓名等数据是否与输入的关键字相同
		if((abs(flag)+equal)==1)//当equal为1时是相等查找,为0时是不相等查找;当abs(flag)为0时，数据与关键字相同,若为1则不同
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
		} 
		p=p->next;

		}

		else
		{
			cout.precision(6);
			if(N=='3')
			{
			flag=strcmp(  (DoubleToString(p->stu.Chinese).c_str()),CHAR  );
			}

			if(N=='4'){
			flag=strcmp(  (DoubleToString(p->stu.math).c_str()),CHAR  );
			}

			if(N=='5'){
			flag=strcmp(  (DoubleToString(p->stu.English).c_str()),CHAR  );
			}

			if(N=='6'){
			flag=strcmp(  (DoubleToString(p->stu.count_score).c_str()),CHAR  );
			}

			if(flag==0)//当equal为1时是相等查找,为0时是不相等查找;当abs(flag)为0时，数据与关键字相同,若为1则不同
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
			} 
			p=p->next;
		}

	}

	if(i==0)
		printf("\n\t没有查找到符合条件的信息\n");

return i;
}

int SelectScore(node * head)   
{	
	char CHAR[10];


	printf("----------------------------------------------\n\n");
	printf("请输入考号：\n");	
	scanf("%s",CHAR);

	int  i=0,flag; 
	node *p;
	p=head->next;
	
	while (NULL!=p)
	{	
		flag=strcmp((char *)p,CHAR);//比较每一条记录中的考号是否与查询的考号相同
		if(flag==0)
		{	
			if(i==0)
				printf (PRINT_TITLE);
			i++;
			printf(PRINT_FORMAT);
		} 
		p=p->next;

	}

	if(i==0)
		printf("\n\t没有查找到相应考号的信息\n");

return i;
}


void InsertSort(node *head)//总分从高到低排序
{ 
	node *p,*q,*r,*u;
    p=head->next;  
	head->next=NULL;
    while(p!=NULL)
    {
		r=head;  
		q=head->next;
         
		while(q!=NULL&&((q->stu.count_score)>(p->stu.count_score))) 
		{                       
			r=q; 
			q=q->next;
		}
		u=p->next; 
		p->next=r->next;   
		r->next=p;  

		p=u;
	}
}

void CheckNum(node *head)
{
	/*删除学号重复的条目*/
		node *release,*p;
		p=head->next;
		int m=0;
		while(NULL!=p->next)
		{
			node *p2=p;
			
			while(NULL!=p2->next)
			{
				if(0==strcmp(p->stu.num,p2->next->stu.num))
				{	m++;
					if(m==1)
					printf("\t\t以下条目因考号与前面的信息冲突而没有导入\n");

			printf("%s\t%s\t%lf\t%lf\t%lf\t%lf",p2->stu.num,p2->stu.name,p2->stu.Chinese,p2->stu.math,p2->stu.English,p2->stu.count_score);

					release=p2->next;
					p2->next=p2->next->next; 
					free(release);				
				}
				p2=p2->next;
			}

			p=p->next;
		}


}

void Fprintf(node *head)
{
	char file[15]="student.txt";
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
			fprintf(fp,"%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
		else
			fprintf(fp,WRITE_FORMAT);
		p=p->next;
	}		
		fclose(fp);
}
void FscanfFromFile(node *head)
{	
	char file[20]="student1.txt";
	FILE *fp;
	if((fp=fopen(file,"r"))==NULL)
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
	printf("\n\t信息导入成功\n");
		

	InsertSort(head);
	Fprintf(head);
	fclose(fp);
}

void ShowList(node *head)//带头结点的链表
{
		InsertSort(head);
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
	char file[15];

	printf("\n输入要写入的文件名:");
	scanf("%s",file);

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
			fprintf(fp,"%s\t%s\t%lf\t%lf\t%lf\t%lf",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
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

int AddStu(node *head)
{
	cout<<"共需输入多少位学生信息？"<<endl;
	int i;
	cin>>i;
	int u=1;
	do
	{
	node *p,*p2=head,*p3;
	p=(node *)malloc(sizeof(node));
	cout<<"请依次输入第"<<u<<"位学生的考号、姓名、语文成绩、数学成绩和英语成绩（用空格隔开）：\n";
	if(u>1)
	{
		cout<<" 按y继续添加，按其他键停止添加\n\n"<<endl;
		char charget;
		charget=getch();
		if(charget=='y')
			goto loop1;
		else
			break;
	}
	loop1:
	cin>>p->stu.num>>p->stu.name>>p->stu.Chinese>>p->stu.math>>p->stu.English;
	p->stu.count_score = p->stu.Chinese + p->stu.math + p->stu.English;
	int flag=0;
	p2=head;
	while(NULL!=p2->next)
	{	/*找出第一个比新学生的考号大的位置，将新信息放在它前面*/
		if((flag=strcmp(p->stu.num,p2->next->stu.num))<0)
		{
			p3=p2->next;
			p2->next=p;
			p->next=p3;
			break;
		}
		
		p2=p2->next;
	}

	/*如果新添加学生的考号比已有的都大，放置最末尾*/
	if(flag>0)
	{
		p2->next=p;
		p->next=NULL;
	}
	i--;
	u++;
	}while(i>0);

	printf("信息添加成功\n");
	printf("\t按任意键返回\n");
	getch();	
	


	return 1;
}


int DeleteByNum(node *head)
{	char num[9];
	int flag=1;
	node *p=head,*p2;
	printf("输入要删除信息的考号：");
	scanf("%s",num);
	while(NULL!=p->next)
	{
		if((flag=strcmp(p->next->stu.num,num))==0)
		{
			p2=p->next;
			p->next=p->next->next;
			free(p2);
			printf("删除成功\n");
			break;		
		}
		p=p->next;
	}

	if(flag!=0)
		printf("你输入的考号不存在\n");
	printf("\t按任意键返回\n");
	getche();
		



	return 1;
}


int main()
{
	
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



		printf("欢迎使用\n");
		printf("\n----------------------------------------------\n");


		FscanfFromFile(head);




	char charget;

	do
	{
		printf("\n----------------------------------------------\n");
		printf("\n[1]信息显示\n");
		printf("[2]信息查找\n");
		printf("[3]查询成绩\n");
		printf("[4]添加信息\n");
		printf("[5]删除信息\n");
		printf("[6]退出程序\n");
		do
		{
		charget=getch();
		}while((charget!='1')&&(charget!='2')&&(charget!='3')&&(charget!='4')&&(charget!='5')&&(charget!='6'));

		switch(charget)
		{
		case '1':	ShowList(head);
					printf("\n按任意键显示上层操作菜单\n");
					getch();
					break;
		case '2':	if(0!=MySelect(head,temp))//查找结束不为空则进行下面的操作，为空则返回上层菜单
					{

						char charget2;
						do
						{
							printf("\n[1]在此基础上继续查找\n");
							printf("[2]将查找结果写入文件\n");
							printf("[3]退出本次查找\n");
							
							
							do
							{
								charget2=getch();
							}while((charget2!='1')&&(charget2!='2')&&(charget2!='3'));

							switch(charget2)
							{
							case '1':	if(0==MySelect(temp,temp))
										{	
											printf("\n按任意键结束本次查找\n");
											getch();
											charget2='3';	
										}
										break;

							case '2':	FprintfToFile(temp);
										charget2='3';//数据写入后，自动结束本次查找
										break;
							case '3':	ClearList(temp);//结束查找，释放暂存查找结果的链表
										break;
							

							}//end switch，结束本次查找

						}
						while(charget2!='3');//如果charget2也用charget的话，在查找中按键3会直接退出程序
					}//end if
					break;
		case '3':	SelectScore(head);break;
		case '4':	AddStu(head);Fprintf(head);break;
		case '5':	DeleteByNum(head);Fprintf(head);break;

					
		}//end switch，结束操作



	}while(charget!='6');

return 0;
}



