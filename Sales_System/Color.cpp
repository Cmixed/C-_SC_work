// 改变 Windows 下 控制台的相关颜色
// 所有函数放在 名称空间 color 下

#ifndef _COLOR_CPP
#define _COLOR_CPP

#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

#define _COLOR_BEGIN namespace color {
#define _COLOR_END }

#include <iostream>

_COLOR_BEGIN    // 名称空间起始处

/*函数列表*/
void colorDefault(); // 字体默认颜色
void colorRed();    // 字体变红
void colorGreen();  // 字体变绿
void colorYellow(); // 字体变黄
void colorBlue();   // 字体变蓝
void colorPurple(); // 字体变紫
void colorCyan();   // 字体变青
void colorWhite();  // 字体变白



/*函数定义*/
// 字体默认颜色
void colorDefault()
{
    std::cout << "\033[0m";
}

// 字体变红
void colorRed()
{
    std::cout << "\033[31m";
}

// 字体变绿
void colorGreen()
{
    std::cout << "\033[32m";
}

// 字体变黄
void colorYellow()
{
    std::cout << "\033[33m";
}

// 字体变蓝
void colorBlue()
{
    std::cout << "\033[34m";
}

// 字体变紫
void colorPurple()
{
    std::cout << "\033[35m";
} 

// 字体变青
void colorCyan()
{
    std::cout << "\033[36m";
}

// 字体变白
void colorWhite()
{
    std::cout << "\033[37m";
}


// CmxxdZZJ

_COLOR_END  // !namespace color

#endif // !_COLOR_CPP