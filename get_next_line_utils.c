#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*ft_strdup(const char *s)
{
    char    *dup;
    size_t  i;

    dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!dup)   
        return (NULL);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len1)
		res[i] = s1[i++];
	j = 0;
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}


char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
	{
		finish = slen - start;
		if (finish > len)
			finish = len;
	}
	new = (char *)malloc(finish + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < finish)
		new[i] = s[start + i++];
	new[i] = '\0';
	return (new);
}
