
//具有不同功能的函数，可用同一函数名表示；用一个函数名调用不同的函数内容
//C语言主要通过函数指针实现动态多态

#include<stdio.h>
#include<stdlib.h>

//虚函数表结构
struct baseVirtualTable
{
	void (*dance)(void*);
	void (*jump)(void*);
};

//基类
struct base
{
	/*VirtualTable*/
	struct baseVirtualTable *baseVirtualTablePtr
};

void BaseDance(void *this)
{
	printf("base dance \n");
}

void BaseJump(void *this)
{
	printf("base jump \n");
}

//基类全局虚函数表
struct baseVirtualTable baseTable
{
	BaseDance,
	BaseJump
};

//基类构造函数
struct base * NewBase()
{
	struct base * temp  = (struct base * )malloc(sizeof(struct base ));
	temp->baseVirtualTablePtr = &baseTable;
	return temp;
}

//派生类
struct derived
{
	struct base super;
	//派生类新增成员
	int high;
};

void DerivedDance(void * this)
{
	printf("derived dance\n");
}

void DerivedJump(void * this)
{
	struct derived* temp = (struct derived*)this;
	printf("derived jump: %d\n",temp->high);
}

//派生类的全局虚函数表
struct baseVirtualTable deriveTable
{
	(void(*)(void*))DerivedDance,
	(void(*)(void*))DerivedJump
};

//派生类的构造函数
struct derived * NewDerived(int h)
{
	struct derived * temp  = (struct derived * )malloc(sizeof(struct derived ));
	temp->super->baseVirtualTablePtr = &deriveTable;
	temp->high = h;
	return temp;
}


int main(void)
{
	struct base* base = NewBase();
	
	base->baseVirtualTablePtr->dance((void * )base);
	base->baseVirtualTablePtr->jump((void * )base);
	
	struct derived * child = NewDerived(100);
	
	//基类指针指向派生类
	base = (struct base*)child;
	base->baseVirtualTablePtr->dance((void * )base);
	base->baseVirtualTablePtr->jump((void * )base);
	
	return 0;
	
}














