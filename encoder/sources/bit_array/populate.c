/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:10:54 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 16:00:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

u_int8_t    *convert_str_to_bit_array(const unsigned char *str);

u_int8_t	*convert_str_to_bit_array(const unsigned char *str)
{
	u_int8_t	*bit_array;
	size_t		i;

	i = 0;
	g_data->bit_array_len = bit_array_space(strlen((char *)str));
	bit_array = bit_array_new(g_data->bit_array_len);
	while (i < g_data->bit_array_len)
	{
		set_bits(&bit_array[i], &(str[i * BITS_IN_A_BYTE]));
		i++;
	}
	return (bit_array);
}
