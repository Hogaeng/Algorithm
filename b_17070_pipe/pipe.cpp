#include<iostream>
#define debug
#define FILENAME "pipe_in.txt"
#define FILE_CIN
using namespace std;
int n;
int board[16][16];
int cnt=0;
int hdir[2][4]={
    {0,1,0,1},//가로
    {0,1,1,1}//대각선
};
int adir[3][4]={
    {1,1,0,1},//가로
    {1,1,1,1},//대각선
    {1,1,1,0}//세로
};
int cdir[2][4]={
    {1,0,1,0},//세로
    {1,0,1,1}//대각선
};
void recur(int xi, int xj, int yi, int yj,int s){
    if((xi==n-1&&xj==n-1) || (yi==n-1)&&(yj==n-1)){
	cnt++;
	return;
    }
    else{
	int nn;
	int (*pp)[4];
	if(s==0){
	    nn=2;
	    pp=hdir;
	}
	else if(s==1){
	    nn=3;
	    pp=adir;
	}
	else{
	    nn=2;
	    pp=cdir;
	}
	for(int i=0;i<nn;i++){
	    int txi=xi+pp[i][0];int txj=xj+pp[i][1];
	    int tyi=yi+pp[i][2];int tyj=yj+pp[i][3];
	    if(txi<n && txi>-1 && txj<n && txj>-1 && tyi<n && tyi>-1 && tyj<n && tyj>-1 && board[txi][txj]!=1 && board[tyi][tyj]!=1){
		if(i==1){
		    if(tyi-1>-1 && tyj-1>-1){
			if(board[tyi-1][tyj]==1 || board[tyi][tyj-1]==1)
			    continue;
		    }
		    else{
			continue;
		    }
		}
		if(s==2&&i==0)
		    recur(txi,txj,tyi,tyj,2);
		else
		    recur(txi,txj,tyi,tyj,i);
	    }
	}
    }
}
int main(){
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	cin>>n;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		cin>>board[i][j];
	recur(0,0,0,1,0);
	cout<<cnt<<endl;

#ifdef FILE_CIN
	cnt=0;
    }
#endif
    return 0;
}
