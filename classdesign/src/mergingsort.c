//
// Created by 86136 on 2022/5/22.
//

#include "mergingsort.h"
#include "stdio.h"

void Merge(SqType r1[], int low, int mid, int high) {
  int i, j, k;
  SqType left[mid - low], right[high - mid + 1];
  for (i = low; i < mid; i++) {
    left[i-low] = r1[i];
  }
  for (i = mid; i <= high; i++) {
    right[i - mid] = r1[i];
  }
  i = 0;
  j = 0;
  k = low;
  while ((i < mid - low) && (j < high - mid + 1)) {  //归并
    if (left[i].key < right[j].key) {
      r1[k] = left[i];
      i++;
      k++;
    } else {
      r1[k] = right[j];
      j++;
      k++;
    }

  }
//    若左边剩余的,放入r1中
  while (i < mid - low) {
    r1[k] = left[i];
    k++;
    i++;
  }
  //    若右边剩余的,放入r1中
  while (j < high - mid) {
    r1[k] = right[j];
    k++;
    j++;
  }

}

void MSort(SqType r1[], int low, int high ) {
  int mid;
  if (low == high) {

     return;
  } else {
    mid = (low + high) / 2;
    MSort(r1, low, mid);
    MSort(r1, mid + 1, high);
    Merge(r1,low, mid + 1, high);
    for (int i = 0; i <10; i++) {
      printf("%d " ,r1[i].key);
    }
    printf("\n");
  }
}
void MergeSort(SqType r[], int n) {
  MSort(r, 0, n-1);

}



