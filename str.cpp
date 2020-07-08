#include "main.h"

//��src�����е�oldstr�滻Ϊnewstr��oldstr�ĳ���Ҫ���ڵ���newstr��
char *str_replace(char* src,const char* oldstr,const char* newstr)
{
	char* _src = (char*)malloc(strlen(src));
	memset(_src, 0, sizeof(_src));
	unsigned int i = 0;
	for (i = 0; i < (strlen(src)); i++)
	{
		if (!strncmp(src + i, oldstr, strlen(oldstr)))
		{
			strcat(_src, newstr);
			i += ((int)strlen(oldstr) - 1);
		}
		else
		{
			strncat(_src, src + i, 1);
		}
	}
	strcpy(src, _src);
	return src;
}
/* ���ԣ�https://blog.csdn.net/baidu_36649389/article/details/87980451
 * ����΢����
 */

//�ж��ַ��Ƿ��д�Сд��ĸ����
int _isalnum(int c)
{
	/*
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= ' Z') || (c >= '0' && c <= '9'))
	{
		return true;
	}
	return false;*/
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= ' Z') || (c >= '0' && c <= '9')?true:false;
}

//���ַ�������URL����
char* url_encode(char* _str)
{
	char *str = (char*)malloc(strlen(_str) + 1);
	strcpy(str, _str);
	unsigned int size = (int)strlen(str);
	__int64 i;
	char* temp = (char*)malloc(10);
	char* hex = (char*)malloc(4);
	char* urlencode_str = (char*)malloc(size * 3 + 1);
	urlencode_str[0] = '\0';
	for (i = 0; i < size; i++)
	{
		//printf("%d  ", str[i]);
		if (!_isalnum((int)str[i]))
		{
			sprintf(temp, "%x", str[i]);
			hex[0] = temp[6];
			hex[1] = temp[7];
			hex[2] = temp[8];
			//hex = (int*)temp & 0xff;
			sprintf(urlencode_str, "%s%%%s", urlencode_str, hex);
			//printf("%%%s", hex);
		}
		else
			sprintf(urlencode_str, "%s%c", urlencode_str, str[i]);
	}
	//strcpy(str, urlencode_str);
	//return str;
	return urlencode_str;
}

//char�ַ���ת��Ϊwchar_t�ַ���
wchar_t* char2wchar(const char* cchar)
{
	wchar_t* m_wchar;
	//int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	unsigned int len = strlen(cchar);
	m_wchar = new wchar_t[len + (unsigned int)1];
	//m_wchar = (wchar_t*)malloc(len + 1);
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}

//wchar_t�ַ���ת��Ϊchar�ַ���
char* wchar2char(const wchar_t* wchar)
{
	char* m_char;
	int len = WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), NULL, 0, NULL, NULL);
	m_char = new char[len + (unsigned int)1];
	WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	return m_char;
}
/* ���ԣ�https://blog.csdn.net/bailang_zhizun/java/article/details/80348282
 * ����ɾ��
 */
