#include<iostream>
#define debug
#define FILENAME "19237_adultshark/adultshark_in.txt"
#define FILE_CIN
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
#ifdef FILE_CIN
	}
#endif
	return 0;
}
