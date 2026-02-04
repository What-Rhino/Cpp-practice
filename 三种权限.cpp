#include<iostream>
using namespace std;
//公共权限 public 成员 类内可以访问,类外可以访问 
//保护权限 protected 成员 类内可以访问，类外不可以访问
//私有权限private 成员 类内可以访问，类外不可以访问 
class Person 
{
	public:
		string m_Name;
	protected:
		string m_Car;
	private:
		int m_Password;
	public:
		//类内访问均正确 
		void func()
		{
			m_Name="张三";
			m_Car="拖拉机";
			m_Password=123456; 
		}
};
int main()
{
	//实例化
	Person p1;
	p1.m_Name ="李四";
	//p1.m_Car="奔驰";//保护权限类外无法访问
	//p1.m_Password=45678;//私有权限类外无法访问 
	cout<<"姓名："<<p1.m_Name<<endl; 
	system("pause");
	return 0;
}

