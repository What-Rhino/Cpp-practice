#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;
class Message
{
	private:
		char *body;//消息正文 
		char from[20];//发送者 
		char to[20];//接受者
	public:
		Message(const char * b=NULL,const char *f=NULL,const char *t=NULL)
		{
			if(b!=NULL)
			{
				body=new char(strlen(b)+1);
				strcpy(body,b);
			}
			else body=NULL;
			if(f!=NULL)
			{
				strcpy(from,f);
			}
			else from[0]='\0';
			if(t!=NULL)
			{
				strcpy(to,t);
			}
			else to[0]='\0';
		}
		Message(const Message & m)
		{
			body=NULL;
			if(m.body!=NULL)
			{
				body=new char(strlen(m.body)+1);
				strcpy(body,m.body);
			}
			if(m.from!='\0')
			{
				strcpy(from,m.from);
			}
			if(m.to!='\0')
			{
				strcpy(to,m.to);
			}
			
		}
		~Message()
		{
			delete [] body;
		} 
		int send()
		{
			
			if(body!=NULL&&body[0]!='\0'&&from[0]!='\0'&&to[0]!='\0')
			{
				cout<<from<<" "<<"发送给 "<<to<<":"<<body <<endl;
				return 1;
			}
			else 
			{
				return 0;
			}
		}
};
int main()
{
	Message ms1("hello","zhangsan","lisi");
	if(ms1.send())
	{
		cout<<"发送成功"<<endl;
	}
	Message ms2("hello");
	if(ms2.send())
	{
		cout<<"发送成功"<<endl;
	}
	else
	{
		cout<<"发送失败"<<endl;
	}
	Message ms3=ms1;
	if(ms3.send())
	{
		cout<<"发送成功"<<endl;
	}
	else
	{
		cout<<"发送失败"<<endl;
	}
	return 0;
}
