#include<iostream>
using namespace std;
//建筑类 
class Building
{
	//表示goodGay全局函数是Building的好朋友，可以访问Building中的私有成员 
	friend void goodGay(Building*building); 
	public:
		Building()
		{
			m_SittingRoom="客厅";
			m_BedRoom="卧室"; 
		 }
	public:
		string m_SittingRoom;//客厅
	private:
		string m_BedRoom;//卧室
		 
};
//全局函数
void goodGay(Building*building)
{
	cout<<"好基友全局函数正在访问："<<building->m_SittingRoom<<endl;//传入的是building的指针，用->访问属性 
	cout<<"好基友全局函数正在访问："<<building->m_BedRoom<<endl;//因为m_BedRoom是私有成员，所以需要使用友元写法 
} 
void test01()
{
	Building building;
	goodGay(&building);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
