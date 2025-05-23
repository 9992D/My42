#include "pipex.h"

void perror_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char *get_command_path(char *cmd, char **envp) {
    char *path_env = NULL;
    for (int i = 0; envp[i]; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5;
            break;
        }
    }
    if (!path_env)
        return NULL;
    char **paths = ft_split(path_env, ':');
    for (int i = 0; paths[i]; i++) {
        char *candidate = ft_strjoin(paths[i], "/");
        char *full = ft_strjoin(candidate, cmd);
        free(candidate);
        if (access(full, X_OK) == 0) {
            // free paths
            for (int j = 0; paths[j]; j++)
                free(paths[j]);
            free(paths);
            return full;
        }
        free(full);
    }
    for (int j = 0; paths[j]; j++)
        free(paths[j]);
    free(paths);
    return NULL;
}

void execute_cmd(char *cmd, char **envp) {
    char **args = ft_split(cmd, ' ');
    char *path = get_command_path(args[0], envp);
    if (!path) {
        fprintf(stderr, "pipex: command not found: %s\n", args[0]);
        exit(127);
    }
    execve(path, args, envp);
    perror_exit("execve");
}