/* File: main.c */

#include <stdio.h>  // 標準輸入輸出
#include <stdlib.h>  // 標準函式庫
#include <windows.h>  // 控制視窗用
#include <math.h>  // 數學函式庫(三角函數、四捨五入等等)

#include "RenderMemory.h"  // 繪製記憶體
#include "SystemSetting.h"  // 系統設定
#include "GameStatus.h"  // 遊戲狀態
#include "Renderer.h"  // 繪製器

#define M_PI acos(-1.0)  // 因為cos(PI) = -1，所以用arccos(-1)來反向定義PI。
                         // 但此方法須引入"math.h"標頭檔

int main(int argc, char *argv[])
{
    init_render_memory();  // 先初始化memory

    setting_system();  // 設置視窗屬性

    initGameStatus();  // 初始化遊戲狀態(畫面是否更新初始化為True)

    init_renderer();  // 初始化Renderer，設置好所有相關變數值

    int i = 0, j = 0;  // 設置好給for迴圈使用的計數器

    for(;;)  /* 主要的無窮迴圈，每循環一次一個週期 */
    {
        if(isFrameUpdated)  // 若上個週期更新了Renderer中的變數，
        {                   // 則isFrameUpdated已被設為True，此週期將清空原畫面並以新變數重繪
            selfCls();  // 游標移到左上角，準備覆蓋舊畫面
            for(i=0;i<SCREEN_HEIGHT;i++)
            {
                for(j=0;j<SCREEN_WIDTH;j++)
                {
                    printf("%c", render_memory[i][j]);  // 印出繪製記憶體中的畫面
                }
            }

            // 以下部分為Debug用，可看出各項變數變化
            printf("Camera x: %f\n", camera_x_pos);
            printf("Camera y: %f\n", camera_y_pos);
            printf("Camera z: %f\n", camera_z_pos);
            printf("sin x: %f\n", sin_x);
            printf("sin y: %f\n", sin_y);
            printf("cos x: %f\n", cos_x);
            printf("cos y: %f\n", cos_y);
            printf("rotate x: %f\n", rot_x);
            printf("rotate y: %f\n", rot_y);
            printf("FOV: %f\n", fov);

            isFrameUpdated = False;  // 將上一周期被設為True的isFrameUpdated設回False
        }

        if(GetAsyncKeyState(87) != 0)  /*W*/
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos += cos_y * camera_speed;
            camera_x_pos -= sin_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(83) != 0)  /*S*/
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= cos_y * camera_speed;
            camera_x_pos += sin_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(65) != 0)  /*A*/
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= sin_y * camera_speed;
            camera_x_pos -= cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(68) != 0)  /*D*/
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos += sin_y * camera_speed;
            camera_x_pos += cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(66) != 0)  /*B*/  // up
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos -= 2;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(78) != 0)  /*N*/  // down
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos += 2;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(VK_LEFT) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_RIGHT) != 0)
            {
                rot_y -= camera_speed * 0.006;
            }
            if(GetAsyncKeyState(VK_LEFT) != 0)
            {
                rot_y += camera_speed * 0.006;
            }
            if(rot_y > M_PI * 2 || rot_y < -(M_PI * 2)) rot_y = 0.0;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(VK_DOWN) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_UP) != 0)
            {
                rot_x -= camera_speed * 0.006;
            }
            if(GetAsyncKeyState(VK_DOWN) != 0)
            {
                rot_x += camera_speed * 0.006;
            }
            if(rot_x > M_PI / 10) rot_x = M_PI / 10;
            else if(rot_x < -(M_PI / 10)) rot_x = -(M_PI / 10);
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            return 0;
        }
    }

    return 0;
}
