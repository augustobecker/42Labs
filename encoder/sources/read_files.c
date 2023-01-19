/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:39:45 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 15:01:01 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static unsigned char *read_file(char *filename);

int	get_files_content(int argc, char **argv)
{
	int		i;

	i = 1;
	g_data->text = (unsigned char *)strdup("");
	while (i < argc)
	{
		if (argv[i][0])
			if (!access(argv[i], F_OK | R_OK))
				g_data->text = ft_strappend(&g_data->text, read_file(argv[i]));
		i++;
	}
	return (NO_ERROR);
}

static unsigned char *read_file(char *filename)
{
	FILE 			*ptr;
	unsigned char	*content;
	unsigned char	*final;

	final = (unsigned char *)strdup("");
	content = malloc(sizeof(char) * BUFFER_SIZE);
	ptr = fopen(filename, "r");
	while (fgets((char *)content, BUFFER_SIZE, ptr))
		final = ft_strappend(&final, content);
	free(content);
    fclose(ptr);
	return (final);
}
