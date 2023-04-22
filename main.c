#include <stdio.h>
#include <stdlib.h>
#include "linked_lib.h"

void print_int_elem(t_elem *elem, void *o)
{
	// printf("aqui\n");
    printf("%d \n", *(int *)elem->content);
}

void print_elem(t_elem *elem) {
    if (elem != NULL) {
        printf("Content: %p\n", elem->content);
    } else {
        printf("Element is NULL\n");
    }
}

int main()
{
	void *my_array;
	void *my_array2;

	my_array = create_array();
	my_array2 = create_array();

    int *elem1 = malloc(sizeof(int));
    *elem1 = 10;
    array(my_array)->add(elem1)->destroy = NULL;
	array(my_array2)->add(elem1);
	//array(my_array2)->begin->destroy = NULL;

	//array(my_array2)->add(elem1);
	//if (array(my_array)->begin)
		//printf("[content] %i\n", *(int *)(my_array->begin->content));
	//if (array(my_array2)->begin)
		//printf("[content2] %i\n", *(int *)(my_array2->begin->content));
    
	int *elem2 = malloc(sizeof(int));
    *elem2 = 20;
    array(my_array)->add(elem2);


    int *elem3 = malloc(sizeof(int));
    *elem3 = 30;
    array(my_array)->add(elem3);

    printf("Array contents my_array1:\n");
    array(my_array)->apply_all(print_int_elem, NULL);

    // printf("\nArray contents my_array2:\n");
    // array(my_array2)->apply_all(print_int_elem, NULL);

    // printf("Switching elements 1 and 3...\n");
    // my_array->switch_elem(my_array->begin, my_array->end);

    // printf("Array contents after switching:\n");
    // my_array->apply_all(print_elem, NULL);

    printf("\nDeleting element 2...\n");
    t_elem *elem_to_delete = array(my_array)->begin->next;
	
    printf("Array after delete contents my_array1:\n");
    array(my_array)->del_element(elem_to_delete);
	//array(my_array)->free_element(elem_to_delete);
	//printf("antes do apply--%p\n", (*__this())->begin);
	//printf("antes do apply--%d\n", *(int *)(*__this())->begin->content);
    array(my_array)->apply_all(print_int_elem, NULL);

    // printf("\nClearing array 1...\n");
    array(my_array)->free_all();
    // //printf("Clearing array 2...\n");
    array(my_array2)->free_all();
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

