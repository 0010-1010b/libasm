#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);

int main() {
	char *test = "Je suis la\n";

	printf("------------------------------\n");
	printf("Testing -> ft_strlen\n");
	printf("------------------------------\n\n");

	printf("Original -> %ld\n", strlen(test));
	printf("Assembly -> %d\n", ft_strlen(test));

	printf("\n------------------------------\n");
	printf("Testing -> ft_strcpy\n");
	printf("------------------------------\n\n");

	char *src = "albillie\n";
	char dst[133];

	printf("Original -> %s", strcpy(dst, src));
	printf("Assembly -> %s", ft_strcpy(dst, src));
}
