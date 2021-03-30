#include<iostream>
#include<vector>
#define debug
#define FILENAME "b_19237_adultshark/adultshark_in.txt"
#define FILE_CIN
using namespace std;
int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		int b[20][20]={0,};
		int d[401]={0,};
		pair<int,int> bscent[20][20];
		vector<int> priord[401];
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				cin>>b[i][j];
				if(b[i][j]>0)
					bscent[i][j]=make_pair(b[i][j],k);
				else
					bscent[i][j]=make_pair(0,0);
			}
		for(int i=1;i<=m;i++){
			vector<int> tmp;
			for(int j=0;j<4;j++){
				int t;
				cin>>t;
				tmp.push_back(t);
			}
			priord[i]=tmp;
		}
		for(int i=1;i<=m;i++){
			cin>>d[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<bscent[i][j].first<<':'<<bscent[i][j].second<<' ';
			}
			cout<<endl;
		}
#endif
#ifdef FILE_CIN
	}
#endif
	return 0;
}
