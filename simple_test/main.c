#include "shell.h"

int main(void)
{
    info_t info = {NULL, 0};  // Assurez-vous que INFO_INIT est bien défini dans shell.h
    shell_loop(&info);
    return (0);
}
