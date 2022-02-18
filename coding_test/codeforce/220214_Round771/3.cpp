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

int n;
int arr[100000+5];
int parent[100000+5];
int idx[100000+5];
vector<int> check;

// 노드 x의 부모를 찾는 함수
int find(int x){
  if (x == parent[x])
    return x;
  else {
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}

// 노드 x,y를 합치는 함수
void unionNode(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (x < y) parent[y] = parent[x];
    else parent[x] = parent[y];
  }
}

void pc() {
  cout << "union:\n";
  for(int i=0; i<n; i++) {
    cout << parent[i] << " ";
  }
  cout << "\n";
  if(!check.empty()) {
    for(int i=0; i<check.size(); i++) {
      cout << check[i] << " ";
    }
  }
  cout << "\n\n";
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;

  while (tc--) {
    cin >> n;
    ll ans = 0;
    int dis[100000+5] = {};
    check.clear();

    for (int i=0; i<n; i++) {
      parent[i] = i;
      cin >> arr[i];
      idx[arr[i]] = i;
    }

    for (int i=0; i<n; i++) {
      if (i == 0) check.push_back(arr[i]);
      else {
        int ii = lower_bound(check.begin(), check.end(), arr[i]) - check.begin();
        check.insert(ii+check.begin(), arr[i]);

        for (int j = ii+1; j < (int)check.size(); j++) {
          int x = check[j];
          int xidx = idx[x];
          // if (parent[xidx] == parent[i]) break;
          // else unionNode(i, xidx);
          unionNode(i,xidx);
        }

        // if (check.back() != arr[i]) {
        //   int x = check[ii+1];
        //   // cout << arr[i] << " " << x << ":\n"; 
        //   unionNode(i, idx[x]);
        // }
        // if (check.front() != arr[i]) {
        //   int x = check[ii-1];
        //   unionNode(i, idx[x]);
        // }
      }
      pc();
    }

    for (int i=0; i<n; i++) {
      cout << parent[i] << " ";
    }
    cout << '\n';
    for(int i=0; i<n; i++) {
      int x = parent[i];
      if (dis[x] == 0) {
        dis[x] = 1;
        ans++;
      } else {
        continue;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}