//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո�
//�ո��ַ����������������˶������Ժ��ٶԶ������������������������������


����˼·�����ȹ�ǰ����������ѣ����ظ�֮�����������ӡ�ַ�����ӡ�ַ��ĸ�ʽ�����д�









#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char val;
	struct Node *left;
	struct Node *right;
}Node;


Node* HeapCreat(char *str, int *sub)//ǰ�򹹽���
{
	if (str[*sub] != '#')
	{
		Node *root = (Node *)malloc(sizeof(Node));
		root->val = str[*sub];
		(*sub)++;
		root->left = HeapCreat(str, sub);
		(*sub)++;
		root->right = HeapCreat(str, sub);
		return root;
	}
	return NULL;
}

void InorderTraversal(Node *root)
{
	if (root)
	{
		InorderTraversal(root->left);
		printf("%c ", root->val);
		InorderTraversal(root->right);
	}

}


int main()
{
	char str[101] = { 0 };
	scanf("%s", str);
	int sub = 0;
	Node *root = HeapCreat(str, &sub);
	InorderTraversal(root);

	return 0;
}