#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int src[] = {1,-1,-1,-1,-1,-1};
	int dst[6];

	memcpy(dst, src, 6*sizeof(int));

	for (i = 0; i < 6; ++i){printf("%d ", dst[i]);} printf("\n");
	return 0;
}