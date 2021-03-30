#include<iostream>
#include<limits.h>
#include<queue>
#include<vector>
#define FILENAME "chicken_in.txt"
#define FILE_CIN
using namespace std;
enum {B,H,C};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int board[50][50]={0,};
bool eboard[50][50]={0,};
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;
vector<pair<int,int> > subchicken;
queue<pair<int,int> > buf;
queue<int> cnts;
int n,m;
void wipeEntered(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    eboard[i][j]=0;
    queue<pair<int,int> > emp;
    queue<int> emp2;
    swap(buf,emp);
    swap(cnts,emp2);
}
void wipe(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    board[i][j]=0;
	}
    house.clear();
    chicken.clear();
    wipeEntered();
}
int bfs_subfunc(int r, int c,int cnt){
    if(r<0||r>n-1||c<0||c>n-1||eboard[r][c]==1)
	return -1;
    else{
	eboard[r][c]=1;
	for(int i=0;i<n;i++){
	    buf.push(pair<int,int>(r+dir[i][0],c+dir[i][1]));
	    cnts.push(cnt+1);
	}
	if(board[r][c]==2)
	    return cnts.front();
	else
	    return -1;
    }
}
int bfs(){
    //cout<<r<<' '<<c<<endl;
    for(;!buf.empty();){
	int tmp;
	if((tmp=bfs_subfunc(buf.front().first,buf.front().second,cnts.front()))!=-1)
	    return tmp;
	buf.pop();
	cnts.pop();
    }
    return -1;
}
void makeboardsub(){
    for(int i=0;i<subchicken.size();i++)
	board[subchicken[i].first][subchicken[i].second]=2;
}
void makeboard(){
    for(int i=0;i<subchicken.size();i++)
	board[subchicken[i].first][subchicken[i].second]=0;
}
int recursiv(int cnt,int lv){
    int max=INT_MAX;
    if(cnt==m){
	makeboardsub();
	int tmp=0;
	int ret=0;
	for(int i=0;i<house.size();i++){
	    buf.push(house[i]);
	    cnts.push(0);
	    if((ret=bfs())!=-1)
		tmp+=ret;
	    wipeEntered();
	}
	makeboard();
	return tmp;
    }
    else{
	for(int i=lv;i<chicken.size();i++){
	    subchicken.push_back(chicken[i]);
	    max=min(max,recursiv(cnt+1,lv+1));
	    subchicken.erase(subchicken.begin()+subchicken.size()-1);
	}
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
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++){
		cin>>board[i][j];
		if(board[i][j]==1)
		    house.push_back(pair<int,int>(i,j));
		else if(board[i][j]==2){
		    board[i][j]=0;
		    chicken.push_back(pair<int,int>(i,j));
		}
	    }
	cout<<recursiv(0,0)<<endl;
#ifdef FILE_CIN
	wipe();
    }
#endif
    return 0;
}
