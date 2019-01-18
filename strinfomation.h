#ifndef STRINFOMATION_H
#define STRINFOMATION_H

#include <QString>


typedef char S8;
typedef unsigned char U8;

typedef short S16;
typedef unsigned short U16;

typedef int S32;
typedef unsigned int U32;

typedef float F32;
typedef double F64;

typedef long long S64;
typedef unsigned long long U64;

struct InfoSystem{
    QString name;
    QString ip_addr;
    int listenPort;
};

struct locaionMessage{
    U8 header[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    U8 messageType;
    F32 loc_x;
    F32 loc_y;
    S32 rotation;
};

#endif // STRINFOMATION_H
