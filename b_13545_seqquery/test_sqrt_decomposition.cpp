//Sqrt Decomposition
//for Mo's algorithm
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Query{
    int lo;
    int hi;
};
int main(void){
    vector<Query> q;
    Query qs[4]={1,8,1,6,1,4,1,2};
    for(int i=0;i<4;i++)
	q.push_back(qs[i]);
    int n=10;
    int sz=sqrt(n);
    sort(q.begin(),q.end(),[&](const Query& l, const Query& r) {
      // 쿼리가 끝나는 부분이 어떠한 묶음에 속하는지 확인하다
      // 묶음의 인덱스가 더 작은곳에 속하는 쿼리를 먼저 처리한다
      // 만약 묶음의 인덱스가 같다면 쿼리의 시작지점이 작은것을 먼저 처리한다
      int lIdx = l.hi / sz;
      int rIdx = r.hi / sz;
      return lIdx == rIdx ? l.lo <= r.lo : lIdx < rIdx;
    });
    for(int i=0;i<4;i++)
	cout<<q[i].lo<<' '<<q[i].hi<<' ';
    cout<<endl;
}

