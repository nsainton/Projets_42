#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*ns;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	ns = (char *)malloc((i + 1) * sizeof(*ns));
	if (ns == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		*(ns + j) = *(s + j);
		j ++;
	}
	*(ns + j) = 0;
	return (ns);
}
