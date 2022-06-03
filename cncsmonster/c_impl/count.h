//count.h
#ifndef _COUNT_H_ //如果没有引入头文件count.h
    #define _COUNT_H_ //那就引入头文件count.h

#include "cals.h"

/*
根据公式字符串计算其值
如果输入的字符串能够成功计算，返回1
否则，返回0
*/
int sz_count(char* f,double* outcome);

//根据输入的公式字符串计算简单字符串值

int sz_easycount(char* f,double* outcome);




#endif