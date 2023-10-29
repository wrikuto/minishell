#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <fcntl.h>

int main() {
	int	fd = 0;

	fd = creat("new_file.txt", O_RDWR);



    return 0;
}