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
int visited[10][10]={0,};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<pair<int,int> > rights;
vector<pair<int,int> > downs;
vector<int> track;
void bfs(){
    vector<pair<int,int> > que;
    que.push_back(make_pair(0,0));
    v[0][0]=1;
	visited[0][0]=1;
    while(que.size()>0){
		int x=que[0].first,y=que[0].second,t=v[x][y];
#ifdef debug
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<visited[i][j]<<' ';
			cout<<endl;
		}
		cout<<endl;
#endif
        que.erase(que.begin());
		if(x==n-1 && y==n-1)
			continue;
        for(int i=0;i<4;i++){
            int dx=dir[i][0],dy=dir[i][1];
            int nx=x+dx,ny=y+dy;
            int h;
            vector<pair<int,int> > tmp;
            if(i==1 || i==3)
                tmp=downs;
            else
                tmp=rights;
            
            if(nx>-1&&nx<n&&ny>-1&&ny<n){
				if(visited[nx][ny]>0)
					continue;
				visited[nx][ny]=1;
                int bp=b[x][y];
                int bn=b[nx][ny];
                if(bn==0){
                    if(bp==1){
                        auto iter=find(tmp.begin(),tmp.end(),make_pair(nx,ny));
                        if(iter!=tmp.end()){
                            int cnt=0;
                            while((t+cnt)%m>0)cnt++;
                            int tmp=t+cnt+1;
                            if(v[nx][ny]>0)
                                v[nx][ny]=min(v[nx][ny],tmp);
                            else
                                v[nx][ny]=tmp;
                            
                            que.push_back(make_pair(nx,ny));
                        }
                    }
                    
                }
                else if(bn==1){
                    int tmp=t+1;
                    if(v[nx][ny]>0)
                        v[nx][ny]=min(v[nx][ny],tmp);
                    else
                        v[nx][ny]=tmp;
                    que.push_back(make_pair(nx,ny));
                }
                else{
                    if(bp==1){
                        int cnt=0;
                        while((t+cnt)%bn>0)cnt++;
                        int tmp=t+cnt+1;
                        if(v[nx][ny]>0)
                            v[nx][ny]=min(v[nx][ny],tmp);
                        else
                        {
                            v[nx][ny]=tmp;
                        }
                        que.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
    //freopen("output.txt","w",stdout);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
        cin>>n>>m;
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
        /*
        int answer=INT_MAX;
        for(int i=0;i<rights.size();i++){
            int x=rights[i].first, y=rights[i].second;
            b[x][y]=m;
            int tmp=dfs(0,0,0);
            answer=min(tmp,answer);
            b[x][y]=0;
        }
        for(int i=0;i<downs.size();i++){
            int x=downs[i].first, y=downs[i].second;
            b[x][y]=m;
            int tmp=dfs(0,0,0);
            answer=min(tmp,answer);
            b[x][y]=0;
        }
        cout<<answer<<endl;
        */
        bfs();
        #ifdef debug
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
				if(v[i][j]/10==0)
					cout<<' ';
				cout<<v[i][j]<<' ';
			}
            cout<<endl;
            }
        #endif
        cout<<v[n-1][n-1]-1<<endl;
#ifdef FILE_CIN
    rights.clear();
    downs.clear();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            v[i][j]=0;
            visited[i][j]=0;
		}
	}
#endif
	return 0;
}
