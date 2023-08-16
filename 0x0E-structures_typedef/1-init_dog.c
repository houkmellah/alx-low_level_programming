#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initializes a struct dog variable
 * @d: Pointer to struct dog to initialize
 * @name: Name for initialization
 * @age: Age for initialization
 * @owner: Owner for initialization
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
d = malloc(sizeof(struct dog));
d->name = name;
d->age = age;
d->owner = owner;
}
