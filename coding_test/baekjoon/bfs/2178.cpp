/*
Time : 2022.01.11 (15 min)
Problem : BOJ2178 (https://www.acmicpc.net/problem/2178)
Algorithm Type : BFS
Outline :
NxM 크기의 배열로 표현한 미로가 있다.
미로에서 1은 이동할 수 있는 칸, 0은 이동할 수 없는 칸을 나타낸다.
(1,1) 에서 출발하여 (N,M) 위치로 이동할 때 최소 칸 수를 출력한다.
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

int dist[100+2][100+2];
string arr[100+2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, cnt=0;
queue<pii> q;

void solve() {
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> arr[i];
  for(int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1);
  q.push(mp(0,0));
  dist[0][0] = 1;
  while(!q.empty()) {
    pii cur = q.front();
    q.pop();
    int x = cur.X;
    int y = cur.Y;
    int d = dist[x][y];
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx < 0 || n <= xx || yy < 0 || m <= yy) continue;
      if(arr[xx][yy] != '1' || dist[xx][yy] != -1) continue;
      dist[xx][yy] = d + 1;
      q.push(mp(xx,yy));
    }
  }
  cout << dist[n-1][m-1];
  return;
}