#include "../../includes/encoder.h"

int	main()
{
	int i, vet[250];

	for(i = 0; i < 250; i++)
		vet[i] = 0;
	
	vet['V']++;
	vet['a']++;
	vet['m']++;
	vet['o']++;
	vet['s']++;

	return 0;
}
