#include<iostream>
#include<stack>
#include<cstring>
#include<cstdlib>
using namespace std;

void line_edit()
{
	stack<char> stk;
	char ch;
	cin>>ch
	while(ch!=EOF && ch!='\r')
	{
		switch(ch)
		{
			case '#':
				stk.pop();
				break;
			case '@':
				clearstack();
				break;
			default:
				stk.push(ch);
				break;
		}
		clearstack();
		if(ch!=EOF)
		{
			cin>>ch;
		}
		cout<ch;
	}
}
int main()
{
	line_edit();
	return 0;
}
