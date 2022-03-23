/*
Time : 2022.01.20 (20 min)
Problem : BOJ1992 (https://www.acmicpc.net/problem/1992)
Algorithm Type : Recursion
Outline :
흰 점(0)과 검은 점(1)로 이루어진 2차원 배열이 주어진다.
쿼드 트리는 주어진 영상이 모두 0 또는 1로 주어진다면 해당 숫자로 압축한다.
만약 섞여있다면 4개의 영상으로 나누어 압축하고, 4개의 영역을 괄호 안에 묶어서 표현한다.
배열이 주어지면 압축한 결과를 출력한다.
Method :
qtree(n, x, y)를 (x,y) 점부터 가로,세로 nxn 크기를 확인하는 재귀함수로 정의한다.
해당 점부터 nxn크기의 각각의 배열를 확인하면서 (x,y)점과 다른 숫자가 하나라도 발견된다면 4등분으로 나눈다.
만약 발견되지 않았다면 해당 숫자를 출력한다.
발견되었다면 먼저 여는 괄호를 출력하고, 재귀적으로 4등분한 좌표를 넣고, n의 값을 1/2로 줄여서 반복한다.
위 재귀 호출에서 괄호 안의 숫자가 출력되고, 모든 호출이 끝나면 닫는 괄호를 출력한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

vector<string> v(64+1);
int qtree(int n, int x, int y) {
  int flag=1, half=n/2;
  char val = v[x][y];
  if(n==1) {
    cout << val;
    return val-'0';
  }
  for(int i=0; flag&&i<n; i++) {
    for(int j=0; flag&&j<n; j++) {
      if(val != v[x+i][y+j]) flag=0;
    }
  }
  if(flag) {
    cout << val;
    return val-'0';
  }
  cout << "(";
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      qtree(half, x+i*half, y+j*half);
    }
  }
  cout << ")";
  return 0;
}

void solve() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> v[i];
  qtree(n,0,0);
  return;
}