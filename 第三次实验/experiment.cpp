#include <iostream>
#include<iomanip>
using namespace std;

class Matrix_4x4
{
    private:
        double matrix[4][4];
    public:
        Matrix_4x4(double defaultnum = 1);
        Matrix_4x4(const double (&mat)[4][4]);
        Matrix_4x4(const Matrix_4x4 &obj); //拷贝构造函数
        void operator=(const double (&b)[4][4]);
        void operator=(const Matrix_4x4 &b);
        Matrix_4x4 operator+(const Matrix_4x4& b);
        Matrix_4x4 operator-(const Matrix_4x4& b);
        Matrix_4x4 operator*(const Matrix_4x4& b);
        Matrix_4x4 operator^(const int pow);
        const double* operator[](const int i){
            return matrix[i];
        }

        Matrix_4x4 Transpose();
        Matrix_4x4 Inverse();
        Matrix_4x4 Swap(unsigned short nozerol, unsigned short line);
        Matrix_4x4 Change(unsigned short col);
        double delt();
        short FindNotZero(unsigned short col);
        Matrix_4x4 Swap(unsigned short nozerol, Matrix_4x4& E);
        Matrix_4x4 Swap(unsigned short nozerol,unsigned short El, Matrix_4x4& E);
        Matrix_4x4 Change(unsigned short col, Matrix_4x4 &E);
        friend ostream &operator<<(ostream &output, const Matrix_4x4& OutputMatrix)
        {
            output << "ans=" << endl;
            short i, j;
            for (i = 0; i < 4; i++)
            {
                for (j = 0;j<4;j++)
                {
                    output << setw(8) << setprecision(4) << OutputMatrix.matrix[i][j] << " "; //setprecision 控制的是从非0开始的位数而非小数点后位数
                }
                output << "\n";
            }
            return output;
        }
        friend istream &operator>>(istream &input, Matrix_4x4 & inmat)
        {
            short i, j;
            for (i = 0; i < 4; i++)
            {
                    cin >> inmat.matrix[i][0] >> inmat.matrix[i][1] >> inmat.matrix[i][2] >> inmat.matrix[i][3];
            }
            return input;
        }
};


Matrix_4x4::Matrix_4x4(double defaultnum)
{
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            matrix[i][j] = 0;
    }
    for (i = 0; i < 4; i++)
        matrix[i][i] = defaultnum;
}

Matrix_4x4::Matrix_4x4(const double (&mat)[4][4])
{
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            matrix[i][j] = mat[i][j];
    }
}

Matrix_4x4::Matrix_4x4(const Matrix_4x4 &obj)
{
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            matrix[i][j] = obj.matrix[i][j];
    }
}

void Matrix_4x4::operator=(const double (&b)[4][4])
{
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j< 4; j++)
            matrix[i][j] = b[i][j];
    }
}

void Matrix_4x4::operator=(const Matrix_4x4& b)
{
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j< 4; j++)
            matrix[i][j] = b.matrix[i][j];
    }
}

