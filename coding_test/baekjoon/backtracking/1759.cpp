/*
Time : 2022.02.21
Problem : BOJ1759 (https://www.acmicpc.net/problem/1759)
Algorithm Type : Backtracking
Outline :
암호가 L개의 서로 다른 알파벳 소문자로 구성되어 있으며, 최소 한개의 모음과 최소 두개의 자음으로 구성되어 있다고 한다.
또한 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었다.
C개의 문자로 암호를 구성한다. 문자들로 만들 수 있는 가능성 있는 암호를 모두 사전식으로 출력한다.
Method :
전형적인 백트래킹 방식으로 해결하였다.
먼저 암호는 증가하는 순서로 배열되므로, 입력한 암호가 될 수 있는 알파벳들을 먼저 정렬하였다.
이후 dfs(idx, len, vowel, cons) 라는 함수를 통해 가능한 경우를 출력해주었다.
idx는 현재 보고있는 인덱스, 즉 암호가 될 수 있는 알파벳을 의미한다.
len은 현재까지 저장한 암호의 길이를 의미하고,
vowel과 cons는 각각 암호에 포함된 모음과 자음의 개수를 의미한다.
탐색을 하면서, 만약 len이 암호의 길이 l이라면 바로 출력하면 된다.
왜냐하면 정렬된 배열에서, 현재것을 사용하는 것을 먼저 탐색하도록 구현했기 때문에 사전순으로 탐색하게 된다.
또한 만약 idx가 out of bound일 경우는 즉시 종료한다.
Example:
4 6
a t c i s w
-------
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

int charToInt(char c) {
  if ('A' <= c && c <= 'Z')
    return (int)(c - 'A');
  else if ('a' <= c && c <= 'z')
    return (int)(c - 'a');
  else if ('0' <= c && c <= '9')
    return (int)(c - '0');
  return -1;
}

int l, c; // 암호에 포함된 알파벳 : l개, 사용할 수 있는 알파뱃 : c개
string tmp = "";
char a[20] = {};
vector<string> ans;

void dfs(int idx, int len, int vowel, int cons) {
  if (len == l) {
    if (0<vowel && 1<cons) {
      cout << tmp << "\n";
    }
    return;
  }
  if (idx == c) return;
  char cur = a[idx];
  int is_vowel = (cur=='a'||cur=='e'||cur=='i'||cur=='o'||cur=='u'); // 모음 여부
  tmp.push_back(cur);
  dfs(idx+1, len+1, vowel+is_vowel, cons+!is_vowel);
  tmp.pop_back();
  dfs(idx+1, len, vowel, cons);
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> l >> c;
  for (int i=0; i<c; i++) {
    cin >> a[i];
  }
  sort(a, a+c);
  dfs(0,0,0,0);
  // sort(ans.begin(), ans.end());
  // for (string s : ans) {
  //   cout << s << "\n";
  // }

  return 0;
}