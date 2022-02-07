/*
Time : 2022.02.07 (30 mins)
Problem : BOJ2800 (https://www.acmicpc.net/problem/2800)
Algorithm Type : Backtracking
Outline :
괄호와 숫자, 연산기호로 이루어진 식이 주어진다.
주어진 식에서 최소 하나 이상의 괄호쌍을 지웠을때 얻을 수 있는
서로다른 식을 사전순으로 출력한다.
Method :
괄호쌍을 배열로 저장해서, 배열의 인덱스 기준으로 백트래킹을 통해
해당 인덱스의 괄호쌍을 적용할 것인지, 뺄 것인지 적용하여 모두 탐색한다.
flag변수는 현재까지 지운 괄호 쌍의 개수를 의미하며, 최소 하나 이상의 괄호쌍을
지웠을때만 정답 셋에 추가한다.
셋을 사용한 이유는 다른 괄호쌍을 지우더라도 같은 결과값이 나올 수 있기 때문에
중복값을 제거하기 위해서 셋을 사용한다.
Example :
(0/(0))
=====
(0/0)
0/(0)
0/0
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

// bool compare(const string& a, const string& b) {
//   // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
//   // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
//   // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
//   // 래퍼런스 사용하는게 좋음
// }

string origin;
vector<pii> bk;
set<string> ans;
stack<int> opn;

void solve(int idx, int flag) {
  if(idx == bk.size()) {
    if(!flag) return;
    string cur = "";
    for(int i=0; i<origin.size(); i++)
      if(origin[i]!='.') cur += origin[i];
    ans.insert(cur);
    return;
  }
  // idx번째 괄호를 안쓸 때
  origin[bk[idx].first] = '.';
  origin[bk[idx].second] = '.';
  solve(idx+1, flag+1);
  origin[bk[idx].first] = '(';
  origin[bk[idx].second] = ')';

  // idx번째 괄호를 안 쓸때
  solve(idx+1, flag);
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> origin;
  for(int i=0; i<origin.size(); i++) {
    if(origin[i] == '(') opn.push(i);
    else if(origin[i] == ')') {
      bk.push_back(mp(opn.top(), i));
      opn.pop();
    }
  }
  
  solve(0, 0);
  for(string s : ans) cout << s << "\n";
  return 0;
}