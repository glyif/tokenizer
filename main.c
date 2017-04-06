#include "header.h"
#include "tokenizer.h"

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

	str = "The \"quick brown\" fox\\ ju;mps ;o\"ver th\"e lazy do\\\"g.";

	printf("Original String: %s\n", str);
	printf("========================================================\n");
	tokenize(&tokens, str);
	print_tokens(&tokens);
	delete_tokens(&tokens);

	return (0);
}
