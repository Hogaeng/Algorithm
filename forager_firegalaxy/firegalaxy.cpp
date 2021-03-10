#include<iostream>
#include<ctime>
#include<unordered_map>
#define debug
#define FILENAME "forager_firegalaxy/firegalaxy_in.txt"
#define FILE_CIN
#define elapsedseconds(start) (clock()-start)/(double)CLOCKS_PER_SEC
using namespace std;
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
    int n=6;
    clock_t start;
	for(int z=0;z<tmp;z++){
#endif
        
        bool boardb[6][6]={0,};
        int boardi[6][6]={0,};

        unordered_map<int,int> b;        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                b.insert(make_pair(i*6+j,0));
        // for(int i=0;i<100000000;i++)
        //     if(b[i%36]==0);
        //     b[i%36]++;
        
        start=clock();
        for(int i=0;i<100000000/36;i++)
            for(auto ele=b.begin();ele!=b.end();ele++)
                if(ele->second==0);
        cout<<elapsedseconds(start)<<endl;
        
        start=clock();
        for(int j=0;j<100000000;j++){
            int i=j%36;
            if(boardb[i/36][i%6]!=0);
            //boardb[i/36][i%6]=!boardb[i/6][i%6];
        }
        cout<<elapsedseconds(start)<<endl;
        start=clock();
        for(int j=0;j<100000000;j++){
            int i=j%36;
            if(boardi[i/36][i%6]!=0);
            //boardi[i/6][i%6]++;
        }
        cout<<elapsedseconds(start)<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}