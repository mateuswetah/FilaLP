#include <stdio.h>
#include <stdlib.h>

void vetAlloc(int n, int **V)
{
	*V = (*int)malloc(n*sizeof (int));
} 

void vetFree(int **V)
{
	free(*V);
}

void* lst_create(){}

void lst_append(void *lst, int v){}

int lst_insert(void *lst, size_t pos, int v){}

int lst_get(void *lst, size_t pos, int *v){}

int lst_remove(void *lst, size_t pos){}

size_t lst_size(void *lst){}

void lst_destroy(void *lst){}

int main()
{
	void *lst;
	int v;

	lst = lst_create(); // Cria a lista vazia: [ ]
	lst_insert(lst, 1, 11); // Erro, posicao invalida: retorna “0”
	lst_append(lst, 11); // [ ] -> [ 11 ]
	lst_append(lst, 5); // [ 11 ] -> [ 11, 5 ]
	lst_insert(lst, 2, 8); // [ 11, 5 ] -> [ 11, 8, 5 ]
	lst_insert(lst, 1, 7); // [ 11, 8, 5 ] -> [ 7, 11, 8, 5 ]
	lst_insert(lst, 10, 2); // Erro, posicao invalida: retorna "0"

	if (lst_get(lst, 3, &v) == 1) // Imprime 8
		printf(“v: %d\n”, v); 

	if (lst_get(lst, 6, &v) == 1) // Erro, posicao invalida: retorna “0”
		printf(“v: %d\n”, v); // Nao e executado

	lst_destroy(lst);
	
	return (0);
}
