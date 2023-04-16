/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:29:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/28 17:09:03 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIB_H
# define LINKED_LIB_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_elem t_elem;
typedef struct s_array t_array;

struct s_elem
{
	void	*content;
	t_elem	*previous;
	t_elem	*next;
};
	
struct s_array
{
	t_elem		*begin;
	t_elem		*end;
	int			size;
	void		(*switch_elem)(void *content);
	void		(*add)(void *content);
	void		(*del)(t_elem *elem);
	void		(*clear)(void);
	int			(*get_index)(t_elem *elem);
	void		(*apply_all)(void(*f)(t_elem *elem, void *o), void *o);
	void		(*destroy)(void(*f)(t_elem *elem, void *o);
};		

t_array	**__this(void);
t_array	*array(void *lst);
void	__add(void *content);
void 	__clear();
int 	__get_index(t_elem *elem);
void 	__apply_all(void (*f)(t_elem *elem, void *o), void *o);
void	__destroy(void (*f)(t_elem *elem, void *o), void *o);
void	*create_array(void);


// t_elem	*ft_lstnew(void *content);
// t_elem	*ft_lstlast(t_elem *lst);
// void	ft_lstadd_front(t_elem **lst, t_elem *new);
// void	ft_lstadd_back(t_elem **lst, t_elem *new);
// void	ft_lstdelone(t_elem *lst, void (*del)(void*));

#endif