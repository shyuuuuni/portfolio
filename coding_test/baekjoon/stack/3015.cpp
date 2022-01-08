/*
Time : 2022.01.08 (10+ hours)
Problem : BOJ3015 (https://www.acmicpc.net/problem/3015)
Algorithm Type : Stack
Outline :
N명이 한줄로 서서 기다리고 있다.
사람 A와 B 사이에 둘중 하나보다 키가 큰 사람이 없으면 서로 볼 수 있다.
줄에 서있는 사람의 키들이 주어졌을 때, 서로 불 수 있는 쌍의 수를 출력한다.
Method :
pair에 두개의 정수를 저장한다. first 는 높이, second는  높이인 사람의 수를 의미한다.
stk을 다음과 같이 정의했다.
"현재까지 본 사람 중 stk.top()보다 키가 작은 사람 중 가장 큰 사람을 top()에 위치시킨다."
즉, [5 4 3 2 1(top)] 과 같이 위치시키거나
[5 4 1] 에서 다음 사람이 3인 경우 1을 처리해주고 [5 4 3] 을 보유하도록 한다.

두번째 경우 현재 stk.top() <-> 새로운 사람 쌍을 만들 수 있으므로 stk.top().second (그 사람 수) 만큼 ans를 증가시킨다.

이후 stk의 정의에 부합하도록 처리를 반복해서 진행해준다.
stk.top()을 계속 확인하면서 top()의 키가 더 클때까지 반복한다.
만약 같을 경우에는 해당 높이의 사람이 한명 더 있는 것으로 처리한다. (cnt += ...)

마지막으로 이미 왼쪽에 더 큰 사람이 있을때 그 사람과 이번에 들어온 사람의 눈이 마주칠 수 있다.
따라서 stk.empty()를 통해 왼쪽에 사람이 있는지 확인을 해주고, 만약 있다면 정답을 1 증가시킨다.

여기까지 처리한 이후, 계산해둔 cnt(처리 안된 해당 높이의 사람 수) 를 이용하여
페어를 스택에 추가한다.
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int solve2();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int solve1() {
  long long ans=0, cnt, n, i, h;
  stack<pair<int,int> > stk;
  // stk : 지금까지 본 사람들 중에서 stk.top()보다 큰 값이 없도록 유지.
  // stk : [5 5 4 4 1(top)] 이런식, 만약 2라는 값이 들어오면 1을 빼고 2를 넣어준다.
  cin >> n;
  for(i=0; i<n; i++) {
    cin >> h;
    cnt = 1;
    while(!stk.empty() && stk.top().first <= h) {
      ans += stk.top().second; // top -> 현재 사람 보는 경우 처리
      if(stk.top().first == h) { // top과 현재 사람의 키가 같은 경우
        cnt += stk.top().second;
      } else {
        cnt = 1;
      }
      stk.pop();
    }
    if(!stk.empty()) ans++;
    stk.push(make_pair(h, cnt));
  }
  cout << ans;
  return 0;
}