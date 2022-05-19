//
// Created by 86136 on 2022/5/14.
//
#include <stdbool.h>
#include "stdio.h"
#include "sqtype.h"
#include "insertsort.h"
#include "shellsort.h"
#include "quickSort.h"
#include "binsertsort.h"
#include "bubblesort.h"

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
  Print(r, n);
  int choice;
  menu();
  while (true) {
    if (flag) {
      printf("����0�ɼ�����9������:");
    }
    flag = true;
    scanf("%d", &choice);
    if (choice == 9)
      break;
    switch (choice) {
      case 0:flag = false;
        menu();
        break;
      case 1:printf("ֱ�Ӳ�������\n");
        InsertSort(r, n);
        break;
      case 2:printf("ϣ������\n");
        ShellSort(r, n);
        break;
      case 3:printf("�۰��������\n");
        BinsertSort(r, n);
        break;
      case 4:printf("ð������\n");
        BubbleSort(r, n);
        break;
      case 5:printf("��������\n");
        QuickSort(r, 0, n);
        break;
        /*case 6:
          SelectSort();
          break;
        case 7:
          HeapSort();
          break;
        case 8:
          MergeSort();
          break;*/
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
  printf("8����>������\n");
  printf("9����>�˳�ϵͳ��\n");
  printf("��ѡ������Ҫ�����򷽷���\n");
}

void Print(SqType r[], int n) {
  for (int i = 0; i < n; i++) {
  }
}