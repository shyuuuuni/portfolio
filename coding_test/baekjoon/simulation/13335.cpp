/*
Time : 2022.02.03 (30 mins)
Problem : BOJ13335 (https://www.acmicpc.net/problem/13335)
Algorithm Type : Simulation
Outline :
길이가 w이고 최대 부하가 l인 다리에 n개의 트럭이 한줄로 올라가려고 한다.
트럭의 순서는 바뀔 수 없으며, 트럭은 하나당 1칸을 차지한다.
트럭이 통과하는데 걸리는 총 시간을 계산한다.
Method :
다리가 크기 1당 트럭 1개를 운반하고, 한칸씩 이동하므로 큐로 생각한다.
큐에 0인 부분은 빈 칸, 0이 아닌 부분은 차량을 옮기고 있는것으로 판단한다.
매 시간마다, front에서 pop하고, back에다가 push 하는 식으로 이동을 표현한다.
만약 현재 부하 curl에 새로운 차량을 올렸을때 최대 부하 l보다 크다면 이번 시간에는 올리지 않고 대기한다.
부하가 괜찮아 질 때 까지 front에서 pop하면서 부하를 줄이고, 0을 push한다.
만약 front에서 pop할 때 차가 나온다면, complete변수를 1 증가시켜 기록해둔다.
이런식으로 반복한 후, 모든 차량이 나올 때 까지 큐를 pop하면서 시간을 증가시킨다.
Example :
4 2 10
7 4 5 6
-------
8
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, w, l;
int curl, complete, t; // 현재 부하, 완료한 차량 수, 걸린 시간
queue<int> q;

// bool oob(int x, int y) { // out of bound check
//   return (x<0 || y<0 || n<=x || m<=y);
// }

void solve() {
  cin >> n >> w >> l; // 차량수, 다리길이, 최대하중
  for(int i=0; i<w; i++) q.push(0); // 처음 큐(다리)에 빈 칸 w개

  for(int i=0; i<n; i++) {
    int car;
    cin >> car;
    while(l < car + curl - q.front()) {
      // 한칸 옮겨도 다리에 부하가 커서 차량을 올릴 수 없는 경우
      int out = q.front();
      if(out) complete++;
      q.pop();
      q.push(0);
      curl -= out;
      t++;
    }
    int out = q.front();
    if(out) complete++;
    q.pop();
    curl -= out;
    curl += car;
    q.push(car);
    t++;
  }
  while(complete < n) {
    if(q.front()) complete++;
    q.pop();
    t++;
  }
  cout << t;
  return;
}