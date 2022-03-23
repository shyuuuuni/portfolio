/*
Time : 2022.01.10 (30 min)
Problem : BOJ5430 (https://www.acmicpc.net/problem/5430)
Algorithm Type : Deque
Outline :
정수 배열에 다음과 같은 연산이 있다.
1. R : 정수 배열을 뒤집는다.
2. D : 정수 배열의 맨 앞을 제거한다.
명령이 주어졌을 때, 배열의 최종 결과를 출력한다.
Method :
배열을 뒤집는 작업을 매 명령마다 실행하면 시간복잡도가 굉장히 높을 것으로 생각된다.
따라서 앞 뒤로 삽입과 삭제가 가능한 Deque를 사용하여
배열의 맨 앞을 Front로 볼건지 Back으로 볼건지 정하는 변수 dir로 구분하였다.
기본적으로 배열의 맨 앞을 Front로 본다.
만약 다음 입력으로 R이 들어온다면 배열의 맨 앞을 Back으로 본다.
이때 입력으로 D가 들어온다면 맨 앞을 기준으로 pop_front() 또는 pop_back()을 실행한다.
Failed :
이 문제에서 입력과 출력 처리가 까다로웠다.
1. 입력으로 들어오는 배열에 포함된 숫자는 1부터 100 사이이다. 즉 [22,50,100] 과 같은 입력도 처리한다.
2. 매 실행 이후 [], [1,2,3], error와 같은 문장 출력 후 개행문자를 입력해야한다.
입출력에 신경쓰도록 하자.
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    solve1();
  }
  return 0;
}

#define BACK_TO_FRONT 1
#define FRONT_TO_BACK 0
int solve1() {
  string s, arr;
  int n, x, tmp=0, dir = FRONT_TO_BACK;;
  deque<int> dq;
  cin >> s;
  cin >> n;
  cin >> arr;
  for(int i=0; i<arr.size() && n; i++) {
    if(arr[i] == '[') {
      tmp = 0; continue;
    }
    else if(arr[i] == ']' || arr[i] == ',') {
      dq.push_back(tmp); tmp = 0;
    } else {
      tmp *= 10;
      tmp += arr[i] - '0';
    }
  }
  for(auto c : s) {
    if(c == 'R' && dir == BACK_TO_FRONT) {
      dir = FRONT_TO_BACK;
    } else if(c == 'R' && dir == FRONT_TO_BACK) {
      dir = BACK_TO_FRONT;
    } else if(c == 'D' && dq.empty()) {
      cout << "error\n";
      dir = -1;
      break;
    } else if(c == 'D' && dir == BACK_TO_FRONT) {
      dq.pop_back();
    } else if(c == 'D' && dir == FRONT_TO_BACK) {
      dq.pop_front();
    }
  }
  if(dir == -1) return 0;
  cout << '[';
  if(dir == BACK_TO_FRONT && !dq.empty()) {
    for(int i=dq.size()-1; 0<=i; i--) {
      cout << dq[i];
      if(i) cout << ",";
    }
  } else if(dir == FRONT_TO_BACK && !dq.empty()) {
    for(int i=0; i<dq.size(); i++) {
      cout << dq[i];
      if(i!=dq.size()-1) cout << ",";
    }
  }
  cout << ']';
  cout << '\n';
  return 0;
}