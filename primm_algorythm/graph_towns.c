//includes
#include "graph_towns.h"
#include "heapsort.c"
#include "binsearch.c"

char *cityvector(int);

////debug
int allroadsthere(int cm[TOWNS][TOWNS], int where)
{
    int i;
    printf("All roads from %s: ", cityvector(where));
    for (i = 0; i < TOWNS; i++)
    {
        printf("%d ", cm[where][i]);
    }
    printf("\n");
}

void checkedcities(int checked_city[TOWNS])
{
    int i;
    printf("Visited city: ");
    for (i = 0; i < TOWNS; i++)
    {
        if (checked_city[i] != -1)
            printf(" %s (%d)", cityvector(checked_city[i]), checked_city[i]);
    }
    printf("\n");
    printf("------------------\n");
}

char *cityvector(int i)
{
    char *cityvector[] = {"Aberdin", "Edinburg", "Fort Yilyam",
                          "Glazgo", "Invers", "Pert"
                         };

    return cityvector[i];
}
////end debug


void search_shortest_way(int cm[TOWNS][TOWNS], int city, int search_correction, struct city *n)
{
    int i;
    int shortest_road = MAXPATHLEN;
    int next_city = -1;

    for (i = 0; i < TOWNS; i++)
    {
        if ((cm[city][i] > 0) && (cm[city][i] < MAXPATHLEN) && (cm[city][i] < shortest_road) && (cm[city][i] > search_correction))
        {
            shortest_road = cm[city][i];
            next_city = i;
        }
    }

    n->cityname = next_city;
    n->roadlength = shortest_road;
}

int sort_and_search(int where_to_search[TOWNS], int arraysize, struct city *n)
{
    int i;
    int array[TOWNS];
    memcpy(array, where_to_search, sizeof(array));
    makeheap(array, arraysize);
    heapsort(array, arraysize);
    return search(array, n->cityname, arraysize);
}

int main(int argc, char const *argv[])
{
    int i;
    srand(time(NULL));
    int checked_city[TOWNS]; 
    int position_in_array = 0;

    struct city next_city;
    next_city.cityname = 0;
    next_city.roadlength = 0;

    memset(&checked_city, -1, sizeof(checked_city)); 
    int current_city = rand() % TOWNS; // first city

    checked_city[position_in_array++] = current_city; 

    printf("First city: %s\n", cityvector(current_city));
    search_shortest_way(cm, current_city, 0, &next_city); 


    while (position_in_array < TOWNS) // while wasn't been in all cities
    {
        // allroadsthere(cm, current_city); // all roads from currient city
        if (sort_and_search(checked_city, TOWNS, &next_city) >= 0)
        {
            printf("%s Was visited. Searchin another way\n", cityvector(next_city.cityname));
            search_shortest_way(cm, current_city, next_city.roadlength, &next_city);
        }
        else
        {
            printf("%s Wasn't visited\n", cityvector(next_city.cityname));
            current_city = next_city.cityname;
            search_shortest_way(cm, current_city, 0, &next_city);
            checked_city[position_in_array++] = current_city;       
        }
        checkedcities(checked_city);
    }
    return 0;
}