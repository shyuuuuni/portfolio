/*
Time : 2022.02.05 (30 mins)
Problem : BOJ13460 (https://www.acmicpc.net/problem/13460)
Algorithm Type : Simulation
Outline :
NxM 크기의 게임판에 빨간구슬(R), 파란구슬(B), 벽(#), 빈칸(.), 구멍(O)이 존재한다.
이 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다.
이때 파란 구슬이 (동시에라도) 구멍에 빠져서는 안 된다.
보드의 상태가 주어졌을 때 최소 몇 번 만에 빨간 구슬을 구멍을 통해 뺄 수 있는지 출력한다.
만약 10번 이내에 뺄 수 없다면 -1을 출력한다. 
Method :

Example :
5 5
#####
#..B#
#.#.#
#RO.#
#####
-------
1
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dz[6] = {0,0,0,0,-1,1};
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

/*
 * declare here
 */
int n, m, ans=-1;
pii b, r, o;
string board1[10+1], board2[10+1];
int INF = 100000;

bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

int run(int trial, int prev) {
  if(trial == 10) {
    return INF;
  }
  pii cb = b;
  pii cr = r;
  for(int i=0; i<4; i++) {
    if(prev != -1) {
      // 이전 방향과 같은 방향 = 벽에 계속 박음
      // 이번 방향과 반대 방향 = 
      if(i == prev) continue;
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> board1[i];
    for(int j=0; j<m; j++) {
      if(board1[i][j] == 'B')
        b = mp(i,j);
      else if(board1[i][j] == 'R')
        r = mp(i,j);
      else if(board1[i][j] = 'O')
        o = mp(i,j);
    }
  }

  cout << run(0, -1);

  return;
}