#include<iostream>
#define FILE_CIN
#define FILENAME "yut_in4.txt"
#define endl "\n"
#define MAX 10
using namespace std;
 
struct STATE            // 움직임에 대한 정보를 받아오는 구조체
{
    int Prev;            // 현재 칸
    int Next;            // 이동하려는 칸
    int Start_Circle;    // 시작한 파랑원의 번호(1, 2, 3 중 하나)
    bool Select_Circle;    // 이번 움직임으로 파랑색 원의 번호가 결정되었는지에 대한 여부판단
    bool Finish;        // 이번 움직임으로 윷이 도착점에 도달하였는지에 대한 여부판단
};
 
struct YUT
{
    int Blue_Circle;    // 윷이 한번이라도 시작한 파랑색 원의 번호
    int Pos;            // 윷의 정보
    int Score;            // 윷의 점수
    bool Finish;        // 윷이 도착점에 도달했는지에 대한 여부
};
 
int Answer;
int Command[MAX];
int MoveNum[4];                // 각 경로 별, 움직여야 하는 최대 칸수를 저장하는 배열
int MAP_Score[4][30];        // 점수 판
bool Visit[4][30];            // 이미 다른 윷이 있는지 없는지 판단하기 위한 배열
bool Special_Point[4][30];    // 특별한 점 (모든 경로가 겹치는 칸들)
 
YUT Yut[4];
 
void Setting()
{
    /* 기초 세팅 작업 */
    /* 
    1. 각 경로 별 움직여야 하는 최대 칸수를 저장하는 배열 Move_Num에 값 삽입.
       2. 특별한 점들 체크.
       3. 점수 판 만들기
    */
    for(int i=0;i<4;i++){
	Yut[i].Blue_Circle=0;
	Yut[i].Pos=0;
	Yut[i].Score=0;
	Yut[i].Finish=false;
    }
    for(int i=0;i<4;i++)
	for(int j=0;j<30;j++)
	    Visit[i][j]=false;
    Answer=0;
    MoveNum[0] = 21;
    MoveNum[1] = 13;
    MoveNum[2] = 17;
    MoveNum[3] = 23;
 
    Special_Point[1][9] = Special_Point[1][10] = Special_Point[1][11] = Special_Point[1][12] = true;
    Special_Point[2][13] = Special_Point[2][14] = Special_Point[2][15] = Special_Point[2][16] = true;
    Special_Point[3][19] = Special_Point[3][20] = Special_Point[3][21] = Special_Point[3][22] = true;
    Special_Point[0][1] = Special_Point[0][2] = Special_Point[0][3] = Special_Point[0][4] = Special_Point[0][5] = Special_Point[0][20] = true;
 
    for (int i = 1; i <= 20; i++) MAP_Score[0][i] = 2 * i;
    MAP_Score[1][6] = 13; MAP_Score[1][7] = 16; MAP_Score[1][8] = 19; MAP_Score[1][9] = 25;
    MAP_Score[1][10] = 30; MAP_Score[1][11] = 35; MAP_Score[1][12] = 40;
    MAP_Score[2][11] = 22; MAP_Score[2][12] = 24; MAP_Score[2][13] = 25; MAP_Score[2][14] = 30;
    MAP_Score[2][15] = 35; MAP_Score[2][16] = 40;
    MAP_Score[3][16] = 28; MAP_Score[3][17] = 27; MAP_Score[3][18] = 26; MAP_Score[3][19] = 25;
    MAP_Score[3][20] = 30; MAP_Score[3][21] = 35; MAP_Score[3][22] = 40;
 
    for (int i = 1; i <= 5; i++) MAP_Score[1][i] = MAP_Score[0][i];
    for (int i = 1; i <= 10; i++) MAP_Score[2][i] = MAP_Score[0][i];
    for (int i = 1; i <= 15; i++) MAP_Score[3][i] = MAP_Score[0][i];
}
 
void Input()
{
    for (int i = 0; i < 10; i++) cin >> Command[i];
}
 
