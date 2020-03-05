//첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
//둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

//첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
#include<iostream>
using namespace std;
int recur_chek(int n, int *t, int *p,int pivot, int *map){
eif(pivot>n-1)
		return 0;
	int ans=0;
	int i=pivot;
	if(i+t[i]-1<n){//오늘부터 일하기
		ans+=p[i];
		i+=t[i];
	}
	else
		return 0;//이 날은 일못함
	if(map[i]==-1)
		map[i]=ans;
	int candi=0;
	for(int j=i;j<n;j++)
		candi=max(candi,recur_chek(n,t,p,j,map));
	return ans+candi;
}

int main(){
	int tmp;
	cin >> tmp;
	int ans=0;
	int *t;
	int *p;
	int *map;
	for(int z =0; z<tmp;z++)
	{
	  int n;
	  cin >> n;
		t = (int*)malloc(n*sizeof(int));
		p = (int*)malloc(n*sizeof(int));
		map = (int*)malloc(n*sizeof(int));
	  for(int i = 0; i<n;i++){
		  cin >> t[i];
		  cin >> p[i];
		  map[i] = -1;
		}
	  ans=recur_chek(n,t,p,0,map);
		cout<<ans<<endl;
	  free(t);
	  free(p);
	  free(map);
  }
	return 0;
}
