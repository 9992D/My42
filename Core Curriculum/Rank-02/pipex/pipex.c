/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:38:12 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 03:52:28 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Verifies that the argument count is valid
static void	check_args(int argc, char *prog_name)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(prog_name, 2);
		ft_putstr_fd(" infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
}

// Opens infile and outfile and returns them through pointers
static void	init_fds(char **argv, int *infile, int *outfile)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		perror_exit("open infile");
	*outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*outfile < 0)
		perror_exit("open outfile");
}

// Forks and launches both child processes
static void	start_children(char **argv, char **e, int *pipefd, int *fds)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		perror_exit("fork");
	if (pid1 == 0)
		child1(pipefd, argv, e, fds[0]);
	pid2 = fork();
	if (pid2 < 0)
		perror_exit("fork");
	if (pid2 == 0)
		child2(pipefd, argv, e, fds[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

// Main function: orchestrates argument check, fd setup and process creation
int	main(int argc, char **argv, char **e)
{
	int	pipefd[2];
	int	fds[2];

	check_args(argc, argv[0]);
	if (pipe(pipefd) == -1)
		perror_exit("pipe");
	init_fds(argv, &fds[0], &fds[1]);
	start_children(argv, e, pipefd, fds);
	return (0);
}