STATE GetState(int Idx, int C_Idx)
{
    /* 현재의 움직임으로 변하는 윷의 상태를 받아오는 함수 */
    int Prev = Yut[Idx].Pos;                    // 윷이 현재 있는 칸
    int Next = Yut[Idx].Pos + Command[C_Idx];    // 윷이 이동하려는 칸
    int Start_Circle = Yut[Idx].Blue_Circle;    // 기존에 시작한 파랑색 원의 번호
    bool Select_Circle = false;                    // 이번 턴의 움직임으로 인해 파랑색 원이 결정되었는지에 대한 여부
    bool Finish = false;                        // 이번 턴의 움직임으로 인해 도착점에 도달했는지에 대한 여부
 
    if (Start_Circle == 0)                        // 아직 시작한 파랑색 원이 없을 경우에만
    {
        if (Prev == 5 || Prev == 10 || Prev == 15)    // 파랑색 원에서 시작한다면
        {
            Select_Circle = true;                // 이번 턴의 움직임으로 파랑색 원이 결정되었다.
            Start_Circle = Prev / 5;            // 윷의 시작한 파랑색 원의 번호
        }
    }
 
    if (Next >= MoveNum[Start_Circle]) Finish = true;    // 도착점에 도달했다면 체크.
 
    return{ Prev, Next, Start_Circle, Select_Circle, Finish };
}
 
bool Check_Special_Point(int Circle, int Pos)
{
    /* 특별한 점에 다른 윷이 존재하는지 판단하는 함수 */
    if (Circle == 0)
    {
        /* 현재 이동하려는 윷이 파랑색 원에서 시작한 적이 없는 경우. */
        /* '40'점이 설정되어있는 칸에 기존에 윷이 있는지 판단해 주면 된다.
        /* '40'점이 있는 칸은, 빨강색, 파랑색, 초록색, 주황색 모두 겹치는 경로이기 때문 ! */
        if (Pos == 20)
        {
            if (Visit[1][12] == true || Visit[2][16] == true || Visit[3][22] == true) return false;
        }
        else
        {
            if (Visit[0][Pos] == true) return false;
        }
    }
    else if (Circle == 1)
    {
        /* 현재 윷이, 1번 파랑 원에서 시작해서 움직이고 있는 경우 */
        /* 빨강색 / 파랑색 / 주황색 경로가 겹치는 "25", "30", "35", "40" 을 체크해 주어야 한다. */
        if (Visit[2][Pos + 4] == true || Visit[3][Pos + 10] == true) return false;
        if (Pos == 12)
        {
            if (Visit[0][20] == true) return false;
        }
    }
    else if (Circle == 2)
    {
        if (Visit[1][Pos - 4] == true || Visit[3][Pos + 6] == true) return false;
        if (Pos == 16)
        {
            if (Visit[0][20] == true) return false;
        }
    }
    else if (Circle == 3)
    {
        if (Visit[1][Pos - 10] == true || Visit[2][Pos - 6] == true) return false;
        if (Pos == 22)
        {
            if (Visit[0][20] == true) return false;
        }
    }
    return true;
}
 
bool Check_Visit(STATE S, int Idx)
{
    /* 현재 윷이 움직일 수 있는지를 판단해주는 함수 */
    /* 판단해 줘야 할 것
       1. 움직이려는 좌표가 특별한 점인지 ?
          - 특별한 점이라면 다른 경로를 통해서 해당 좌표에 있는 놈들도 Check.
       2. 움직이려는 좌표에 다른 윷이 존재하는지 ? 
    */
    if (Special_Point[S.Start_Circle][S.Next] == true)
    {
        if (Check_Special_Point(S.Start_Circle, S.Next) == false) return false;
    }
 
    if (Visit[S.Start_Circle][S.Next] == true) return false;
    return true;
}
 
