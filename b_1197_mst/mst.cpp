#include<iostream>
#include<ctime>
#define debug
#define FILENAME "b_1197_mst/mst_in.txt"
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
        clock_t start=clock();
        cout<<elapsedseconds(start)<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
