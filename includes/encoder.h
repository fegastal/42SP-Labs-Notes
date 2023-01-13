// ======================== DEFINITIONS

#ifndef ENCODER_H
# define ENCODER_H

// ======================== MACROS

# define TAM 256

// ======================== INCLUDES

# include <unistd.h> // standard unix functions, like getpid(), write()
# include <stdlib.h> // exit()
# include <sys/types.h> //various type definitions, like pid_t
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <string.h>

// ======================== STRUCTS

typedef struct no{
	unsigned char caracter;
	int frequencia;
	struct no *esq;
	struct no *dir;
	struct no *proximo;
}No;

typedef struct lista{
	No *inicio;
	int tam;
}Lista;

// ======================== UTILS PROTOTYPES

void	inicializa_tabela_com_zero(unsigned int tab[]);
void	preenche_tab_frequencia(unsigned char texto[], unsigned int tab[]);
void	imprime_tab_frequencia(unsigned int tab[]);

#endif
