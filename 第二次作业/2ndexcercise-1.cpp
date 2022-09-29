#include <iostream>
using namespace std;

void set_time(void);
void show_time(void);

class Time
{
public:
    int hour;
    int minute;
    int sec;
};
Time t;
int main()
{
    set_time();
    show_time();
}
void set_time(void)
{
    cin>>t.hour;
    cin>>t.minute;
    cin>>t.sec;
}
void show_time(void)
{
    cout<<t.hour<<":" <<t. minute<<":" <<t.sec<<endl;
}

