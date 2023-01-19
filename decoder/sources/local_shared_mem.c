/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_shared_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:04:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 13:26:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	write_to_shared_memory(const void *content, size_t content_size);

void	write_to_shared_memory(const void *content, size_t content_size)
{
	if (content_size > BLOCK_SIZE)
		error_msg(OVER_BLOCK_SIZE, "write_to_shared_memory");
	sem_wait(g_data->sem_empty);
	memset(g_data->memory_block, 0, BLOCK_SIZE);
	memmove(g_data->memory_block, content, content_size);
	sem_post(g_data->sem_full);
}
