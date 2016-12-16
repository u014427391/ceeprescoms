// six.cpp : 实现文件
//

#include "stdafx.h"
#include "project2.h"
#include "six.h"
#include "afxdialogex.h"

#include<iostream>
#include<string>
#include<fstream>    //文件操作头文件
#include<vector>     //容器头文件
#include <algorithm> //容器排序所用头文件
#include <functional>//容器排序所用头文件
using namespace std;
/*
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;
using std::sort;
using std::greater;          //容器排序的时候会用到
using std::less;             //容器排序的时候会用到*/
//string BOOL_GRADE;
int BOOL__[5][3]={0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0};       //开关
// six 对话框

IMPLEMENT_DYNAMIC(six, CDialogEx)

six::six(CWnd* pParent /*=NULL*/)
	: CDialogEx(six::IDD, pParent)
	, m_seek_six(_T(""))
	, m_value_six(_T(""))
{

}

six::~six()
{
}

void six::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_seek_six);
	DDX_Text(pDX, IDC_EDIT2, m_value_six);
}


BEGIN_MESSAGE_MAP(six, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &six::OnBnClickedButton1)
END_MESSAGE_MAP()


// six 消息处理程序
/*void  System()
{
	cout << "输入查询语句格式如下:" << endl
		<< "(地区1,类型)+(地区1,类型)" << endl;
}

class Student_yong3                 //学生类
{
public:
	Student_yong3();
	~Student_yong3();
	int finput(fstream *fp);	//文件输入数据
	void fdisplay(fstream *fp); //文件输入数据
	void input();				//控制台输入数据
	void display();				//控制台输出数据
	void setMath();				//设定数学成绩
	void setChinese();			//设定语文成绩
	void setEnglish();			//设定英语成绩
	void getMath();				//获取数学成绩
	void getChinese();			//获取语文成绩
	void getEnglish();			//获取英语成绩


	string _num;				//考号
	string _name;               //姓名
	string _sex;                //性别
	unsigned int _age;          //年龄
	string _place;	            //地点
	string _type;               //考生类型
	string _wchar[5];           //储存前缀
	unsigned int _chinese;      //语文
	unsigned int _math;         //数学
	unsigned int _English;      //英语
	unsigned int _course1;     //课程一
	unsigned int _course2;     //课程二
	unsigned int _sum;          //总成绩
	unsigned int _list_num;     //序号	
	fstream *_fp;               //文件指针

};*/

