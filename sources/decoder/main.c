/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:13:23 by fgastal-          #+#    #+#             */
/*   Updated: 2022/11/13 05:22:06 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* main.c
* A simple file compressor using Huffman trees.
* @ver 0.4
* @autores: Fernanda Gastal
*/

#include "decoder.h"

//------------------------------- Utils Functions -------------------------------

/**
* The function ft_strlen was created to use strlen as a basis,
* but getting a const unsigned char *str instead of a const char.
* It is intended to return the size of a string.
*/
size_t	ft_strlen(const unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//--------------------------- Part 1: Frequency Table ---------------------------

/**
* Function that starts the table with the value zero.
*/
void	initialize_table_with_zero(unsigned int tab[]) 
{
	int i;

	for(i = 0; i < SIZE; i++)
		tab[i] = 0;
}

/**
* Function that fills the frequency table from the received text.
*/
void	fill_tab_frequency(unsigned char text[], unsigned int tab[])
{
	int i = 0;

	while(text[i] != '\0')
	{
		tab[text[i]]++;
		i++;
	}
}

/**
* Function that prints the frequency table from the received text.
*/
void print_tab_frequency(unsigned int tab[])
{
	int i;

	printf("\tFREQUENCY TABLE:\n");
	for(i = 0; i < SIZE; i++)
	{
		if(tab[i] > 0)
			printf("\t%d = %u = %c\n", i, tab[i], i);
	}
}

//------------------------- Part 2: Sorted Linked List  -------------------------

/**
* Function that creates an ordered list.
*/
void create_list(List *list)
{
	list->start = NULL;
	list->size = 0;
}

/**
* Function that inserts a node in an ordered linked list.
*/
void insert_ordered(List *list, Node *node)
{
	Node *aux;

	if(list->start == NULL)
	{
		list->start = node;
	}
	else if(node->frequency < list->start->frequency)
	{
		node->next = list->start;
		list->start = node;
	}
	else
	{
		aux = list->start;
		while(aux->next && aux->next->frequency <= node->frequency)
			aux = aux->next;
		node->next = aux->next;
		aux->next = node;
	}
	list->size++;
}

/**
* Function that fills the list with nodes in an ordered (ascending) manner.
*/
void fill_list(unsigned int tab[], List *list)
{
	int i;

	Node *new;
	for(i = 0; i < SIZE; i++)
	{
		if(tab[i] > 0)
		{
			new = malloc(sizeof(Node));
			if(new){
				new->character = i;
				new->frequency = tab[i];
				new->right = NULL;
				new->left = NULL;
				new->next = NULL;
				insert_ordered(list, new);
			}
			else
			{
				printf("\tError when allocating memory in fill_list");
				break;
			}
		}
	}
}

/**
* Function that prints the list on the terminal.
*/
void print_list(List *list)
{
	Node *aux = list->start;

	printf("\n\tSorted Linked List: Size: %d\n", list->size);
	while(aux)
	{
		printf("\tCharacter: %c Frequency: %d\n", aux->character, aux->frequency);
		aux = aux->next;
	}
}

//---------------------- Part 3: Building Huffman's Tree  ----------------------

/**
* Function that removes the first two lowest frequency nodes.
*/
Node* remove_at_start(List *list)
{
	Node *aux = NULL;

	if(list->start)
	{
		aux = list->start;
		list->start = aux->next;
		aux->next = NULL;
		list->size--;
	}

	return aux;
}

/*
Algorithm to build the huffman tree, inspired by the following pseudocode:
<http://www.cs.gettysburg.edu/~ilinkin/courses/Spring-2014/cs216/assignments/a8.html>

procedure BUILD-TREE(frequencies):
    pq ← make empty priority queue
    for each (symbol, key) in frequencies:
        h ← make a leaf node for the (symbol, key) pair
        INSERT(pq, h)

    n ← size[pq]
    for i = 1 to n-1:
        h1 ← POP-MIN(pq)
        h2 ← POP-MIN(pq)
        h3 ← MAKE-NODE(h1, h2)
        INSERT(pq, h3)

    return POP-MIN(pq)
*/

/** Function that constructs the huffman tree
* @param: the priority queue.
*/
Node* assemble_tree(List *list)
{
	Node *first;
	Node *second;
	Node *new;

	while(list->size > 1)
	{
		first = remove_at_start(list);
		second = remove_at_start(list);
		new = malloc(sizeof(Node));
		if(new)
		{
			new->character = '+';
			new->frequency = first->frequency + second->frequency;
			new->left = first;
			new->right = second;
			new->next = NULL;

			insert_ordered(list, new);
		}
		else
		{
			printf("\n\tError when allocating memory in assemble_tree!");
			break;
		}
	}
	return list->start;
}

/**
* Function that prints the Huffman's tree.
*/
void print_tree(Node *root, int size)
{
	if(root->left == NULL && root->right == NULL)
		printf("\tLeaf: %c\t Height: %d\n", root->character, size);
	else
	{
		print_tree(root->left, size + 1);
		print_tree(root->right, size + 1);
	}
}

/**
* Function to destroy the nodes of the tree and release the stored memory.
*/
void destroy_tree(Node *root)
{
	if(root)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	}
}

