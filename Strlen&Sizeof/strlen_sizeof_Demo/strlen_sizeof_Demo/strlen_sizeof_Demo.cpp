// strlen_sizeof_Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int _tmain(int argc, _TCHAR* argv[])
{	
	char str[20] = "hello world";
	char *s = (char *)malloc(20);
	strcpy(s, str);
	printf("strlen(str)=%d\n", strlen(str));
	printf("sizeof(str)=%d\n", sizeof(str));
	printf("strlen(s)=%d\n", strlen(s));
	printf("sizeof(s)=%d\n", sizeof(s));
	free(s);

	printf("strlen(strTemp)=%d\n", strlen("abcdef"));
	printf("sizeof(strTemp)=%d\n", sizeof("abcdef"));

	getchar();
	return 0;
}
