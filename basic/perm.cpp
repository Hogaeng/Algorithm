#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int cnt=0;
//중복순열 : 그냥 무조건 for문 내 i 값을 받아 돌려버림.
void rperm(int lev, int m, int n, int check[10]){
    if(lev==n){
	for(int i=0;i<n;i++){
	    cout<<check[i]<<' ';
	}
	cout<<endl;
	cnt++;
	return;
    }
    for(int i=0;i<m;i++){
	check[lev]=i+1;
	rperm(lev+1,m,n,check);
	check[lev]=0;
    }
}
//순열1 : 초기값으로 제공된 배열에서 하나하나 뽑아 새롭게 배치하는 방식으로 구현.
void perm(int lev, int m, int n, vector<int> vec, int check[10]){
    if(lev==n){
	for(int i=0;i<n;i++){
	    cout<<check[i]<<' ';
	}
	cout<<endl;
	cnt++;
	return;
    }
    for(int i=0;i<m-lev;i++){
	check[lev]=vec[i];
	vec.erase(vec.begin()+i);
	perm(lev+1,m,n,vec,check);
	vec.insert(vec.begin()+i,check[lev]);
    }
}
void swap(vector<int> &vec, int i, int j){
    int tmp=vec[i];
    vec[i]=vec[j];
    vec[j]=tmp;
}

//순열2 : 초기값으로 오른차순으로 된 배열을 순차적으로 자리를 바꿔 구현.
void perm2(int lev, int m, int n, vector<int> vec){
    if(lev==n){
	for(int i=0;i<n;i++){
	    cout<<vec[i]<<' ';
	}
	cout<<endl;
	cnt++;
	return;
    }
    for(int i=lev;i<m;i++){
	swap(vec,lev,i);
	perm2(lev+1,m,n,vec);
	swap(vec,lev,i);
    }
}
//조합: ind는 for문의 i를 초기화 하는데 필요. 그 이후 재귀호출 할 땐 i를 넣어 전번째 수가 나오지 않도록 함.
void comb(int lev, int ind, int m, int n, vector<int> vec){
    if(lev==n){
	for(int i=0;i<n;i++){
	    cout<<vec[i]<<' ';
	}
	cout<<endl;
	cnt++;
	return;
    }
    for(int i=ind;i<m;i++){
	vec.push_back(i+1);
	comb(lev+1,i+1,m,n,vec);
	vec.erase(vec.end()-1);
    }
}
//중복조합: ind는 for문의 i를 초기화 하는데 필요. 그 이후 재귀호출 할 땐 i를 넣어 전번째 수가 하나만 오도록 함.
void rcomb(int lev, int ind, int m, int n, vector<int> vec){
    if(lev==n){
	for(int i=0;i<n;i++){
	    cout<<vec[i]<<' ';
	}
	cout<<endl;
	cnt++;
	return;
    }
    for(int i=ind;i<m;i++){
	vec.push_back(i+1);
	rcomb(lev+1,i,m,n,vec);
	vec.erase(vec.end()-1);
    }
}
int main(void){
    int check[10]={0,};
    //rperm(0,5,5,check);
    vector<int> vec;
    for(int i=1;i<=5;i++){
	vec.push_back(i);
    }
    perm(0,5,3,vec,check);
    cout<<cnt<<endl;
    cnt=0;

    perm2(0,5,3,vec);
    cout<<cnt<<endl;
    cnt=0;
    
    vec.clear();
    comb(0,0,5,3,vec);
    cout<<cnt<<endl;
    cnt=0;
    
    vec.clear();
    rcomb(0,0,5,3,vec);
    cout<<cnt<<endl;
    cnt=0;
    
    rperm(0,5,3,check);
    cout<<cnt<<endl;
    cnt=0;
}
