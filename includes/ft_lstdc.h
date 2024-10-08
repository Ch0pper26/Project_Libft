/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:04:13 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/26 15:53:41 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTDC_H
# define FT_LSTDC_H

typedef struct s_lstdc	t_lstdc;

struct	s_lstdc
{
	int		index;
	void	*data;
	t_lstdc	*next;
	t_lstdc	*prev;
};

/* ft_create_lstdc */
t_lstdc	*ft_create_one(int index, void	*data);
t_lstdc	*ft_create_lstdc(int nb_elem, void **data, char type);
/* ft_free_lstdc */
void	ft_free_lstdc(t_lstdc **lstdc);
void	ft_destroy_link(t_lstdc **lstdc, int index);
void	ft_destroy_links(t_lstdc **lstdc, int *index, int lenght);
void	ft_destroy_slot(t_lstdc **lstdc, int start, int end);
void	ft_destroy_utils(t_lstdc **lstdc, int index);
/* ft_add_lstdc */
void	ft_add_front(t_lstdc **lstdc, void *data);
void	ft_add_back(t_lstdc **lstdc, void *data);
void	ft_add_index(t_lstdc **lstdc, void *data, int index);
void	ft_add_elem(t_lstdc **lstdc, t_lstdc *elem, int index);
/* ft_print_lstdc */
void	ft_print_one(t_lstdc *lstdc, char type);
void	ft_print_lstdc(t_lstdc **lstdc, char type);
void	ft_rev_print_lstdc(t_lstdc **lstdc, char type);
void	ft_check_print(t_lstdc **lstdc, char type);
/* ft_anything_to_void */
void	**ft_itovv(int	*nb);
void	**ft_ctovv(char	*c);
void	**ft_stovv(char	**tab);
/* ft_void_to_anything */
int		*ft_vvtoi(void **tab);
char	*ft_vvtoa(void **tab);
char	**ft_vvtos(void **tab);
/* ft_index_lstdc */
t_lstdc	*ft_check_index(t_lstdc **lstdc, int shift);
void	ft_fix_index(t_lstdc **lstdc, int shift);
void	ft_shift_index(t_lstdc **lstdc, int shift);
/* ft_move_in_lstdc */
void	ft_move_one(t_lstdc **lstdc);
void	ft_move_lstdc(t_lstdc **lstdc, int move);
void	ft_back_one(t_lstdc **lstdc);
void	ft_back_lstdc(t_lstdc **lstdc, int back);
void	ft_go_to(t_lstdc **lstdc, int where);
/* ft_get_lstdc */
int		ft_get_len_lstdc(t_lstdc **lstdc);
void	*ft_get_data(t_lstdc **lstdc, int index);
/* ft_move_elem_lstdc */
void	ft_move_to(t_lstdc **lstdc, int index_1, int index_2);
void	ft_swap_data(t_lstdc **lstdc, int index_1, int index_2);
/* ft_merge_lstdc */
void	ft_merge_lstdc(t_lstdc **lstdc1, t_lstdc **lstdc2);
/* ft_int_lstdc */
t_lstdc	*ft_create_int_lstdc(int nb_elem, int *data);
void	ft_add_int(t_lstdc **lstdc, int elem, int index);
int		ft_get_int(t_lstdc **lstdc, int index);
int		*ft_get_ints(t_lstdc **lstdc, int *index, int nb_elem);
int		ft_change_int(t_lstdc **lstdc, int data, int index);
/* ft_str_lstdc */
t_lstdc	*ft_create_str_lstdc(char **data, int nb_elem);
void	ft_add_str(t_lstdc **lstdc, char *elem, int index);
char	*ft_get_str(t_lstdc **lstdc, int index);
char	**ft_get_strs(t_lstdc **lstdc, int *index, int nb_elem);
char	*ft_change_str(t_lstdc **lstdc, char *data, int index);
/* ft_char_lstdc */
t_lstdc	*ft_create_char_lstdc(char *data, int nb_elem);
void	ft_add_char(t_lstdc **lstdc, char elem, int index);
char	ft_get_char(t_lstdc **lstdc, int index);
char	*ft_get_chars(t_lstdc **lstdc, int *index, int nb_elem);
char	ft_change_char(t_lstdc **lstdc, char data, int index);

#endif
