/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:20:07 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 04:22:53 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Handles the first child process
void	child1(int *pipefd, char **argv, char **e, int infile)
{
	if (dup2(infile, STDIN_FILENO) < 0 || dup2(pipefd[1], STDOUT_FILENO) < 0)
		perror_exit("dup2 child1");
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		perror_exit("dup2 pipe write");
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	execute_cmd(argv[2], e);
}

// Handles the second child process
void	child2(int *pipefd, char **argv, char **e, int outfile)
{
	if (dup2(pipefd[0], STDIN_FILENO) < 0 || dup2(outfile, STDOUT_FILENO) < 0)
		perror_exit("dup2 child2");
	if (dup2(outfile, STDOUT_FILENO) < 0)
		perror_exit("dup2 outfile");
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfile);
	execute_cmd(argv[3], e);
}
