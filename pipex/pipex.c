/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:46:55 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/24 22:32:16 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(char **path, char **re_argv)
{
	int	i;

	i = 1;
	while (*path[i])
	{
		execve(path[i], re_argv, NULL);
		i++;
		if (!path[i])
			perror(re_argv[0]);
	}
	free(re_argv);
	return ;
}

void	change_fd_child(int *pi_fd, char *argv)
{
	int file_fd;

	if ((file_fd = open(argv, O_RDONLY)) == -1)
	{
		perror(argv);
		return ;
	}
	dup2(file_fd, STDIN_FILENO);
	dup2(pi_fd[1], STDOUT_FILENO);
	close(pi_fd[0]);
	close(pi_fd[1]);
	return ;
}

void	change_fd_parent(int *pi_fd, char *argv)
{
	int out_file_fd;

	if ((out_file_fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		perror(argv);
		return ;
	}
	dup2(pi_fd[0], STDIN_FILENO);
	dup2(out_file_fd, STDOUT_FILENO);
	close(pi_fd[0]);
	close(pi_fd[1]);
	return ;
}

void	make_argv(char *argv)
{
	char	**re_argv;
	char	*path[6];
	int		i;

	i = -1;
	path[0] = "/usr/local/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/bin/";
	path[3] = "/usr/sbin/";
	path[4] = "/sbin/";
	path[5] = NULL;
	re_argv = ft_split(argv, ' ');
	while (path[++i])
		path[i] = ft_strjoin(path[i], re_argv[0]);
	run_cmd(path, re_argv);
}

int		main(int argc, char **argv)
{
	pid_t	child_pid;
	int		status;
	int		pi_fd[2];

	if (argc != 5)
		return (-1);
	status = 0;
	pipe(pi_fd);
	child_pid = fork();
	if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
		change_fd_parent(pi_fd, argv[4]);
		make_argv(argv[3]);
	}
	else if (child_pid == 0)
	{
		change_fd_child(pi_fd, argv[1]);
		make_argv(argv[2]);
		exit(status);
	}
	else
		perror("fork error :");
	return (-1);
}
