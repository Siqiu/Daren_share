/*
 * Copyright (c) Daren Hi-Tech Electronics Co., Ltd. Development Team 2020-2020. All rights reserved.
 * File name: protoc_at_checkbyte.c
 * Author: Jinyuan Chen   ID:     Version: V1.0.0   Date: 07/01/2021
 * Description: AT指令的异或校验
 * Others:
 * History:
 */

#include "protocal_at_checkbyte.h"

/**
 * @Description:
 * @param buf - 输入字符串指针.
 * @param len - 输入字符串长度.
 * @return
 */
uint8_t at_protocol_check_byte(uint8_t *buf, uint16_t len) {
    uint16_t i;
    uint8_t check;
    check = 0;

    for (i = 0; i < len; i++) {
        check = check ^ buf[i];
    }
    return check;
}

/**
 * @Description:
 * @param  buf - 传入字符串指针.
 * @return check_byte 校验值
 */
uint8_t get_check_byte(uint8_t *buf) {
    uint8_t *p1, *p2;

    uint8_t check_byte;
    p1 = buf;

    if (p1) {
        p2 = (uint8_t *) strchr((char *) p1, '*');
        if (p2 && p2 > p1) {
            check_byte = at_protocol_check_byte(p1, p2 - p1);
        }
    }
    return check_byte;
}

