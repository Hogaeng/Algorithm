#include<vector>
#include<iostream>
using namespace std;
int check[20] = {0,};
int num=0;
void divide(int index, int size){
	if(num<size/2){
		if(check[index]==0){
			for(int i=index;i<size;i++){
				check[i]=1;
				num++;
				divide(i,size);
				check[i]=0;
				num--;
			}
		}
	}
	else{
		for(int i = 0;i<20;i++){
			cout<<check[i]<<' ';
		}
		cout<<'\n';
	}
}
int main(){
	freopen("tilt_in1.txt","r",stdin);
	int n;
	cin>>n;
	for(int z=0;z<n;z++)
	{
	  int abil[20][20];
	  int an;
	  cin>>an;
	  for(int i=0;i<an;i++)
		  for(int j=0;j<an;j++)
			  cin>>abil[i][j];
	  for(int i=0;i<an/2;i++){
		  divide(i,an);
	  }
  }
	return 0;
}
