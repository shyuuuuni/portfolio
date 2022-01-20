/*
Time : 2022.01.20 (30 min)
Problem : BOJ2447 (https://www.acmicpc.net/problem/2447)
Algorithm Type : Recursion
Outline :
재귀적인 패턴으로 별을 찍는다.
N=3일때 다음과 같이
***
* *
***
별을 찍는다.
Method :
star(n,x,y) 는 (x,y)부터 가로/세로 각각 n 범위에 별을 찍는다.
만약 n이 9이상이라면 범위를 9등분한다.
n이 3이라면 별을 찍는다. 이때 중앙의 공간은 비워둔다.
9등분을 할 때 재귀적으로 star함수를 호출한다. 이때 마찬가지로 중앙이 비어야하기 때문에 중앙 범위에서는
space함수를 호출한다.
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

vector<vector<char> > v(6561+1, vector<char>(6561+1,' '));

void space(int n, int x, int y) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      v[x+i][y+i] = ' ';
    }
  }
}

void star(int n, int x, int y) {
  int nxt = n/3;
  // cout << n << " (" << x << " " << y << ")\n";
  if(n==1) return;
  if(n >= 9) {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(i==1 && j==1) space(nxt, x+nxt*i, y+nxt*j);
        else star(nxt, x+nxt*i, y+nxt*j);
      }
    }
  } else {
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        if(i==1 && j==1) v[x+i][y+j] = ' ';
        else v[x+i][y+j] = '*';
      }
    }
  }
  return;
}

void solve() {
  int n;
  cin >> n;
  star(n,0,0);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << v[i][j];
    }
    cout << "\n";
  }
  return;
}