#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define debug
#define FILENAME "phonnum_in.txt"
#define FILE_CIN
using namespace std;
bool solution(vector<string> phoneBook) {
    bool answer = true;
    sort(phoneBook.begin(), phoneBook.end());
    cout<<phoneBook[0]<<endl;
    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        string we = phoneBook[i+1].substr(0,phoneBook[i].size());
        if ( phoneBook[i] ==  we)
        {
            cout <<phoneBook[i]<<' '<<phoneBook[i+1]<<endl;
            answer = false;
            break;
        }
    }

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
