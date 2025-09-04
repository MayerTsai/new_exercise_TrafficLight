#include <stdio.h>
#include "my_light.h"
#include "my_signal.h"

int R_traffic = 0;
int G_traffic = 0;
int Y_traffic = 0;
int light_status = 0;         // 哪個路口綠燈 循環完+1
int intersections_status = 0; // 每次循環++
const int Y = 2;              // 黃燈時間
const int G = 5;              // 綠燈時間
int Y_Time = 0;
int G_Time = 0; // 綠燈狀態

void traffic_signal(int road)
{
  for (int i = 0; i < road; i++)
  {

    int x = my_light(i, Y_Time, light_status); // my_light = 0紅 1綠 2黃

    switch (x)
    {
    case 0:
      R_traffic = 1;
      G_traffic = 0;
      Y_traffic = 0;
      break;
    case 1:
      R_traffic = 0;
      G_traffic = 1;
      Y_traffic = 0;
      break;
    default:
      R_traffic = 0;
      G_traffic = 0;
      Y_traffic = 1;

      break;
    }

    printf("%d %d %d\t", R_traffic, Y_traffic, G_traffic);
  }

  G_Time++;
  if (G_Time >= G) // 綠燈時間5s
  {
    Y_Time++;
  }
  if (Y_Time > Y)
  {
    Y_Time = 0;
    G_Time = 0;
  }
  if (G_Time == 0)
    light_status++;

  if (light_status == road)
  {
    light_status = 0;
  }

  printf("\n");
}