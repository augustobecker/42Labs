/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:05:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/14 20:38:45 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void		*get_shared_memory_block(char *filename, int size);
int			open_memory_block(char *filename, int size);
static int	get_shared_block_id(char *filename, int size);
void 		*attach_memory_block(int shared_block_id);
void		detach_memory_block(char *mem_block);
void		destroy_memory_block(char *filename);

void *get_shared_memory_block(char *filename, int size)
{
	void	*memory_block;
	int		block_id;

	block_id = open_memory_block(filename, size);
	memory_block = attach_memory_block(block_id);
	return (memory_block);
}

int	open_memory_block(char *filename, int size)
{
	int	shared_block_id;

	shared_block_id = get_shared_block_id(filename, size);
	if (shared_block_id == IPC_ERROR)
		error_msg(IPC_OPEN_ERROR, "create_memory_block");
	return (shared_block_id);
}

void *attach_memory_block(int shared_block_id)
{
	void *memory_block; // pointer to that memory block

	memory_block = shmat(shared_block_id, NULL, 0);
	if (memory_block == (void *) -1)
		error_msg(IPC_ATTACH_ERROR, "attach_memory_block");
	return (memory_block);
}

static int get_shared_block_id(char *filename, int size)
{
	key_t	key;

	key = ftok(filename, 0);
	if (key == IPC_ERROR)
		error_msg(IPC_KEY_ERROR, "get_shared_block");
	return (shmget(key, size, 0644 | IPC_CREAT));
}

void	detach_memory_block(char *mem_block)
{
	if (shmdt(mem_block) == IPC_ERROR)
		error_msg(IPC_DETACH_ERROR, "detach_memory_block");
}

void	destroy_memory_block(char *filename)
{
	int shared_block_id;
	int	was_destroyed;

	shared_block_id = get_shared_block_id(filename, 0);
	if (shared_block_id == IPC_ERROR)
		error_msg(IPC_OPEN_ERROR, "destroy_memory_block");
	was_destroyed = shmctl(shared_block_id, IPC_RMID, NULL);
	if (was_destroyed == IPC_ERROR)
		error_msg(IPC_DESTROY_ERROR, "destroy_memory_block");	
}
