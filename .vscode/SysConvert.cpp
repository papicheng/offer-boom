// ½øÖÆ×ª»»

#include<iostream>
#include<string>
using namespace std;
 
string* fun(const string number, int n, int m)
{
        //   string s("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
          string s("0123456789abcdefghijklmnopqrstuvwxyz");
          unsigned int i = 0;
          int num = 0;
          while (i < number.size())
          {
                   num = num * n + number[i] - '0';
                   i++;
          }
 
          i = 0;
          string* ret = new string;
          while (num > 0)
          {
                   ret->push_back(s[num%m]);
                   num /= m;
          }
 
          int begin = 0;
          int end = ret->size() -1;
          while (begin < end)
          {
                   char tmp = (*ret)[begin];
                   (*ret)[begin] = (*ret)[end];
                   (*ret)[end] = tmp;
                   begin++;
                   end--;
          }
 
          return ret;
}
 
int main()
{
          string s("1111");
          string *ret = fun(s, 2, 10);
          cout << *ret << endl;
          delete ret;
          ret = NULL;
          return 0;
}