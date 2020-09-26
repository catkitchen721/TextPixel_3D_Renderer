/* File: RenderMemory.c */

#include "RenderMemory.h"  // 注意是用引號「""」括住，非內建標頭的角括號「<>」

void init_render_memory()
{
    int i = 0, j = 0;

    for(i=0;i<SCREEN_HEIGHT;i++)  // 雙重迴圈將memory內全部填上' ' (空白符)
    {
        for(j=0;j<SCREEN_WIDTH;j++)
        {
            if(j == SCREEN_WIDTH - 1)  // 此處就是為什麼需要將寬先加一，
            {                          // 若寬的部分在同一列的最後一格，則填換行('\n')
                render_memory[i][j] = '\n';
            }
            else                       // 反之就是空格
            {
                render_memory[i][j] = ' ';
            }
        }
    }
}