//---------------------- Part 4: Building the Dictionary  ----------------------

/**
* Function to check the height of the binary tree. 
* Note that + 1 is for the null character '\0'.
*/
int height_tree(Node *root)
{
	int left;
	int right;

	if(root == NULL)
		return -1;
	else
	{
		left = height_tree(root->left) + 1;
		right = height_tree(root->right) + 1;
		if(left > right)
			return left;
		else
			return right;
	}
}

/**
* Function that allocates memory for the dictionary, 
* receiving the value of the number of columns (which is the 
* height of the Huffman tree + 1)
* Important to note that the number of rows, in turn, is the 
* size of the ASCII table (macro SIZE).
*/
char** allocate_dictionary(int columns)
{
	char **dictionary;
	int i;

	dictionary = malloc(sizeof(char*) * SIZE);

	for(i = 0; i < SIZE; i++)
		dictionary[i] = calloc(columns, sizeof(char));
	return dictionary;
}

/**
* In this function I will produce (generate) my dictionary. I get some parameters
* like the dictionary, the root node, the path and the columns.
* Note that this is a recursive procedure: as I go 
* in my tree to the left(0) or to the right(1), I concatenate (with strcat) to 0 or 1,
* and the path is precisely the code of the character generated until it reaches a leaf 
* (that is, a non-intermediate node, with no children).
*/
void generate_dictionary(char **dictionary, Node *root, char *path, int columns)
{
	char left[columns];
	char right[columns];

	if(root->left == NULL && root->right == NULL)
	{
		strcpy(dictionary[root->character], path);
	}
	else
	{
		strcpy(left, path);
		strcpy(right, path);

		strcat(left,"0");
		strcat(right, "1");

		generate_dictionary(dictionary, root->left,left, columns);
		generate_dictionary(dictionary, root->right, right, columns);
	}
}

/**
* Function for printing the dictionary.
*/
void print_dictionary(char **dictionary)
{
	int i;

	for(i = 0; i < SIZE; i++)
	{
		if(ft_strlen((unsigned char *) dictionary[i]) > 0)
			printf("\t%3d: %s\n", i, dictionary[i]);
	}
}

//----------------------------- Part 5: Encode  -----------------------------

/*
* Function that calculates the string size, given the dictionary and the text
* as parameters. Note that text[i] will become a number represented in ASCII.
*/
int calculates_size_string(char ** dictionary, unsigned char *text)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while(text[i] != '\0')
	{
		size = size + ft_strlen((unsigned char *) dictionary[text[i]]);
		i++;
	}
	return size + 1;
}

/*
* Function responsible for doing the encoding of our text.
* Receives as parameter the dictionary and the strings.
* Note that calloc takes the number of characters from an array
* and the size of a character.
*/
char* encode(char ** dictionary, unsigned char *text)
{
	int i;
	int size;

	i = 0;
	size = calculates_size_string(dictionary, text);
	// calloc recebe:
	// a quant de caracteres de um vetor
	// o size de um caractere
	char *code = calloc(size, sizeof(char));
	while(text[i] != '\0')
	{
		strcat(code, dictionary[text[i]]);
		i++;
	}
	return code;
}

//------------------------------ Part 6: Decode  ----------------------------

/*
* Function responsible for the decoding - the process 
* inverse to the codification - of a text. 
*/
char* decode(unsigned char text[], Node *root)
{
	int i = 0;

	Node *aux = root;
	char temp[2];
	char *decoded = calloc(ft_strlen(text), sizeof(char));

	while(text[i] != '\0')
	{
		if(text[i] == '0')
			aux = aux->left;
		else
			aux = aux->right;
		if(aux->left == NULL && aux->right == NULL)
		{
			temp[0] = aux->character;
			temp[1] = '\0';
			strcat(decoded, temp);
			aux = root;
		}
		i++;
	}
	return decoded;
}

//---------------------------- Part 7: Compress  ----------------------------

/*
* This function is responsible for compressing our file, receiving strings 
* as argument. Here we can see that it was necessary to manipulate 
* bits with Shift Left.
* Note: wb = write binary.
*/
void compress(unsigned char str[])
{
	unsigned char mask;
	unsigned char byte;

	FILE *file = fopen("compressed.wg", "wb"); //write binary
	int i = 0;
	int j = 7;
	byte = 0;
	if(file)
	{
		while(str[i] != '\0')
		{
			mask = 1;
			if(str[i] == '1')
			{
				mask = mask << j;
				byte = byte | mask;
			}
			j--; // j precisa decrementar porque começou com 7
			if(j < 0) // tem um byte formado
			{
				fwrite(&byte, sizeof(unsigned char), 1, file);
				byte = 0; // toda vez que escrevemos 1 byte em um arquivo ele volta para 7
				j = 7;
			}
			i++;
		}
		// existe 1 bit pela metade ou foi finalizado certinho?
		if(j != 7) // existe um byte em formação (?)
			fwrite(&byte, sizeof(unsigned char), 1, file);
		fclose(file);
	}
	else
		printf("\nError when opening / creating file in compress\n");
}

