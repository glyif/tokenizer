#ifndef __TOKENIZER_H
#define __TOKENIZER_H
#include "header.h"
/**
 * struct tokens - struct for tokenizing string
 * @data: initial string separated with '\0', hold all the tokens
 * @tokens: array of pointers pointing to different parts of the data string
 * @tokensN: amount of tokens parsed
 */
typedef struct tokens
{
	/* Do not deallocate everything from here until the full parse tree deallocation, because
	 * AST will use tokens from this structure!
	 */
	char *data;
	const char **tokens;
	unsigned int tokensN;
} tokens_t;

/* This function tokenizes a string, allocates memory and properly fills the tokens_t structure */
int tokenize(tokens_t *tokens, const char *string);

/* This function deallocates and frees a tokens_t structure */
int delete_tokens(tokens_t *tokens);

/* Output tokens to the stdout for debugging */
int print_tokens(tokens_t *tokens);

/* Initializes tokens struct */
void init_tokens(tokens_t *tokens, int length);
#endif
