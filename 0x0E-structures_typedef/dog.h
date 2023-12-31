#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Info about a dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 * Description: More details about the dog structure
 */
struct dog
{
char *name;
float age;
char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
