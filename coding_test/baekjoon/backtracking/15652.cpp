/*
Time : 2022.01.21 (15 min)
Problem : BOJ15652 (https://www.acmicpc.net/problem/15652)
Algorithm Type : Backtracking
Outline :
1~N까지 자연수 중에서 중복을 허용하여 M개를 고른 수열을 모두 출력한다.
이때 수열을 비내림차순으로 출력한다.
Method :
백트래킹을 이용하여 해결한다.
다음 탐색시 조건으로 이전에 탐색한 수보다 크거나 같을 경우만
탐색을 이어나가는 조건을 추가한다.
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
int ans[8+1];

void func(int cur) {
  if(cur==m) {
    for(int i=0; i<m; i++)
      cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++) {
    if(cur==0 || ans[cur-1] <= i) {
      ans[cur] = i;
      func(cur+1);
    }
  }
  return;
}

void solve() {
  cin >> n >> m;
  func(0);
  return;
}