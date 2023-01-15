//---------------------- Part 4: Building the Dictionary  ----------------------

void print_dictionary(char **dictionary)
{
	int i;

	for(i = 0; i < SIZE; i++)
	{
		if(ft_strlen((unsigned char *) dictionary[i]) > 0)
			printf("\t%3d: %s\n", i, dictionary[i]);
	}
}
