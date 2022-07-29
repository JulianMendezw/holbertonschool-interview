#include "binary_trees.h"

/**
 * binary_tree_node - creates a no in binary tree
 * @parent: pointer to the parent node
 * @value: value to set in the new node
 *
 * Return: New Node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return (new_node);
}
/**
 * sort_insert - Function for sort insertion
 * @array: pointer to the first element
 * @min: lower limit
 * @max: upper limit
 *
 * Return: pointer to the root node or NULL on failure
 */
avl_t *sort_insert(int *array, int min, int max)
{
	int half;
	avl_t *tree;

	if (min > max)
		return (NULL);

	half = (max + min) / 2;

	tree = binary_tree_node(NULL, array[half]);
	if (!tree)
		return (NULL);

	tree->left = sort_insert(array, min, half - 1);

	tree->right = sort_insert(array, half + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree
 * @array: pointer to the first element
 * @size: number of element in the array
 *
 * Return: pointer to the root node or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);

	root = sort_insert(array, 0, size - 1);

	return (root);
}
