#ifndef ENERGIA_H
#define ENERGIA_H

struct Energia
{
    float energia_1;
    float energia_2;
    float energia_3;
};

float ler_energia(void);
void ler_todas_energias(struct Energia *energia);

#endif
