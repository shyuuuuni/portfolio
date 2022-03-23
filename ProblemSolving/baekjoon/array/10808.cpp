/*
Time : 2022.01.06 (5 min)
Problem : BOJ10808 (https://www.acmicpc.net/problem/10808)
Algorithm Type : Array
Outline :
알파뱃 소문자로 이루어진 단어 S에서 각 알파뱃이 몇개 포함되어 있는지 출력한다.
Method :
string형으로 단어를 입력받은뒤, 문자열의 각 문자마다 접근해서
'a'라는 문자를 빼주면 ASCII코드 특성상 정수 인덱스로 표현할 수 있다.
따라서 O(N)으로 한바퀴만 돌아서 카운트를 끝낼 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  int cnt[26] = {0};
  cin >> s;
  for(int i=0; i<s.size(); i++) {
    cnt[s[i]-'a']++;
  }
  for(int i=0; i<26; i++) cout << cnt[i] << " ";
  return 0;
}