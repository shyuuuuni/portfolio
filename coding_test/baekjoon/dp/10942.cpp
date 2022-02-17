/*
Time : 2022.02.16
Problem : BOJ10942 (https://www.acmicpc.net/problem/10942)
Algorithm Type : DP
Outline :
자연수 N개를 칠판에 적는다. 그 다음, 명우에게 질문을 총 M번 한다.
질문에는 S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지를 물어보고 답한다.
Method :
d[i][j]를 i<=j일 때, 부분수열 i:j가 펠린드롬이면 1, 아니면 0을 저장하도록 정의한다.
먼저 수열을 입력받으면서, d[i][i] = 1로 저장한다. (길이가 1인 수열은 펠린드롬)
이후 d 배열을 부분 수열의 길이 l을 기준으로 갱신한다.
l값을 2부터 n까지 반복하면서 길이가 l인 부분수열이 펠린드롬인지 확인한다.
펠린드롬인지 확인하는 방법은, 길이가 l인 부분수열의 시작점 i와 끝점 i+l-1의 값이 같은지 확인하고,
1. 만약 같다면 시작점의 오른쪽과 끝점의 왼쪽을 범위로 하는 부분수열이 펠린드롬인지 확인한다. (d[i+1][i+l-2])
2. 만약 다르다면 펠린드롬이 아니다. (=0)
위와 같이 반복한 후, 쿼리에 따라 출력하면 된다.
Example :
7
1 2 1 3 1 2 1
4
1 3
2 5
3 3
5 7
-------
1
0
1
1
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


int a[2000+5] = {};
int d[2000+5][2000+5] = {};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    d[i][i] = 1; // 원소 하나는 펠린드롬이다.
  }
  /*
  a : 1 2 3 2
  -> d배열 : 4x4
  (00) (01) (02) (03)
  */
  for (int l=2; l<=n; l++) { // 길이가 l인 펠린드롬 갱신
    for (int i=0; i+l-1<n; i++) { // [i:i+l)이 펠린드롬인지 갱신
      if (a[i] == a[i+l-1]) {
        if (l==2) {
          d[i][i+1] = 1;
        } else {
          d[i][i+l-1] = d[i+1][i+l-2];
        }
      } else {
        d[i][i+l-1] = 0;
      }
    }
  }
  // for (int i=0; i<n; i++) {
  //   for (int j=0; j<n; j++) {
  //     cout << d[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cin >> m;
  while (m--) {
    int s, e;
    cin >> s >> e;
    cout << (int)(d[s-1][e-1]==1) << "\n";
  }
  return 0;
}