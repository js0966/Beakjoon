#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculating() {
	int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
	scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

	if (x1 == x2 && y1 == y2) {
		if (r1 == r2) {
			return -1;// ¹«ÇÑ´ë
		}
		else if (r1 != r2) {
			return 0;
		}
	}

	double d = 0; // (x1, y1) with (x2, y2)
	int temporary = 0;
	temporary = pow((x2 - x1), 2) + pow((y2 - y1), 2);
	d = sqrt(temporary);

	if (d == r1 + r2) {
		temporary = 1;
	}
	else if (d < r1 + r2) {
		if (d == fabs(r1 - r2)) return 1;
		else if (d > fabs(r1 - r2)) return 2;
		else return 0;
	}
	else if (d > r1 + r2) {
		temporary = 0;
	}

	return temporary;
}

int main(void)
{
	int number = 0;

	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		printf("%d\n", calculating());
	}

	return 0;
}
