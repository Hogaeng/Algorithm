#include<iostream>
#include<vector>
#define debug
#define FILENAME "eoff_in.txt"
#define FILE_CIN
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    cout<<'t'<<z<<endl;
	    vector<string> vs;
	    string s;
	    cin>>s;
	    do{
		vs.push_back(s);
		cin>>s;
	    }while(cin.eof()!=true);
	    for(int i=0;i<vs.size();i++)
		cout<<(int)vs[i][0]<<'\n';
#ifdef FILE_CIN
	}
#endif
	return 0;
}
