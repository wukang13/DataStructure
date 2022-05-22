//
// Created by 86136 on 2022/5/14.
//
#include <stdbool.h>
#include <memory.h>
#include "stdio.h"
#include "sqtype.h"
#include "insertsort.h"
#include "shellsort.h"
#include "quickSort.h"
#include "binsertsort.h"
#include "bubblesort.h"
#include "selectsort.h"
#include "mergingsort.h"

#define MaxSizes 50
void menu();
void Print(SqType r[], int n);

int main() {
  SqType r[MaxSizes];
  bool flag = false;

  int a[] = {75, 87, 68, 92, 88, 61, 77, 96, 80, 72}, n = 0;
  for (int i = 0; i < 10; i++) {
    r[i].key = a[i];
    n++;
  }
  SqType unsort[n];
  Print(r, n);
  int choice;
  menu();
  while (true) {
    if (flag) {
      printf("����0�ɼ�����8������:");
    }
    flag = true;
    scanf("%d", &choice);
    if (choice == 9)
      break;
    switch (choice) {
      case 0:flag = false;
        Print(unsort, n);
        menu();
        break;
      case 1:printf("ֱ�Ӳ�������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        InsertSort(unsort, n);
        break;
      case 2:printf("ϣ������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        ShellSort(unsort, n);
        break;
      case 3:printf("�۰��������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        BinsertSort(unsort, n);
        break;
      case 4:printf("ð������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        BubbleSort(unsort, n);
        break;
      case 5:printf("��������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        QuickSort(unsort, 0, n);
        break;
      case 6:printf("��ѡ������\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        SelectSort(unsort, n);
        break;
        case 7:printf("�鲢����\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        MergeSort(unsort,n);
        break;
      case 8:
        break;
      default:printf("������������ԣ�");
    }
  }
  return 0;
}

void menu() {
  printf("1����>ֱ�Ӳ�������\n");
  printf("2����>ϣ������\n");
  printf("3����>�۰��������\n");
  printf("4����>ð������\n");
  printf("5����>��������\n");
  printf("6����>��ѡ������\n");
  printf("7����>�鲢����\n");
  printf("8����>�˳�ϵͳ��\n");
  printf("��ѡ������Ҫ�����򷽷���\n");
}

void Print(SqType r[], int n) {
  printf("ԭ����Ϊ��");
  for (int i = 0; i < n; i++) {
    printf("%d  ", r[i].key);
  }
  printf("\n");
}