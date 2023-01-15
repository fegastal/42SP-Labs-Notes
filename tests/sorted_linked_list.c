//------------------------- Part 2: Sorted Linked List  -------------------------

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
