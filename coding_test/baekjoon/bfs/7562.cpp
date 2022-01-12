/*
Time : 2022.01.12 (25 min)
Problem : BOJ7562 (https://www.acmicpc.net/problem/7562)
Algorithm Type : BFS
Outline :
IxI 크기의 체스판이 있다. 체스판에 나이트의 좌표가 주어진다.
이후 나이트가 이동하고자 하는 위치의 좌표가 주어진다.
나이트가 최소 몇 번 만에 해당 위치로 이동할 수 있는지 출력한다.
Method :
일반적인 BFS가 상하좌우를 탐색하여 이동하는 반면
7562번 문제는 나이트의 이동이 필요하다.
dx, dy배열을 나이트가 이동하는 모양에 맞춰서 좌표를 변화시키도록 설정한다.
vis[i][j] 는 (i,j)에 도달하기까지 필요한 이동 횟수를 의미한다.
만약 (i,j)가 나이트가 원하는 위치라면 해당 vis[i][j]를 출력한다.
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

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
void solve() {
  int tc;
  cin >> tc;
  while(tc--) {
    int l, xxx, yyy, ans=0;
    int vis[300+1][300+1];
    fill(&vis[0][0], &vis[0][0]+301*301, -1);
    queue<pii> q;
    cin >> l;
    cin >> xxx >> yyy;
    q.push(mp(xxx,yyy));
    vis[xxx][yyy]=0;
    cin >> xxx >> yyy;
    while(!q.empty()) {
      int x = q.front().X;
      int y = q.front().Y;
      int d = vis[x][y];
      if(x == xxx && y == yyy) {
        ans = d;
        break;
      }
      q.pop();
      for(int i=0; i<8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx<0 || yy<0 || l<=xx || l<=yy) continue;
        if(vis[xx][yy] != -1) continue;
        vis[xx][yy] = d + 1;
        q.push(mp(xx,yy));
      }
    }
    cout << ans << "\n";
  }
  return;
}