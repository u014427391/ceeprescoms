/*	
		项目实训第四部分使用说明:

		直接运行,两个txt文件(student.txt && data_student.txt )要放到F盘的根目录下
		为了分类用了2维类容器

		优点:
		通过判断学生_type属性来判断是多一科课程还是两科课程
		用容器的sort排序显得非常简练
		写得非常乱啊,叫我拿什么优点出来啊

		不足:
		乱到只有编辑器才看得懂
		提取字符串有效数据的方法很累赘
		控制台输出数据的方法很操蛋
		并没用实现类的封装,规则写进类里面要记住用静态类型
		没有实现模块化
		Student里面的_fp属性有点多余
		用容器数组存储分类的算法是不是可以优化?
		无任何页面操作
											by2014/6/30
*/

#include<iostream>
#include<string>
#include<fstream>    //文件操作头文件
#include<vector>     //容器头文件
#include <algorithm> //容器排序所用头文件
#include <functional>//容器排序所用头文件

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;
using std::sort;
using std::greater;          //容器排序的时候会用到
using std::less;             //容器排序的时候会用到
string BOOL_GRADE;
int BOOL_TYPE[3]{0, 0, 0};       //开关
int BOOL_PLACE[5]{0, 0, 0, 0, 0};//开关
int BOOL_S[4]{ 0, 0, 0, 0 };	 //开关
int BOOL_T[6]{ 0, 0, 0, 0, 0,0 };  //开关
 
void  System()
{
	cout << "输入查询语句格式如下:"<<endl
		<<"P(地区1...)+Q(类型1...)+S(考生信息)+T(考试信息)-P(地区)%T(按什么排序)" << endl;
}

class Student                 //学生类
{
public:
	Student  ();
	~Student  ();
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

};

/*----------------------排序规则------------------------------*/
//总分降序排序
bool   greatersum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum   >   s2._sum;
}
//英语成绩降序排序
bool   greaterEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English   >   s2._English;
}
//语文成绩降序排序
bool   greaterchinese(const   Student&   s1, const   Student&   s2)
{
	return   s1._chinese   >   s2._chinese;
}
//数学成绩降序排序
bool   greatermath(const   Student&   s1, const   Student&   s2)
{
	return   s1._math   >   s2._math;
}
//第一科降序排序
bool   greatercourse1(const   Student&   s1, const   Student&   s2)
{
	return   s1._course1   >   s2._course1;
}
//第二科降序排序
bool   greatercourse2(const   Student&   s1, const   Student&   s2)
{
	return   s1._course2   >   s2._course2;
}
/*-------------------------排序规则--------------------------*/
Student  ::Student  ()
{
	_fp = 0;                    //初始化文件指针
}

