/*
Time : 2022.02.03 (30 mins)
Problem : BOJ16985 (https://www.acmicpc.net/problem/16985)
Algorithm Type : Simulation
Outline :
5x5 크기의 미로가 5개 주어진다.
5개의 미로는 원하는데로 회전시킬 수 있다.
또한 미로를 겹쳐 쌓을 수 있고, 그 순서도 정할 수 있다.
쌓아 올린 미로의 한 꼭짓점을 입구로 하고, 그 입구와 닿아있는 면과 닿지 않은 곳에 있는 꼭짓점을 출구로 하는
최단 이동 횟수를 구하시오.
Method :
먼저 미로를 회전시키는 함수 rotation을 구현했다.
한 방향으로 회전하는 것을 구현하고, 나머지는 N번 돌려서 회전시킬 수 있지만, 시간 단축을 위해 각각 구현했다.
다음으로 미로를 쌓아 올리는 순서는 순열로 표현했다.
permutation[5] = {0,1,2,3,4} 로 선언하고, 이 배열은 next_permuation으로
0,1,2,3,4
0,1,2,4,3 <-ex
0,1,3,2,4
...
4,3,2,1,0
순서로 오름차순으로 표현되며,
permutation[i]는 입력받은 i번째 미로의 현재 위치를 permutation[i]로 한다는 뜻이다.
(ex) 4번째 입력으로 들어온 미로는 permutation[4] = 3 이므로 3번째 인덱스의 z좌표로 사용한다.
마지막으로 이렇게 조립한 큐브의 각 미로를 브루트포스 식으로 모든 경우를 따져서 돌려주었다.
이때 각 미로마다 4가지 경우의 수(회전0,1,2,3번)가 있으므로, 0부터 4^5-1 까지의 수를
4진수 표기로 각 자릿수를 회전 수로 사용하였다.
이후 큐브가 완성되면 (0,0,0)에서부터 BFS를 돌려 (4,4,4) 까지 가는 최단 경로를 검색한다.
모든 경우를 탐색하므로 최솟값을 갱신하며, 만약 갱신되지 않았다면 경로가 존재하지 않으므로 -1이다.
Example :
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
-------
12
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dz[6] = {-1,1,0,0,0,0};
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n = 5, mn = 100000000;
vector<vector<vector<int> > > cube1(5, vector<vector<int> >(5, vector<int>(5)));
vector<vector<vector<int> > > cube2(5, vector<vector<int> >(5, vector<int>(5)));

int permutation[5] = {0,1,2,3,4};

void rotation(int z, int n_rot) {
  // z번째 n x n 크기의 벡터를 회전, n_rot번 시계방향 회전
  if(n_rot == 0) return;

  vector<vector<int> > tmp(5, vector<int>(5));
  if(n_rot == 1) {
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        tmp[j][n-1-i] = cube2[z][i][j];
  } else if(n_rot == 2) {
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        tmp[n-1-i][n-1-j] = cube2[z][i][j];
  } else {
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        tmp[n-1-j][i] = cube2[z][i][j];
  }
  for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cube2[z][i][j] = tmp[i][j];
  return;
}

// bool oob(int x, int y, int nn, int mm) { // out of bound check
//   return (x<0 || y<0 || nn<=x || mm<=y);
// }

bool oob(int z, int x, int y) {
  return (z<0 || x<0 || y<0 || n<=z || n<=x || n<=y);
}

void solve() {
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      for(int k=0; k<n; k++)
        cin >> cube1[i][j][k];

  do {  
    for(int i=0; i<(1 << 2*5); i++) {
      // 순서를 설정해서, 연산용 벡터 cube2로 복사
      for(int j=0; j<n; j++)
        for(int k=0; k<n; k++)
          for(int l=0; l<n; l++)
            cube2[j][k][l] = cube1[permutation[j]][k][l];
      
      // 4진법으로 각 판이 회전을 얼마나 할지 결정
      int r = i;

      // 각 판 회전
      for(int j=0; j<n; j++) {
        int nr = r % 4; // 회전수
        r = r / 4; // 남은수
        rotation(j, nr);
      }

      // BFS로 최단거리 계산
      queue<pair<int,pii> > q; // z,(x,y) 저장
      int vis[5][5][5];
      fill_n(&vis[0][0][0], n*n*n, -1);
      if(cube2[0][0][0] == 0) continue;
      q.push(mp(0,mp(0,0)));
      vis[0][0][0] = 0;

      while(!q.empty()) {
        int z = q.front().first;
        int x = q.front().second.X;
        int y = q.front().second.Y;
        int d = vis[z][x][y];
        q.pop();
        if(z==n-1 && x==n-1 && y==n-1) {
          mn = min(d, mn);
          if(mn == 12) {
            cout << mn;
            return;
          }
          break;
        }
        for(int j=0; j<6; j++) {
          int nz = z + dz[j];
          int nx = x + dx[j];
          int ny = y + dy[j];
          if(oob(nz,nx,ny)) {
            continue;
          }
          if(vis[nz][nx][ny]!=-1 || cube2[nz][nx][ny]==0) {
            continue;
          }
          q.push(mp(nz,mp(nx,ny)));
          vis[nz][nx][ny] = d + 1;
        }
      }
    }
  } while(next_permutation(permutation, permutation+5)); // 순열로 쌓는 순서를 정함.

  if(mn == 100000000) cout << -1;
  else cout << mn;

  return;
}