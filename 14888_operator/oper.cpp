//big의 mx가 0이면 안되었다. 음수값이 나올수도 있지 않는가?
//10억과 -10억의 리미트는 아무 의미 없다. 그냥 INT의 한계까지만 정해놓아도 괜찮을것이다
//big과 small을 하나로 합칠 수 있을것이다.
#include<iostream>
#include<limits.h>
#define file_cin
#define MIN_INIT 1000000000
#define MAX_INIT -1000000000
//#define debug
using namespace std;
enum {P,S,M,D};
int n;
int num[11];
int opercnt[4];
int oper[10];
void wipe(){
	for(int i=0;i<11;i++)
		num[i]=0;
	for(int i=0;i<4;i++)
		opercnt[i]=0;
	for(int i=0;i<10;i++)
		oper[i]=0;
}
void printoper(int tmp){
	for(int i=0;i<n-1;i++)
		cout<<oper[i]<<' ';
	cout<<tmp<<endl;
}
int calc(bool bs){
	int tmp=num[0];
	for(int i=0;i<n-1;i++)
		switch(oper[i]){
			case P:
				tmp+=num[i+1];
				break;
			case S:
				tmp-=num[i+1];
				break;
			case M:
				tmp*=num[i+1];
				break;
			case D:
				tmp/=num[i+1];
				break;
	}
#ifdef debug
	printoper(tmp);
#endif
	return tmp;
}
int big(int lv){
	int mx=MAX_INIT;
	if(lv==n-1){
		return calc(true);
	}
	int i=lv;
	if(opercnt[P]>0){
		opercnt[P]--;
		oper[i]=P;
		mx=max(mx,big(lv+1));
		opercnt[P]++;
	}
	if(opercnt[S]>0){
		opercnt[S]--;
		oper[i]=S;
		mx=max(mx,big(lv+1));
		opercnt[S]++;
	}
	if(opercnt[M]>0){
		opercnt[M]--;
		oper[i]=M;
		mx=max(mx,big(lv+1));
		opercnt[M]++;
	}
	if(opercnt[D]>0){
		opercnt[D]--;
		oper[i]=D;
		mx=max(mx,big(lv+1));
		opercnt[D]++;
	}
	return mx;
}
int small(int lv){
	int mx=MIN_INIT;
	if(lv==n-1){
		return calc(false);
	}
	int i=lv;
	if(opercnt[P]>0){
		opercnt[P]--;
		oper[i]=P;
		mx=min(mx,small(lv+1));
		opercnt[P]++;
	}
	if(opercnt[S]>0){
		opercnt[S]--;
		oper[i]=S;
		mx=min(mx,small(lv+1));
		opercnt[S]++;
	}
	if(opercnt[M]>0){
		opercnt[M]--;
		oper[i]=M;
		mx=min(mx,small(lv+1));
		opercnt[M]++;
	}
	if(opercnt[D]>0){
		opercnt[D]--;
		oper[i]=D;
		mx=min(mx,small(lv+1));
		opercnt[D]++;
	}
	return mx;
}
int main(){
#ifdef file_cin
	freopen("oper_in.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<4;i++)
			cin>>opercnt[i];
		cout<<big(0)<<endl;
		cout<<small(0)<<endl;
#ifdef file_cin
		wipe();
	}
#endif
	//cout<<-24/4<<endl;
	return 0;
}
