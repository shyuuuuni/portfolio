/*
Time : 2022.03.09
Problem : BOJ1507 (https://www.acmicpc.net/problem/1507)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
N개의 도시에 M개의 길로 연결되어 있다. 각 길마다 걸리는 시간이 정해져 있다.
모든 쌍의 도시에 대해서 최소 이동 시간을 구해놓았다.
해당 표를 보고, 모든 길의 시간의 합을 출력한다.
Method :
플로이드를 역으로 생각한다.
플로이드 와샬 알고리즘은 d[i][j] > d[i][k] + d[k][j] 일때 갱신한다.
즉, 올바른 입력이 들어왔다면 다음과 같이
1. i == j : d[i][i] = 0
2. i != j != k : i -> k -> j 이동
3. i == k or k == j : d[i][i] + d[i][j] or d[i][j] + d[j][j] = d[i][j] -> i j 사이 도로가 있다.
따라서 dist[i][j] (최소 거리) 값이 나오는 경우가 3번만 있다면 직선이 있어야만 하고, 그렇지 않다면 굳이 선을 그을 필요가 없다.
(선의 개수를 최소로 하므로 제외한다.)
따라서 직선을 그을 필요가 없다면 flag[i][j]를 1로 설정하고, 아니라면 0으로 유지한다.
flag[i][j] == 0 이면 i->j 선이 잇다는 뜻이므로 출력값에 dist[i][j]값을 더한다.
선이 양방향이므로 dist[j][i]값을 중복으로 더하지 않기 위해 flag값을 약간 변형했음에 유의하자.
Example :
5
0 6 15 2 6
6 0 9 8 12
15 9 0 16 18
2 8 16 0 4
6 12 18 4 0
-------
55
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
const int N = 25;
int dist[N][N];
int flag[N][N];
int n;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO
  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> dist[i][j];
    }
  }
  int isvalid = 1;
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (0 < dist[i][j] && dist[i][j] == dist[i][k] + dist[k][j]) {
          // 이미 저장된 i->j 최단 경로가 i->k->j를 통해서 가능한 경우
          if (!(i==k || k==j)) {
            // dist[i][j] = dist[i][i] + dist[i][j] or dist[i][j] + dist[j][j], 즉, 항상 참인 것 제외
            flag[i][j] = 1;
          }
        } else if (dist[i][j] > dist[i][k] + dist[k][j]) {
          isvalid = 0;
        }
      }
    }
  }
  if (!isvalid) {
    cout << -1;
    return 0;
  }
  int ans = 0;
  int num = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (!flag[i][j]) {
        ans += dist[i][j];
        flag[i][j] = flag[j][i] = 1;
        num ++;
      }
    }
  }
  cout << ans;
  return 0;
}
