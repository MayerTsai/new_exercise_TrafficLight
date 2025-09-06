#include <stdio.h>
#include "set_signal.h"

// 使用標準 C 函式定義，並採用 my_signal.h 中更具描述性的參數名稱
/*
void my_light(int road_count, int Y_time, int active_intersection, traffic_light_t *my_traffic_light)
{
  // 設定路口燈號
  for (int i = 0; i < road_count; i++)
  {
    traffic_light_state_t state;
    if (i != active_intersection) // 非綠燈路口，設定紅燈，其他燈號
            state = RED_STATE;
    else if (Y_time > 0)// 轉黃燈
      state = YELLOW_STATE;
    else// 綠燈
      state = GREEN_STATE;

    // 點燈
    set_traffic_light_state(&my_traffic_light[i], state);
    // printf("%d-%d-%d \t", my_traffic_light[i].red_pin, my_traffic_light[i].yellow_pin, my_traffic_light[i].green_pin);
    // digitalWrtire(, G_traffic);
    // digitalWrtire(....)
  }
  printf("\n");
}
*/

void set_traffic_light_pin(traffic_light_t *light, int green_pin, int yellow_pin, int red_pin)
{
  //  pinMode(green_pin, OUTPUT);
  //  pinMode(yellow_pin, OUTPUT);
  //  pinMode(red_pin , OUTPUT);
  light->green_pin = green_pin;
  light->yellow_pin = yellow_pin;
  light->red_pin = red_pin;
}

void set_traffic_light_state(traffic_light_t *light, traffic_light_state_t state)
{
  // digitalWrite(light->green_pin, state == GREEN_STATE ? HIGH : LOW);
  // digitalWrite(light->yellow_pin, state == YELLOW_STATE ? HIGH : LOW);
  // digitalWrite(light->red_pin, state == RED_STATE ? HIGH : LOW);
  light->state = state;
}