Student  ::~Student  ()
{	
}
int Student::finput(fstream *fp)              //具体化finput()      
{
	_fp = fp;
	(*_fp) >> _num >> _name                  //设定学号姓名
		   >>_sex>>_age                      //设定性别和年龄
		   >>_place>>_type                   //地点和考生类型
		   >> _wchar[0] >> _chinese >> _wchar[1] >> _math >> _wchar[2] >> _English;  //设定3科成绩
	if (_type == "文科")
	{
		(*_fp) >> _wchar[3] >> _course1 >> _wchar[4] >> _course2;     //设定历史和地理
	}
	else
	{
		(*_fp) >> _wchar[3] >> _course1;                 //设定物理或美术
	}
	if (_num==""||_name=="")                             //如果没有读到数据返回false
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
void Student::fdisplay(fstream *fp)                                        //具体化fdisplay
{
	(*fp) << _num << "	" << _name << "	"						            //文件输出学号姓名
		<< _sex << " " << _age << "	"										//文件输出性别和年龄
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;  //文件输出3科成绩
	if (_type == "文科")
	{
		(*fp) << _wchar[3] << _course1 << _wchar[4] << _course2 ;          //文件输出历史和地理
	}
	else
	{
		(*fp) << _wchar[3] << _course1;                                    //文件输出物理或美术
	}
	(*fp) << "总分 " << _sum << endl;                                     //文件输出总分
}
void Student::display()											                        //具体化display(调试的时候写的)
{	
	if (BOOL_S[0])
	{
		cout << _num << "	";
	}
	if (BOOL_S[1])
	{
		cout << _name << "	";
	}
	if (BOOL_S[2])
	{
		cout << _sex << "	";
	}
	if (BOOL_S[3])
	{
		cout << _age << "	";
	}
	if (BOOL_T[0])
	{
		cout << _wchar[0] << "	" << _chinese << "	";
	}
	if (BOOL_T[1])
	{
		cout << _wchar[1] << "	" << _math << "	";
	}
	if (BOOL_T[2])
	{
		cout << _wchar[2] << "	" << _English << "	";
	}
	if (BOOL_T[3])
	{
		cout << _wchar[3] << "	" << _course1 << "	";
	}
	if (BOOL_T[4]&&_type=="文科")
	{
		cout << _wchar[4] << "	" << _course2 << "	";
	}
	if (BOOL_T[5])
	{
		cout << "总分	" << _sum << "	";
	}
	cout<< endl;
}
/*       字符串处理 ,根据符号分类添加到容器                        */
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
int main()
{
	fstream file_one("F://data_student.txt");	 //打开第一个文件
	if (!file_one)						//如果打开失败
	{
		cout << "open error!" << endl;//显示出错信息
		abort();//程序退出
	}
	vector<Student>stu_data;					//定义一个空的stu_date容器,储存文件的全部信息
	do
	{
		Student stu;
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
	vector<Student>data_two[5];                //定义一个容器数组
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
	vector<Student>data_three[5][3];
	for (size_t i = 0; i < 5; ++i)
	{
		for (auto it = data_two[i].begin(); it != data_two[i].end(); ++it)
		{
			if (it->_type == "文科")
			{
				data_three[i][0].push_back(*it); // 添加到data_two[i][0]
			}
			else if (it->_type == "理科")
			{
				data_three[i][1].push_back(*it);//添加到data_two[i][1]
			}
			else if (it->_type == "艺术")
			{
				data_three[i][2].push_back(*it); //添加到data_two[i][2]
			}
		}
	}
	System();
	//string str="P(汕头)+Q(艺术,文科,理科)+S(学号,姓名,性别)+T(总分)-Q()-P()-S(学号)%T(总分)";
	string str;
	cin >> str;
	if (str.find("%T(")<1000){
    BOOL_GRADE = str.substr(str.find("%T") + 3, 4);
	str = str.substr(0, str.find("%T"));
	}
	else
	{
		cout << "请输入正确语法" << endl;
	}
	vector<string> strs1 = splitEx(str, "-");
	vector<string> strs2 = splitEx(strs1[0], "+");
	//删除掉"-"号前的字符串
	strs1.erase(strs1.begin());
	//+的情况
	for (unsigned int i = 0; i < strs2.size(); i++)
	{
		if ( strs2[i].find("P") < 1000)
		{
			int is_ture = 1;
			if ( strs2[i].find("广州") < 1000)
			{
				BOOL_PLACE[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("汕头") < 1000)
			{
				BOOL_PLACE[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("珠海") < 1000)
			{
				BOOL_PLACE[2] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("湛江") < 1000)
			{
				BOOL_PLACE[3] = 1;
				is_ture = 0;
				
			}
			if ( strs2[i].find("深圳") < 1000)
			{
				BOOL_PLACE[4] = 1;
				is_ture = 0;
			}
			//如果里面没有任何信息
			if (is_ture)
			{
				BOOL_PLACE[0] = 1;
				BOOL_PLACE[1] = 1;
				BOOL_PLACE[2] = 1;
				BOOL_PLACE[3] = 1;
				BOOL_PLACE[4] = 1;
			}

		}
		else if ( strs2[i].find("Q") < 1000)
		{	
			int is_ture = 1;
			if ( strs2[i].find("文科") < 1000)
			{
				BOOL_TYPE[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("理科") < 1000)
			{
				BOOL_TYPE[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("艺术") < 1000)
			{
				BOOL_TYPE[2] = 1;
				is_ture = 0;
			}
			//如果里面没有任何信息
			if (is_ture)
			{
				BOOL_TYPE[0] = 1;
				BOOL_TYPE[1] = 1;
				BOOL_TYPE[2] = 1;
			}
		}
		else if ( strs2[i].find("S") < 1000)
		{
			int is_ture = 1;
			if ( strs2[i].find("学号") < 1000)
			{
				BOOL_S[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("姓名") < 1000)
			{
				BOOL_S[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("性别") < 1000)
			{
				BOOL_S[2] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("年龄") < 1000)
			{
				BOOL_S[3] = 1;
				is_ture = 0;
			}
			//如果里面没有任何信息
			if (is_ture)
			{
				BOOL_S[0] = 1;
				BOOL_S[1] = 1;
				BOOL_S[2] = 1;
				BOOL_S[3] = 1;
			}
		}
		else if ( strs2[i].find("T") < 1000)
		{	
			int is_ture = 1;
			if ( strs2[i].find("语文") < 1000)
			{
				BOOL_T[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("数学") < 1000)
			{
				BOOL_T[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("英语") < 1000)
			{
				BOOL_T[2] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("美术") < 1000 || 
				strs2[i].find("历史") < 1000 || 
				strs2[i].find("物理") < 1000  )
			{
				BOOL_T[3] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("地理") < 1000)
			{
				BOOL_T[4] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("总分") < 1000)
			{
				BOOL_T[5] = 1;
				is_ture = 0;
			}
			//如果里面没有任何信息
			if (is_ture)
			{
				BOOL_T[0] = 1;
				BOOL_T[1] = 1;
				BOOL_T[2] = 1;
				BOOL_T[3] = 1;
				BOOL_T[4] = 1;
				BOOL_T[5] = 1;
			}
		}
	}

	//-的情况
	for (unsigned int i = 0; i < strs1.size(); i++)
	{
		if (strs1[i].find("P") < 1000)
		{	
			if (strs1[i].find("广州") < 1000)
			{
				BOOL_PLACE[0] = 0;
			}
			if (strs1[i].find("汕头") < 1000)
			{
				BOOL_PLACE[1] = 0;
			}
			if (strs1[i].find("珠海") < 1000)
			{
				BOOL_PLACE[2] = 0;
			}
			if (strs1[i].find("湛江") < 1000)
			{
				BOOL_PLACE[3] = 0;
			}
			if (strs1[i].find("深圳") < 1000)
			{
				BOOL_PLACE[4] = 0;
			}
			//如果里面没有任何信息
			if (!(BOOL_PLACE[0] || BOOL_PLACE[1] || BOOL_PLACE[2] || BOOL_PLACE[3] || BOOL_PLACE[4]))
			{
				BOOL_PLACE[0] = 0;
				BOOL_PLACE[1] = 0;
				BOOL_PLACE[2] = 0;
				BOOL_PLACE[3] = 0;
				BOOL_PLACE[4] = 0;
			}

		}
		else if (strs1[i].find("Q") < 1000)
		{
			if (strs1[i].find("文科") < 1000)
			{
				BOOL_TYPE[0] = 0;
			}
			if (strs1[i].find("理科") < 1000)
			{
				BOOL_TYPE[1] = 0;
			}
			if (strs1[i].find("艺术") < 1000)
			{
				BOOL_TYPE[2] = 0;
			}
			//如果里面没有任何信息
			if (!(BOOL_TYPE[0] || BOOL_TYPE[1] || BOOL_TYPE[2]))
			{
				BOOL_TYPE[0] = 0;
				BOOL_TYPE[1] = 0;
				BOOL_TYPE[2] = 0;
			}
		}
		else if (strs1[i].find("S") < 1000)
		{
			int is_ture = 1;
			if (strs1[i].find("学号") < 1000)
			{
				BOOL_S[0] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("姓名") < 1000)
			{
				BOOL_S[1] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("性别") < 1000)
			{
				BOOL_S[2] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("年龄") < 1000)
			{
				BOOL_S[3] = 0;
				is_ture = 0;
			}
			if (is_ture)
			{
				BOOL_S[0] = 0;
				BOOL_S[1] = 0;
				BOOL_S[2] = 0;
				BOOL_S[3] = 0;
			}
			
		}
		else if (strs1[i].find("T") < 1000)
		{
			int is_ture = 1;
			if (strs1[i].find("语文") < 1000)
			{
				BOOL_T[0] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("数学") < 1000)
			{
				BOOL_T[1] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("英语") < 1000)
			{
				BOOL_T[2] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("美术") < 1000 ||
				strs1[i].find("历史") < 1000 ||
				strs1[i].find("物理") < 1000)
			{
				BOOL_T[3] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("地理") < 1000)
			{
				BOOL_T[4] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("总分") < 1000)
			{
				BOOL_T[5] = 0;
				is_ture = 0;
			}
			if (is_ture)
			{
				BOOL_T[0] = 0;
				BOOL_T[1] = 0;
				BOOL_T[2] = 0;
				BOOL_T[3] = 0;
				BOOL_T[4] = 0;
				BOOL_T[5] = 0;
			}
			
		}
	}
	for (size_t i = 0; i < 5; ++i)
	{	
		//如果开关是开的
		if (BOOL_PLACE[i])
		{
			cout << (*data_two[i].begin())._place << endl << endl;
		}
		else
		{
			continue;
		}
		for (size_t j = 0; j < 3; ++j)
		{	
			//如果开关是开的
			if (BOOL_TYPE[j])
			{
				cout << (*data_three[i][j].begin())._type << " : " << endl;
				//按总分降序排序
				if (BOOL_GRADE == "总分")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatersum);
				}
				else if (BOOL_GRADE == "英语")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greaterEnglish);
				}
				else if (BOOL_GRADE == "数学")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatermath);
				}
				else if (BOOL_GRADE == "语文")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greaterchinese);
				}
				else if (BOOL_GRADE == "物理" || BOOL_GRADE == "历史" || BOOL_GRADE == "美术")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatercourse1);
				}
				else if (BOOL_GRADE == "地理")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatercourse2);
				}
				else
				{
					cout << "请输入正确语法" << endl;
					break;
				}				
				for (auto it = data_three[i][j].begin(); it != data_three[i][j].end(); ++it)
				{

					//把数据读进student.txt
					it->display();
				}
			}			
		}

	}

}