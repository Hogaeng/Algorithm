#include<iostream>
#include<vector>
using namespace std;
enum {RED, BLACK, HOLE, SHARP, DOT};
char icon[]= {'R','B','O','#','.'};
typedef struct board{
vector< vector<char> > board;
int row;
int col;
}Board;
typedef struct pos{
    int x;
    int y;
    void print(int i)
    {
	cout<<icon[i]<<endl;
	cout<<"  x:"<<x<<endl;
	cout<<"  y:"<<y<<endl;
    }
}Pos;
void setpos(Pos pos[3], Board& board)
{
    vector<char> tmp;
    for(int i=0;i<board.row;i++)
    {
	for(int j=0;j<board.col;j++)
	{
	    if(board.board[i][j]==icon[BLACK])
	    {
		pos[BLACK].x=i;
		pos[BLACK].y=j;
	    }
	    else if(board.board[i][j]==icon[RED])
	    {
		pos[RED].x=i;
		pos[RED].y=j;
	    }
	    else if(board.board[i][j]==icon[HOLE])
	    {
		pos[HOLE].x=i;
		pos[HOLE].y=j;
	    }
	}
    }
}
int trytilt(Pos pos[3], Board& board)
{
    Pos black=pos[BLACK];
    Pos red=pos[RED];
    Pos hole=pos[HOLE];

    int bx = black.x;
    int by = black.y;
    int rx = red.x;
    int ry = red.y;
    while(bx>2 && board.board[bx-1][by] == icon[DOT])
	bx-=1;
    while(rx>2 && board.board[rx-1][ry] == icon[DOT]){
	rx-=1;
    }
    while(bx<board.col-2 && board.board[bx+1][by] == icon[DOT])
	bx+=1;
    while(rx<board.col-2 && board.board[rx+1][ry] == icon[DOT]){
	rx+=1;
    }
    while(by>2 && board.board[bx][by-1] == icon[DOT])
	by-=1;
    while(ry>2 && board.board[bx][ry-1] == icon[DOT]){
	ry-=1;
    }
    while(by<board.row-2 && board.board[bx][by+1] == icon[DOT])
	by+=1;
    while(ry<board.row-2 && board.board[rx][ry+1] == icon[DOT]){
	ry+=1;
    }
    return 0;
}
void printpos(Pos pos[3])
{
    for(int i=0;i<3;i++)
	pos[i].print(i);
}
void initboard(Board &board)
{
    char *tmp = (char *)malloc((board.col)*sizeof(char));
    for(int i=0;i<board.row;i++)
    {
	cin >> tmp;
	vector<char> ele;
	for(int j=0;j<board.col;j++)
	    ele.push_back(tmp[j]);
	board.board.push_back(ele);
    }
}
void printboard(Board &board){
    for(int i=0;i<board.row;i++){
	for(int j=0;j<board.col;j++)
	    cout<<board.board[i][j];
	cout<<endl;
    }
}
int main()
{
    int tmp;
    {
	Board board;
	cin>>board.row;
	cin>>board.col;
	initboard(board);
	printboard(board);


	Pos pos[3];
	setpos(pos,board);
	printpos(pos);
    }
}
