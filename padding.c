#include<stdio.h>
#include<time.h>

#define MAX_ALLIGN 100000 

struct noallign {
	int i;
	char b;
	int j;
	char c;
	int k;
	char e;
};

struct yesallign {
	int i;
	int j;
	int k;
	char b;
	char c;
	char e;
};



int main(void)
{
	clock_t t;
	int i;
	struct noallign noa[MAX_ALLIGN];
	struct yesallign yesa[MAX_ALLIGN];

	t = clock();
	for(i = 0; i < MAX_ALLIGN; i++) {
		noa[i].i = 10;
		noa[i].j = 20;
		noa[i].k = 30;
		noa[i].b = 'b';
		noa[i].c = 'c';
		noa[i].e = 'e';
	}
	t = clock() - t;
	printf("Time without Padding: %f seconds\n",t/((float)(CLOCKS_PER_SEC)));


	t = clock();
	for(i = 0; i < MAX_ALLIGN; i++) {
		yesa[i].i = 10;
		yesa[i].j = 20;
		yesa[i].k = 30;
		yesa[i].b = 'b';
		yesa[i].c = 'c';
		yesa[i].e = 'e';

	}
	t = clock() - t;
	printf("Time with Padding : %f seconds\n",t/((float)(CLOCKS_PER_SEC)));
}
