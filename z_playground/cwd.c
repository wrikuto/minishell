#include <unistd.h> // fork(), execve()
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	char	*str = "/Users/user/wrikuto/";
	char	*cwd;
	size_t	size;

	if (chdir(str) < 0)
		perror("chdir");
	cwd = getcwd(NULL, 0);
	if (cwd == NULL) {
		if (errno == ERANGE) {
			// バッファサイズが不足している場合の処理
			fprintf(stderr, "Error: Buffer size is too small.\n");
		} else {
			// その他のエラーの場合の処理
			perror("getcwd error");
		}
		// エラー処理を行った後、必要に応じてプログラムを終了する
		exit(EXIT_FAILURE);
	}
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}