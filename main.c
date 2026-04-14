#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int		ft_strlen(const char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

// https://www.chromium.org/chromium-os/developer-library/reference/linux-constants/errnos/
// https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf

int main() {
	printf("------------------------------\n");
	printf("Testing -> ft_strlen\n");
	printf("------------------------------\n\n");

	char *test = "Je suis la\n";

	printf("Original -> %ld\n", strlen(test));
	printf("Assembly -> %d\n", ft_strlen(test));

	printf("\n------------------------------\n");
	printf("Testing -> ft_strcpy\n");
	printf("------------------------------\n\n");

	char *src = "albillie\n";
	char dst[10] = "testtttt";

	printf("ft_strcpy -> %s", ft_strcpy(dst, src));
	printf("dst after ft_strcpy -> %s", dst);
	printf("strcpy -> %s", strcpy(dst, src));

	printf("\n------------------------------\n");
	printf("Testing -> ft_strcmp\n");
	printf("------------------------------\n\n");

	char *s1 = "Je suis\n";
	char *s2 = "Je suiq\n";
	char *s3 = "Je suis\n";

	printf("strcmp -> %d\n", strcmp(s1, s2));
	printf("ft_strcmp -> %d\n\n", ft_strcmp(s1, s2));

	printf("strcmp -> %d\n", strcmp(s1, s3));
	printf("ft_strcmp -> %d\n", ft_strcmp(s1, s3));


	printf("\n------------------------------\n");
	printf("Testing -> ft_write\n");
	printf("------------------------------\n\n");

	char *str = "Je suis la";

	int original = write(1, str, ft_strlen(str));
	printf(" -> %d\n", original);
	int assembly = ft_write(1, str, ft_strlen(str));
	printf(" -> %d\n\n", assembly);

	int original_err = write(-1, str, ft_strlen(str));
	printf("write -> %d\n", original_err);
	printf("write errno -> %d\n", errno);

	errno = 42;
	printf("\nerrno value after reset -> %d\n", errno);

	int assembly_err = ft_write(-1, str, ft_strlen(str));
	printf("\nft_write -> %d\n", assembly_err);
	printf("ft_write errno -> %d\n", errno);

	printf("\n------------------------------\n");
	printf("Testing -> ft_read\n");
	printf("------------------------------\n\n");

	char buffer[155];
	errno = 0;

	int fd = open("test.txt", O_RDONLY);
	printf("read return -> %ld\n", read(fd, buffer, 10));
	printf("read buffer -> ~%s~\n", buffer);
	printf("read errno -> %d\n\n", errno);
	close(fd);

	errno = 0;
	printf("errno value after reset -> %d\n\n", errno);
	memset(buffer, '\0', sizeof(buffer));

	fd = open("test.txt", O_RDONLY);
	printf("ft_read return -> %ld\n", ft_read(fd, buffer, 10));
	printf("ft_read buffer -> ~%s~\n", buffer);
	printf("ft_read errno -> %d\n", errno);
	close(fd);

	printf("\n------------------------------\n");
	printf("Testing -> ft_strdup\n");
	printf("------------------------------\n\n");

	char test42[] = "Bonjour a tous\n";

	printf("strdup -> %s", strdup(test42));
	printf("ft_strdup -> %s", ft_strdup(test42));
}
