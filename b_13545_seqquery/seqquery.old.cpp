//lookup은 시작하는 값을 index에 두고
//끝나는 값은 각 벡터에 들어 있는 값이다.
//시작하는 값에서 부터 끝나는 값 까지가 0인 것만 들어있다..
//즉 0번째 벡터에서부터 1, 4가 들어가 있으면 0~1, 0~4의 합은 0의 값인 의미다.
//2, 3은 들어가 있지 않으므로 0~2, 0~3의 합은 0의 값을 갖지 않는다 
#include<iostream>
#include<vector>
#include<cmath>
#define debug
#define FILENAME "seq_in2.txt"
#define FILE_CIN
using namespace std;
int n;
bool c[100000];
vector<int> lookup[100000];
void printlook(){
    for(int i=0;i<n;i++){
	for(int j=0;j<lookup[i].size();j++){
	    cout<<i<<' '<<lookup[i][j]<<endl;
	}
    }
    cout<<endl;
}
int checkit(int k, int l){
    int t=0;
    for(int i=0;i<lookup[k].size();i++){
	if(lookup[k][i]==l){
	    return l-k+1;
	}
    }
    if(t==0 && k+1<l && k+1<n)
	t=checkit(k+1,l);
    /*
    if(t==0 && l+1>k && l+1<n)
	t=checkit(k,l+1);
    */
    if(t==0 && l-1>k && l-1>-1)
	t=checkit(k,l-1);
    /*
    if(t==0 && k-1<l && k-1>-1)
	t=checkit(k-1,l);
	*/
    return t;
}
void makelook_dfs(int lev, int idx){
    if(idx+lev>n-1)
	return;
    if(c[idx] != c[idx+lev]){
	lookup[idx].push_back(idx+lev);
	if(idx-1>-1)
	    makelook_dfs(lev+2,idx-1);
    }
}
/*
void makelook_bfs(){
    vector<int> q;
    q.push_back(0);
    q.push_back(1);
    while(!q.empty()){
	int t1,t2;
	t1=q[0];
	q.erase(q.begin());
	t2=q[0];
	q.erase(q.begin());
	q.push_back(t2);
	q.push_back(t2+1);
	if(c[t1]!=c[t2]){
	   ;
	}
    }
}
*/
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    cin>>n;
	    for(int i=0;i<n;i++){
		int k;
		cin>>k;
		if(k==1)
		    c[i]=true;
		else
		    c[i]=false;
	    }
	    for(int i=0;i<n-1;i++)
		makelook_dfs(1,i);
	    //printlook();
	    int t;
	    cin>>t;
	    for(int i=0;i<t;i++){
		int m,k;
		cin>>m>>k;
		cout<<checkit(m-1,k-1)<<endl;
	    }
	    
#ifdef FILE_CIN
	    for(int i=0;i<n;i++)
		lookup[i].clear();
	    cout<<endl;
	}
#endif
	return 0;
}
