/*
Time : 2022.03.29
Problem : BOJ5052 (https://www.acmicpc.net/problem/5052)
Algorithm Type : 문자열, Trie(자료구조)
Outline :
전화번호 목록이 주어졌을 때, 이 목록이 일관성이 있는지 없는지 출력한다.
일관성을 유지한다는 것은 한 번호가 다른 번호의 접두어인 경우가 없다는 것을 의미한다.
예를 들어 911(긴급 전화), 91 12 54 26(선영) 과 같은 전화번호가 있다면
선영에게 전화하기 위해 911을 입력하는 순간 긴급 전화가 걸리게 된다.
Method :
전화번호를 문자열로 생각하면, 어떤 전화번호 문자열이 다른 전화번호 문자열의 일부에 속하는지 확인하는 문제이다.
이 문제를 Trie 자료구조를 사용하여 해결하였다. (find 함수는 사용하지 않아서 구현하지 않았다.)
일관성이 없다는 것은 두 가지 경우의 수가 존재한다.
1. "9110" -> "911" 순서로 포함하는 노드가 먼저 등장하는 경우
2. "911" -> "9110" 순서로 포함될 노드가 먼저 등장하는 경우
====
먼저 1번의 경우에는 Trie 자료구조의 insert 메소드를 호출할 때,
if (!cursor->children[toInteger(c)]) 조건과 같이 해당 문자열의 원소가 자식 노드로 존재하는지 확인한다.
만약 이러한 조건에 한번이라도 걸리지 않는다면, 현재 입력하는 문자열("911")의 모든 원소가 이전에 다른 문자열을 입력하면서 등록했다는 것을 의미한다.
따라서 이를 flag라는 변수에 저장하여 한번이라도 걸리면 true, 아니면 false로 저장한다.
====
다음으로 2번의 경우에는 마찬가지로 insert 메소드를 호출할 때,
반대로 if (!cursor->children[toInteger(c)]) 조건을 만족하지 않으면서,
다음 커서가 단말 노드인 경우 확인할 수 있다.
즉, 9 -> 1 -> 1 -> 0 순서로 확인하는데, 911에서 1을 확인했더니 이미 "911" 을 처리하면서
마지막 1을 단말노드라고 표시했기 때문에 일관성이 없다는 것을 알 수 있다.
====
따라서 위 경우를 각 테스트케이스마다 처리하면 해결할 수 있다.
Example :
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
-------
NO
YES
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
      return c - '0';
    }

  public:
    bool isTerminal;
    Trie* children[10];

    Trie() {
      this->isTerminal = false;
      for (int i=0; i<10; i++) {
        this->children[i] = NULL;
      }
    }

    bool insert(string phoneNo) {
      bool isConsist = true;
      bool flag = false;
      Trie* cursor = this;
      for (char &c : phoneNo) {
        if (!cursor->children[toInteger(c)]) {
          cursor->children[toInteger(c)] = new Trie();
          flag = true;
        } else if (cursor->children[toInteger(c)]->isTerminal) {
          isConsist = false;
        }
        cursor = cursor->children[toInteger(c)];
      }
      cursor->isTerminal = true;
      return isConsist && flag;
    }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  int tc;
  cin >> tc;
  while (tc--) {
    Trie trie;
    bool result = true;
    int n;
    cin >> n;
    while(n--) {
      string phoneNo;
      cin >> phoneNo;
      result = result && trie.insert(phoneNo);
    }
    if (result) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
