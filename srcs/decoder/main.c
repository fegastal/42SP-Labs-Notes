#include "../../includes/decoder.h"

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
			printf("\t%d = %d = %c\n", i, tab[i], i);
	}
}

int	main()
{
	unsigned char	texto[] = "Vamos aprender a programar";
	unsigned int	tabela_frequencia[TAM];

	setlocale(LC_ALL, "Portuguese");

	//-------------- parte 1: tabela de frequência --------------
	inicializa_tabela_com_zero(tabela_frequencia);
	preenche_tab_frequencia(texto, tabela_frequencia);
	imprime_tab_frequencia(tabela_frequencia);

	return 0;
}
