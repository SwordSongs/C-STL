#include<iostream>
#include<ratio>
#include<chrono>
using namespace std;

int main()
{
    //数值：tick类型, 对应构造入参, 分数: 秒计单位类型
    std::chrono::duration<int> twentySenonds(20);  
    std::chrono::duration<double, ratio<60>> halfMinute(0.5);     /* 60/1 秒*/
    std::chrono::duration<long, ratio<1, 1000>> milliSecond(1);   /* 1/1000 秒*/







    return EXIT_SUCCESS;
}

