
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* mergeSort algorithm implementation in C */
#include <stdio.h>
#include <stdlib.h>

#define LOWER_INDEX 0

void swap(int *val1, int *val2) {
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int* merge(int* arr1, int s1, int* arr2, int s2) {
	int* arr = (int*)malloc(sizeof(int) * (s1 + s2));
	int k = 0;
	int newStart = 0;
	for (int i = 0; i < s1; i++) {
		for (int j = newStart; j < s2; j++) {
			if (arr1[i] < arr2[j]) {
				arr[k++] = arr1[i];
				break;
			}
			else {
				arr[k++] = arr2[j];
				newStart = j + 1 ;
			}
		}


		if (newStart == s2) {
			for (int l = i; l < s1; l++) {
				arr[k] = arr1[l];
				k++;
			}
			return arr;
		}
		else if (i+1 == s1) {
			for (int l = newStart; l < s2; l++) {
				arr[k] = arr2[l];
				k++;
			}
			return arr;
		}


	}

	return arr;
}

int* breakArr(int *arr, int low, int high) {
	int middle = (low + high) / 2;
	int *subArr1 = (int *)malloc(sizeof(int)*(middle+1 - low));
	int *subArr2 = (int *)malloc(sizeof(int) * (high - middle));
	int indexArr1 = 0,indexArr2 =0;
	if (high - low < 2)									//minimum number elements in an array should be two or more: this is the base condition for recursive call
		return NULL;
	else {
		for (int index = low; index <= middle; index++) {
			subArr1[indexArr1] = arr[index];
			indexArr1++;
		}
		breakArr(subArr1, low, middle);
		for (int index = middle + 1; index <= high; index++) {
			subArr2[indexArr2] = arr[index];
			indexArr2++;
		}
		breakArr(subArr2, middle, high);
		return merge(subArr1, indexArr1, subArr2, indexArr2);

	}
}

void display(int* arr, int s) {
	for (int index = 0; index < s; index++)
		printf("%d ", arr[index]);
}

int main() {
	int testArray[] = {2,45,55,80,85,37,48,72,95};
	int sizeOfArr = (sizeof(testArray) / 4);

	printf("Before Sorting...\n");
	display(testArray, sizeOfArr);
	
	int *sortedArr = breakArr(testArray, LOWER_INDEX, sizeOfArr - 1);

	printf("\nAfter Sorting....\n");
	display(sortedArr, sizeOfArr);

	return 0;
}

