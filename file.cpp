#include "main.h"
#include <io.h>

//��file2������׷�ӵ�file1ĩβ
int add(const char* file1, const char* file2)
{
	//�򿪵�һ���ļ�
	FILE* fp2;
	fopen_s(&fp2, file2, "rb");
	if (fp2 == NULL)
	{
		return error;
	}

	//�򿪵ڶ����ļ�
	FILE* fp1;
	fopen_s(&fp1, file1, "ab");
	if (fp1 == NULL)
	{
		return error;
	}

	//׷���ļ�
	while(!feof(fp2))
	{
		fputc((char)fgetc(fp2), fp1);
	}

	//����ǰ����
	fclose(fp1);
	fclose(fp2);

	//��������
	return 0;
}

//��ȡMP3�ļ���ʱ��
MP3SIZE getMp3Long(const char* filename)
{
	//���ļ����ƶ��ļ�ָ��
	FILE* fp;
	fopen_s(&fp, filename, "r");
	fseek(fp, 0L, SEEK_END);

	//��ȡ�ļ���С
	int filesize;
	filesize = ftell(fp);
	fclose(fp);

	//����MP3��Ƶ����
	double size;
	size = filesize / 1024.0 * 8.0 / 8.0;

	//����ֵ����
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
	//�򵥵����
	a.h += b.h;
	a.min += b.min;
	a.s += b.s;
	a.ms += b.ms;
	return a;
}

void del(const char* filename)
{
	//���ж���ɾ������δ֪�Ĵ���
	if (!_access(filename, 0))
		remove(filename);
	return;
}