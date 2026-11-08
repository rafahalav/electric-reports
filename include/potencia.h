#ifndef POTENCIA_H
#define POTENCIA_H

struct Potencia
{
    float potencia_1;
    float potencia_2;
    float potencia_3;
};

float ler_potencia(void);
void ler_todas_potencias(struct Potencia *potencia);

#endif
