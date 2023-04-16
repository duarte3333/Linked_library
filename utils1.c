#include "linked_lib.h"
#include "stdlib.h"


/* Gera uma struct global que permite aceder
a t_array **a em qualquer funcao */
t_array	**__this(void)
{
	static t_array *a;

	return(&a);
}
//criada como static na stack por isso 
//nao desaparece depois de ser retornada
//consigo aceder sempre ao *t_array

/* Serve apenas para que uma dada lista
se iguale à list do this() */
t_array	*array(void *lst)
{
	*(__this()) = lst;
	return (*__this());
}

/* Adiciona um novo elemento ao array */
void	__add(void *content)
{	
	t_elem	*elem;

	elem = (t_elem *)calloc(sizeof(t_elem), 1);
	if (!elem)
		return (NULL);
	elem->content = content;
	if (!(*__this())->begin)
		(*__this())->begin = elem;
	else
	{
		elem->previous = (*__this())->end;
		(*__this())->end->next = elem;
	}
	(*__this())->end = elem;
	
}

/* Elimina todos os elementos do array */
void __clear()
{
    t_elem *elem;
    t_elem *next;

    elem = (*__this())->begin;
    while (elem)
    {
        next = elem->next;
        free(elem->content);
        free(elem);
        elem = next;
    }
    (*__this())->begin = NULL;
    (*__this())->end = NULL; 
    (*__this())->size = 0;
}

void	__destroy(void (*f)(t_elem* , void*), void *o)
{
	
}

/* Retorna o indice do elemento na linked list */
int __get_index(t_elem *elem)
{
    int i;
    t_elem *current_elem;

    i = 0;
    current_elem = (*__this())->begin;
    while (current_elem)
    {
        if (current_elem == elem)
            return i;
        i++;
        current_elem = current_elem->next;
    }
    return -1;
}

void __del(t_elem *elem)
{
    if (elem)
    {

 		if (!elem->previous)
		{
			(*__this())->begin = elem->next;
			(*__this())->begin->previous = NULL;
		}
		else
		{
			elem->previous->next = elem->next;
			elem->next->previous = elem->previous;
		}
		free(elem->content);
        free(elem);
        (*__this())->size--;
    }
}


void __apply_all(void (*f)(t_elem* , void*), void *o)
{
    t_elem *elem;

    elem = (*__this())->begin;
    while (elem)
    {
        f(elem, o);
        elem = elem->next;
    }
}

void	*create_array(void)
{
	t_array *my_array = calloc(sizeof(t_array), 1);

    my_array->add = __add;
	//my_array->switch_elem = switch_elem;
	my_array->del = __del;
	my_array->clear = __clear;
	my_array->get_index = __get_index;
	my_array->apply_all = __apply_all;
	my_array->destroy = __destroy;
	return (my_array);
}
