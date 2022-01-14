/*
Time : 2022.01.14 (1+ hour)
Problem : BOJ9466 (https://www.acmicpc.net/problem/9466)
Algorithm Type : DFS
Outline :
학생 1, 2, 3, 4, ..., N이 프로젝트를 함께하고 싶은 팀원을 선택한다.
학생 1이 1(자기자신)을 선택한 경우 혼자 팀이 될 수 있다.
학생 1이 학생 2를, 학생 2가 학생 3을, ..., 학생 r이 학생 1을 선택한다면
학생 1~r은 한 팀으로 될 수 있다.
어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산한다.
Method :
백트래킹을 이용하여 해결하였다.
target[i] = j : 학생 i가 팀원으로 j를 지목함
start_idx[i] = j : 학생 j -> ... -> 학생 i 순으로 지목당함
valid_start[i] : 0이면 학생 i부터 시작하는 지목은 팀X
순서대로 학생을 1부터 N까지 방문하면서, 이전에 방문되지 않은 학생이라면
DFS를 돌면서 start_idx를 체크해주면서 계속 지목한다.
만약 DFS를 도는 중 다음에 방문해야 하는 학생 t의 start_idx와
현재 보고있는 학생의 start_idx가 같다면 사이클이다.
이런 경우 해당 학생부터 현재 학생까지 팀을 이룰 수 있으므로
백트래킹하면서 학생 t가 나올때까지 방문했던 학생들의 start_idx를 t로 설정한다.
만약 학생 t의 start_idx가 현재 학생의 start_idx와 다르다면
현재 학생은 계속 방문해도 사이클이 될 수 없다.
이 경우 valid_start[stt]를 0으로 설정한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int target[100000+1]; // target[i] = j (학생 i가 j를 지목)
int start_idx[100000+1]; // -1이면 미방문, 1이상이면 시작점의 인덱스를 가지고 있음.
int valid_start[100000+1]={0}; // valid_start[i] = 0이면 i부터 시작한건 팀X, 1이면 팀
int dfs(int stt, int cur) {
  int t = target[cur];
  int ans = 0;
  start_idx[cur] = stt;
  if(start_idx[t] == -1) { // 다음 노드가 이전에 방문X
    ans = dfs(stt, t);
  } else { // 다음 노드가 이전에 방문 O
    if(start_idx[t] == start_idx[cur]) {
      // 사이클이 생긴 경우 ... -> {t -> cur -> t}
      ans = t;
      start_idx[cur] = t;
      valid_start[t] = 1;
    } else {
      // 이전에 방문한 노드인데, 출발점이 다름
      // 이전에 방문했다면 사이클이라면 현재 노드를 들렸을것임.
      // 따라서 invalid
      ans = 0;
      valid_start[stt] = 0;
    }
  }
  if(ans) {
    start_idx[cur] = ans;
    if(cur == ans) ans = 0;
  }
  return ans;
}
void solve1() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n; cin >> n;
    fill(start_idx, start_idx+100001, -1);
    fill(valid_start, valid_start+100001, 0);
    for(int i=1; i<=n; i++) cin >> target[i];
    for(int i=1; i<=n; i++) {
      if(start_idx[i] != -1) continue; // 전에 방문한 노드
      if(start_idx[target[i]] != -1) continue; // 다음 노드가 이전에 방문한 노드
      int check = dfs(i, i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
      int s = start_idx[i];
      if(valid_start[s] == 0) ans++;
    }
    cout << ans << "\n";
  }
  return;
}