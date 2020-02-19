#include "ZipTool.h"
#include<cstring>
#define MAX_BUFFER 1024*1024*10
unsigned char*  ZipTool::zip(const unsigned char* src, unsigned long srcLen, unsigned long* destLen)
{
	unsigned char* tmp = new unsigned char[srcLen];//ѹ����Ĵ���ռ䣬��ʱ����Ϊ��srcͬ�ȴ�С
	*destLen = srcLen;//��ʼ��ѹ����ĳ��Ⱥ�ԭʼ������ͬ
	compress(tmp, destLen, src, srcLen);
	unsigned char* dest = new unsigned char[*destLen];//���ڴ���ѹ���������
	memcpy(dest, tmp, *destLen);
	delete []tmp;
	cout << "ѹ���ɹ� " << "ѹ����Ϊ" << (*destLen /((1.0)* srcLen))<<endl;
	return dest;
}

unsigned char* ZipTool::zip(const unsigned char* src, unsigned long srcLen, unsigned long* destLen,int level)
{
	unsigned char* tmp = new unsigned char[srcLen];
	*destLen = srcLen;
	compress2(tmp, destLen, src, srcLen,level);
	unsigned char* dest = new unsigned char[*destLen];
	memcpy(dest, tmp, *destLen);
	delete[]tmp;
	cout << "ѹ���ɹ� " << "ѹ����Ϊ" << (*destLen / ((1.0) * srcLen)) <<endl;
	return dest;
}

unsigned char* ZipTool::unzip(unsigned char* src, unsigned long srcLen, unsigned long* destLen)
{
	unsigned char* tmp = new unsigned char[MAX_BUFFER];//�ݴ��ѹ�������
	uncompress(tmp, destLen, src, srcLen);
	//cout << *destLen << "--��ѹ��" << endl;
	unsigned char* dest = new unsigned char[*destLen];
	memcpy(dest, tmp, *destLen);
	delete[]tmp;
	cout << "��ѹ�ɹ� " << "��ѹ�󳤶�Ϊ" << *destLen << endl;
	return dest;
}


