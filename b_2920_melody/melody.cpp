#include<iostream>
#define debug
#define FILENAME "2920_melody/melody_in.txt"
#define FILE_CIN
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		int tt[8]={0,};
		for(int i=0;i<8;i++)
			cin>>tt[i];
		int i=0;
		string status="";//0 ascending, 1 descending, 2 mixed
		while(i<7){
			int t=tt[i];
			if(i==0){
				if(t-tt[i+1]==1)
					status="descending";
				else if(t-tt[i+1]==-1)
					status="ascending";
				else
					status="mixed";
			}
			else{
				if(status=="descending")
					if(t-tt[i+1]!=1){
						status="mixed";
						break;
					}
				if(status=="ascending")
					if(t-tt[i+1]!=-1){
						status="mixed";
						break;
					}
			}
			i++;
		}
		cout<<status<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
