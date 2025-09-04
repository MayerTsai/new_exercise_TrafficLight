#include <stdio.h>
#include "my_signal.h"

// 使用標準 C 函式定義，並採用 my_signal.h 中更具描述性的參數名稱
void my_light(int road_count, int Y_time, int active_intersection)
{
  // 設定路口燈號
  for (int i = 0; i < road_count; i++)
  {
    int R_traffic = 0;
    int G_traffic = 0;
    int Y_traffic = 0;

    if (i != active_intersection) // 非綠燈路口，設定紅燈，其他燈號
      R_traffic = 1;
    else if (Y_time > 0)
      Y_traffic = 1; // 轉黃燈
    else
      G_traffic = 1; // 綠燈

    // 點燈
    printf("%d-%d-%d \t", R_traffic, Y_traffic, G_traffic);
    // digitalWrtire(....)
  }
  printf("\n");
}