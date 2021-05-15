/*
각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요.
짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다.
*/
/*
알고스팟은 freopen만 주석처리하고 제출
*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#define debug
#define FILENAME "a_PICNIC/PICNIC_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
int recur(int lev, int pivot, int n, bool *check,vector<pair<int, int> > f){
	int answer=0;
	if(lev==n){
		return 1;
	}
	else{
		for(int i=pivot;i<f.size();i++){
			if(check[f[i].first]==true || check[f[i].second]==true)
				continue;
			check[f[i].first]=true;
			check[f[i].second]=true;
			answer+=recur(lev+2,i,n,check,f);
			check[f[i].first]=false;
			check[f[i].second]=false;
		}
	}
	return answer;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
        //clock_t start=clock();
        //cout<<elapsedseconds(start)<<endl;
		
		int answer=0;
		vector<pair<int,int> > f;
		int n,m;
		cin>>n;
		cin>>m;
		//cout<<n<<":"<<m<<endl;
		int one, two;
		for(int i=0;i<m;i++){
			cin>>one>>two;
			f.push_back(make_pair(one,two));
		}
		bool *check=(bool*)calloc(sizeof(bool),n);
		answer=recur(0,0,n,check,f);
		cout<<answer<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
