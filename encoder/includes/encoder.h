/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:57:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/12 15:03:55 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h> 
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "defines.h"
# include "types.h"
# include "t_list.h"
# include "t_tree.h"
# include "bit_array.h"

extern          t_data *g_data;

// initial validations
bool		    arguments_validation(int argc, char *const *argv);

// create
void		    *create(t_type type);
void		    data_clear(t_data *data);

// semaphores (to both)
sem_t		    *set_semaphore(char *sem_name, int value);

// read files
int             get_files_content(int argc, char **argv);

// huffman coding
t_list	        **huffman_coding(const unsigned char *text_to_encode);

// dictionary utils
void	        set_codes_to_dictionary(t_list **dictionary, t_tree **root);
unsigned char 	*parse_dictionary_to_str(t_list **dictionary);
size_t          *get_frequency_array(t_list **head);

// compress_text                                                                         
u_int8_t	    *compress_text(t_list **dictionary);

// local shared mem
void		    write_to_shared_memory(const void *content, size_t content_size);
void		    *read_from_shared_memory(void *content);

//global data
void            set_global_data(void);
void        	clear_global_data(void);


// shared memory
void		    *get_shared_memory_block(char *filename, int size);
int			    open_memory_block(char *filename, int size);
void 		    *attach_memory_block(int shared_block_id);
void		    detach_memory_block(char *mem_block);
void		    destroy_memory_block(char *filename);

// error
int			    error_msg(t_error exit_code, char *function_name);
void		    bad_usage_msg(const char *function_name);

// string utils
unsigned char	*ft_strappend_char(unsigned char **str, const unsigned char c);
unsigned char	*ft_strappend(unsigned char **s1, unsigned const char *s2);

// utils
bool            is_whitespace(unsigned const char c);
void            print_whitespace(unsigned char whitespace);

#endif