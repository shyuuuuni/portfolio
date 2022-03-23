/*
Time : 2022.02.07 (10 mins)
Problem : BOJ1027 (https://www.acmicpc.net/problem/1027)
Algorithm Type : Math
Outline :
N개의 빌딩이 각각 높이를 가지고 있다.
고층빌딩 A에서 다른 고층 빌딩 B가 볼 수 있는 빌딩이 되려면
두 지붕을 잇는 선분이 다른 빌딩을 지나거나 접하지 않아야 한다.
가장 많은 고층 빌딩이 보이는 빌딩을 구하고, 거기서 보이는 빌딩의 수를 출력한다.
Method :
좌측 빌딩부터 순서대로 자기보다 오른쪽에 있는 건물의 기울기로 계산한다.
처음 빌딩은 무조건 연결되므로 prev_grad를 초기화하면서 연결한다.
이후 prev_grad는 지금까지 본 다른 빌딩과의 기울기의 최대값을 의미한다.
다음 나오는 빌딩마다 grad를 계산한 후, prev_grad보다 크다면 볼 수 있고,
작다면 볼 수 없다.
볼때마다 횟수를 저장하는 배열을 하나 만들어서 값을 증가시키고, 최댓값을 출력한다.
Example :
15
1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
=====
7
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

// bool compare(const string& a, const string& b) {
//   // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
//   // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
//   // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
//   // 래퍼런스 사용하는게 좋음
// }

// 점 p1과 p2를 지나는 직선의 기울기를 리턴
long double get_gradient(long double x1, long double y1, long double x2, long double y2) {
  return (y2 - y1) / (x2 - x1);
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int connect[50+5] = {0,};
  long double building_y[50+5] = {};
  cin >> n;
  for(int i=0; i<n; i++) cin >> building_y[i];

  for(int i=0; i<n; i++) {
    long double x1 = (long double)i;
    long double y1 = building_y[i];
    long double prev_grad;
    for(int j=i+1; j<n; j++) {
      long double x2 = (long double)j;
      long double y2 = building_y[j];
      long double grad = get_gradient(x1,y1,x2,y2);
      if(j == i+1) {
        connect[i]++;
        connect[j]++;
        prev_grad = grad;
        continue;
      }
      if(prev_grad < grad) {
        connect[i]++;
        connect[j]++;
      }
      prev_grad = max(grad, prev_grad);
    }
  }
  cout << *max_element(connect, connect+n);
  return 0;
}