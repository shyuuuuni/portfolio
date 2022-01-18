/*
Time : 2022.01.18 (40 min)
Problem : BOJ2146 (https://www.acmicpc.net/problem/2146)
Algorithm Type : BFS
Outline :
NxN 크기의 이차원 평면에 육지(1), 바다(0)로 이루어진 지도가 주어진다.
지도가 주어졌을 때, 육지간 연결할 수 있는 가장 짧은 다리의 길이를 출력한다.
Method :
arr[i][j] : 해당 위치가 육지면 1 바다면 0인 이차원 배열
flags[i][j] : 해당 위치가 어떤 대륙과 연결되어 있는지 (1,2,3, ...) 표시
vis[i][j] : 해당 위치가 방문 되었는지. 방문되지 않았으면 -1, 방문 되었다면 얼마만에 방문할 수 있는지
먼저 입력을 받는다.
이후 일반적인 BFS를 통하여 대륙별로 flags를 번호매긴다.
이때 사방에 0이 존재하는 위치 = 즉, 대륙의 끝을 모두 qq에 입력한다.
모든 루프가 끝나면 qq에 대해서 BFS를 한번 더 돌린다.
qq에는 대륙의 끝에서부터 BFS가 일어난다.
만약 BFS시 새로 탐험하려는 위치의 vis값이 -1이 아닌지 체크한다.
바다는 기본적으로 vis값을 -1로 초기화 해두었는데,
-1이 아니라는 뜻은 이전에 다른 대륙에서부터 나온 탐색이 해당 점까지 방문했다는 뜻이다.
즉, 최단 거리의 다리가 될 가능성이 있다고 판단한다.
이럴 경우 ans값에 이번 탐색의 다리의 길이를 저장하고, anscnt값에 그때의 distance를 저장한다.
남은 탐색에서 더 가까운 다리가 존재할 수 있으므로, 해당 distance보다 작거나 같은 경우를 마저 탐색하고 리턴한다.
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
  int vis[100+1][100+1];
  int arr[100+1][100+1] = {0};
  int flags[100+1][100+1] = {0};
  int ans=0, anscnt=0;
  queue<pii> q;
  queue<pair<pii,int> > qq;

  // 입력,초기화
  cin >> n;
  fill(&vis[0][0], &vis[0][0]+101*101, -1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> arr[i][j];
    }
  }

  // 바다에 인접한 육지의 좌표를 qq에 입력
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(vis[i][j]==-1 && arr[i][j]==1) {
        // 처음 방문한 육지일 경우
        q.push(mp(i,j));
        vis[i][j]=0;
        cnt++;
        flags[i][j] = cnt;
      }
      while(!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        int flag = 0;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
          if(arr[xx][yy]==0) {
            // (xx,yy)가 바다와 인접한 경우
            flag=1;
            continue;
          }
          if(vis[xx][yy]!=-1) continue;
          q.push(mp(xx,yy));
          flags[xx][yy] = cnt;
          vis[xx][yy]=0;
        }
        if(flag) qq.push(mp(mp(x,y), 0));
      }
    }
  }

  // 바다에 인접한 육지로부터 바다쪽으로 BFS
  // 만약 바다인데 vis가 -1이 아니면 최단거리로 만남
  while(!qq.empty()) {
    int x = qq.front().first.X;
    int y = qq.front().first.Y;
    int d = qq.front().second;
    qq.pop();
    if(ans) {
      if(anscnt < d) {
        cout << ans;
        return;
      }
    }

    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
      if(arr[xx][yy] != 0 || flags[xx][yy] == flags[x][y]) continue;
      if(vis[xx][yy] == -1) {
        qq.push(mp(mp(xx,yy), d+1));
        vis[xx][yy] = d+1;
        flags[xx][yy] = flags[x][y];
      } else {
        // 이전에 누군가 바다를 방문 -> 최단 거리 다리
        if(ans == 0) {
          ans = d+vis[xx][yy];
          anscnt = d;
        } else {
          if(d+vis[xx][yy] < ans) {
            ans = d+vis[xx][yy];
          }
        }
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << arr[i][j] << " ";
    } cout << "\n";
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << vis[i][j] << " ";
    } cout << "\n";
  }
  return;
}