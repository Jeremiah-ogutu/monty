#include "monty.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *mf;
    char *buff = NULL, *opcode, *n;
    size_t lol = 0;
    int line_number = 0;
    stack_t *stack = NULL, *current;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    mf = fopen(argv[1], "r");
    if (mf == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((getline(&buff, &lol, mf)) != -1)
    {
        line_number++;
        opcode = strtok(buff, DELIMATOR);
        if (opcode == NULL || opcode[0] == '#')
            continue;

        if (!strcmp(opcode, "nop"))
            continue;
        else if (!strcmp(opcode, "push"))
        {
            n = strtok(NULL, DELIMATOR);
            _push(&stack, n, line_number);
        }
        else
            find_opcode(&stack, opcode, line_number);
    }

    fclose(mf);
    free(buff);
    
    while (stack != NULL)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }

    return EXIT_SUCCESS;
}
