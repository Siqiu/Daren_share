/*
 * Copyright (c) Daren Hi-Tech Electronics Co., Ltd. Development Team 2020-2020. All rights reserved.
 * File name:   main.c
 * Author: Donn1e      ID：      Version: V1.0.0       Date: 2021.01.07
 * Description: AT指令的异或校验 测试代码
 * Others:
 * History:
 */

#include "protocal_at_checkbyte.h"
#include <stdlib.h>

/**
 * @Description:    函数用于判断字符串str2是否是str1的子串。
 *                  如果是，则该函数返回 str1字符串从 str2第一次出现的位置开始到 str1结尾的字符串；
 *                  否则，返回NULL。
 * @param s1 - 字符指针.
 * @param s2 - 字符指针.
 * @return
 */
char *rt_strstr(const char *s1, const char *s2) {
    int l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *) s1;
    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *) s1;
        s1++;
    }

    return NULL;
}

int main() {
    uint8_t *p1;
    uint8_t check_byte = 0;
    uint8_t TestString[] = "AT+01GPINF,1.01,200000000000002,30000000000000000003,4,500005,1,7,8,114.05707,22.754436,210106153606, 12, 13,*,77(0x0D,0X0A)";

    p1 = (uint8_t *) rt_strstr((const char *) TestString, "+") + 1;//attention + 号不是我们所需要的，所以这里地址加+1

    printf("\ncheck string:01GPINF,1.01,200000000000002,30000000000000000003,4,500005,1,7,8,114.05707,22.754436,210106153606, 12, 13,");
    check_byte = get_check_byte(p1);

    printf("\ncheck is %x\n", check_byte);
}