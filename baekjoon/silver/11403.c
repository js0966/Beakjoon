#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int adj_array[100][100];

void dps(int visited[], int **array, int target, int y, int N) {
	if (visited[y]) return;

	array[target][y] = 1;
	visited[y] = 1;

	for (int i = 0; i < N; i++) {
		if (adj_array[y][i] == 1 && visited[i] == 0) {
			dps(visited, array, target, i, N);
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	int** array = (int**)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++) {
		array[i] = (int*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj_array[i][j]);
			array[i][j] = 0;
		}
	}
	


	for (int i = 0; i < N; i++) {
		int visited[100] = { 0 };
		for (int j = 0; j < N; j++) {
			if (visited[j] == 0 && adj_array[i][j] == 1) {
				dps(visited, array, i, j, N);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		free(array[i]);
	}
	free(array);
	return 0;
}