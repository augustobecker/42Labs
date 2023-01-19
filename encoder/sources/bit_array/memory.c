/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:07:25 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/13 02:35:41 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

u_int8_t	*bit_array_new(unsigned int length);
int		    bit_array_space(unsigned int data_length);
void		bit_array_clear(u_int8_t *bit_array, unsigned int length);

u_int8_t	*bit_array_new(unsigned int length)
{
	u_int8_t	*bit_array;

	bit_array = calloc(length, sizeof(u_int8_t));
	if (!bit_array)
		error_msg(MALLOC_ERROR, "bit_array_new");
	return (bit_array);
}

int		bit_array_space(unsigned int data_length)
{
	unsigned int	bytes_necessary;

	bytes_necessary = data_length / BITS_IN_A_BYTE;
	if (data_length % BITS_IN_A_BYTE)
		bytes_necessary++;
	return (bytes_necessary);
}

void	bit_array_clear(u_int8_t *bit_array, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		unset_bits(&bit_array[i]);
		i++;
	}
	free(bit_array);
}
