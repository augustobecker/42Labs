/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:12:42 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 14:11:47 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_ARRAY_H
# define BIT_ARRAY_H

#include "decoder.h"

# define    SET_BIT(BF, N) BF |= ((u_int64_t)0x0000000000000001 << N)
# define    CLR_BIT(BF, N) BF &= ~((u_int64_t)0x0000000000000001 << N)
# define    IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

//memory
u_int8_t	*bit_array_new(unsigned int length);
int			bit_array_space(unsigned int data_length);
void		bit_array_clear(u_int8_t *bit_array, unsigned int length);

//populate
u_int8_t    *convert_str_to_bit_array(const char *str);

//functionalities
void 		unset_bits(u_int8_t *bits);
void 		set_bits(u_int8_t *bits, const char *str);
void		print_bit_array(u_int8_t *bit_array, unsigned int length);
size_t      bit_array_length(u_int8_t *bit_array, unsigned char *end_code);

#endif