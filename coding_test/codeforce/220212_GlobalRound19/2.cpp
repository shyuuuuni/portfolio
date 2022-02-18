/*
Time : 2022.02.12 23:30~
Contest : Global Round 19
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

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

int getmex(vector<int> &a, int st, int en) {
  int mex = 0;
  int tmp[100+5] = {};
  int len = en - st + 1;
  for(int i=0; i<len; i++) {
    tmp[i] = a[st+i];
  }
  sort(tmp, tmp+len);
  // for(int i=0; i<len; i++) cout << tmp[i] << " ";
  for(int i=0; i<len; i++) {
    if(mex < tmp[i]) break;
    mex++;
  }
  return mex;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> arr(100+5);
    int mex[100+5][100+5] = {}; // mex[l][r] : l~r (포함) 에서 등장하지 않는 최소 음X정수
    for(int i=0; i<n; i++) {
      cin >> arr[i];
    }
    for(int len=0; len<n; len++) {
      for(int i=0; i+len<n; i++) { // [i,i+len] check
        if(len == 0) mex[i][i] = (arr[i] ? 0 : 1);
        else if(mex[i][i+len-1] == mex[i+len][i+len]) mex[i][i+len] = mex[i][i+len-1];
        else mex[i][i+len] = getmex(arr, i, i+len);
      }
    }
    for(int len=1; len<n; len++) {
      for(int i=0; i+len<n; i++) {
        int cur = 0;
        
      }
    }

  }
  return 0;
}