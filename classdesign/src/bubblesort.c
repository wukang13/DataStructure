//
// Created by 86136 on 2022/5/14.
//

#include <string.h>
#include "bubblesort.h"
#include "stdio.h"
//ð������
void BubbleSort(SqType y[], int n) {
  int i, j;
  SqType temp,r[n];
  mempcpy(r, y, sizeof(SqType) * n);
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {           //�Ӻ���ǰ��
      if (r[j].key < r[j - 1].key) {     //ǰ����ں���ͽ���
        temp = r[j];
        r[j] = r[j - 1];
        r[j - 1] = temp;
      }
    }
    printf("��%d�˽����", i + 1);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}