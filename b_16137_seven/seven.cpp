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
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<pair<int,int> > rights;
vector<pair<int,int> > downs;
vector<int> track;
void bfs(){
	for(int i=1;i<n;i++){
		if(b[0][i]==1)
			v[0][i]=v[0][i-1]+1;
		else if(b[0][i]>0){
			if(i+1<n && b[0][i+1]==1){
				int cnt=1;
				while((v[0][i-1]+cnt)%b[0][i]>0)cnt++;
				v[0][i]=v[0][i-1]+cnt;
				v[0][i+1]=v[0][i]+1;
				i++;
			}
		}
		else{
			auto iter=find(rights.begin(),rights.end(),make_pair(0,i));
			if(iter!=rights.end()){
				int cnt=1;
				while((v[0][i-1]+cnt)%m>0)cnt++;
				v[0][i]=v[0][i-1]+cnt;
				if(i+1<n){
					v[0][i+1]=v[0][i]+1;
					i++;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		if(b[i][0]==1)
			v[i][0]=v[i-1][0]+1;
		else if(b[i][0]>0){
			if(i+1<n && b[i+1][0]==1){
				int cnt=1;
				while((v[i-1][0]+cnt)%b[i][0]>0)cnt++;
				v[i][0]=v[i-1][0]+cnt;
				v[i+1][0]=v[i][0]+1;
				i++;
			}
		}
		else{
			auto iter=find(downs.begin(),downs.end(),make_pair(i,0));
			if(iter!=downs.end()){
				int cnt=1;
				while((v[i-1][0]+cnt)%m>0)cnt++;
				v[i][0]=v[i-1][0]+cnt;
				if(i+1<n){
					v[i+1][0]=v[i][0]+1;
					i++;
				}
			}
		}
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++){
			int bi=i-1,bj=j-1;

			int upv=INT_MAX;
			if(b[i][j]==1){
				if(b[bi][j]==1)
					upv=v[bi][j]+1;
				else{
					if(b[bi][j]==0){
						auto iter=find(downs.begin(),downs.end(),make_pair(bi,j));
						if(iter!=downs.end())
							upv=v[bi][j]+1;
					}
					else
						upv=v[bi][j]+1;
				}
			}
			else if(b[i][j]==0){
				auto iter=find(downs.begin(),downs.end(),make_pair(i,j));
				if(iter!=downs.end()){
					int cnt=1;
					while((v[bi][j]+cnt)%m>0)cnt++;
					upv=v[bi][j]+cnt;
				}
			}
			else{
				int cnt=1;
				while((v[bi][j]+cnt)%b[i][j]>0)cnt++;
				upv=v[bi][j]+cnt;
			}

			int lfv=INT_MAX;
			if(b[i][j]==1){
				if(b[i][bj]==1)
					lfv=v[i][bj]+1;
				else{
					if(b[i][bj]==0){
						auto iter=find(rights.begin(),rights.end(),make_pair(i,bj));
						if(iter!=rights.end()){
#ifdef debug
							if(i==6&&j==4)
								cout<<upv<<' '<<v[i][bj]<<endl;

#endif
							lfv=v[i][bj]+1;
						}
					}
					else
						lfv=v[i][bj]+1;
				}
			}
			else if(b[i][j]==0){
				auto iter=find(rights.begin(),rights.end(),make_pair(i,j));
				if(iter!=rights.end()){
					int cnt=1;
					while((v[i][bj]+cnt)%m>0)cnt++;
					lfv=v[i][bj]+cnt;
				}
			}
			else{
				int cnt=1;
				while((v[i][bj]+cnt)%b[i][j]>0)cnt++;
				lfv=v[i][bj]+cnt;
			}
			v[i][j]=min(upv,lfv);
			if(v[i][j]==INT_MAX)
				v[i][j]=0;
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
        cout<<v[n-1][n-1]<<endl;
#ifdef FILE_CIN
    rights.clear();
    downs.clear();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            v[i][j]=0;
		}
	}
#endif
	return 0;
}
