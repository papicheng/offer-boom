/*功能：*/
#include<bits/stdc++.h>

using namespace std;

class Calculator{
    public:
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1 + m_Num2;
        }
        else if(oper == "-"){
            return m_Num1 - m_Num2;
        }
        else if(oper == "*"){
            return m_Num1 * m_Num2;
        }
    }
    int m_Num1;
    int m_Num2;
};
void test01(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    cout<< c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+")<<endl;
    cout<<c.m_Num1<< "-" << c.m_Num2 << "=" << c.getResult("-")<<endl;
    cout<<c.m_Num1 <<"*" <<c.m_Num2 << "=" << c.getResult("*") <<endl;
}

//实现计算器的抽象类
class AbstractCalculator{
    public:
    virtual int getResult(){
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//加法计算器类
class AddCalculator : public AbstractCalculator{
    public:
    int getResult(){
        return m_Num1 + m_Num2;
    }
};
class CutCalculator : public AbstractCalculator{
    public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};

void test02(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    //加法运算
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;

    cout<< abc->m_Num1 << "+" << abc->m_Num2 << " = " << abc->getResult()<<endl;

    delete abc;
}
int main()
{
    test02();
    return 0;
}
