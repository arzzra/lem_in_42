/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 22:41:51 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/26 18:14:15 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define BUFF_SIZE 300

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *c, size_t len);
void				*ft_memcpy(void *des, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *source,
					int c, size_t n);
void				*ft_memmove(void *dest, const void *source, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *source);
char				*ft_strncpy(char *dest, const char *source, size_t n);
char				*ft_strcat(char *dest, const char *append);
char				*ft_strncat(char *dest, const char *append, size_t n);
size_t				ft_strlcat(char *dest, const char *append, size_t n);
char				*ft_strchr(const char *str, int chr);
char				*ft_strrchr(const char *str, int chr);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t				ft_lst_size(t_list *begin_list);
t_list				*ft_lstnpoint(t_list *lst, size_t n);
void				ft_sort_wordtab(char **tab);
char				*ft_strlowcase(char *str);
char				*ft_str_reverse(char *str);
char				*ft_strupcase(char *str);
t_list				*ft_lst_contentsearch(t_list *lst, void *content_search);
int					get_next_line(const int fd, char **line);

#endif
