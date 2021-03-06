/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_mass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:13:28 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/26 10:13:29 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_mass(int ***arr, int row)
{
	int		i;

	i = 0;
	if (arr == 0 || *arr == 0)
		return ;
	while (i < row)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}
