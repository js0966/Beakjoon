#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	int index;
} LIST;

int cmp(const void* a, const void* b) {
	LIST* cmp1 = (LIST*)a;
	LIST* cmp2 = (LIST*)b;

	return cmp1->data - cmp2->data;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	LIST* array = (LIST*)malloc(sizeof(LIST) * N);
	int* counting_array = (int*)malloc(sizeof(int) * N);
	int* printing_array = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &array[i].data);
		array[i].index = i;
		counting_array[i] = 0;
		printing_array[i] = 0;
	}
	qsort(array, N, sizeof(LIST), cmp);

	for (int i = 1; i < N; i++) {
		if (array[i].data > array[i - 1].data) {
			counting_array[i] = counting_array[i - 1] + 1;
		}
		else if (array[i].data == array[i - 1].data) {
			counting_array[i] = counting_array[i - 1];
		}
	}

	for (int i = 0; i < N; i++) {
		printing_array[array[i].index] = counting_array[i];
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", printing_array[i]);
	}

	free(array);
	free(counting_array);
	free(printing_array);
	return 0;
}