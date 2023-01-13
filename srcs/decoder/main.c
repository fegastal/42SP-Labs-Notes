#include "decoder.h"

/*
//-------------- parte 1: tabela de frequência --------------

void	inicializa_tabela_com_zero(unsigned int tab[]) 
{
	int i;

	for(i = 0; i < TAM; i++)
		tab[i] = 0;
}

void	preenche_tab_frequencia(unsigned char texto[], unsigned int tab[])
{
	int i = 0;

	while(texto[i] != '\0')
	{
		tab[texto[i]]++;
		i++;
	}
}

void imprime_tab_frequencia(unsigned int tab[])
{
	int i;

	printf("\tTABELA DE FREQUENCIA\n");
	for(i = 0; i < TAM; i++)
	{
		if(tab[i] > 0)
			printf("\t%d = %u = %c\n", i, tab[i], i);
	}
}

//-------------- parte 2: lista encadeada ordenada  ---------

void criar_lista(Lista *lista)
{
	lista->inicio = NULL;
	lista->tam = 0;
}

void inserir_ordenado(Lista *lista, No *no)
{
	No *aux;
	if(lista->inicio == NULL)
	{
		lista->inicio = no;
	}
	else if(no->frequencia < lista->inicio->frequencia)
	{
		no->proximo = lista->inicio;
		lista->inicio = no;
	}
	else
	{
		aux = lista->inicio;
		while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
			aux = aux->proximo;
		no->proximo = aux->proximo;
		aux->proximo = no;
	}
	lista->tam++;
}

void preencher_lista(unsigned int tab[], Lista *lista)
{
	int i;

	No *novo;
	for(i = 0; i < TAM; i++)
	{
		if(tab[i] > 0)
		{
			novo = malloc(sizeof(No));
			if(novo){
				novo->caracter = i;
				novo->frequencia = tab[i];
				novo->dir = NULL;
				novo->esq = NULL;
				novo->proximo = NULL;

				inserir_ordenado(lista, novo);
			}
			else
			{
				printf("\tErro ao alocar memória em preencher_lista");
				break;
			}
		}
	}
}

void imprimir_lista(Lista *lista)
{
	No *aux = lista->inicio;

	printf("\n\tLista ordenada: Tamanho: %d\n", lista->tam);
	while(aux)
	{
		printf("\tCaracter: %c Frequência: %d\n", aux->caracter, aux->frequencia);
		aux = aux->proximo;
	}
}

//-------------- parte 3: Montar a Árvore de Huffman ---------

No* remove_no_inicio(Lista *lista)
{
	No *aux = NULL;

	if(lista->inicio)
	{
		aux = lista->inicio;
		lista->inicio = aux->proximo;
		aux->proximo = NULL;
		lista->tam--;
	}

	return aux;
}

No* montar_arvore(Lista *lista)
{
	No *primeiro;
	No *segundo;
	No *novo;

	while(lista->tam > 1)
	{
		primeiro = remove_no_inicio(lista);
		segundo = remove_no_inicio(lista);
		novo = malloc(sizeof(No));

		if(novo)
		{
			novo->caracter = '+';
			novo->frequencia = primeiro->frequencia + segundo->frequencia;
			novo->esq = primeiro;
			novo->dir = segundo;
			novo->proximo = NULL;

			inserir_ordenado(lista, novo);
		}
		else
		{
			printf("\n\tErro ao alocar memória em montar_arvore!");
			break;
		}
	}
	return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam)
{
	if(raiz->esq == NULL && raiz->dir == NULL)
		printf("\tFolha: %c\t Altura: %d\n", raiz->caracter, tam);
	else
	{
		imprimir_arvore(raiz->esq, tam + 1);
		imprimir_arvore(raiz->dir, tam + 1);
	}
}

//-------------- parte 4: Montar o dicionário ---------

int altura_arvore(No *raiz)
{
	int esq;
	int dir;

	if(raiz == NULL)
		return -1;
	else
	{
		esq = altura_arvore(raiz->esq) + 1;
		dir = altura_arvore(raiz->dir) + 1;
		if(esq > dir)
			return esq;
		else
			return dir;
	}
}

char** aloca_dicionario(int colunas)
{
	char **dicionario;
	int i;

	dicionario = malloc(sizeof(char*) * TAM);

	for(i = 0; i < TAM; i++)
		dicionario[i] = calloc(colunas, sizeof(char));
	return dicionario;
}

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas)
{
	char esquerda[colunas];
	char direita[colunas];

	if(raiz->esq == NULL && raiz->dir == NULL)
	{
		strcpy(dicionario[raiz->caracter], caminho);
	}
	else 
	{
		// precisamos caminhar pela arvore inteira
		strcpy(esquerda, caminho);
		strcpy(direita, caminho);

		// aqui estou concatenando o 0 e 1
		strcat(esquerda,"0");
		strcat(direita, "1");

		gerar_dicionario(dicionario, raiz->esq, esquerda, colunas);
		gerar_dicionario(dicionario, raiz->dir, direita, colunas);
	}
}

void imprime_dicionario(char **dicionario)
{
	int i;

	for(i = 0; i < TAM; i++)
	{
		if(strlen(dicionario[i]) > 0)
			printf("\t%3d: %s\n", i, dicionario[i]);
	}
}

//-------------- parte 5: Codificar ----------

int calcula_tamanho_string(char ** dicionario, unsigned char *texto)
{
	int i;
	int tam;

	i = 0;
	tam = 0;
	while(texto[i] != '\0')
	{
		tam = tam + strlen(dicionario[texto[i]]);
		i++;
	}
	return tam + 1;
}

char* codificar(char ** dicionario, unsigned char *texto)
{
	int i;
	int tam;

	i = 0;
	tam = calcula_tamanho_string(dicionario, texto);
	char *codigo = calloc(tam, sizeof(char));
	while(texto[i] != '\0')
	{
		strcat(codigo, dicionario[texto[i]]);
		i++;
	}
	return codigo;
}

//-------------- parte 6: Decodificar ----------

char* decodificar(unsigned char texto[], No *raiz)
{
	int i = 0;

	No *aux = raiz;
	char temp[2];
	char *decodificado = calloc(strlen(texto), sizeof(char));

	while(texto[i] != '\0')
	{
		if(texto[i] == '0')
			aux = aux->esq;
		else
			aux = aux->dir;
		if(aux->esq == NULL && aux->dir == NULL)
		{
			temp[0] = aux->caracter;
			temp[1] = '\0';
			strcat(decodificado, temp);
			aux = raiz;
		}
		i++;
	}
	return decodificado;
}

//-------------- MAIN ----------------

int	main()
{
	unsigned char	texto[] = "Vamos aprender programação";
	unsigned int	tabela_frequencia[TAM];
	Lista lista;
	No *arvore;
	int colunas;
	char **dicionario;
	char *codificado;
	char *decodificado;

	setlocale(LC_ALL, "Portuguese");

	//-------------- parte 1: Tabela de frequência --------------
	inicializa_tabela_com_zero(tabela_frequencia);
	preenche_tab_frequencia(texto, tabela_frequencia);
	imprime_tab_frequencia(tabela_frequencia);

	//-------------- parte 2: Lista encadeada ordenada  ---------
	criar_lista(&lista);
	preencher_lista(tabela_frequencia, &lista);
	imprimir_lista(&lista);

	//-------------- parte 3: Montar a Árvore de Huffman  ---------
	arvore = montar_arvore(&lista);
	printf("\n\tÁrvore de Huffman\n");
	imprimir_arvore(arvore, 0);

//-------------- parte 4: Montar o dicionário ---------
	colunas = altura_arvore(arvore) + 1;
	dicionario = aloca_dicionario(colunas);
	printf("\n\tDicionário\n");
	gerar_dicionario(dicionario, arvore, "", colunas);
	imprime_dicionario(dicionario);

//-------------- parte 5: Codificar---------
	codificado = codificar(dicionario, texto);
	printf("\n\tTexto codificado: %s\n", codificado);

//-------------- parte 6: Decodificar---------
	decodificado = decodificar(codificado, arvore);
	printf("\n\tTexto decodificado: %s\n", decodificado);

	return 0;
}
*/

