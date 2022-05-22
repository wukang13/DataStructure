//
// Created by 86136 on 2022/5/14.
//

#include <string.h>
#include "binsertsort.h"
#include "stdio.h"

//折半排序：
void BinsertSort(SqType r[], int n) {
  int i, j;
  SqType tem;

  int low, high, mid;
  for (i = 1; i < n; ++i) {      //从第二个数字开始
    tem.key = r[i].key;
    low = 0;
    high = i - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (tem.key < r[mid].key) { //左边插入
        high = mid - 1;
      } else {
        low = mid + 1;            //右边查找
      }
    }
    for (j = i - 1; j >= low; --j) {
      r[j + 1] = r[j];
    }
    r[low].key = tem.key;
    printf("第%d趟结果：", i);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}