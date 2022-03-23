/*
Time : 2022.01.12 (15 min)
Problem : BOJ2667 (https://www.acmicpc.net/problem/2667)
Algorithm Type : BFS
Outline :
NxN 크기의 지도가 있다. 각 지도 안에는 집(1)과 집이아닌곳(0)이 있다.
집이 연결되어 있다면 단지로 정의하고, 단지에 번호를 붙이려고 한다.
지도가 입력되면 단지 수를 출력하고, 각 단지의 집의 수를 오름차순으로 정렬하여 출력한다.
Method :
BFS를 이용하여 해결한다.
vis[i][j]는 방문한적이 없다면 -1, 있다면 0
arr[i][j]는 집이라면 1 아니면 0 을 저장한다.
입력을 받은 후, 집이면서 방문하지 않은 위치를 큐에 넣고 BFS를 돌린다.
(이러면 해당 위치와 연결된 단지를 모두 방문한다.)
큐에 넣은 횟수를 cnt로 저장하여 1 증가시키고,
단지에 들어있는 집의 개수를 ans에 저장시킨다.
출력시 집의 개수를 오름차순으로 출력해야 하므로 STL sort를 이용한다.
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
int dy[4] = {0,-1,0,1};
void solve() {
  int n, cnt=0;
  int vis[25+1][25+1];
  string arr[25+1];
  vector<int> ans;
  queue<pii> q;
  cin >> n;
  fill(&vis[0][0], &vis[0][0] + 26*26, -1);
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(arr[i][j]=='1' && vis[i][j]==-1) {
        cnt++;
        q.push(mp(i,j));
        vis[i][j]=0;
      } else {
        continue;
      }
      int tmp=0;
      while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        tmp++;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
          if(vis[xx][yy]!=-1 || arr[xx][yy]!='1') continue;
          q.push(mp(xx,yy));
          vis[xx][yy]=0;
        }
      }
      ans.push_back(tmp);
    }
  }
  sort(ans.begin(), ans.end());
  cout << cnt << "\n";
  for(auto i : ans) cout << i << "\n";
  return;
}