#include "main.h"
#include <WinInet.h>

//���ӿ�
#pragma comment (lib,"Urlmon.lib")
#pragma comment (lib,"Wininet.lib")

int DownloadFile(const char* url, const char* outfilename)
{
    LPCWSTR _url = char2wchar(url);
    LPWSTR _outfilename = char2wchar(outfilename);
    DeleteUrlCacheEntry(_url);//��ջ��棬����������ϵ��ļ��޸ĺ��޷��������µ��ļ�
    //URLDownloadToCacheFile(NULL, _url, _outfilename, strlen(outfilename), 0, NULL);
    URLDownloadToFile(NULL, _url, _outfilename, 0, NULL);
    CoUninitialize();
	return 0;
}