/*
Time : 2022.02.05 (30 mins)
Problem : BOJ3190 (https://www.acmicpc.net/problem/3190)
Algorithm Type : Simulation
Outline :
NxN 크기의 보드 위에 뱀(-1)과 사과(1)가 있다.
뱀은 방향(d)을 가지고 있으며, 1초마다 해당 방향으로 이동한다.
뱀은 다음과 같은 규칙을 따른다.
1. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
2. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
3. 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
Method :
뱀을 deque로 구현하였다.
front()에는 뱀의 머리가, back()에는 뱀의 꼬리를 위치시킨다.
뱀의 이동은 방향 d에 따라서 결정한다. d는 0(북) 1(동) 2(남) 3(서) 로 구현하였다.
다음 위치가 가능한 위치라면 deque에 다음 위치를 넣고, 해당 위치를 -1로 표시한다.
(가능하지 않다면 종료한다)
만약 다음 위치에 사과가 있었다면 뱀의 길이가 늘어나므로 넘어간다.
만약 사과가 없다면 길이는 그대로이므로 deque의 back에서 하나를 뺀다 (꼬리를 이동시킨다)
이후 다음 반복문으로 넘어가기 전, 시간마다 왼쪽/오른쪽으로 이동하는지 체크해주며, 방향을 바꾼다.
Example :
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
-------
9
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
// int dz[6] = {0,0,0,0,-1,1};
// int dx[6] = {-1,1,0,0,0,0};
// int dy[6] = {0,0,-1,1,0,0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n;
int k;
int l, idx;
int t=0, d=1;
int x=0, y=0; // head
vector<pii> v;
int board1[100+1][100+1];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

void pm() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << board1[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  cin >> n;
  cin >> k;
  while(k--) {
    int r, c;
    cin >> r >> c;
    board1[r-1][c-1] = 1; // apple
  }
  cin >> l;
  while(l--) {
    int ti;
    char dir;
    cin >> ti >> dir;
    v.push_back(mp(ti, (dir=='L'?-1:1)));
  }

  deque<pii> baaam;
  baaam.push_back(mp(0,0));
  board1[0][0] = -1;
  
  while(1) {
    // pm();
    // cout << t << "---------------\n";
    t++;
    int x = baaam.front().X;
    int y = baaam.front().Y;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(oob(nx,ny,n,n) || board1[nx][ny]==-1) {
      break;
    }
    baaam.push_front(mp(nx,ny));
    if(board1[nx][ny] == 1) {
      // apple here
      board1[nx][ny] = -1;
    } else {
      // just move
      int xx = baaam.back().X;
      int yy = baaam.back().Y;
      board1[nx][ny] = -1;
      board1[xx][yy] = 0;
      baaam.pop_back();
    }
    if(idx < v.size() && t == v[idx].first) {
      // change dir
      d = (4 + d + v[idx++].second) % 4;
    }
  }

  cout << t;

  return;
}