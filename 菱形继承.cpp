#include<iostream>
using namespace std;
//菱形继承概念：两个派生类继承同一个基类，又有某个类同时继承两个派生类
//动物类
class Animal
{
	public:
		int m_Age;
}; 
//利用虚继承 解决菱形继承浪费内存的问题
//继承之前加上关键字 virtual变为虚继承
//Animal类称为虚基类 
//羊类
class  Sheep:virtual public Animal
{
	
};
//驼类 
class Tuo:virtual public Animal 
{
	
};
//羊驼类
class SheepTuo:public Sheep,public Tuo
{
	
}; 
void test01()
{
	SheepTuo st;
	//父类中出现重名 需要加作用域进行区分 
	st.Sheep::m_Age=18;
	st.Tuo::m_Age=28;
	//当菱形继承，两个父类拥有相同数据，需要加上作用域区分 
	cout<<"st.Sheep::m_Age= "<<st.Sheep::m_Age<<endl;
	cout<<"st.Tuo::m_Age= "<<st.Tuo::m_Age<<endl;
	//这份数据 我们只需要一份就可以了 菱形继承导致数据有两份 浪费内存 
	//用虚继承来解决 这样数据就只有一份了 
	cout<<"st.m_Age= "<<st.m_Age<<endl;
	//最后一次修改之后的值 就是该数据的值 
	cout<<"st.Sheep::m_Age= "<<st.Sheep::m_Age<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
