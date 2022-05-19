
#include "stdio.h"
int main() {
  printf("直接插入排序:\n");
  int i, j, tem;
  int r[10];
  printf("输入十个待排序的数字：");
  for (i = 0; i < 10; i++) {
    scanf("%d", &r[i]);
  }
  for (i = 1; i <= 9; i++) {
    printf_s("第%d趟结果：", i);
    tem = r[i];
    if (r[i] < r[i - 1]) {
      for (j = i - 1; j >= 0 && r[j] > tem; j--) {
        r[j + 1] = r[j];
        r[j] = tem;
      }
    }
    for (int k = 0; k < 10; k++)
      printf("  %d", r[k]);
    printf("\n");
  }
}

