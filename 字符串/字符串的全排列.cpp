#include<iostream> 
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void p(char *s,int from,int to){
	if(from==to){
		cout<<s<<endl;
		return;
	}
	for(int i=from; i<=to; i++){
		swap(s[from],s[i]);//�ò�ͬ�������ַ� 
		p(s,from+1,to);
		swap(s[from],s[i]);
	}
}

//������ظ���ȫ���� 
bool check(char *s,int from,int to){
	bool res=true;
	for(int i=from; i<to; i++){
		if(s[i]==s[to]){
			res=false;
			break;
		}
	}
	return res;
} 
int count=0;
void pup(char *s,int from,int to){
	if(from==to){
		count++;
		cout<<count<<": "<<s<<endl;
	}
	for(int i=from; i<=to; i++){
		//�ڽ���֮ǰҪ�ж�from��i-1�е��ַ��ǲ����к�s[i]���
		//������ܽ��� 
		if(!check(s,from,i)){//������ܽ�����continue 
			continue;
		}
		swap(s[from],s[i]);
		pup(s,from+1,to);
		swap(s[from],s[i]);
	}
}


//���￼�������ص�hash  ��hash������ȽϺ� 
void pupup(char *s,int from,int to){
	if(from==to){
		count++;
		cout<<count<<": "<<s<<endl;
	}
	int mark[256]={0};//�����и�˼��Ϊʲômark������ȫ�ֱ��� 
	for(int j=0; j<256; j++){
		mark[j]=0;
	}
	for(int i=from; i<=to; i++){
		//�ڽ���֮ǰҪ�ж�from��i-1�е��ַ��ǲ����к�s[i]���
		//������ܽ���  
		if(mark[s[i]]==1){
			continue;
		}
		mark[s[i]]=1;
		if(!check(s,from,i)){//������ܽ�����continue 
			continue;
		}
		swap(s[from],s[i]);
		pupup(s,from+1,to);
		swap(s[from],s[i]);
	}
}



 
int main(){
	char s1[]="1223";
	pupup(s1,0,3);
	return 0;
}
