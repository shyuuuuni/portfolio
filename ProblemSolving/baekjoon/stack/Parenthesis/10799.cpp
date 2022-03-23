/*
Time : 2022.01.10 (10 min)
Problem : BOJ10799 (https://www.acmicpc.net/problem/10799)
Algorithm Type : Stack
Outline :
쇠막대기를 레이저로 자르는 모양을 괄호로 표현한다.
레이저는 인접한 괄호쌍 () 로 표현한다.
쇠막대기는 시작점이 여는 괄호, 끝점이 닫는 괄호로 표현한다.
괄호 표현이 주어졌을 때, 쇠막대기가 총 몇개로 조각나는지 표현한다.
Method :
스택을 이용하여 해결한다.
스택에는 여는 괄호 '(' 를 저장한다.
만약 닫는 괄호 ')'가 들어오면, 두가지 경우가 있다.
1. 이전에 여는 괄호가 나온 경우 '...()' -> 레이저
2. 이전에 닫는 괄호가 나온 경우 '...))' -> 쇠막대기
레이저인 경우, 현재 스택에 저장된 여는 괄호의 수 = 쇠막대기의 수 만큼 조각이 생긴다.
닫는 괄호가 생길 경우, --|--|--- 와 같이 잘리고 마지막 조각을 세주어야 한다.
위의 경우를 처리하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

void solve1() {
  int ans=0;
  string s;
  stack<char> stk;
  char prv = 'x';
  cin >> s;
  for(auto c : s) {
    if(c == '(') {
      stk.push(c);
    } else {
      if(stk.empty()) continue;
      else if(stk.top() == '(') {
        stk.pop();
        if(prv == '(') ans += stk.size();
        if(prv == ')') ans++;
      }
    }
    prv = c;
  }
  cout << ans;
  return;
}