void MakeState(STATE S, int Idx, bool T)
{
    /* 방문 체크를 하고, 실제로 윷을 옮기는 함수. */
    /* T = true 일 경우, 실행 */
    /* T = false 일 경우, 실행 취소 */
 
    if (T == true)
    {
        if (S.Finish == true)
        {
            /* 현재 턴의 움직임으로 윷이 도착점에 도달했다면 ?? */
 
            Visit[S.Start_Circle][S.Prev] = false;    // 기존 좌표 방문 체크 해제
            Yut[Idx].Pos = S.Next;                    // 현재 윷의 좌표 갱신
            Yut[Idx].Finish = true;                    // 끝났음을 표시.
            // 마지막 좌표는 윷이 있어도 다른 윷이 올 수 있기 때문에, 해당 좌표에 방문표시는 하지 않음 ! 
        }
        else
        {
            /* 현재 턴의 움직임으로 윷이 도착점에 도달하지는 않은 경우 */
            if (S.Select_Circle == true)
            {
                /* 현재 턴의 움직임으로 파랑원의 번호가 결정 되었다면 ?*/
 
                Yut[Idx].Blue_Circle = S.Start_Circle;    // 윷의 파랑 원의 번호를 설정
                Visit[0][S.Prev] = false;                // 기존의 좌표 체크 해제.
                /* 이번 턴에 파랑원의 번호가 결정되었다 = 기존에는 파랑원이 결정되지 않은 상태였다. 
                   즉, 기존의 좌표 체크 해제는 파랑원이 결정되지 않은 Visit[0][S.Prev]로 해준다.
                */
            }
            else
            {
                /* 현재 턴의 움직임으로 파랑원의 번호가 결정되지 않았다. */
                /* 이미 정해져있었을 수도, 아니면 아직 정해지지 않은 것일수도 있다. */
 
                Visit[Yut[Idx].Blue_Circle][S.Prev] = false;
                /* 기존의 좌표 체크 해제. 파랑원이 기존에 정해졌는지 아직 안정해졌는지는 모르지만 
                   이번 턴에 결정되지는 않았으니까, Yut[Idx].BlueCircle 로 파랑원의 번호를 대체 */
            }
            Visit[Yut[Idx].Blue_Circle][S.Next] = true;    // 방문 체크
            Yut[Idx].Pos = S.Next;                        // 좌표갱신
            Yut[Idx].Score = Yut[Idx].Score + MAP_Score[Yut[Idx].Blue_Circle][S.Next]; // 점수갱신
        }
    }
    else
    {
        /* 실행 취소하는 과정 */
        if (S.Finish == true)
        {
            /* 이번 턴으로 윷이 도착점에 도달했다면 ? */
            Visit[S.Start_Circle][S.Prev] = true;    // 기존의 좌표 방문 체크
            Yut[Idx].Pos = S.Prev;                    // 좌표값 되돌리기
            Yut[Idx].Finish = false;                // 끝남표시 해제
        }
        else
        {
            if (S.Select_Circle == true)
            {
                /* 이번 턴으로 인해서 파랑색 원이 결정 되었는데, 이를 실행취소 한다. */
 
                Visit[0][S.Prev] = true;                        // 기존에는 아직 파랑원이 정해져 있지 않았는데, 그 좌표로 돌아가야 하므로 Visit[0][S.Prev]
                Visit[Yut[Idx].Blue_Circle][S.Next] = false;    
                Yut[Idx].Pos = S.Prev;
                Yut[Idx].Score = Yut[Idx].Score - MAP_Score[Yut[Idx].Blue_Circle][S.Next];
                Yut[Idx].Blue_Circle = 0;    // 선택한 파랑원의 번호 다시 0으로 갱신.
            }
            else
            {
                Visit[Yut[Idx].Blue_Circle][S.Prev] = true;
                Visit[Yut[Idx].Blue_Circle][S.Next] = false;
                Yut[Idx].Pos = S.Prev;
                Yut[Idx].Score = Yut[Idx].Score - MAP_Score[Yut[Idx].Blue_Circle][S.Next];
            }
        }
    }
}
 
void DFS(int Cnt)
{
    if (Cnt == 10)
    {
        int Temp = 0;
        for (int i = 0; i < 4; i++) Temp = Temp + Yut[i].Score;
 
        if (Answer < Temp) Answer = Temp;
        return;
    }
 
    for (int i = 0; i < 4; i++)
    {
        if (Yut[i].Finish == true) continue;
        STATE State = GetState(i, Cnt);
        if (Check_Visit(State, i) == false) continue;
 
        MakeState(State, i, true);
        DFS(Cnt + 1);
        MakeState(State, i, false);
    }
}
 
void Solution()
{
    DFS(0);
    cout << Answer << endl;
}
 
void Solve()
{
    Setting();
    Input();
    Solution();
}
 
int main(void)
{
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("Input.txt", "r", stdin);
	Solve();
#ifdef FILE_CIN
    }
    cout<<"right_answer"<<endl;
#endif
    return 0;
}
