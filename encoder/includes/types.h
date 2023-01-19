/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:41:53 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/13 17:41:53 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "encoder.h"

typedef enum e_error
{
	NO_ERROR,
	MALLOC_ERROR,
	OVER_BLOCK_SIZE,
	IPC_RESULT_ERROR,
	IPC_CREAT_ERROR,
	IPC_OPEN_ERROR,
	IPC_KEY_ERROR,
	IPC_ATTACH_ERROR,
	IPC_DETACH_ERROR,
	IPC_DESTROY_ERROR,
	SEMAPHORE_FAILED
}	t_error;

typedef enum e_type
{
	NONE,
	LIST,
	TREE,
	DATA
}	t_type;

typedef struct s_list
{
	unsigned char	c;
	size_t			frequency;
	unsigned char	*code;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_tree
{
	unsigned char	c;
	size_t			frequency;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*next;
	struct s_tree	*prev;
}	t_tree;

typedef struct s_data
{
	unsigned char	*text;
	char			*memory_block;
	sem_t 			*sem_empty;
	sem_t 			*sem_full;
	size_t			bit_array_len;
}	t_data;

#endif