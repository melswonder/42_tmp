/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:54:42 by kohki_T           #+#    #+#             */
/*   Updated: 2025/05/04 20:45:31 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
// # include "libft.h"
# include "parse.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

unsigned long	ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *v1, const void *v2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

char			*ft_strcpy(char *dest, const char *src);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
char			*ft_strcat(char *dest, const char *src);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);

char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);

void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);

char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
// char				**ft_split(char const *s, char c);
char			**ft_split(const char *sep, char *strs);

char			*ft_itoa(int n);
// char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
// void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_free(void *ptr);
void			free_2darray(char **array);
void			free_3darray(char ***array);
void			free_4darray(char ****array);

// printf
char			*ft_convert_base(unsigned long long p, int base);
char			*ft_tolowerall(char *str);
// int					ft_dprintf_classify_by_specifier(int fd, int c,
// 						va_list args);
// int					ft_dprintf_char(int fd, int c);
// int					ft_dprintf_count(int fd, char *str);
// int					ft_dprintf_distinction(int fd, const char *str,
// 						va_list args);
// int					ft_dprintf_hexa(int fd, unsigned int n, int f);
// int					ft_dprintf_int(int fd, int n);
// int					ft_dprintf_pointer(int fd, unsigned long long point);
// int					ft_dprintf_str(int fd, char *str);
// int					ft_dprintf_unsigned(int fd, unsigned int n);
// int					ft_dprintf(int fd, const char *format, ...);
// int					ft_printf(const char *format, ...);

// // getnextline
char				*get_next_line(int fd);
// char				*ft_before_newline(char *str);
// char				*ft_after_newline(char *str);
// char				*read_line_loop(int fd, int nb, char *buffer, char *save);
// int					ft_str_has_newline(char *str);
// char				*ft_strcat_andfree(char *s1, char *s2);

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }					t_list;

// t_list				*ft_lstnew(void *content);
// void				ft_lstadd_front(t_list **lst, t_list *new);
// int					ft_lstsize(t_list *lst);
// t_list				*ft_lstlast(t_list *lst);
// void				ft_lstadd_back(t_list **lst, t_list *new);
// void				ft_lstdelone(t_list *lst, void (*del)(void *));
// void				ft_lstclear(t_list **lst, void (*del)(void *));
// void				ft_lstiter(t_list *lst, void (*f)(void *));
// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
//  void (*del)(void *));

#endif
