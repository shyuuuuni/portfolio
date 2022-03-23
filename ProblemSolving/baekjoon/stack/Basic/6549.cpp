/*
Time : 2022.01.08 (30 min)
Problem : BOJ6549 (https://www.acmicpc.net/problem/6549)
Algorithm Type : Stack
Outline :
너비가 1인 직사각형이 일렬로 여러개 붙어서 세워져있다.
직사각형의 높이가 주어졌을 때, 그림에서 가장 넓이가 큰 직사각형의 크기를 출력한다.
Method :
-해결중-
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int check[80000+1];
int solve1() {
  while(1) {
    int n; cin >> n;
    long long h, ans=0;
    stack<pair<long long,long long> > stk; // (가로길이, 세로길이)
    if(!n) break;
    while(n--) {
      cin >> h;
      stk.push({1, h});
    }
    while(1 < stk.size()) {
      
    }
    cout << ans;
  }
  return 0;
}