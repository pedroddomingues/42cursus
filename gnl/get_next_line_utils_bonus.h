#ifndef GET_NEXT_LINE_UTILS_BONUS_H
# define GET_NEXT_LINE_UTILS_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
