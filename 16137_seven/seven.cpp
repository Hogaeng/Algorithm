#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define debug
#define FILENAME "16137_seven/seven_in.txt"
#define FILE_CIN
using namespace std;
int n;
int m;
int b[10][10]={0,};
int v[10][10]={0,};
vector<pair<int,int> > rights;
vector<pair<int,int> > downs;
vector<int> track;
int dfs(int i, int j, int t){
    if(i==n-1 && j==n-1){
        #ifdef debug
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<v[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<' '<<t<<endl;
        #endif
        return t;
    }
    else{
        int min=INT_MAX;
        v[i][j]=1;
        #ifdef debug
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<v[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<' '<<t<<endl;
        cout<<endl;
        #endif
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(int h=0;h<4;h++){
            int di=dir[h][0];
            int dj=dir[h][1];
            if(i+di>n-1||i+di<0||j+dj>n-1||j+dj<0)
                continue;
            if(v[i+di][j+dj]==1)
                continue;
            
            int bv=b[i+di][j+dj];
            vector<pair<int,int> > tmp;
            if(h==1 || h==3){//downs
                tmp=downs;
            }
            else{
                tmp=rights;
            }

            if(bv==1){
                int k=dfs(i+di,j+dj,t+1);
                min=std::min(min,k);
            }
            else if(bv==0){
                auto iter=find(tmp.begin(),tmp.end(),make_pair(i+di,j+dj));
                if(iter!=tmp.end()){
                    int k=INT_MAX;
                    if((t+1)%m==0){
                        k=dfs(i+di,j+dj,t+1);
                    }
                    else{
                        k=dfs(i,j,t+1);
                    }
                    min=std::min(min,k);
                }
            }
            else{
                int k=INT_MAX;
                if((t+1)%bv==0){
                     k=dfs(i+di,j+dj,t+1);
                }
                else{
                     k=dfs(i,j,t+1);
                }
                min=std::min(min,k);
            }
        }
        v[i][j]=0;
        return min;
    }
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
        cin>>m>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>b[i][j];
        int bv=1;
        for(int j=0;j<n;j++){
            for(int i=0;i<n-1;i++){
                int v=b[i][j];
                int nv=b[i+1][j];
                if(bv==1 && nv==1 && v==0)
                    downs.push_back(make_pair(i,j));
                bv=v;
            }
        }

        bv=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                int v=b[i][j];
                int nv=b[i][j+1];
                if(bv==1 && nv==1 && v==0)
                    rights.push_back(make_pair(i,j));
                bv=v;
            }
        }
        int answer=dfs(0,0,0);
        cout<<answer<<endl;
#ifdef FILE_CIN
    rights.clear();
    downs.clear();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[i][j]=0;
	}
#endif
	return 0;
}