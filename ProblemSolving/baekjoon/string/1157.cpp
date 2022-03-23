/*
Time : 2022.02.14 (30 mins)
Problem : BOJ1157 (https://www.acmicpc.net/problem/1157)
Algorithm Type : String
Outline :
문자열이 주어졌을 때, 해당 문자열 내에서 가장 많이 사용된 알파뱃이 무엇인지 알아낸다.
(이때 대소문자를 구분하지 않는다.)
Method :
문자형(char)는 결국 아스키코드로 숫자로 변환할 수 있으므로
이를 인덱스로 하는 배열을 만들어서 카운팅한다.
Example :
Mississipi
-------
? (여러개 존재할 경우 ? 출력)
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

bool compare(const string &a, const string &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};

// 문자열을 구분자를 기준으로 나눠서 벡터에 저장
int splitStringByToken(vector<string> &v, string &s, const char &del) {
  if(s.empty()) return 0;
  istringstream ss(s);
  string token;

  v.clear();
  while (getline(ss, token, del)) {
    if(!token.empty()) v.push_back(token);
  }

  return v.size();
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int cnt[26] = {};

  for (auto c : s) {
    int idx;
    if ('A' <= c && c <= 'Z') {
      idx = c-'A';
    } else {
      idx = c-'a';
    }
    cnt[idx]++;
  }

  int mx=0;
  int flag = 0;
  for (int i=1; i<26; i++) {
    if (cnt[mx] < cnt[i]) {
      mx = i;
      flag = 0;
    } else if (cnt[mx] == cnt[i]) {
      flag = 1;
    }
  }

  if (flag) cout << '?';
  else cout << (char)(mx + 'A');

  return 0;
}