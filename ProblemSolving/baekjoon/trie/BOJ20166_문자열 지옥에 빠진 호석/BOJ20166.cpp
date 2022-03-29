/*
Time : 2022.03.29
Problem : BOJ20166 (https://www.acmicpc.net/problem/20166)
Algorithm Type : 문자열, Trie(자료구조), 백트래킹
Outline :
NxM 크기의 격자판 위에 각각 알파벳 소문자가 올려져 있다.
격자판은 환형으로 이루어져 있어서, 만약 격자판의 끝으로 이동하면 반대쪽 끝에서 나오게 된다.
격자판에서 이동할 때 마다 각 칸에 써진 알파뱃을 이어 붙여서 문자열을 만들 수 있고, A->B로 가는 경우와 B->A로 가는 경우는 다른 경우이다.
K개의 "신이 좋아하는 문자열" 이 주어졌을 때, 각각의 문자열들이 격자판 위에서 몇 번 만들 수 있는지 출력한다.
Method :
N,M,K의 크기가 작아서 백트래킹으로 풀면 쉽게 풀 수 있다.
Trie 자료구조를 연습 할 겸, K개의 문자열을 확인하는 시간을 줄여보기 위해서 Trie를 사용하였다.
방법은 Trie 자료구조의 단말 노드인지를 저장하는 bool 변수 대신, 해당 단말 노드의 개수가 몇개인지를 세는
count 변수를 사용해서, 그 값이 0이면 단말 노드가 아니고, 0보다 크다면 단말 노드가 count개 있음으로 저장했다.
이후, NxM 크기의 격자판 각 좌표 위에서부터 시작하여 백트래킹으로 길이가 1~5인 문자열 모두를 서치한다.
마지막으로 최대 길이가 되면 해당 문자열을 Trie에 추가한다. 이러면 나중에 검색할 때 굉장히 빠른 속도로 개수를 알아 낼 수 있다.
조금 더 최적화를 하면 더 빠르게 할 수 있겠지만, 이 코드로 72ms 정도의 시간이 소요되었다.
다른 채점현황을 보았을때 최상위권 속도는 아니지만 나름 빠른 속도를 가지고 있는 것으로 판단된다.
Example :
3 3 2
aaa
aba
aaa
aa
bb
-------
56
0
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

class Trie {
  private:
    int toInteger(char c) {
      return c - 'a';
    }
  
  public:
    int count;
    Trie* children[26];

    Trie() {
      count = 0;
      for (int i=0; i<26; i++) {
        children[i] = NULL;
      }
    }

    void insert(string str) {
      Trie* cursor = this;
      for (char c : str) {
        if (!cursor->children[toInteger(c)]) {
          cursor->children[toInteger(c)] = new Trie();
        }
        cursor = cursor->children[toInteger(c)];
      }
      cursor->count++;
      return;
    }

    int find(string str) {
      bool exist = true;
      Trie* cursor = this;
      for (char c : str) {
        if (!cursor->children[toInteger(c)]) {
          exist = false;
          break;
        }
        cursor = cursor->children[toInteger(c)];
      }
      if (!cursor->count) {
        exist = false;
      }
      return (exist ? cursor->count : 0);
    }
};

//  0    1    2   3    4    5    6    7
// 오아, 아래, 왼아, 왼쪽, 왼위, 위쪽, 오위, 오른
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int n, m, k;
Trie trie;
vector<string> a;
string result;

pair<int,int> move(int x, int y, int d) {
  int nx = x + dx[d];
  int ny = y + dy[d];

  if (nx == -1) nx = n-1;
  if (nx == n) nx = 0;
  if (ny == -1) ny = m-1;
  if (ny == m) ny = 0;

  return mp(nx,ny);
}

void travel(int x, int y, int mx) {
  if ((int)result.size() == mx) {
    trie.insert(result);
    return;
  }

  for (int d=0; d<8; d++) {
    pii nxt = move(x, y, d);

    result.push_back(a[nxt.X][nxt.Y]);
    travel(nxt.X, nxt.Y, mx);

    result.pop_back();
  }
  
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO
  
  cin >> n >> m >> k;

  for (int i=0; i<n; i++) {
    string row;
    cin >> row;
    a.push_back(row);
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      for (int k=1; k<=5; k++) {
        result = "";
        result.push_back(a[i][j]);
        travel(i, j, k);
      }
    }
  }

  for (int i=0; i<k; i++) {
    string str;
    cin >> str;
    cout << trie.find(str) << "\n";
  }

  return 0;
}