Matrix_4x4 Matrix_4x4::operator+(const Matrix_4x4& b)
{
    Matrix_4x4 retmat;
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            retmat.matrix[i][j] = matrix[i][j] + b.matrix[i][j]; 
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::operator- (const Matrix_4x4& b)
{
    Matrix_4x4 retmat;
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            retmat.matrix[i][j] = matrix[i][j] -b.matrix[i][j]; 
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::operator* (const Matrix_4x4& b)
{
    Matrix_4x4 retmat(0);
    short i, j, k;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
                retmat.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
        }
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::operator ^(const int pow)
{
    Matrix_4x4 retmat;
    short i;
    double power;
    if (pow < 0)
    {
        power = -pow;
        retmat = Inverse();
    }
    power = pow;
    for (i = 0; i < power; i++)
    {
        retmat = retmat * (*this);
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::Transpose()
{
    Matrix_4x4 retmat;
    short i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            retmat.matrix[i][j] = matrix[j][i];
        }
    }
    return retmat;
}

//---------以下为求行列式

double Matrix_4x4::delt()
{
    double ret = 1;
    short col;
    Matrix_4x4 temp = (*this);
    for (col = 0; col < 3; col++) //通过行变换化为上三角行列式
    {
        short maxl = temp.FindNotZero(col); // 找到这一列中不是0的元素
        if (maxl == -1)   //如果这一列中都是0那么行列式一定为0
            return 0;
        temp = temp.Swap(maxl, col);
        temp = temp.Change(col);
    }
    for (col = 0; col < 4; col ++) //行列式等于上三角对角线元素累乘
    {
        ret *= temp.matrix[col][col];
    }
    return ret;
}

short Matrix_4x4::FindNotZero(unsigned short col)
{
    short line;
    for (line = col; line < 4; line ++) //从当前行往下找非0的元素
    {
        if (matrix[line][col] != 0)
            return line;
    }
    return -1; //如果这一列全部是0
}

Matrix_4x4  Matrix_4x4::Change(unsigned short col) //求行列式，通过行变换把当前列的元素行数大于col的变为0
{
    Matrix_4x4 retmat(*this);
    short line, i;
    for (line = 3; line > col; line--)
    {
        double multiple = matrix[line][col]  / matrix[col][col];
        for (i = 0; i < 4; i++)
        {
            retmat.matrix[line][i] = retmat.matrix[line][i] - retmat.matrix[col][i] * multiple;
        }
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::Swap(unsigned short nozerol,unsigned short line) //行变换，把非0的行对应的行
{
    Matrix_4x4 retmat(*this);
    double temp;
    short col;
    for (col = 0; col < 4; col++)
    {
        temp = retmat.matrix[line][col];
        retmat.matrix[line][col] = retmat.matrix[nozerol][col];
        retmat.matrix[nozerol][col] = temp; 
    }
    return retmat;
}
//----------以上为求行列式
//----------以下为求逆
Matrix_4x4 Matrix_4x4::Swap(unsigned short nozerol,unsigned short El, Matrix_4x4& E) //行变换，将自身的非0行移动到单位阵对应的那一行，同时对单位阵移动
{
    Matrix_4x4 retmat(*this);
    double temp;
    short col;
    for (col = 0; col < 4; col++)
    {
        temp = retmat.matrix[El][col];
        retmat.matrix[El][col] = retmat.matrix[nozerol][col];
        retmat.matrix[nozerol][col] = temp; 
        temp = E.matrix[El][col];
        E.matrix[El][col] = E.matrix[nozerol][col];
        E.matrix[nozerol][col] = temp; 
    }
    return retmat;
}

Matrix_4x4  Matrix_4x4::Change(unsigned short col, Matrix_4x4 &E) //求行列式，通过行变换把当前列的元素除了单位阵对应的那一个之外全部变为0
{
    Matrix_4x4 retmat(*this);
    short line = col, i;
    double multiple = 1 / retmat.matrix[line][col];
    for (i = 0; i < 4; i++)//首先把当前行的元素对应单位阵的第一个元素变成1，后面的元素对应除以倍数
    {
        retmat.matrix[line][i] = retmat.matrix[line][i] * multiple;
        E.matrix[line][i] =E.matrix[line][i] * multiple;
    }
    for (line = 0; line < 4; line ++)
    {
        multiple = retmat.matrix[line][col]  / retmat.matrix[col][col];
        if (line == col) //如果当前行等于单位阵对应的行
            continue;
        for (i = 0; i < 4; i ++) //对当前行的每一个元素执行操作
        {
            retmat.matrix[line][i] = retmat.matrix[line][i] - retmat.matrix[col][i] * multiple;
            E.matrix[line][i] = E.matrix[line][i] - E.matrix[col][i] * multiple;
        }
    }
    return retmat;
}

Matrix_4x4 Matrix_4x4::Inverse()
{
    Matrix_4x4 E(1);
    Matrix_4x4 temp = (*this);
    short col, i;
    for (col = 0; col < 4; col ++)
    {
        short nozerol = temp.FindNotZero(col);
        temp = temp.Swap(nozerol,col,E);
        temp = temp.Change(nozerol, E);
    }
    return E;
}

int main()
{
    Matrix_4x4 mat1({{1,2,3,5},
                    {6,3,2,1},
                    {4,3,5,2},
                    {6,1,3,8}});
    Matrix_4x4 mat2;
    mat2={{2,3,4,5}, //测试 = 运算符重载
                       {1,6,2,1},
                       {1,2,8,32},
                       {8,1,2,7}};
    cout << "matrix1[3][1] is " <<mat1[3][1] << endl; //测试下标重载
    cout << "the determinant of mat1 is " << mat1.delt() << endl; //测试行列式
    cout << "mat1^3 " << (mat1^3); //测试^运算符重载和<<操作符重载
    cout << "The inverse of the matrix1 " << mat1.Inverse(); //测试逆矩阵
    cout << "The transverse of the matrix1" << mat1.Transpose(); //测试转置矩阵
    cout << "input mat2" << endl; 
    cin >> mat2; //测试输入运算符>> 重载

/*测试四则运算符*+-重载*/
    cout << "mat1 x mat2 " << mat1*mat2; 
    cout << "mat1 + mat2 " << mat1+mat2;
    cout << "mat1 - mat2 " << mat1-mat2;
}
