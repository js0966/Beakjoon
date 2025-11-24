#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[10000000];

typedef struct {
	int height;
	int count;
} TREE;

int cmp(const void* a, const void* b) {
	TREE* tree1 = a;
	TREE* tree2 = b;
	return tree1->height - tree2->height;
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	TREE* array = (TREE*)malloc(sizeof(TREE) * N);
	
	//initailize
	for (int i = 0; i < N; i++) {
		scanf("%d", &array[i].height);
		array[i].count = 0;
	}

	//sort
	qsort(array, N, sizeof(TREE), cmp);

	//
	int uni_count = 0;

	for (int i = 0; i < N; ) {
		int h = array[i].height;
		int cnt = 0;

		while (i < N && array[i].height == h) {
			cnt++;
			i++;
		}

		array[uni_count].height = h;
		array[uni_count].count = cnt;
		uni_count++;
		//printf("array[%d].height : %5d		count : %5d\n", uni_count - 1, array[uni_count - 1].height, array[uni_count - 1].count);
	}

	int left = 0;
	int right = array[uni_count - 1].height;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;

		for (int j = 0; j < uni_count; j++) {
			if (array[j].height > mid) {
				sum += (array[j].height - mid) * 1ll * array[j].count;
			}
		}

		if (sum >= M) {
			answer = mid;
			left = mid + 1;   // 더 높은 절단 높이도 가능한지 확인
		}
		else {
			right = mid - 1;
		}
	}
	
	printf("%d", answer);

	free(array);
	return 0;
}