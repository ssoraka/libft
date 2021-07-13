//
// Created by Suzette Soraka on 7/11/21.
//
#include "libft.h"

int f(void *a, void *b) {
	return ft_strcmp(a, b);
}


int main() {

//	t_arr	*arr = ft_create_arr_of_ptr(10, NULL);
//	ft_arr_add(arr, "first");
//	ft_arr_add(arr, "second");
//	ft_arr_add(arr, "third");
//
//	t_iter iter = get_arr_iter(arr);
//
//	while (iter.get_next_elem(&iter)) {
//		ft_putstr(iter.value);
//	}

//	t_arr	*arr1 = ft_create_arr(4, 10, NULL);
//	int a = 10;
//	ft_arr_add(arr1, &a);
//
//	t_iter iter1 = get_arr_iter(arr1);
//
//	while (iter1.get_next_elem(&iter1)) {
//		ft_putnbr(*((int *)iter1.value));
//	}


//	t_llist	*list = ft_create_llist(NULL);
//	ft_llist_add(list, "first");
//	ft_llist_add(list, "second");
//	ft_llist_add(list, "third");
//
//
//	t_iter iter = get_llist_iter(list);
//
//	while (iter.get_next_elem(&iter)) {
//		ft_putstr(iter.value);
//		ft_putstr("\n");
//	}


	t_rbtr *tree = ft_create_rbtree(f, NULL);
//	ft_rbtree_add(tree,"1", "1");
//	ft_rbtree_add(tree,"2", "2");
//	ft_rbtree_add(tree,"3", "3");
//	ft_rbtree_add(tree,"4", "4");
//	ft_rbtree_add(tree,"5", "5");
//	ft_rbtree_add(tree,"6", "6");
//	ft_rbtree_add(tree,"7", "7");
//	ft_rbtree_add(tree,"8", "8");

	t_iter iter = get_rbtree_iter(tree);
	while (iter.get_next_elem(&iter)) {
		ft_putstr(iter.value);
		ft_putstr("\n");
	}


	return (0);
}