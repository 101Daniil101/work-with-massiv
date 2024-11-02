#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int* inizialisation(int* array, int size)
{   
    free(array);
    int* ptr;
    ptr = (int* )malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        scanf("%d", &ptr[i]);
    return ptr;
}

int* insert(int* array, int size, int value, int index)
{
    int* ptr;
    int i = 0;
    //А почему тут не объявить index и value? Функция диалоговая и что... Зато переменные хранятся в стеке функции а удаляются вместе с ней сразу

    ptr = (int* )malloc((size + 1) * sizeof(int));

    if (index <= 0)
        return array;
    
    index = (index >= size) ? size: index;
    while (i < size + 1)
    {   
        if (i < index)
        {
            ptr[i] = array[i];
        }
        else if (i > index)
        {
            ptr[i] = array[i - 1];
        }
        else
        {
            ptr[i] = value;
        }
        i++;
    }
    free(array);
    return ptr;
}

int* pop(int* array, int size, int index)
{
    int *ptr;
    int i = 0;

    if (index <= 0)
        return array;

    ptr = (int* )malloc((size - 1) * sizeof(int));

    while (i < size - 1)
    {
        if (i < index)
        {
            ptr[i] = array[i];
        }
        else
        {
            ptr[i] = array[i + 1];
        }
        i ++;
    }

    free(array);
    return ptr;
}

int data_processing(int* array, int size)
//Функция изменяет массив array: элементы, которые не подходят условию в индивидуальном задании я просто смещаю в начало массива (типо удаление путем смещения)
//А возвращает функция как раз-таки номер последнего такого +1 в начале массива. И потом я уже в main-е убираю ненужную часть через realloc. Это так и надо делать? 
{   
    int k = 0;
    for (int i = 0; i < size; i++)
    {   
        int count = 0; // Количество разрядов
        int item = abs(array[i]);
        int flag = 1;
        int number1 = -1;
        int number2 = 0;

        while (item > 0)
        {
            item = item / 10;
            count += 1;
        }   
        
        if (count == 1)
            flag = 0;
        
        item = abs(array[i]);
        for (int j = 1; j <= count && flag; j++)
        {   
            number2 = (item / pow_my(10, count - j)) % 10;

            if (number2 < number1)
                flag = 0;

            number1 = number2;
        }

        if (!flag)
        {   
            array[k] = array[i];
            k += 1;
        }
    }
    return k;
}

void array_output(int* array, int size)
{   
    printf("Array output:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int pow_my(int item, int power)
{   
    int res = 1;
    for (int i = 0; i < power; i++)
    {
        res *= item;
    }
    return res;
}
