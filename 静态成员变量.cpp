#include<iostream>
using namespace std;
//静态成员变量
//1、所有的对象共享同一份数据
//2、在编译阶段就已经分配在内存的全局区，不是在创建对象时
//3、必须在类内声明,在类外初始化
class Person
{
	public:
		static int m_A;
		//静态成员变量也有访问权限
	private:
		static int m_B; 
};
//在类外初始化 
int Person ::m_A=100;
int Person ::m_B=200; 
void test01()
{
	Person p;
	cout<<p.m_A<<endl;
	Person p2;
	p2.m_A=200;
	cout<<p.m_A<<endl;
}
void test02()
{
	//静态成员变量 不属于某个对象上，所有对象都共享一份数据
	//因此静态成员有两种访问方式
	//1、通过对象访问
	Person p; 
	cout<<p.m_A<<endl;
	//2、通过类名进行访问
	cout<<Person::m_A<<endl;
	//cout<<Person::m_B<<endl; 私有权限类外访问不到静态成员变量,类内可以访问 
}
int main()
{
	test01();
	test02(); 
	system("pause");
	return 0;
}
