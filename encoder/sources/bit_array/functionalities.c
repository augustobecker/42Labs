/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionalities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:10:11 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 15:12:55 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void 		unset_bits(u_int8_t *bits);
void 		set_bits(u_int8_t *bits, const unsigned char *str);
void		print_bits(u_int8_t *bits);
void		print_bit_array(u_int8_t *bit_array, unsigned int length);

void unset_bits(u_int8_t *bits)
{
	int i;

	i = 0;
	while (i < BITS_IN_A_BYTE)
		CLR_BIT(*bits, i++);
}

void set_bits(u_int8_t *bits, const unsigned char *str)
{
	int	i;

	i = 0;
	while (i < BITS_IN_A_BYTE && str[i])
	{
		if (str[i] == RIGHT)
			SET_BIT(*bits, i);
		i++;
	}
}

void	print_bits(u_int8_t *bits)
{
	int i;

	i = 0;
	while (i < BITS_IN_A_BYTE)
	{
		if (IS_BIT_SET(*bits, i))
			printf("+");
		else
			printf("-");
		i++;
	}
}

void	print_bit_array(u_int8_t *bit_array, unsigned int length)
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		print_bits(&bit_array[i]);
		i++;
	}
	printf("\n");
}
