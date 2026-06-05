#include <stdio.h>

void calcula(float r, float *p, float *a)
{
    *p = 2 * 3.14 * r;
    *a = 3.14 * r * r;
}

int main()
{
    float r, p, a;
    scanf("%f", &r);
    calcula(r, &p, &a);
    printf("\n raio = % .2f, perimetro = % .2f, area = % .2f", r, p, a);

    return 0;
}