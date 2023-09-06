#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Outputs text file content to STDOUT.
 * @filename: File to be read
 * @letters: Number of characters to read
 * Return: actualChars - Actual number of bytes read and outputted.
 *         0 if the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t fileDesc;
ssize_t actualChars;
ssize_t bytesRead;

fileDesc = open(filename, O_RDONLY);
if (fileDesc == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
bytesRead = read(fileDesc, buffer, letters);
actualChars = write(STDOUT_FILENO, buffer, bytesRead);

free(buffer);
close(fileDesc);

return (actualChars);
}
