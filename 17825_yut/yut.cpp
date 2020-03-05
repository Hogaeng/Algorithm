#include<iostream>
#include<cmath>
#define debug
//#define FILENAME "yut_in3.txt"
//#define FILE_CIN
using namespace std;
int board[5][20]={
    {0,},
    {10,13,16,19,25,},
    {20,22,24,25,},
    {30,28,27,26,25,},
    {25,30,35,40,}
};
int dir[4][4]={
    {0,4,1,0},
    {0,9,2,0},
    {0,14,3,0},
    {0,19,4,3},
};
int dicev[10];
int malchoice[10];

bool boundary(int i, int j){
    //if(i==0 && j>19)
	//return true;
    if(i==1 && j>4)
	return true;
    if(i==2 && j>3)
	return true;
    if(i==3 && j>4)
	return true;
    //if(i==4 && j>3)
	//return true;
    return false;
}
int turndir(int i,int j){
    for(int x=0;x<4;x++)
	if(dir[x][0]==i && dir[x][1]==j)
	    return x;
    return -1;
}
int movemal(){
    bool c[5][20]={0,};
    int mali[4]={0,};
    int malj[4]={-1,-1,-1,-1};
    int total=0;
    for(int i=0;i<10;i++){

	int idx=malchoice[i]-1;
	int mi=mali[idx];
	int mj=malj[idx];
	if(mj!=-1)
	    c[mi][mj]=false;
	mj+=dicev[i];
	if(boundary(mi,mj)){
	    if(mi==1 || mi==3)
		mj-=4;
	    else if(mi==2)
		mj-=3;
	    mi=4;
	}
	mali[idx]=mi;
	malj[idx]=mj;
	int tmp;
	if((tmp=turndir(mi,mj))!=-1){
	    mi=dir[tmp][2];
	    mj=dir[tmp][3];
	    mali[idx]=mi;
	    malj[idx]=mj;
	}

	/*
	int answer[10]={1,1,1,1,1,1,1,1,1,1};
	bool tt=false;
	for(int i=0;i<10;i++){
	    if(answer[i]!=malchoice[i])
		tt=true;
	}
	if(!tt)
	    cout<<dicev[i]<<' '<<idx+1<<' '<<mi<<' '<<mj<<' '<<board[mi][mj]<<' '<<total<<endl;

	*/
	if(mi==0 && mj>19){
	    mali[idx]=4;
	    malj[idx]=4;
	    continue;
	}
	if(mi==4 && mj>3){
	    malj[idx]=4;
	    continue;
	}
	if(c[mi][mj])
	    return 0;
	c[mi][mj]=true;
	total+=board[mi][mj];
    }
    return total;
}

int recur_pi(int lev){
    if(lev==0){
	return movemal();
    }
	
    else{
	int maxi=0;
	for(int i=1;i<5;i++){
	    malchoice[10-lev]=i;
	    int tmp=recur_pi(lev-1);
	    maxi=max(maxi,tmp);
	}
	return maxi;
    }
}

int main(){
	for(int i=0;i<20;i++)
	    board[0][i]=(i+1)*2;
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    for(int i=0;i<10;i++)
		cin>>dicev[i];
	    cout<<recur_pi(10)<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
