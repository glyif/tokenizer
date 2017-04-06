#include "tokenizer.h"

/**
 * delete_tokens - frees tokens_t struct
 * @tokens: tokens_t struct that gets freed
 *
 * Return: 0
 */
int delete_tokens(tokens_t *tokens)
{
	free(tokens->data);
	tokens->data = NULL;

	free(tokens->tokens);
	tokens->tokens = NULL;
	tokens->tokensN = 0;

	return (0);
}

/**
 * print_tokens - prints all tokens from tokens_t struct
 * @tokens: tokens_t struct that you want to print
 *
 * Return: 0
 */
int print_tokens(tokens_t *tokens)
{
	unsigned int i;

	printf("There are %u tokens in token structure: ======================\n", tokens->tokensN);

	for (i = 0; i < tokens->tokensN; i++)
	{
		printf("\"%s\"\n", tokens->tokens[i]);
	}

	return (0);
}
