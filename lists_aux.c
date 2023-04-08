#include "linked_lib.h"

// //Esta funcao cria um nó
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// //Esta funcao retorna o ultimo elemento de uma linked list
// t_list	*ft_lstlast(t_list *lst)
// {
// 	while (lst)
// 	{
// 		if (lst->next == NULL)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// //Esta funcao acrescenta um ultimo elemento na linked list
// //Ou seja, coloca o last->next a apontar para o new
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	if (lst)
// 	{
// 		if (*lst)
// 			ft_lstlast(*lst)->next = new;
// 		else
// 			*lst = new;
// 	}
// }

// //t_list **lst equivale a uma list de linked lists
// //Esta funcao adiciona um elemento ao inicio
// //da linked list, colocando o new->next a apontar
// //para o primeiro elemento da linked list recebida
// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	if (*lst)
// 		new->next = *lst;
// 	*lst = new;
// }

// //Esta funcao elimina um elemento da linked list
// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!del || !lst)
// 		return ;
// 	(*del)(lst->content);
// 	free(lst);
// }
