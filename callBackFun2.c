void Invoke(char* s);

int main()
{
    void (*fp)(char* s);    //声明一个函数指针(fp)        
    fp=Invoke;              //将Invoke函数的入口地址赋值给fp
    fp("Hello World!\n");   //函数指针fp实现函数调用
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
