#include "main.h"
#include <WinInet.h>

//链接库
#pragma comment (lib,"Urlmon.lib")
#pragma comment (lib,"Wininet.lib")

int DownloadFile(const char* url, const char* outfilename)
{
    LPCWSTR _url = char2wchar(url);
    LPWSTR _outfilename = char2wchar(outfilename);
    DeleteUrlCacheEntry(_url);//清空缓存，否则服务器上的文件修改后，无法下载最新的文件
    //URLDownloadToCacheFile(NULL, _url, _outfilename, strlen(outfilename), 0, NULL);
    URLDownloadToFile(NULL, _url, _outfilename, 0, NULL);
    CoUninitialize();
	return 0;
}