//hello world
int main(int argc,char* argv[])
{
    printf("Hello World!\n");
    return 0;
}

//使用函数调用方式实现hello world
void Invoke(char* s);

int main(int argc,char* argv[])
{
    Invoke("Hello World!\n");
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
