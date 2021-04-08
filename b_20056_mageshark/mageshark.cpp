#include<iostream>
#include<ctime>
#define debug
#define FILENAME "b_20056_mageshark/mageshark_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
//ë³´í†µ ?°ì‚°??1?µì— 1ì´ˆì´ì§€ë§?
//?¨ìˆœ ?˜ì‹ê³„ì‚°, ë©”ëª¨ë¦??‘ê·¼, ?ë£Œêµ¬ì¡°???°ë¼ ?°ì‚°?‰ì? ???˜ì–´?˜ê±°??ì¤„ì–´?????ˆë‹¤.
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
