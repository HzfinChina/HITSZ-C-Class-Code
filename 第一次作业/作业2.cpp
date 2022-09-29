#include <iostream>
using namespace std;
void Quicksort(int nums[], int left, int right) //快速排序
{
    if (left >= right)return ;
    int start = left, end = right;
    int pivot = nums[left], pivotpos = left;
    while (left < right)
    {
        if (nums[right] > pivot)
        {
            right --;
        }
        else
        {
            nums[left] = nums[right];
            pivotpos = right;
            left++;
            while (nums[left] < pivot && left < right)
            {
                left++;
            }
            if (left < right)
            {
                nums[right] = nums[left];
                pivotpos = left;
                right--;
            }
        }
    }
    nums[pivotpos] = pivot;
    Quicksort(nums, start, left-1); //递归调用
    Quicksort(nums, left+1, end);
}
int main()
{
    int i, nums[4];
    cout << "input 4 numbers" << endl;
    for (i = 0; i < 4; i++)
    {
        cin >> nums[i];
    }
    Quicksort(nums, 0, 3);
    for (i = 0;i<4; i++)
    {
        cout << nums[i] << " " ;
    }
    cout << "\n";
}
