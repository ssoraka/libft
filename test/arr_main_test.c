
#include "../libft.h"

int		num;

void	ft_print(int i, int status)
{
	ft_putstr("test ");
	ft_putnbr(i);
	if (status == SUCCESS)
		ft_putstr(" SUCCESS\n");
	else
		ft_putstr(" FAIL\n");
}

void	ft_use_func_with_arr(int (*func)(t_arr *))
{
	t_arr *arr;

	arr = ft_create_arr(8, 0, NULL);
	if (func)
		ft_print(num, func(arr));
	else
		ft_print(num, SUCCESS);

	ft_del_arr(&arr);
	if (arr)
		ft_putstr("error\n");
	num++;
}

void	ft_use_func_with_arr_of_ptr(int (*func)(t_arr *))
{
	t_arr *arr;

	arr = ft_create_arr_of_ptr(0, NULL);
	if (func)
		ft_print(num, func(arr));
	else
		ft_print(num, SUCCESS);

	ft_del_arr(&arr);
	if (arr)
		ft_putstr("error\n");
	num++;
}

void	func_del_str(void *str)
{
	free(str);
}

int		ft_one_add_str(t_arr *arr)
{
	char *str;
	int elems_count;

	str = ft_strdup("some text");
	elems_count = arr->elems_used;
	ft_arr_add(arr, str);
	if (((char **)arr->elems)[elems_count] == str && elems_count + 1 == arr->elems_used)
		return (SUCCESS);
	return (FAIL);
}

int		ft_one_del_first_str(t_arr *arr)
{
	int answer;
	int count;
	void *ptr;

	answer = FAIL;
	count = arr->elems_used;
	ptr = ft_arr_get(arr, 0);
	if ((count == 0 && arr->elems == NULL && ptr == NULL)
	|| ((char **)arr->elems)[0] == ptr)
		return (SUCCESS);
	ft_del_elem(arr, 0);

	if (count != arr->elems_used + 1 && count + arr->elems_used != 0)
		answer = FAIL;
	return (answer);
}

