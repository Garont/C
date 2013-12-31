#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define TOWNS 6 //кол-во городов
#define MAXPATHLEN 168

// Primm Algorythm

struct city
{
    int cityname;
    int roadlength;
};

int cm[TOWNS][TOWNS] =
{
    {0, 120, 147, 142, 107, 81},
    {120, 0, 132, 42, 157, 45},
    {147, 132, 0, 108, 66, 105},
    {142, 42, 108, 0, 168, 61},
    {107, 157, 66, 168, 0, 112},
    {81, 45, 105, 61, 112, 0}
};

//      Aber Edin Yil Glaz Invers Pert
// Aber  0   120  147 142  107    81
// Edin 120   0   132  42  157    45
// Yil  147  132  0   108   66   105
// Glaz 142  42   108  0   168    61
// Inv  107  157  66  168   0    112
// Pert  81  45   105  61  112     0