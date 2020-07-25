#include <stdio.h>


void minmax(int a[],int len)
{
  int min,max,i;
  min=max=a[0];
  for(i=0;i<len;i++)
  {
    if(min>a[i])
            min=a[i];
    if(max<a[i])
            max=a[i];
  }
  printf("Minimum is: %d\n",min);
  printf("Maximum is: %d\n",max);
}
int main(void) {
  /*int num1,num2,sum;
  printf("Enter Number 1: \n");
  scanf("%d",&num1);
  printf("Enter Number 2: \n");
  scanf("%d",&num2);
  sum=num1+num2;
  printf("Sum is: %d\n",sum);
  printf("Hello World\n");*/

  /*char name[10];
  printf("Enter Name: \n");
  scanf("%s",name);
  printf("Name is %s \n",name);
  */
  int arr[20],i,len,j;
  printf("Enter array length: \n");
  scanf("%d",&len);
  for(i=0; i<len; i++)
  {
    printf("Enter number %d: \n",i+1);
    scanf("%d",&arr[i]);
  }
  minmax(arr,len);
  return 0;
}