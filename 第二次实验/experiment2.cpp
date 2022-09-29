#include <iostream>
#include <string>
using namespace std;

template <class T> class Stack;
inline int GetPriority(char s);
double Calculate(double b, char opter, double a);
template <class T> 
class Stack
{
    private:
        T elem;
        Stack* next;
    public:
        bool is_empty =false; //如果是底部则为true
        void  Push(T newelem);
        T Pop();
        inline T GetTop(){
            return elem;
        }
        void ReadBracket(char* &s, Stack<double> *&numhead);
        void ReadOpter(char * &s, Stack<double> *&numhead);
        void ReadNumber(char* &s, Stack<double> *&head);
        void Calc_Push(Stack<char>*opterhead);
};

template<>
void Stack<double>::Calc_Push(Stack<char>*opterhead) //弹出两个操作数和一个操作符然后入栈
{
    double num1 = Pop();
    double num2 = Pop();
    char opter = opterhead->Pop();
    Push(Calculate(num2, opter, num1)); //要让后弹出的数字作为第一个参数
}


template<class T>
void Stack<T>::Push(T newelem)
{
    if (is_empty)
    {
        elem = newelem;
        is_empty = false;
    }
    else
    {
        Stack<T>* newnode = new Stack<T>;
        T tempelem = elem;
        Stack<T>* temppos = next;
        elem = newelem;
        next = newnode;
        newnode -> next = temppos;
        newnode -> elem = tempelem;
    }
}

template<class T>
T Stack<T>::Pop()
{
    if (is_empty) //如果栈已经是空的那么再Pop会抛出错误
    {
        cout << "匹配错误" << endl;
        exit(-1);
    }
    double retelem = elem; 
    if (next == NULL)
    {
        is_empty = true;
    } 
    else 
    {
        elem = next -> elem;
        next = next -> next;
    }
    return retelem;
}



template<>
void Stack<double>::ReadNumber(char* &s, Stack<double>* &head) //使用引用以便直接移动字符指针而不引入二级指针
{
    int len = 0;
    char tempstr[10];
    while ('0' <= *s && *s <= '9') 
    {
        tempstr[len] = *s;
        len++;
        s++;
    }
    if (len == 0)return;
    int num = std::stoi(tempstr);
    if (is_empty)
    {
        elem = num;
        is_empty = false;
    }
    else 
        Push((double)num);
}

template <>
void Stack<char>::ReadBracket(char* &s,  Stack<double> *&numhead)
{
    if (*s == '(')
    {
        Push(*s);
        s++;
    }
    if (*s == ')')
    {
        while (GetTop() != '(' && !is_empty) // 因为已经判断条件里已经有Pop所以循环体里面不能再出现Pop, 使用GetTop()
        {
            numhead->Calc_Push(this);
        }
        if (is_empty)
        {
            cout<< "匹配错误！" << endl;
            exit(-1);
        }
        else 
            Pop();
        s++;
    }
}


template<>
void Stack<char>::ReadOpter(char * &s,Stack<double> *&numhead)
{
    if (*s == '*' || *s == '/' || *s == '+' || *s == '-')
    {
        if (is_empty) //如果当前是空栈的话
        {
            elem = *s;
            is_empty = false;
        }
        else if (GetPriority(*s) < GetPriority(GetTop())) // */优先级>+- 如果入栈加减而栈顶是乘除则需要先计算乘除,反之不需要
        {
            numhead->Calc_Push(this);
            Push(*s);
        }
        else 
        {
            Push(*s);
        }
        s++;
    }
}

inline int GetPriority(char s) //返回优先级
{
    if (s == '*' || s == '/')return 1;
    if (s == '+' || s == '-')return 0;
    if (s == '(' || s == ')') return -1;
}

double Calculate(double b, char opter, double a)   //计算b theta a  
{  
    switch (opter)  
    {  
    case '+':  
        return b + a;  
    case '-':  
        return b - a;  
    case '*':  
        return b * a;  
    case '/':  
        return b / a;  
    default:  
        break;  
    }  
}

double Read(char *s, Stack<double> *numhead, Stack<char> *opterhead)
{
    while (*s != '\0')
    {
        numhead->ReadNumber(s, numhead);
        opterhead->ReadBracket(s, numhead);
        opterhead->ReadOpter(s, numhead);
    }
    while (!opterhead->is_empty) //如果操作符栈不为空
    {
        numhead->Calc_Push(opterhead);
    }
    return numhead->GetTop();
}



int main()
{
    Stack<double> *numhead = new Stack<double>;
    Stack<char> *opterhead = new Stack<char>;
    numhead->is_empty = true;
    opterhead->is_empty = true;
    char str[100] ;
    cout << "Input!" << endl;
    cin >> str;
    double retnum = Read(str, numhead, opterhead);
    cout << retnum << endl;
}
