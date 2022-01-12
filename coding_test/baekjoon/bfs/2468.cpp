/*
Time : 2022.01.12 (15 min)
Problem : BOJ2468 (https://www.acmicpc.net/problem/2468)
Algorithm Type : BFS
Outline :
크기가 NxN인 지도에 높이정보가 주어진다.
장마철에 비가 내리면 일정한 높이 이하의 모든 지점이 물이 잠긴다.
안전한 영역을 "위,아래,왼쪽,오른쪽에 인접해 있는 물에 잠기지 않은 지점들"로 정의한다.
높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
Method :
입력을 받으면서 지도의 높이정보의 최솟값(mn)과 최댓값(mx)을 기록한다.
비가 오는 높이가 mn 미만일 경우에는 결국 하나도 잠기지 않으므로 답은 1이다.
이후 비에 잠기는 높이를 h라고 하고, h의 범위를 mn부터 mx까지 1씩 증가시키면서 다음과 같이 처리한다.
만약 arr[i][j]-h가 0 이하라면, h까지 비가 올때 잠긴다는 것을 의미한다.
위와 같이 처리하여 잠기지 않는다면 해당 위치에서부터 BFS를 통해 안전한 영역을 체크한다.
vis배열을 통해 이미 처리한 안전한 영역에 대해서는 다시 처리하지 않으므로,
새로 처리하는 개수를 세어준다면 해당 개수가 안전한 영역의 개수를 의미한다.
loop를 돌면서 안전한 영역의 최대 개수를 저장하여 마지막에 출력한다.
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
  int n, mx=0, mn=10000001, ans=1;
  int arr[100+1][100+1]={0};
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> arr[i][j];
      mx = max(mx, arr[i][j]);
      mn = min(mn, arr[i][j]);
    }
  }
  // i : 장마시 잠기는 높이
  for(int h=mn; h<mx; h++) {
    int cur = 0;
    int vis[100+1][100+1]={0};
    queue<pii> q;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(arr[i][j]-h > 0 && vis[i][j]==0) {
          q.push(mp(i,j));
          vis[i][j]=1;
          cur++;
        } else {
          continue;
        }
        while(!q.empty()) {
          int x = q.front().X;
          int y = q.front().Y;
          q.pop();
          for(int k=0; k<4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
            if(vis[xx][yy]!=0 || arr[xx][yy]-h<=0) continue;
            q.push(mp(xx,yy));
            vis[xx][yy]=1;
          }
        }
      }
    }
    ans = max(ans, cur);
  }
  cout << ans;
  return;
}