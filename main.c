#include <stdio.h>
#include <stdlib.h>
#include "linked_lib.h"

void print_int_elem(t_elem *elem, void *o)
{
    printf("%d ", *((int *)elem->content));
}

void print_elem(t_elem *elem) {
    if (elem != NULL) {
        printf("Content: %p\n", elem->content);
    } else {
        printf("Element is NULL\n");
    }
}

void print_list(void) {
    if ((*__this()) == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List contents:\n");
    t_elem *current = (*__this());
    while (current != NULL) {
        printf("%i \n", *(int *)current->content);
        current = current->next;
    }
    printf("\n");
}

int main()
{
	t_array *my_array;

	my_array = array(create_array());

    int *elem1 = malloc(sizeof(int));
    *elem1 = 10;
    my_array->__add(elem1);
	printf("[content] %i\n", *(int *)(my_array->begin->content));

    int *elem2 = malloc(sizeof(int));
    *elem2 = 20;
    my_array->__add(elem2);
	printf("[content] %i\n", *(int *)(my_array->begin->next->content));

    int *elem3 = malloc(sizeof(int));
    *elem3 = 30;
    my_array->__add(elem3);
	printf("[content] %i\n", *(int *)(my_array->begin->next->content));

    printf("Array contents:\n");
	print_list();
    //my_array->__apply_all(print_elem, NULL);

    // printf("Switching elements 1 and 3...\n");
    // my_array->switch_elem(my_array->begin, my_array->end);

    // printf("Array contents after switching:\n");
    // my_array->__apply_all(print_elem, NULL);

    printf("Deleting element 2...\n");
    t_elem *elem_to_delete;
	elem_to_delete = my_array->__get_index(my_array->begin->next);
    my_array->del(elem_to_delete);

    printf("Array contents after deleting:\n");
	print_list();
    //my_array->__apply_all(print_elem, NULL);

    printf("Clearing array...\n");
    my_array->__clear();

    return 0;
}

// t_list	*state(t_list *copy)
// {
// 	printf("\nSou local e aponto para nó 1 também -----\n");
// 	printf("Meu endereço é: %p\n", (&copy));
// 	copy->content = 20;
// 	return (copy);
// }

// //aponto para o segundo - será o futuro primeiro
// //dou free do primeiro
// //coloco o list a apontar para o novo primeiro
// void	ft_free_list(t_list *list)
// {
// 	t_list	*temp;

// 	while (list)
// 	{
// 		temp = list->next;
// 		free(list);
// 		list = temp;
// 	}
// }

// void	change_int(int a, int b, int *c, int *d)
// {
// 	//a = 6; só muda localmente
// 	//b = 7; só muda localmente
// 	//*c = 6; muda na heap
// 	//*d = 7; muda na stack
// 	printf ("\nDe forma local ---------\n");
// 	printf("Conteudo int a: %i\n", (a));
// 	printf("Morada a: %p\n", &(a));
// 	printf("Conteudo int b: %i\n", (b));
// 	printf("Morada b: %p\n", &(b));
// 	printf("Conteudo int c: %p\n", (a));
// 	printf("Morada c: %p\n", &(a));
// 	printf("Conteudo int d: %p\n", (b));
// 	printf("Morada d: %p\n", &(b));
// }

// int	main()
// {
// 	t_list	*a;
// 	t_list	*temp;
// 	int		b;
// 	int		aa;
// 	int		bb;
// 	int		*cc;
// 	int		*dd;
// 	char *choices[3] = { "New Game", "Continue Game", "Exit" };
// 	char *str = "oi";

// 	printf("\nARRAY OF STRINGS\n");
// 	printf("Conteudo 1 elemento %c\n", **choices);
// 	printf("Conteudo 1 elemento %c\n", *(choices[0]));
// 	printf("Conteudo 1 elemento %c\n", choices[0][0]);
// 	printf("Conteudo 2 elemento %c\n", *((*choices) + 1));
// 	printf("Conteudo 2 elemento %c\n", *(choices[0] + 1));
// 	printf("Conteudo 2 elemento %c\n", choices[0][1]);
// 	printf("Conteudo 2 elemento %c\n", *str);



// 	aa = 5;
// 	bb = 10;
// 	cc = &(aa);
// 	dd = &(bb);
// 	printf("\nINTEIROS\n");
// 	printf("Conteudo int aa: %i\n", (aa));
// 	printf("Morada aa: %p\n", &(aa));
// 	printf("Conteudo int bb: %i\n", (bb));
// 	printf("Morada bb: %p\n", &(bb));
// 	printf("Conteudo int cc: %p\n", (cc));
// 	printf("Morada cc: %p\n", &(cc));
// 	printf("Conteudo int dd: %p\n", (dd));
// 	printf("Morada dd: %p\n", &(dd));
// 	change_int(aa, bb, cc, dd);
// 	printf("\nConteudo int aa: %i\n", (aa));
// 	printf("Morada aa: %p\n", &(aa));
// 	printf("Conteudo int bb: %i\n", (bb));
// 	printf("Morada bb: %p\n", &(bb));
// 	printf("Conteudo int cc: %p\n", (cc));
// 	printf("Morada cc: %p\n", &(cc));
// 	printf("Conteudo int dd: %p\n", (dd));
// 	printf("Morada dd: %p\n", &(dd));


// 	b = 10;
// 	a = ft_lstnew((int)b);
// 	printf("\nLISTAS\n");
// 	printf("Conteudo nó 1: %i\n", (a->content));
// 	printf("Meu endereço é: %p\n", (&a));
// 	a = state(a);
// 	printf("\nConteudo nó 1: %i\n", (a->content));
// 	printf("Meu endereço é: %p\n", (&a));
// 	ft_lstadd_back(&a, ft_lstnew((int)33));
// 	printf("\nConteudo nó 2: %i\n", (a->next->content));
// 	printf("Meu endereço é: %p\n", (&a));
// 	printf("Conteudo nó atual: %i\n", *(int *)(a));
// 	printf("Pointer do next: %p\n", (t_list *)(a));
// 	printf("Conteudo do next: %i\n", *(int *)(a->next));
// 	ft_lstadd_back(&a, ft_lstnew((int)9));
// 	printf("Conteudo do next: %i\n", *(int *)(a->next->next));
// 	ft_lstadd_back(&a, ft_lstnew((int)12));
// 	printf("Conteudo do next: %i\n", (int)(a->next->next->next->content));

// 	ft_free_list(temp);
// 	ft_free_list(a);
// }
