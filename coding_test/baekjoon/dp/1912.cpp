/*
Time : 2022.02.10 (10 mins)
Problem : BOJ1912 (https://www.acmicpc.net/problem/1912)
Algorithm Type : Dynamic Programming
Outline :
n개의 수로 이루어진 정수 수열이 주어진다.
연속해서 선택한 부분수열의 합이 최대가 되도록 선택하는 프로그램을 작성한다.
Method :
dp[i]를 i번째 수를 선택했을 때 최대가 되는 합으로 정의한다.
그럼 다음과 같이 두가지 경우의 수가 존재한다.
1. i번째와 그 이전을 이어서 보는 경우 -> dp[i-1] + arr[i]
2. i번째부터 새로 보는 경우 -> arr[i]
두 경우 중 최대값으로 갱신한 뒤, 마지막으로 dp값이 최대가 되는 값을 출력한다.
이때 원소를 최소 하나 이상 선택해야 하므로, 처음에 dp[0]값을 max(0,arr[0])이 아닌 arr[0]으로 둔다.
Example :
10
10 -4 3 1 5 6 -35 12 21 -1
-------
33
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

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int arr[100000+5] = {}; // -1000 ~ 1000
  int dp[100000+5] = {};
  cin >> n; // 최대 100,000
  for(int i=0; i<n; i++) cin >> arr[i];
  dp[0] = arr[0];
  for(int i=1; i<n; i++) dp[i] = max(arr[i], dp[i-1]+arr[i]); // 새로 시작 or 이어서
  cout << *max_element(dp, dp+n);
  return 0;
}