size_t	ft_strlen(const unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//-------------- parte 1: tabela de frequência --------------

void	inicializa_tabela_com_zero(unsigned int tab[]) 
{
	int i;

	for(i = 0; i < TAM; i++)
		tab[i] = 0;
}

void	preenche_tab_frequencia(unsigned char texto[], unsigned int tab[])
{
	int i = 0;

	while(texto[i] != '\0')
	{
		tab[texto[i]]++;
		i++;
	}
}

void imprime_tab_frequencia(unsigned int tab[])
{
	int i;

	printf("\tTABELA DE FREQUENCIA\n");
	for(i = 0; i < TAM; i++)
	{
		if(tab[i] > 0)
			printf("\t%d = %u = %c\n", i, tab[i], i);
	}
}

//-------------- parte 2: lista encadeada ordenada  ---------

void criar_lista(Lista *lista)
{
	lista->inicio = NULL;
	lista->tam = 0;
}

void inserir_ordenado(Lista *lista, No *no)
{
	No *aux;
	// a lista está vazia?
	if(lista->inicio == NULL)
	{
		// alterando o inicio da lista
		lista->inicio = no;
		//lista->tam++;

	}
	// pode ser que a lista não esteja vazia,
	// mas vamos inserir de forma ordenada
	// tem freq menor que o inicio da lista
	else if(no->frequencia < lista->inicio->frequencia)
	{
		no->proximo = lista->inicio;
		lista->inicio = no;
		//lista->tam++;
	}
	else
	{
		// criei um ponteiro auxiliar para o inicio da lista
		aux = lista->inicio;
		// o novo nó vai ficar antes e apos o aux
		while(aux->proximo && aux->proximo->frequencia <= no->frequencia)
			aux = aux->proximo;
		// conectar o novo nó na nossa lista
		no->proximo = aux->proximo;
		aux->proximo = no;
		//lista->tam++;
	}
	lista->tam++;
}

void preencher_lista(unsigned int tab[], Lista *lista)
{
	// precisamos percorrer essa tabela de 0 a 255
	// olhar qual posição é maior que 0 (frequência 1)
	int i;

	No *novo;
	for(i = 0; i < TAM; i++)
	{
		if(tab[i] > 0)
		{
			novo = malloc(sizeof(No));
			if(novo){
				novo->caracter = i;
				novo->frequencia = tab[i];
				novo->dir = NULL;
				novo->esq = NULL;
				novo->proximo = NULL;

				inserir_ordenado(lista, novo);
			}
			else
			{
				printf("\tErro ao alocar memória em preencher_lista");
				break;
			}
		}
	}
}

void imprimir_lista(Lista *lista)
{
	No *aux = lista->inicio;

	printf("\n\tLista ordenada: Tamanho: %d\n", lista->tam);
	while(aux)
	{
		printf("\tCaracter: %c Frequência: %d\n", aux->caracter, aux->frequencia);
		aux = aux->proximo;
	}
}

//-------------- parte 3: Montar a Árvore de Huffman ---------
No* remove_no_inicio(Lista *lista)
{
	No *aux = NULL;

	if(lista->inicio)
	{
		aux = lista->inicio;
		lista->inicio = aux->proximo;
		aux->proximo = NULL;
		lista->tam--;
	}

	return aux;
}

No* montar_arvore(Lista *lista)
{
	No *primeiro;
	No *segundo;
	No *novo;

	while(lista->tam > 1)
	{
		primeiro = remove_no_inicio(lista);
		segundo = remove_no_inicio(lista);
		novo = malloc(sizeof(No));

		if(novo)
		{
			novo->caracter = '+';
			novo->frequencia = primeiro->frequencia + segundo->frequencia;
			novo->esq = primeiro;
			novo->dir = segundo;
			novo->proximo = NULL;

			inserir_ordenado(lista, novo);
		}
		else
		{
			printf("\n\tErro ao alocar memória em montar_arvore!");
			break; // tbm poderia ser return null em vez de break
		}
	}
	return lista->inicio;
}

void imprimir_arvore(No *raiz, int tam)
{
	if(raiz->esq == NULL && raiz->dir == NULL)
		printf("\tFolha: %c\t Altura: %d\n", raiz->caracter, tam);
	else
	{
		imprimir_arvore(raiz->esq, tam + 1);
		imprimir_arvore(raiz->dir, tam + 1);
	}
}

//-------------- parte 4: Montar o dicionário ---------
int altura_arvore(No *raiz)
{
	int esq;
	int dir;

	// se a raiz for nula, chegamos a uma folha
	if(raiz == NULL)
		return -1;
	else
	{
		esq = altura_arvore(raiz->esq) + 1;
		dir = altura_arvore(raiz->dir) + 1;
		if(esq > dir)
			return esq;
		else
			return dir;
	}
}

char** aloca_dicionario(int colunas)
{
	char **dicionario;
	int i;

	dicionario = malloc(sizeof(char*) * TAM);

	for(i = 0; i < TAM; i++)
		// cada posição desse vetor irá apontar para outro vetor
		// ou seja, uma matriz
		// calloc aloca em uma região de memória 
		// e retorna o endereço dessa memória (limpa o que tem naquela
		// região de memória -> precisamos fazer isso porque
		// vamos ter que concatenar strings
		dicionario[i] = calloc(colunas, sizeof(char));
	return dicionario;
}

// aqui vou produzir o meu dicionário
// recebe meu dicionario / tabela como primeiro parametro
// procedimento recursivo: conforme eu for caminhando na minha
// arvore, p/ esquerda ou direita, eu vou concatenando em 0 ou 1
// ou seja, o caminho é o código do caractere até chegar em uma folha

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas)
{
	char esquerda[colunas];
	char direita[colunas];

	if(raiz->esq == NULL && raiz->dir == NULL)
	{
		// destino, caminho
		strcpy(dicionario[raiz->caracter], caminho);
	}
	else
	{
		// precisamos caminhar pela arvore inteira
		strcpy(esquerda, caminho);
		strcpy(direita, caminho);

		// aqui estou concatenando o 0 e 1
		strcat(esquerda,"0");
		strcat(direita, "1");

		gerar_dicionario(dicionario, raiz->esq, esquerda, colunas);
		gerar_dicionario(dicionario, raiz->dir, direita, colunas);
	}
}

