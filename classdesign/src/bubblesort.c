//
// Created by 86136 on 2022/5/14.
//

#include <string.h>
#include "bubblesort.h"
#include "stdio.h"
//冒泡排序：
void BubbleSort(SqType y[], int n) {
  int i, j;
  SqType temp,r[n];
  mempcpy(r, y, sizeof(SqType) * n);
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {           //从后往前找
      if (r[j].key < r[j - 1].key) {     //前面大于后面就交换
        temp = r[j];
        r[j] = r[j - 1];
        r[j - 1] = temp;
      }
    }
    printf("第%d趟结果：", i + 1);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}