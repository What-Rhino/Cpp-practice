#include<iostream>
using namespace std; 
class Cube
{
	public:
	//行为
	//设置长
	void setL(int l)
	{
		m_L=l;
	}
	//获取长
	int getL()
	{
		return m_L;
	}
	//设置宽
	void setW(int w)
	{
		m_W=w;
	}
	//获取宽
	int getW()
	{
		return m_W;
	}
	//设置高
	void setH(int h)
	{
		m_H=h;
	}
	//获取高 
	int getH()
	{
		return m_H;
	}
	//获取立方体表面积
	int calculateS()
	{
		return 2*(m_L*m_W+m_W*m_H+m_L*m_H); 
	}
	//获取立方体体积 
	int calculateV()
	{
		return (m_L*m_W*m_H);
	}
	//利用成员函数判断两个立方体是否相等 
	bool isSameByClass(Cube &c)//此时只需要传入一个未知的即可，在类内可以访问私有权限 
	{
		if(m_L==c.getL()&&m_W==c.getW()&&m_H==c.getH())
		{
			return true;
		}
		else
			return false;
	} 
	private:
		int m_L;
		int m_W;
		int m_H;	
};
//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1,Cube &c2)//用引用方式传入节省空间
{
	if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH())
	{
		return true;
	}
	else
	return false;
} 
int main()
{
	//实例化一个立方体对象 
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout<<"c1的面积为："<<c1.calculateS()<<endl;
	cout<<"c1的体积为："<<c1.calculateV()<<endl;
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);
	//利用全局函数判断 
	bool ret=isSame(c1,c2);
	if (ret)
	{
		cout<<"全局函数判断：c1和c2相等"<<endl;
	}
	else
	cout<<"全局函数判断：c1和c2不相等"<<endl;
	//利用成员函数判断 
	ret=c1.isSameByClass(c2);
	if (ret)
	{
		cout<<"成员函数判断：c1和c2相等"<<endl;
	}
	else
	cout<<"成员函数判断：c1和c2不相等"<<endl;
	system("pause");
	return 0;
} 
