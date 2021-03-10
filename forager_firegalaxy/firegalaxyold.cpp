#include<iostream>
#include<vector>
//#define debug
#define FILENAME "forager_firegalaxy/firegalaxy_in.txt"
#define FILE_CIN
using namespace std;
//규칙
//1. 바로 전 키를 누르면 원복한다. 예) 0,0을 누르고 또 0,0을 누르면 전상태로 돌아간다.
//2. 전에 눌렀던 키들을 반복하여 누르면 원복한다. 반복하여 누를땐 순서에 상관없이 눌러도 반복한 것으로 간주한다.
//예) {1,1},{2,2},{3,3}을 누르고 {2,2},{1,1},{3,3}을 눌러도 전상태로 돌아간다.
//3. 모든 키는 서로 영향을 주지 않는다. 단지 홀수번 작동되었느냐 짝수번 작동되었는냐의 차이 뿐이다.
//예) {1,1},{2,2},{1,1},{3,3}과 {2,2},{3,3}은 같은 의미이다.

//풀이
//조합으로 brute-force하는 방법
//단점
//6수 이후로 연산시간이 1000ms이상 걸린다.
int cnt=0;
int dir[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int limt=12;
bool answer=false;
bool goal=false;
int step;
void printaddition(vector<pair<int,int> > vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i].first+1<<':'<<vec[i].second+1<<' ';
    cout<<endl;
}
bool boardcheck_adv(bool board[6][6],int n,vector<int> vec){
    bool chkb[6][6]={0,};
    vector<pair<int, int> > addition;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            bool flag=true;
            bool pivot=!goal;
            if(!chkb[i][j])
                for(int k=0;k<5;k++){
                    int dx=i+dir[k][0],dy=j+dir[k][1];
                    if(dx>-1&&dx<n&&dy>-1&&dy<n){
                        if(chkb[dx][dy] || board[dx][dy]!=pivot){
                            flag=false;
                            break;
                        }
                    }
                }
            else
                continue;
            if(flag){
                addition.push_back(make_pair(i,j));
                for(int k=0;k<5;k++){
                    int dx=i+dir[k][0],dy=j+dir[k][1];
                    if(dx>-1&&dx<n&&dy>-1&&dy<n)
                        chkb[dx][dy]=true;
                }
            }            
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(chkb[i][j])
               continue;
            else
            {
                if(board[i][j]==!goal){
                    return false;
                }
            }
        }
    printaddition(addition);
    return true;
}
void printboard(bool board[6][6],vector<int> vec, int k){
    for(int i=0;i<k;i++)
        cout<<vec[i]/6+1<<':'<<vec[i]%6+1<<' ';
    cout<<endl;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++)
            cout<<board[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
int boardmove(bool board[6][6], int n, vector<int> vec){
    bool b[6][6];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            b[i][j]=board[i][j];
    for(int i=0;i<vec.size();i++){
        /*
        if(boardcheck_adv(b,n)){
            printboard(b, vec, i);
            return i;
        }
        */
        for(int j=0;j<5;j++){
            int dx=vec[i]/6+dir[j][0],dy=vec[i]%6+dir[j][1];
            if(dx>-1&&dx<n&&dy>-1&&dy<n)
                b[dx][dy]=!b[dx][dy];
        }
    }
#ifdef debug
    //printboard(b, vec, vec.size());
#endif
    if(boardcheck_adv(b,n,vec)){
        printboard(b, vec, vec.size());       
        return vec.size();
    }
    return -1;
}
void printdebug(vector<int> vec){
    if(step==3){
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<' ';
        cout<<endl;
    }
}
void recur(int n, int lev,int pivot,vector<int> &vec,bool board[6][6]){
    if(answer)
        return;
    if(lev==0){
#ifdef debug
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<' ';
        cout<<endl;
#endif
        int k;
        if((k=boardmove(board,6,vec))>-1){
            answer=true;
            return;
        }
        //printdebug(vec);
        cnt++;
    }
    else{
        for(int i=pivot;i<n;i++){
            vec.push_back(i);
            recur(n,lev-1,i+1,vec,board);
            vec.erase(vec.begin()+vec.size()-1);
        }
    }
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
        
#endif
        int n=6;
        bool b[6][6];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>b[i][j];
        vector<int> vec;
        for(int i=0;i<=limt;i++){
            cout<<"step"<<i<<endl;
            step=i;
            recur(n*n,i,0,vec,b);
            vec.clear();
            if(answer)
                break;
            cout<<cnt<<endl;
            cnt=0;
        }
        
        //recur(n*n,9,0,vec,b);
        //recur(n*n,10,0,vec,b);
        //recur(n*n,11,0,vec,b);
        //recur(n*n,12,0,vec,b);
        //cout<<"step"<<':'<<13<<endl;
        //recur(n*n,13,0,vec,b);
#ifdef FILE_CIN
    cnt=0;
    answer=false;
	}
#endif
	return 0;
}
