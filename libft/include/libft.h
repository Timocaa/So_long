/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:22:07 by tlafont           #+#    #+#             */
/*   Updated: 2022/05/09 10:34:52 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_printf
{
	va_list	args;
	int		width;
	int		zero;
	int		dot;
	int		dash;
	int		tot_len;
	int		sign;
	int		form_hex;
	int		space;
}	t_printf;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

void			*ft_memset(void *s, int c, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(int c);
void			ft_putendl(const char *s);
void			ft_putstr(const char *s);
void			ft_putnbr(int n);
char			*ft_strcapitalize(char *str);
int				ft_strcasecmp(const char *s1, const char *s2);
char			*ft_strlowcase(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcasestr(const char *haystack, const char *needle);
char			*ft_strstr(const char *haystack, const char *needle);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(const char *s1, const char *s2);
int				ft_str_is_alpha(const char *s);
int				ft_str_is_lowercase(const char *s);
int				ft_str_is_numeric(const char *s);
int				ft_str_is_printable(const char *s);
int				ft_str_is_uppercase(const char *s);
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strmap(const char *s, char (*f)(char));
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strndup(const char *s, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strupcase(const char *str);
size_t			ft_intlen(int n);
char			*get_next_line(int fd);
int				ft_printf(const char *format, ...);
t_printf		*ft_init_tab(t_printf *tab);
t_printf		*ft_reset_tab(t_printf *tab);
int				ft_get_argument(t_printf *tab, const char *format, int i);
int				ft_check_flags(t_printf *tab, const char *format, int i);
int				ft_width(t_printf *tab, const char *format, int i);
int				ft_dot(t_printf *tab, const char *format, int i);
void			ft_printchar(t_printf *tab);
void			ft_putwidth_left_char(t_printf *tab);
void			ft_putwidth_right_char(t_printf *tab);
void			ft_printstr(t_printf *tab);
size_t			ft_dotlen(t_printf *tab, size_t len);
void			ft_putwidth_left_str(t_printf *tab, size_t len);
void			ft_putwidth_right_str(t_printf *tab, size_t len);
int				ft_hexalen(unsigned long nb);
void			ft_printaddr(t_printf *tab);
int				ft_calcul_len_addr(t_printf *tab, int hexalen);
void			ft_putwidth_left_addr(t_printf *tab, int len);
void			ft_putzero_addr(t_printf *atb, int len, unsigned long p);
void			ft_putnbr_base(unsigned long nb, char *base, t_printf *tab);
void			ft_putwidth_right_addr(t_printf *tab, int len);
void			ft_print_hexa(t_printf *tab, const char c);
int				ft_calcul_len_hex(int h_len, t_printf *tab);
void			ft_putwidth_left_hexa(t_printf *tab, int len, unsigned int x,
					int form);
void			ft_putwidth_right_hexa(t_printf *tab, int len);
void			ft_printunsigned(t_printf *tab);
int				ft_unsignedlen(unsigned int nb);
int				ft_calcul_len_u(t_printf *tab, int u_len);
void			ft_putwidth_left_u(t_printf *tab, int len);
void			ft_putnbr_u(unsigned int n, t_printf *tab);
void			ft_putzero_unsigned(t_printf *tab, int len, unsigned int u);
void			ft_putwidth_right_u(t_printf *tab, int len);
void			ft_printint(t_printf *tab);
int				ft_calcul_len_int(int neg, t_printf *tab, int len);
void			ft_putwidht_left_int(t_printf *tab, int len);
void			ft_putzero_int(int d, t_printf *tab, int neg, int len);
void			ft_putnbr_int(int n, t_printf *tab);
void			ft_putwidth_right_int(t_printf *tab, int len);
long long int	ft_atoll(const char *nptr);
void			ft_sort_int_tab(int *tab, int size);

#endif
