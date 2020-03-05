#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
 
int n,L,R,k;
int arr[50][50];
int r[4] = {1,-1,0,0};
int c[4] = {0,0,1,-1};
int yun = 1;
int idong = 0;
int pop[3] = {0};
int yy[2500][2] = {0, };
int sw = 0;
int check[50][50] = {0, };
int newone[50][50] = {0, };
int ii = 0;

void init(){
yun = 1;
idong = 0;
pop[0] = 0;
pop[1] = 0;
pop[2] = 0;
	fill(yy[0],yy[2499]+2,0);
	sw = 0;
	fill(check[0],check[0]+50,0);
	fill(newone[0],newone[0]+50,0);
	ii = 0;
}

int yunhap(int a, int b, int c){
    if(a <= c && b >= c){
        sw = 1;
        return 1;
    }
    else{
        return 0;
    }
}

void dfs(int row, int col){
    if(check[row][col] == 0){
        check[row][col] = yun; // 방문
        yy[ii][0] = row;
        yy[ii][1] = col;
        pop[0] += arr[row][col];
        pop[1] += 1;
        
        for(int i = 0; i < 4; i++){
        // 인접한 노드를 방문
        // 상하좌우선택
        int newr = row + r[i];
        int newc = col + c[i];
        
            if(check[newr][newc]){
                // 방문한경우 다음꺼
                continue;
            }
            else if(newr < 0 || newc < 0 || newr > n-1 || newc > n-1){
                // 범위를 벗어나면 다음꺼
                continue;
            }
            else{
                // 비교
                int w = abs(arr[row][col] - arr[newr][newc]);
                if(yunhap(L,R,w)){
                    // 연합이 맞다면
                    ii += 1;
                    dfs(newr, newc);
                }
                else{
                    // 연합이 아니라면
                    continue;
                }
            }
        }
        // 모든 연합 체크 후에 인구나누기
    }
    else{
        return ;
    }
}

int main(){
    // 입력받기!
	freopen("pop_input2.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		init();
    cin >> n >> L >> R;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> k;
            arr[i][j] = k; 
        }
    }
    //첫줄부터 체크하기!
        do{
            idong += 1;
            sw = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dfs(i,j);
                    // 인구저장 초기화
                    if(pop[1] != 0){
                        for(int m = 0; m < pop[1]; m++){
                            newone[yy[m][0]][yy[m][1]] = pop[0] / pop[1];
                            yy[m][0] = 0;
                            yy[m][1] = 0;
                        }
                        pop[0] = 0;
                        pop[1] = 0;
                    }
                    ii = 0;
                    yun += 1;
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    arr[i][j] = newone[i][j];
                    check[i][j] = 0;
                    newone[i][j] = 0;
                }
            }
        }while(sw);

 // 디버깅 코드
    // cout << idong-1 << "\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << check[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    cout << idong-1;

	}
    return 0;
}
