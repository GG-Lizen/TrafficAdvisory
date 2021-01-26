#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define MAX_INT 0x7fffffff
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
#define MAX_LENGTH_STRING 20

//自定义类型
typedef int Status;
typedef char VexType;
typedef struct Time {//24小时制
	int day;
	int hour;
	int minute;
};

