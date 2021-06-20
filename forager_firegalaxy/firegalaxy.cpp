#include<iostream>
#include<ctime>
#include<bitset>
#include<cmath>
#define debug
#define FILENAME "forager_firegalaxy/firegalaxy_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
int n=6;
clock_t start;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void simul(int rn,bool boardb[6][6]){
	bool b[6][6];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[i][j]=boardb[i][j];

	bitset<6> bitrn=rn;
	bool inputb[6][6]={0,};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==0){
				inputb[i][j]=bitrn[j];
			}
			else{
				if(b[i-1][j])
					inputb[i][j]=true;
			}
			if(inputb[i][j]){
				b[i][j]=!b[i][j];
				for(int k=0;k<4;k++){
					int dx=i+dir[k][0], dy=j+dir[k][1];
					if(dx>-1&&dx<n&&dy>-1&&dy<n){
						b[dx][dy]=!b[dx][dy];
					}
				}
			}
		}
	}
	bool iszero=true;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(b[i][j]==true){
				iszero=false;
				break;
			}
	if(iszero)
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<inputb[i][j]<<' ';
			cout<<endl;
		}
	//cout<<endl;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
        bool boardb[6][6]={0,};
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>boardb[i][j];
		int rn=pow(2,n);
		int answer=0;
		for(int i=0;i<rn;i++){
			simul(i,boardb);
		}
#ifdef FILE_CIN
	}
#endif
	return 0;
}
