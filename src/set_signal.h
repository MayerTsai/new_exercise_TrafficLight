#ifndef SET_SIGNAL_H
#define SET_SIGNAL_H
#include <stdio.h>

typedef enum
{
  GREEN_STATE,
  YELLOW_STATE,
  RED_STATE
} traffic_light_state_t;

typedef struct
{
  int green_pin;
  int yellow_pin;
  int red_pin;
  traffic_light_state_t state;
} traffic_light_t;

void set_traffic_light_pin(traffic_light_t *light, int green_pin, int yellow_pin, int red_pin);
void set_traffic_light_state(traffic_light_t *light, traffic_light_state_t state);

// void my_light(int road_number, int Y_time, int active_intersection, traffic_light_t *my_traffic_light);

#endif // SET_SIGNAL_H