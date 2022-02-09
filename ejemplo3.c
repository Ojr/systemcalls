#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/sendfile.h>
#include <sys/random.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
 
#define BUFFER_SIZE 67108864
 
int main() {
 
    int fOut, fIn;
 
    printf("\nI/O utilizando sendfile\n\n");
 
    printf("Apartando 64 MB buffer:                      ");
    char *buffer = (char *) malloc(BUFFER_SIZE);
    printf("Hecho\n");
 
    printf("Escribiendo en el primer buffer:             ");
    fOut = open("buffer1", O_RDONLY);
    write(fOut, &buffer, BUFFER_SIZE);
    close(fOut);
    printf("Hecho\n");
 
    printf("Copiando datos del archivo 1 al archivo 2:   ");
    fIn = open("buffer1", O_RDONLY);
    fOut = open("buffer2", O_RDONLY);
    sendfile(fOut, fIn, 0, BUFFER_SIZE);
    close(fIn);
    close(fOut);
    printf("Hecho\n");
 
    printf("Liberando buffer:                            ");
    free(buffer);
    printf("Hecho\n");
 
    printf("Eliminando buffers:                          ");
    unlink("buffer1");
    unlink("buffer2");
    printf("Hecho\n");
 
    return 0;
}
