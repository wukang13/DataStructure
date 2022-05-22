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
      printf("输入0可继续（8结束）:");
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
      case 1:printf("直接插入排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        InsertSort(unsort, n);
        break;
      case 2:printf("希尔排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        ShellSort(unsort, n);
        break;
      case 3:printf("折半插入排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        BinsertSort(unsort, n);
        break;
      case 4:printf("冒泡排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        BubbleSort(unsort, n);
        break;
      case 5:printf("快速排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        QuickSort(unsort, 0, n);
        break;
      case 6:printf("简单选择排序法\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        SelectSort(unsort, n);
        break;
        case 7:printf("归并排序\n");
        memcpy(unsort, r, sizeof(SqType) * n);
        MergeSort(unsort,n);
        break;
      case 8:
        break;
      default:printf("输入错误，请重试！");
    }
  }
  return 0;
}

void menu() {
  printf("1——>直接插入排序法\n");
  printf("2——>希尔排序法\n");
  printf("3——>折半插入排序法\n");
  printf("4——>冒泡排序法\n");
  printf("5——>快速排序法\n");
  printf("6——>简单选择排序法\n");
  printf("7——>归并排序法\n");
  printf("8——>退出系统！\n");
  printf("请选择你想要的排序方法：\n");
}

void Print(SqType r[], int n) {
  printf("原数组为：");
  for (int i = 0; i < n; i++) {
    printf("%d  ", r[i].key);
  }
  printf("\n");
}