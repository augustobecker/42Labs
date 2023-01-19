/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:44 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/14 21:37:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

sem_t	*set_semaphore(char *sem_name, int value)
{
	sem_t	*semaphore;

	semaphore = sem_open(sem_name, O_CREAT, S_IRWXU | S_IRWXG, value);
	if (semaphore == SEM_FAILED)
		error_msg(MALLOC_ERROR, "set_semaphore");
	return (semaphore);
}
