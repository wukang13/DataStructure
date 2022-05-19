//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: ��������
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;


/**
 * @time 2021/4/29 15:32
 * @description ������r�е�r[left]��r[right]���ֽ���һ�˿�������,���õ������¼
 * �����Ľ��������֮��()ǰ�ļ�¼�Ĺؼ��־���С��(����)�����¼
 * @param
 * @return
 */
int Partition(Record r[], int left, int right) {
    Record temp;
    int low, high;
    temp = r[left];
    low = left;
    high = right;
    while (low < high) {
        while (low < high && r[high].key >= temp.key) {
            high--;
        }
        if (low < high) {  //�ҵ�С��temp.key�ļ�¼,���н���
            r[low] = r[high];
            low++;
        }
        while (low < high && r[low].key < temp.key) {  //low�������ҵ�����temp.key�ļ�¼
            low++;
        }
        if (low < high) {  //�ҵ�����temp.key�ļ�¼,���н���
            r[high] = r[low];
            high--;
        }
    }
    r[low] = temp;  //�������¼���浽low=high��λ��
    return low;  //���������¼��λ��
}

void quicksort(Record r[], int low, int high) {
    int pos;
    if (low < high) {
        pos = Partition(r, low, high);
        quicksort(r, low, pos - 1);
        quicksort(r, pos + 1, high);
    }
}

int main() {
    printf("��������\n");
    int i, j;
    Record r[20];
    int len;
    printf("����������¼�ĳ��ȣ�");
    fflush(stdout);
    scanf("%d", &len);
    rewind(stdin);
    printf("����%d����¼�Ĺؼ���ֵ\n", len);
    fflush(stdout);
    for (i = 1; i <= len; i++) {
        printf("�������%d���ؼ���ֵ:", i);
        fflush(stdout);
        scanf("%d", &j);
        rewind(stdin);
        r[i].key = j;
    }
    quicksort(r, 1, len);
    printf("�����������:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}
