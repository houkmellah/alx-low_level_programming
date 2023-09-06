#include "main.h"

/**
 * append_text_to_file - Appends a string to file's end.
 * @filename: Pointer to the name of the target file.
 * @text_content: Text to append to the file's end.
 *
 * Return: -1 if function fails, filename is NULL, or lacks write permissions.
 *         Otherwise, returns 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fileDescriptor, writeStatus, textLength = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (textLength = 0; text_content[textLength];)
textLength++;
}
fileDescriptor = open(filename, O_WRONLY | O_APPEND);
writeStatus = write(fileDescriptor, text_content, textLength);
if (fileDescriptor == -1 || writeStatus == -1)
return (-1);
close(fileDescriptor);
return (1);
}