//---------------------------- Part 8: Decompress  ----------------------------

/*
* Function responsible for helping decompress a file, receiving as argument 
* the bytes and an integer value i to be able to Shift left, 
* and checking if the byte is equal to 1.
*/
unsigned int is_bit_one(unsigned char byte, int i)
{
	unsigned char mask;

	mask = (1 << i); // 00000001
	return byte & mask; // 10000000
}

/*
* Function responsible for decompressing a file, 
* taking as argument the root node of our binary tree. 
* Note: "rb" = read binary.
*/
void decompress(Node *root)
{
	FILE *file = fopen("compressed.wg", "rb"); //read binary
	Node *aux = root;
	unsigned char byte; // 10111001
	int i;

	if(file)
	{
		while(fread(&byte, sizeof(unsigned char), 1, file))
		{
			for(i= 7; i >= 0; i--)
			{
				if(is_bit_one(byte, i))
					// então quando for 1, precisamos caminhar para a direita
					// portanto, precisamos do nosso ponteiro para caminhar na arvore
					aux = aux->right;
				else
					aux = aux->left;
				if(aux->left == NULL && aux->right == NULL)
				{
					// aqui, significa que estamos em uma folha da nossa árvore
					printf("%c", aux->character);
					aux = root;
				}
			}
		}
		fclose(file);
	}
	else
		printf("\nError when opening file in unzip\n");
}

/*
* Function responsible for returning the size of the 
* .txt file in order to check the compression capacity.
*/
int	find_size()
{
	FILE *file = fopen("./tests/teste.txt", "r");
	int size = 0;

	if(file)
	{
		while(fgetc(file) != -1)
			size++;
		fclose(file);
	}
	else
		printf("\nError when opening file in discover_size\n");
	return size;
}

/*
* Function responsible for reading the text (.txt) 
* passed as argument to the function.
*/
void read_text(unsigned char *text)
{
	FILE *file = fopen("./tests/teste.txt", "r");
	char letter;
	int i = 0;

	if(file)
	{
		while(!feof(file))
		{
			letter = fgetc(file);
			if(letter != -1)
			{
				text[i] = letter;
				i++;
			}
		}
		fclose(file);
	}
	else
		printf("\nError when opening file in read_text\n");
}

//---------------------------- Part 9: Main  ----------------------------

/*
* The main function of the program is very important to link all the 
* previous functions and form the program. It is important to note that 
* the "setlocale" was used in order to make accent / punctuation characters 
* also readable from UTF-8.

* From this we can see all the processes involved, as well as the encoding 
* and decoding going on.
*/
int	main()
{
	//unsigned char	text[] = "Insert some text here";
	unsigned char	*text;
	unsigned int	table_frequency[SIZE];
	List list;
	Node *tree;
	int columns;
	int size;
	char **dictionary;
	unsigned char *encoded;
	unsigned char *decoded;

	setlocale(LC_ALL, "utf8");

	size = find_size();
	printf("\nQUANTITY: %d\n", size);

	text = calloc(size + 2, sizeof(unsigned char));
	read_text(text);
	printf("\nTEXT:\n%s\n", text);

//--------------------------- Part 1: Frequency Table ---------------------------

	initialize_table_with_zero(table_frequency);
	fill_tab_frequency(text, table_frequency);
	print_tab_frequency(table_frequency);

//------------------------- Part 2: Sorted Linked List  -------------------------

	create_list(&list);
	fill_list(table_frequency, &list);
	print_list(&list);

//---------------------- Part 3: Building Huffman's Tree  ----------------------

	tree = assemble_tree(&list);
	printf("\n\tHUFFMAN'S TREE\n");
	print_tree(tree, 0);

//---------------------- Part 4: Building the Dictionary  ----------------------

	columns = height_tree(tree) + 1;
	dictionary = allocate_dictionary(columns);
	printf("\n\tDICTIONARY:\n");
	generate_dictionary(dictionary, tree, "", columns);
	print_dictionary(dictionary);

//----------------------------- Part 5: Encode  -----------------------------

	encoded = (unsigned char *) encode(dictionary, text);
	printf("\n\tCODED TEXT: %s\n", encoded);

//------------------------------ Part 6: Decode  ----------------------------

	decoded = (unsigned char *) decode(encoded, tree);
	printf("\n\tENCODED TEXT: %s\n", encoded);

//---------------------------- Part 7: Compress  ----------------------------

	compress(encoded);

//---------------------------- Part 8: Decompress  ----------------------------

	printf("\nUNZIPPED FILE!\n");
	decompress(tree);
	printf("\n\n");

	free(text);
	free(encoded);
	free(decoded);
	destroy_tree(tree);

	return 0;
}
