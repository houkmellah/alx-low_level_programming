#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file_name);
void close_file_descriptor(int file_desc);

/**
 * create_buffer - Allocates memory for a buffer of 1024 bytes.
 * @file_name: File name for which the buffer stores characters.
 *
 * Return: A pointer to the allocated buffer.
 */
char *create_buffer(char *file_name)
{
char *buf;
buf = malloc(sizeof(char) * 1024);
if (buf == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
exit(99);
}
return (buf);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @file_desc: File descriptor to close.
 */
void close_file_descriptor(int file_desc)
{
int status;
status = close(file_desc);
if (status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
exit(100);
}
}

/**
 * main - Copies content from one file to another.
 * @argc: Count of arguments provided to the program.
 * @argv: Array of pointers to the provided arguments.
 *
 * Return: 0 on success.
 * Description: Exit codes:
 * 97 if incorrect argument count.
 * 98 if source file doesn't exist or isn't readable.
 * 99 if destination file isn't creatable or writable.
 * 100 if a file can't be closed.
 */
int main(int argc, char *argv[])
{
int source_fd, dest_fd, read_bytes, written_bytes;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp source dest\n");
exit(97);
}

buf = create_buffer(argv[2]);
source_fd = open(argv[1], O_RDONLY);
read_bytes = read(source_fd, buf, 1024);
dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (source_fd == -1 || read_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
free(buf);
exit(98);
}

written_bytes = write(dest_fd, buf, read_bytes);
if (dest_fd == -1 || written_bytes == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buf);
exit(99);
}

read_bytes = read(source_fd, buf, 1024);
dest_fd = open(argv[2], O_WRONLY | O_APPEND);

} while (read_bytes > 0);

free(buf);
close_file_descriptor(source_fd);
close_file_descriptor(dest_fd);

return (0);
}