void imprime_dicionario(char **dicionario)
{
	int i;

	for(i = 0; i < TAM; i++)
	{
		if(ft_strlen((unsigned char *) dicionario[i]) > 0)
			printf("\t%3d: %s\n", i, dicionario[i]);
	}
}

//-------------- parte 5: Codificar---------

/*
* texto[i] vai virar um número representado em ASCII
*/
int calcula_tamanho_string(char ** dicionario, unsigned char *texto)
{
	int i;
	int tam;

	i = 0;
	tam = 0;
	while(texto[i] != '\0')
	{
		tam = tam + ft_strlen((unsigned char *) dicionario[texto[i]]);
		i++;
	}
	return tam + 1;
}

/*
* Se, em um texto, eu tiver 35 caracteres, 
* eu preciso percorrer o meu dicionário procurando qual o tamanho de cada um desses caracteres
* Lembrando-se que acrescenta-se + 1 por causa do '\0' no final de string
*/
char* codificar(char ** dicionario, unsigned char *texto)
{
	int i;
	int tam;

	i = 0;
	tam = calcula_tamanho_string(dicionario, texto);
	// calloc recebe:
	// a quant de caracteres de um vetor
	// o tamanho de um caractere
	char *codigo = calloc(tam, sizeof(char));
	while(texto[i] != '\0')
	{
		strcat(codigo, dicionario[texto[i]]);
		i++;
	}
	return codigo;
}

