//cals.h
#ifndef _CALS_H_ //如果没有引入头文件cals.h
    #define _CALS_H_ //那就引入头文件cals.h


/*
删除字符串中的无效字符
可以用来把字符串中的空格删去
*/
int mystrip(char* str,char* ig);



//判断一个字符串是否是合法的四则运算公式串,如果是返回1，否则返回0
int if_sz(char* str);

//判断一个字符串是否是简单的只有一个运算符的四则运算式子
int if_easy_sz(char* str);








#endif