/*
Time : 2022.01.11 (20 min)
Problem : BOJ4179 (https://www.acmicpc.net/problem/4179)
Algorithm Type : BFS
Outline :
미로에 지훈이와 불이 매 분마다 수평 혹은 수직으로 이동한다.
불은 각 지점의 상하좌우로 확산한다.
지훈이가 미로에서 탈출하려면 미로에 가장자리에 접한 공간으로 가야 한다.
벽(#), 지나갈 수 있는 공간(.), 지훈이(J), 불이 난 공간(F)으로 주어졌을 때
가장 빠른 탈출시간을 출력한다.
Method :
두개의 BFS를 이용하여 해결한다.
df는 fire의 dist, dj는 지훈이의 dist를 의미하며,
df[i][j] = (i,j) 까지 가는데 걸린 블록 수 를 의미한다.
출발점을 큐에 넣어서 각각 BFS를 돌려서 불과 지훈이가 각각 블록에 도달하는데
걸리는 시간을 획득한다.
지훈이가 이동할 수 있다는 뜻은 지훈이가 해당 칸에 도착한 시간보다 불이 늦게 도착했다는 것을 의미한다.
따라서 df[xx][yy] != -1 && df[xx][yy] <= d+1 와 같은 조건을 추가해서
불의 도착 시간과 비교해서 지훈이가 더 빠르게 갈 수 있으면 이동하는 식으로 구현한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int df[1000+2][1000+2], dj[1000+2][1000+2];
string arr[1000+2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, ans=0;
queue<pii> jq, fq;

void solve() {
  int flag = 0;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    fill(df[i], df[i]+m, -1);
    fill(dj[i], dj[i]+m, -1);
    cin >> arr[i];
    for(int j=0; j<m; j++) {
      if(arr[i][j] == 'J') {
        jq.push(mp(i,j));
        dj[i][j] = 1;
      } else if(arr[i][j] == 'F') {
        fq.push(mp(i,j));
        df[i][j] = 1;
      }
    }
  }
  while(!fq.empty()) {
    pii cur = fq.front();
    fq.pop();
    int x = cur.X;
    int y = cur.Y;
    int d = df[x][y];
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
      if(arr[xx][yy]=='#' || df[xx][yy]!=-1) continue;
      df[xx][yy] = d + 1;
      fq.push(mp(xx,yy));
    }
  }
  while(!jq.empty()) {
    pii cur = jq.front();
    jq.pop();
    int x = cur.X;
    int y = cur.Y;
    int d = dj[x][y];
    if(x==0 || x==n-1 || y==0 || y==m-1) {
      cout << d;
      return;
    }
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
      if(arr[xx][yy]=='#' || dj[xx][yy]!=-1) continue;
      if(df[xx][yy] != -1 && df[xx][yy] <= d+1) continue;
      dj[xx][yy] = d + 1;
      jq.push(mp(xx,yy));
    }
  }
  cout << "IMPOSSIBLE";
  return;
}