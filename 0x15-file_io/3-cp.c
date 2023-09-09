#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocateBuffer(char *filename);
void closeFileDescriptor(int fd);

/**
 * allocateBuffer - Allocates 1024 bytes for a temp buffer.
 * @filename: The name of the file the buffer is used for.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *allocateBuffer(char *filename)
{
char *tempBuffer;
tempBuffer = malloc(sizeof(char) * 1024);
if (tempBuffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
exit(99);
}
return (tempBuffer);
}

/**
 * closeFileDescriptor - Closes given file descriptor.
 * @fd: The file descriptor to close.
 */
void closeFileDescriptor(int fd)
{
int closeStatus;
closeStatus = close(fd);
if (closeStatus == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - Duplicates file content to another file.
 * @argc: Number of arguments provided.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success.
 * Description: If incorrect arg count - exit 97.
 * If source file issues - exit 98.
 * If destination file issues - exit 99.
 * If file close issues - exit 100.
 */
int main(int argc, char *argv[])
{
int srcFD, destFD, readCount, writeCount;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp source dest\n");
exit(97);
}
buffer = allocateBuffer(argv[2]);
srcFD = open(argv[1], O_RDONLY);
readCount = read(srcFD, buffer, 1024);
destFD = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (srcFD == -1 || readCount == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
writeCount = write(destFD, buffer, readCount);
if (destFD == -1 || writeCount == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
readCount = read(srcFD, buffer, 1024);
destFD = open(argv[2], O_WRONLY | O_APPEND);
} while (readCount > 0);
free(buffer);
closeFileDescriptor(srcFD);
closeFileDescriptor(destFD);
return (0);
}
