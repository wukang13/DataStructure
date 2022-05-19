/*75 87 68 92 88 61 77 96 80 72*/
#include "stdio.h"
#define MaxSizes 50
typedef struct {
  int key;
} SqType;
void Print(SqType r[], int n) {
  for (int i = 0; i < n; i++) {
  }
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
//直接插入排序：
void InsertSort(SqType r[], int n) {
  int i, j;
  SqType tem;
  for (i = 1; i < n; i++) {
    printf_s("第%d趟结果：", i);
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
  printf("最终结果：");
  for (int k = 0; k < 10; k++) {
    printf("  %d", r[k].key);
  }
  printf("\n");
}

//希尔排序：
void ShellSort(SqType r[], int n) {
  int i;
  SqType tem;
  for (int x = 1, d = n / 2; d > 0; d = d / 2, x++) {         //d相当于一把尺子，相隔距离d的结果数字为一组
    printf("第%d趟结果：", x);
    for (i = d; i < n; i++) {
      tem.key = r[i].key;
      int p = i;
      while (p > 0 && r[p - d].key > tem.key && p - d >= 0) {  //p=d，p不能小于零，p-d=0表示第一个数字
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
  printf("最终结果： ");
  for (i = 0; i < 10; i++) {
    printf("%d  ", r[i].key);
  }
  printf("\n");
}
//折半排序：
void BinsertSort(SqType r[], int n) {
  int i, j;
  SqType tem;
  int low, high, mid;
  for (i = 1; i < n; ++i) {      //从第二个数字开始
    tem.key = r[i].key;
    low = 1;
    high = i - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (tem.key < r[mid].key) { //左边插入
        high = mid - 1;
      } else {
        low = mid + 1;            //右边查找
      }
    }
    for (j = i - 1; j >= low; --j) {
      r[j + 1] = r[j];
    }
    r[low].key = tem.key;
    printf("第%d趟结果：", i);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}
//冒泡排序：
void BubbleSort(SqType r[], int n) {
  int i, j;
  SqType temp;
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {           //从后往前找
      if (r[j].key < r[j - 1].key) {     //前面大于后面就交换
        temp = r[j];
        r[j] = r[j - 1];
        r[j - 1] = temp;
      }
    }
    printf("第%d趟结果：", i + 1);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}
//快速排序：
int quickSort(SqType r[], int s, int n) {
  SqType temp;
  int left = s, right = n;
  temp = r[left];
  while (left != right) {
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
void QuickSort(SqType r[], int m, int n) {
  {
    int y;
    if (m < n) {
      y = quickSort(r, m, n);
      QuickSort(r, m, y - 1);  //将枢轴记录保存到low=high的位置
      QuickSort(r, y + 1, n);
    }
  }
  printf("第%d趟结果：", m);
  for (int x = 0; x < n; x++) {
    printf("  %d", r[x].key);
  }
  printf("\n");
}

//简单选择排序：
/*void SelectSort() {
  int i, k, j;
  int n;
  Record temp;
  n = length;
  for (i = 1; i <= n - 1; ++i) {
    k = i;
    for (j = i + 1; j <= n; ++j) {
      if (r[j].key < r[k].key) {
        k = j;
      }
    }
    if (k != i) {
      temp = r[i];
      r[i] = r[k];
      r[k] = temp;
    }
  }
}*/
//堆排序：
/*void sift(Record r[], int k, int m) {
  Record t;
  int i, j;
  int x;
  int finished;
  t = r[k];  //暂存跟记录人r[k]
  x = r[k].key;
  i = k;
  j = 2 * i;
  finished = 0;
  while (j <= m && !finished) {
    if (j < m && r[j].key > r[j + 1].key) {
      j = j + 1;  //若存在右子树,且右子树根的关键字小,则沿右分支筛选
    }
    if (x <= r[j].key) {
      finished = 1;  //筛选完毕
    } else {
      r[i] = r[j];
      i = j;
      j = 2 * i;
    }   //继续筛选
  }
  r[i] = t;
}

void creatheap(Record r[], int length) {
  int i, n;
  n = length;
  for (i = n / 2; i >= 1; --i) {  //自第[n/2]个记录开始筛选
    sift(r, i, n);
  }
}

void HeapSort() {
  int i, n;
  Record b;
  creatheap(r, length);
  n = length;
  for (i = n; i >= 2; --i) {
    b = r[i];  //堆顶和堆最后一个交换
    r[i] = r[1];  //最值放放入r[i]
    r[1] = b;
    sift(r, 1, i - 1);  //继续调整,使r[1...i-1]变成堆
  }
}*/
//归并排序：
/*void Merge(Record r1[], int low, int mid, int high, Record r2[]) {
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;
  while ((i <= mid) && (j <= high)) {  //归并
    if (r1[i].key <= r1[j].key) {
      r2[k] = r1[i];
      ++i;
    } else {
      r2[k] = r1[j];
      ++j;
    }
    ++k;
  }
//    若右剩余的,放入r2中
  while (i <= mid) {
    r2[k] = r1[i];
    k++;
    i++;
  }
  while (j <= high) {
    r2[k] = r1[j];
    k++;
    j++;
  }
}

void MSort(Record r1[], int low, int high, Record r3[]) {
  int mid;
  Record r2[20];
  if (low == high) {
    r3[low] = r1[low];
  } else {
    mid = (low + high) / 2;
    MSort(r1, low, mid, r2);
    MSort(r1, mid + 1, high, r2);
    Merge(r2, low, mid, high, r3);
  }
}

void MergeSort() {
  MSort(r, 1, n, r);
}*/
int main() {
  SqType r[MaxSizes];
  int a[] = {75, 87, 68, 92, 88, 61, 77, 96, 80, 72}, n = 0;
  for (int i = 0; i < 10; i++) {
    r[i].key = a[i];
    n++;
  }
  Print(r, n);
  int choice;
  while (1) {
    menu();
    scanf("%d", &choice);
    if (choice == 9)
      break;
    switch (choice) {
      case 1:InsertSort(r, n);
        break;
      case 2:ShellSort(r, n);
        break;
      case 3:BinsertSort(r, n);
        break;
      case 4:BubbleSort(r, n);
        break;
      case 5:QuickSort(r, 1, n);
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
}


/*{
  printf("希尔排序\n");
  int i;
  int r[10];
  printf("请输入待排序的十个数：");
  for (i = 0; i < 10; i++) {
    scanf("%d", &r[i]);
  }
  for (int x=1, d = 10 / 2; d >0; d = d / 2,x++) {
    printf("第%d趟结果：",x);
    for (i = d; i < 10; i++) {
      int tem = r[i];
      int p = i;
      while (p> 0 && r[p - d] > tem&&p-d>=0) {
        r[p] = r[p - d];
        p = p - d;
      }
      r[p] = tem;
    }
    for (int k = 0; k < 10; k++) {
      printf("%d  ", r[k]);
    }
    printf("\n");
  }
  printf("最终结果： ");
  for (i = 0; i < 10; i++) {
    printf("%d ", r[i]);
  }
}*/