#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep()
#include "my_light.h"

int intersections;
int loop = 0;

int main()
{
  do
  {
    printf("路口數:");
    scanf("%d", &intersections);
    if (intersections >= 2 && intersections <= 7)
      loop = 0;
    else
    {
      loop = 1;
      printf("輸入錯誤，請重新輸入\n");
    }
  } while (loop);

  printf("\n");
  while (1)
  {
    traffic_signal(intersections);
    sleep(1);
  }
  return 0;
}