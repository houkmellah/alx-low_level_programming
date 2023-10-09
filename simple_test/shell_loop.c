#include "shell.h"

void shell_loop(info_t *info)
{
    char *line = NULL;
    size_t len = 0;
    char *cmd = NULL;
    char **args = NULL;

    while (1)
    {
        printf("$ ");
        getline(&line, &len, stdin);

        if (line == NULL || line[0] == '\0')
        {
            continue; // Ignorer les lignes vides
        }

        info->argv = split_string(line, " ");

        if (info->argv[0] == NULL)
        {
            free(line);
            continue;
        }

        if (strcmp(info->argv[0], "exit") == 0)
        {
            free(line);
            free(info->argv);
            free(cmd);  // Libération de la mémoire allouée pour cmd
            free(args);  // Libération de la mémoire allouée pour args
            exit(EXIT_SUCCESS);
        }

        cmd = info->argv[0]; // Assigner la commande à cmd
        args = info->argv;   // Assigner les arguments à args

        execute_command(info, cmd, args);

        // Libérer la mémoire allouée pour cmd et args après leur utilisation
        free(cmd);
        free(args);

        free(line);
    }
}
