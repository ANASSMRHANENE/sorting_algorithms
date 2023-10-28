#include "sort.h"
#include <stdio.h>
/**
 *_calloc -function
 *@nmemb: number
 *@size: bit size
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nm, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nm == 0 || size == 0)
		return ('\0');
	p = malloc(nm * size);
	if (p == '\0')
		return ('\0');
	for (i = 0; i < (nm * size); i++)
		p[i] = '\0';
	return (p);
}
/**
 * counting_sort - function
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (array == '\0' || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}