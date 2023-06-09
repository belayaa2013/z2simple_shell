#include "shell.h"
/**
 * unsetenv -the function that Remove an environment variable
 * @info: arguments
 * Return: Always 0    
 */
int unsetenv(info_t *info)
{
        int k;

        if (info->argc == 1)
        {
                _eputs("Too few arguements.\n");
                return (1);
        }
        for (k = 1; k <= info->argc; k++)   
                _unsetenv(info, info->argv[k]);

        return (0);
}
/**
 * env - the function that prints the current environment
 * @info: arguments
 * Return: 0 success
 */
int env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * genv - the function that gets the value of an environ variable
 * @info: arguments
 * @name: env var name
 *
 * Return: the value
 */
char *genv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * setenv - the function that Initialize a new environment variable
 * @info: arguments
 *  Return: Always 0
 */
int setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}



