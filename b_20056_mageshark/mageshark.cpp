#include<iostream>
#include<ctime>
#define debug
#define FILENAME "b_20056_mageshark/mageshark_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
//보통 ?�산??1?�에 1초이지�?
//?�순 ?�식계산, 메모�??�근, ?�료구조???�라 ?�산?��? ???�어?�거??줄어?????�다.
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
