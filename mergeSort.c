#include <stdio.h>

void merge(int *arr, int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[right];
  int R[right];
  //putting element into left arr
  for (int i = 0; i < n1; i++){
    L[i] = *(arr + (left + i));
  }
  // putting element into right ar
  for (int j = 0; j < n2; j++){
    R[j] = *(arr + (mid + j + 1));
  }
  int i = 0;
  int j = 0;
  int k = left;
  while ((i < n1) && (j < n2)){
    if (L[i] >= R[j]){
      *(arr + k) = L[i];
      i += 1;
    }
    else{
      *(arr + k) = R[j];
      j += 1;
    k += 1;
    }
  }

  while (i < n1){
    *(arr + k) = L[i];
    i += 1;
    k += 1;
  }

  while (j < n2){
    *(arr + k) = R[j];
    j += 1;
    k += 1;
  }
}

void mergeHelper(int *arr, int left, int right){
  if (left < right){
      int mid = (left + right) / 2; // 2
      mergeHelper(arr, left, mid);
      mergeHelper(arr, mid + 1, right);
      merge(arr, left, mid, right);
  }
}

void mergeSort(int *a, int n) {
  mergeHelper(a, 0, n - 1);
}

int main(void)
{
    int arr[] = {90, 30, 70, 100};
    int length = sizeof(arr) / sizeof(int);
    printf("sorted array is ");
    mergeSort(arr, length);
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