//-------------- parte 6: Decodificar---------

char* decodificar(unsigned char texto[], No *raiz)
{
	int i = 0;

	No *aux = raiz;
	char temp[2];
	char *decodificado = calloc(ft_strlen(texto), sizeof(char));

	while(texto[i] != '\0')
	{
		if(texto[i] == '0')
			aux = aux->esq;
		else
			aux = aux->dir;
		if(aux->esq == NULL && aux->dir == NULL)
		{
			temp[0] = aux->caracter;
			temp[1] = '\0';
			strcat(decodificado, temp);
			aux = raiz;
		}
		i++;
	}
	return decodificado;
}

//-------------- MAIN ----------------

int	main()
{
	unsigned char	texto[] = "Vamos aprender programação";
	unsigned int	tabela_frequencia[TAM];
	Lista lista;
	No *arvore;
	int colunas;
	char **dicionario;
	unsigned char *codificado;
	unsigned char *decodificado;

	setlocale(LC_ALL, "utf8");

	//-------------- parte 1: Tabela de frequência --------------
	inicializa_tabela_com_zero(tabela_frequencia);
	preenche_tab_frequencia(texto, tabela_frequencia);
	imprime_tab_frequencia(tabela_frequencia);

	//-------------- parte 2: Lista encadeada ordenada  ---------
	criar_lista(&lista);
	preencher_lista(tabela_frequencia, &lista);
	imprimir_lista(&lista);

	//-------------- parte 3: Montar a Árvore de Huffman  ---------
	arvore = montar_arvore(&lista);
	printf("\n\tÁrvore de Huffman\n");
	imprimir_arvore(arvore, 0);

//-------------- parte 4: Montar o dicionário ---------
	colunas = altura_arvore(arvore) + 1;
	dicionario = aloca_dicionario(colunas);
	printf("\n\tDicionário\n");
	gerar_dicionario(dicionario, arvore, "", colunas);
	imprime_dicionario(dicionario);

//-------------- parte 5: Codificar---------
	codificado = (unsigned char *) codificar(dicionario, texto);
	printf("\n\tTexto codificado: %s\n", codificado);

//-------------- parte 6: Decodificar---------
	decodificado = (unsigned char *) decodificar(codificado, arvore);
	printf("\n\tTexto decodificado: %s\n", decodificado);

	return 0;
}