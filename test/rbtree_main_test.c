
#include "../libft.h"

void	ft_print(int i, int status)
{
	ft_putstr("test ");
	ft_putnbr(i);
	if (status == SUCCESS)
		ft_putstr(" SUCCESS\n");
	else
		ft_putstr(" FAIL\n");
}

int		func_cmp(void *old, void *new)
{
	int *o;
	int *n;

	o = (int *)old;
	n = (int *)new;
	if (*n > *o)
		return (1);
	else if (*n == *o)
		return (0);
	else
		return (-1);
}

void	ft_use_func_with_tree(int (*func)(t_rbtr *))
{
	static int num;
	t_rbtr *tree;

	tree = ft_create_rbtree(func_cmp, NULL);
	if (func)
		ft_print(num, func(tree));
	else
		ft_print(num, SUCCESS);

	ft_del_rbtree(&tree);
	if (tree)
		ft_putstr("error\n");
	num++;
}

int		ft_add_one_elem(t_rbtr *tree)
{
	int value;

	value = 4;
	ft_rbtree_add(tree, (void *)&value, (void *)&value);
	if (tree->root.left->elem == (void *)&value
	&& tree->root.left->color == BLACK
	&& tree->elems_count == 1)
		return (SUCCESS);
	return(FAIL);
}

int		ft_add_two_elem(t_rbtr *tree)
{
	int v[2];

	v[0] = 4;
	v[1] = 5;
	ft_rbtree_add(tree, (void *)v, (void *)v);
	ft_rbtree_add(tree, (void *)(v + 1), (void *)(v + 1));
	if (tree->root.left->elem == (void *)v
	&& tree->root.left->right->elem == (void *)(v + 1)
	&& tree->root.left->color == BLACK
	&& tree->root.left->right->color == RED
	&& tree->elems_count == 2)
		return (SUCCESS);
	return(FAIL);
}

int		ft_add_three_elem_left_rot(t_rbtr *tree)
{
	int v[3];

	v[0] = 4;
	v[1] = 5;
	v[2] = 6;
	ft_rbtree_add(tree, (void *)v, (void *)v);
	ft_rbtree_add(tree, (void *)(v + 1), (void *)(v + 1));
	ft_rbtree_add(tree, (void *)(v + 2), (void *)(v + 2));
	if (tree->root.left->elem == (void *)(v + 1)
	&& tree->root.left->color == BLACK
	&& tree->root.left->right->elem == (void *)(v + 2)
	&& tree->root.left->right->color == RED
	&& tree->root.left->left->elem == (void *)(v + 0)
	&& tree->root.left->left->color == RED
	&& tree->elems_count == 3)
		return (SUCCESS);
	return(FAIL);
}

int		ft_add_three_elem_right_rot(t_rbtr *tree)
{
	int v[3];

	v[0] = 4;
	v[1] = 5;
	v[2] = 4;
	ft_rbtree_add(tree, (void *)v, (void *)v);
	ft_rbtree_add(tree, (void *)(v + 1), (void *)(v + 1));
	ft_rbtree_add(tree, (void *)(v + 2), (void *)(v + 2));
	if (tree->root.left->elem == (void *)(v + 2)
	&& tree->root.left->color == BLACK
	&& tree->root.left->right->elem == (void *)(v + 1)
	&& tree->root.left->right->color == RED
	&& tree->root.left->left->elem == (void *)(v + 0)
	&& tree->root.left->left->color == RED
	&& tree->elems_count == 3)
		return (SUCCESS);
	return(FAIL);
}

t_bool	ft_assert_true(t_tnode *node, void *value, int color)
{
	if (node->elem == value && node->color == color)
		return (TRUE);
	return (FALSE);
}

int		ft_add_eight_elem(t_rbtr *tree)
{
	t_tnode *root;
	int v[8];
	int i;

	i = -1;
	while (++i < 8)
	{
		v[i] = i;
		ft_rbtree_add(tree, (void *)(v + i), (void *)(v + i));
	}
	root = tree->root.left;
	if (ft_assert_true(root, (void *)(v + 3), BLACK)
	&& ft_assert_true(tree->root.left->right, (void *)(v + 5), RED)
	&& ft_assert_true(root->right->right, (void *)(v + 6), BLACK)
	&& ft_assert_true(root->right->left, (void *)(v + 4), BLACK)
	&& ft_assert_true(root->right->right->right, (void *)(v + 7), RED)
	&& ft_assert_true(root->left, (void *)(v + 1), RED)
	&& ft_assert_true(root->left->left, (void *)(v + 0), BLACK)
	&& ft_assert_true(root->left->right, (void *)(v + 2), BLACK)
	&& tree->elems_count == 8)
		return (SUCCESS);
	return(FAIL);
}

int		ft_iterator(t_rbtr *tree)
{
	int *ptr;
	int v[8];
	int i;

	i = -1;
	while (++i < 8)
	{
		v[i] = i;
		ft_rbtree_add(tree, (void *)(v + i), (void *)(v + i));
	}
	i = -1;
	while ((ptr = (int *)ft_rbtree_get_next(tree)))
		if (*ptr != ++i)
			return(FAIL);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	ft_putstr("start\n");

	ft_use_func_with_tree(NULL);
	ft_use_func_with_tree(ft_add_one_elem);
	ft_use_func_with_tree(ft_add_two_elem);
	ft_use_func_with_tree(ft_add_three_elem_left_rot);
	ft_use_func_with_tree(ft_add_three_elem_right_rot);
	ft_use_func_with_tree(ft_add_eight_elem);
	ft_use_func_with_tree(ft_iterator);
	ft_putstr("end\n");
	return (0);
}
