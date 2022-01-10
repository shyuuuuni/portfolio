/*
Time : 2022.01.09 (15 min)
Problem : BOJ1021 (https://www.acmicpc.net/problem/1021)
Algorithm Type : Deque
Outline :
1부터 N까지의 수가 들어가있는 양방향 순환 큐를 이용하여 다음의 명령을 처리한다.
1. 첫번째 원소를 뽑아낸다.
2. 왼쪽으로 한칸 이동시킨다.
3. 오른쪽으로 한칸 이동시킨다.
주어진 수들을 순서대로 뽑아내기 위해 드는 2번,3번 연산의 최솟값을 출력한다.
Method :
STL Deque를 사용하여 구현한다.
find 함수는 해당 원소 위치의 iterator를 반환하는데,
int t = find() - dq.begin() 로 해당 index를 얻을 수 있다.
index가 다음과 같이 [0, 1, 2, ..., x, ..., N-1, N] 로 있으면, 
0 -> x의 경우 2번 연산이 t 개 만큼 필요하다.
N -> x의 경우 1번 연산이 front에서만 일어나기 때문에
3번 연산이 dq.size() - t 개 만큼 필요하다.
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int solve1() {
  int n, m, x, cnt, ans=0;
  deque<int> dq;
  cin >> n >> m;
  for(int i=1; i<=n; i++) dq.push_back(i);
  while(m--) {
    cin >> x;
    cnt = 0;
    while(dq.front() != x) {
      int t = find(dq.begin(), dq.end(), x) - dq.begin();
      if(t < dq.size() - t) {
        dq.push_back(dq.front());
        dq.pop_front();
      } else {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      cnt++;
    }
    dq.pop_front();
    ans += cnt;
  }
  cout << ans;
  return 0;
}