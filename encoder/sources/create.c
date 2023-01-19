/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:37:39 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/10 02:55:42 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void			*create(t_type type);
static t_data	*data_new(void);
void			data_clear(t_data *data);

void	*create(t_type type)
{
	switch (type)
	{
		case (DATA):
			return ((void *)data_new());
		case (LIST):
			return ((void *)list_new());
		case (TREE):
			return ((void *)root_new());
		default:
			bad_usage_msg("create");
			return (NULL);
	}
}

static t_data	*data_new(void)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		error_msg(MALLOC_ERROR, "data_new");
	new->bit_array_len = 0;
	return (new);
}

void	data_clear(t_data *data)
{
	free(data->text);
	free(data);
}
