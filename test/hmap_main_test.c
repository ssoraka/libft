
#include "../libft.h"
#include "../collections/collections_help_header.h"


int func_cmp(void *old, void *new)
{
	return (ft_strcmp((char *)old, (char *)new));
}

void func_del(void *key, void *value)
{
	free(value);
}


int add(void *list, void *key, void *value)
{
	return (ft_rbtree_add((t_rbtr *)list, key, value));
}

void *find(void *list, void *key)
{
	return (ft_rbtree_get_elem((t_rbtr *)list, key));
}

void del(void *list)
{
	ft_del_rbtree_nodes((t_rbtr *)list);
}

void	del_list_without_key_value(void *list)
{
	((t_rbtr *)list)->func_del = NULL;
	ft_del_rbtree_nodes((t_rbtr *)list);
}

int func_hash(void *key)
{
	return (((char *)key)[0] - '0');
}

t_iter iterator(void *list)
{
	return get_rbtree_iter((t_rbtr *)list);
}

t_hmap	*ft_create_hmap()
{
	t_rbtr *tree;
	t_ilist list;
	t_hmap *hmap;

	tree = (t_rbtr *)((void *)list.mem);
	ft_bzero((void *)tree, sizeof(t_rbtr));
	ft_init_rbtree(tree, func_cmp, func_del);
	ft_ilist_set_add(&list, add);
	ft_ilist_set_get(&list, find);
	ft_ilist_set_del(&list, del);
	ft_ilist_set_iterator(&list, iterator);
	ft_ilist_set_list(&list, (void *)tree, sizeof(t_rbtr));
	ft_ilist_set_func_for_resize_map(&list, del_list_without_key_value);

	hmap = ft_create_hashmap(func_hash, &list);
	return(hmap);
}


void	ft_print(int i, int status)
{
	ft_putstr("test ");
	ft_putnbr(i);
	if (status == SUCCESS)
		ft_putstr(" SUCCESS\n");
	else
		ft_putstr(" FAIL\n");
}


void	ft_use_func_with_tree(int (*func)(t_hmap *))
{
	static int num;
	t_hmap *hmap;

	hmap = ft_create_hmap();
	if (func)
		ft_print(num, func(hmap));
	else
		ft_print(num, SUCCESS);

	ft_del_hmap(&hmap);
	//if (hmap)
	//	ft_putstr("error\n");
	num++;
}


int		ft_add_one_str(t_hmap *hmap)
{
	char *str;

	str = ft_strdup("1123");

	ft_hashmap_put(hmap, (void *)str, (void *)str);
	if (ft_hashmap_get(hmap, (void *)str) == (void *)str)
		return (SUCCESS);
	else
		return (FAIL);
}

int		ft_add_two_str(t_hmap *hmap)
{
	char *str[2];

	str[0] = ft_strdup("1");
	str[1] = ft_strdup("2");

	ft_hashmap_put(hmap, (void *)str[0], (void *)str[0]);
	ft_hashmap_put(hmap, (void *)str[1], (void *)str[1]);
	if (ft_hashmap_get(hmap, (void *)str[0]) == (void *)str[0]
	&& ft_hashmap_get(hmap, (void *)str[1]) == (void *)str[1])
		return (SUCCESS);
	else
		return (FAIL);
}

int		ft_add_two_str_with_one_hash(t_hmap *hmap)
{
	char *str[2];

	str[0] = ft_strdup("11");
	str[1] = ft_strdup("12");

	ft_hashmap_put(hmap, (void *)str[0], (void *)str[0]);
	ft_hashmap_put(hmap, (void *)str[1], (void *)str[1]);
	if (ft_hashmap_get(hmap, (void *)str[0]) == (void *)str[0]
	&& ft_hashmap_get(hmap, (void *)str[1]) == (void *)str[1])
		return (SUCCESS);
	else
		return (FAIL);
}

void ft_putnbr_end1(int n)
{
	ft_putnbr(n);
	ft_putstr("\n");
}


int		ft_increase_hashmap(t_hmap *hmap)
{
	char *str;
	int i;

	i = 0;
	while (i < hmap->max_load)
	{
		str = ft_itoa(i);
		ft_hashmap_put(hmap, (void *)str, (void *)str);
		i++;
	}
	str = ft_itoa(i);
	if (!ft_hashmap_put(hmap, (void *)str, (void *)str))
		return (FAIL);
	if (hmap->max_load == HASHMAP_LOAD * (HASHMAP_FIRST_COUNT * 2)
	&& hmap->elems_used == i + 1
	&& hmap->arr->elems_count == HASHMAP_FIRST_COUNT * 2)
		return (SUCCESS);
	return (FAIL);
}


int		main(int argc, char **argv)
{
	ft_putstr("start\n");
	ft_use_func_with_tree(NULL);
	ft_use_func_with_tree(ft_add_one_str);
	ft_use_func_with_tree(ft_add_two_str);
	ft_use_func_with_tree(ft_add_two_str_with_one_hash);
	ft_use_func_with_tree(ft_increase_hashmap);
	ft_putstr("end\n");
	return (0);
}
