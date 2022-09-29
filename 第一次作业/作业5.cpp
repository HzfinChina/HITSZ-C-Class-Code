#include<iostream>
using namespace std;
int* Input()
{
    int* numslist = new int[10];
    int i;
    cout << "input 10 numbers" << endl;
    for (i=0; i<10; i++)
        cin >> numslist[i];
    return numslist;
}

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Cope(int * const numslist, int len)
{
    int i, minpos = 0, maxpos = 0;
    for (i=0; i<10; i++)
    {
        maxpos = numslist[maxpos] < numslist[i] ? i : maxpos;
        minpos = numslist[minpos] > numslist[i] ? i : minpos;
    }
    Swap(numslist[0], numslist[minpos]);
    Swap(numslist[len-1], numslist[maxpos]);
}

void Print(const int * const numslist, int len)
{
    int i;
    cout << "Output:" << endl;
    for (i = 0; i < len; i++)
        cout << numslist[i] <<endl;
}

int main()
{
    int* numslist = Input();
    int len = 10;
    Cope(numslist, len);
    Print(numslist, len);
}
