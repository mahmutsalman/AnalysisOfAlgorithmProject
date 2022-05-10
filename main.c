#include<stdio.h>
#include <string.h>

//Global value
int numberOfBasicOp = 0;
int count = 0;

void insertionSort(int array[], int size) {
    numberOfBasicOp = 0;
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (++numberOfBasicOp && key < array[j] && j >= 0) {
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
    int pivot = array[low];

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

// QUICK SORT
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


//MERGE SORT
//stack
int merge(int arr[], int l, int m, int r) {
    int i = l; /* left subarray*/
    int j = m + 1; /* right  subarray*/
    int k = l; /* temporary array*/
    int temp[r + 1];
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
        count++;

    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
    return count;
}

int mergesort(int arr[], int l, int r) {
    int comparisons;
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        comparisons = merge(arr, l, m, r);
    }
    return comparisons;
}

// Generating worst case
// Indicates function to join left and right subarray
int join(int arr1[], int left1[], int right1[],
         int l1, int m1, int r1) {
    int i; // So used in second loop
    for (i = 0; i <= m1 - l1; i++)
        arr1[i] = left1[i];
    for (int j = 0; j < r1 - m1; j++)
        arr1[i + j] = right1[j];
}

// Indicates function to store alternate elements in left
// and right subarray
int split(int arr1[], int left1[], int right1[],
          int l1, int m1, int r1) {
    for (int i = 0; i <= m1 - l1; i++)
        left1[i] = arr1[i * 2];
    for (int i = 0; i < r1 - m1; i++)
        right1[i] = arr1[i * 2 + 1];
}

// Indicates function to generate Worst Case of Merge Sort
int generateWorstCase(int arr1[], int l1, int r1) {
    if (l1 < r1) {
        int m1 = l1 + (r1 - l1) / 2;
        // creating two auxillary arrays
        int left1[m1 - l1 + 1];
        int right1[r1 - m1];
        // Storing alternate array elements in left
        // and right subarray
        split(arr1, left1, right1, l1, m1, r1);
        // Recursing first and second halves
        generateWorstCase(left1, l1, m1);
        generateWorstCase(right1, m1 + 1, r1);
        // joining left and right subarray
        join(arr1, left1, right1, l1, m1, r1);
    }
}


void printArr(int a[], int n)/*function to print the array*/
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int returnKthElement(int a[], int k) {
    return a[k - 1];
}

void read(int array[], char *inputFile) {
    int index = 0;
    int entity = 0;
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
        array[index] = entity;
        index++;
    }
}

// SELECTION SORT
// function to swap the the position of two elements
void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int array[], int size, int kthElement) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        if (step == kthElement) {
            return array[kthElement - 1];
        }
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (++numberOfBasicOp && array[i] < array[min_idx])
                min_idx = i;
        }
        // put min at the correct position
        // exchange

        swap2(&array[min_idx], &array[step]);


    }
}

// Heap sort
// Function to swap the the position of two elements


// To heapify a subtree with node i as root

// Size of heap is n

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int leftChild = 2 * i + 1; // left child = 2*i + 1
    int rightChild = 2 * i + 2; // right child = 2*i + 2

// If left child is greater than root

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

// If right child is greater than new largest

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

// If largest is not the root

    if (largest != i) {
// swap root with the new largest

        swap(&arr[i], &arr[largest]);

// Recursively heapify the affected sub-tree i.e, subtree with root as largest
        heapify(arr, n, largest);
    }
}


// Function to build a Max-Heap from a given array

void buildHeap(int arr[], int n) {
// Index of last non-leaf node
    int lastNonLeafNode = (n / 2) - 1;

// Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
    for (int i = lastNonLeafNode; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteRoot(int arr[], int n) {
// Get the last element
    int lastElement = arr[n - 1];

// Replace root with last element
    arr[0] = lastElement;

// Decrease size of heap by 1
    n = n - 1;

// heapify the root node
    heapify(arr, n, 0);
}


int main() {
    int iterator = 0;
    while (iterator < 10) {
        setbuf(stdout, 0);
        printf("Enter algorithm type:          --Insertion: 1,Merge Sort: 2 ,Quicksort: 3,Selection sort: 4 , Heap sort: 5 \n");
        int option;
        scanf("%d", &option);

        //For Insertion sort
        if (option == 1) {
            int a[15];
            int kthElement = 0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a, filename);
            numberOfBasicOp = 0;
            insertionSort(a, 15);
            printf("Number of comparisons %d\n", numberOfBasicOp);
            printf("k th element?");
            scanf("%d", &kthElement);
            printf("%d\n", returnKthElement(a, kthElement));
        }
            //Merge sort
        else if (option == 2) {
            int a[50];
            int kthElement = 0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            numberOfBasicOp = 0;
            read(a, filename);
            // Generate worst case
            generateWorstCase(a, 0, 50 - 1); // size - 1
            printArr(a, 50);
            printf("Number of comparisons %d \n", mergesort(a, 0, 50 - 1));

        }
            // Quicksort
        else if (option == 3) {
            int a[50];
            int kthElement = 0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a, filename);
            numberOfBasicOp = 0;
            quickSort(a, 0, 49);
            printf("Number of comparisons %d\n", numberOfBasicOp);
            printf("k th element?");
            scanf("%d", &kthElement);
            printf("%d\n", returnKthElement(a, kthElement));
        }

            //Selection sort
        else if (option == 4) {
            int a[7];
            int kthElement = 0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a, filename);

            printf("kth element is %d\n", selectionSort(a, 7, kthElement));
            printf("Number of comparisons %d\n", numberOfBasicOp);
        }
            // Heap sort
        else if (option == 5) {
            int size = 20;
            int a[20];
            int kthElement = 0;
            setbuf(stdout, 0);
            printf("%s", "Please enter the name of the file :");
            char filename[20];
            scanf("%s", filename);
            read(a, filename);
            numberOfBasicOp = 0;
            buildHeap(a, 20);
            // [1,2,3,4,5]
            printf("k th element?");
            scanf("%d", &kthElement);
            int numberOfDeletion = 20 - kthElement;

            for (int i = 0; i <numberOfDeletion ; ++i) {
                deleteRoot(a,size);
                size--;
            }

            printf("The root is : %d",a[0]);
            printf("Number of comparisons : %d\n", numberOfBasicOp);

        }
    }

    return 0;
}
