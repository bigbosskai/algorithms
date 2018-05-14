#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int map[10][10];
int trace[10][10];
typedef struct{
	int x,y;
}postype; 


typedef struct{
	int ord;		//��� 
	postype seat;	//λ������ 
	int di;			//���� 
}selem_type; 		//ջ�����Ԫ�� 

void init_map()
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i==0 || j==0 || i==9 || j==9)
			{
				map[i][j]=1;
			}
		}
	}
	map[1][3]=1;
	map[2][3]=1;
	map[1][7]=1;
	map[2][7]=1;
	map[3][5]=1;
	map[3][6]=1;
	map[4][2]=1;
	map[4][3]=1;
	map[4][4]=1;
	map[5][4]=1;
	
	map[6][2]=1;
	map[7][2]=1;	
	map[7][3]=1;
	map[7][4]=1;
	map[8][1]=1;
	map[6][6]=1;
	map[7][6]=1;
	map[7][7]=1;
}
void print_map()
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			cout<<trace[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool pass(postype pos)
{
	if(trace[pos.x][pos.y]==1 || trace[pos.x][pos.y]==2 )
	{
		return false;
	}
	else
	{
		return true;
	}
}
void foot_print(postype pos)
{
	trace[pos.x][pos.y]=1;
}
void make_print(postype pos)
{
	trace[pos.x][pos.y]=2;
} 
postype next_pos(postype curpos,int ord)
{
	switch(ord)
	{
		case 1://���� 
			curpos.y=curpos.y+1;
			return curpos;
			break;
		case 2://��
			curpos.x=curpos.x+1;
			return curpos;
			break;
		case 3:
			curpos.y=curpos.y-1;
			return curpos;
			break;
		case 4:
			curpos.x=curpos.x-1;
			return curpos;
			break; 
	}
	return curpos;
}
void print_seat(postype pos)
{
	cout<<"("<<pos.x<<","<<pos.y<<")"<<endl;
	return;
}
bool search(postype start,postype end)
{
	selem_type e;
	stack<selem_type> stk;
	memcpy(trace,map,sizeof(map));
	if(start.x<1 || start.y>8 || start.y<1 || start.x>8 )
	{
		return false;
	}
	if(end.x<1 || end.y>8 || end.x>8 || end.y>8)
	{
		return false;
	}
	//   1<=x,y<=8
	postype curpos=start;
	int curstep=1;
	do
	{
		if(pass(curpos))//��ǰλ�û�û���߹� 
		{
			foot_print(curpos); //�����㼣
			e.ord=curstep;
			e.di=1;
			e.seat=curpos;
			stk.push(e);
			//�ж��ǲ��ǳ���
			if(curpos.x==end.x && curpos.y==end.y)
			{
				cout<<"find maze path"<<endl;
				int a;
				cin>>a;
				while(!stk.empty())
				{
					e=stk.top();
					print_seat(e.seat);
					stk.pop();
				}
				return true;
			} 
			
			curpos=next_pos(curpos,e.di);
			curstep=curstep+1;
		}
		else//��ǰλ�ò���ͨ�� 
		{
			if(!stk.empty())
			{
				e=stk.top();
				stk.pop();//��ջ������һ��
				while(e.ord==4 && !stk.empty())//����Ƿ����Ѿ��������Ҿ�һֱ�� 
				{
					make_print(e.seat);//���²���ͨ���ı�� 
					e=stk.top();
					stk.pop();
				}
				if(e.di<4)
				{
					e.di++;//����һ������
					stk.push(e);
					curpos=next_pos(e.seat,e.di); 
				} 
			}

		}
	}while(!stk.empty());
	
	return false;
	
}
int main()
{
	init_map();
	postype start,end;
	start.x=start.y=1;
	end.x=end.y=8;
	search(start,end);
	return 0;
}
