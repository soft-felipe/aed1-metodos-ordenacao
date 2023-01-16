#include <stdio.h>

int main() {
    int a = 2000;
    int b = 50;
    double c = 111.080901;
    double d = 2031.290190;
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|                             TAMANHO DOS VETORES  = %6d                           |\n", a);
    printf("+-------------------------------------------------------------------------------------+\n");
    printf("|      ALGORITMO      |    N° DE VETORES    |   TEMPO TOTAL (s)   |  TEMPO MEDIO (ms) |\n");
    printf("|    INSERTION SORT   |      %5.d          |   %15.6f   |     %12.6f  |\n", b, d,c);
    return 0;
}