#include<iostream>
#include<stack> 
#include<cstring>
using namespace std;
int table[1000][1000];
void inittable()
{
	    //cur  top
	table['+']['+']=-1;
	table['+']['-']=-1;
	table['+']['*']=-1;
	table['+']['/']=-1;
	table['+']['(']=1;
	//table['+'][')']=-1; error
	table['+']['#']=1;
	
	table['-']['+']=-1;
	table['-']['-']=-1;
	table['-']['*']=-1;
	table['-']['/']=-1;
	table['-']['(']=1;
	//table['-'][')']=-1; error
	table['-']['#']=1;
	
	table['*']['+']=1;
	table['*']['-']=1;
	table['*']['*']=-1;
	table['*']['/']=-1;
	table['*']['(']=1;
	//table['*'][')']=1; error
	table['*']['#']=1;
	
	table['/']['+']=1;
	table['/']['-']=1;
	table['/']['*']=-1;
	table['/']['/']=-1;
	table['/']['(']=1;
	//table['/'][')']=1; error
	table['/']['#']=1;
	
	table['(']['+']=1;
	table['(']['-']=1;
	table['(']['*']=1;
	table['(']['/']=1;
	table['(']['(']=1;
	//table['('][')']=-1; error
	table['(']['#']=1;
	
	table[')']['+']=-1;
	table[')']['-']=-1;
	table[')']['*']=-1;
	table[')']['/']=-1;
	table[')']['(']=-1;//特殊处理
	//table[')'][')']=-1;  error
	table[')']['#']=1;
	
	table['#']['+']=-1;
	table['#']['-']=-1;
	table['#']['*']=-1;
	table['#']['/']=-1;
	table['#']['(']=-1;
	table['#'][')']=-1;
	table['#']['#']=-1;//结束 	 
}
int look_up(char op1,char op2)
{
	return table[op1][op2];
}
bool is_oper(char op)
{
	if(op=='+' || op=='-' || op=='*' || op=='/' || op=='(' || op==')' || op=='#')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_num(char num)
{
	if(num=='0' || num=='1' || num=='2' || num=='3' || num=='4' || num=='5' || num=='6' || num=='7' || num=='7' || num=='9')
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
	inittable();
	stack<char> stk;
	char lastexp[100]={0};
	int index=0;
	char exp[]="2*3+(5-4/2)*6#";
	stk.push('#');
	int length=strlen(exp);	
	for(int i=0; i<length; i++)
	{
		
		if(is_num(exp[i]))
		{
			lastexp[index++]=exp[i];
		} 
		else if(is_oper(exp[i]))
		{
			if(look_up(exp[i],stk.top())==1)
			{
				stk.push(exp[i]);
			}
			else
			{
				if(exp[i]==')' && stk.top()=='(')
				{
					stk.pop();//弹出( 
				}
				else if(exp[i]=='#' && stk.top()=='#')
				{
					break;//结束 
				}
				else
				{
					lastexp[index++]=stk.top();
					stk.pop();
					i=i-1; //不能动 
				}
				
				
			}
			
		}
	}
	
	cout<<lastexp<<endl; 
	return 0;
}
