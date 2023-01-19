/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:16:30 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 15:12:29 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void					set_codes_to_dictionary(t_list **dictionary, t_tree **root);
static int				get_code_length(t_tree *node);
static unsigned char	*get_code(t_tree *node);
unsigned char 			*parse_dictionary_to_str(t_list **dictionary);
size_t					*get_frequency_array(t_list **head);

void	set_codes_to_dictionary(t_list **dictionary, t_tree **root)
{
	t_list	*item;
	t_tree	*node;

	item = *dictionary;
	if (*dictionary == NULL)
		return ;
	while (item)
	{
		node = find_node(*root, item->c);
		item->code = get_code(node);
		item = item->next;
	}
}

static unsigned char	*get_code(t_tree *node)
{
	t_tree			*ptr_i;
	t_tree			*next_ptr;
	unsigned char	*code;
	int		i;

	if (!node)
		return (NULL);
	next_ptr = node;
	ptr_i = next_ptr->prev;
	code = calloc(get_code_length(node) + 1, sizeof(char));
	if (!code)
		error_msg(MALLOC_ERROR, "get_code");
	i = get_code_length(node);
	while (ptr_i && i)
	{
		i--;
		if (next_ptr == ptr_i->right)
			code[i] = RIGHT;
		else
			code[i] = LEFT;
		next_ptr = next_ptr->prev;
		ptr_i = ptr_i->prev;
	}
	return (code);
}

static int	get_code_length(t_tree *node)
{
	t_tree	*ptr_i;
	int		length;

	if (!node)
		return (0);
	length = 0;
	ptr_i = node;
	while (ptr_i->prev)
	{
		ptr_i = ptr_i->prev;
		length++;
	}
	return (length);
}

unsigned char *parse_dictionary_to_str(t_list **dictionary)
{
	t_list			*ptr_i;
	unsigned char	*dictionary_str;

	if (*dictionary == NULL)
		return (NULL);
	ptr_i = *dictionary;
	dictionary_str = (unsigned char *)strdup("");
	while (ptr_i)
	{
		dictionary_str = ft_strappend_char(&dictionary_str, ptr_i->c);
		ptr_i = ptr_i->next;
	}
	return (dictionary_str);
}

size_t *get_frequency_array(t_list **head)
{
	size_t	*frequency;
	t_list *ptr_i;
	size_t len;
	size_t	i;

	i = 0;
	len = list_size(head);
	frequency = malloc(sizeof(size_t) * (len + EXTRA_ELEM_BIT_ARRAY_LEN));
	if (!frequency)
		error_msg(MALLOC_ERROR, "get_frequency_array");
	ptr_i = *head;
	while (ptr_i)
	{
		frequency[i] = ptr_i->frequency;
		i++;
		ptr_i = ptr_i->next;
	}
	frequency[i] = g_data->bit_array_len;
	return (frequency);
}