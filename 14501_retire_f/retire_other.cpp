//첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
//둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

//첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
//map[n]은 지난날 받은 것을 제외한 n번째 날까지 받을 수 있는 최대 수익
//초기값:map[n-1] = p[n-1]
//점화식:map[i] = map[i+t[i]]+p[i]
#include<iostream>
using namespace std;
void recur_chek(int n, int *t, int *p,int i, int *map){
	if(i<0)
		return;
	int tmp;
	if(i+t[i]-1<n)//can you work this day?
		tmp = p[i];
	else
		tmp = 0;
	map[i]=tmp;
	if(i+t[i]<n)//make map
		map[i]=map[i+t[i]]+tmp;
	if(i<n-1)
		map[i]=max(map[i],map[i+1]);
	recur_chek(n,t,p,i-1,map);
}
int main(){
	int tmp;
	cin >> tmp;
	int *t;
	int *p;
	int *map;
	int ans;
	for(int z =0; z<tmp;z++)
	{
	  ans=0;
	  int n;
	  cin >> n;
	  t = (int*)malloc(n*sizeof(int));
	  p = (int*)malloc(n*sizeof(int));
	  map = (int*)malloc(n*sizeof(int));
	  for(int i = 0; i<n;i++){
		  cin >> t[i];
		  cin >> p[i];
		  map[i] = p[i];
	  }
	  recur_chek(n,t,p,n-1,map);
	  //for(int i=0;i<n;i++){
			//ans=max(ans,map[i]);
	  //}
	  ans=map[0];
	  cout<<ans<<endl;
	  free(t);
	  free(p);
	  free(map);
  }
	return 0;
}
