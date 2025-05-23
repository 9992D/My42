#include "pipex.h"

int main(int argc, char **argv, char **envp) {
    int pipefd[2];
    pid_t pid1, pid2;
    int infile, outfile;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return 1;
    }

    if (pipe(pipefd) == -1)
        perror_exit("pipe");
    infile = open(argv[1], O_RDONLY);
    if (infile < 0)
        perror_exit("open infile");
    outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile < 0)
        perror_exit("open outfile");

    pid1 = fork();
    if (pid1 < 0)
        perror_exit("fork");
    if (pid1 == 0) {
        dup2(infile, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(infile);
        close(outfile);
        execute_cmd(argv[2], envp);
    }

    pid2 = fork();
    if (pid2 < 0)
        perror_exit("fork");
    if (pid2 == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(pipefd[1]);
        close(infile);
        close(outfile);
        execute_cmd(argv[3], envp);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    close(infile);
    close(outfile);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
