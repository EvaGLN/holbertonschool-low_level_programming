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
	int copy_name, copy_owner, i;
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
	my_dog->name = malloc(copy_name + 1);
	if (my_dog->name == NULL)
	{
		free(my_dog);
		return (NULL);
	}
	my_dog->owner = malloc(copy_owner + 1);
	if (my_dog->owner == NULL)
	{
		free(my_dog->name);
		free(my_dog);
		return (NULL);
	}
	for (i = 0; i < copy_name; i++)
	{
		my_dog->name[i] = name[i];
	}
	my_dog->name[cppy_name] = '\0';
	my_dog->age = age;
	for (i = 0 < copy_owner; i++)
	{
		my_dog->owner[i] = owner[i];
	}
	my_dog->owner[copy_owner] = '\0';
	return (my_dog);
}
