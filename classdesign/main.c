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
      printf("输入0可继续（9结束）:");
    }
    flag = true;
    scanf("%d", &choice);
    if (choice == 9)
      break;
    switch (choice) {
      case 0:flag = false;
        menu();
        break;
      case 1:printf("直接插入排序法\n");
        InsertSort(r, n);
        break;
      case 2:printf("希尔排序法\n");
        ShellSort(r, n);
        break;
      case 3:printf("折半插入排序法\n");
        BinsertSort(r, n);
        break;
      case 4:printf("冒泡排序法\n");
        BubbleSort(r, n);
        break;
      case 5:printf("快速排序法\n");
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
  printf("8——>堆排序法\n");
  printf("9——>退出系统！\n");
  printf("请选择你想要的排序方法：\n");
}

void Print(SqType r[], int n) {
  for (int i = 0; i < n; i++) {
  }
}