#include "includes.h"
#include "funcs.h"

int main() {
	int n;
	printf("Enter length of array ");
	scanf_s("%i", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	//���� � ����� �������
	input(arr, n);
	output(arr, n);

	//���������� � �����
	heap_sort(arr, n);
	output(arr, n);
}