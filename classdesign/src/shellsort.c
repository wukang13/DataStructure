//
// Created by 86136 on 2022/5/14.
//

#include "shellsort.h"
#include "stdio.h"
#include "string.h"
//希尔排序：
void ShellSort(SqType r[], int n) {
  int i;
  SqType tem;
  for (int x = 1, d = n / 2; d > 0; d = d / 2, x++) {         //d相当于一把尺子，相隔距离d的结果数字为一组
    printf("第%d趟结果：", x);
    for (i = d; i < n; i++) {
      tem.key = r[i].key;
      int p = i;
      while (p > 0 && r[p - d].key > tem.key && p - d >= 0) {  //p=d，p不能小于零，p-d=0表示第一个数字
        r[p] = r[p - d];
        p = p - d;
      }
      r[p] = tem;
    }
    for (int k = 0; k < 10; k++) {
      printf("%d  ", r[k].key);
    }
    printf("\n");
  }
  printf("最终结果： ");
  for (i = 0; i < 10; i++) {
    printf("%d  ", r[i].key);
  }
  printf("\n");
}