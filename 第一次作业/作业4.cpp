#include<stdlib.h>
#include<iostream>
using namespace std;

int FindPos(const int *nums, int len, int insertnum)
{
    int pos;
    if (nums[len-1] >= nums[0])
        for (pos=0; nums[pos] < insertnum; pos++);
    else
        for (pos=0; nums[pos] > insertnum; pos++);
    return pos;
}

int *NewList (const int *nums, int len, int insertnum)
{
    int* retlist = (int*)malloc((len+1) * sizeof(int));
    int pos = FindPos(nums, len, insertnum);
    int i;
    for (i = 0; i < pos; i ++)
        retlist[i] = nums[i];
    retlist[i] = insertnum; //现在i = pos(要插入的位置)
    for (i=i+1; i < len + 1; i++)
        retlist[i] = nums[i-1];
    return retlist;
}

int main()
{
    int nums[] = {20,16,14,10,8,7,6,5,4,3,2,1};
    int len = sizeof(nums)/sizeof(nums[0]);
    int insertnum;
    cout << "input number to insert"<< endl;
    cin >> insertnum;
    int i;
    int *newlist = NewList(nums, len,insertnum);
    for (i=0; i< len+1; i++)
        cout<<newlist[i]<<endl;
}
