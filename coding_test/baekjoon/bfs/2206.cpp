/*
Time : 2022.01.12 (25 min)
Problem : BOJ2206 (https://www.acmicpc.net/problem/2206)
Algorithm Type : BFS
Outline :
NxM 행렬로 표현되는 맵이 있다.
1. '0' : 이동할 수 있는 위치
2. '1' : 이동할 수 없는 벽
(1,1)에서 (N,M)으로 이동할 때 최댄 경로로 이동하려 한다.
이동하는 중 한개의 벽을 부수고 이동하는 것이 경로가 짧아진다면 한개의 벽을 부수고 이동할 수 있따.
최단 경로를 출력한다.
Method :

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
int dy[4] = {0,1,0,-1};
void solve() {
  int n, m;
  string arr[1000+1];
  cin >> n >> m;  // 세로(x), 가로(y)
  for(int i=0; i<n; i++)
    cin >> arr[i];
  return;
}