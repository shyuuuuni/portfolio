/*
Time : 2022.01.11 (10 min)
Problem : BOJ1021 (https://www.acmicpc.net/problem/1021)
Algorithm Type : BFS
Outline :
가로길이 M, 세로길이 N의 이차원 배열에 대해 배추(1)와 배추를 심지 않은 땅(0)을 입력받는다.
배추를 해충으로부터 보호하기 위해 배추흰지렁이를 설치하려고 한다.
배추흰지렁이는 상하좌우에 인접한 배추를 이동할 수 있다.
필요한 배추흰지렁이의 최소 개수를 출력한다.
Method :
BFS를 이용하여 해결한다.
먼저 배열을 입력 받은 후, 배열을 차례대로 순회하며
만약 배추(1)인 경우 해당 위치에서부터 BFS를 통해 인접한 1을 모두 visit체크한다.
이러면 다음에 arr[i][j]==1 이여도 vis[i][j]가 0이 아니라면
이미 다른 배추에 연결되었기 때문에 새로운 배추흰지렁이를 설치할 필요가 없다.
따라서 위와같이 vis[i][j]==0 이면서 arr[i][j]==1인 위치의 개수를 cnt에 저장하여 출력한다.
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void solve() {
  int tc;
  cin >> tc;
  while(tc--) {
    int m, n, k; //가로,세로,배추개수
    int cnt=0;
    int vis[50+1][50+1]={0}, arr[50+1][50+1]={0};
    queue<pii> q;
    cin >> m >> n >> k;
    while(k--) {
      int i, j; // i : X(세로), j : Y(가로)
      cin >> j >> i;
      arr[i][j] = 1;
    }
    // cout << "=======\n";
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(vis[i][j]==1 || arr[i][j]==0) continue;
        // cout << i << " " << j << "\n";
        cnt++;
        q.push(mp(i,j));
        vis[i][j] = 1;
        while(!q.empty()) {
          auto cur = q.front(); q.pop();
          // cout << "cur :" << cur.X << " " << cur.Y << "\n";
          int x = cur.X;
          int y = cur.Y;
          for(int i=0; i<4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
            if(vis[xx][yy]==1 || arr[xx][yy]==0) continue;
            vis[xx][yy] = 1;
            q.push(mp(xx,yy));
          }
        }
      }
    }
    cout << cnt << "\n";
  }
  return;
}