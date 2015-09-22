#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <skeleton.h>

#define MY_BS 1024

int main()
{
	SkeletonHandleType* skltHnd;
	char* dstStr = (char*)malloc(sizeof(char) * MY_BS);
	memset(dstStr, 0, MY_BS);

	printf("Hello, world!\n");
	
	SKLTInit(&skltHnd);

	SKLTGetInternals(skltHnd, dstStr, MY_BS);
	printf("Get str: %s\n", dstStr);

	SKLTDeInit(skltHnd);

	free(dstStr);

	return 0;
}
