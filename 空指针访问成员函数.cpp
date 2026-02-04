#include<iostream> 
using namespace std;
class Person
{
	public:
		void showClassName()
		{
			cout<<"this is Person class"<<endl;
		}
		void showPersonAge()
		{
			if(this==NULL) 
			{
				return; 
			}
			cout<<"age= "<<m_Age<<endl;//编译器会补成this->m_Age 
		}
		int m_Age;//非静态成员变量，在实例化之前是不会创建的，其他的成员在创建对象时就已经创建好了 
}; 
void test01()
{
	Person *p=NULL;
	p->showClassName();
	p->showPersonAge();	//若传入指针为空，则无法访问其属性 
}
int main()
{
	test01();
	system("pause");
	return 0;
}
