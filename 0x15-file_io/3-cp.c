#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void shut_file(int file_desc);

/**
 * allocate_buffer - Assigns memory for a buffer of size 1024 bytes.
 * @filename: Name of the file the buffer is associated with.
 *
 * Return: Pointer to the allocated buffer.
 */
char *allocate_buffer(char *filename)
{
char *buf;
buf = malloc(sizeof(char) * 1024);
if (!buf)
{
dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", filename);
exit(99);
}
return (buf);
}

/**
 * shut_file - Safely closes the file descriptor.
 * @file_desc: File descriptor to close.
 */
void shut_file(int file_desc)
{
if (close(file_desc) == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", file_desc);
exit(100);
}
}

/**
 * main - Duplicates content from one file to another.
 * @argc: Argument count.
 * @argv: Argument values.
 *
 * Return: 0 if successful.
 *
 * Errors: 97 for incorrect argument count.
 *         98 if source file doesn't exist or can't be read.
 *         99 if target file can't be created or written to.
 *         100 if either file can't be closed.
 */
int main(int argc, char *argv[])
{
int src, dest, bytesRead, bytesWritten;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp source destination\n");
exit(97);
}

buf = allocate_buffer(argv[2]);
src = open(argv[1], O_RDONLY);
bytesRead = read(src, buf, 1024);
dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do 
{
if (src == -1 || bytesRead == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
free(buf);
exit(98);
}

bytesWritten = write(dest, buf, bytesRead);
if (dest == -1 || bytesWritten == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buf);
exit(99);
}

bytesRead = read(src, buf, 1024);
dest = open(argv[2], O_WRONLY | O_APPEND);

} while (bytesRead > 0);

free(buf);
shut_file(src);
shut_file(dest);

return (0);
}
