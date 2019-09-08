typedef void (*FP)(char* s);

void InvokeA(char* s);
void InvokeB(char* s);
void InvokeC(char* s);

int main(int argc，char* argv[])
{
    void* a[]={f1,f2,f3};   //定义了指针数组，这里a是一个普通指针
    a[0]("Hello World!\n"); //编译错误，指针数组不能用下标的方式来调用函数

    FP f[]={f1,f2,f3};      //定义一个函数指针的数组，这里的f是一个函数指针
    f[0]("Hello World!\n"); //正确，函数指针的数组进行下标操作可以进行函数的间接调用
    return 0;
}

void InvokeA(char* s)
{
    printf(s);
}

void InvokeB(char* s)
{
    printf(s);
}

void InvokeC(char* s)
{
    printf(s);
}



