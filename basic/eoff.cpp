#include<iostream>
#include<vector>
#define debug
#define FILENAME "eoff_in.txt"
#define FILE_CIN
using namespace std;
//파일의 EOF를 감지하여 데이터 입력을 제한하는 코드
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    vector<string> vs;
	    string s;
	    cin>>s;
		while(cin.eof()!=true){
			vs.push_back(s);
			cin>>s;
		}
	    for(int i=0;i<vs.size();i++)
			cout<<vs[i]<<'\n';
#ifdef FILE_CIN
	}
#endif
	return 0;
}
