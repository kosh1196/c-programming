#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);
int main()
{
  int array0[] = {};
  int array1[] = {1};
  int array2[] = {1,1,1,1,1,1,1};
  int array3[] = {-2,-1,0};
  int array4[] = {1,-2,3,-4};
  int array5[] = {-2,-3,-4,-5};
  int array6[] = {10,9,7,2,0};
  int array7[] = {1,1,2,2,3,3,4,4};
  int array8[] = {1,2,3,-1,-2,4,5,6,7,8};
  int array9[] = {1,2,1,3,5,7,2,4,6,9};
  int array10[] = {2,4,39,67,94,102};
  int array11[] = {1,2,3,99,-3,-4,0,1};
  size_t num;

  if(maxSeq(array0,0)!=0)
    return EXIT_FAILURE;
  if(maxSeq(array1,1)!=1)
    return EXIT_FAILURE;
  if(maxSeq(array2,7)!=1)
    return EXIT_FAILURE;
  if(maxSeq(array3,3)!=3)
    return EXIT_FAILURE;
  if(maxSeq(array4,4)!=2)
    return EXIT_FAILURE;
  if(maxSeq(array5,4)!=1)
    return EXIT_FAILURE;
  if(maxSeq(array6,5)!=1)
    return EXIT_FAILURE;
  if(maxSeq(array7,8)!=2)
    return EXIT_FAILURE;
  if(maxSeq(array8,10)!=6)
    return EXIT_FAILURE;
  if(maxSeq(array9,10)!=4)
    return EXIT_FAILURE;
  if(maxSeq(array10,6)!=6)
    return EXIT_FAILURE;
  if(maxSeq(array11,8)!=4)
    return EXIT_FAILURE; 
}
