/*
Time : 2022.03.29
Problem : BOJ5052 (https://www.acmicpc.net/problem/5052)
Algorithm Type : STL::Map
Outline :
미국 전역의 나무들이 주어졌을 때, 각 종이 전체에서 몇 %를 차지하는지 출력한다.
%는 소수 4째자리까지 반올림해서 출력한다.
Method :
간단하게 입력된 문자열의 개수를 STL의 맵으로 체크하면서 마지막에 맵을 순회하면서 그 비율을 출력한다.
맵은 key 기준으로 정렬해주므로, iterator를 이용하여 그냥 순서대로 출력하면 된다.
또한 테스트를 위해서는 EOF를 마지막에 입력해야 하는데, Ctrl+D를 누르면 입력할 수 있다. 참고하자.
Example :
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
-------
Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  double n=0LL;
  string buf;
  map<string,double> counter;
  while (getline(cin, buf)) {
    n++;
    if (counter.find(buf) == counter.end()) {
      counter[buf] = 1LL;
    } else {
      counter[buf] += 1LL;
    }
  }
  if (n == 0) return 0;
  cout << fixed;
  for (auto si : counter) {
    cout.precision(4);
    cout << si.first << " " << (100*si.second/n)<< "\n";
  }

  return 0;
}
