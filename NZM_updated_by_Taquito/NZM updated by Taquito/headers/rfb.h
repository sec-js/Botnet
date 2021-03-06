#ifndef RFB_H__
#define RFB_H__

// Define the CARD* types as used in X11/Xmd.h

typedef unsigned long CARD32;
typedef unsigned short CARD16;
//typedef short INT16;
typedef unsigned char  CARD8;

// include the protocol spec
#define rfbProtocolVersionFormat "RFB %03d.%03d\n"
#define rfbProtocolMajorVersion 3
#define rfbProtocolMinorVersion 8
#define useShared "\x00"

typedef char rfbProtocolVersionMsg[13];	/* allow extra byte for null */

#define sz_rfbProtocolVersionMsg 12

#define rfbConnFailed 0
#define rfbNoAuth 1
#define rfbVncAuth 2

#define rfbVncAuthOK 0
#define rfbVncAuthFailed 1
#define rfbVncAuthTooMany 2

#define sz_rfbClientInitMsg 1

typedef struct _rfbPixelFormat {
    CARD8 bitsPerPixel;	
    CARD8 depth;	
    CARD8 bigEndian;
    CARD8 trueColour;
    CARD16 redMax;	
    CARD16 greenMax;		
    CARD16 blueMax;		
    CARD8 redShift;	
    CARD8 greenShift;	
    CARD8 blueShift;	
    CARD8 pad1;
    CARD16 pad2;
} rfbPixelFormat;

#define sz_rfbPixelFormat 16

typedef struct _rfbServerInitMsg {
    CARD16 framebufferWidth;
    CARD16 framebufferHeight;
    rfbPixelFormat format;
    CARD32 nameLength;
} rfbServerInitMsg;

#define sz_rfbServerInitMsg (8 + sz_rfbPixelFormat)

// define some quick endian conversions
// change this if necessary
#define LITTLE_ENDIAN_HOST

#ifdef LITTLE_ENDIAN_HOST

#define Swap16IfLE(s) \
    ((CARD16) ((((s) & 0xff) << 8) | (((s) >> 8) & 0xff)))
#define Swap32IfLE(l) \
    ((CARD32) ((((l) & 0xff000000) >> 24) | \
     (((l) & 0x00ff0000) >> 8)  | \
	 (((l) & 0x0000ff00) << 8)  | \
	 (((l) & 0x000000ff) << 24)))

#else

#define Swap16IfLE(s) (s)
#define Swap32IfLE(l) (l)

#endif


#endif // RFB_H__

