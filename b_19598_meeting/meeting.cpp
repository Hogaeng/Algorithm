#include<iostream>
#include<vector>
#include<ctime>
#include<climits>
#include<algorithm>
#define debug
#define FILENAME "b_19598_meeting/meeting_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		int n;
		cin>>n;
		vector<pair<int,int> > t;
		for(int i=0;i<n;i++){
			int b,e;
			cin>>b>>e;
			t.push_back(make_pair(b,1));
			t.push_back(make_pair(e,-1));
		}
		sort(t.begin(),t.end());
		int res=0,cnt=0;
		for(int i=0;i<t.size();i++){
			cnt+=t[i].second;
			res=max(cnt,res);
		}
		cout<<res<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}

