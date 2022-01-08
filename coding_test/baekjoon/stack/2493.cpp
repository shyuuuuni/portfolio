/*
Time : 2022.01.07 (30 min)
Problem : BOJ2493 (https://www.acmicpc.net/problem/2493)
Algorithm Type : Stack
Outline :
수평선 위에 높이가 각기 다른 타워 N개가 놓여져 있다.
타워에는 왼쪽 수평으로 레이저를 쏘는 장치가 있고,
각 타워는 레이저를 수신할 수 있는 장치가 있다.
타워의 높이가 다르기때문에, 오른쪽에서 쏜 레이저는 더 높은 타워만 수신할 수 있다.
각각의 탑에서 발사한 레이저가 어느 탑에서 수신했는지 출력한다.
Method :
스택을 이용하여 해결하였다.
pair<int,int>로 first에는 타워의 높이를, second에는 타워의 순서를 저장했다.
스택 towers는 수평선에 서있는 타워를 순서대로 저장한 스택이다.
즉, 마지막에 들어온 타워가 먼저 나오는 자료구조이다.
스택 buf는 이전에 레이저를 발사했지만 아직 부딫히지 않은 타워의 pair를 저장한 자료구조이다.
buf가 부딫히지 않은 타워들을 모아두었다는 뜻은, buf 안에 들어있는 타워간의 관계가
높이가 오름차순이라는 뜻이다. (만약 아니라면 이미 부딫혀서 buf 안에 없었기 때문이다.)
따라서 buf.top()보다 낮은 높이의 타워는 buf 안에 존재하지 않고,
따라서 towers.top()과 비교해서 만약 towers의 것이 더 작다면 buf에 추가하고,
반대로 크다면 buf에서 부딫히는 모든 타워를 pop 하면서 ans배열에 저장해주면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

int ans[500000+1];
void solve1() {
  int tc, n;
  stack<pair<int,int> > towers, buf;
  cin >> tc;
  for(int i=1; i<=tc; i++) {
    cin >> n;
    towers.push(make_pair(n, i));
  }
  while(!towers.empty()) {
    pair<int,int> cur = towers.top();
    towers.pop();
    if(buf.empty() || cur.first < buf.top().first) {
      buf.push(cur);
    } else {
      while(!buf.empty() && buf.top().first < cur.first) {
        ans[buf.top().second] = cur.second;
        buf.pop();
      }
      buf.push(cur);
    }
  }
  for(int i=1; i<=tc; i++) {
    cout << ans[i] << " ";
  }
  return;
}