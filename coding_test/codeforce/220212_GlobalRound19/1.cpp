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

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    int arr[10000+5] = {};
    int mx = 0;
    int mxidx = -1;
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> arr[i];
      // if(i!=0 && mx < arr[i]) {
      //   mx = arr[i];
      //   mxidx = i;
      // }
    }
    int flag = 0;
    for(int len = 1; len <= n-1; len++) {
      int tmp[10000+5] = {};
      for(int i=0; i<n; i++) tmp[i] = arr[i];
      sort(tmp, tmp+len);
      sort(tmp+len, tmp+n);
      if(tmp[len-1] <= tmp[len]) {
        flag = 1;
      } else {
        flag = 0;
        break;
      }
    }
    if(flag) cout << "NO\n";
    else cout << "YES\n";
    // int mn = *min_element(arr+mxidx, arr+n);
    // int mxx = *max_element(arr, arr+mxidx);
    // cout << mn << " " << mxx << "\n";
    // if(mxx <= mn) cout << "NO\n";
    // else cout << "YES\n";
  }
  return 0;
}