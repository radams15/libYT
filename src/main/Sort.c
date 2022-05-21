//
// Created by rhys on 19/05/22.
//

#include "Sort.h"

void swap(Video_t** intArray, int num1, int num2) {
    Video_t* temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

int partition(Video_t** intArray, int left, int right, long pivot) {
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
            swap(intArray, leftPointer,rightPointer);
        }
    }

    swap(intArray, leftPointer,right);
    return leftPointer;
}

void reverse_vids(Video_t** arry, int length){
    int opposite;
    Video_t* temp;

    for(int i=0 ; i<length ; i++){
        opposite = length-i-1;

        //printf("Swap %d with %d\n", i, opposite);

        swap(arry, i, opposite);
    }
}

void sort_vids(Video_t** arry, int length, int left, int right) {
    if(right-left <= 0) {
        return;
    } else {
        long pivot = arry[right]->published;
        int partitionPoint = partition(arry, left, right, pivot);
        sort_vids(arry, length, left, partitionPoint - 1);
        sort_vids(arry, length, partitionPoint + 1, right);
    }
}
