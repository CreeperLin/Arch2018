#ifndef CPU_JUDGE_TEST_IO_H
#define CPU_JUDGE_TEST_IO_H

#define BYTE_PORT_IN 0x100
#define BYTE_PORT_OUT 0x104

static inline unsigned char inb()
{
	return *((volatile unsigned char *)BYTE_PORT_IN);
}

static inline void outb(const unsigned char data)
{
	*((volatile unsigned char *)BYTE_PORT_OUT) = data;
}

static inline unsigned long inl()
{
    unsigned long ret = 0;
    unsigned char ch;
    int sign=0;
    while ((ch=inb())) {
        if(ch<'0'||ch>'9') break;
        if(ch=='-'&&!sign) sign=1;
        ret = ret * 10 + ch - '0';
    }
    return sign?-ret:ret;
}

static inline void outl(const int data)
{
    unsigned char str[13];
    int tmp = data;
    int i=0, s=0;
    if (tmp<0){
        s=1;
        tmp=-tmp;
    }
    do {
        str[i++] = tmp % 10 + '0';
    }
    while ((tmp/=10)>0);
    if(s) str[i++]='-';
    while (i--) {
        outb(str[i]);
    }
}

static inline void print(const char *str)
{
	for (; *str; str++)
		outb(*str);
}

static inline void println(const char *str)
{
	print(str);
	outb('\n');
}

static inline void outlln(const unsigned int data)
{
    outl(data);
	outb('\n');
}
#endif
