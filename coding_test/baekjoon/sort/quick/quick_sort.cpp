/*
Time : 2022.02.07
Problem : -
Algorithm Type : Sort (Quick)
Outline :
퀵정렬을 구현한다.
*/
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[100000+1] = {7,1,2,8,9,2,0,3,5,4};
int tmp[100000+1];

void quick_sort(int st, int en) {
  if(en <= st+1) return;
  int pivot = arr[st];
  int lptr = st + 1; // lptr보다 죄측에 pivot보다 작은 원소 위치하도록 함
  int rptr = en - 1; // rptr보다 우측에 pivot보다 큰 원소 위치하도록 함
  while(1) {
    while(lptr <= rptr && arr[lptr] <= pivot) lptr++;
    while(lptr <= rptr  && pivot < arr[rptr]) rptr--;
    if(rptr < lptr) break;
    swap(arr[lptr], arr[rptr]);
  }
  swap(arr[st], arr[rptr]);
  quick_sort(st, rptr);
  quick_sort(rptr+1, en);
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  quick_sort(0,n);
  for(int i=0; i<n; i++) cout << arr[i] << " ";
  return 0;
}