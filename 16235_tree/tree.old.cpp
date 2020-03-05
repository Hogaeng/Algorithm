//vector의 erase때문에 큰일날 뻔했다. 하나 없앨때마다 나머지 요소들이 전부다 앞으로 당겨지기 때문에 엄한것을 삭제하기 때문.
//이것을 해결하기 위해 나무를 그때그때 지우지 않고 나이를 0으로 만들어 나중에 정렬한뒤 0이 있는 나무만 지웠다.
//그리고 최초의 양분을 초기화할때 5로 모두 초기화해야한다. {5,}로는 첫 요소만 5가 되고 나머지는 0이 된다.
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#define R 10
#define C 10
#define M_MAX 100
#define K_MAX 1000
#define file_cin
#define debug
using namespace std;
int n,m,k;
vector<int> trees[R][C];
vector<int> deadtrees[R][C];
int board[R][C]={5,};
int s2d2[R][C]={0,};
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
void wipe(){
    for(int i=0;i<R;i++){
	for(int j=0;j<R;j++){
	    trees[i][j].clear();
	    deadtrees[i][j].clear();
	    board[i][j]=5;
	    s2d2[i][j]=0;
	}
    }
#ifdef debug
    cout<<"wipe"<<'\n';
#endif
}
void sortDownUp(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    sort(trees[i][j].begin(),trees[i][j].end());
	    sort(deadtrees[i][j].begin(),deadtrees[i][j].end());
	}
}
void sortUpDown(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    sort(deadtrees[i][j].begin(),deadtrees[i][j].end(),greater<int>());
	    sort(trees[i][j].begin(),trees[i][j].end(),greater<int>());
	}
}
void printboard(){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	    cout<<board[i][j]<<' ';
	cout<<endl;
    }

}
void printtree(){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cout<<"ij"<<i<<':'<<j<<'>';
	    for(int k=0;k<trees[i][j].size();k++){
		cout<<trees[i][j][k]<<',';
	    }
	    cout<<' ';
	}
	cout<<'\n';
    }
}
void spring(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    for(int k=0;k<trees[i][j].size();k++){
		int y=trees[i][j][k];
		if(board[i][j]-y>-1){
		    //cout<<"yes"<<'\n';
		    trees[i][j][k]+=1;
		    board[i][j]-=y;
		}
		else{
		    //cout<<"no"<<'\n';
		    deadtrees[i][j].push_back(trees[i][j][k]);
		    trees[i][j][k]=0;
		    //trees[i][j].erase(trees[i][j].begin()+k);
		}
	    }
	}
    sortUpDown();
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    int k=0;
	    for(k=0;k<trees[i][j].size();k++){
		if(trees[i][j][k]<1)
		    break;
	    }
	    trees[i][j].erase(trees[i][j].begin()+k,trees[i][j].end());
	}
}
void summer(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	    for(int k=0;k<deadtrees[i][j].size();k++){
		int y=deadtrees[i][j][k];
		board[i][j]+=y/2;
		deadtrees[i][j][k]=0;
		//deadtrees[i][j].erase(deadtrees[i][j].begin()+k);
	    }
    sortUpDown();
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    int k=0;
	    for(k=0;k<deadtrees[i][j].size();k++){
		if(deadtrees[i][j][k]<1){
		    break;
		}
	    }
	    deadtrees[i][j].erase(deadtrees[i][j].begin()+k,deadtrees[i][j].end());
	}
}
void fall(){
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    for(int k=0;k<trees[i][j].size();k++){
		int y=trees[i][j][k];
		if(y%5==0)
		    for(int l=0;l<8;l++){
			int r=i+dir[l][0];
			int c=j+dir[l][1];
			if(r<n&&r>-1&&c<n&&c>-1)
			    trees[r][c].push_back(1);
		    }
	    }
	}
    sortDownUp();
}
int winter(){
    int cnt=0;
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
	    board[i][j]+=s2d2[i][j];
	    if(trees[i][j].size()>0)
		cnt+=trees[i][j].size();
	}
    return cnt;
}
int year(){
    spring();
    summer();
    fall();
#ifdef debug
    printtree();
    cout<<'\n';
    printboard();
#endif
    return winter();
}
int main(){
#ifdef file_cin
    freopen("tree_in.txt","r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	wipe();
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		cin>>s2d2[i][j];
	for(int i=0;i<m;i++){
	    int r,c,k;
	    cin>>r>>c>>k;
	    trees[r-1][c-1].push_back(k);
	}
	int cnt=m;
	while(k--){
	    cnt=year();
	    //cout<<"endyear"<<endl;
	}
	cout<<cnt<<endl;
#ifdef file_cin
    }
#endif
    return 0;
}
