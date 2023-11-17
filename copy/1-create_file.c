#include "main.h"

/**
 * create_file - Makes a new file.
 * @filename: Name of the file to be created.
 * @text_content: String content to be written to the file.
 *
 * Return: 1 if successful, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
int fileDesc, writeStatus, length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[length])
length++;
}

fileDesc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
writeStatus = write(fileDesc, text_content, length);

if (fileDesc == -1 || writeStatus == -1)
return (-1);

close(fileDesc);

return (1);
}
