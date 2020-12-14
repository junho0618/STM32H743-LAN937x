#ifndef __TYPEDEF_H
#define __TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------
	includes
----------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/*----------------------------------------------------------------------
	typedefs
----------------------------------------------------------------------*/
typedef	bool									BOOL;

typedef	unsigned char							U8;
typedef	unsigned short							U16;
typedef	unsigned int							U32;
typedef	volatile unsigned char					VU8;
typedef	volatile unsigned short					VU16;
typedef	volatile unsigned int					VU32;
typedef	signed char								S8;
typedef	signed short							S16;
typedef	signed int								S32;

typedef	unsigned char							u8;
typedef	unsigned short							u16;
typedef	unsigned int							u32;
typedef	volatile unsigned char					vu8;
typedef	volatile unsigned short					vu16;
typedef	volatile unsigned int					vu32;
typedef	signed char								s8;
typedef	signed short							s16;
typedef	signed int								s32;

typedef enum
{
	INIT_OK		= 0,
	INIT_FAIL	= 1
} InitStatus;

/*----------------------------------------------------------------------
	defines
----------------------------------------------------------------------*/
#ifndef FALSE
	#define FALSE				false
	#define TRUE				true
#endif

/*----------------------------------------------------------------------
	typedef
----------------------------------------------------------------------*/
typedef enum				// Packet type
{
	PACKET_USB		= 0 ,
	PACKET_UART		= 1 ,
	PACKET_CAN		= 2 ,
	PACKET_FDCAN	= 3 ,
	PACKET_SPICAN	= 4
} ePKT_TD;

typedef enum				// Message type
{
	MSG_COMM		= 0 ,
	MSG_DIAG		= 1 ,
	MSG_LOG			= 2 ,
	MSG_SDCARD		= 3
} eMSG_TD;

typedef struct
{
	eMSG_TD	mMsgType;							// Message Type
	ePKT_TD	mPktType;							// Packet Type

	u16		mLen;
	u16		mMod;
	u8		mSeq;
	u8		mCS;

	void	*pPacket;							// Packet
} MsgClst_t;

#ifdef __cplusplus
}
#endif

#endif /* __TYPEDEF_H */