#include<iostream>
#include<climits>
#include<cmath>
#define debug
#define FILENAME "gery_in.txt"
#define FILE_CIN
using namespace std;
int k;
int board[20][20]={0,};
void printc(int c[20][20]){
    for(int m=0;m<k;m++){
	for(int n=0;n<k;n++)
	    cout<<c[m][n]<<' ';
	cout<<endl;
    }
    cout<<endl;
}
int calc(int c[20][20]){
    int d[5]={0,};
    for(int i=0;i<k;i++)
	for(int j=0;j<k;j++){
	    if(c[i][j]==0)
		d[4]+=board[i][j];
	    else
		d[c[i][j]-1]+=board[i][j];
	}
    int maxi=0;
    int mini=INT_MAX;
    for(int i=0;i<5;i++)
    {
	maxi=max(maxi,d[i]);
	mini=min(mini,d[i]);
    }
    return maxi-mini;
	

}
int drawl(int i,int j, int m, int n){
    int c[20][20]={0,};
    c[i][j]=5;
    c[i+n][j+n]=5;
    for(int l=1;l<m+1;l++){
	c[i+l][j-l]=5;
	c[i+n+l][j+n-l]=5;
    }
    for(int l=1;l<n+1;l++){
	c[i+m+l][j-m+l]=5;
	c[i+l][j+l]=5;
    }
    
    for(int l=1;i-l>-1;l++)
	c[i-l][j]=1;
    for(int l=1;i+m+n+l<k;l++)
	c[i+m+n+l][j-m+n]=4;
    for(int l=1;j+n+l<k;l++)
	c[i+n][j+n+l]=2;
    for(int l=1;j-m-l>-1;l++)
	c[i+m][j-m-l]=3;

    for(int q=1;j-q>-1;q++)
	for(int r=0;r<k;r++)
	    if(c[r][j-q]==0)
		c[r][j-q]=1;
	    else
		break;
    for(int q=1;j+q<k;q++)
	for(int r=0;r<k;r++)
	    if(c[r][j+q]==0)
		c[r][j+q]=2;
	    else
		break;

    for(int q=1;j-m+n-q>-1;q++)
	for(int r=0;r<k;r++)
	    if(c[k-1-r][j-m+n-q]==0)
		c[k-1-r][j-m+n-q]=3;
	    else
		break;
    for(int q=1;j-m+n+q<k;q++)
	for(int r=0;r<k;r++)
	    if(c[k-1-r][j-m+n+q]==0)
		c[k-1-r][j-m+n+q]=4;
	    else
		break;
    
    //printc(c);
    return calc(c);
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    cin>>k;
	    for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
		    cin>>board[i][j];

	    int mini=INT_MAX;
	    for(int m=1;m<k;m++)
		for(int n=1;n<k;n++)
		    for(int i=0;i+m+n<k && i>-1;i++)
			for(int j=m;j+n<k && j-m>-1;j++){
			    int tmp=drawl(i,j,m,n);
			    mini=min(mini,tmp);
			}
	    cout<<mini<<endl;

#ifdef FILE_CIN
	}
#endif
	return 0;
}
