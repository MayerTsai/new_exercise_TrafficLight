#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep()
#include <stdlib.h> // For atoi()
#include "set_signal.h"

const int pin_2 = 2;
const int pin_3 = 3;
const int pin_4 = 4;

#define _ROAD 5
const int intersections = _ROAD;
traffic_light_t my_traffic_light[_ROAD];

// int light_status = 0; // Index of the intersection that is currently green/yellow
const int G = 5; // 綠燈轉黃燈計時時間點
const int Y = 2; // 黃燈計時上限時間點
// int Y_Time = 0;       // Yellow light timer
int G_Time = 0; // Green light timer

traffic_light_state_t active_light_state;
int active_intersection;

void setup();
void loop();
void show_light_status();
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

  active_light_state = GREEN_STATE;
  active_intersection = 0;
  for (int i = 0; i < intersections; i++)
  {
    if (i == active_intersection)
      set_traffic_light_state(&my_traffic_light[active_intersection], GREEN_STATE);
    else
      set_traffic_light_state(&my_traffic_light[i], RED_STATE);
  }
}

void loop()
{
  // my_light(intersections, Y_Time, light_status, my_traffic_light); // 設定通行路口為綠燈或黃燈，其他為紅燈
  show_light_status();
  G_Time++;        // 綠燈計時
  if (G_Time == G) // 轉黃燈
  {
    set_traffic_light_state(&my_traffic_light[active_intersection], YELLOW_STATE);
    active_light_state = YELLOW_STATE;
  }
  else if (G_Time == Y + G) // 轉紅燈，下個路口轉綠燈，並重新計時
  {
    set_traffic_light_state(&my_traffic_light[active_intersection], RED_STATE);
    active_intersection++;
    if (active_intersection >= intersections)
      active_intersection = 0;
    set_traffic_light_state(&my_traffic_light[active_intersection], GREEN_STATE);
    active_light_state = GREEN_STATE;
    G_Time = 0;
    for (int i = 0; i < intersections; i++)
      printf("路口%d G------Y------R\t", i);
    printf("\n");
  }
  sleep(1);
}

void show_light_status()
{
  for (int i = 0; i < intersections; i++)
  {
    printf("[%d(%d) - %d(%d) - %d(%d)]\t",
           my_traffic_light[i].green_pin, (my_traffic_light[i].state == GREEN_STATE) ? 1 : 0,
           my_traffic_light[i].yellow_pin, (my_traffic_light[i].state == YELLOW_STATE) ? 1 : 0,
           my_traffic_light[i].red_pin, (my_traffic_light[i].state == RED_STATE) ? 1 : 0);
  }
  printf("\n");
}