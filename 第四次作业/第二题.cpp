#include <iostream>
#include <string.h>

class Teacher
{
    public:
        void display();
    protected:
        char name[20], sex[5], address[50], phonenum[15];
        char title[20];
        short age;
};
class Cadre
{
    public:
        void display();
    protected:
        char post[20];
    private: 
        char name[10], sex[5], address[20], phonenum[15];
        short age;
};

class Teacher_Cadre : public Teacher, public Cadre
{
    public: 
        void show();
        Teacher_Cadre();
    private: 
        float wages;
};

void Teacher::display()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "sex: " << sex << std::endl;
    std::cout << "title: " << title << std::endl;
    std::cout << "address: " << address << std::endl;
    std::cout << "phonenumber: " << phonenum << std::endl;
}

Teacher_Cadre::Teacher_Cadre()
{
    strcpy(Teacher::name, "Alan V. Oppenheim");
    strcpy(Teacher::sex, "male");
    strcpy(Teacher::title, "professor");
    strcpy(Teacher::address, "25 Gray St, Cambridge, MA 02138");
    strcpy(Teacher::phonenum, "(617) 876-4864");
    strcpy(Cadre::post, "None");
    wages = 300000;
}

void Teacher_Cadre::show()
{
    Teacher::display();
    std::cout << "wages:" << wages << std::endl;
    std::cout << "post:" << post << std::endl;
}

int main()
{
    Teacher_Cadre person1;
    person1.show();
}
