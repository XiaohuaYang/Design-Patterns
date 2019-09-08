//简单的hello world程序
int main(int argc,char* argv[])
{
    printf("Hello World!\n");
    return 0;
}


//使用回调函数来实现hello world
//定义回调函数
void PrintfText() 
{
    printf("Hello World!\n");
}

//定义实现回调函数的"调用函数"
void CallPrintfText(void (*callfuct)())
{
    callfuct();
}

//在main函数中实现函数回调
int main(int argc,char* argv[])
{
    CallPrintfText(PrintfText);
    return 0;
}


//定义带参回调函数
void PrintfText(char* s) 
{
    printf(s);
}

//定义实现带参回调函数的"调用函数"
void CallPrintfText(void (*callfuct)(char*),char* s)
{
    callfuct(s);
}

//在main函数中实现带参的函数回调
int main(int argc,char* argv[])
{
    CallPrintfText(PrintfText,"Hello World!\n");
    return 0;
}
