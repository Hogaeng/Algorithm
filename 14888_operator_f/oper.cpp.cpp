#include<iostream>
#include<vector>
#include<math.h>
enum {P,M,T,D};
using namespace std;
void makedst(short &c, int n,int dst){
	int one=0;
	while(c!=0){
		bitset<16> b(c);
		for(int i=0;i<n;i++){
			if(b[i]==1)
				one++;
		}
		if(one==dst)
			break;
		one=0;
		c--;
	}
}
void calc(vector<int> subc[4], int caten, vector<int> subp, vector<int> &p){
	short size[4];
	for(int i=0;i<caten;i++){
		size[i]=pow(2,subp.size()+subc[4].size())-1;
		makedst(size, subp.size()+subc.size(), subc[i].size());
	}
	while(size!=0)
	{
	  bitset<16> b(size);

		makedst(size, subp.size()+subc.size(), subp.size());
  }
}
int main(){
	freopen("oper_input.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		int oper[4];
		int n;
		int num[11];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		for(int i=0;i<4;i++){
			cin>>oper[i];
		}
		vector<int> subp;
		vector<int> subc[4];
		int caten=0;
		vector<int> p;
		for(int i=0;i<4;i++){
			if(oper[i]>1){
				caten++;
				for(int j=0;j<oper[i];j++)
					subc[i].push_back(i);
			}
			else if(oper[i]==1)
				subp.push_back(i);
		}
		/*
		for(int i=0;i<subp.size();i++)
			cout<<subp[i];
		cout<<' ';
		for(int i=0;i<subc.size();i++)
			cout<<subc[i];
		cout<<endl;
		*/
		calc(subc, caten, subp, p);
	}
	return 0;
}
