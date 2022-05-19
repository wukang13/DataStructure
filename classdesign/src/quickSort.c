//
// Created by 86136 on 2022/5/14.
//

#include "quickSort.h"
#include "stdio.h"
#include "string.h"
int quickSort(SqType r[], int s, int n);

/**
 * ���������
 * @param r ����
 * @param m ���±�
 * @param n ���±�
 */
void QuickSort(SqType y[], int m, int n) {
  static int times=0;
  SqType r[n];
  int z;
  memcpy(r, y,sizeof(SqType) * n);
  if (m < n) {
    z = quickSort(r, m, n);
    printf("��%d�˽����", ++times);
    for (int x = 0; x < 10; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
    QuickSort(r, m, z - 1);  //�������¼���浽low=high��λ��
    QuickSort(r, z + 1, n);
  }
}
/**
 * ��������
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
    if (left < right) {  //�ҵ�С��temp.key�ļ�¼,���н���
      r[left] = r[right];
      left++;
    }
    while (left < right && r[left].key <= temp.key)  //low�������ҵ�����temp.key�ļ�¼
      left++;
    if (left < right) {  //�ҵ�����temp.key�ļ�¼,���н���
      r[right] = r[left];
      right--;
    }
  }
  r[left] = temp;
  return left;//���������¼��λ��
}
