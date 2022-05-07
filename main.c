#include<stdio.h>

//Global value
int numberOfBasicOp=0;
int insertionSort(int array[], int size,int kthElement) {
    numberOfBasicOp=0;
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (++numberOfBasicOp &&key < array[j] && j >= 0 ) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    return array[kthElement-1];
}

void printArr(int a[], int n)/*function to print the array*/
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {10, 9, 8, 7, 6, 5};
    int b[]={5,6,7,8,9,10};
    int n = sizeof(a) / sizeof(a[0]);
    int nb = sizeof(b) / sizeof(b[0]);

    int kthElement = 2;
    setbuf(stdout, 0);
    printf("Before sorting array elements are-\n");
    printArr(a, n);

    //Insertion sort for the worst case
   insertionSort(a, n, kthElement);
    printf("\nAfter sorting array elements are-\n");
    printArr(a, n);
    printf("Number of operations %d\n",numberOfBasicOp);
    kthElement=2;
    printf("Printing kth element %d\n", insertionSort(a, n, kthElement));

    printf("------------------------------------------------------------------");
    //Insertion sort for the best case

    setbuf(stdout, 0);
    printf("\nBefore sorting array elements are-\n");
    printArr(b, n);
    insertionSort(b, n, kthElement);
    printf("\nAfter sorting array elements are-\n");
    printArr(b, n);
    printf("Number of operations %d\n",numberOfBasicOp);
    kthElement=2;
    printf("Printing kth element %d\n", insertionSort(b, nb, kthElement));



    return 0;
}
