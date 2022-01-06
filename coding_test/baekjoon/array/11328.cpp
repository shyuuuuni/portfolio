/*
Time : 2022.01.06 (5 min)
Problem : BOJ11328 (https://www.acmicpc.net/problem/11328)
Algorithm Type : Array
Outline :
strfry 함수는 문자열을 무작위로 재배치하는 함수이다.
두개의 문자열에 대해서 strfry 함수를 적용하여 얻을 수 있는지 판단한다.
Method :
각 문자열에 들어있는 각 문자의 개수가 동일한지 비교하면 된다.
두개의 카운트용 배열을 선언한 후 ASCII코드의 특성을 이용하여
문자열의 각 문자에서 'a'를 빼면 인덱스로 표현할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n=0, tc;
  cin >> tc;
  while(n < tc) {
    string x, y;
    int cnt1[26]={}, cnt2[26]={};
    int flag = 1;
    cin >> x >> y;
    for(int i=0; i<x.size(); i++)
      cnt1[x[i]-'a']++;
    for(int i=0; i<y.size(); i++)
      cnt2[y[i]-'a']++;
    for(int i=0; i<26; i++) {
      if(cnt1[i]!=cnt2[i]) flag=0;
    }
    if(flag) cout << "Possible\n";
    else cout << "Impossible\n";
    n++;
  }
  return 0;
}