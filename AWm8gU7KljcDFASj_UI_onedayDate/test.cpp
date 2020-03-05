#include<stdio.h>
#include<cmath>
int main(void){
	int dp[2][2][2]={0,};
	int *k = dp[0][0];
	int (*l)[2][2];
	int (*m)[2];
	int *n;
	int o;
	k[0]=1;
	printf("%d\n",dp[0][0][0]);
	k[0]=0;
	dp[1][1][1]=2;
	dp[1][0][0]=3;
	int c[3]={0,0,1};
	//for(int i=2;i>-1;i--)
		//l=dp+(int)(pow(2,i)*c[i]);
	l=dp+1;//양측 같은 3차원
	m=*l+1;//왼쪽 2차원, 오른쪽 3차원
	n=*m+1;//왼쪽 1차원, 오른쪽 2차원
	o=*n;//왼쪽 int형, 오른쪽 1차원
	printf("%d\n",o);
	//int dp[2][2][2]={0,};
	//int c[3]={0,0,1};
	//와 이렇게 간단하게 다차원 배열에 접근하는 방법이 있다니
	//난 왜 이걸 몰랐을까
	//자개감들고 개로워
	n=**dp;
	for(int i=0;i<3;i++)
		n+=(int)(pow(2,i)*c[i]);
	printf("%d\n",*n);
	int q=0;
	int*p=(int*)q;
}
