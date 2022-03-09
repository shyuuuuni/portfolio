/*
Time : 2022.03.09
Problem : BOJ11562 (https://www.acmicpc.net/problem/11562)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
n개의 건물과 그 사이를 잇는 m개의 길이 주어진다.
길은 단방향 길도 있고, 양방향 길도 있다.
어떤 두 건물 사이의 길은 한개뿐이고, 현재 길로는 도착할 수 없는 건물이 존재할 수 있다.
출발 건물과 도착 건물이 주어졌을 때, 최소 몇개의 길을 양방향으로 바꾸어야 해당 도착 건물로 도착할 수 있는지 출력하는 프로그램을 작성한다.
Method :

Example :
4 3
1 2 0
2 3 1
3 4 0
7
1 1
1 2
2 1
1 4
4 1
2 3
4 3
-------
0
0
1
0
2
0
1
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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const int INF = 0x3f3f3f3f;
const int N = 405;
int v, e;
int dist[N][N];

int main(void) {
  cin >> v >> e;
  fill(&dist[0][0], &dist[N-1][N], INF);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < dist[a][b]) {
      dist[a][b] = c;
    }
  }
  for (int i=1; i<=v; i++) dist[i][i] = 0;
  // FW
  for (int k=1; k<=v; k++) {
    for (int i=1; i<=v; i++) {
      for (int j=1; j<=v; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  int ans = INF;
  for (int i=1; i<=v; i++) { // 출발지
    for (int j=1; j<=v; j++) {
      if (i==j) continue;
      if (dist[i][j] + dist[j][i] < ans) {
        ans = dist[i][j] + dist[j][i];
      }
    }
  }

  if (INF <= ans) cout << -1;
  else cout << ans;

  return 0;
}
