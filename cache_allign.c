#include<stdio.h>
#include<time.h>

#define ALLIGN_CONST 1000000

struct t_struct_inner {
	int a;
};

struct t_struct_outer {
	struct t_struct_inner	b[ALLIGN_CONST];
	struct t_struct_inner *next;
}out;

struct t_struct_outer1 {
	struct t_struct_inner	b[ALLIGN_CONST];
	struct t_struct_inner *next;
}out1 __attribute__((aligned(64)));


int main(void)
{
	clock_t t;
	int i;

	t = clock();
	for(i = 0; i < 1000; i++) {
		out.b[i].a ++;
	}
	t = clock() - t;
	printf("Time taken without cache allign: %f seconds\n",t/((float)(CLOCKS_PER_SEC)));

	t = clock();
	for(i = 0; i < 1000; i++) {
		out1.b[i].a ++;
	}
	t = clock() - t;
	printf("Time taken with Cache Allign : %f seconds\n",t/((float)(CLOCKS_PER_SEC)));
}
