#include<iostream>
#include<vector>
#define debug 3
#define FILENAME "forager_firegalaxy/firegalaxy_in.txt"
#define FILE_CIN
using namespace std;
//풀이
//문제의 보이는 부분의 주변만 후보키로 등록+순열을 고친 조합으로 brute-force하는 방법
//장점
//전버전보다 약간 적은 연산량
//단점
//모든 케이스를 체크하지 못해 boardcheck_adv의 기능이 특정 문제에선 유명무실함.
//6수 이후로 1000m/s 이상 걸림
//전버전과 체감상 속도가 달라지지 않음
int dir[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
bool goal=false;
bool answer=false;
int step;
int cnt=0;
void printaddition(vector<pair<int,int> > vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i].first+1<<':'<<vec[i].second+1<<' ';
    cout<<endl;
}
bool boardcheck_adv(bool board[6][6]){
    bool chkb[6][6]={0,};
    int n=6;
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
vector<pair<int,int> > makedesk(bool board[6][6]){
    int n=6;
    vector<pair<int,int> > ret;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            bool isnotgoal=false;
            for(int k=0;k<5;k++){
                int di=dir[k][0]+i, dj=dir[k][1]+j;
                if(di>-1&&di<n&&dj>-1&&dj<n)
                    if(board[di][dj]!=goal){
                        isnotgoal=true;
                        break;
                    }
            }
            if(isnotgoal){
                ret.push_back(make_pair(i,j));
            }
        }
    return ret;
}
void pushit(bool b[6][6], pair<int,int> ele){
    int i=ele.first, j=ele.second;
    int n=6;
    for(int k=0;k<5;k++){
        int di=dir[k][0]+i, dj=dir[k][1]+j;
        if(di>-1&&di<n&&dj>-1&&dj<n)
            b[di][dj]=!b[di][dj];
    }
}
bool checkanswer(bool board[6][6]){
    int n=6;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(board[i][j]!=goal)
                return false;
        }
    return true;
}
int calc(pair<int,int> &ele){
    return ele.first*6+ele.second;
}
void printdebug(vector<pair<int,int> > vec){
    if(debug==step){
        if(calc(vec[0])==2){
            for(int i=0;i<vec.size();i++)
            cout<<calc(vec[i])<<' ';
            cout<<endl;
        }
        vector<int> answervec;
        
        answervec.push_back(2);
        answervec.push_back(3);
        answervec.push_back(28);
        
        bool isanswervec=true;
        for(int i=0;i<answervec.size();i++)
            if(answervec[i]!=calc(vec[i])){
                isanswervec=false;
                break;
            }
        if(isanswervec){
            for(int i=0;i<vec.size();i++)
                cout<<calc(vec[i])<<' ';
            cout<<endl;
        }
    }
}
void recur(int lev, vector<pair<int, int> > &vec,bool board[6][6]){
    if(answer)
        return;
    if(lev<1){
        printdebug(vec);
        if(boardcheck_adv(board)){
            for(int i=0;i<vec.size();i++)
                cout<<vec[i].first<<':'<<vec[i].second<<' ';
            cout<<endl;
            answer=true;
        }
        cnt++;
    }
    else{
        vector<pair<int,int> > desk=makedesk(board);
        for(int i=0;i<desk.size();i++){
            if(vec.size()<1||calc(vec[vec.size()-1])<calc(desk[i])){
                int n=6;
                bool b[6][6]={0,};
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        b[i][j]=board[i][j];
                vec.push_back(desk[i]);
                pushit(b,desk[i]);
                recur(lev-1, vec, b);
                vec.erase(vec.begin()+vec.size()-1);
            }
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
        bool board[6][6];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>board[i][j];
        vector<pair<int,int> > vec;
        for(int i=0;i<37;i++){
            cout<<"step"<<i<<endl;
            step=i;
            recur(i,vec,board);
            if(answer)
                break;
            vec.clear();
            cout<<cnt<<endl;
            cnt=0;
        }
#ifdef FILE_CIN
    answer=false;
	}
#endif
	return 0;
}