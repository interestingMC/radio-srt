#pragma once

//公用头文件
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//宏设定
#define error -1

//结构体
typedef struct _mp3size
{
	unsigned int h;
	unsigned int min;
	unsigned int s;
	unsigned int ms;
}MP3SIZE;

//file.cpp
int add(const char* file1, const char* file2);
MP3SIZE getMp3Long(const char* filename);
MP3SIZE MP3SIZE_adder(MP3SIZE a, MP3SIZE b);
void del(const char* filename);

//download.cpp
int DownloadFile(const char* url, const char* outfilename);

//radio.cpp
int radio(char* str);

//str.cpp
char* str_replace(char* src, const char* oldstr, const char* newstr);
int _isalnum(int c);
char* url_encode(char* _str);
wchar_t* char2wchar(const char* cchar);
char* wchar2char(const wchar_t* wchar);