//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

//通过递归更换原树的根节点来与新树进行比较判断，是否相等

bool  Judge(struct TreeNode* s, struct TreeNode* t)//判断是否相等
{
	if (s == NULL&&t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;

	return
		(s->val == t->val) &&
		Judge(s->left, t->left) &&
		Judge(s->right, t->right);
}



bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (t == NULL)//子树为空，肯定被包含
		return true;
	if (s == NULL)//子树不为空，原树为空
		return false;

	if (Judge(s, t))//判断相等直接返回
		return true;

	return (isSubtree(s->left, t) || isSubtree(s->right, t));//判断子树

}