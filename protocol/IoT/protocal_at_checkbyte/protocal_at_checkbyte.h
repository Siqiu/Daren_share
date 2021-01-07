/*
 * Copyright (c) Daren Hi-Tech Electronics Co., Ltd. Development Team 2020-2020. All rights reserved.
 * File name:   protocal_at_checkbyte.h
 * Author: Donn1e   ID:     Version:    Date: 07/01/2021
 * Description: AT指令的异或校验
 * Others:
 * History:
 */

#ifndef DAREN_SHARE_PROTOCAL_AT_CHECKBYTE_H__
#define DAREN_SHARE_PROTOCAL_AT_CHECKBYTE_H__

#include <stdio.h>
#include <string.h>
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

uint8_t at_protocol_check_byte(uint8_t *buf, uint16_t len);
uint8_t get_check_byte(uint8_t *buf);

#endif //DAREN_SHARE_PROTOCAL_AT_CHECKBYTE_H__
