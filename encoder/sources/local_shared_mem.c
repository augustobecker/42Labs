/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_shared_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:04:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 17:42:38 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	write_to_shared_memory(const void *content, size_t content_size);
void    *read_from_shared_memory(void *content);

void	write_to_shared_memory(const void *content, size_t content_size)
{
	if (content_size > BLOCK_SIZE)
		error_msg(OVER_BLOCK_SIZE, "write_to_shared_memory");
	sem_wait(g_data->sem_empty);
	memset(g_data->memory_block, 0, BLOCK_SIZE);
	memmove(g_data->memory_block, content, content_size);
	sem_post(g_data->sem_full);
}

void    *read_from_shared_memory(void *content)
{
	sem_wait(g_data->sem_full);
	memmove(content, g_data->memory_block, BLOCK_SIZE);
	sem_post(g_data->sem_empty);
	return (content);
}
