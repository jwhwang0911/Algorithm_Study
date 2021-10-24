#include <stdio.h>
#include <stdlib.h>

void qsort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = start;   //피봇은 첫 번째 원소 
    int i = pivot + 1;   //i는 피봇 다음원소 
    int j = end;   //j는 마지막 원소 
    int temp;

    while (i <= j) {
        //피봇 보다 큰 값 만날 때 까지
        while (i <= end && arr[i] <= arr[pivot]) {
            ++i;
        }
        //피봇 보다 작은 값 만날 때 까지
        while (j > start && arr[j] >= arr[pivot]) {
            --j;
        }

        //위에서 계산된 i와 j가 만나거나 엇갈리면 종료
        if (i >= j) break;

        //두 원소 교환 
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    //피봇 정렬 완료 
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;

    qsort(arr, start, j - 1);   //피봇 중심으로 왼쪽부분 분할
    qsort(arr, j + 1, end);   //피봇 중심으로 오른쪽부분 분할

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