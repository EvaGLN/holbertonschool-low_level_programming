#include "main.h"
#define BUFFER_SIZE 1024
/**
 * open_file_from - opens the source file for reading
 * @file_from: name of the file to read from
 * Return: the file descriptor
 */
int open_file_from(char *file_from)
{
	int fd_from;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	return (fd_from);
}

/**
 * open_file_to - creates/opens the destination file for writing
 * @file_to: name of the file to write to
 * Return: the file descriptor
 */
int open_file_to(char *file_to)
{
	int fd_to;

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	return (fd_to);
}

/**
 * copy_content - reads from fd_from and writes to fd_to, 1024 bytes at a time
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: name of the source file (for error messages)
 * @file_to: name of the destination file (for error messages)
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_fd - closes a file descriptor and checks for errors
 * @fd: the file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open_file_from(av[1]);
	fd_to = open_file_to(av[2]);
	copy_content(fd_from, fd_to, av[1], av[2]);
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
