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

struct locationMessage{
    U8 header[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    U8 messageType = 0x00;
    F32 loc_x;
    F32 loc_y;
    S32 rotation;
    U8 id;
};

struct StringAllInt{

};

struct NetMsgTrack
{
    //NetMsgHeader msgHeader;

    U16 unTrackNo;
    U16 unTimeOfTrack;
    U16 unSSRCode;
    F64 dLatitude;
    F64 dLongitude;
    F64 pos_x;          //meter
    F64 pos_y;          //meter
    F64 dAzimuth;       //heading(0~360)is North zero?
    F64 dSpeed;         //meter per second?
    U16 unFlightLevel;  //meter & 1meter == 3.28084feet, 100feet == 1FL

    char cFlightID[8];
    U32 icaoAddress;
};



#endif // STRINFOMATION_H
