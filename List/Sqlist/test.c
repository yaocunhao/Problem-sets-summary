#include "seqlist.h"

void Menu()
{
	printf("############################################\n");
	printf("#1.��ӡ ##############################2.β��\n");
	printf("#3.βɾ###############################4.�ײ�\n");
	printf("#5.��ɾ###############################6.����\n");
	printf("#7.������λ�ò���#############8.ɾ��ĳ��λ��\n");
	printf("#9.����˳���################10.�˳�########\n");
	printf("############################################\n");

}
void SeqListInit(SL*sp)//���ٿռ�
{
	assert(sp);
	sp->arr = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (sp->arr == NULL)
	{
		printf("���ٿռ�ʧ��\n");
		exit(-1);
	}
	printf("���ٿռ�ɹ�\n");
	sp->size = 0;
	sp->capacity = 4;
}
void SeqListPrint(SL*sp)//��ӡ
{
	assert(sp);
	if (sp->size == 0)
	{
		printf("����Ϊ��\n");
	}
	for (int i = 0; i < sp->size; i++)
	{
		printf("%d\n", sp->arr[i]);
	}
}


static void  CheckCapacity(SL*sp)//�������
{
	assert(sp);
	if (sp->size == sp->capacity)
	{
		SLDataType *p = NULL;
		p = (SLDataType*)realloc(sp->arr, 2 * sp->capacity*sizeof(SLDataType));
		if (p == NULL)
		{
			printf("����ʧ��\n");
		}
		else
		{
			sp->arr = p;
			sp->capacity = 2 * sp->capacity;
			printf("���ݳɹ�\n");
		}
	}
}
void SeqListPushBack(SL*sp)//β��
{
	assert(sp);
	int n = 0;
	CheckCapacity(sp);
	printf("��������Ҫ���������\n");
	scanf("%d", &n);
	sp->arr[sp->size] = n;
	sp->size++;
}
void SeqListPopBack(SL*sp)//βɾ
{
	assert(sp);
	sp->size--;
}
void SeqListPushFront(SL*sp)//�ײ�
{
	assert(sp);
	int n = 0;
	CheckCapacity(sp);
	int end = sp->size;
	while (end)
	{
		sp->arr[end] = sp->arr[end-1];
		end--;
	}
	printf("��������Ҫ���������\n");
	scanf("%d", &n);
	sp->arr[0]=n;
	sp->size++;

}
void SeqListPopFront(SL*sp)//��ɾ
{
	assert(sp);
	for (int i = 0; i < sp->size - 1; i++)
	{
		sp->arr[i] = sp->arr[i + 1];
	}
	sp->size--;
}
void SeqListFind(SL*sp)//����
{
	assert(sp);
	int n = 0;
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d", &n);
	for (int i = 0; i < sp->size; i++)
	{
		if (sp->arr[i] == n)
		{
			printf("%d��˳����ж�Ӧ���±���%d\n", n, i);
			break;
		}
	}
	printf("˳�����û����Ҫ���ҵ�����\n");
}
void SeqListInsert(SL*sp)//�������
{
	assert(sp);
	CheckCapacity(sp);
	int pos = 0;
	int n = 0;
	printf("��������Ҫ���ĸ�λ�ò���ʲô����\n");
	scanf("%d%d", &pos, &n);
	if (pos > sp->size)
		printf("��������\n");
	else
	{
		int end = sp->size;
		while (end > pos)
		{
			sp->arr[end] = sp->arr[end - 1];
			end--;
		}
		sp->arr[pos] = n;
		sp->size++;
	}
	
}
void SeqListErase(SL*sp)//ɾ��λ�õ�ֵ
{
	assert(sp);
	int pos = 0;
	printf("��������Ҫɾ���ĸ�λ�õ�ֵ\n");
	scanf("%d", &pos);
	if (pos >= sp->size)
	{
		printf("��������\n");
	}
	else
	{
		int end = sp->size-1;
		while (pos < end)
		{
			sp->arr[pos] = sp->arr[pos + 1];
			pos++;
		}
		sp->size--;
	}
}
void SeqListDestory(SL*sp)//����˳���
{
	assert(sp);
	if (sp->capacity == 0)
	{
		printf("�Ѿ����٣���ֹ�ظ�����\n");
	}
	else
	{
		free(sp->arr);
		sp->arr = NULL;//��Ұָ��
		sp->size = 0;
		sp->capacity = 0;
	}
}

