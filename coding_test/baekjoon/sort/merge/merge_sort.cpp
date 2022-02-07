/*
Time : 2022.02.07
Problem : -
Algorithm Type : Sort (Merge)
Outline :
병합정렬을 구현한다.
*/
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[100000+1] = {7,1,2,8,9,2,0,3,5,4};
int tmp[100000+1];

void merge(int st, int en) {
  // arr[st:en]을 정렬하면서 병합한다.
  int mid = (st+en)/2;
  int i = st, j = mid;
  for(int idx = st; idx < en; idx++) {
    if (i == mid) tmp[idx] = arr[j++];
    else if (j == en) tmp[idx] = arr[i++];
    else if (arr[i] <= arr[j]) tmp[idx] = arr[i++];
    else tmp[idx] = arr[j++];
  }
  for(int idx = st; idx < en; idx++)
    arr[idx] = tmp[idx];
  return;
} 

void merge_sort(int st, int en) {
  // arr[st:en]을 정렬한다.
  if(st+1 == en) return;
  int mid = (st+en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st,en);
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  merge_sort(0,n);
  for(int i=0; i<n; i++) cout << arr[i] << " ";
  return 0;
}