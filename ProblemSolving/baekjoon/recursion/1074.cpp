/*
Time : 2022.01.20 (30 min)
Problem : BOJ1074 (https://www.acmicpc.net/problem/1074)
Algorithm Type : Recursion
Outline :
2^N x 2^N 크기의 2차원 배열을 Z모양으로 탐색한다.
좌표가 주어졌을 때, 해당 위치를 몇번째로 탐색하는지 출력한다.
Method :
재귀 함수를 구현하여 해결하였다.
travle(n,r,c)는 2^n x 2^n 크기에서 (r,c) 위치의 방문 횟수를 리턴한다.
타일을 4등분내면 왼쪽위(1)->오른쪽위(2)->왼쪽아래(3)->오른쪽아래(4) 순서로 방문한다.
(r,c)의 위치를 판단하여 1~4의 위치를 생각하고,
1번일 경우 n을 1 줄인 travel(n-1,r,c)를 리턴한다.
2번일 경우 1번을 들렸다 왔으므로 (1번의 타일 개수) + travle(n-1,r,c-half)를 리턴한다.
3번일 경우 1,2번을 들렸다 왔으므로 (1,2번의 타일 개수) + ...
이런식으로 재귀적으로 해결한다.
base condition은 n=0일 경우로, 이때는 0을 리턴한다.
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

// 2^n x 2^n 크기에서 (r,c) 위치 방문 순서를 리턴
int travel(int n, int r, int c) {
  if(n == 0) return 0; // base condition
  int half = (1<<n) / 2;
  if(r<half && c<half) {
    // 왼쪽-위(1)
    return travel(n-1, r, c);
  } else if(r<half && half<=c) {
    // 오른쪽-위(2)
    return half*half + travel(n-1, r, c-half);
  } else if(half<=r && c<half) {
    // 왼쪽-아래(3)
    return 2*half*half + travel(n-1, r-half, c);
  } else {
    // 오른쪽-아래(4)
    return 3*half*half + travel(n-1, r-half, c-half);
  }
}

void solve() {
  int n, r, c;
  cin >> n >> r >> c; // (r,c)가 몇번째 탐색인지 출력
  cout << travel(n,r,c);
  return;
}