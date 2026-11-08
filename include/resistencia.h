#ifndef RESISTENCIA_H
#define RESISTENCIA_H

struct Resistencia
{
    float resistencia_1;
    float resistencia_2;
    float resistencia_3;
};

float ler_resistencia(void);
void ler_todas_resistencias(struct Resistencia *resistencia);

#endif
