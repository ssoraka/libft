
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

void	ft_use_func_with_list(int (*func)(t_llist *))
{
	static int num;

	t_llist *list;

	list = ft_create_llist(NULL);
	if (func)
		ft_print(num, func(list));
	else
		ft_print(num, SUCCESS);

	ft_del_llist(&list);
	if (list)
		ft_putstr("error\n");
	num++;
}

void	func_del_str(void *str)
{
	free(str);
}

int		ft_one_push_str(t_llist *list)
{
	char *str;
	int elems_count;

	str = ft_strdup("some text");
	elems_count = list->elems_count;
	ft_llist_push(list, str);
	if (list->start.next->elem == str && elems_count + 1 == list->elems_count)
		return (SUCCESS);
	return (FAIL);
}

int		ft_one_pop_str(t_llist *list)
{
	int answer;
	int count;
	void *ptr;
	void *first_elem;

	answer = FAIL;
	first_elem = NULL;
	if (list->start.next != &list->end)
		first_elem = list->start.next->elem;
	count = list->elems_count;
	ptr = ft_llist_pop(list);
	if (first_elem == ptr)
		answer = SUCCESS;
	if (count != list->elems_count + 1 && count + list->elems_count != 0)
		answer = FAIL;
	func_del_str(ptr);
	return (answer);
}

