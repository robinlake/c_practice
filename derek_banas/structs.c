#include <stdlib.h>
#include <stdio.h>

struct dog{
    const char *name;
    const char *breed;
    const int avgHeightCm;
    const int avgWeightLbs;

};

void getDogInfo(struct dog theDog) {
    printf("Name : %s\n\n", theDog.name);
    printf("Breed : %s\n\n", theDog.breed);
    printf("Avg Height: %d cm\n\n", theDog.avgHeightCm);
    printf("Avg Weight: %d lbs\n\n ", theDog.avgWeightLbs);
}

void getMemoryLocations(struct dog theDog) {
    printf("Name Location: %d\n\n", theDog.name);
    printf("Breed Location: %d\n\n", theDog.breed);
    printf("Avg Height Location: %d\n\n", &theDog.avgHeightCm);
    printf("Avg Weight Location: %d\n\n", &theDog.avgWeightLbs);
}

int main()
{
    struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};
    struct dog cujo2 = cujo;

    getDogInfo(cujo);
    getMemoryLocations(cujo);
    getMemoryLocations(cujo2);
}
