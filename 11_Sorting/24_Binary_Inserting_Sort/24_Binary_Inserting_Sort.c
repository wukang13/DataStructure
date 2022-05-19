//
// Created by Nine_Dollar on 2021/4/28.
//
/**
 * p: ���ֲ�������
 */
#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/28 16:36
 * @description �۰��������
 * @param
 * @return
 */
void BinsertSort(Record r[], int length) {
    int i, j;
    Record x;
    int low, high, mid;
    for(i = 2; i<=length;++i){
        x = r[i];
        low=1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if(x.key < r[mid].key){ //��߲���
                high = mid - 1;
            } else{
                low = mid + 1;  //�ұ߲���
            }
        }
        for (j = i - 1; j >= low; --j) {
            r[j + 1] = r[j];
        }
        r[low] = x;
    }
}


int main() {
    printf("���ֲ�������\n");
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
    BinsertSort(r, len);
    printf("���ֲ����������:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}
