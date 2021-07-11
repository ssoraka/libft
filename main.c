//
// Created by Suzette Soraka on 7/11/21.
//
#include "libft.h"

int main() {

	t_arr	*arr = ft_create_arr_of_ptr(10, NULL);
	ft_arr_add(arr, "first");
	ft_arr_add(arr, "second");
	ft_arr_add(arr, "third");

	t_iter iter = get_arr_iter(arr);

	while (iter.get_next_elem(&iter)) {
		ft_putstr(iter.value);
	}

	t_arr	*arr1 = ft_create_arr(4, 10, NULL);
	int a = 10;
	ft_arr_add(arr1, &a);

	t_iter iter1 = get_arr_iter(arr1);

	while (iter1.get_next_elem(&iter1)) {
		ft_putnbr(*((int *)iter1.value));
	}

	return (0);
}