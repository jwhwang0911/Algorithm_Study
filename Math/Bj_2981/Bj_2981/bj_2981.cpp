#include <stdio.h>
#include <stdlib.h>

void qsort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = start;   //�Ǻ��� ù ��° ���� 
    int i = pivot + 1;   //i�� �Ǻ� �������� 
    int j = end;   //j�� ������ ���� 
    int temp;

    while (i <= j) {
        //�Ǻ� ���� ū �� ���� �� ����
        while (i <= end && arr[i] <= arr[pivot]) {
            ++i;
        }
        //�Ǻ� ���� ���� �� ���� �� ����
        while (j > start && arr[j] >= arr[pivot]) {
            --j;
        }

        //������ ���� i�� j�� �����ų� �������� ����
        if (i >= j) break;

        //�� ���� ��ȯ 
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //�Ǻ� ���� �Ϸ� 
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    qsort(arr, start, j - 1);   //�Ǻ� �߽����� ���ʺκ� ����
    qsort(arr, j + 1, end);   //�Ǻ� �߽����� �����ʺκ� ����

}

int main()
{
    int n, i;
    int temp;
    int min = 1000000000;

    scanf("%d", &n);

    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * (n - 1));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    qsort(arr1, 0, n);

    for (i = 0; i < n - 1; i++)
    {
        arr2[i] = arr1[i + 1] - arr1[i];
        if (min > arr2[i]) min = arr2[i];
    }

    for (i = 2; i <= min; i++)
    {
        if (min % i == 0) printf("%d ", i);
    }
    printf("\n");

    return 0;
}