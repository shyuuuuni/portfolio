/*
Time : 2022.01.20 (10 min)
Problem : BOJ17478 (https://www.acmicpc.net/problem/17478)
Algorithm Type : Recursion
Outline :
N이 주어진다.
N에 따라서 주어진 규칙에 따라 재귀적으로 문장을 출력한다.
Method :
0, 1, 2, ..., n까지 허용하면서 재귀를 돌린다.
처음 출력과 마지막 출력을 신경쓰고, 현재의 n 개수만큼 "----"를 앞에 출력한다.
문자 " 를 출력할때 주의한다.
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

void chatbot(int n, int lim) {
  if(lim < n) return;
  const string chat[5] = {"\"재귀함수가 뭔가요?\"\n", "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", "라고 답변하였지.\n"};
  if(n<lim) {
    for(int i=0; i<4; i++) {
      for(int j=0; j<n; j++) {
        cout << "____";
      }
      cout << chat[i];
    }
  } else {
    for(int j=0; j<n; j++) {
      cout << "____";
    }
    cout << "\"재귀함수가 뭔가요?\"\n";

    for(int j=0; j<n; j++) {
      cout << "____";
    }
    cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
  }
  
  chatbot(n+1,lim);
  for(int j=0; j<n; j++) {
    cout << "____";
  }
  cout << chat[4];
  return;
}

void solve() {
  int n;
  cin >> n;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  chatbot(0, n);
  return;
}