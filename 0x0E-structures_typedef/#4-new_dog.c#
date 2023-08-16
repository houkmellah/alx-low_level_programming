#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - Returns string length
 * @s: String to evaluate
 * Return: String length
 */
int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

/**
 * _strcpy - Copies a string including terminating null byte
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int len = 0, i;
    while (src[len] != '\0')
        len++;
    for (i = 0; i < len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

/**
 * new_dog - Creates a new dog structure
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 * Return: Pointer to the new dog, or NULL if failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    int len1 = _strlen(name), len2 = _strlen(owner);

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    dog->name = malloc(sizeof(char) * (len1 + 1));
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }

    dog->owner = malloc(sizeof(char) * (len2 + 1));
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }

    _strcpy(dog->name, name);
    _strcpy(dog->owner, owner);
    dog->age = age;

    return (dog);
}
