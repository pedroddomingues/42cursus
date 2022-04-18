/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:30:28 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:09:41 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# define BUFFER_SIZE	32
# define SPECIFIERS		"cspdiuxX%"

# define HEXALOWER		"0123456789abcdef"
# define HEXAUPPER		"0123456789ABCDEF"
# define DECIMAL		"0123456789"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

void	ft_bzero(void *str, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memchr(const void *str, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(char const *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_atoi(const char *str);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strctrim(char const *s1, char c);

int		ft_number_width(int n, char *base);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_itoa_base(int n, char *base);

char	*ft_ullitoa_base(unsigned long long int n, char *base);

int		ft_signal(int n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr_base_fd(int nbr, char *base, int fd);

void	ft_putnchar_fd(int n, char c, int fd);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *n);

void	ft_lstadd_front(t_list **lst, t_list *n);

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

int		ft_isspace(char c);

char	*ft_strrev(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strnochr(const char *s, int c);

char	*ft_strnorchr(const char *s, int c);

char	*ft_strcpy(char *dst, const char *src);

size_t	get_wordsnum(const char *s, char c);

size_t	get_wordlen(const char *s, char c);

int		ft_printf(const char *str, ...);

int		print_c(char *str, int arg);
int		print_percent(char *str);
int		print_s(char *str, char *arg);
int		print_d(char *str, int arg);
int		print_x(char *str, unsigned long int arg);
int		ft_strchr_i(const char *s, int c);

int		ft_hexstrtoi(char *hex);

void	ft_free_split(char **split);

char	*ft_ftoa(float number, int precision);

int		ft_strendcmp(char *s1, char *s2);

char	*ft_strappend(char *str, char add);

float	ft_pow(float base, int exp);

#endif
