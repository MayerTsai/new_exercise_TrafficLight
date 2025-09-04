#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep()
#include <stdlib.h> // For atoi()
#include "my_signal.h"

const int pin_2 = 2;
const int pin_3 = 3;
const int pin_4 = 4;

#define _ROAD 3
const int intersections = _ROAD;
traffic_light_t my_traffic_light[_ROAD];

int light_status = 0; // Index of the intersection that is currently green/yellow
const int G = 5;      // 綠燈轉黃燈計時時間點
const int Y = 2;      // 黃燈計時上限時間點
int Y_Time = 0;       // Yellow light timer
int G_Time = 0;       // Green light timer

void setup();
void loop();
// void my_light_timer(int current_light, int g_time, int y_time);

int main()
{
  setup();

  printf("路口數: %d", intersections);
  printf("\n");

  for (int i = 0; i < intersections; i++)
    printf("路口%d G------Y------R\t", i);
  printf("\n");

  for (int i = 0; i < intersections * (G + Y); i++)
  {
    loop();
  }
  return 0;
}

void setup()
{
  for (int i = 0; i < intersections; i++)
    set_traffic_light_pin(&my_traffic_light[i], pin_2 + i * 3, pin_3 + i * 3, pin_4 + i * 3);
}

void loop()
{
  my_light(intersections, Y_Time, light_status, my_traffic_light); // 設定通行路口為綠燈或黃燈，其他為紅燈

  G_Time++;        // 綠燈計時
  if (G_Time >= G) // 黃燈開始計時
    Y_Time++;
  if (Y_Time > Y) // 黃燈時間到，下一個路口要轉綠燈
  {
    Y_Time = 0;
    G_Time = 0;
    light_status++; // 下個路口
    if (light_status > intersections)
      light_status = 0;

    for (int i = 0; i < intersections; i++)
      printf("路口%d G------Y------R\t", i);
    printf("\n");
  }
  sleep(1);
}
