#include "hsh.h"

int main(void)
{
    while (1)
    {
        printf("$ ");    /* Mostrar el prompt */
        shell_loop();    /* Llamada correcta sin argumentos y sin asignar valor */
    }
    return (0);
}
