#include "binary_trees.h"

/**
 * binary_tree_height_b - measures the height of a balance tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			b = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			a = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((b > a) ? b : a);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree to measure balance factor
 * Return: balanced factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int bal = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		bal = left - right;
	}
	return (bal);
}
