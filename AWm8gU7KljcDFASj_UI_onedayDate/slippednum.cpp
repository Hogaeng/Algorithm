//입력:
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 수의 길이를 의미하는 정수 N(1 ≤ N ≤ 100)이 주어진다.

//출력:
//각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,
//길이가 N인 삐끗 수의 개수를 10억으로 나눈 나머지를 출력하라.

/*
   조건:
   “오늘 하루가 지나기 전까지 0~9 숫자가 모두 등장하고,

   길이가 N인 삐긋 수들의 개수를 댓글로 가장 먼저 달아주신다면, 저와 함께 일일 데이트를 할 수 있습니다!”

   여기서 삐끗 수란 인접한 숫자가 1씩 차이나는 수를 말한다.

   예를 들면, 1232345 같은 수를 의미한다. 길이가 10인 삐끗 수 중에서 조건에 맞는 수는 9876543210 밖에 없다.

   단, 수는 0으로 시작할 수 없다.
 */

//11인 경우는 3가지
//아니면 10억에 3가지인가?
//9 8 7 6 5 4 3 2 1 0 1
//8 9 8 7 6 5 4 3 2 1 0
//1 0 1 2 3 4 5 6 7 8 9

//10억은 10초
//제한시간은 1초
//브루트포스 금지
//답은 9억이 나올수도 있다 예)50의 답은 9억이 넘음
//수학적으로 접근해야함.

//수학적이기 힘든게
//50은 989898.....210이 될수도 있다.
//결국 시뮬레이션 돌려야 한다는 이야기지만 연산량이 너무 많다.
//왼쪽은 0, 오른쪽은 1로 간다고 치면
//_10101010101.....111111로 가게 된다.
//진자운동에 의미가 있는가?

//어찌됐든 삐끗수이다
//중복되는 수는 아무래도 상관없다.
//오름차순과 내림차순에 수의 배열 사이사이에 삐끗수를 몇개를 넣어도 상관없다.(단 오름차순에선 0의 앞엔 반드시 하나의 수가 있어야 한다 == 1)
//1과 2 사이엔 21또는 또는 212121도 되고 234321이 들어가도 되고 1과5사이엔 234 또는 23234또는 234323234이 들어가도 된다.
//결국 점화식이라고 해야하나?
//1:9개
//2:17개
//아닌것 같다.


//솔루션 1:
//9 8 7 6 5 4 3 2 1 0 이라는 배열에서 끝은 막아놓고 다시 되돌아가는 코드를 짠다.
//체크하는 배열을 만들어놓고 전부가는지 확인
//연산량이 너무많아 배제

//솔루션 2:
//1~9자릿수에서 모든 수가 안나와도 좋으니 삐끗수의 갯수를 구해보자
//그 모듈을 이용해 0~9의 모든 수가 나온다고 상정하고 사이사이에 삐끗수를 넣어보자.
//1,2,3,4,5,6,7,8,9~8 중 n자리 삐끗수
//9,7~8,6 중 n자리 삐끗수
//21자리수 부터 중복
//98765432(10123456789)
//(9876543210)123456789

//11인 경우는 3가지
//98765432101
//89876543210
//10123456789

//12인 경우는
//(78)9876543210
//(98)9876543210
//9(89)876543210-중복
//98(78)76543210


//솔루션 3:
//마지막으로 특정수로 끝나는 자릿수는 한자리 낮은 자릿수의 특정수보다 1낮거나 높은 특정수로 끝나는 수를 모두 더하면 된다.
//하지만 모든 수가 나오는 공식은 좀더 세분화한 다이나믹 프로그래밍으로 다가가야 한다.



#include<iostream>
#include<vector>
#include<cmath>
#define debug
#define FILENAME "slippednum_in4.txt"
#define FILE_CIN
#define RHS 1000000000
#define Z 1
using namespace std;
int dp[101][10][2][2][2][2][2][2][2][2][2][2]={0,};
int lesser[] = {9,8,7,6,5,4,3,2,1,0};
int upper[] = {1,0,1,2,3,4,5,6,7,8,9};
vector<int> vec;
void printit(){
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<' ';
	cout<<'\n';
}
void _dpcheck(int n,int check[10]){
	if(n==-1){
		for(int j=0;j<10;j++){
			int *tmp=*********dp[Z][j];
			for(int i=0;i<10;i++)
				tmp+=(int)(pow(2,i)*check[i]);
			int k=0;
			for(int i=0;i<10;i++)
				if(check[i]==1)
					k++;
			if(k<2){
				cout<<j<<':';
				for(int i=0;i<10;i++)
					cout<<check[i];
				cout<<':'<<*tmp<<'\n';
			}
		}
		return;
	}
	check[n]=0;
	_dpcheck(n-1,check);
	check[n]=1;
	_dpcheck(n-1,check);
	return;
}
void printdp(){
	int check[10]={0,};
	_dpcheck(9,check);
}
void isallstuff(){
	int check[10]={0,};
	for(int i=0;i<vec.size();i++)
		check[vec[i]]=1;
	int *tmp=*********dp[vec.size()][vec[vec.size()-1]];
	for(int i=0;i<10;i++)
		tmp+=(int)(pow(2,i)*check[i]);
	*tmp+=1;
}
int _s_md(int n,int d,int c){
	int i;
	d?i=c+1:i=c-1;
	vec.push_back(lesser[i]);
	if(n==0){
#ifdef debug
		printdp();
#endif
		isallstuff();
		vec.pop_back();
		return 1;
	}
	int r=0;
	if(i!=9)
		r+=_s_md(n-1,1,i);
	if(i!=0)
		r+=_s_md(n-1,0,i);
	vec.pop_back();
	return r;
}
int s_md(int n){
	int r=0;
	for(int i=-1;i<8;i++){
		r+=_s_md(n-1,1,i);
	}
	return r;
}
int b_md(int n){
	int r=0;
	vector<int> desk;
	if(n==n%10){
		n=n-10;
		for(int i=0;i<n;i++){
			desk.push_back(s_md(i));
		}
	}
	else if(n==10){
		r=1;
	}
	else
		r=-1;
	return r;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		int tt;
		int result=0;
		cin>>tt;
		cout<<"#"<<z+1<<' ';
		result=s_md(tt);
		cout<<'r'<<result%RHS<<'\n';
#ifdef debug
		vec.clear();
#endif
#ifdef FILE_CIN
	}
#endif
	return 0;
}
