#include<iostream>
#include<vector>
using namespace std;
//EOF를 감지하여 데이터 입력을 제한하는 코드
/*
입력:
1 엔터
2 엔터
3 엔터
4 엔터
5 엔터
ctrl+z 엔터
출력:
1
2
3
4
5
*/
int main(){
    vector<string> vs;
    string s;
    cin>>s;
    while(cin.eof()!=true){
        vs.push_back(s);
        cin>>s;
    }
    for(int i=0;i<vs.size();i++)
	    cout<<vs[i]<<'\n';
}