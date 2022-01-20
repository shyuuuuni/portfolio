/*
Time : 2022.01.21 (15 min)
Problem : BOJ15666 (https://www.acmicpc.net/problem/15666)
Algorithm Type : Backtracking
Outline :
N개의 자연수가 주어졌을 때, M개를 M개를 고른 수열을 출력한다.
이때 수열에서 같은 수를 여러번 골라도 된다.
또한 수열은 비내림차순이여야 한다.
Method :
비내림차순의 조건으로 [처음 추가하는 원소가 아니면서, 이전 원소보다 크거나 같을때만 추가] 라는 조건을 넣는다. 
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

int n, m, cnt=0;
vector<int> v, ans, issued;
set<int> s;

void func(int cur) {
  // cur : 총 몇개 들어갔는지
  int prv = -1;
  if(cur == m) {
    for(int i=0; i<m; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for(int i=0; i<n; i++) {
    if(cur!=0 && v[i]<ans[cur-1]) continue;
    if(/*!issued[i] && */prv!=v[i]) {
      // issued[i] = 1;
      ans[cur] = v[i];
      prv=v[i];
      func(cur+1);
      // issued[i] = 0;
    }
  }
  return;
}

void solve() {
  cin >> n >> m;
  v.resize(n);
  issued.resize(n);
  ans.resize(m);
  for(int i=0; i<n; i++) {
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  func(0);
  return;
}