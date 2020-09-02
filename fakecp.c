#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
char buffer[2048];
int version = 1;

void copy(int old, int new);

int main(int argc, char *argv[]){
	int fdold;
	int fdnew;

	if(argc != 3){
		printf("son necesarios al menos 2 argumentos para copiar\n");
		exit(1);
	}

	fdold = open(argv[1], O_RDONLY);
	if(fdold == -1){
		printf("No se puede abrir el archivo %s\n", argv[1]);
		exit(1);
	}
	
	fdnew = creat(argv[2], 0666);
	if(fdnew == -1){
		printf("No se puede abrir el archivo %s\n", argv[2]);
		exit(1);
	}

	copy(fdold, fdnew);
	exit(0);

	return 0;
}

void copy(int old, int new){
	int count;

	while( (count = read(old, buffer, sizeof(buffer))) > 0){
		write(new, buffer, count);
	}
}
