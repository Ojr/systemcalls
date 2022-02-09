#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>



unsigned cpu, node;


/*
 * las llamadas al sistema tienen un identificador
 * debemos incluir el syscall header para obtener estas constantes
 */

/*
int main(void) {
  printf("Sope 1\n");
  printf("El identificador de Syscall write es: %d\n", SYS_write);
  printf("El identificador de Syscall cpu es: %d\n", SYS_getcpu);
  return 0;
}
*/

/*
 * podemos utilizar las funciones de wrapper que estan definidas
 * en las librerias de c
 */

/*
int main(void) {
   write(1, "Usando wrapper de c\n", 21);
}
*/


/*
 * O podemos utilizar la funcion de syscall para invocarlas
 */

/*
int main(void) {
  syscall(SYS_write, 1, "hola \n", 8);
  syscall(SYS_getcpu, &cpu, &node, NULL);
  printf("cpu: %u, NUMA:%u", cpu, node);
  return 0;
}
*/


int main(void) {
  register int    syscall_no  asm("rax") = 1;
  register int    arg1        asm("rdi") = 1;
  register char*  arg2        asm("rsi") = "Holi!! \n";
  register int    arg3        asm("rdx") = 14;
  asm("syscall");
  return 0;
}
