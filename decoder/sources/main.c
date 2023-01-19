/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:02:58 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 17:47:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

t_data	*g_data;

int main(void)
{	
	unsigned char		*text_elem;
	size_t				*frequency;
	size_t				frequency_size;
	t_tree				**huffman;
	u_int8_t			*bit_array;

	set_global_data();
	sem_wait(g_data->sem_full);
	text_elem = (unsigned char *)strdup(g_data->memory_block);
	sem_post(g_data->sem_empty);
	
	sem_wait(g_data->sem_full);
	frequency_size = strlen((char *)text_elem) + EXTRA_ELEM_BIT_ARRAY_LEN;
	frequency = malloc(sizeof(size_t) * frequency_size);
	memmove(frequency, g_data->memory_block, frequency_size * sizeof(size_t));
	g_data->bit_array_len = frequency[frequency_size - 1];
	huffman = set_tree(text_elem, frequency);
	sem_post(g_data->sem_empty);
	
	sem_wait(g_data->sem_full);
	bit_array = calloc(g_data->bit_array_len, sizeof(char));
	memmove(bit_array, g_data->memory_block, g_data->bit_array_len);
	g_data->text = decompress_text(huffman, bit_array);
	printf("Decoder: %s\n", g_data->text);
	sem_post(g_data->sem_empty);
	clear_global_data();
}
