#include "main.h"

/**
* append_text_to_file - Adds text to the end of a file.
* @filename: Name of the file.
* @text_content: String to append to the file.
*
* Return: 1 on success, -1 on failure, or if filename is NULL,
* or if file does not exist or lacks write permissions.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fileDesc, writeStatus, length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[length])
length++;
}

fileDesc = open(filename, O_WRONLY | O_APPEND);
writeStatus = write(fileDesc, text_content, length);

if (fileDesc == -1 || writeStatus == -1)
return (-1);

close(fileDesc);

return (1);
}
