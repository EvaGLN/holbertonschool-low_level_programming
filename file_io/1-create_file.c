#include "main.h"
/**
 * create_file - Create a function that creates a file.
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 if success or -1 if fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	size_t len;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	len = strlen(text_content);
	bytes_written = write(fd, text_content, len);
	close(fd);
	if (bytes_written == -1 || (size_t)bytes_written != len)
		return (-1);
	return (1);
}
