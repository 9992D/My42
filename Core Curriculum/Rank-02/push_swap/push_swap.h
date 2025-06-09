/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:51:20 by adenny            #+#    #+#             */
/*   Updated: 2025/06/09 23:24:54 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

void				rotate_b_to_max(t_stack *b, int max_pos);
void				push_back_to_a(t_stack *a, t_stack *b);
void				chunk_sort(t_stack *a, t_stack *b);
int					exit_and_cleanup(t_stack *a, t_stack *b, int status);
int					is_valid_number(const char *str);
int					has_duplicates(t_stack *a);
int					is_sorted(t_stack *a);
void				free_tab(char **tab);
int					check_args(int ac);
t_stack				*init_t_stack(void);
t_stack				*init_node_value(t_stack *stack, int value);
void				rank_init(t_stack *a);
int					init_stacks(t_stack **a, t_stack **b);
int					fill_stack(t_stack **a, t_stack *b, int ac, char **av);
int					reverse_rotate(t_stack *a);
int					rotate(t_stack *a);
int					push(t_stack *a, t_stack *b);
int					swap(t_stack *stack);
void				push_chunks_to_b(t_stack *a, t_stack *b, int num_chunks,
						double d_chunk_size);
void				compute_boundaries(int *params, double d_chunk_size,
						int *boundary, int *half_boundary);
void				push_next_chunk_element(t_stack *a, t_stack *b,
						int boundary, int half_boundary);
void				rotate_to_index(t_stack *a, int index);
void				init_chunk_params(t_stack *a, int *num_chunks,
						double *d_chunk_size);
int					ft_atoi(const char *str);
void				free_stack(t_stack *stack);
int					find_index_for_chunk(t_stack *a, int boundary);
int					check_and_prepare(t_stack **a, t_stack **b, int ac,
						char **av);
int					parse_and_fill_stack(t_stack **a, t_stack *b, int ac,
						char **av);
int					validate_and_convert(char *arg, t_stack **a, t_stack *b);
void				case_1(t_stack *a);
void				case_2(t_stack *a);
void				case_3(t_stack *a);
void				case_4(t_stack *a);
void				case_5(t_stack *a);
void				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
void				free_array(char **array, int count);
char				**ft_split(const char *s, char c);
int					count_words(const char *s, char c);
int					run_push_swap(t_stack *a, t_stack *b);

#endif