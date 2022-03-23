/*
Time : 2022.01.20 (20 min)
Problem : BOJ1780 (https://www.acmicpc.net/problem/1780)
Algorithm Type : Recursion
Outline :
NxN 크기의 행렬로 종이를 표현한다.
종이는 -1, 0, 1로 저장되어 있다.
종이는 다음 규칙에 따라 자른다.
1. 종이가 모두 같은 수로 저장되어 있다면 그대로 사용한다.
2. 그렇지 않으면 종이를 같은 크기의 종이 9개로 자르고 1을 반복한다.
종이를 잘랐을 때, -1, 0, 1 각각으로만 이루어진 종이의 개수를 출력한다.
Method :
travel(n, x, y)를 (x,y) 점부터 가로,세로 nxn 크기를 확인하는 재귀함수로 정의한다.
해당 점부터 nxn크기의 각각의 종이를 확인하면서 (x,y)점과 다른 숫자가 하나라도 발견된다면 9등분으로 나눈다.
만약 발견되지 않았다면 해당 숫자의 카운트를 1 증가시킨다.
발견되었다면 재귀적으로 9등분한 좌표를 넣고, n의 값을 1/3로 줄여서 반복한다.
만약 n이 1이 되었다면 해당 종이는 1번 조건을 만족하므로 해당 숫자 카운트를 1 증가시킨다.
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

vector<int> ans(3,0);
vector<vector<int> > v(2187+1, vector<int>(2187+1));
// (x,y)에서부터 가로 n, 세로 n을 탐색, n은 3^k 꼴
void travel(int n, int x, int y) {
  int val = v[x][y], flag=1, nxt=n/3;
  if(n == 1) {
    ans[val+1]++; // -1:ans[0], 0:ans[1], 1:ans[2]
    return;
  }
  for(int i=0; flag&&i<n; i++) {
    for(int j=0; flag&&j<n; j++) {
      if(val != v[x+i][y+j]) flag=0;
    }
  }
  if(flag) {
    ans[val+1]++;
    return;
  }
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      travel(nxt, x+i*nxt, y+j*nxt);
    }
  }
  return;
}

void solve() {
  int n; // <= 3^7
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> v[i][j];
  travel(n, 0, 0);
  for(auto i : ans) cout << i << "\n";
  return;
}