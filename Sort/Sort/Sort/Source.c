#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include "Sort.h"
#include "Function.h"


int main() {
	int* arr;
	int n = 10;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = n-i;
	}
	print_array(&arr, n);
	bubble_sort(&arr);
	print_array(&arr, n);
	free(arr);
	return 0;
}