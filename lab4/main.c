#include<stdio.h>

void exchange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void get_num(int p, int n[], int nfind) {
	int i = 0;
	while (n[i] != nfind) {
		i++;
	}
	p = n[i];
	
	printf("&n[%i]->%p, n[%i]=%d; p->%p, *p=%d\n", i, &n[i], i, n[i], &p, p);
}

void array_find(int ap, int n[], int nsize) {
	int i, j, a[nsize];
	
	for (i = 0; i < nsize; i++) {
		a[i] = n[i];
	}
	
	for (i = 0; i < nsize - 1; i++) {
		for (j = 0; j < nsize - i - 1; j++) {
			if (n[j] > n[j + 1]) exchange (&n[j], &n[j + 1]);
		}
	}
	
	for (i = 0; i < nsize; i++) {
		get_num(ap, a, n[i]);
		ap++;
	}
}

int main() {
	int n[] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
	int* p;
	int* ap[10];
	
	printf("No.1-----------\n");
	get_num(p, n, 9);
	printf("No.2-----------\n");
	array_find(ap, n, 10);
	
	return 0;
}
