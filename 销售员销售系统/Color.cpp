// 改变 Windows 下 控制台的相关颜色
// 所有函数放在 名称空间 color 下

#ifndef _COLOR_CPP
#define _COLOR_CPP

#define _COLOR_BEGIN namespace color {
#define _COLOR_END }

#include <iostream>

_COLOR_BEGIN    // 名称空间起始处

// 函数列表
void colorDefault(); // 字体默认颜色
void colorRed();    // 字体变红
void colorGreen();  // 字体变绿
void colorYellow(); // 字体变黄
void colorBlue();   // 字体变蓝
void colorPurple(); // 字体变紫
void colorCyan();   // 字体变青
void colorWhite();  // 字体变白

_COLOR_END  // !namespace color


// 字体默认颜色
void color::colorDefault()
{
    std::cout << "\033[0m";
}

// 字体变红
void color::colorRed()
{
    std::cout << "\033[31m";
}

// 字体变绿
void color::colorGreen()
{
    std::cout << "\033[32m";
}

// 字体变黄
void color::colorYellow()
{
    std::cout << "\033[33m";
}

// 字体变蓝
void color::colorBlue()
{
    std::cout << "\033[34m";
}

// 字体变紫
void color::colorPurple()
{
    std::cout << "\033[35m";
} 

// 字体变青
void color::colorCyan()
{
    std::cout << "\033[36m";
}

// 字体变白
void color::colorWhite()
{
    std::cout << "\033[37m";
}


#endif // !_COLOR_CPP