/*----------------------排序规则------------------------------*/
//总分降序排序
/*
bool   greatersum(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._sum   >   s2._sum;
}
//英语成绩降序排序
bool   greaterEnglish(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._English   >   s2._English;
}
//语文成绩降序排序
bool   greaterchinese(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._chinese   >   s2._chinese;
}
//数学成绩降序排序
bool   greatermath(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._math   >   s2._math;
}
//第一科降序排序
bool   greatercourse1(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._course1   >   s2._course1;
}
//第二科降序排序
bool   greatercourse2(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._course2   >   s2._course2;
}*/
/*-------------------------排序规则--------------------------*/
/*
Student_yong3::Student_yong3()
{
	_fp = 0;                    //初始化文件指针
}

Student_yong3  ::~Student_yong3()
{
}
int Student_yong3::finput(fstream *fp)              //具体化finput()      
{
	_fp = fp;
	(*_fp) >> _num >> _name                  //设定学号姓名
		>> _sex >> _age                      //设定性别和年龄
		>> _place >> _type                   //地点和考生类型
		>> _wchar[0] >> _chinese >> _wchar[1] >> _math >> _wchar[2] >> _English;  //设定3科成绩
	if (_type == "文科")
	{
		(*_fp) >> _wchar[3] >> _course1 >> _wchar[4] >> _course2;     //设定历史和地理
	}
	else
	{
		(*_fp) >> _wchar[3] >> _course1;                 //设定物理或美术
	}
	if (_num == "" || _name == "")                             //如果没有读到数据返回false
	{
		return 0;
	}
	else
	{
		//计算总成绩
		_sum = _math + _English + _chinese + _course1 + _course2;
		return 1;
	}
}
void Student_yong3::fdisplay(fstream *fp)                                        //具体化fdisplay
{
	(*fp) << _num << "	" << _name << "	"						            //文件输出学号姓名
		<< _sex << " " << _age << "	"										//文件输出性别和年龄
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;  //文件输出3科成绩
	if (_type == "文科")
	{
		(*fp) << _wchar[3] << _course1 << _wchar[4] << _course2;          //文件输出历史和地理
	}
	else
	{
		(*fp) << _wchar[3] << _course1;                                    //文件输出物理或美术
	}
	(*fp) << "总分 " << _sum << endl;                                     //文件输出总分
}

/*       字符串处理 ,根据符号分类添加到容器                        */
/*
vector<string> splitEx(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();//分割字符串的长度,这样就可以支持如“,,”多字符串的分隔符
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//截取最后一个分隔符后的内容
	if (!lastString.empty())
		strs.push_back(lastString);//如果最后一个分隔符后还有内容就入队
	return strs;
}
*/
void six::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	 /* UpdateData(TRUE); 

	  fstream file_one("F://data_student6.txt");	 //打开第一个文件
	if (!file_one)						//如果打开失败
	{
		cout << "open error!" << endl;//显示出错信息
		abort();//程序退出
	}
	vector<Student_yong3>stu_data;					//定义一个空的stu_date容器,储存文件的全部信息
	do
	{
		Student_yong3 stu;
		if (stu.finput(&file_one))                //调用finpu(),输入成绩
		{
			stu_data.push_back(stu);              //添加对象到容器末端
		}
		else
		{
			file_one.close();                   //关闭文件
			break;                              //跳出循环
		}
	} while (true);
	vector<Student_yong3>data_two[5];                //定义一个容器数组
	//遍历stu_data
	for (auto it = stu_data.begin(); it != stu_data.end(); ++it)
	{
		if ((*it)._place == "广州")
		{
			data_two[0].push_back(*it);    //添加到data_two[0]
		}
		else if ((*it)._place == "汕头")
		{
			data_two[1].push_back(*it);	   //添加到data_two[1]
		}
		else if ((*it)._place == "珠海")
		{
			data_two[2].push_back(*it);	   //添加到data_two[2]
		}
		else if ((*it)._place == "湛江")
		{
			data_two[3].push_back(*it);    //添加到data_two[3]
		}
		else if ((*it)._place == "深圳")
		{
			data_two[4].push_back(*it);    //添加到data_two[4]
		}
	}
	vector<Student_yong3>data_three1[5][3];
	for (size_t i = 0; i < 5; ++i)
	{
		for (auto it = data_two[i].begin(); it != data_two[i].end(); ++it)
		{
			if (it->_type == "文科")
			{
				data_three1[i][0].push_back(*it); // 添加到data_two[i][0]
			}
			else if (it->_type == "理科")
			{
				data_three1[i][1].push_back(*it);//添加到data_two[i][1]
			}
			else if (it->_type == "艺术")
			{
				data_three1[i][2].push_back(*it); //添加到data_two[i][2]
			}
		}
	}
	System();
	//string str="P(汕头)+Q(艺术,文科,理科)+S(学号,姓名,性别)+T(总分)-Q()-P()-S(学号)%T(总分)";
	string str_1="";
	//cin >> str;
	str_1=m_seek_six;
	vector<string> strs2 = splitEx(str_1, "+");
	
	//+的情况
	for (unsigned int i = 0; i < strs2.size(); i++)
	{
		
			
			if (strs2[i].find("(广州") < 1000)
			{
				string str1__= strs2[i].substr(strs2[i].find("广州")+5, 4);
				if (str1__ == "文科")
				BOOL__[0][0] = 1;
				if (str1__ == "理科")
				BOOL__[0][1] = 1;
				if (str1__== "艺术")
				BOOL__[0][2] = 1;
			}
			if (strs2[i].find("(汕头") < 1000)
			{	
				string str2__ = strs2[i].substr(strs2[i].find("汕头") + 5, 4);
				if (str2__ == "文科")
				BOOL__[1][0] = 1;
				if (str2__ == "理科")
				BOOL__[1][1] = 1;
				if (str2__ == "艺术")
				BOOL__[1][2] = 1;
			}
			if (strs2[i].find("(珠海") < 1000)
			{
				string str3__ = strs2[i].substr(strs2[i].find("珠海") + 5, 4);
				if (str3__ == "文科")
					BOOL__[2][0] = 1;
				if (str3__ == "理科")
					BOOL__[2][1] = 1;
				if (str3__ == "艺术")
					BOOL__[2][2] = 1;;
			}
			if (strs2[i].find("(湛江") < 1000)
			{
				string str3__ = strs2[i].substr(strs2[i].find("湛江") + 5, 4);
				if (str3__ == "文科")
					BOOL__[3][0] = 1;
				if (str3__ == "理科")
					BOOL__[3][1] = 1;
				if (str3__ == "艺术")
					BOOL__[3][2] = 1;;
			}
			if (strs2[i].find("(深圳") < 1000)
			{
				{
					string str3__ = strs2[i].substr(strs2[i].find("深圳") + 5, 4);
					if (str3__ == "文科")
						BOOL__[4][0] = 1;
					if (str3__ == "理科")
						BOOL__[4][1] = 1;
					if (str3__ == "艺术")
						BOOL__[4][2] = 1;;
				}
			}
	}
	fstream file_six("F://scholar.txt",std::ios::out);	 //打开第一个文件
	for (size_t i = 0; i < 5; ++i)
	{
		
		for (size_t j = 0; j < 3; ++j)
		{
			//如果开关是开的
			if (BOOL__[i][j])
			{	
				file_six << (*data_three1[i][j].begin())._place  
					<< (*data_three1[i][j].begin())._type << " 状元:  " << endl;
				//按总分降序排序				
					sort(data_three1[i][j].begin(), data_three1[i][j].end(), greatersum);
				auto it = data_three1[i][j].begin();
				//把数据读进student.txt
					it->fdisplay(&file_six);
				//(汕头,文科)+(广州,理科)
			}
		}

	}
	string _str_one_1;
	string _str_two_1;
	fstream file_six_2("F://scholar.txt");
	while (!file_six_2.eof())
	{
		getline(file_six_2, _str_one_1, '\n');		// 从文件流中读入下一个字符

		_str_two_1 += _str_one_1 + "\r\n";
		CString cstr(_str_two_1.c_str());
		cstr=_str_two_1.c_str();
		m_value_six=cstr;
	}
	//关闭文件
	//cout << _str_two_1 << endl;
	
	file_six_2.close();
	   UpdateData(FALSE);   */
}
