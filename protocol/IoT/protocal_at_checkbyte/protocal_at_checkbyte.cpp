#include <stdio.h>
#include <string.h>
 #include <stdlib.h> 



extern "C"{

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;
typedef signed short int int16_t;

uint8_t TestString[] = "AT+01GPINF,1.01,200000000000002,30000000000000000003,4,500005,1,7,8,114.05707,22.754436,210106153606, 12, 13,*,77(0x0D,0X0A)";
uint8_t at_protocol_check_byte(uint8_t *buf, uint16_t len);
   char *rt_strstr(const char *s1, const char *s2);
uint8_t get_check_byte(uint8_t *buf);


int main()
{
	uint8_t * p1;
	uint8_t check_byte=0;

	p1 = (uint8_t*)rt_strstr((const char *)TestString, "+")+1;//attention：+号不是我们所需要的，所以这里地址加+1；

	check_byte = get_check_byte(p1);

	printf("checksum is %02x",check_byte); 

	while(1)
	{
		;
	}

}


uint8_t at_protocol_check_byte(uint8_t *buf, uint16_t len)
{
    uint16_t i;
    uint8_t  check;
    check = 0;
	printf("\r\n buf[i]=");
    for(i = 0; i < len; i++)
    {
        check = check ^ buf[i];
		printf("%c",buf[i]);
        //*ckb=*ckb+*cka;
    }
	printf("""\r\n");
    return check;
}



char *rt_strstr(const char *s1, const char *s2)
{
    int l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;
    l1 = strlen(s1);
    while (l1 >= l2)
    {
        l1 --;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1 ++;
    }

    return NULL;
}

uint8_t get_check_byte(uint8_t *buf)
{
    uint8_t *p1, *p2;
    uint8_t  ret;

	uint8_t check_byte;
    p1 = buf;
    ret = 0;

    if (p1)
    {
        p2 = (uint8_t *)strchr((char *)p1, '*');
        if (p2 && p2 > p1)
        {
            check_byte = at_protocol_check_byte(p1, p2 - p1);
			
           
        }
    }
    return check_byte;
}

}