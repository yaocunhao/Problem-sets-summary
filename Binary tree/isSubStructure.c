入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

解法：通过递归前序遍历求解，在判断A和B都不为空后，进行递归
在递归的过程中判断A中是否有和B相等的子结构



bool Judge(struct TreeNode* A, struct TreeNode* B)
{
	if (B == NULL)
		return true;
	if (A == NULL&&B != NULL)
		return false;

	return
		(A->val == B->val) &&
		Judge(A->left, B->left) &&
		Judge(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
	if (B == NULL || A == NULL)
		return false;//空树

	if (Judge(A, B))
		return true;

	return isSubStructure(A->left, B) || isSubStructure(A->right, B);

}