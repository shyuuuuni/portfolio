/*
Time : 2022.03.08
Problem : BOJ1238 (https://www.acmicpc.net/problem/1238)
Algorithm Type : 다익스트라
Outline :
N개의 도시와, 그 도시들 사이의 길이 M개 주어진다.
x라는 위치의 도시에서 나머지 각 도시로 돌아갈 때, 가장 오래 걸리는 도시의 거리를 출력한다.
Method :
문제를 정리하면, 모든 도시들 중에서
(도시 X로 가는 시간의 최솟값) + (도시 X로부터 돌아오는 시간의 최솟값) 의 최댓값을 구하는 문제이다.
X로부터 돌아오는 시간의 최솟값은 간단하게 다익스트라로 구할 수 있다.
첫번째의 도시 X로 가는 시간의 최솟값을 생각해보자.
이를 간선을 뒤집어서 X로부터 출발하는 다익스트라로 해결하였다.
만약 도착지가 X이고, X <- PREV 로 가중치가 W인 간선이 있다면
이를 inverse adj[X] 값에 (W, PREV)로 저장한다.
즉 X로부터 시작하지만, 실제 간선은 X로 도착하는 모양을 유지한다.
이런식으로 X로부터 역간선을 따라서 각 도시로의 최단 경로를 구한다면, dist_to_x[i] 값이 i에서 X로 가는 최단 경로가 된다.
Example :
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
-------
10
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

int charToInt(char c) {
  if ('A' <= c && c <= 'Z')
    return (int)(c - 'A');
  else if ('a' <= c && c <= 'z')
    return (int)(c - 'a');
  else if ('0' <= c && c <= '9')
    return (int)(c - '0');
  return -1;
}

const int INF = 1 << 22;
int v, e;
int X;
int dist_to_x[1000+5];
int dist_from_x[1000+5];
vector<pii> adj[1000+5];
vector<pii> invadj[1000+5]; // invadj[i] : i로 들어오는 간선 저장 (가중치, 출발지)

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> v >> e >> X;
  for (int i=0; i<e; i++) {
    int s, d, w;
    cin >> s >> d >> w;
    adj[s].push_back({w,d});
    invadj[d].push_back({w, s});
  }

  fill(dist_from_x, dist_from_x+1000+5, INF);
  fill(dist_to_x, dist_to_x+1000+5, INF);

  // 1. 각 정점(i)에서 x로 이동하는 최단 거리 구하기
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist_to_x[X] = 0;
  pq.push({0,X});

  while (!pq.empty()) {
    int cur = pq.top().second;
    int cur_dst = pq.top().first;
    pq.pop();
    if (dist_to_x[cur] != cur_dst) continue;
    for (pii prv : invadj[cur]) { // cur로 들어오는 간선을 확인 (즉, Prev 정점과의 간선 확인)
      
      // 만약 이전에 어떤 방법으로든 prv로 간 방법이 X->cur->prv 보다 짧은 경우 : 패스
      if (dist_to_x[prv.second] <= cur_dst + prv.first) continue;

      dist_to_x[prv.second] = cur_dst + prv.first;
      pq.push({dist_to_x[prv.second], prv.second});
    }
  }

  // 2. X에서 각 정점으로 이동하는 최단 거리 구하기
  priority_queue<pii, vector<pii>, greater<pii>> pq2;
  dist_from_x[X] = 0;
  pq2.push({0,X});

  while(!pq2.empty()) {
    int cur = pq2.top().second;
    int cur_dst = pq2.top().first;
    pq2.pop();
    if (dist_from_x[cur] != cur_dst) continue;
    for (pii nxt : adj[cur]) {
      if (dist_from_x[nxt.second] <= cur_dst + nxt.first) continue;
      dist_from_x[nxt.second] = cur_dst + nxt.first;
      pq2.push({dist_from_x[nxt.second],nxt.second});
    }
  }
  
  int ans = -1;
  for (int i=1; i<=v; i++) {
    ans = max(ans, dist_from_x[i]+dist_to_x[i]);
  }

  cout << ans;

  return 0;
}