#include "main.h"
#include <io.h>
#include <ctype.h>

//主函数
int main(int argc,const char* argv[])
{
	//参数判断
	if (argc != 2)
		return error;

	//删除上次文件
	del("result.srt");
	del("result.mp3");
	
	//打开文件
	FILE* fp;
	fopen_s(&fp,argv[1], "r");
	if (fp == NULL)
	{
		printf("error!!");
		return error;
	}
	//printf("%s", argv[1]);

	//将文件读入并传递参数
	char str[1024];
	while (!feof(fp))
	{
		fscanf(fp, "%s", &str);
		//printf("%s\n", str);
		radio(str);
	}
	
	//关闭前任务
	fclose(fp);
	del("temp.mp3");

	//正常返回
	return 0;
}