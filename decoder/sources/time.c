/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:10:39 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 16:44:21 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

long int	get_elapsed_time(struct timeval *start);
void	    start_counting_time(struct timeval *timer);

long int	get_elapsed_time(struct timeval *start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec - (*start).tv_sec) * SECND_TO_MILLISECND) \
	+ (current.tv_usec - (*start).tv_usec) / MICRO_TO_MILLISECND);
}

void	start_counting_time(struct timeval *timer)
{
	gettimeofday(timer, NULL);
}