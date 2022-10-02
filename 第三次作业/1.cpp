#include<iostream>
using namespace std;

class Student
{
    private:
        unsigned long id;
        float grade;
    public:
        friend void Max(Student * stulist);
        Student();
};

Student::Student()
{
    cout << "Input this student's id" << endl;
    cin >> id;
    cout << "Input this student's grade" << endl;
    cin >> grade;
}

void Max(Student *stulist)
{
    unsigned short i;
    unsigned long highestid;
    float highestgrade = 0;  //初始化为0否则可能是随机数
    for (i = 0; i < 5; i++)
    {
        if (stulist[i].grade > highestgrade)
        {
            highestgrade = stulist[i].grade;
            highestid = stulist[i].id;
        }
    }
    cout << "The id of the student who have the highest grade: " << highestid << endl;
    cout << "This student's grade is : " << highestgrade << endl;
}

int main()
{
    Student stu1, stu2, stu3, stu4, stu5;
    Student stulist[] = {stu1, stu2, stu3, stu4, stu5};
    Max(stulist);
}


