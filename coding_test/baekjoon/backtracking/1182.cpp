/*
Time : 2022.01.21 (30 min)
Problem : BOJ1182 (https://www.acmicpc.net/problem/1182)
Algorithm Type : Backtracking
Outline :
N개의 정수 수열에서, 부분수열의 합이 S인 경우의 개수를 출력한다.
Method :
nums에 수열을 저장한다.
ans는 부분수열의 개수이다.
cur는 현재 부분수열의 합이다.
i는 현재 부분수열에 포함된 원소의 개수이다. (s=0일때 하나도 들어가지 않는 경우는 세지 않음.)
func(idx)는 수열의 idx를 포함/미포함 했을 경우
부분수열을 끝까지 확인해주는 함수이다.
부분수열을 끝까지 탐색했을때 부분수열에 원소가 있고, 그 합이 s라면 ans를 1 증가시킨다.
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

int n,s;
int nums[20+1];
int ans=0, cur=0, i=0;

void func(int idx) {
  if(idx == n) {
    if(cur == s && i) {
      ans++;
    }
    return;
  }
  cur += nums[idx];
  i++;
  func(idx+1);
  cur -= nums[idx];
  i--;
  func(idx+1);
  return;
}

void solve() {
  cin >> n >> s;
  for(int i=0; i<n; i++)
    cin >> nums[i];
  func(0);
  cout << ans;
  return;
}