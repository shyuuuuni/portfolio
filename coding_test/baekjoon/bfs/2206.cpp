/*
Time : 2022.01.12 (25 min)
Problem : BOJ2206 (https://www.acmicpc.net/problem/2206)
Algorithm Type : BFS
Outline :
NxM 행렬로 표현되는 맵이 있다.
1. '0' : 이동할 수 있는 위치
2. '1' : 이동할 수 없는 벽
(1,1)에서 (N,M)으로 이동할 때 최댄 경로로 이동하려 한다.
이동하는 중 한개의 벽을 부수고 이동하는 것이 경로가 짧아진다면 한개의 벽을 부수고 이동할 수 있따.
최단 경로를 출력한다.
Method :

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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve() {
  int n, m;
  string arr[1000+1];
  int dist[2][1000+1][1000+1];
  queue<pair<pii,int> > q;
  cin >> n >> m;  // 세로(x), 가로(y)
  fill(&dist[0][0][0], &dist[0][0][0]+2*1001*1001, -1);
  for(int i=0; i<n; i++)
    cin >> arr[i];
  dist[0][0][0] = dist[1][0][0] = 0;
  q.push(mp(mp(0,0),0));
  while(!q.empty()) {
    int x = q.front().first.X;
    int y = q.front().first.Y;
    int is_broken = q.front().second; // 이미 부수고 왔는지
    int d = dist[is_broken][x][y];
    q.pop();
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || yy<0 || n<=xx || m<=yy) continue;
      if(is_broken && arr[xx][yy]=='1') continue;
      if(is_broken) {
        if(dist[1][xx][yy]==-1 || d+1 < dist[1][xx][yy]) {
          dist[1][xx][yy] = d+1;
          q.push(mp(mp(xx,yy),1));
        } else {
          // 기존에 도착한 방법이 더 빠름
        }
      } else {
        if(arr[xx][yy]=='1') {
          if(dist[1][xx][yy]==-1 || d+1 < dist[1][xx][yy]) {
            dist[1][xx][yy] = d+1;
            q.push(mp(mp(xx,yy),1));
          } else {
            // 전에 방문했으면서 이번 시행보다 빨리 도달할 수 있음.
          }
        } else {
          if(dist[0][xx][yy]!=-1) continue;
          dist[0][xx][yy] = d+1;
          q.push(mp(mp(xx,yy),0));
        }
      }
    }
  }
  if(dist[0][n-1][m-1]==-1) dist[0][n-1][m-1]=1000000001;
  if(dist[1][n-1][m-1]==-1) dist[1][n-1][m-1]=1000000001;
  if(dist[0][n-1][m-1]==1000000001 && dist[1][n-1][m-1]==1000000001) cout << "-1";
  else cout << min(dist[0][n-1][m-1],dist[1][n-1][m-1])+1;
  return;
}