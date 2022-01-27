/*
Time : 2022.01.27 (40 mins)
Problem : BOJ14499 (https://www.acmicpc.net/problem/14499)
Algorithm Type : Simulation
Outline :

Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m, x, y, k;
int board1[25][25];

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || n<=y);
}

void solve() {
  cin >> n >> m >> x >> y >> k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board1[i][j];
    }
  }
  return;
}