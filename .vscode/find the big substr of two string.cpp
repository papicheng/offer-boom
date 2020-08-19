#include <iostream>
#include <string.h>
using namespace std;

char* getLCS(char* str1, char* str2)
{
	char *longerStr, *shorterStr;
	if (NULL==str1 || NULL == str2){
		return NULL;
	} 

	if (strlen(str1) <= strlen(str2)){
		shorterStr =str1;
		longerStr = str2;
	} else {
		shorterStr =str2;
		longerStr = str1;
	}

	int iShorterLen = strlen(shorterStr);
	char* subStr= new char[iShorterLen+1];
	memset(subStr, '\0', sizeof(subStr));
	if (strstr(longerStr, shorterStr) != NULL) {
		memcpy(subStr, &shorterStr[0], iShorterLen);
		return subStr;
	}

	for (int i = iShorterLen; i >= 1; i --) { ///////////////1
      for (int j = 0; j < strlen(shorterStr); j++) {//////////////2
			memcpy(subStr, &shorterStr[j], i);
			subStr[i]='\0';
			if (strstr(longerStr, subStr) != NULL) {
				return subStr;
			}
		}
	}

	delete[] subStr;
	return NULL;
}

int delChars(char* sSrc, int pos, int num)
{
	if (NULL==sSrc) {
		return -1;
	}

	int iStrLen = strlen(sSrc);
	if (iStrLen == 0) {/////////////////////3
		cout<<"Invalid param!";
		return -1;
	}

	int iBegin =pos;
	int iEnd   =pos+num;
	while( iEnd<=iStrLen) {////////////4
		sSrc[iBegin]=sSrc[iEnd];
		iBegin++;
		iEnd++;
	}

	sSrc[iStrLen-num]='\0';
	return 0;
}

int main()
{
	char str1[] = "abcdexyz";
	char str2[] = "wocdew";
	char* lcs=getLCS(str1, str2);
	if (NULL==lcs) {
		return -1;
	}
	else {
		cout<<"LCS:"<<lcs<<endl;
	}

	string sTmpStr1(str1), sTmpStr2(str2);
	int iIndex1 = sTmpStr1.find(lcs);
	int iIndex2 = sTmpStr2.find(lcs);
	delChars(str1, iIndex1, strlen(lcs));
	delChars(str2, iIndex2, strlen(lcs));
	delete[] lcs;/////////////5
	cout<<"str1:"<<str1<<endl;
	cout<<"str2:"<<str2<<endl;
	return 0;
}
 