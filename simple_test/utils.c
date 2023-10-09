#include "shell.h"

/**
 * split_string - Découpe une chaîne en un tableau de sous-chaînes basé sur un délimiteur.
 * @str: La chaîne à découper.
 * @delim: Le délimiteur.
 *
 * Return: Un tableau de sous-chaînes.
 */
char **split_string(char *str, char *delim) {
    int count = 0;
    char **result;
    char *tmp = strdup(str);
    char *tok = strtok(tmp, delim);

    while (tok) {
        count++;
        tok = strtok(NULL, delim);
    }
    free(tmp);

    result = malloc((count + 1) * sizeof(char *));
    if (!result) return NULL;

    int i = 0;
    tmp = strdup(str);
    tok = strtok(tmp, delim);
    while (tok) {
        // supprimer le caractère de nouvelle ligne de la chaîne
        tok[strcspn(tok, "\n")] = '\0';
        result[i] = strdup(tok);
        i++;
        tok = strtok(NULL, delim);
    }
    result[i] = NULL;
    free(tmp);

    return result;
}

/**
 * free_string_array - Libère un tableau de chaînes.
 * @arr: Le tableau à libérer.
 */
void free_string_array(char **arr) {
    int i = 0;
    while (arr[i]) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

/**
 * find_command_path - Trouve le chemin complet d'une commande.
 * @pathstr: La variable d'environnement PATH.
 * @cmd: La commande à rechercher.
 *
 * Return: Le chemin complet de la commande ou NULL si non trouvé.
 */
char *find_command_path(const char *pathstr, const char *cmd) {
    char *path = strdup(pathstr);
    char *directory = strtok(path, ":");
    char *fullpath = malloc(1024); // Taille arbitraire, à ajuster selon vos besoins

    while (directory) {
        snprintf(fullpath, 1024, "%s/%s", directory, cmd);
        if (access(fullpath, F_OK) == 0) {
            free(path);
            return fullpath;
        }
        directory = strtok(NULL, ":");
    }

    free(fullpath);
    free(path);
    return NULL;
}
