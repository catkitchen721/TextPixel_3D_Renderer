#ifndef __GAMESTATUS_H__
#define __GAMESTATUS_H__

#define boolean int  // 定義布林型態
#define True 1  // True為1
#define False 0  // False為0

boolean isFrameUpdated;  // 稍後會使用到，確認此時是否需更新畫面

void initGameStatus();  // 將isFrameUpdated初始化為True

#endif // __GAMESTATUS_H__
