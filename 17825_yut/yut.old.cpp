#include<iostream>
#include<vector>
#define debug
#define FILE_CIN
#define FILENAME "yut_in4.txt"
using namespace std;
vector<int> input;
int malpo[10] = {0,};
int board[5][20]={
		    {0,},
		    {10,13,16,19,25,30,35,40},//10
		    {20,22,24,25,30,35,40},//20
		    {30,28,27,26,25,30,35,40},//30
		    {25,30,35,40},//30
		};
int boardis[16][4]={
		    {0,4,1,0},
		    {0,9,2,0},
		    {0,14,3,0},
		    {0,19,4,3},
		    {1,4,4,0},
		    {1,5,4,1},
		    {1,6,4,2},
		    {1,7,4,3},
		    {2,3,4,0},
		    {2,4,4,1},
		    {2,5,4,2},
		    {2,6,4,3},
		    {3,4,4,0},
		    {3,5,4,1},
		    {3,6,4,2},
		    {3,7,4,3}
		};
bool boundary(const int mal[4], const int mals[4],int nu){
    if(mals[nu]==4)
	if(mal[nu]>3)
	    return true;
    if(mals[nu]==0)
	if(mal[nu]>19)
	    return true;
    if(mals[nu]==2)
	if(mal[nu]>6)
	    return true;
    if(mals[nu]==1||mals[nu]==3)
	if(mal[nu]>7)
	    return true;
    return false;
}
int check(){
    int score=0;
    int mals[4] = {0,};
    int mal[4] = {-1,-1,-1,-1};
    int boardexist[5][20] = {0,};
    for(int i=0;i<10;i++){
	int nu=malpo[i]-1;
	if(boundary(mal,mals,nu))
	    ;
	else
	    boardexist[mals[nu]][mal[nu]]=0;
	mal[nu]+=input[i];

	for(int j=0;j<16;j++){
	    int x1=boardis[j][0];
	    int y1=boardis[j][1];
	    int x2=boardis[j][2];
	    int y2=boardis[j][3];
	    if(mals[nu]==x1 && mal[nu]==y1){
		mals[nu]=x2;
		mal[nu]=y2;
	    }
	}
	if(boundary(mal,mals,nu))
	    ;
	else{
	    score+=board[mals[nu]][mal[nu]];
	    if(boardexist[mals[nu]][mal[nu]]==1)
		return 0;
	    else
		boardexist[mals[nu]][mal[nu]]=1;
	}
    }
    return score;
}
int recur(int i,int m,int am){
    int max=0;
    if(i<11){
	malpo[i-1]=m;
	for(int j=0;j<=i-1;j++)
	    if(am==malpo[j])
		if(am<4){
		    am+=1;
		    break;
		}
	if(i+1==11)
	    am=1;
	for(int mm=1;mm<=am;mm++){
	    int tmpmax=0;
	    tmpmax=recur(i+1,mm,am);
	    if(tmpmax>max)
		max=tmpmax;
	}
    }
    else{
	return check();
    }
    return max;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    for(int i=0;i<20;i++)
		board[0][i]=2*(i+1);
	    for(int i=0;i<10;i++){
		int k;
		cin>>k;
		input.push_back(k);
	    }
	    cout<<recur(1,1,1);//<<'\n';
	    //cout<<check()<<'\n';
#ifdef FILE_CIN
	input.clear();
	}
	cout<<"old_habit"<<endl;
#endif
	return 0;
}
