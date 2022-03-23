/*
Time : 2022.02.14 (10 mins)
Problem : BOJ2240 (https://www.acmicpc.net/problem/2240)
Algorithm Type : DP
Outline :
2개의 자두나무가 있다.
자두나무에서는 T초동안 매 초 하나의 자두가 둘 중 하나에서 떨어진다.
해당 시간에 나무 아래에 있다면, 자두를 주을 수 있다.
그러나 사람은 W번만 움직일 수 있다.
주울 수 있는 자두의 최대 개수를 출력한다.
Method :
d[time][move][tree] 를 다음과 같이 정의한다.
"시간 time에 move 번 이동해서 tree 번 나무에 서 있을 때 최대 획득 수"
그러면 각 시간에 대해서, w이하의 move에 대해서 다음과 같은 상황이 만족한다.
d[time][move][tree] = max(d[time-1][move][tree], d[time-1][move-1][anothre_tree])
즉, 이전과 같은 나무라면 move값을 그대로, 다른 나무라면 move를 한번 해야하므로 move-1에서 가져온다.
또한 arr[time] (= time번째에 자두가 떨어지는 나무) 값이 tree와 같으면 새로 하나를 주워야 하므로 +1을 해준다.

기본 조건으로 매 time마다 d[time][0][1] 을 초기화 했는데,
사람이 처음에 기본적으로 1번 나무에서 시작하기 때문에, d[time][0][2]는 존재할 수 없다.
따라서 [t][0][1]의 경우를 초기화해주면 되고, 그 값은 [t-1][0][1]값에 해당 time에 떨어지는 위치가 1이라면 +1을 하면 된다.

모든 시행 이후 해당 dp배열에서 최대값을 찾아서 출력한다.
Example :
7 2
2
1
1
2
2
1
1
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

const int arrlen = 1000+5;
const int wlen = 30+5;
int arr[arrlen];
int d[arrlen][wlen][3];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int t, w;
  cin >> t >> w;
  for (int i=1; i<=t; i++) cin >> arr[i]; // 1-indexed

  // dp
  for (int i=1; i<=t; i++) {
    d[i][0][1] = d[i-1][0][1] + (int)(arr[i]==1); // 이동X -> 1번 나무에 떨어질 경우 +1

    // move번 이동하는 경우 처리
    for (int move=1; move<=w && move<=i; move++) {
      if (arr[i] == 1) {
        d[i][move][1] = max(d[i-1][move][1], d[i-1][move-1][2]) + 1;
        d[i][move][2] = max(d[i-1][move-1][1], d[i-1][move][2]);
      } else {
        d[i][move][1] = max(d[i-1][move][1], d[i-1][move-1][2]);
        d[i][move][2] = max(d[i-1][move-1][1], d[i-1][move][2]) + 1;
      }
    }
  }

  int ans=0;
  for(int i=1; i<=t; i++) {
    for(int j=0; j<=w; j++) {
      for(int k=1; k<=2; k++) {
        ans = max(ans, d[i][j][k]);
      }
    }
  }

  cout << ans;

  return 0;
}