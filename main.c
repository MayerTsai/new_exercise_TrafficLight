#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep()
#include <stdlib.h> // For atoi()
#include "my_signal.h"

const int G = 5; // 綠燈轉黃燈計時時間點
const int Y = 2; // 黃燈計時上限時間點

int light_status = 0; // Index of the intersection that is currently green/yellow
int Y_Time = 0;       // Yellow light timer
int G_Time = 0;       // Green light timer
int intersections;

void loop();

int main()
{
  printf("路口數(2~7):");
  while (scanf("%d", &intersections) == 1)
  {
    if (intersections >= 2 && intersections <= 7)
      break;
    printf("路口數(2~7):");
  }

  for (int i = 0; i < intersections; i++)
    printf("路口%d\t", i);
  printf("\n");

  for (int i = 0; i < intersections; i++)
    printf("R-Y-G\t");
  printf("\n");

  for (int i = 0; i < intersections; i++)
    printf("------\t");
  printf("\n");

  while (1)
  {
    loop();
  }
  return 0;
}

void loop()
{
  my_light(intersections, Y_Time, light_status); // 設定通行路口為綠燈或黃燈，其他為紅燈
  G_Time++;                                      // 綠燈計時
  if (G_Time >= G)                               // 黃燈開始計時
    Y_Time++;
  if (Y_Time > Y) // 黃燈時間到，下一個路口要轉綠燈
  {
    Y_Time = 0;
    G_Time = 0;
    light_status++; // 下個路口
    if (light_status >= intersections)
      light_status = 0;
    for (int i = 0; i < intersections; i++)
      printf("------\t");
    printf("\n");
  }
  sleep(1);
}