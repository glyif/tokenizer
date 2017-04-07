#include "tokenizer.h"

/**
 * init_tokens - initializes token struct
 * @tokens: tokens struct to initialize
 * @length: length to malloc for
 */
void init_tokens(tokens_t *tokens, int length)
{
	/* For the extreme case, such as 'a;a;a;a;a;a', we'll need to allocate twice as much memory for data + 1 byte for terminator */
	/* Maximum amount of tokens is the same as length */
	tokens->data = malloc((length * 2 + 1) * sizeof(char));
	tokens->tokens = malloc(length * sizeof(token_t));

	if (!tokens->data || !tokens->tokens)
	{
		perror("Unable to allocate memory for tokens");
		exit(1); /* This is a critical error */
	}

	/* Initialize the rest of the structure */
	tokens->tokensN = 0;
}
