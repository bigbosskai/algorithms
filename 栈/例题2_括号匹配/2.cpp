#include<iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;

bool matching(char *str)
{
	stack<char> stk;
	int i=0;
	bool state=true;
	int length=strlen(str);
	while(i<length && state)
	{
		switch(str[i])
		{
			case '(':
				stk.push(str[i]);
				break;
			case '[':
				stk.push(str[i]);
				break;
			case '{':
				stk.push(str[i]);
				break;
			case ')':
				if(!stk.empty() && stk.top()=='(' )
				{
					stk.pop();
				}
				else
				{
					state=false;	
				}
				break;
			case '}':
				if(!stk.empty() && stk.top()=='{' )
				{
					stk.pop();
				}
				else
				{
					state=false;	
				}
				break;				
			case ']':
				if(!stk.empty() && stk.top()=='[' )
				{
					stk.pop();
				}
				else
				{
					state=false;	
				}
				break;
		}
		i++;
	}
	if(stk.empty() && state==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char s[]="[(1+2) [*] {3+4}]";
	cout<<matching(s);
	return 0;
}



