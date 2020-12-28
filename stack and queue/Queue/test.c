#include "queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	Queuepush(&q, 1);
	Queuepush(&q, 2);
	Queuepush(&q, 3);
	Queuepush(&q, 4);
	printf("%d\n", QueueSize(&q));
	//QueueEmpty(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d\n", QueueSize(&q));
	QueuePop(&q);
	QueuePop(&q);
	int c=QueueEmpty(&q);
	if (c)
		printf("Á´±íÎª¿Õ\n");
	int ret=QueueFront(&q);
	int num = QueueBack(&q);


}


int main()
{
	test1();

	printf("dd\n");
	system("pause");
	return 0;
}