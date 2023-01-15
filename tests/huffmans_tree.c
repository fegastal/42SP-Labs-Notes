//---------------------- Part 3: Building Huffman's Tree  ----------------------

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
