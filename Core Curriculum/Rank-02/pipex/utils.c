/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 01:34:18 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 03:19:28 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Prints an error message and exits the program
void	perror_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

// Libft function
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (c < n)
	{
		if (s1[c] != s2[c] || s1[c] == '\0' || s2[c] == '\0')
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	return (0);
}

// Tries to create a full execuatble path
char	*generate_path(char **paths, char *cmd)
{
	int		i;
	char	*candidate;
	char	*full;

	i = 0;
	while (paths[i])
	{
		candidate = ft_strjoin(paths[i], "/");
		full = ft_strjoin(candidate, cmd);
		free(candidate);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

// Seaches for a command in PATH and returns its full path if found
char	*get_command_path(char *cmd, char **e)
{
	int		i;
	char	**paths;
	char	*full;

	i = 0;
	while (e[i] && ft_strncmp(e[i], "PATH=", 5) != 0)
		i++;
	if (!e[i])
		return (NULL);
	paths = ft_split(e[i] + 5, ':');
	if (!paths)
		return (NULL);
	full = generate_path(paths, cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (full);
}

// Execute the given command using execve
void	execute_cmd(char *cmd, char **e)
{
	char	**args;
	char	*path;
	int		i;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		perror_exit("Invalid command");
	path = get_command_path(args[0], e);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		exit(127);
	}
	execve(path, args, e);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	perror_exit("execve");
}
