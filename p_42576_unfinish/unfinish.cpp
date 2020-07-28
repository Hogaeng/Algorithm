#include<iostream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#define debug
#define FILENAME "unfinish_in.txt"
#define FILE_CIN
using namespace std;
void showme(unordered_multiset<string> &us){
    for(int i=0;i<us.bucket_count();i++){
        cout<<i<<':';
    for(auto iter = us.begin(i);iter!=us.end(i);iter++)
        cout<<","<<*iter;
    cout<<'\n';
    }
}
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> us(participant.begin(),participant.end());
    showme(us);
    //auto iter = us.begin();
    int i;
    for(string s: completion){
        i= us.erase(s);
        if(i>1){
            for(int j= 0 ;j<i-1;j++)
                us.insert(s);
        }
    }

    for(string s: us)
        answer=s;
    return answer;
}
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
