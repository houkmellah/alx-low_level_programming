#include "main.h"
#include <stdlib.h>

/**
* read_textfile - Reads and displays text file content.
* @filename: Name of the file to be read.
* @letters: Amount of characters to read.
*
* Return: Actual byt read and displayed. 0 on failure or if filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t fileDesc;
ssize_t bytesRead;
ssize_t bytesWritten;

fileDesc = open(filename, O_RDONLY);
if (fileDesc == -1)
return (0);

buffer = malloc(sizeof(char) * letters);
bytesRead = read(fileDesc, buffer, letters);
bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

free(buffer);
close(fileDesc);
return (bytesWritten);
}
