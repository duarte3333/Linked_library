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
		(*__this())->begin->next = elem;
		(*__this())->begin->next->next = NULL;
	}
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
        free(elem);
        elem = next;
    }
    (*__this())->begin = NULL;
    (*__this())->end = NULL;
    (*__this())->size = 0;
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

void del(t_elem *elem)
{
    if (elem)
    {
        if (elem->previous)
            elem->previous->next = elem->next;
        else
            (*__this())->begin = elem->next;
        if (elem->next)
            elem->next->previous = elem->previous;
        else
            (*__this())->end = elem->previous;
        free(elem);
        (*__this())->size--;
    }
}


void __apply_all(void (*f)(t_elem *elem, void *o), void *o)
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
	t_array *my_array = array(calloc(sizeof(t_array), 1));

    my_array->__add = __add;
	//my_array->switch_elem = switch_elem;
	my_array->del = del;
	my_array->__clear = __clear;
	my_array->__get_index = __get_index;
	//my_array->__apply_all = __apply_all;
	return (my_array);
}
