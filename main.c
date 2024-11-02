#include <stdio.h>
#include <stdlib.h>
#include "func.h"

//Сделал без проверок на ввод значений... Ну их не сложно вроде
// realloc использовал только в этом файле, потому что забыл что он вообще существует

int main(){
    char choice;
    int *array = NULL;
    int size = 0;

    int index;
    int value;

    do
    {   
        printf("Menu:\n");
        printf("a - initializing an array\nb - inserting a new array element by index\nc - deleting an element\nd - data processing\ne - array output\nother letter - exit\n");
        printf("Enter one of the listed letters to proceed to the action: "); //"Введите одну из перечисленных букв, чтобы перейти к действию"
        scanf("%c", &choice);

        switch (choice)
        {

            case 'a':
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter the array elements:\n");
                array = inizialisation(array, size);
                array_output(array, size);
                break;

            case 'b':
                if (array != NULL)
                {
                    printf("Enter the value of the element and the index:\n"); //Если что индексация элементов начинается с одного
                    scanf("%d %d", &value, &index);
                    array = insert(array, size, value, index - 1);
                    size += 1; //Скорее всего можно сделать поумнее
                    array_output(array, size);
                }
                else
                    printf("The array is uninitialized\n");
                break;

            case 'c':
                if (array != NULL)
                {
                    printf("Enter the number of the item you want to delete:\n");
                    scanf("%d", &index);
                    array = pop(array, size, index - 1);
                    size -= 1; //Скорее всего можно сделать поумнее
                    array_output(array, size);
                }
                else
                    printf("The array is uninitialized\n");
                break;
            
            case 'd':
                if (array != NULL)
                {
                    size = data_processing(array, size); //Ну тут я только так догадался это сделать
                    array = (int* )realloc(array, size * sizeof(int)); 
                    array_output(array, size); 
                }
                else
                    printf("The array is uninitialized\n");
                break;

            case 'e':
                if (array != NULL)
                {
                    array_output(array, size);  
                }
                else
                    printf("The array is uninitialized\n");
                break;

            default:
                choice = 'f';
                break;
        }
        printf("\n");
        
        while (getchar() != '\n');
    } while (choice != 'f');
    free(array);
}

