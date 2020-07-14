#define R 31
#define C 11
#include<iostream>
//#define debug
//틀린이유:출력해야하는 가로선의 최솟값을 출력해야한다.
//하나의 문제에 답이 여러개 있을 수 있다.
//여러개 있을 수 있는 답은 가장 적게 사다리를 놓을 수 있는 답을 출력해야한다.
using namespace std;
int n,m,h;
int cnt_EndCond;
void printbar(int bar[R][C]){
	cout<<'\n';
	for(int i=1;i<=h;i++){
		for(int j=1;j<n;j++)
			cout<<bar[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}
bool lets(int bar[R][C],int ver){
	int state=ver;
	for(int i=1;i<=h;i++){
		if(bar[i][state])
			state++;
		else if(bar[i][state-1])
			state--;
	}
	if(state==ver)
		return true;
	else
		return false;
}
bool letss(int bar[R][C]){
	bool ret=true;
	for(int i=1;i<=n;i++)
		if(!lets(bar,i)){
			ret=false;
			break;
		}
	return ret;
}
int recursiv(int bar[R][C],int cnt,int lvr){
	if(cnt==0)
		if(letss(bar))
			return cnt;
		else
			return -1;
	else{
		int ret=0;
		for(int i=lvr;i<=h;i++)
			for(int j=1;j<n;j++){
				if(bar[i][j-1]==0&&bar[i][j+1]==0&&bar[i][j]==0){
					bar[i][j]=1;
#ifdef debug
					cout<<i<<' '<<j<<' '<<cnt;
					printbar(bar);
#endif
					if(recursiv(bar,cnt-1,i)!=-1)
						return cnt;
					bar[i][j]=0;
#ifdef debug
					cout<<i<<' '<<j<<' '<<cnt;
					printbar(bar);
#endif
				}
			}
		return -1;
	}
}
int main(){
	//freopen("ladder_in9.txt","r",stdin);
#ifdef debug
	freopen("ladder_out9.txt","w",stdout);
#endif
	//int tmp;
	//cin>>tmp;
	//for(int z=0;z<tmp;z++){
		int bar[R][C] = {0,};
		cin>>n;
		cin>>m;
		cin>>h;
		for(int i=0;i<m;i++){
			int tmpr,tmpc;
			cin>>tmpr;
			cin>>tmpc;
			bar[tmpr][tmpc]=1;
		}
#ifdef debug
		printbar(bar);
#endif
		int ret=-1;
		int i;
		for(i=0;i<4;i++)
			if((ret=recursiv(bar,i,1))!=-1){
				cout<<ret<<'\n';
				break;
			}
		if(i==4)
			cout<<-1<<'\n';
	//}
	return 0;
}
