//
// Created by rhys on 19/05/22.
//

#include "Sort.h"
#include <stdio.h>

void swap(Video_t** intArray, int num1, int num2) {
    Video_t* temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

int partition(Video_t** intArray, int left, int right, int pivot) {
    int leftPointer = left -1;
    int rightPointer = right;

    while(1) {
        while(intArray[++leftPointer]->published < pivot) {
            //do nothing
        }

        while(rightPointer > 0 && intArray[--rightPointer]->published > pivot) {
            //do nothing
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            printf(" item swapped :%ld,%ld\n", intArray[leftPointer]->published,intArray[rightPointer]->published);
            swap(intArray, leftPointer,rightPointer);
        }
    }

    printf(" pivot swapped :%ld,%ld\n", intArray[leftPointer]->published,intArray[right]->published);
    swap(intArray, leftPointer,right);
    printf("Updated Array: ");
    return leftPointer;
}

void quickSort(Video_t** intArray, int left, int right) {
    if(right-left <= 0) {
        return;
    } else {
        long pivot = intArray[right]->published;
        int partitionPoint = partition(intArray, left, right, pivot);
        quickSort(intArray, left,partitionPoint-1);
        quickSort(intArray, partitionPoint+1,right);
    }
}
