//
// Created by 86136 on 2022/5/14.
//

#include "insertsort.h"
#include "stdio.h"
#include "string.h"
/**
 * ֱ�Ӳ�������
 * @param r  ����
 * @param n ����
 */
void InsertSort(SqType y[], int n) {
  int i, j;
  SqType r[n], tem;
  mempcpy(r, y, sizeof(SqType) * n);
  for (i = 1; i < n; i++) {
    printf_s("��%d�˽����", i);
    tem = r[i];
    if (r[i].key < r[i - 1].key) {
      for (j = i - 1; j >= 0 && r[j].key > tem.key; j--) {
        r[j + 1] = r[j];
        r[j] = tem;
      }
    }
    for (int k = 0; k < 10; k++)
      printf("  %d", r[k].key);
    printf("\n");
  }
  printf("���ս����");
  for (int k = 0; k < 10; k++) {
    printf("  %d", r[k].key);
  }
  printf("\n");
}
