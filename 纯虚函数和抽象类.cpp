#include<iostream>
using namespace std;
//纯虚函数语法： virtual 返回值类型 函数名 （参数列表）=0；
//当类中有了纯虚函数，这个类叫做抽象类
//抽象类特点：
//1、无法实例化对象
//2、子类必须重写抽象类中的纯虚函数，否则子类也属于抽象类 
class Base
{
	public:
		virtual void func()=0;//纯虚函数
		 
};
class Son:public Base
{
	public:
		virtual void func()
		{
			cout<<"func调用"<<endl;
		}//子类需要重写父类中的虚函数，否则也是抽象类，无法实例化对象  
		
};
void test01()
{
	//Base b;  抽象类不能实例化对象
	//new Base; 抽象类不能实例化对象
	Son s1;//子类重写虚函数后 可以实例化
	Base *base=new Son;
	base->func(); 
	delete base;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
