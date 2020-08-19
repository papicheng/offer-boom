//�����ַ���ת�ɰ���������

#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int chineseNum2num(wstring s)
{
    map<wchar_t, int> chineseNum;
    chineseNum.insert(pair<wchar_t, int>(L'��', 0));
    chineseNum.insert(pair<wchar_t, int>(L'һ', 1));
    chineseNum.insert(pair<wchar_t, int>(L'��', 2));
    chineseNum.insert(pair<wchar_t, int>(L'��', 3));
    chineseNum.insert(pair<wchar_t, int>(L'��', 4));
    chineseNum.insert(pair<wchar_t, int>(L'��', 5));
    chineseNum.insert(pair<wchar_t, int>(L'��', 6));
    chineseNum.insert(pair<wchar_t, int>(L'��', 7));
    chineseNum.insert(pair<wchar_t, int>(L'��', 8));
    chineseNum.insert(pair<wchar_t, int>(L'��', 9));
    chineseNum.insert(pair<wchar_t, int>(L'ʮ', 10));
    chineseNum.insert(pair<wchar_t, int>(L'��', 100));
    chineseNum.insert(pair<wchar_t, int>(L'ǧ', 1000));
    chineseNum.insert(pair<wchar_t, int>(L'��', 10000));
    chineseNum.insert(pair<wchar_t, int>(L'��', 100000000));
    chineseNum.insert(pair<wchar_t, int>(L'Ҽ', 1));
    chineseNum.insert(pair<wchar_t, int>(L'��', 2));
    chineseNum.insert(pair<wchar_t, int>(L'��', 3));
    chineseNum.insert(pair<wchar_t, int>(L'��', 4));
    chineseNum.insert(pair<wchar_t, int>(L'��', 5));
    chineseNum.insert(pair<wchar_t, int>(L'½', 6));
    chineseNum.insert(pair<wchar_t, int>(L'��', 7));
    chineseNum.insert(pair<wchar_t, int>(L'��', 8));
    chineseNum.insert(pair<wchar_t, int>(L'��', 9));
    chineseNum.insert(pair<wchar_t, int>(L'ʰ', 10));
    chineseNum.insert(pair<wchar_t, int>(L'��', 100));
    chineseNum.insert(pair<wchar_t, int>(L'Ǫ', 1000));
    chineseNum.insert(pair<wchar_t, int>(L'�f', 10000));
    chineseNum.insert(pair<wchar_t, int>(L'�|', 100000000));

    int result=0, tmp = 0, hnd_mln=0;
    wchar_t curr_char;
    int curr_digit;
    for (int i = 0; i < s.length(); ++i)
    {
        curr_char = s.at(i);
        if (chineseNum.find(curr_char) == chineseNum.end())
            return NULL;
        curr_digit = chineseNum.at(curr_char);
        if (curr_digit == pow(10, 8))//meet ���ڡ� or ���|��
        {
            result = result + tmp;
            result = result * curr_digit;
            hnd_mln = hnd_mln * pow(10, 8) + result;
            result = 0;
            tmp = 0;
        }
        else
        {
            if (curr_digit == pow(10, 4))
            {
                result = result + tmp;
                result = result * curr_digit;
                tmp = 0;
            }
            else
            {
                if (curr_digit >= 10)
                {
                    if (tmp == 0)
                        tmp = 1;
                    result = result + curr_digit * tmp;
                    tmp = 0;
                }
                else
                {
                    tmp = tmp * 10 + curr_digit;
                }
            }
        }
    }
    result = result + tmp;
    result = result + hnd_mln;
    return result;
}

int main(){
    wcout.imbue(locale("chs"));
    wstring str = L"һ�ٶ�ʮ������ǧ�����ʮ��";
    wcout<<chineseNum2num(str)<<endl;
}


//���������һ���ַ��������
/*
template <class T>
int getArrayLen(T& array)
{//ʹ��ģ�嶨��һ ������getArrayLen,�ú�������������array�ĳ���
    return (sizeof(array) / sizeof(array[0]));
}
int main()
{
    wcout.imbue(locale("chs"));
    wstring testdict[] = {L"һ�ٶ�ʮ������ǧ�����ʮ��" };
    for (int i = 0; i < getArrayLen(testdict); ++i)
    {
        wcout << testdict[i] << '\t' << chineseNum2num(testdict[i]) << endl;
    }
    return 0;
}
*/