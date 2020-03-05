#include<iostream>
#include<climits>
#include<cmath>
#define debug
#define FILENAME "gery_in1.txt"
#define FILE_CIN
using namespace std;
int n;
int board[20][20];
int dir[2][2]={
    {1,-1},
    {1,1}
};
void printc(int c[20][20],int x, int y){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	    cout<<c[i][j]<<' ';
	cout<<endl;
    }
    cout<<x<<' '<<y<<endl;
    cout<<endl;
}
int calc(int c[20][20]){
    int mini=INT_MAX;
    int maxi=0;
    int total[5]={0,};
    for(int k=0;k<n;k++)
	for(int l=0;l<n;l++){
	    if(c[k][l]==0 || c[k][l]==5)
		total[4]+=board[k][l];
	    if(c[k][l]==1)
		total[0]+=board[k][l];
	    if(c[k][l]==2)
		total[1]+=board[k][l];
	    if(c[k][l]==3)
		total[2]+=board[k][l];
	    if(c[k][l]==4)
		total[3]+=board[k][l];
	}
    for(int i=0;i<5;i++){
	//cout<<total[i]<<' ';
	mini=min(mini,total[i]);
	maxi=max(maxi,total[i]);
    }
    //cout<<endl;
    if(maxi-mini==127)
	printc(c,0,0);
    return maxi-mini;
}
int drawlines(int x, int y){
    int maxi=0;
    int mini=INT_MAX;
    int j=1;
    for(j=1;j+y<n;j++){
	for(int i=1;i+x+j<n;i++){
	    int board[20][20]={0,};
	    board[x][y]=5;
	    int dx=dir[0][0];
	    int dy=dir[0][1];
	    int nx=x;
	    int ny=y;
	    int mx=x+j;
	    int my=y+j;
	    for(int k=0;k<i;k++){
		nx+=dx;
		ny+=dy;
		mx+=dx;
		my+=dy;
		board[nx][ny]=5;
		board[mx][my]=5;
	    }
	    dx=dir[1][0];
	    dy=dir[1][1];
	    nx=x;
	    ny=y;
	    mx=x+i;
	    my=y-i;
	    for(int k=0;k<j;k++){
		nx+=dx;
		ny+=dy;
		mx+=dx;
		my+=dy;
		board[nx][ny]=5;
		board[mx][my]=5;
	    }
	    for(int k=x-1;k>-1;k--)
		board[k][y]=1;
	    for(int k=y-i-1;k>-1;k--)
		board[x+i][k]=3;
	    for(int k=y+j+1;k<n;k++)
		board[x+j][k]=2;
	    for(int k=x+i+j+1;k<n;k++)
		board[k][y-i+j]=4;

	    for(int k=1;y-k>-1;k++)
		for(int l=0;l<n;l++){
		    if(board[l][y-k]!=0)
			break;
		    board[l][y-k]=1;
		}

	    for(int k=1;y+k<n;k++)
		for(int l=0;l<n;l++){
		    if(board[l][y+k]!=0)
			break;
		    board[l][y+k]=2;
		}

	    for(int k=1;y-i+j-k>-1;k++)
		for(int l=n;l>-1;l--){
		    if(board[l][y-i+j-k]!=0)
			break;
		    board[l][y-i+j-k]=3;
		}
	    for(int k=1;y-i+j+k<n;k++)
		for(int l=n;l>-1;l--){
		    if(board[l][y-i+j+k]!=0)
			break;
		    board[l][y-i+j+k]=4;
		}

	    int tttt=calc(board);
	    mini=min(mini,tttt);
	}
    }
    return mini;

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
	    int mini=INT_MAX;
	    for(int i=0;i<n-2;i++)
		for(int j=1;j<n;j++)
		    mini=min(mini,drawlines(i,j));
	    cout<<mini<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
