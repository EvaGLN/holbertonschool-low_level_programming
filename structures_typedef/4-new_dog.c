#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - create a new dog
 * @name: of the dog
 * @age: of the dog
 * @owner: of the dog
 * Return: pointer to the dog created or NULL if fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	char *copy_name, *copy_owner;
	dog_t *my_dog;

	for (copy_name = 0; name[copy_name]; copy_name++)
	{
	}
	for (copy_owner = 0; owner[copy_owner]; copy_owner++)
	{
	}
	my_dog = malloc(sizeof(dog_t));
	if (my_dog == NULL)
	{
		return (NULL);
	}
	my_dog->name = malloc(copy_name);
	if (my_dog->name == NULL)
	{
		return (NULL);
	}
	my_dog->owner = malloc(copy_owner);
	if (my_dog->owner == NULL)
	{
		return (NULL);
	}
	my_dog->name = name;
	my_dog->age = age;
	my_dog->owner = owner;
	return (my_dog);
}
