/*
Time : 2022.01.27 (1h 30 mins)
Problem : BOJ14499 (https://www.acmicpc.net/problem/14499)
Algorithm Type : Simulation
Outline :
아래와 같은 모양의 주사위가 (x,y) 위치에 놓여져 있다.
   [2]
[4][1][3] <- [1]이 맨 위, [3]이 동쪽
   [5]
   [6] <- 바닥
주사위는 명령대로 동(1), 서(2), 북(3), 남(4) 방향으로 굴릴 수 있다.
만약 주사위가 굴러간 위치의 바닥이 0이라면 바닥에 주사위의 밑면의 숫자를 복사한다.
이외의 경우에는 주사위의 밑면에 바닥의 숫자를 붙여넣고, 바닥의 숫자를 0으로 바꾼다.
매번 굴릴 때 마다 주사위의 윗면에 적힌 숫자를 출력한다.
Method :
주사위를 1차원 배열 dice[7] = {X, 1, 2, 3, 4, 5, 6} 으로 생각한다. (숫자는 위 주사위 그림의 숫자)
주사위를 굴리는 행위는 주사위의 인덱스로 참조해서 바꾸는 방식으로 구현할 수 있다.
(ex) 동쪽으로 굴리면 [1] 자리에 [4]가, [3]자리에 [1]이, ... 이런식
따라서 매 command마다 먼저 유효한 범위인지 확인한 후,
유효한 범위라면 주사위를 굴리고, 바닥면을 확인해서 적절한 처리를 한다.
이후 맨 위의 숫자인 dice[1]을 출력한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m, x, y, k, c;
int board[25][25];
int dice[7];
/*
   [2]
[4][1][3] <- [1]이 맨 위, [3]이 동쪽
   [5]
   [6] <- 바닥
{empty, 1(맨위), 2, 3, 4, 5, 6(맨아래)} 
*/

bool oob(int x, int y) { // out of bound check
  return (x<0 || y<0 || n<=x || m<=y);
}

void roll(int command) {
  if(command == 1) {// 동쪽으로 roll 
    int afterroll[7] = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else if(command == 2) {// 서쪽으로 roll
    int afterroll[7] = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else if(command == 3) {// 북쪽으로 roll
    int afterroll[7] = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else {// 남쪽으로 roll
    int afterroll[7] = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  }
  return;
}

void solve() {
  cin >> n >> m >> x >> y >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> board[i][j];
  
  while(k--) {
    cin >> c;
    int nx = x + dx[c-1];
    int ny = y + dy[c-1];
    if(!oob(nx, ny)) {
      x = nx; y = ny;
      roll(c);
      if(board[x][y] == 0)
        board[x][y] = dice[6];
      else {
        dice[6] = board[x][y];
        board[x][y]=0;
      }
      cout << dice[1] << "\n";
    }
  }
  return;
}