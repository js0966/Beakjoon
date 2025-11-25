#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define MAX_LEN 20

typedef struct NODE {
	char key[MAX_LEN];
	int value;
	struct NODE* next;
} NODE;

NODE *hash_table[TABLE_SIZE];

unsigned long long hash_string(const char* s) {
	unsigned long long h = 0;
	const unsigned long long P = 131;

	while (*s) {
		h = h * P + (*s++);
	}
	return h;
}

unsigned int get_index(const char* s) { // insert함수에 있는 index는 문자열을 넣을 때 알 수 있음.
	return hash_string(s) % TABLE_SIZE;
}

void insert_hash(const char* key, int value) {
	unsigned int index = get_index(key);

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	strcpy(newNode->key, key);
	newNode->value = value;
	newNode->next = hash_table[index];
	hash_table[index] = newNode;
}

int find(const char* key, int *out_value) {
	unsigned int index = get_index(key);
	NODE* cur = hash_table[index];
	
	while (cur) {
		if (strcmp(cur->key, key) == 0) {
			*out_value = cur->value;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	
	char** string = (char**)malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++) {
		string[i] = (char*)malloc(sizeof(char) * MAX_LEN);
		scanf("%s", string[i]);
		insert_hash(string[i], i);
	}
	char tmp[20];
	int value = 0;
	for (int i = 0; i < M; i++) {
		scanf("%s", tmp);
		int code = (int)tmp[0];
		if (code > 64) {
			find(tmp, &value);
			printf("%d\n", value + 1);
			value = 0;
		}
		else {
			printf("%s\n", string[atoi(tmp) - 1]);
		}
	}

	for (int i = 0; i < N; i++) {
		free(string[i]);
	}
	free(string);
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i]) {
			free(hash_table[i]);
		}
	}
	return 0;
}