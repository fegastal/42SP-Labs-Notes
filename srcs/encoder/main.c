#include "encoder.h"

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

void destruir_arvore(No *raiz)
{
	if(raiz)
	{
		destruir_arvore(raiz->esq);
		destruir_arvore(raiz->dir);
		free(raiz);
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

//-------------- parte 7: Compactar -------------

void compactar(unsigned char str[])
{
	unsigned char mascara;
	unsigned char byte;

	FILE *arquivo = fopen("compactado.wg", "wb"); //write binary
	int i = 0;
	int j = 7;
	byte = 0;
	if(arquivo)
	{
		while(str[i] != '\0')
		{
			mascara = 1;
			if(str[i] == '1')
			{
				mascara = mascara << j;
				byte = byte | mascara;
			}
			j--; // j precisa decrementar porque começou com 7
			if(j < 0) // tem um byte formado
			{
				fwrite(&byte, sizeof(unsigned char), 1, arquivo);
				byte = 0; // toda vez que escrevemos 1 byte em um arquivo ele volta para 7
				j = 7;
			}
			i++;
		}
		// existe 1 bit pela metade ou foi finalizado certinho?
		if(j != 7) // existe um byte em formação (?)
			fwrite(&byte, sizeof(unsigned char), 1, arquivo);
		fclose(arquivo);
	}
	else
		printf("\nErro ao abrir / criar arquivo em compactar\n");
}

//-------------- parte 8: Descompactar --------------

unsigned int eh_bit_um(unsigned char byte, int i)
{
	unsigned char mascara;

	mascara = (1 << i); // 00000001
	return byte & mascara; // 10000000
}

/*
	O retorno é zero ou maior que zero, se o bit mais à esquerda
	for 1, o retorno será 128 que é 10000000 em binário
*/
void descompactar(No *raiz)
{
	FILE *arquivo = fopen("compactado.wg", "rb"); //read binary
	No *aux = raiz;
	unsigned char byte; // 10111001
	int i;

	if(arquivo)
	{
		while(fread(&byte, sizeof(unsigned char), 1, arquivo))
		{
			for(i= 7; i >= 0; i--)
			{
				if(eh_bit_um(byte, i))
					// então quando for 1, precisamos caminhar para a direita
					// portanto, precisamos do nosso ponteiro para caminhar na arvore
					aux = aux->dir;
				else
					aux = aux->esq;
				if(aux->esq == NULL && aux->dir == NULL)
				{
					// aqui, significa que estamos em uma folha da nossa árvore
					printf("%c", aux->caracter);
					aux = raiz;
				}
			}
		}
		fclose(arquivo);
	}
	else
		printf("\nErro ao abrir arquivo em descompactar\n");
}

int	descobrir_tamanho()
{
	FILE *arq = fopen("teste.txt", "r");
	int tam = 0;

	if(arq)
	{
		while(fgetc(arq) != -1)
			tam++;
		fclose(arq);
	}
	else
		printf("\nErro ao abrir arquivo em descobrir_tamanho\n");
	return tam;
}

void ler_texto(unsigned char *texto)
{
	FILE *arq = fopen("teste.txt", "r");
	char letra;
	int i = 0;

	if(arq)
	{
		while(!feof(arq))
		{
			letra = fgetc(arq);
			if(letra != -1)
			{
				texto[i] = letra;
				i++;
			}
		}
		fclose(arq);
	}
	else
		printf("\nErro ao abrir arquivo em ler_texto\n");
}

//-------------- MAIN ----------------------------

int	main()
{
	//unsigned char	texto[] = "Vamos aprender programação";
	unsigned char	*texto;
	unsigned int	tabela_frequencia[TAM];
	Lista lista;
	No *arvore;
	int colunas;
	int tam;
	char **dicionario;
	unsigned char *codificado;
	unsigned char *decodificado;

	setlocale(LC_ALL, "utf8");

	tam = descobrir_tamanho();
	printf("\nQuantidade: %d\n", tam);

	texto = calloc(tam + 2, sizeof(unsigned char));
	ler_texto(texto);
	//printf("\nTEXTO:\n%s\n", texto);

	//-------------- parte 1: Tabela de frequência --------------
	inicializa_tabela_com_zero(tabela_frequencia);
	preenche_tab_frequencia(texto, tabela_frequencia);
	//imprime_tab_frequencia(tabela_frequencia);

	//-------------- parte 2: Lista encadeada ordenada  ---------
	criar_lista(&lista);
	preencher_lista(tabela_frequencia, &lista);
	//imprimir_lista(&lista);

	//-------------- parte 3: Montar a Árvore de Huffman  ---------
	arvore = montar_arvore(&lista);
	printf("\n\tÁrvore de Huffman\n");
	//imprimir_arvore(arvore, 0);

//-------------- parte 4: Montar o dicionário ---------
	colunas = altura_arvore(arvore) + 1;
	dicionario = aloca_dicionario(colunas);
	//printf("\n\tDicionário\n");
	gerar_dicionario(dicionario, arvore, "", colunas);
	//imprime_dicionario(dicionario);

//-------------- parte 5: Codificar---------
	codificado = (unsigned char *) codificar(dicionario, texto);
	printf("\n\tTexto codificado: %s\n", codificado);

//-------------- parte 6: Decodificar---------
	decodificado = (unsigned char *) decodificar(codificado, arvore);
	printf("\n\tTexto decodificado: %s\n", decodificado);

//-------------- parte 7: Compactar ---------
	compactar(codificado);

//-------------- parte 8: Descompactar --------
	printf("\nARQUIVO DESCOMPACTADO!\n");
	descompactar(arvore);
	printf("\n\n");

	free(texto);
	free(codificado);
	free(decodificado);

	return 0;
}
