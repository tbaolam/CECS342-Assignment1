#include <stdio.h>

int partition(int *arr, int p, int r) {
  int x = *(arr + r);
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (*(arr + j) > x){
      i += 1;
      int temp = *(arr + i);
      *(arr + i) = *(arr + j);
      *(arr + j) = temp;

    }
  }
  int temp = *(arr + (i + 1));
  *(arr + (i + 1)) = *(arr + r);
  *(arr + r) = temp;
  return i + 1;
}

void quickHelper(int *a, int p, int r){
  if (p < r) {
    int q = partition(a, p, r);
    quickHelper(a, p, q - 1);
    quickHelper(a, q + 1, r);
  }
}

void quickSort(int *a, int n) {
  quickHelper(a, 0, n - 1);
}

int main(void)
{
    int arr[] = {90, 30, 70, 100};
    int length = sizeof(arr) / sizeof(int);
    printf("sorted array is ");
    quickSort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }

    int arr[] = {};
    int length = sizeof(arr) / sizeof(int);
    printf("sorted array is ");
    quickSort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        printf(" ");
    }
}
