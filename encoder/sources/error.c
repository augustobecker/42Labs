/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:40:53 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/09 23:59:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int	error_msg(t_error exit_code, char *function_name)
{
    printf(GREY"encoder: "RESET);
    switch (exit_code)
    {
        case (MALLOC_ERROR):
            printf("malloc error: %s\n", function_name);
            break;
        case (OVER_BLOCK_SIZE):
            printf(HOW_TO_SET_MORE_SPACE);
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
