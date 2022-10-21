#include <math.h>
#include <iostream>
class Shape
{
    public:
        /*在基类中定义虚函数，然后在派生类中重写，就可以用基类指针调用派生类函数了 */
        virtual float area(){             return 0.0;
        }
};

class Point: public Shape
{
    protected:
        float x,y;
    public:
        Point(float = 0, float = 0);
        float Getx(){
            return x;
        }
        float Gety(){
            return y;
        }
        Point operator+(const Point &b) //重载+-符号使得可以实现两个坐标相加减的到向量
        {
            Point retpoint;
            retpoint.x = x + b.x;
            retpoint.y = y + b.y;
            return retpoint;
        }
        Point operator-(const Point &b)
        {
            Point retpoint;
            retpoint.x = x - b.x;
            retpoint.y = y - b.y;
            return retpoint;
        }
};

Point::Point(float x, float y)
{
    this -> x = x;
    this -> y = y;
}

class Circle :public Shape
{
    public:
        virtual float area(){
            return (3.14159 * radius * radius);
        }
        Circle(float r, Point p):radius(r), point(p){ };
    private:
        float radius;
        Point point;
};

class Rectangle :public Shape
{
    public:
        virtual float area(){
            return (length * height);
        }
        Rectangle(Point p1, Point p2, Point p3, Point p4):A(p1), B(p2), C(p3), D(p4){
            if ((B-A).Getx() != (C-D).Getx() || (B-A).Gety() != (B-A).Gety()) //判断所给的点是否能构成矩形
            {
                std::cout << "坐标不能构成矩形!" << std::endl;
                std::cout << "异常，程序退出" << std::endl;
                exit(-1);
            }
            length = (B-A).Getx(); //记录矩形的长和宽方便计算面积
            height = (D-A).Gety();
        }
    private:
        float length, height;
        Point A, B, C, D;

};

class Triangle :public Shape
{
    public:
        virtual float area();
        Triangle(Point p1, Point p2, Point p3):A(p1), B(p2), C(p3)
        {
            lena = sqrt(pow((B-C).Getx(),2) + pow((B-C).Gety(),2));
            lenb = sqrt(pow((A-C).Getx(),2) + pow((A-C).Gety(),2));
            lenc = sqrt(pow((B-A).Getx(),2) + pow((B-A).Gety(),2));
            if (lena + lenb <= lenc || lena + lenc <= lenb || lenb + lenc <= lena)
            {
                std::cout << "坐标不能构成三角形!" << std::endl;
                std::cout << "异常，程序退出" << std::endl;
                exit(-1);
            }
        }
    private:
        Point A, B, C;
        float lena, lenb, lenc; //三条边的长度
};

float Triangle::area()//利用海伦公式求三角形面积
{
    float s = (lena + lenb + lenc)/2;
    return sqrt(s * (s - lena) * (s - lenb) * (s - lenc));
}

int main()
{
    Circle cir(3,Point(4,5));
    Rectangle rec(Point(3,4),Point(5,4), Point(5,8), Point(3,8));
    Triangle tri(Point(0,0), Point(4,0), Point(4,3));
    Shape** shapelist = new Shape* [3];
    shapelist[0] = &cir;
    shapelist[1] = &tri;
    shapelist[2] = &rec;
    int i;
    float sumArea = 0;
    for ( i = 0; i < 3; i++)
        sumArea += shapelist[i]->area();
    std::cout << "总面积是：" << sumArea << std::endl;
}
