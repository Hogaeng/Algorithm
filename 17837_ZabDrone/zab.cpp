#include<iostream>
#include<vector>
#include<algorithm>
#define debug
#define FILENAME "zab_in.txt"
#define FILE_CIN
using namespace std;
int k;
int mal[10][3]={0,};
int n;
int board[12][12]={0,};
vector<int> loc[12][12];
int dir[4][2]={
    {0,1},//->
    {0,-1},//<-
    {-1,0},//up
    {1,0}//down
};
void printmal(){
    int c[12][12]={0,};
    for(int i=0;i<k;i++){
	c[mal[i][0]][mal[i][1]]++;
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	    cout<<c[i][j]<<' ';
	cout<<endl;
    }
    cout<<endl;
}

void movewhite(int vidx, int idx, int x, int y, int dx, int dy){
    for(int i=vidx;i<loc[x][y].size();i++){
	int midx=loc[x][y][i];
	mal[midx][0]=x+dx;
	mal[midx][1]=y+dy;
	loc[x+dx][y+dy].push_back(midx);
    }
    loc[x][y].erase(loc[x][y].begin()+vidx,loc[x][y].end());
}
void move(int idx){


    bool blue=false;
    do{
	int x=mal[idx][0];
	int y=mal[idx][1];
	int d=mal[idx][2];
	int dx=dir[d][0];
	int dy=dir[d][1];
	auto tt = find(loc[x][y].begin(),loc[x][y].end(),idx);
	int vidx = distance(loc[x][y].begin(),tt);
	if(x+dx<n && x+dx>-1 && y+dy<n && y+dy>-1){
	    int tmp=board[x+dx][y+dy];
	    if(tmp==2){
		if(blue){
		    blue=false;
		}
		else{
		    blue=true;
		    if(d%2==0)
			mal[idx][2]++;
		    else
			mal[idx][2]--;
		}
	    }
	    else if(tmp==0){
		blue=false;
		movewhite(vidx, idx, x,y,dx,dy);
	    }
	    else if(tmp==1){
		blue=false;
		for(int i=loc[x][y].size()-1;i>vidx-1;i--){
		    int midx=loc[x][y][i];
		    mal[midx][0]=x+dx;
		    mal[midx][1]=y+dy;
		    loc[x+dx][y+dy].push_back(midx);
		}
		loc[x][y].erase(loc[x][y].begin()+vidx,loc[x][y].end());
	    }
	}
	else{
	    if(blue)
		blue=false;
	    else{
		blue=true;
		if(d%2==0)
		    mal[idx][2]++;
		else
		    mal[idx][2]--;
	    }
	}
    }while(blue);
}
bool next(){
    for(int l=0;l<k;l++){
	move(l);
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		if(loc[i][j].size()>=4)
		    return true;
	/*
	for(int i=0;i<k;i++){
	    int cnt=0;
	    for(int j=0;j<k;j++){
		if(mal[i][0]==mal[j][0] && mal[i][1]==mal[j][1])
		    cnt++;
	    }
	    if(cnt>=4)
		return true;
	}
	*/
    }
    return false;
}
int main(){
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	cin>>n>>k;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		cin>>board[i][j];
	for(int i=0;i<k;i++){
	    int t1,t2,t3;
	    cin>>t1>>t2>>t3;
	    mal[i][0]=t1-1;
	    mal[i][1]=t2-1;
	    mal[i][2]=t3-1;
	    loc[t1-1][t2-1].push_back(i);
	}

	/*
	printmal();
	if(k>9)
	    cout<<mal[8][2]<<endl;

	*/
	int i=1;
	for(;i<1000;i++){
	    if(next())
		break;
	}
	if(i==1000)
	    cout<<-1<<endl;
	else
	    cout<<i<<endl;

#ifdef FILE_CIN
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		loc[i][j].clear();
    }
#endif
    return 0;
}
