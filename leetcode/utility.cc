#include <stdio.h>

int main()
{
  char my_array[100] = "some cool string";
  printf("my_array = %p\n", my_array);
  printf("&my_array = %p\n", &my_array);

  char *pointer_to_array = my_array;
  printf("pointer_to_array = %p\n", pointer_to_array);
  printf("&pointer_to_array = %p\n", &pointer_to_array);

  printf("Press ENTER to continue...\n");
  getchar();
  return 0;
}
