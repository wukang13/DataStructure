//
// Created by 86136 on 2022/5/14.
//

#include "shellsort.h"
#include "stdio.h"
#include "string.h"
//ϣ������
void ShellSort(SqType r[], int n) {
  int i;
  SqType tem;
  for (int x = 1, d = n / 2; d > 0; d = d / 2, x++) {         //d�൱��һ�ѳ��ӣ��������d�Ľ������Ϊһ��
    printf("��%d�˽����", x);
    for (i = d; i < n; i++) {
      tem.key = r[i].key;
      int p = i;
      while (p > 0 && r[p - d].key > tem.key && p - d >= 0) {  //p=d��p����С���㣬p-d=0��ʾ��һ������
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
  printf("���ս���� ");
  for (i = 0; i < 10; i++) {
    printf("%d  ", r[i].key);
  }
  printf("\n");
}