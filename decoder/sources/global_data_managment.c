/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_data_managment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:25:49 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 16:26:12 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	set_global_data(void);
void	clear_global_data(void);

void	set_global_data(void)
{
	g_data = malloc(sizeof(t_data));
	g_data->text = NULL;
	g_data->memory_block = \
	get_shared_memory_block(FILENAME_MEM_BLOCK, BLOCK_SIZE);
	g_data->sem_empty = set_semaphore(SEM_EMPTY_NAME, 1);
	g_data->sem_full = set_semaphore(SEM_FULL_NAME, 0);
	g_data->bit_array_len = 0;
}

void	clear_global_data(void)
{
	g_data->text = NULL;
	detach_memory_block(g_data->memory_block);
	g_data->memory_block = NULL;
	sem_close(g_data->sem_empty);
	sem_close(g_data->sem_full);
	g_data->bit_array_len = 0;
	free(g_data->text);
}