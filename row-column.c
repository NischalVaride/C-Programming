#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int row = 0;
int column = 0;


size_t cache_line_size() {
	FILE * p = 0;
	p = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r");
	unsigned int i = 0;

	if (p) {
		fscanf(p, "%d", &i);
		fclose(p);
	}
	return i;
}

void column_wise(void)
{
	int i = 0, j = 0;
	char a[row][column];
	for(i = 0; i < row;i++)
	{
		for(j = 0; j < column; j++)
		{
			a[j][i]++ ;

		}
	}

}

void row_wise(void)
{
	int i = 0, j = 0;
	int a[row][column];
	for(i = 0; i < row;i++) 
	{
		for(j = 0; j < column; j++)
		{
			a[i][j]++;

		}
	}
}

int main(int argc, char *argv[])
{
	int i, j;
	clock_t t;

	if(argv[1] == NULL) {
		printf("Enter Integer as First Argument to Function\n");
		exit(1);
	}

	if(argv[2] == NULL) {
		printf("Enter function name as second parameter 1. row or 2. column \n");

	}

	row = cache_line_size();
	column = atoi(argv[1]);

	if(!strncmp(argv[2], "row", strlen("row"))) {

		t = clock();
		row_wise();
		t = clock() - t;
		printf("Row  Wise Time is : %f seconds\n", t/((float)(CLOCKS_PER_SEC)));
	}


	if(!strncmp(argv[2], "column", strlen("row"))) {
		t = clock();
		column_wise();
		t = clock() - t;
		printf("Column  Wise Time is : %f seconds\n",t/((float)(CLOCKS_PER_SEC)));
	}

	return 0;

}



