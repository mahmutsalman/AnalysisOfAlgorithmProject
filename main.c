#include<stdio.h>
#include <string.h>
//Global value
int numberOfBasicOp=0;
void insertionSort(int array[], int size) {
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

}

// Quick-sort algorithm
// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (++numberOfBasicOp && array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

void printArr(int a[], int n)/*function to print the array*/
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int returnKthElement(int a[],int k){
    return a[k-1];
}
void read(int array[],char *inputFile){
    int index=0;
    int entity=0;
    FILE *fPtr;
    char fileNamex[100];
    strcpy(fileNamex, "C:\\Users\\asxdc\\CLionProjects\\AnalysisOfAlgorithmProject\\");
    //inputFile ex : input.txt
    strcat(fileNamex, inputFile);
    fPtr = fopen(fileNamex, "r");
    if (fPtr == NULL) {
        printf("There is a error opening the file.");

    }
    while (fscanf(fPtr, "%d", &entity) != EOF) {
        array[index]=entity;
        index++;
    }


}

// SELECTION SORT


int main() {
    int iterator=0;
    while(iterator<10){
        printf("Enter algorithm type:          --Insertion: 1,Quicksort: 3 \n");
        int option;
        scanf("%d", &option);

        //For Insertion sort
        if(option==1){
            int a[15];
            int kthElement=0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a,filename);
            numberOfBasicOp=0;
            insertionSort(a,15);
            printf("Number of comparasions %d\n",numberOfBasicOp);
            printf("k th element?");
            scanf("%d",&kthElement);
            printf("%d\n", returnKthElement(a,kthElement));
        }
        // For Quicksort
        else if(option==3){
            int a[15];
            int kthElement=0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a,filename);
            numberOfBasicOp=0;
            quickSort(a,0,14);
            printf("Number of comparasions %d\n",numberOfBasicOp);
            printf("k th element?");
            scanf("%d",&kthElement);
            printf("%d\n", returnKthElement(a,kthElement));
        }

    }

    return 0;
}
