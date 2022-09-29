#include <iostream>
using namespace std;

class Cuboid{
    private:
        double length ,width, height;
    public:
        void Init(void)
        {
            cout << "Initiate cuboid" << endl;
            cout << "input length";
            cin >> length;
            cout << "input width";
            cin >> width;
            cout << "input height";
            cin >> height;
        }
        double GetVolume(void)
        {
            return length * width * height;
        }
};

int main()
{
    Cuboid cub1, cub2, cub3;
    cub1.Init();
    cout << "The cuboid's volume is:" << cub1.GetVolume() << endl;
    cub2.Init();                                          
    cout << "The cuboid's volume is:" << cub2.GetVolume() << endl;
    cub3.Init();                                         
    cout << "The cuboid's volume is:" << cub3.GetVolume() << endl;
}
