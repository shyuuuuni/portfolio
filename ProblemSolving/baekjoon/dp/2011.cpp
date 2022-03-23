/*
Time : 2022.02.17
Problem : BOJ2011 (https://www.acmicpc.net/problem/2011)
Algorithm Type : DP
Outline :
A를 1이라고 하고, B는 2로, 그리고 Z는 26으로 문자를 암호화 하려고 한다.
암호가 주어지면 여러가지로 해석될 수 있다 (ex 11 = (1)(1) or (11))
해석할 수 잇는 가짓수를 출력한다.
Method :
d[i]를 (계산상 편의를 위해서 1-indexed를 사용함) 암호의 a[i-1] 까지 사용했을 때
만들 수 있는 경우의 수를 저장한다.
dp를 계산하기 전에, 만약 암호의 시작이 '0'이라면 항상 불가능하다. (0이 될 수 있으려면 10, 20밖에 안됨)
d[i]는 다음과 같은 조건으로 계산된다.
1. 만약 a[i-1](이번에 보는 값) 이 '0'일 경우
  1-1. 만약 a[i-2](전 시행에서 가장 오른쪽에 있던 암호) 값이 '0' 또는 '3'~'9' 일 경우 불가능 (flag=0)
  1-2. 만약 1-1이 아닐 경우 '10', '20' 으로 사용해야만 하므로 d[i] = d[i-2];
2. 만약 a[i-1]이 '0'이 아닌 경우
  1-1. a[i-2]가 '1'인 경우 '1'+@를 해도 '1''@' 또는 '1@' 경우가 가능함 d[i] = d[i-1]+d[i-2]
  1-2. a[i-2]가 '2'인 경우 '2'로 시작하는 값은 z '26'이 마지막임
    1-2-1. a[i-1]이 '1' ~ '6' 인 경우 1-1과 같음. d[i] = d[i-1]+d[i-2]
    1-2-2. 이외의 경우 따로따로 쓰는 방법밖에 없음. d[i] = d[i-1]
  1-3. 이외의 경우는 ~~'3' + '5'와 같이 따로 따로 봐야하는 경우이므로 d[i] = d[i-1]
0에 대한 예외처리를 잘 해주면서 dp를 계산한다.
Example :
25114
-------
6
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
  string a;
  ll d[5000+5] = {}; // d[i] : ith 암호까지 봤을 때 경우의 수
  int flag = 1;
  cin >> a;
  /*
  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
  
  여기서 0이 등장하는 경우 -> j(10), t(20)

  1 + @로 1~9를 붙일 경우 (1)(@) or (1@) 의 경우가 가능함

  2 + @로 1~6을 붙인 경우 (2)(@) or (2@) 의 경우가 가능함
  2 + @로 2~9를 붙인 경우 (2)(@)만 가능함

  3~9는 뒤에 +@를 해도 새로운 암호가 될 수 없음


  00 or 3~9+0 -> 오류
  */
  if (a[0]=='0') {
    cout << "0";
    return 0;
  }
  d[0] = 1; // base condition
  d[1] = 1; // a[0]하나만 있는 경우
  for (int i=2; i<=(int)a.size() && flag; i++) {
    char p = a[i-2];
    char c = a[i-1];
    if (c == '0') {
      if (p=='0' || '2'<p) {
        flag = 0;
      } else {
        /*
        111
         -> d[i-1] = 3
        111 + 0 -> 0을 살리려면 (10)만 써야함 = 11 + [10]
         -> d[i] = d[i-2] = 2
        */
        d[i] = d[i-2];
      }
    } else {
      if (p=='1') {
        d[i] = (d[i-1] + d[i-2]) % 1000000; // c를 p와 같이 쓰거나 따로 쓰거나
      } else if (p=='2') {
        if ('1'<=c && c<='6') {
          d[i] = (d[i-1] + d[i-2]) % 1000000; // c를 p와 같이 쓰거나 따로 쓰거나
        } else {
          d[i] = d[i-1]; // c를 p와 따로 써야만 함
        }
      } else {
        d[i] = d[i-1]; // c를 p와 따로 써야만 함
      }
    }
    d[i] = d[i]%1000000;
  }

  cout << (flag ? d[(int)a.size()] : 0);

  return 0;
}