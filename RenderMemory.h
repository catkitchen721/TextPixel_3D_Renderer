/* File: RenderMemory.h */

#ifndef __RENDERMEMORY_H__  // 怕別的標頭檔的定義互撞而加註，習慣是寫標頭檔都會加。
#define __RENDERMEMORY_H__  // 命名潛規則：兩次底線+全大寫檔名+一次底線+大寫H+兩次底線

#define WIDTH_USER_SET 60  // 在這邊設置真正想要的高寬
#define HEIGHT_USER_SET 30
#define SCREEN_WIDTH (WIDTH_USER_SET + 1)  // 在文字介面中，「換行符」雖然無法被看到，
                                           // 卻占一格在那邊，所以必須將我們設定的值 + 1
#define SCREEN_HEIGHT (HEIGHT_USER_SET)

char render_memory[SCREEN_HEIGHT][SCREEN_WIDTH];  // char型態二維陣列作為繪製記憶體

void init_render_memory();  // 將render memory初始化用

#endif // __RENDERMEMORY_H__
