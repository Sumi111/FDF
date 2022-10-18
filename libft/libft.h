/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:55:38 by sfathima          #+#    #+#             */
/*   Updated: 2022/03/14 16:55:50 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include<string.h>
# include<fcntl.h>
# include<stdio.h>
# include<stdarg.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int i);
int		ft_atoi_h(const char *str);
void	*ft_memcpy(void *restrict_dst, const void *restrict_src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_word_count(char *s, char c);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);
int		ft_word_count(char *s, char c);
int		ft_printf(const char *arg, ...);
int		ft_print_char(char c, int ct);
int		ft_print_str(char *c, int ct);
int		ft_print_ptr(unsigned long long pt, int ct);
int		ft_print_ptrhex(unsigned long long nb, int ct);
int		ft_print_int(long nb, int ct);
int		ft_print_u(unsigned int u, int ct);
int		ft_check_hex(unsigned int nbr, int ct, char c);
int		ft_print_hex(unsigned int nbr, int ct, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_arg_space(va_list ap, int ct, char c, char d);
int		ft_arg_plus(va_list ap, int ct, char c);

#endif
