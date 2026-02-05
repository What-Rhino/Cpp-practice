#include<iostream>
using namespace std;
class Base
{
	public:
		Base()
		{
			cout<<"Base构造函数!"<<endl;
		} 
		~Base()
		{
			cout<<"Base析构函数！"<<endl;
		}
};
class Son :Base
{
	public:
		Son()
		{
			cout<<"Son构造函数！"<<endl;
		}
		~Son()
		{
			cout<<"Son析构函数！"<<endl;
		}
};
void test01()
{
	//Base b;
	//继承中构造和析构的顺序如下：
	//先构造父类 再构造子类，析构的顺序与构造的顺相反 
	Son s;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
