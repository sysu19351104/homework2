#include<iostream>
#include<string>
using namespace std;
class identity
{
public:
	identity(int number = 0, const char* name = "ma") :number_(number)                               //构造函数
	{
		strcpy_s(name_, name);
		cout << "constuctor" << endl;
	}
	identity(identity& i)                                                                            //复制构造函数
	{
		number_ = i.number_;
		strcpy_s(name_, i.name_);
		cout << "copy constructor" << endl;
	}
	void getid()                                                                                     //存取函数                         
	{
		cout << "please input the number and name:" << endl;
		cin >> number_;
		cin >> name_;
	}
	long long int mynumber()
	{
		return number_;
	}
	char* myname()
	{
		return name_;
	}
	void showid()
	{
		cout << "the number and the name" << endl;
		cout << number_ << endl;
		cout << name_ << endl;
	}
	void setid(int number, char* name)
	{
		number_ = number;
		strcpy_s(name_, name);
	}
	~identity()                                                                                       //析构函数
	{
		cout << "disstructor" << endl;
	}
private:
	long long int number_;
	char name_[32];
};


class student
{
public:
	student(identity id, string school = "zhongda") :school_(school), id_(id)                                //构造函数
	{
		cout << "constructor" << endl;
	}
	student()                                                                                          //无参构造函数重载
	{
		school_ = "zhongda";
		cout << "constructor" << endl;
	}
	student(student& s)                                                                                 //复制构造函数
	{
		id_ = s.id_;
		school_ = s.school_;
		cout << "copy constructor" << endl;
	}
	void getdata();                                                                                    //存取函数
	string myschool()
	{
		return school_;
	}
	void showdata();
	void setstudent(identity id, string school)
	{
		id_ = id;
		school_ = school;
	}
	~student()
	{
		cout << "disstuctor" << endl;
	}
private:
	identity id_;
	std::string school_;
};

void student::getdata()                                                                             //存取函数的实现
{
	cout << "input your school:" << endl;
	cin >> school_;
	id_.getid();
}
void student::showdata()
{
	cout << "your data:" << endl;
	id_.showid();
	cout << "your school" << endl;
	cout << school_ << endl;
}
student Makestudent(int number,  char* name, std::string school)                            //Makestudent函数
{
	student s1;
	identity id1;
	id1.setid(number, name);
	s1.setstudent(id1, school);
	cout << "打印默认数据:" << endl;
	s1.showdata();
	return s1;
}
int main()                                                                                    //主函数
{
	student s1;
	identity id2;
	
	s1 = Makestudent(id2.mynumber(), id2.myname(), s1.myschool());
	s1.getdata();
	cout << "\n";
	s1.showdata();
	return 0;
}
