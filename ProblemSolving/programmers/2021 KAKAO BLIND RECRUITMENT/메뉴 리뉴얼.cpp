#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;          // 반환값, 마지막에 정렬한다.
    map<string,int> ans[10+2];      // 길이별로 후보 코스의 개수를 저장
    int has[10+10][26+10] = {0};    // has[i][C] : i번째 order가 C라는 메뉴를 가지는지
    int n[10+10] = {0};             // n[i] == len(orders[i])

    // 변수 초기화
    for (int i=0; i<(int)orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        n[i] = (int)orders[i].size();
        for (auto c : orders[i]) {
            has[i][c-'A'] = 1;
        }
    }

    // 모든 코스 요리의 길이별로 가능한 모든 경우의 수를 탐색하면서 map에 저장한다.
    // map을 vector로 옮겨서 등장 횟수 기준으로 내림차순 정렬한다.
    // 정렬된 vector에서 2번 이상 등장한 코스 중 가장 많이 등장한 코스들을 answer에 저장한다.
    for (auto course_len : course) {
        cout << course_len << "! \n";
        for (int i=0; i<(int)orders.size(); i++) {
            if (n[i] < course_len) continue;
            string cur = orders[i];
            vector<int> comb(n[i], 0);
            for (int j=1; j<=course_len; j++) {
                comb[n[i]-j] = 1;
            }
            do {
                string s = "";
                for (int j=0; j<n[i]; j++) {
                    if (comb[j] == 1) s.push_back(cur[j]);
                }
                if (ans[course_len].find(s) == ans[course_len].end()) {
                    ans[course_len][s] = 1;
                } else {
                    ans[course_len][s]++;
                }
            } while (next_permutation(comb.begin(), comb.end()));
        }
        if (ans[course_len].empty()) continue; // 비어있으면 넘어간다.
        
        // 정렬
        vector<pair<string,int>> tmp(ans[course_len].begin(), ans[course_len].end());
        sort(tmp.begin(), tmp.end(), [](pair<string,int> a, pair<string,int> b) {
            return a.second > b.second;
        });

        // 가장 많이 등장한 코스를 추가
        int mx = tmp[0].second;
        if (mx < 2) continue;
        answer.push_back(tmp[0].first);
        for (int it=1; it<tmp.size(); it++) {
            if (tmp[it].second < mx) break;
            answer.push_back(tmp[it].first);
        }
    }

    // 마지막으로 answer 배열 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main(void) {
    return 0;
}