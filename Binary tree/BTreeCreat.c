//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，
//空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。


解题思路：首先构前序遍历构建堆，返回根之后，中序遍历打印字符，打印字符的格式不能有错；









#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char val;
	struct Node *left;
	struct Node *right;
}Node;


Node* HeapCreat(char *str, int *sub)//前序构建堆
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