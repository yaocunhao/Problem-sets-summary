#include "seqlist.h"


int main()
{
	int quit = 0;
	int select = 0;
	SL s;//����һ���ṹ�����
	SeqListInit(&s);//���ٿռ�
	while (!quit)
	{
		Menu();
		printf("�������ѡ��\n");
		scanf("%d", &select);
		getchar();//�Ե����з�
		switch (select)
		{
		case 1:
			system("cls");
			SeqListPrint(&s);
			break;
		case 2:
			system("cls");
			SeqListPushBack(&s);
			break;
		case 3:
			system("cls");
			SeqListPopBack(&s);
			break;
		case 4:
			system("cls");
			SeqListPushFront(&s);
			break;
		case 5:
			system("cls");
			SeqListPopFront(&s);
			break;
		case 6:
			system("cls");
			SeqListFind(&s);
			break;
		case 7:
			system("cls");
			SeqListInsert(&s);
			break;
		case 8:
			system("cls");
			SeqListErase(&s);
			break;
		case 9:
			SeqListDestory(&s);
			quit = 1;//˳��������˳�ѭ��;
			break;
		case 10:
			system("cls");
			quit = 1;//�˳�;
			break;
		default:
			printf("�����������������\n");
		}
	}
	system("pause");
	return 0;
}