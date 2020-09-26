/* File: Renderer.h */

#ifndef __RENDERER_H__
#define __RENDERER_H__

#define _CLEAN_MODE_ 0
#define _RENDER_MODE_ 1

float camera_x_pos, camera_y_pos, camera_z_pos;  // 攝影機(大家的螢幕)位置
float camera_speed;  // 相機移動速度，決定按下同樣按鍵時間攝影機移動快慢
float fov;  // 視野，等同於前幾天所說的esd(眼睛到螢幕距離)
float x1, y1, z1, x2, y2, z2;  // 畫直線時用來暫存兩端點的變數
double rot_x, rot_y;  // 沿x, y軸轉動的角度
double sin_x, cos_x, sin_y, cos_y;  // 算好後的三角函數放這裡
int rx, ry;  // 最後輸出到螢幕上的二維座標

void init_renderer();  // 初始化以上所有變數
void div_zero_adjust(float *n);  // 遇到z = 0的特殊情況時，將z調整為0.5避免程式出錯

void render_line(char style, int lx1, int ly1, int lz1, int lx2, int ly2, int lz2);
// 畫線的函數，所有圖形繪製中樞

void render_zplane(char style, int cx, int cy, int cz, int left, int right, int top, int bottom);
void render_yplane(char style, int cx, int cy, int cz, int left, int right, int f, int r);
void render_xplane(char style, int cx, int cy, int cz, int top, int bottom, int f, int r);
// 畫平面的函數，由多組render_line組合而成

void render_cube(char style, int cx, int cy, int cz, int left, int right, int top, int bottom, int f, int r);
// 畫方塊，由畫平面的組合而成

void render_screen(int mode);
// 繪製出一幀內所有存在的圖形

void calc_tri();
// 事先計算三角函數值(較費時)

#endif // __RENDERER_H__
