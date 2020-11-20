#include<stdio.h>
#include<stdlib.h>

void QuickSort(int* array, int size) {
    char *sd =(char *)malloc( size * sizeof(char) );

    for (int i = 0; i < size; ++i){
        sd[i] = 0;
    }
    for (int j = 0 ; j < size - 1; j += (sd[j+1]|sd[j])) {
        int l = j;
        int r = l + 1;
        while (sd[r] != 1 && r != size) {++r;}
        --r;
        int m = (r + l) / 2;
        for (int i = l; i < m; ++i)
            if (array[i] > array[m]){
                int tmp = array[i];
                array[i--] = array[m-1];
                array[m-1] = array[m];
                array[m--] = tmp;
            }
        for (int i = m + 1 ; i <= r; ++i)
            if (array[i] < array[m]){
                int tmp = array[i];
                array[i] = array[m+1];
                array[m+1] = array[m];
                array[m++] = tmp;
            }
        sd[m] = 1;
    }
}

int main() {
    int n;
    printf("Size of array:");
    scanf("%d",&n);
    int* array = (int*)malloc(n*sizeof(int));
    printf("Elements of array:");
    for (int i = 0;i < n; ++i){
        scanf("%d", &array[i]);
    }
    QuickSort(array, n);
    for (int i = 0; i < n; ++i){
        printf("%d ",array[i]);
    }
    free(array);
    return 0;
}
