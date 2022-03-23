/*
Time : 2022.01.19 (25 min)
Problem : BOJ13549 (https://www.acmicpc.net/problem/13549)
Algorithm Type : BFS
Outline :
직선에 수빈이가 위치 N, 동생이 위치 K에 서있다.
수빈이는 1초만에 X-1, X+1로 이동하거나 0초만에 2*X의 위치로 이동할 수 있다.
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
Method :
1차원 배열(수직선) 상에서의 BFS로 해결하였다.
queue에는 수직선상의 좌표를 입력한다.
dist는 해당 위치까지 가기위한 "최소" 시간을 저장한다.
BFS시 먼저 해당 위치 x에서부터 2x, 4x, 8x, ... 를 모두 체크한다.
(왜냐하면 해당 위치는 0초만에 순간이동 할 수 있기 때문)
이때 만약 2x, 4x, 8x, ...를 방문하다가 해당 위치에서 같은 시간이나
더 빠른 시간 내에 해당 위치로 도착할 수 있다면 loop를 break한다.
(왜냐하면 해당 시간이 기록되었을 때 이후 시간은 모두 기록했을 것이기 때문.)
이후 +1, -1을 처리하며, 이때에는 시간이 1초 들으므로 dist[xx] = dist[x] + 1로
시간을 1 증가시킨다.
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

void solve() {
  const int MAX_LEN = 2*100000+1;
  int n, k;
  vector<int> dist(MAX_LEN, -1);
  cin >> n >> k;
  queue<int>q;
  q.push(n);
  dist[n] = 0;
  while(!q.empty()) {
    int xx;
    int x = q.front();
    if(x == k) {
      cout << dist[x];
      return;
    }
    q.pop();
    // 순간이동
    for(xx=x*2; xx<MAX_LEN; xx*=2) {
      if(xx<0 || MAX_LEN<=xx) break;
      if(dist[xx]!=-1 && dist[xx] <= dist[x]) break;
      dist[xx] = dist[x];
      q.push(xx);
    }

    // 뒤로이동
    xx = x-1;
    if(!(xx<0 || MAX_LEN<=xx || (dist[xx]!=-1 && dist[xx] <= dist[x]+1))) {
      dist[xx] = dist[x]+1;
      q.push(xx);
    }

    // 뒤로이동
    xx = x+1;
    if(!(xx<0 || MAX_LEN<=xx || (dist[xx]!=-1 && dist[xx] <= dist[x]+1))) {
      dist[xx] = dist[x]+1;
      q.push(xx);
    }
  }
  
  return;
}