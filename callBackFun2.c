typedef void (*FP)(char* s);

void Invoke(char* s);

int main(int argc，char* argv[])
{
    FP fp;
    fp=Invoke;              //将Invoke函数的入口地址赋值给fp
    fp("Hello World!\n");   //函数指针fp实现函数调用
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}


