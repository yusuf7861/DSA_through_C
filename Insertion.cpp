#include<stdio.h>
int main()
{
    int a[50], pos, size, i;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: \n");
    for(i=0; i<size; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the position, where you wish to add element.");
    scanf("%d", &pos);
    
    if(pos <= 0 || pos > size){
        printf("Invalid position.\nPlease enter valid position again.");
        return 1;
    }
    // Insertion in an array
    for(i=size-1; i>=pos-1; i--)
    {
        a[i+1] = a[i];
    }
    size++;
    
    printf("Elements of the array are: \n");
    for(i=0; i<size; i++)
    {
        printf("%d\t", a[i]);
    }
}