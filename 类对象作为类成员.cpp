#include<iostream>
using namespace std;
class Phone
{
	public:
		Phone(string PName)
		{
			cout<<"Phone的构造函数调用"<<endl;
			m_PName=PName;
		}
		~Phone()
		{
			cout<<"Phone的析构函数调用"<<endl; 
		}
		string m_PName;
};
class Person
{
	public: 
		Person(string name,string pName):m_Name(name),m_Phone(pName)//相当于Phone m_Phone=pName即隐式转换法 
		 {
		 	cout<<"Person的构造函数调用"<<endl;
		 }
		~Person()
		{
			cout<<"Person的析构函数调用"<<endl;
		} 
		string m_Name;
		Phone m_Phone;
};
//当其他类的对象作为本类的成员，先构造其他类对象，再构造自身 
//析构时，与构造相反 
void test01()
{
	Person p("张三","苹果MAX");
	cout<< p.m_Name<<"拿着："<<p.m_Phone.m_PName<<endl;
} 
int main()
{
	test01();
	system("pause");
	return 0;
}
