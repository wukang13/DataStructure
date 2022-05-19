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
//ֱ�Ӳ�������
void InsertSort(SqType r[], int n) {
  int i, j;
  SqType tem;
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
//�۰�����
void BinsertSort(SqType r[], int n) {
  int i, j;
  SqType tem;
  int low, high, mid;
  for (i = 1; i < n; ++i) {      //�ӵڶ������ֿ�ʼ
    tem.key = r[i].key;
    low = 1;
    high = i - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (tem.key < r[mid].key) { //��߲���
        high = mid - 1;
      } else {
        low = mid + 1;            //�ұ߲���
      }
    }
    for (j = i - 1; j >= low; --j) {
      r[j + 1] = r[j];
    }
    r[low].key = tem.key;
    printf("��%d�˽����", i);
    for (int x = 0; x < n; x++) {
      printf("  %d", r[x].key);
    }
    printf("\n");
  }
}
//ð������
void BubbleSort(SqType r[], int n) {
  int i, j;
  SqType temp;
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
//��������
int quickSort(SqType r[], int s, int n) {
  SqType temp;
  int left = s, right = n;
  temp = r[left];
  while (left != right) {
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
void QuickSort(SqType r[], int m, int n) {
  {
    int y;
    if (m < n) {
      y = quickSort(r, m, n);
      QuickSort(r, m, y - 1);  //�������¼���浽low=high��λ��
      QuickSort(r, y + 1, n);
    }
  }
  printf("��%d�˽����", m);
  for (int x = 0; x < n; x++) {
    printf("  %d", r[x].key);
  }
  printf("\n");
}

//��ѡ������
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
//������
/*void sift(Record r[], int k, int m) {
  Record t;
  int i, j;
  int x;
  int finished;
  t = r[k];  //�ݴ����¼��r[k]
  x = r[k].key;
  i = k;
  j = 2 * i;
  finished = 0;
  while (j <= m && !finished) {
    if (j < m && r[j].key > r[j + 1].key) {
      j = j + 1;  //������������,�����������Ĺؼ���С,�����ҷ�֧ɸѡ
    }
    if (x <= r[j].key) {
      finished = 1;  //ɸѡ���
    } else {
      r[i] = r[j];
      i = j;
      j = 2 * i;
    }   //����ɸѡ
  }
  r[i] = t;
}

void creatheap(Record r[], int length) {
  int i, n;
  n = length;
  for (i = n / 2; i >= 1; --i) {  //�Ե�[n/2]����¼��ʼɸѡ
    sift(r, i, n);
  }
}

void HeapSort() {
  int i, n;
  Record b;
  creatheap(r, length);
  n = length;
  for (i = n; i >= 2; --i) {
    b = r[i];  //�Ѷ��Ͷ����һ������
    r[i] = r[1];  //��ֵ�ŷ���r[i]
    r[1] = b;
    sift(r, 1, i - 1);  //��������,ʹr[1...i-1]��ɶ�
  }
}*/
//�鲢����
/*void Merge(Record r1[], int low, int mid, int high, Record r2[]) {
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;
  while ((i <= mid) && (j <= high)) {  //�鲢
    if (r1[i].key <= r1[j].key) {
      r2[k] = r1[i];
      ++i;
    } else {
      r2[k] = r1[j];
      ++j;
    }
    ++k;
  }
//    ����ʣ���,����r2��
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
      default:printf("������������ԣ�");
    }
  }
}


/*{
  printf("ϣ������\n");
  int i;
  int r[10];
  printf("������������ʮ������");
  for (i = 0; i < 10; i++) {
    scanf("%d", &r[i]);
  }
  for (int x=1, d = 10 / 2; d >0; d = d / 2,x++) {
    printf("��%d�˽����",x);
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
  printf("���ս���� ");
  for (i = 0; i < 10; i++) {
    printf("%d ", r[i]);
  }
}*/