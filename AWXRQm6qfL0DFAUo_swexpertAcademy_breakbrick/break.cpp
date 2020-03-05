#include<iostream>
#include<vector>
#define FILENAME "break_in.txt"
#define FILE_CIN
using namespace std;
int N,W,H;
int brick[12][15]={0,};
void swipe(){
	//topview.clear();
}
void demolish(int **cbrick, int x, int y){
	int tmp=cbrick[x][y];
	cbrick[x][y]=0;
	for(int i=1;i<value;i++){
		demolish(int **cbrick, x+i, y);
		demolish(int **cbrick, x, y+i);
		demolish(int **cbrick, x-i, y);
		demolish(int **cbrick, x, y-i);
	}
}
void gravitity(int **cbrick){
}
int bf(int k, int **tbrick){
	int cbrick[12][15];
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			cbrick[i][j]=tbrick[i][j];
	demolish
	return cnt;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		int cnt=0;
		cin>>N>>W>>H;
		for(int i=0;i<H;i++)
			for(int j=0;i<W;j++)
				cin>>brick[i][j];
		for(int i=0;i<N;i++)
			cnt+=bf(0);
		cout<<'#'<<z<<' '<<cnt<<'\n';
#ifdef FILE_CIN
	}
#endif
	return 0;
}
