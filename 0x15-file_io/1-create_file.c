#include "main.h"
/**
 * create_file - Generates a file.
 * @filename: Pointer to the file name to generate.
 * @text_content: Pointer to the text to write into the file.
 *
 * Return: Returns -1 if function fails.
 *         Otherwise, returns 1.
 */
int create_file(const char *filename, char *text_content)
{
int fileDescriptor, writeStatus, length = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (length = 0; text_content[length];)
length++;
}

fileDescriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
writeStatus = write(fileDescriptor, text_content, length);

if (fileDescriptor == -1 || writeStatus == -1)
return (-1);
close(fileDescriptor);
return (1);
}
