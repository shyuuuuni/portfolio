/*
Time : 2022.01.06 (3 min)
Problem : BOJ2490 (https://www.acmicpc.net/problem/2490)
Algorithm Type : Simulation
Outline :
윷놀이의 윷을 배(0), 등(1) 으로 입력받아서 도(A),개(B),걸(C),윷(D),모(E)를 출력한다.
총 세번의 윷을 던진다.
Method :
등(1)의 개수만 cnt변수에 저장하여 그 개수에 따라서 출력을 결정한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc = 0;

  while(tc < 3) {
    int x, cnt = 0;
    for(int i=0; i<4; i++) {
      cin >> x;
      if(x) cnt++;
    }
    if(cnt==0) cout << "D";
    else if(cnt==1) cout << "C";
    else if(cnt==2) cout << "B";
    else if(cnt==3) cout << "A";
    else cout << "E";
    cout << "\n";
    tc++;
  }
  
  return 0;
}