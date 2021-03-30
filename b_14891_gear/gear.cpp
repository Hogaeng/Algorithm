#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
enum {N,S};
enum {CC=-1,C=1};
bitset<32> prestates[4];
int states[4][8];
int wises[100][2];
int wn;
int maskint = pow(2,7);
bitset<32> mask(maskint);
int inter[3][2][2]={
										{{0,2},{1,6}},
										{{1,2},{2,6}},
										{{2,2},{3,6}}
};
int result(){
	int ret=0;
	for(int i=0;i<4;i++){
		if(states[i][0]==1)
			ret+=pow(2,i);
	}
	return ret;
}
void printgear(int ind)
{
	for(int i=0;i<8;i++){
		cout<<states[ind][i];
	}
	cout<<endl;
}
void rot(int ind, int wise){
	int tmp;
	if(wise == C){
		tmp = states[ind][7];;
		for(int i = 7;i>0;i--){
			states[ind][i]=states[ind][i-1];
		}
		states[ind][0]=tmp;
	}
	else{
		tmp = states[ind][0];
		for(int i=0;i<7;i++){
			states[ind][i]=states[ind][i+1];
		}
		states[ind][7]=tmp;
	}
}
bool check(int interind){
	int r;
	int c;
	int num[2]
	for(int i=0;i<2;i++){
		r=inter[interind][i][0];
		c=inter[interind][i][1];
		num[i]=states[r][c];
	}
	if(num[0] != num[1])
		return true;
	return false;
}
void simulate(int ind, int wise){
	rot(ind,wise);
	for(int i=0;i<3;i++){
		if(check(i))
			
	}
}
void startinter(int ind, int wise){
}
int main(){
	freopen("gear_input1.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		for(int i=0;i<4;i++){
			cin>>prestates[i];
			for(int j=0;j<8;j++){
				if((prestates[i] & mask)==mask)
					states[i][j]=1;
				else
					states[i][j]=0;
				prestates[i]=prestates[i]<<1;
			}
		}
		cin>>wn;
		for(int i=0;i<wn;i++){
			for(int j=0;j<2;j++){
				cin>>wises[i][j];
			}
		}
		//printgear(1);
	}
	return 0;
}
