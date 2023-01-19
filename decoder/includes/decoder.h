/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:44:40 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/15 16:26:24 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <sys/shm.h>
# include <pthread.h>
# include <fcntl.h> 
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "defines.h"
# include "types.h"
# include "t_tree.h"
# include "t_list.h"
# include "bit_array.h"


extern t_data *g_data;

//utils
unsigned char	*ft_strappend_char(unsigned char **str, const unsigned char c);
unsigned char	*ft_strappend(unsigned char **s1, unsigned const char *s2);
bool            is_whitespace(char c);
void            print_whitespace(char whitespace);

//decompress
unsigned char	*decompress_text(t_tree **huffman, u_int8_t *bit_array);

// semaphore
sem_t		*set_semaphore(char *sem_name, int value);

//shared mem
void		*get_shared_memory_block(char *filename, int size);
int			open_memory_block(char *filename, int size);
void 		*attach_memory_block(int shared_block_id);
void		detach_memory_block(char *mem_block);
void		destroy_memory_block(char *filename);
void		write_to_shared_memory(const void *content, size_t content_size);

//error
int			error_msg(t_error exit_code, const char *function_name);
void		bad_usage_msg(const char *function_name);

//time
long int	get_elapsed_time(struct timeval *start);
void	    start_counting_time(struct timeval *timer);

//global
void	    set_global_data(void);
void	    clear_global_data(void);

#endif