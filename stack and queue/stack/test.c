#include "statck.h"

void test1()
{
	statck s;
	stackInit(&s);
	stackpush(&s, 1);
	stackpush(&s, 2);
	stackpush(&s, 3);
	stackpush(&s, 4);
	stackpush(&s, 5);
	stackpush(&s, 6);
	stackPop(&s);
	stackPop(&s);
	stackPop(&s);
	//printf("%d\n", statckTop(&s)); 
	///printf("%d\n", statckSize(&s));

	stackPop(&s);
	stackPop(&s);
	if (stackEmpty(&s))
		printf("weikong\n");
	stackDestroy(&s);
	//stackpush(&s, 1);




}


int main()
{
	test1();
	system("pause");
	return 0;
}