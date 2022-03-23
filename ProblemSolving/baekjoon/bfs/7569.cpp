/*
Time : 2022.01.12 (15 min)
Problem : BOJ7569 (https://www.acmicpc.net/problem/7569)
Algorithm Type : BFS
Outline :
가로x세로x높이가 MxNxH인 토마토 창고가 있다.
창고에 있는 토마토는 익은 토마토와 익지 않은 토마토가 있는데,
익은 토마토는 주위(위,아래,왼쪽,오른쪽,앞,뒤)의 토마토를 하루마다 익도록 만든다.
며칠이 지나야 상자 안의 토마토가 모두 익는지 출력한다.
만약 토마토가 모두 익지 못하는 상황이면 -1을 출력한다.
Method :
3차원 상에서 BFS를 이용하여 해결하였다.
dx, dy, dz를 선언하여 상하좌우앞뒤를 쉽게 이동하도록 처리한다.
vis배열은 해당 위치가 익은 시점을 저장하고, 초기값을 -1로 설정한다.
(STL의 fill 함수를 이용하여 초기화했다.)
만약 모든 수행이 끝났는데, 방문되지 않은 익지 않은 토마토(0)가 있다면 -1을 출력한다.
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

int dx[6] = {1, 0, -1, 0, 0, 0}; // 세로
int dy[6] = {0, -1, 0, 1, 0, 0}; // 가로
int dz[6] = {0, 0, 0, 0, 1, -1}; // 높이
void solve() {
  int m, n, h, ans=0;
  int arr[100+1][100+1][100+1]={0};
  int vis[100+1][100+1][100+1];
  fill(&vis[0][0][0], &vis[0][0][0] + 101*101*101, -1);
  queue<pair<pii,int> > q;
  cin >> m >> n >> h; // 가로, 세로, 높이
  for(int i=0; i<h; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++) {
        cin >> arr[i][j][k];
        if(arr[i][j][k] == 1) {
          q.push(mp(mp(j,k),i));
          vis[i][j][k] = 0; // vis[z][x][y]
        }
      }
    }
  }
  while(!q.empty()) {
    int x = q.front().first.X;
    int y = q.front().first.Y;
    int z = q.front().second;
    int d = vis[z][x][y];
    q.pop();
    for(int i=0; i<6; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      int zz = z + dz[i];
      if(xx<0 || yy<0 || zz<0 || n<=xx || m<=yy || h<=zz) continue;
      if(vis[zz][xx][yy]!=-1 || arr[zz][xx][yy]!=0) continue;
      vis[zz][xx][yy]=d+1;
      ans = max(vis[zz][xx][yy], ans);
      q.push(mp(mp(xx,yy),zz));
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++) {
        if(arr[i][j][k]==0 && vis[i][j][k]==-1) {
          cout << "-1\n";
          return;
        }
      }
    }
  }
  cout << ans;
  return;
}