#include<iostream>
using namespace std;
enum {U,B,R,L,F,D};
enum {EE,E,W,N,S};
int dice[6]={0,};
int board[20][20];
int r = 0;c=0;
int sdir[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
void rolldice(int dir){
	int tmp;
	if(dir == E){
		tmp = dice[R];
		dice[R]=dice[U];
		dice[U]=dice[L];
		dice[L]=dice[D];
		dice[D]=tmp;
	}
	if(dir == W){
		tmp = dice[L];
		dice[L]=dice[U];
		dice[U]=dice[R];
		dice[R]=dice[D];
		dice[D]=tmp;
	}
	if(dir == N){
		tmp = dice[D];
		dice[D]=dice[B];
		dice[B]=dice[U];
		dice[U]=dice[F];
		dice[F]=tmp;
	}
	if(dir == S){
		tmp = dice[F];
		dice[F]=dice[U];
		dice[U]=dice[B];
		dice[B]=dice[D];
		dice[D]=tmp;
	}
}
void rollboard(int dir){
	int tr,tc;
	r = r+sdir[dir][0];
	c = c+sdir[dir][1];
	
}
int main(){
	freopen("dice_in1.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
	}
	cout<<dice[D]<<endl;
	return 0;
}
