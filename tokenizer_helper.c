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
	unsigned int i, j;
	token_types token_names[] = {
    	{ TOKEN_SEMICOLON,  ";",  "semicolon" },
    	{ TOKEN_PIPE,       "|",  "pipe" },
    	{ TOKEN_REWRITE,    ">",  "rewrite" },
    	{ TOKEN_APPEND,     ">>", "append" },
    	{ TOKEN_CAT,        "<",  "cat" },
    	{ TOKEN_BACKGROUND, "&",  "background" }
	};

	printf("There are %u tokens in token structure: ======================\n", tokens->tokensN);
	
	for (i = 0; i < tokens->tokensN; i++)
	{
		/* For each token, we'll also need to locate its description */
		const char * description = "string"; /* Default token name */
		
		for (j = 0; j < sizeof(token_names) / sizeof(token_names[0]); j++)
		{
			if (token_names[j].token_id == tokens->tokens[i].id)
			{
				description = token_names[j].token_descr;
				break;
			}
		}
			
		printf("%14s token \"%s\"\n", description, tokens->tokens[i].str);
	}
	
	return 0;
}
