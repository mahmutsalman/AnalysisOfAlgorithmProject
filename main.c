#include<stdio.h>


int insert(int a[], int n, int kthElement)/*function to sort an array with insertion sort*/
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && temp <= a[j])/*Move the elements greater than temp to one position ahead from their current position*/
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    return a[kthElement - 1];
}

void printArr(int a[], int n)/*function to print the array*/
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}

int main() {
    int a[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(a) / sizeof(a[0]);
    int kthElement = 2;
    setbuf(stdout, 0);
    printf("Before sorting array elements are-\n");
    printArr(a, n);
    insert(a, n, kthElement);
    printf("\nAfter sorting array elements are-\n");
    printArr(a, n);
    printf("Printing kth element %d", insert(a, n, kthElement));
    return 0;

}
