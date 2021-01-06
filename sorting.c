#include <stdio.h>

//shifts i elements from the start of arr to the right.
void shift_element(int* arr, int i) {
    int *arrStart = arr;
    int *fromArrPtr = arrStart+i-1;
    int *shiftToPtr = fromArrPtr+1;

    for (int j=0; j<i; j++) {
        *shiftToPtr-- = *fromArrPtr--;
    }
}

//sorts an array with len elements using insertion sort algorithm
void insertion_sort(int* arr , int len) {
    int *arrStart = arr;
    
    for (int i=1; i<len; i++) {
        int *iPtr = arrStart+i;
        for (int j=0; j<i; j++) {
            int *jPtr = arrStart+j;
            if (*iPtr<*jPtr) {
                int temp = *iPtr;
                shift_element(jPtr, i-j);
                *jPtr = temp;
                break;
            }
        }
    }

    /*
    for (int i=1; i<len; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]<arr[j]) {
                int temp = arr[i];
                shift_element(&arr[j], i-j);
                arr[j] = temp;
                break;
            }
        }
    }
    */
}