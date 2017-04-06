#include "tokenizer.h"

/**
 * tokenize - tokenizes command string
 * @tokens: tokens_t struct containing initial string and array of strings
 * @string: command string
 *
 * Return: 0, or exits with error
 */
int tokenize(tokens_t *tokens, const char *string)
{
	unsigned int length, string_idx, data_idx, tokens_idx;
	unsigned int skip_next, skip_quote;
	unsigned int is_token;

	char symbol;
	/* First of all, we need to carefully allocate memory */
	/* It does not matter if we allocate too much, it is better than constant reallocations, */
	/* because they take too much time, and memory is not a concern */
	length = strlen(string);
	if (length == 0)
		length = 1; /* Empty string should be properly processed too! */

	/* Initializes struct */
	init_tokens(tokens, length);

	/* Set up current indexes; */
	string_idx = 0; /* Current position in original string */
	data_idx = 0;   /* Current position in resulting data string */
	tokens_idx = 0; /* Current token */

	skip_next = 0;  /* If it is set to 1, then any symbol except for '\0' would be skipped */
	skip_quote = 0; /* If it is set to 1, then we need to skip any symbol (including '\') until we find another '\"' symbol */

	is_token = 0;   /* If it is set to 1, then we are currently processing a token. If 0, then we are processing whitespace symbols */

	/* Cycle for each symbol from the original string */
	while (string[string_idx] != '\0')
	{
		/* Cycle until the end */
		/* Retrieve current symbol and advance further */
		symbol = string[string_idx];
		string_idx++;

		if (!is_token && isspace(symbol))
			continue; /* Skip whitespaces if we are not in token mode */

		if (!is_token && !isspace(symbol) && (symbol != ';'))
		{
			/* Note that we'll handle ';' later, this is the special case */
			/* New token has been started */
			/* We need to set up pointer properly so it points to current location in data */
			tokens->tokens[tokens_idx] = tokens->data + data_idx;
			tokens_idx++;
			is_token = 1; /* The token has started. We need to process it carefully */
		}

		if (is_token && isspace(symbol) && !skip_next && !skip_quote)
		{
			/* Previous token has been ended */
			/* Finish this token */
			tokens->data[data_idx] = '\0';
			data_idx++;

			/* Also set token flag to 0 */
			is_token = 0;

			continue; /* We have nothing to do here, because current symbol is a space symbol */
		}

		/* Deal with ; */
		/* It should be the separate token */
		if ((symbol == ';') && !skip_next && !skip_quote)
		{
			if (is_token)
			{
				/* First, we need to close previous token */
				tokens->data[data_idx] = '\0';
				data_idx++;
				/* No need to mark is_token here, it'll be set to 0 afterwards anyway */
			}

			/* Next, we need to add new token */
			tokens->tokens[tokens_idx] = tokens->data + data_idx;
			tokens_idx++;

			/* And fill it with ';' */
			tokens->data[data_idx] = ';';
			tokens->data[data_idx + 1] = '\0';
			data_idx += 2;

			/* Set up is_token to 0 and skip this iteration */
			is_token = 0;
			continue;
		}

		/* Deal with " */
		/* Note that we need to deal with them only if we are not skipping next symbol, i.e. */
		/* \" is to be skipped */
		if ((symbol == '\"') && !skip_next)
		{
			skip_quote = !skip_quote;
			continue; /* We do not need \" to be in token then*/
		}

		/* Deal with '\' */
		if ((symbol == '\\') && !skip_next)
		{
			skip_next = 1;
			continue; /* We do not need \\ to be in token then */
		}
		skip_next = 0; /* The next symbol has been skipped (or skip_next was 0 to begin with) */

		/* When we got here, is_token is 1, and next symbol is not space or we are skipping it */
		/* We need to add it to current data */
		tokens->data[data_idx] = symbol;
		data_idx++;
	}

	/* Finalize data by placing the last '\0' just to be sure that it has been terminated */
	tokens->data[data_idx] = '\0';

	/* Set current amount of tokens properly */
	tokens->tokensN = tokens_idx;

	return (0); /* All OK */
}
