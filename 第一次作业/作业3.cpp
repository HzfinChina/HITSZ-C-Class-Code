#include<iostream>
using namespace std;

int gcd(int num1, int num2){
    if (num1 < num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 == 0)
        return num1;
    else
        return gcd(num2, num1%num2);
}
int lcm(int num1, int num2)
{
    return num1*num2/gcd(num1, num2);
}

int main()
{
    int nums[2];
    cout << "input two numbers" << endl;
    cin >> nums[0];
    cin >> nums[1];
    cout << "greatest common divisor:" << gcd(nums[0], nums[1]) << endl;
    cout << "lowest common multiple:" << lcm(nums[0], nums[1]) << endl;
}

