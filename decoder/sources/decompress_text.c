/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:02:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 14:14:43 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

unsigned char	*decompress_text(t_tree **huffman, u_int8_t *bit_array)
{
	t_tree			*node;
	unsigned char	*text;
	size_t	bit;
	size_t	i;
	
	i = 0;
	bit = 0;
	text = (unsigned char *)strdup("");
	node = *huffman;
	while (1)
	{
		if (IS_BIT_SET(bit_array[i], bit))
		{
			if (node->right)
				node = node->right;
			else
			{
				if (node->c == END_OF_BIT_ARRAY)
					return (text);
				if (node->c)
				{
					text = ft_strappend_char(&text, node->c);
					node = *huffman;
					bit--;
				}
			}
		}
		else
		{
			if (node->left)
				node = node->left;
			else
			{
				if (node->c == END_OF_BIT_ARRAY)
					return (text);
				if (node->c)
				{
					text = ft_strappend_char(&text, node->c);
					node = *huffman;
					bit--;
				}
			}
		}
		++bit;
		if (bit == BITS_IN_A_BYTE)
		{
			i++;
			bit = 0;
		}
	}
	return (text);
}
