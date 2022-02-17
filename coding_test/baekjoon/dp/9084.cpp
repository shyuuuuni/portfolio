/*
Time : 2022.02.16 (30 mins)
Problem : BOJ9084 (https://www.acmicpc.net/problem/9084)
Algorithm Type : DP
Outline :
동전의 개수와 동전이 가지고 있는 가치가 주어진다.
해당 동전들로 만들어야 할 금액 M이 주어졋을 때,
해당 동전들로 만드는 경우의 수를 출력한다.
Method :
d[i]를 i원을 만드는 경우의 수를 저장하는 배열로 사용한다.
모든 동전들에 대해서, d[i]를 각각 갱신한다.
즉, d[i]는 현재 j번째 동전까지 사용했을 때 만드는 경우의 수를 의미한다.
j번째 동전까지 (가치를 val 이라고 함) 사용한 d[i]는, 기존 배열에서
d[i-val] 값, 즉 i원에서 현재 동전 하나를 사용한 값을 만드는 경우의 수에 j번째 동전을 하나 추가할 수 있다.
즉, d[i](j번째 동전의 경우) = d[i-val] 이고, 이 값을 계속 유지해야 하기 때문에 = 대신 +=로 저장한다.
이를 반복해서 n가지 동전을 사용했을 때의 d[m]을 계산한다.
Example :
3
2
1 2
1000
3
1 5 10
100
2
5 7
22
-------
501
121
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

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc) {
    tc--;
    int n, m;
    cin >> n;
    int a[20+5] = {};
    int d[10000+5] = {}; // d[i] : i라는 수를 만들기 위한 경우의 수
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    cin >> m;
    /*
    2원 동전 5원 동전 7원 동전
    2원만 쓸때
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    0 0 1 0 1 0 1 0 1 0 1  0  1  0  1  0
    2원+5원 쓸때
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
    0 0 1 0 1 1 1 1 1 1 2  1  
    */
    d[0] = 1;
    for (int i=0; i<n; i++) {
      // i번째 동전까지 사용했을 때 경우의 수
      int val = a[i];
      for (int j=0; j<=m; j++) { // j원을 만드는 경우의 수
        if (j-val < 0) continue;
          d[j] += d[j-val];
      }
      // for (int x = 0; x <= m; x++) cout << d[x] << " ";
      // cout << "\n";

    }

    cout << d[m] << "\n";


  }
  return 0;
}