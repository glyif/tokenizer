#include "header.h"
#include "tokenizer.h"

token_types token_names[] = {
    { TOKEN_SEMICOLON,  ";",  "semicolon" },
    { TOKEN_PIPE,       "|",  "pipe" },
    { TOKEN_REWRITE,    ">",  "rewrite" },
    { TOKEN_APPEND,     ">>", "append" },
    { TOKEN_CAT,        "<",  "cat" },
    { TOKEN_BACKGROUND, "&",  "background" }
};

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: array of pointers pointing to the arguments
 *
 * Return: 0
 */
int main(int __attribute__((unused))argc, char __attribute__((unused))*argv[])
{
	tokens_t tokens;
	char *str;

	str = "The \"quick brown\" fox\\ ju;mps ;;;o\"ver th\"e lazy do\\\"g.";

	printf("Original String: %s\n", str);
	printf("========================================================\n");
	tokenize(&tokens, str);
	print_tokens(&tokens);
	delete_tokens(&tokens);

	return (0);
}
