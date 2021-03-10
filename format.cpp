#include<iostream>
#include<ctime>
#define debug
#define FILENAME "00000_format/format_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
//보통 연산량 1억에 1초이지만
//단순 수식계산, 메모리 접근, 자료구조에 따라 연산량은 더 늘어나거나 줄어들 수 있다.
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
        clock_t start=clock();
        cout<<elapsedseconds(start)<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}