#include<iostream>
using namespace std;
//赋值运算符重载
class Person
{
	public:
		Person(int age)
		{
			m_Age=new int (age);
		}
		~Person()
		{
			if(m_Age!=NULL)
			{
				delete m_Age;
				m_Age=NULL;
			}
		}
		//重载赋值运算符=
		Person& operator=(Person &p)//返回引用，防止创建新对象 
		{
			//编译器提供的浅拷贝:m_Age=p.m_Age
			//应该先判断调用函数的对象，是否有属性在堆区，如果有应该先释放干净，再赋值
			if(m_Age!=NULL)
			{
				delete m_Age;
				m_Age=NULL;
			} 
			m_Age=new int (*p.m_Age);
			//返回自身，才可以实现连续赋值 
			return *this; 
		} 
		int *m_Age;	
};
void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3=p2=p1;//连续赋值操作 
	cout<<"p1的年龄为："<<*p1.m_Age<<endl; 
	cout<<"p2的年龄为："<<*p2.m_Age<<endl; 
	cout<<"p3的年龄为："<<*p3.m_Age<<endl; 
}
int main()
{
	test01(); 
	system("pause");
	return 0;
}
