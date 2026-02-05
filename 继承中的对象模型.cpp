#include<iostream>
using namespace std; 
class Base
{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;
}; 
class Son:public Base
{
	public:
		int m_D;
}; 
void test01()
{
	//父类中所有的非静态成员属性都会被子类继承下去
	//父类中的私有属性 是被编译器隐藏了 因此访问不到 但是确实被继承下去了 
	cout<<"size of son= "<<sizeof(Son)<<endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
