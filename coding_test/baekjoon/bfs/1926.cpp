/*
Time : 2022.01.11 (15 min)
Problem : BOJ1926 (https://www.acmicpc.net/problem/1926)
Algorithm Type : BFS
Outline :
이중 배열에 0과 1로 이루어진 그림이 있다.
그림은 1로 연결된 것을 그림이라고 한다. 가로 또는 세로에 연결되어 있으면 연결이 된 것이다.
그림의 넓이를 그림에 포함된 1의 개수인데, 도화지에서 가장 넓은 그림의 넓이를 출력한다.
Method :
Queue를 이용한 BFS를 이용하여 해결하였다.
배열을 입력 받은 뒤, 배열을 순회하면서 visit 하지 않은 1인 원소를 만나면 해당 위치에서 BFS를 시행한다.
BFS를 돌면 해당 위치와 연결된 모든 1의 visit 을 켜므로 다음에는 진입하지 않는다.
매 BFS마다 1의 개수를 세줘서 그림의 넓이를 재고 최댓값을 갱신한다.
매 진입이 있을 때 마다 그림의 개수를 1 증가시킨다.
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

int arr[500+1][500+1], vis[500+1][500+1];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, mx=0, num=0;;
pii cur;
queue<pii> q;

void bfs(int x, int y) {
  int cnt=0, xx, yy;
  q.push(mp(x,y));
  vis[x][y]=1;
  while(!q.empty()) {
    cur = q.front();
    x = cur.X;
    y = cur.Y;
    q.pop();
    cnt++;
    for(int i=0; i<4; i++) {
      xx = x + dx[i];
      yy = y + dy[i];
      if(xx < 0 || n <= x || yy < 0 || m <= y) continue;
      if(arr[xx][yy]  && vis[xx][yy] == 0) {
        vis[xx][yy] = 1;
        q.push(mp(xx,yy));
      } else {
        continue;
      }
    }
  }
  if(mx < cnt) mx = cnt;
  return;
}

void solve() {
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(arr[i][j] == 1 && vis[i][j] == 0) {
        bfs(i,j);
        num++;
      }
    }
  }
  cout << num << "\n" << mx;
  return;
}