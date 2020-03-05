#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int recVec(vector<int> &vec, int pivot, int cnt, bool check[10], int hn,int board[20][20]){
   int ret=0;
   if(cnt==2){
      int tmp[2];
      for(int i=0,tmpn=0;i<hn||tmpn<2;i++){
         if(check[i]==true){
         tmp[tmpn]=vec[i];
         tmpn++;
         }
      }
      //cout<<tmp[0]<<tmp[1]<<'\n';
      return board[tmp[0]][tmp[1]]+board[tmp[1]][tmp[0]];
   }
   for(int i=pivot;i<vec.size();i++){
      cnt++;
      check[i]=true;
      ret+=recVec(vec,i+1,cnt,check, hn,board);
      check[i]=false;
      cnt--;
   }
   return ret;
}
int calc(bool check[20], int board[20][20],int n){
   vector<int> one;
   vector<int> zero;
   for(int i=0;i<n;i++){
      if(check[i]==1)
      one.push_back(i);
      else
      zero.push_back(i);
   }
   bool check2[10]={0,};
   int k = abs(recVec(one,0,0,check2,n/2,board)-recVec(zero,0,0,check2,n/2,board));
   return k;
}
int recComb(int n,int cnt,int pivot, int board[20][20],bool check[20]){
   int ret=pow(2,31)-1;
   if(cnt==n/2){
      ret=calc(check,board,n);
      return ret;
   }
   for(int i=pivot;i<n;i++)
   {
      check[i]=true;
      cnt++;
      ret=min(ret,recComb(n,cnt,i+1,board,check));
      cnt--;
      check[i]=false;
   }
   return ret;
}
int main(void)
{
   freopen("sl_input.txt","r",stdin);
   int tmp;
   cin>>tmp;
   for(int z=0;z<tmp;z++)
   {
      int n;
      int board[20][20];
      cin>>n;
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            cin>>board[i][j];
      vector<int> one;
      vector<int> zero;
      bool check[20]={0,};
      int ret = recComb(n,0,0,board,check);
      cout<<ret<<'\n';
   }
}

