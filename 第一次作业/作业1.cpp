#include <iostream>
using namespace std;


int Getdigitnum(char * const numstr) //�������ֵ�λ��,����λ��
{
    char *s = numstr;
    int len = 0;
    while (*s != '\0')
    {
        s++;
        len++;
    }
    return len;
}

void Printdigit(char const numstr[5], int len)
{
    int i;
    const char* digit[] = {"ten thousand", "thousand", "hundred", "ten", "one" };
    for (i = 0; i< len; i++)
    {
        cout << digit[i + 5 - len] <<":" << numstr[i] << endl; //�����i+5-len��Ϊ����ʾ��ȷ��λ��
    }
}

void Printreverse(char const numstr[5], int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        cout << numstr[i];
    }
    cout << "\n";
}

int main()
{
   char numstr[5];
   cin >> numstr;
   int len = Getdigitnum(numstr);
   cout << "λ���� " << len <<endl;
   Printdigit(numstr,len);
   Printreverse(numstr, len);
   return 0;
}
