/*
Time : 2022.01.21 (30 min)
Problem : BOJ15649 (https://www.acmicpc.net/problem/15649)
Algorithm Type : Backtracking
Outline :
1~N까지의 수 중에서 중복되지 않게 M개의 숫자를 뽑아서 만든 수열을 출력한다.
Method :
vis[i]는 i라는 숫자를 사용했는지 체크하는 배열이다.
out[i]는 수열에 들어간 숫자를 순서대로 저장하는 배열이다.
btracking(cur)는 현재 cur개의 숫자를 수열에 넣고, 나머지 수열을 채우는 함수이다.
종료조건은 cur가 m과 같아질 경우 모두 출력하고 리턴한다.
매 함수 호출마다 사용하지 않은 숫자를 백트래킹식으로 out에 포함한 경우와 포함하지 않은 경우를
모두 방문한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m;
int vis[8+1];
int out[8+1];
void btracking(int cur) {
  // cur : 저장할 인덱스
  if(cur == m) {
    for(int i=0; i<m; i++) {
      cout << out[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++) {
    if(vis[i]) continue;
    vis[i] = 1;
    out[cur] = i;
    btracking(cur+1);
    vis[i] = 0;
  }
}
void solve() {
  cin >> n >> m;
  btracking(0);
  return;
}