int		ft_one_push_and_pop_str(t_llist *list)
{
	ft_init_llist(list, &func_del_str);
	if (ft_one_push_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_three_push_and_two_pop_str(t_llist *list)
{
	ft_init_llist(list, &func_del_str);
	if (ft_one_push_str(list) == SUCCESS
	&& ft_one_push_str(list) == SUCCESS
	&& ft_one_push_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_three_push_and_four_pop_str(t_llist *list)
{
	ft_init_llist(list, &func_del_str);
	if (ft_one_push_str(list) == SUCCESS
	&& ft_one_push_str(list) == SUCCESS
	&& ft_one_push_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS
	&& ft_one_pop_str(list) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

int		ft_one_dpush_str(t_llist *list)
{
	int elems_count;
	char *str;

	str = ft_strdup("some text");
	elems_count = list->elems_count;
	ft_llist_dpush(list, str);
	if (list->end.prev->elem == str && elems_count + 1 == list->elems_count)
		return (SUCCESS);
	return (FAIL);
}

int		ft_one_dpop_str(t_llist *list)
{
	int count;
	int answer;
	void *ptr;
	void *last_elem;

	answer = FAIL;
	last_elem = NULL;
	if (list->end.prev != &list->start)
		last_elem = list->end.prev->elem;
	count = list->elems_count;
	ptr = ft_llist_pop(list);
	if (last_elem == ptr)
		answer = SUCCESS;
	if (count != list->elems_count + 1 && count + list->elems_count != 0)
		answer = FAIL;
	func_del_str(ptr);
	return (answer);
}

int		ft_one_dpush_and_dpop_str(t_llist *list)
{
	ft_init_llist(list, &func_del_str);
	if (ft_one_dpush_str(list) == SUCCESS
	&& ft_one_dpop_str(list) == SUCCESS)
		return (SUCCESS);
	return(FAIL);
}

void	ft_fill_list_by_arr_in_reverse_order(t_llist *list, int *arr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_llist_add(list, arr + count - i - 1);
		i++;
	}
}

void	ft_fill_list_by_arr(t_llist *list, int *arr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_llist_add(list, arr + i);
		i++;
	}
}

void	ft_fill_arr_by_index(int *arr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		arr[i] = i + 1;
		i++;
	}
}
int		ft_for_each_elems(t_llist *list)
{
	int i[3];
	int *ptr;
	int answer;

	i[0] = 3;
	i[1] = 2;
	i[2] = 1;
	ft_init_llist(list, NULL);
	ft_fill_list_by_arr_in_reverse_order(list, i, 3);

	answer = 0;
	while ((ptr = (int *)ft_llist_get_next(list)))
		answer = answer * *ptr + *ptr;
	if (answer != (1*2 + 2) * 3 + 3)
		return (FAIL);
	while ((ptr = (int *)ft_llist_get_next(list)))
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

int		ft_for_each_elems_use_func(t_llist *list)
{
	int i[3];
	int *ptr;
	int answer;

	answer = 0;
	i[0] = 3;
	i[1] = 2;
	i[2] = 1;
	ft_init_llist(list, NULL);
	ft_fill_list_by_arr_in_reverse_order(list, i, 3);
	ft_for_each_llist(list, ft_square_in_answer, &answer);
	if (answer == ((0 * 1 + 1) * 2 + 2) * 3 + 3)
		return (SUCCESS);
	return(FAIL);
}

int		ft_get_elems3(t_llist *list)
{
	int i[3];
	int *ptr;
	int answer;

	answer = 0;
	ft_fill_arr_by_index(i, 3);
	ft_init_llist(list, NULL);
	ft_fill_list_by_arr(list, i, 3);

	if (ft_llist_get(list, -1) == NULL
	&& ft_llist_get(list, 3) == NULL
	&& *((int *)ft_llist_get(list, 0)) == i[0]
	&& *((int *)ft_llist_get(list, 1)) == i[1]
	&& *((int *)ft_llist_get(list, 2)) == i[2])
		return (SUCCESS);

	return(FAIL);
}

int		ft_get_elems4(t_llist *list)
{
	int i[4];
	int *ptr;
	int answer;

	answer = 0;
	ft_fill_arr_by_index(i, 4);
	ft_init_llist(list, NULL);
	ft_fill_list_by_arr(list, i, 4);

	if (ft_llist_get(list, -1) == NULL
	&& ft_llist_get(list, 4) == NULL
	&& *((int *)ft_llist_get(list, 0)) == i[0]
	&& *((int *)ft_llist_get(list, 1)) == i[1]
	&& *((int *)ft_llist_get(list, 2)) == i[2]
	&& *((int *)ft_llist_get(list, 3)) == i[3])
		return (SUCCESS);

	return(FAIL);
}

int		ft_del_elems(t_llist *list)
{
	int i[4];
	int *ptr;
	int answer;

	answer = 0;
	ft_fill_arr_by_index(i, 4);
	ft_init_llist(list, NULL);
	ft_fill_list_by_arr(list, i, 4);

	ft_del_llist_elem(list, -1);
	ft_del_llist_elem(list, 4);
	if (*((int *)ft_llist_get(list, 0)) != i[0]
	|| *((int *)ft_llist_get(list, 3)) != i[3])
		return (FAIL);
	ft_del_llist_elem(list, 1);
	if (*((int *)ft_llist_get(list, 1)) != i[2])
		return (FAIL);
	ft_del_llist_elem(list, 1);
	if (*((int *)ft_llist_get(list, 1)) != i[3])
		return (FAIL);
	ft_del_llist_elem(list, 0);
	ft_del_llist_elem(list, 0);
	ft_del_llist_elem(list, 0);
	if (ft_llist_get(list, 0) == NULL)
		return (SUCCESS);
	return(FAIL);
}

int		main(int argc, char **argv)
{
	ft_putstr("start\n");

	ft_use_func_with_list(NULL);
	ft_use_func_with_list(ft_one_push_and_pop_str);
	ft_use_func_with_list(ft_three_push_and_two_pop_str);
	ft_use_func_with_list(ft_three_push_and_four_pop_str);
	ft_use_func_with_list(ft_one_dpush_and_dpop_str);
	ft_use_func_with_list(ft_for_each_elems);
	ft_use_func_with_list(ft_for_each_elems_use_func);
	ft_use_func_with_list(ft_get_elems3);
	ft_use_func_with_list(ft_get_elems4);
	ft_use_func_with_list(ft_del_elems);
/*	ft_use_func_with_list();
	ft_use_func_with_list();
	*/
	ft_putstr("end\n");
	return (0);
}
