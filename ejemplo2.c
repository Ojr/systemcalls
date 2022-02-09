#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/random.h>
 
#define BUFFER_SIZE 67108864
#define BUFFER_1 "buffer1"
#define BUFFER_2 "buffer2"
 
int main() {
 
    FILE *fOut, *fIn;
 
    printf("\nI/O Prueba utilizando las librerias standar de c\n");
 
    printf("Apartando  64 MB buffer:                     ");
    char *buffer = (char *) malloc(BUFFER_SIZE);
    printf("Hecho\n");
 
    printf("Escribiendo datos en el primer buffer:       ");
    fOut = fopen(BUFFER_1, "wb");
    fwrite(buffer, sizeof(char), BUFFER_SIZE, fOut);
    fclose(fOut);
    printf("Hecho\n");
    printf("---------------------------------------------\n");
 
    printf("Escribiendo en el otro buffer:               ");
    printf("Pasando del buffer_1 al buffer_2             ");
    fIn = fopen(BUFFER_1, "rb");
    fOut = fopen(BUFFER_2, "wb");
    fread(buffer, sizeof(char), BUFFER_SIZE, fIn);
    fwrite(buffer, sizeof(char), BUFFER_SIZE, fOut);
    fclose(fIn);
    fclose(fOut);
    printf("Hecho\n");
 
    printf("Liberando el buffer                          ");
    free(buffer);
    printf("hecho\n");
 
    printf("Limpiando todo                               ");
    remove(BUFFER_1);
    remove(BUFFER_2);
    printf("Hecho\n");
 
    return 0;
 
}
