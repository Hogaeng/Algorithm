#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define FILENAME "chicken_in1.txt"
#define FILE_CIN
int cnt=0;
using namespace std;

vector<vector<int> > h;
vector<vector<int> > c;

int dir[4][2]={
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int recur_h(int lev, queue<vector<int> >subh, bool board[50][50],bool c[50][50],int n){
    /*
    cout<<"hl"<<lev<<"sh"<<subh.size()<<endl;
    if(lev==4)
	for(int i=0;i<subh.size();i++){
	    for(int j=0;j<subh[i].size();j++)
		cout<<subh[i][j]<<' ';
	    cout<<endl;
	}
    */
    while(!subh.empty()){
	int x=subh.front()[0];
	int y=subh.front()[1];
	int dd=subh.front()[2];
	subh.pop();
	for(int i=0;i<4;i++){
	    int dx=dir[i][0];
	    int dy=dir[i][1];
	    cnt++;
	    if(dx+x>-1&& dy+y>-1 && dx+x<n && dy+y<n && !c[dx+x][dy+y]){
		dx+=x;
		dy+=y;
		c[dx][dy]=true;
		if(!board[dx][dy]){
		    vector<int> t;
		    t.push_back(dx);
		    t.push_back(dy);
		    t.push_back(dd+1);
		    subh.push(t);
		}
		else
		    return dd+1;
	    }
	}
    }
    return INT_MAX;
}
int recur_c(int n,int lev,int idx, int m,vector<int> choice){
    if(lev==m){
	vector<vector<int> > newc;
	for(int i=0;i<choice.size();i++){
	    vector<int> t;
	    t.push_back(c[choice[i]][0]);
	    t.push_back(c[choice[i]][1]);
	    newc.push_back(t);
	}
	//맨허튼 거리로 푸는 방법
	/*

	int total=0;
	for(int i=0;i<h.size();i++){
	    int xh=h[i][0];
	    int yh=h[i][1];
	    int mindist=INT_MAX;
	    for(int j=0;j<newc.size();j++){
		int xc=newc[j][0];
		int yc=newc[j][1];
		int dist=abs(xh-xc)+abs(yh-yc);
		cnt++;
		if(mindist>dist)
		    mindist=dist;
	    }
	    total+=mindist;
	}
	return total;
	*/
	//BFS로 푸는 방법
	int board[50][50]={0,};
	for(int i=0;i<h.size();i++){
	    int x=h[i][0];
	    int y=h[i][1];
	    board[x][y]=true;
	}
	int total=0;
	for(int i=0;i<newc.size();i++){
	    bool c[50][50]={0,};
	    c[newc[i][0]][newc[i][1]]=true;
	    queue<vector<int> > subh;
	    vector<int> t;
	    t.push_back(newc[i][0]);
	    t.push_back(newc[i][1]);
	    t.push_back(0);
	    subh.push(t);
	    int ttt=recur_h(0,subh,board,c,n);
	    total+=ttt;
	}
	return total;
    }
    else{
	int ret=INT_MAX;
	for(int i=idx;i<c.size();i++){
	    choice.push_back(i);
	    int ttt=recur_c(n,lev+1,i+1,m,choice);
	    if(ret>ttt)
		ret=ttt;
	    choice.erase(choice.end()-1);
	}
	return ret;
    }
}
int main(){
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	int m=0,n=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++){
		int tt=0;
		cin>>tt;
		vector<int> t;
		t.push_back(i);
		t.push_back(j);
		if(tt==1)
		    h.push_back(t);
		if(tt==2)
		    c.push_back(t);
	    }
	vector<int> choice;
	cout<<recur_c(n,0,0,m,choice)<<endl;
	//cout<<cnt<<endl;
#ifdef FILE_CIN
	h.clear();
	c.clear();
	cnt=0;
    }
#endif
    return 0;
}
