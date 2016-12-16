/*	
		项目实训第三部分使用说明:

		直接运行,两个txt文件(student.txt && data.txt )要放到F盘的根目录下

		优点:
		通过判断学生_type属性来判断是多一科课程还是两科课程
		用器的sort排序显得非常简练

		不足:
		并没用实现类的封装,规则写进类里面要记住用静态类型
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
	unsigned  int _course1;     //课程一
	unsigned  int _course2;     //课程二
	unsigned int _sum;          //总成绩
	unsigned int _list_num;     //序号	
	fstream *_fp;               //文件指针

};
/*----------------------排序规则------------------------------*/
//英语成绩升序排序
static bool   lessEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English <   s2._English;
}
//英语成绩降序排序
static bool   greaterEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English   >   s2._English;
}
//总分升序排序
static bool   lesssum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum <   s2._sum;
}
//总分降序排序
static bool   greatersum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum   >   s2._sum;
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
	cout << _num <<"	"<< _name<<"	"												//控制台输出学号姓名
		<< _sex <<" "<< _age<<"	"														//控制台输出性别和年龄
		<< _place <<"	"<< _type<<" "													//控制台输出地点和考生类型
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;        //控制台输3科成绩
	if (_type == "文科")
	{
		cout << _wchar[3] << _course1 << _wchar[4] << _course2;							//控制台输历史和地理
	}
	else
	{
		cout << _wchar[3] << _course1 ;													//控制台输历史和地理
	}
	cout << "总分 " << _sum << endl;
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
	vector<Student>data_two[5];                //定义个个容器数组
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
			if (it->_type=="文科")       
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
	//打开要储存分类好的文件
	fstream file_two("F://student.txt");
	if (!file_two)//如果打开失败
	{
		cout << "open error!" << endl;//显示出错信息
		abort();//程序退出
	}
	for (size_t i = 0; i < 5; ++i)
	{
		file_two<<(*data_two[i].begin())._place<<endl<<endl;
		for (size_t j = 0; j < 3; ++j)
		{
			file_two << (*data_three[i][j].begin())._type << " : " << endl;
			//按总分降序排序
			sort(data_three[i][j].begin(), data_three[i][j].end(), greatersum);
			for (auto it = data_three[i][j].begin(); it != data_three[i][j].end(); ++it)
			{   
				//把数据读进student.txt
				it->fdisplay(&file_two);
			}
		}

	}
	//关闭文件
	file_two.close();
}