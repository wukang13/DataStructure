//
// Created by 86136 on 2022/5/14.
//

#include "quickSort.h"
#include "stdio.h"
#include "string.h"
int quickSort(SqType r[], int s, int n);

/**
 * 夸快速排序
 * @param r 数组
 * @param m 左下标
 * @param n 右下标
 */
void QuickSort(SqType y[], int m, int n) {
  static int times=0;
  SqType r[n];
  int z;
  memcpy(r, y,sizeof(SqType) * n);
  if (m < n) {
    z = quickSort(r, m, n);
    printf("第%d趟结果：", ++times);
    for (int x = 0; x < 10; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
    QuickSort(r, m, z - 1);  //将枢轴记录保存到low=high的位置
    QuickSort(r, z + 1, n);
  }
}
/**
 * 快速排序
 * @param r
 * @param s
 * @param n
 * @return
 */
int quickSort(SqType r[], int s, int n) {
  SqType temp;
  int left = s, right = n;
  temp = r[left];
  while (left < right) {
    while (right > left && r[right].key >= temp.key)
      right--;
    if (left < right) {  //找到小于temp.key的记录,进行交换
      r[left] = r[right];
      left++;
    }
    while (left < right && r[left].key <= temp.key)  //low从左到右找到大于temp.key的记录
      left++;
    if (left < right) {  //找到大于temp.key的记录,进行交换
      r[right] = r[left];
      right--;
    }
  }
  r[left] = temp;
  return left;//返回枢轴记录的位置
}
