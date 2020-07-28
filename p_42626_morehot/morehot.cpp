#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define debug
#define FILENAME "morhot_in.txt"
#define FILE_CIN
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    int max = scoville.size();
    /*
    for(int i = 0; i<max;i++)
    {
        q.push(scoville[i]);
        //cout << scoville[i]<<endl;
    }
    */
    for(int n : scoville)
        q.push(n);
    while (q.size()>1)
    {
        if (q.top() < K)
        {
            int smallest = q.top();
            q.pop();
            int nextsmallest = q.top();
            q.pop();
            q.push(smallest + nextsmallest*2);
            answer++;
        }
        else
            break;
    }
    if (q.size() == 1)
        answer = -1;
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
