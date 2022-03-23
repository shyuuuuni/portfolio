/*
Time : 2022.01.06 (15 min)
Problem : BOJ13300 (https://www.acmicpc.net/problem/13300)
Algorithm Type : Array
Outline :
수학여행 방 배정 과정에서 다음과 같은 조건에 맞춰서 방을 배정해야 한다.
1. 성별이 동일해야한다.
2. 학년이 동일해야한다.
최소한의 방의 개수를 출력한다.
Method :
성별과 학년에 따른 학생수를 각각 저장하기 위해 이중배열로 students[][] 배열을 선언한다.
각 성별-학년에 대하여 필요한 방의 수를 구하기 위해, 학생수가 0이 아닌 집단에 대해서
(student[i][j]+k-1) / k 를 통해 필요한 방의 개수를 모두 더해 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, s, y, ans=0;
  int students[2][6] = {};
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    cin >> s >> y;
    students[s][y-1]++;
  }
  for(int i=0; i<2; i++) {
    for(int j=0; j<6; j++) {
      if(students[i][j])
        ans += (students[i][j] + k - 1) / k;
    }
  }
  cout << ans;
  return 0;
}