/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:10:54 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/14 21:05:54 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

u_int8_t    *convert_str_to_bit_array(const char *str);

u_int8_t	*convert_str_to_bit_array(const char *str)
{
	u_int8_t	*bit_array;
	int			array_len;
	int			i;

	i = 0;
	array_len = bit_array_space(strlen(str));
	bit_array = bit_array_new(array_len);
	while (i < array_len)
	{
		set_bits(&bit_array[i], &(str[i * 8]));
		i++;
	}
	return (bit_array);
}
