/*
** mutator.c for vector in /Users/arthur/Dev/B2/IA/dante/lib/vector/src/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Sun Apr 23 19:20:39 2017 Arthur Chaloin
** Last update Sun Apr 23 19:20:42 2017 Arthur Chaloin
*/
#include <unistd.h>
#include "vector.h"

int	vector_getsize(t_vector *vector)
{
  return (vector->size);
}

void	vector_delete(t_vector *vector, int index)
{
  if (index < 0 || vector->size <= index)
    return;
  vector->items[index] = NULL;
  while (index != vector->size - 1)
    {
      vector->items[index] = vector->items[index + 1];
      vector->items[index + 1] = NULL;
      index += 1;
    }
  vector->size -= 1;
  if (0 < vector->size && vector->size == vector->capacity / 4)
    vector_resize(vector, vector->capacity / 2);
}

void	_vector_set(t_vector *vector, int index, void *item)
{
  if (0 <= index && index < vector->size)
    vector->items[index] = item;
}

void	*_vector_get(t_vector *vector, int index)
{
  if (0 <= index && index < vector->size)
    return (vector->items[index]);
  return (NULL);
}

void	_vector_push(t_vector *vector, void *item)
{
  if (vector->size == vector->capacity)
    vector_resize(vector, vector->capacity * 2);
  vector->items[vector->size] = item;
  vector->size += 1;
}
