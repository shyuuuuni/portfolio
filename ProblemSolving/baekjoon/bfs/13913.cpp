/*
Time : 2022.02.20
Problem : BOJ13913 (https://www.acmicpc.net/problem/13913)
Algorithm Type : BFS
Outline :
수직선 상에서 수빈이와 동생이 0~100000 사이에 있다.
수빈이는 1초마다 X-1 또는 X+1, 2*X 위치로 이동할 수 있다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
Method :
먼저 bfs를 할 배열의 범위를 0부터 넉넉하게 200,000 이상으로 잡았다.
왜냐하면 50001 -> 100000 같은 경우에는 X2를 해서 100002 -> -1 -1 하는 경우가 가장 빠르기 때문에
100,000 이상의 범위에 대해서도 BFS를 통해 이동할 수 있어야 한다.
dist[x]는 x까지 도착하기 위한 최단 이동 시간,
method[x]는 x로 도달하기 바로 직전에 사용한 method를 저장한다.
method는
0 : -1
1 : +1
2 : *2
로 정의했고, _next라는 함수를 통해 처리하도록 구현했다.
이후부터는 일반적인 BFS처럼 탐색하는 위치가 k일 경우를 갱신해주면서 돌면 된다.
출력은 k부터 큐에 넣으면서 method 배열으 보면서 해줬던 연산을 반대로 해주면서
시작점이 될 때 까지 반복했다가 top()을 하나씩 출력하면 된다.
Example :
5 17
-------
4
5 10 9 18 17
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

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};

// 문자열을 구분자를 기준으로 나눠서 벡터에 저장
int splitStringByToken(vector<string> &v, string &s, const char &del) {
  if(s.empty()) return 0;
  istringstream ss(s);
  string token;

  v.clear();
  while (getline(ss, token, del)) {
    if(!token.empty()) v.push_back(token);
  }

  return v.size();
}

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}


bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

int n, k;
int ans = 300000+5;
int dist[300000+5];
int method[300000+5];

int _next(int x, int i) {
  switch (i)
  {
  case 0:
    return x-1;
  case 1:
    return x+1;
  case 2:
    return x*2;;
  }
  return 0;
}

int _prev(int x, int i) {
  switch (i)
  {
  case 0:
    return x+1;
  case 1:
    return x-1;
  case 2:
    return x/2;;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;

  if (n == k) {
    cout << 0 << "\n";
    cout << n;
    return 0;
  }

  fill(method, method+300000+5, -1);
  fill(dist, dist+300000+5, 300000+5);
  queue<int> q;
  q.push(n);
  dist[n] = 0;

  while(!q.empty()) {
    int x = q.front();
    // int met = q.front().second;
    q.pop();

    if (ans < dist[x]) break;

    for (int i=0; i<3; i++) {
      int xx = _next(x, i);
      if (xx<0 || 200000<xx) continue;
      if (dist[xx] < dist[x] + 1) continue;
      q.push(xx);
      dist[xx] = dist[x] + 1;
      method[xx] = i;
      if (xx == k) {
        ans = min(ans, dist[xx]);
      }
    }

  }

  cout << dist[k] << "\n";

  int idx = k;
  stack<int> s;
  while(1) {
    s.push(idx);
    if (method[idx] == -1) break;
    idx = _prev(idx, method[idx]);
  }

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  
  return 0;
}