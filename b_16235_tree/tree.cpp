#include<iostream>
#include<vector>
//#define debug
#define FILENAME "tree_in.txt"
#define FILE_CIN
using namespace std;
int board[10][10];
int more[10][10];
int n;
vector<int> trees[10][10];
int counttree(){
    int cnt=0;
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    cnt+=trees[i][j].size();
    return cnt;
}
void printboard(){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	    cout<<board[i][j]<<' ';
	cout<<endl;
    }
    cout<<endl;
}
void springsummer(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    sort(trees[i][j].begin(),trees[i][j].end());
	    vector<int> dead;
	    for(int k=0;k<trees[i][j].size();k++){
		int ta = trees[i][j][k];
		if(board[i][j]>=ta){
		    board[i][j]-=ta;
		    trees[i][j][k]++;
		}
		else
		    dead.push_back(k);
	    }
	    for(int k=dead.size()-1;k>-1;k--){
		board[i][j]+=trees[i][j][dead[k]]/2;
		trees[i][j].erase(trees[i][j].begin()+dead[k]);
	    }
	}

}
void fall(){
    int dir[8][2]={
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1}
    };
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    int tn=trees[i][j].size(); 
	    for(int k=0;k<tn;k++)
		if(trees[i][j][k]%5==0){
		    for(int l=0;l<8;l++){
			int x=dir[l][0];
			int y=dir[l][1];
			if(i+x>-1 && i+x<n && j+y>-1 && j+y<n)
			    trees[i+x][j+y].push_back(1);

		    }
		}
		
	}
}
void winter(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    board[i][j]+=more[i][j];
}

int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    int m,k;
	    cin>>n>>m>>k;
	    
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
		    board[i][j]=5;
		    cin>>more[i][j];
		}
	    for(int i=0;i<m;i++){
		int r,c,ta;
		cin>>r>>c>>ta;
		trees[r-1][c-1].push_back(ta);
	    }
	    for(int i=0;i<k;i++){
		springsummer();
		fall();
		winter();
	    }
	    cout<<counttree()<<endl;

#ifdef FILE_CIN
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		    trees[i][j].clear();
	}
#endif
	return 0;
}
