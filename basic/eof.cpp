#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string> vs;
    string s;
    cin>>s;
    do{
	vs.push_back(s);
	cin>>s;
    }while(cin.eof()!=true);
    int n=vs.size();
    for(int i=0;i<n;i++)
	cout<<vs[i]<<'\n';
}
