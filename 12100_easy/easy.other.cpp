#include<iostream>
using namespace std;
void check(int n, int map[20][20])
{
	int tmp[n][n] = {0,}
	int i_init;
	int i_end;
	int j_init;
	int j_end;
	for(int i=i_init; i<i_end;i++){
	  for(int j=j_init;j<j_end;j++){
		  tmp[i][j] = map[i][j]
	  }
  }
}
int main()
{
	int ans = 2;
	int map[20][20] = {0,};
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++)
			cin >> map[i][j];
  }
	check(n, map);
	return ans;
}
