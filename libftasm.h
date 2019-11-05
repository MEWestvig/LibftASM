#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			ft_toupper(int c);
char			ft_tolower(int c);
void			*ft_memset(void *dst, int c, size_t size);
void			*ft_bzero(void *dst, size_t size);

#endif