#include"stack.h"

void test1()
{
	stack p;
	StackInit(&p);
	StackPush(&p, 1);
	StackPush(&p, 2);
	StackPush(&p, 3);
	StackPush(&p, 4);
	while (!StackEmpty(&p))
	{
		printf("%d\n", StackTop(&p));
		printf("size:%d\n", StackSize(&p));
		StackPop(&p);

	}

	if (StackEmpty(&p))
		printf("Îª¿Õ\n");
	else
		printf("²»Îª¿Õ\n");

	StackDestory(&p);
}

int main()
{
	test1();
	system("pause");
	return 0;

}