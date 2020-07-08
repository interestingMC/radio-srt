#include "main.h"
#include <io.h>
#include <ctype.h>

//������
int main(int argc,const char* argv[])
{
	//�����ж�
	if (argc != 2)
		return error;

	//ɾ���ϴ��ļ�
	del("result.srt");
	del("result.mp3");
	
	//���ļ�
	FILE* fp;
	fopen_s(&fp,argv[1], "r");
	if (fp == NULL)
	{
		printf("error!!");
		return error;
	}
	//printf("%s", argv[1]);

	//���ļ����벢���ݲ���
	char str[1024];
	while (!feof(fp))
	{
		fscanf(fp, "%s", &str);
		//printf("%s\n", str);
		radio(str);
	}
	
	//�ر�ǰ����
	fclose(fp);
	del("temp.mp3");

	//��������
	return 0;
}