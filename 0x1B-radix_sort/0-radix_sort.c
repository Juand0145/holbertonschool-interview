#include "sort.h"

/**
 * radix_sort - sorts an array of ints in ascending order
 * using least significant digit radix sorting algorithm
 * @array: array of ints to sort
 * @size: size of the array of ints
 */
void radix_sort(int *array, size_t size)
{
unsigned int i = 0;
int *holder = NULL;
int digit_count = 0, current_digit = 0, divisor = 0;

if (array == NULL || size < 2)
return;

holder = malloc(sizeof(int) * size);
if (holder == NULL)
return;

digit_count = digit_counting(array, size);
while (current_digit < digit_count)
{
for (i = 0; i < size; i++)
{
divisor = get_divisor(current_digit);
insert_into_holder(array[i], divisor, holder, i);
}
for (i = 0; i < size; i++)
array[i] = holder[i];
print_array(array, size);
current_digit++;
}
free(holder);
}

/**
 * digit_counting - counts the max number of digits in array of ints
 * @array: input array of ints to count digits of
 * @size: size of the array of ints
 * Return: largest digit count of all ints in array
 */
int digit_counting(int *array, size_t size)
{
unsigned int i = 0;
int current_count = 0, max_count = 0, n = 0;

for (i = 0; i < size; i++)
{
n = array[i];
current_count = 1;
while (n / 10 != 0)
{
current_count++;
n /= 10;
}
if (current_count > max_count)
max_count = current_count;
}
return (max_count);
}

/**
 * get_divisor - sets the divisor to get the current digit of a number
 * @current_digit: current digit count to set divisor for
 * Return: divisor for corresponding digit
 */
int get_divisor(int current_digit)
{
int i = 0, divisor = 1;

/* to get specific digit, divisor needs to be set to power of ten */
/* divisor represents ones place, tens place, hundreds place, etc */
for (i = 0; i < current_digit; i++)
divisor *= 10;
return (divisor);
}

/**
 * insert_into_holder - inserts current value from array into holder,
 * sorted by current digit
 * @value: the current int value from array
 * @divisor: the current divisor to get the digit
 * @holder: the temp array to store values sorted by current digit
 * @i: the current index value of array and holder
 */
void insert_into_holder(int value, int divisor, int *holder, unsigned int i)
{
unsigned int j = 0, k = 0;
int n = 0, m = 0;

n = (value / divisor) % 10;
if (i == 0)
holder[i] = value;
else
{
for (j = 0; j < i; j++)
{
m = (holder[j] / divisor) % 10;
if (m > n)
break;
}
if (j != i)
{
for (k = i; k > j; k--)
holder[k] = holder[k - 1];
}
holder[j] = value;
}
}
