#include <iostream>
using namespace std;
class Time
{
    private:
        int hour, minute, sec;
    public:
        void set_time(void);
        void show_time(void);
};

void Time::set_time(void)
{
    cin>>hour;
    cin>>minute;
    cin>>sec;
}
void Time::show_time(void)
{
    cout<<hour<<":" <<minute<<":" <<sec<<endl;
}


Time t;

int main()
{
    t.set_time();
    t.show_time();
}

