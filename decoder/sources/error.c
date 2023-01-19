/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:38:43 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/14 21:33:38 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int		error_msg(t_error exit_code, const char *function_name);
void	bad_usage_msg(const char *function_name);

int	error_msg(t_error exit_code, const char *function_name)
{
	printf(GREY"encoder: "RESET);
	switch (exit_code)
	{
		case (MALLOC_ERROR):
			printf("malloc error: %s\n", function_name);
			break;
		default:
			printf("error not documented : %s\n", function_name);
		break;
	}
	exit(exit_code);
}

void bad_usage_msg(const char *function_name)
{
	printf(GREY"Encoder: %s : bad usage\n"RESET, function_name);
}
