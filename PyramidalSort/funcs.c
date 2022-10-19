#include "includes.h"

void input(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() - RAND_MAX / 2;
}

void output(int* arr, int n) {
	printf("Array: ");
	for (int i = 0; i < n; i++)
		printf("%i ", *(arr + i));
	printf("\n");
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int* arr, int n) {
	for (int i = 0; i < n/2; i++)
		swap(arr+i, arr + (n - 1 - i));
}

//Наибольшие элементы кучи выносит в начало(вверх)
void heapify(int* arr, int i, int n) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	int biggest = i;

	if (left <= n && arr[left] > arr[biggest])
		biggest = left;
	if (right <= n && arr[right] > arr[biggest])
		biggest = right;

	if (biggest != i) {
		swap(arr+biggest, arr+i);
		heapify(arr, biggest, n);
	}
}

//Формирует кучу
void make_heap(int* arr, int n) {
	reverse(arr, n);
	for (int i = n / 2; i >= 0; i--)
		heapify(arr, i, n - 1);
}

//Сортирует кучу
void heap_sort(int* arr, int n) {
	make_heap(arr, n);
	for (int i = n-1; i >= 0; i--) {
		swap(arr, arr + i);
		heapify(arr, 0, i-1);
	}
}