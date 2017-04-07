#ifndef __TOKENIZER_H
#define __TOKENIZER_H
#include "header.h"
/* TODO: on change, also change the array in the beginning of tokenizer.c! */
#define TOKEN_STRING     0 /* Default token, serves as program name, argument etc */
#define TOKEN_SEMICOLON  1 /* ; token  */
#define TOKEN_PIPE       2 /* | token  */
#define TOKEN_REWRITE    3 /* > token  */
#define TOKEN_APPEND     4 /* >> token */
#define TOKEN_CAT        5 /* < token  */
#define TOKEN_BACKGROUND 6 /* & token  */

/**
 * struct token - link tokenid with string
 * @id: numerical id
 * @str: string to go along with numerical id
 */
typedef struct token {
	int id;
	const char * str;
} token_t;

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
	token_t * tokens;
	unsigned int tokensN;
} tokens_t;

/**
 * struct token_id
 * @token_id: numerical id
 * @token_str: the exact token string to be compared with
 * @token_descr: for debugging
 */
typedef struct token_id
{
	int token_id;
	const char *token_str;
	const char *token_descr;
} token_types;

/* This function tokenizes a string, allocates memory and properly fills the tokens_t structure */
int tokenize(tokens_t *tokens, const char *string);

/* This function deallocates and frees a tokens_t structure */
int delete_tokens(tokens_t *tokens);

/* Output tokens to the stdout for debugging */
int print_tokens(tokens_t *tokens);

/* Initializes tokens struct */
void init_tokens(tokens_t *tokens, int length);
#endif
