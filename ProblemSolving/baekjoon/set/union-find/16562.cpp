/*
Time : 2022.03.22
Problem : BOJ16562 (https://www.acmicpc.net/problem/16562)
Algorithm Type : 집합, 유니온파인드
Outline :
입력으로 학생들의 친구 관계가 주어진다.
또한 학생별로 "친구비" 라는 수가 주어지는데, "친구비"는 준석이와 그 학생이 친해지기 위해서 필요한 돈 이다.
친구 관계에 따라 어떤 학생 A과 다른 학생 B가 친구라면, 준석이가 A와 친구가 되었을 때 B와도 친구가 될 수 있다.
모든 학생과 친구가 되기 위한 최소 비용을 출력한다.
모든 학생과 친구가 될 수 없다면 Oh no를 출력한다.
Method :
친구 관계를 집합으로 표현할 수 있다.
즉 A-B-C 가 친구라면, 같은 집합에 속해 있다고 볼 수 있다.
집합으로 표현하기 위해 union-find 알고리즘을 사용하였고, 합집합 연산을 구현할 때 price를 기준으로 병합하였다.
즉, 가장 높은 root 노드를 친구비가 가장 싼 노드로 설정한다.
그러면 나중에 준석이와 나머지 모든 친구들을 순회하면서 처음 만난 집합의 부모 노드의 친구비만 지불하도록 체크한다.
그러면 모든 학생과 친구가 되어야 하므로 필요한 최소 비용을 알 수 있고, 그 비용이 가진 돈보다 많다면 불가능,
적다면 출력하면 된다.
Example :
5 3 20
10 10 20 20 30
1 3
2 4
5 4
-------
20
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

const int N = 10000 + 100;
int n, m;
int k;
int parent[N], price[N];

int getParent(int x) {
  if (x == parent[x]) return x;

  return parent[x] = getParent(parent[x]);
}

void unionByPrice(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return;
  if (price[x] > price[y]) swap(x,y);
  parent[y] = x;
  return ;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  cin >> n >> m >> k;

  for (int i=1; i<=n; i++) {
    parent[i] = i;
    cin >> price[i];
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    unionByPrice(a,b);
  }

  bool checked[N] = {};
  int needs = 0;
  for (int i=1; i<=n; i++) {
    int p = getParent(i);
    if (checked[p]) {
      checked[i] = true;
    } else {
      needs += price[p];
      checked[p] = checked[i] = true;
    }
  }

  if (k < needs) cout << "Oh no";
  else cout << needs;

  return 0;
}
