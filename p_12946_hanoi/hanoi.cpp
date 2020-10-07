#include <string>
#include <vector>
using namespace std;
int dir[6][3] = {
    {1,2,3},
    {1,3,2},
    {2,3,1},
    {3,2,1},
    {2,1,3},
    {3,1,2}
};
int lookup[6][2]={
    {1,3},
    {0,2},
    {4,1},
    {5,0},
    {2,5},
    {3,4}
};
vector<vector<int>> oldy[6];
vector<vector<int>> newy[6];
vector<vector<int>> recur(int lev){
    if(lev==2){
        for(int i=0;i<6;i++){
            int s=dir[i][0];
            int e=dir[i][1];
            int o=dir[i][2];
            vector<int> tmp;
            tmp.push_back(s);
            tmp.push_back(o);
            oldy[i].push_back(tmp);
            newy[i].push_back(tmp);
            tmp.clear();
            tmp.push_back(s);
            tmp.push_back(e);
            oldy[i].push_back(tmp);
            newy[i].push_back(tmp);
            tmp.clear();
            tmp.push_back(o);
            tmp.push_back(e);
            oldy[i].push_back(tmp);
            newy[i].push_back(tmp);
            tmp.clear();
        }
    }
    else{
        recur(lev-1);
        for(int i=0;i<6;i++){
            int s=dir[i][0];
            int e=dir[i][1];
            int o=dir[i][2];
            vector<vector<int>> tmp[3];
            tmp[0]=oldy[lookup[i][0]];
            tmp[1]=oldy[lookup[i][1]];
            for(int j=0;j<tmp[0].size();j++)
            {
                tmp[2].push_back(tmp[0][j]);
            }
            vector<int> intermid;
            intermid.push_back(s);
            intermid.push_back(e);
            tmp[2].push_back(intermid);
            for(int j=0;j<tmp[1].size();j++)
            {
                tmp[2].push_back(tmp[1][j]);
            }
            newy[i].clear();
            for(int j=0;j<tmp[2].size();j++)
                newy[i].push_back(tmp[2][j]);
        }
        for(int i=0;i<6;i++){
            oldy[i].clear();
            for(int j=0;j<newy[i].size();j++)
                oldy[i].push_back(newy[i][j]);
        }
    }
    return newy[1];
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer=recur(n);
    return answer;
}
