#include <stdio.h>
int main()
{
    int arr[100],n,i,x;
    int flag=0;
    printf("Enter the no. of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The elements of the array are:");
    for(i=0;i<n;i++)
    {
        printf("\n%d element is %d\n",i+1,arr[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d",&x);



    for(i=0; i<n; i++)
    {
        if(arr[i]==x)
        {
            printf("%d is at %d Location", x, i+1);
            flag = 1;
        }
    }
    if(flag==0)
        printf("%d is not present in the Array", x);


    for(i=0;i<n;i++)
    
        if(x==arr[i])
        {
            flag=1;
        }
    if(flag==1)
    {
        printf("Value exists at %d",i);
    }
    else
    {
        printf("Value doesn't exist in the array");
    }
    return 0;
}