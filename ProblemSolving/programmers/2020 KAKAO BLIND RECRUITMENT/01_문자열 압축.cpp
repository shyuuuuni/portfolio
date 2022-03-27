#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int len = s.size();
    int answer = len;
    
    // i : 압축할 길이, 1부터 최대 길이 len까지 완전탐색
    for(int i=1; i<=len; i++) {
        string test = ""; // 압축한 문자열
        string prv = ""; // 이전 문자열
        int n = 0; // 압축 횟수
        for (int j=0; j<len; j+=i) {
            string token = s.substr(j, i); // j부터 길이 i만큼 잘라냄
            if (prv == "") {
                prv = token;
            } else if (prv == token) {
                n++;
            } else if (prv != token) {
                if (n==0) {
                    test += prv;
                } else {
                    test += to_string(n+1) + prv;
                }
                n = 0;
            }
            prv = token;
        }
        
        // 마지막 회차 처리
        if (n==0) {
            test += prv;
        } else {
            test += to_string(n+1) + prv;
        }
        
        // 이번에 만들어낸 압축 문자열의 길이와 최소 길이를 비교해서 갱신
        answer = min(answer, (int)test.size());
    }
    
    return answer;
}

int main(void) {
    cout << solution("x");
    return 0;
}