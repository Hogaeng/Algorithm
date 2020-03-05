#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#define FILE_CIN
#define FILE_NAME "obser_in1.txt"
#define debug 4
using namespace std;
int z=0;
int board[8][8];
int tboard[8][8];
pair<int,int> cctvpo[8];
int cctvcate[8];
int cctvind=0;
int cctvnowdir[8]={0,};
int cctvbitmax;
vector<pair<int,int> > wall;
int cnt=INT_MAX;
enum {P,M};//반시계방향회전, 시계방향회전
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void printtboard(int N, int M){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout<<tboard[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
int dir_operate(int dirind, int operant,int pn){
	if(pn == P)
		if(dirind+operant>3)
			return (dirind+operant)%4;
		else
			return dirind+operant;
	else
		if(dirind-operant<0)
			if((operant-dirind)%4==0)
				return 0;
			else
				return 4-(operant-dirind)%4;
		else
			return dirind-operant;
}
void drawit(int dirind, int cctvind, int N, int M){
	int x = cctvpo[cctvind].first;
	int y = cctvpo[cctvind].second;
	//cout<<'i'<<cctvpo[cctvind].first<<':'<<cctvpo[cctvind].second<<endl;
	int tx=x;int ty=y;
	for(int i=0;tx>-1&&tx<N&&ty>-1&&ty<M;i++){
		tx+=dir[dirind][0];
		ty+=dir[dirind][1];
		if(tboard[tx][ty] == 0)
			tboard[tx][ty]=7;
		else if(tboard[tx][ty]==6)
			break;
	}
}
void drawone(int dirind, int cctvind, int N, int M){
	//cout<<'o'<<cctvcate[cctvind]<<endl;
	switch(cctvcate[cctvind]){
		case 1://dirind<4
			drawit(dirind,cctvind, N, M);
			break;
		case 2://dirind<2
			drawit(dirind,cctvind, N, M);
			drawit(dir_operate(dirind,2,P),cctvind, N, M);
			break;
		case 3://dirind<4
			drawit(dirind,cctvind, N, M);
			drawit(dir_operate(dirind,1,P),cctvind, N, M);
			break;
		case 4://dirind<4
			drawit(dirind,cctvind, N, M);
			drawit(dir_operate(dirind,1,P),cctvind, N, M);
			drawit(dir_operate(dirind,2,P),cctvind, N, M);
			break;
		case 5:
			drawit(dirind,cctvind, N, M);
			drawit(dir_operate(dirind,1,P),cctvind, N, M);
			drawit(dir_operate(dirind,2,P),cctvind, N, M);
			drawit(dir_operate(dirind,3,P),cctvind, N, M);
			break;
defalut:
			break;
	}
}
int searchZ(int N, int M)
{
	int tmpcnt=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(tboard[i][j]==0)
				tmpcnt++;
	return tmpcnt;
}
void revert(int N, int M){
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			tboard[i][j]=board[i][j];
}
int drawall(int N, int M){
	for(int i=0;i<cctvind;i++){
		//cout<<'d'<<i<<cctvnowdir[i]<<endl;
		drawone(cctvnowdir[i],i,N,M);
	}
	return searchZ(N,M);
}
void bruteforce(int N, int M){
	for(int i=0;i<cctvbitmax;i++){
		//cout<<'b'<<i<<endl;
		revert(N,M);
		int tmp=drawall(N,M);
		//cout<<'e'<<i<<endl;
		cnt=min(cnt,tmp);
#ifdef debug
		if(z==debug){
			for(int i=cctvind-1;i>-1;i--)
				cout<<cctvnowdir[i];
		cout<<endl;
		}
		bool ck=true;
		for(int i=0;i<cctvind;i++)
			if(cctvnowdir[i]!=2){
				ck=!ck;
				break;
			}
		if(ck){
			for(int i=cctvind-1;i>-1;i--)
				cout<<cctvnowdir[i];
			cout<<endl;
			printtboard(N,M);
		}
#endif
		cctvnowdir[0]++;
		for(int j=0;j<cctvind-1&&cctvnowdir[j]>3;j++){
			cctvnowdir[j]=0;
			cctvnowdir[j+1]++;
		}
	}
}
//void burteforce(int N, int M)
void clear(int N, int M)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			board[i][j] = 0;
	for(int i=0;i<8;i++)
		cctvnowdir[i]=0;
	wall.clear();
	cnt=INT_MAX;
	cctvind=0;
	cctvbitmax=0;
}
int main(){
#ifdef FILE_CIN
	freopen(FILE_NAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(z=0;z<tmp;z++){
#endif
		int N,M;
		cin>>N;
		cin>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				cin>>board[i][j];
				if(board[i][j]==6)
					wall.push_back(pair<int,int>(i,j));
				else if(board[i][j]>0){
					cctvpo[cctvind].first = i;
					cctvpo[cctvind].second = j;
					cctvcate[cctvind] = board[i][j];
					cctvind++;
				}
			}
		cctvbitmax=pow(4,cctvind);
#ifdef debug
		//cout<<cctvbitmax<<endl;
#endif
		revert(N,M);
		bruteforce(N,M);
		cout<<cnt<<endl;
#ifdef FILE_CIN
		clear(N,M);
	}
#endif
	return 0;
}
