// Write the programs for the following sorting algorithms
//      Bubble Sort, Selection Sort, Insertion Sort and Radix Sort
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int array[], int n) {
    for (int step = 0; step < n - 1; ++step) {
        for (int i = 0; i < n- step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                swap(&array[i],&array[i+1]);
            }
        }
    }
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx])
            min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
        max = array[i];
    return max;
}


void countingSort(int array[], int size, int place) {
    int output[size + 1];
    int max = (array[0] / place) % 10;
    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    int count[max + 1];
    for (int i = 0; i < max; ++i)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}


void radixsort(int array[], int size) {
    int max = getMax(array, size);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}


int main() {
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    printf("1 to bubble sort\n");
    printf("2 to selection sort\n");
    printf("3 to insertion sort\n");
    printf("4 to radix sort\n");
    int choice;
    printf("Enter your choice:");
    scanf("%d",&choice);
    if (choice==1){
        bubbleSort(array,n);    
    }
    else if (choice==2){
        selectionSort(array,n);    
    }
    else if (choice==3){
        insertionSort(array,n);    
    }
    else if (choice==4){
        radixsort(array,n);    
    }        
    printArray(array, n);
}