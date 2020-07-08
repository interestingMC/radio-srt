#include "main.h"
#include <io.h>

//将file2的内容追加到file1末尾
int add(const char* file1, const char* file2)
{
	//打开第一个文件
	FILE* fp2;
	fopen_s(&fp2, file2, "rb");
	if (fp2 == NULL)
	{
		return error;
	}

	//打开第二个文件
	FILE* fp1;
	fopen_s(&fp1, file1, "ab");
	if (fp1 == NULL)
	{
		return error;
	}

	//追加文件
	while(!feof(fp2))
	{
		fputc((char)fgetc(fp2), fp1);
	}

	//结束前任务
	fclose(fp1);
	fclose(fp2);

	//正常返回
	return 0;
}

//获取MP3文件的时长
MP3SIZE getMp3Long(const char* filename)
{
	//打开文件并移动文件指针
	FILE* fp;
	fopen_s(&fp, filename, "r");
	fseek(fp, 0L, SEEK_END);

	//获取文件大小
	int filesize;
	filesize = ftell(fp);
	fclose(fp);

	//计算MP3音频长度
	double size;
	size = filesize / 1024.0 * 8.0 / 8.0;

	//返回值处理
	MP3SIZE ret;
	ret.h = 0;
	ret.min = 0;
	ret.s = 0;
	ret.ms = 0;
	if (size > 3600)
	{
		ret.h = (unsigned int)(size / 3600.0);
		size -= 3600 * (__int64)ret.h;
	}
	if (size > 60)
	{
		ret.min = (unsigned int)(size / 60.0);
		size -= 60 * (__int64)ret.min;
	}
	if (size > 0)
	{
		ret.s = (unsigned int)size;
		size -= 1 * ret.s;
	}
	size = size * 1000.0;
	ret.ms = (unsigned int)size;
	return ret;
}

MP3SIZE MP3SIZE_adder(MP3SIZE a, MP3SIZE b)
{
	//简单的相加
	a.h += b.h;
	a.min += b.min;
	a.s += b.s;
	a.ms += b.ms;
	return a;
}

void del(const char* filename)
{
	//先判断再删除避免未知的错误
	if (!_access(filename, 0))
		remove(filename);
	return;
}