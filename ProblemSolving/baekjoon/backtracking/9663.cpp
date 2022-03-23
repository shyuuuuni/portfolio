/*
Time : 2022.01.21 (30 min)
Problem : BOJ9663 (https://www.acmicpc.net/problem/9663)
Algorithm Type : Backtracking
Outline :
NxN 체스판 위에 N개의 퀸을 올려놓는 경우의 수의 개수를 출력한다.
Method :
퀸은 가로/세로/대각선에 존재할 수 없다.
func함수의 x인자가 해당 행을 나타내므로, x에서 하나의 퀸만 놓으면 문제가 없다.
세로는 issued1 배열에 저장하는데, 만약 방문하려는 y좌표(가로)가 issued1 되었다면 방문할 수 없다.
대각선은 왼쪽위->오른쪽아래 / 오른쪽위->왼쪽아래 두개가 있다.
func(x)의 x에 대해서 각각의 가로좌표 y를 하나씩 놓을 수 있는지 보고,
놓을 수 있다면 놓은 후 다음 단계로 탐색하면 된다.
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

int n,ans=0;
int issued1[15+1]; // issued1[i] : i번째 열이 사용되었는지
int issued2[30+1]; // issued2[i] : i번째 대각선(왼쪽위->오른쪽아래) 사용되었는지
int issued3[30+1]; // issued3[i] : i번째 대각선(오른쪽위->왼쪽아래) 사용되었는지
// (x-세로,y-가로) 좌표가 놓을 수 있는 위치인지 체크
// 1. issued1[y] == 0 : 해당 열에 다른 퀸이 존재하지 않음.
// 2. issued2[x-y+n-1] == 0 : 해당 대각선에 다른 퀸이 존재하지 않음.
// 3. issued3[x+y] == 0 : 해당 대각선에 다른 퀸이 존재하지 않음.

void func(int x) { // cur번째 행을 보는 경우
  if(x==n) {
    ans++;
    return; // 0~n-1 : 총 n줄을 봄, cur==n이면 종료
  }
  for(int y=0; y<n; y++) {
    if(!issued1[y] && !issued2[x-y+n-1] && !issued3[x+y]) {
      issued1[y] = 1;
      issued2[x-y+n-1] = 1;
      issued3[x+y]= 1;
      func(x+1);
      issued1[y] = 0;
      issued2[x-y+n-1] = 0;
      issued3[x+y]= 0;
    }
  }
  return;
}

void solve() {
  cin >> n;
  func(0);
  cout << ans;
  return;
}