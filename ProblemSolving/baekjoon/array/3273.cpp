/*
Time : 2022.01.06 (25 min)
Problem : BOJ3273 (https://www.acmicpc.net/problem/3273)
Algorithm Type : Array
Outline :
양의 정수 배열 a1, a2, ..., an에서
ai + aj = x를 만족하는 (ai, aj) 쌍 (1<=i<j<=n) 의 수를 출력한다.
Method :
입력 순서가 n->정수배열->x이므로 입력과 동시에 처리할 수 없어서 아쉬웠다.
cnt 배열의 크기를 x만큼 잡아야 하기 때문에 굉장히 커서, 전역 변수로 선언했다.
입력을 먼저 받은 후, 각 정수 배열을 한번씩 순회하면서
두 수의 합이 x라는 것은 x-(arr[i]) 값이 존재한다면 (ai, aj)가 존재한다는 것을 의미한다.
따라서 빈도를 저장하는 배열인 cnt의 x-arr[i] 값을 참조하면, cnt[x-arr[i]] 만큼 쌍이 존재한다는 것을 알 수 있다.
그러나 이때 x-arr[i]값이 음수가 될 수 있으므로 조건을 신경써야 한다.
*/
  int arr[100000 + 1];
  int cnt[2000000 + 1];
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, val, ans=0;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cin >> x;
  for(int i=0; i<n; i++) {
    if(0 <= x-arr[i] && cnt[x-arr[i]])
      ans += cnt[x-arr[i]];
    cnt[arr[i]]++;
  }
  cout << ans;
  return 0;
}