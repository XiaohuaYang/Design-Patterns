#include<stdio.h>

//定义三种策略
void strategyA(void)
{
	printf("strategyA\n");
}

void strategyB(void)
{
	printf("strategyB\n");
}

void strategyC(void)
{
	printf("strategyC\n");
}

//策略模式的统一访问接口
void *strategyFunc(void (*strategy)(void))
{
	strategy();
}

int main()
{
	
	//用函数调用使用策略A
	void *strategyPt = strategyFunc(strategyA);
	
	
	//直接赋值使用策略B
	void (*strategyPt)(void ) = strategyB;
	strategyPt();
	
	return 0;
}

#include<stdio.h>
#define LENGTH(array) (sizeof(array)/sizeof(array[0]))

int StrategyA(int dataX, int dataY)
{
	return dataX - dataY;
}

int StrategyB(int dataX, int dataY)
{
	return dataY - dataX;
}

int StrategyC(int dataX, int dataY)
{
	return dataX%3 - dataY%3;
}


void sort(int* array, int arrayLen, int (*ProStrategy)(int, int))
{
	for(int iteratorA = 0; iterator < arrayLen - 1; iterator++)
	{
		for(int iteratorB = 0; iteratorB < arrayLen - iteratorA - 1; iteratorB++)
		{
			if(ProStrategy(array[iteratorB], array[iteratorB + 1]) > 0)
			{
				int temp = array[iteratorB];
				array[iteratorB] = array[iteratorB + 1];
				array[iteratorB + 1] = temp;
			}
		}
	}
}

int main()
{
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	arrayLen = LENGTH(array);
	
	sort(array, arrayLen, StrategyA);
	sort(array, arrayLen, StrategyB);
	sort(array, arrayLen, StrategyC);
	
	return 0;
}
