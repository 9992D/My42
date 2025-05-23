#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

char **ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char *get_command_path(char *cmd, char **envp);
void perror_exit(const char *msg);
void execute_cmd(char *cmd, char **envp);