int		ft_one_add_and_del_str(t_arr *arr)
{
	ft_init_arr(arr, 8, 0, &func_del_str);
	if (ft_one_add_str(arr) == SUCCESS
	&& ft_one_del_first_str(arr) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_three_add_and_del_str(t_arr *arr)
{
	ft_init_arr(arr, 8, 1, &func_del_str);
	if (ft_one_add_str(arr) == SUCCESS
	&& ft_one_add_str(arr) == SUCCESS
	&& ft_one_add_str(arr) == SUCCESS
	&& ft_one_del_first_str(arr) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_two_add_and_four_del_str(t_arr *arr)
{
	ft_init_arr(arr, 8, 0, &func_del_str);
	if (ft_one_add_str(arr) == SUCCESS
	&& ft_one_add_str(arr) == SUCCESS
	&& ft_one_del_first_str(arr) == SUCCESS
	&& ft_one_del_first_str(arr) == SUCCESS
	&& ft_one_del_first_str(arr) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_valid_get_of_ptr(t_arr *arr)
{
	int i[3];

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 8, 10, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));
	if (ft_arr_get(NULL, -100) == NULL
	&& ft_arr_get(arr, -100) == NULL
	&& ft_arr_get(arr, -1) == NULL
	&& ft_arr_get(arr, 0) == (void *)i
	&& ft_arr_get(arr, 1) == (void *)(i + 1)
	&& ft_arr_get(arr, 2) == (void *)(i + 2)
	&& ft_arr_get(arr, 3) == NULL
	&& ft_arr_get(arr, 4) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		ft_valid_get(t_arr *arr)
{
	int i[3];

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 4, 1, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));
	if (ft_arr_get(NULL, -100) == NULL
	&& ft_arr_get(arr, -100) == NULL
	&& ft_arr_get(arr, -1) == NULL
	&& *((int *)ft_arr_get(arr, 0)) == i[0]
	&& *((int *)ft_arr_get(arr, 1)) == i[1]
	&& *((int *)ft_arr_get(arr, 2)) == i[2]
	&& ft_arr_get(arr, 3) == NULL
	&& ft_arr_get(arr, 4) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		ft_valid_del(t_arr *arr)
{
	int i[3];

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 4, 1, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));
	ft_del_elem(NULL, 100);
	ft_del_elem(arr, 100);
	ft_del_elem(arr, -1);
	ft_del_elem(arr, 0);
	ft_del_elem(arr, 2);
	ft_del_elem(arr, 1);
	if (*((int *)ft_arr_get(arr, 0)) == i[2]
	&& ft_arr_get(arr, 1) == NULL
	&& ft_arr_get(arr, 2) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		ft_valid_del_of_ptr(t_arr *arr)
{
	int i[3];

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 8, 3, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));
	ft_del_elem(NULL, 100);
	ft_del_elem(arr, 100);
	ft_del_elem(arr, -1);
	ft_del_elem(arr, 0);
	ft_del_elem(arr, 2);
	ft_del_elem(arr, 1);
	if (ft_arr_get(arr, 0) == (void *)(i + 2)
	&& ft_arr_get(arr, 1) == NULL
	&& ft_arr_get(arr, 2) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		ft_while_arr_get_next(t_arr *arr)
{
	int i[3];
	int *ptr;
	int answer;
	t_iter iter;

	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 8, 3, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));

	answer = 0;
	iter = get_arr_iter(arr);
	while ((ptr = iter.get_next_elem(&iter)))
		answer = answer * *ptr + *ptr;
	if (answer != (1*2 + 2) * 3 + 3)
		return (FAIL);
	iter = get_arr_iter(arr);
	while ((ptr = iter.get_next_elem(&iter)))
		answer = answer * *ptr + *ptr;
	if (answer == ((15 * 1 + 1) * 2 + 2) * 3 + 3)
		return (SUCCESS);
	return(FAIL);
}

void	ft_square_in_answer(void *num, void *answer)
{
	int *value;

	value = num;
	*((int *)answer) = *((int *)answer) * *value + *value;
}

int		ft_for_each_elems_use_func_of_ptr(t_arr *arr)
{
	int i[3];
	int *ptr;
	int answer;

	answer = 0;
	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	ft_init_arr(arr, 8, 3, NULL);
	ft_arr_add(arr, (void *)i);
	ft_arr_add(arr, (void *)(i + 1));
	ft_arr_add(arr, (void *)(i + 2));
	ft_for_each_elem(arr, ft_square_in_answer, &answer);
	if (answer == ((0 * 1 + 1) * 2 + 2) * 3 + 3)
		return (SUCCESS);
	return(FAIL);
}

int		ft_init_arr_by_one(t_arr *arr)
{
	int value;
	int *ptr;

	value = 1;
	ft_init_arr(arr, 4, 4, NULL);
	ft_arr_init_by_value(arr, 3, (void *)&value);
	arr->elems_used = 4;
	if (ft_arr_get(arr, -1) == NULL
	&& *((int *)ft_arr_get(arr, 0)) == value
	&& *((int *)ft_arr_get(arr, 1)) == value
	&& *((int *)ft_arr_get(arr, 2)) == value
	&& *((int *)ft_arr_get(arr, 3)) == 0
	&& ft_arr_get(arr, 4) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		main(int argc, char **argv)
{
	num = 0;
	ft_putstr("start\n");

	ft_use_func_with_arr(NULL);
	ft_use_func_with_arr_of_ptr(NULL);
	ft_use_func_with_arr_of_ptr(ft_one_add_and_del_str);
	ft_use_func_with_arr_of_ptr(ft_three_add_and_del_str);
	ft_use_func_with_arr_of_ptr(ft_two_add_and_four_del_str);
	ft_use_func_with_arr_of_ptr(ft_valid_get_of_ptr);
	ft_use_func_with_arr(ft_valid_get);
	ft_use_func_with_arr(ft_valid_del);
	ft_use_func_with_arr_of_ptr(ft_valid_del_of_ptr);
	ft_use_func_with_arr_of_ptr(ft_for_each_elems_use_func_of_ptr);
	ft_use_func_with_arr_of_ptr(ft_while_arr_get_next);
	ft_use_func_with_arr(ft_init_arr_by_one);
//	ft_use_func_with_list(ft_one_push_str);
//	ft_use_func_with_list(ft_one_pop_str);
//	ft_use_func_with_list(ft_one_push_and_pop_str);
//	ft_use_func_with_list(ft_three_push_and_two_pop_str);
//	ft_use_func_with_list(ft_three_push_and_four_pop_str);

//	ft_use_func_with_list(ft_one_dpush_str);
/*	ft_use_func_with_list(ft_one_dpush_and_dpop_str);
	ft_use_func_with_list(ft_for_each_elems);
	ft_use_func_with_list(ft_for_each_elems_use_func);
	ft_use_func_with_list(ft_get_elems3);
	ft_use_func_with_list(ft_get_elems4);
	ft_use_func_with_list(ft_del_elems);*/
/*	ft_use_func_with_list();
	ft_use_func_with_list();
	*/
	ft_putstr("end\n");
	return (0);
}
