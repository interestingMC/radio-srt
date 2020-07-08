#include "main.h"
#include <io.h>

//下载MP3并追加在result.mp3上
int mp3(char* str)
{
	unsigned int size = (int)strlen(str);
	char* _str = (char*)malloc((unsigned int)(size + 100));
	sprintf(_str, "http://tts.baidu.com/text2audio?lan=zh&ie=UTF-8&spd=6&text=%s", str);
	//printf("%s\n", _str);
	DownloadFile(_str,"temp.mp3");

	return add("result.mp3", "temp.mp3");
}

//生成srt并追加在result.srt上
int srt(char* str)
{

	//打开文件并判断文件状态
	FILE* fp;
	int N = 0;
	if (_access("result.srt", 0))
	{
		fopen_s(&fp, "result.srt", "w+");
		N = 1;
	}
	else
		fopen_s(&fp, "result.srt", "r+");

	//从结尾向前两行
	fseek(fp, -1, SEEK_END);
	int i;
	for (i = 0; i < 3; i++)
	{
		while ((fgetc(fp)) != '\n' && !feof(fp))
		{
			fseek(fp, -2, SEEK_CUR);
		}
		fseek(fp, -3, SEEK_CUR);
	}

	//读入上一个数字
	int n=0;
	fscanf(fp, "%d", &n);
	fgetc(fp);//换行
	n++;

	//获取结果
	char* temp = (char*)malloc(512);
	char* tmp = (char*)malloc(1024);
	fscanf(fp, "%s %s %s", tmp, tmp, temp);
	MP3SIZE start;
	start.h = 0;
	start.min = 0;
	start.s = 0;
	start.ms = 0;
	if (N == 0)
		sscanf(temp, "%d%*c%d%*c%d%*c%d", &start.h, &start.min, &start.s, &start.ms);
	fseek(fp, -1, SEEK_END);

	//写入结果
	if(N==0)
		fprintf(fp,"\n");
	fprintf(fp, "%d\n", n);
	fprintf(fp, "%d:%d:%d,%d --> ", start.h, start.min, start.s, ++start.ms);
	MP3SIZE end = start;
	end = MP3SIZE_adder(end, getMp3Long("temp.mp3"));
	fprintf(fp, "%d:%d:%d,%d\n", end.h, end.min, end.s, end.ms);
	fprintf(fp, "%s\n", str);

	//结束前任务
	fclose(fp);

	//正常返回
	return 0;
}

//radio.cpp对外开放接口
int radio(char* str)
{
	return mp3(url_encode(str)) + srt(str) == 0 ? 0 : error;
}