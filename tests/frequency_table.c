//--------------------------- Part 1: Frequency Table ---------------------------

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
