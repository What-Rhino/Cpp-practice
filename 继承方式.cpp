#include<iostream>
using namespace std;
//继承方式有三种
//1、公共继承
class Base1
{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
};
class Son1:public Base1
{
	public:
		void func()
		{
			m_A=10;//父类中的公共权限成员，到子类中依然是公共权限 
			m_B=10;//父类中的保护权限成员，到子类中依然是保护权限 
			//m_C=10;//父类中的私有成员 子类无法访问 
		}
}; 
void test01()
{
	Son1 s1;
	s1.m_A=100;
	//s1.m_B=100;//到了Son1中 m_B是保护权限 保护权限内容在类外不可以访问 
}
//2、保护继承 
class Base2
{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
};
class Son2:protected Base2
{
	public:
		void func()
		{
			m_A=10;//父类中的公共成员到子类中变为保护权限 
			m_B=10;//父类中的保护成员到子类中依然为保护成员 
			//m_C=10;父类中的私有成员访问不到 
		}
};
void test02()
{
	Son2 s1;
	//s1.m_A=1000;//在Son2中m_A变为保护权限 因此类外访问不到 
	//s1.m_B=100;//在Son2中 m_B是保护权限 不可以访问 
}
//3、私有继承 
class Base3
{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;	
};
class Son3:private Base3
{
	public:
		void func()
		{
			m_A=100;//父类中公有的成员 到子类中变为私有 
			m_B=100;//父类中保护的成员 到子类中变为私有 
			//m_C=100;//父类中私有的成员 子类仍然访问不到 
		}
};
void test03()
{
	Son3 s1;
	//s1.m_A=1000;//在Son3中m_A变为私有权限 因此类外访问不到 
	//s1.m_B=100;//在Son3中 m_B变为私有权限 不可以访问 
}
class GrandSon3:public Son3
{
	public:
		void func()
		{
			//在Son3中 属性就已经都是私有了 即使是 GrandSon3也不可访问 
			//m_A=1000;
			//m_B=1000;
			//m_C=1000;
		}
};
int main()
{
	test01;
	test02;
	test03;
	system("pause");
	return 0;
}
