#include <stdio.h>
#include <stdlib.h>

//Input: encoded = [1,2,3], first = 1
//Output: [1,0,2,1]
//Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
int* decode(int *encoded, int encodedSize, int first, int *returnSize){
    int i;
    int *arr;
    arr = (int*) malloc((encodedSize + 1) * sizeof(int));

    if(!arr){
        printf("Cannot allocate memory.\n");
        return NULL;
    }

    arr[0] = first;
    for(i = 1; i < encodedSize + 1; i++)
        arr[i] = arr[i - 1] ^ encoded[i - 1];

    *returnSize = encodedSize + 1;

    return arr;
}

void printArray(int *arr, int arrSize){
    int i;
    printf("[");
    for(i = 0; i < arrSize; i++)
        printf("%d%s", arr[i], i == arrSize - 1 ? "" : ",");
    printf("]");
}

int main(){
    int encoded[] = {1,2,3};
    int *arr;
    int arrSize;
    int first = 1;

    printf("Input:  encoded = ");
    printArray(encoded, 3);
    printf(", first = %d\n", first);
    arr = decode(encoded, 3, first, &arrSize);
    printf("Output: ");
    printArray(arr, arrSize);
    free(arr);

    return 0;
}
