iinclude "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: common ancestor node or NULL if there's no ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *x, *y;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	x = first->parent;
	y = second->parent;
	if (x == NULL || first == y || (!x->parent && y))
	{
		return (binary_trees_ancestor(first, y));
	}
	else if (y == NULL || x == second || (!y->parent && x))
	{
		return (binary_trees_ancestor(x, second));
	}
	return (binary_trees_ancestor(x, y));
}
