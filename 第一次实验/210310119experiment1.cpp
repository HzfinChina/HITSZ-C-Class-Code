/* Author: 210310119机械1班胡志烽*/
#include<iostream>
using namespace std;

typedef char* ElemType;

class stringnode
{
    private:
        stringnode* next;
    public:
        ElemType name = NULL;
        char type; //如果为0就是操作符，为1就是操作数
        stringnode* NewNode()
        {
            stringnode* next = (stringnode*)malloc(sizeof(stringnode));
            return next;
        }
        void PrintNode()
        {
            if (type == '0')
                cout << "操作符" << name <<endl;
            else 
                cout << "操作数" << name <<endl;
        }
};

class bracketstack
{
    private:
        char stackarray[50] ={};
        int tail = 0;
    public:
        int Gettail()
        {
            return tail;
        }
        void Pop()
        {
            tail--;
        }
        void Push(char bracket)
        {
            stackarray[tail] = bracket;
            tail++;
        }
        int Judge(char bracket) //判断入栈的括号是否匹配
        {
            if (bracket == '('||bracket == '[' || bracket == '{') //如果
            {
                Push(bracket);
                return 1;
            }
            else 
            {
                if (tail == 0)
                    return -1;
                if (
                        ((bracket == '}' || bracket == ']') && bracket == stackarray [tail-1] + 2)
                        ||(bracket == ')' && bracket == stackarray[tail-1]+1)) //如果要入栈的元素栈顶的元素匹配，那就弹出栈顶元素 （通过ASCII码值判断，右括号=左括号+1,大右括号 = 左大括号 + 2
                {

                    Pop();
                    return 1;
                }
                else  
                    return -1; //如果不匹配返回-1;
            }
        }
};

int Readnumber(char* s, stringnode * const node)
{
    int len = 0; //数字的长度
    char*head = s;
    while (('0' <= *s && *s <= '9') || *s == '.')
    {
        len ++;
        s++;
    }
    if (len != 0)
    {
        node->name = (char*)malloc(sizeof(char)*len);
        int i;
        for(i = 0; i< len;i++)
            node->name[i] = *(head + i);
        node->type = '1';
    }
    return len;
}
void Read(char *s, stringnode *node, bracketstack * const stack)
{
    while(*s != '\0')
    {
        int len = Readnumber(s,node);
        if (len != 0)
        {
            s+= len;
            node->type = '1';
            node->PrintNode();
            node = node->NewNode();
        }
        if (*s == '+' || *s == '-' || *s == '*' || *s =='/')
        {
            node->type = '0';
            node->name = (char*)malloc(sizeof(char));
            node->name[0] = *s;
            node->PrintNode();
            node = node->NewNode();
            s++;
        }
        if (*s == '(' || *s == ')' || *s == '[' || *s == ']' || *s == '{' || *s == '}')
        {
            node->type = '0';
            node->name = (char*)malloc(sizeof(char));
            node->name[0] = *s;
            node->PrintNode();
            if (stack->Judge(*s) != 1)
            {
                cout << "匹配错误";
                return;
            }
            node = node->NewNode();
            s++;
        }
    }
    if (stack->Gettail()!= 0)
        cout << "匹配错误";
}
int main()
{
    char* string = (char*)malloc(sizeof(char)*200);
    stringnode *node = (stringnode*)malloc(sizeof(stringnode));
    bracketstack *stack = (bracketstack*)malloc(sizeof(bracketstack));
    cout << "Input number" << endl;
    cin >> string;
    Read(string, node, stack);
}
