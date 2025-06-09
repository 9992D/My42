/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:34:58 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 04:22:33 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	child1(int *pipefd, char **argv, char **e, int infile);
void	child2(int *pipefd, char **argv, char **e, int outfile);
void	execute_cmd(char *cmd, char **e);
char	*get_command_path(char *cmd, char **e);
char	*generate_path(char **paths, char *cmd);
void	perror_exit(const char *msg);

#endif