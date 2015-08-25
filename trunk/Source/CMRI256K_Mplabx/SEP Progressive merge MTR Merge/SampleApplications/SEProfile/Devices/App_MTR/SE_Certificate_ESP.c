/*********************************************************************
*
*                  Certificate
*
*********************************************************************
* FileName:        SE_Certificate.c
* Dependencies:
* Processor:       PIC18 / PIC24 / PIC32
* Complier:        MCC18 v3.00 or higher
*                  MCC30 v2.05 or higher
*                   MCC32 v2.05 or higher
* Company:         Microchip Technology, Inc.
*
* Software License Agreement
*
* Copyright � 2004-2011 Microchip Technology Inc.  All rights reserved.
*
* Microchip licenses to you the right to use, copy and distribute Software
* only when embedded on a Microchip microcontroller or digital signal
* controller and used with a Microchip radio frequency transceiver, which
* are integrated into your product or third party product (pursuant to the
* sublicense terms in the accompanying license agreement).  You may NOT
* modify or create derivative works of the Software.
*
* If you intend to use this Software in the development of a product for
* sale, you must be a member of the ZigBee Alliance.  For more information,
* go to www.zigbee.org.
*
* You should refer to the license agreement accompanying this Software for
* additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
* OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
* PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED
* UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF
* WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR
* EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT,
* PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
* PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY
* THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER
* SIMILAR COSTS.
*
* Author               Date    Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*****************************************************************************/

/****************************************************************************
   Includes
*****************************************************************************/
/* Configuration files */
#include "zigbee.def"

#if I_SUPPORT_CBKE == 1
/* Generic files */
#include "generic.h"

/* CBKE Related Files */
#include "eccapi.h"
#include "SE_Certificate.h"




/*****************************************************************************
   Constants and Enumerations
*****************************************************************************/
/* None */

/*****************************************************************************
   Customizable Macros
*****************************************************************************/
/* None */

/*****************************************************************************
   Data Structures
*****************************************************************************/
/* None */

/*****************************************************************************
   Variable Definitions
 *****************************************************************************/
/*This holds the static private key for ESP device*/
BYTE static_privateKey[SECT163K1_PRIVATE_KEY_SIZE] = {

    0x03, 0xb5, 0x69, 0x82, 0x90, 0x87, 0x62, 0x7b,
    0xa2, 0xdf, 0x75, 0x6e, 0x2a, 0xb4, 0x6f, 0x1f,
    0xa1, 0x9a, 0x03, 0xcd, 0x34
};

/*This holds the certificate for ESP device*/
BYTE test_certificate[SECT163K1_CERTIFICATE_SIZE] = {

    0x03, 0x01, 0xb2, 0xdd, 0x80, 0xca, 0x41, 0xf9,
    0x7b, 0x46, 0xd5, 0xc4, 0x41, 0x93, 0x0e, 0xcd,
    0xaa, 0xb5, 0x17, 0x95, 0x51, 0x64, 0x4d, 0x43,
    0x48, 0x49, 0x50, 0x00, 0x00, 0x01, 0x54, 0x45,
    0x53, 0x54, 0x53, 0x45, 0x43, 0x41, 0x01, 0x09,
    0x10, 0x4d, 0x54, 0x45, 0x53, 0x54, 0x43, 0x46
};

/*This holds the certificate authority's public key*/
BYTE ca_publicKey[SECT163K1_COMPRESSED_PUBLIC_KEY_SIZE] = {

    0x02, 0x00, 0xfd, 0xe8, 0xa7, 0xf3, 0xd1, 0x08,
    0x42, 0x24, 0x96, 0x2a, 0x4e, 0x7c, 0x54, 0xe6,
    0x9a, 0xc3, 0xf0, 0x4d, 0xa6, 0xb8
};

/*****************************************************************************
   Function Prototypes
 *****************************************************************************/
/* None */

/*****************************************************************************
  Private Functions
*****************************************************************************/
/* None */

/*****************************************************************************
  Public Functions
 *****************************************************************************/

/******************************************************************************
* Function:        BYTE* SE_GetStaticPrivateKey( void )
*
* PreCondition:    None
*
* Input:           None
*
* Output:          None
*
* Side Effects:    None
*
* Return Value:    pointer to the certificate
*
* Overview:        This function returns the pointer to the certificate of the
*                   device.
*
* Note:
*****************************************************************************/
BYTE* SE_GetCertificate( void )
{
    return test_certificate;
}

/******************************************************************************
* Function:        BYTE* SE_GetStaticPrivateKey( void )
*
* PreCondition:    None
*
* Input:           None
*
* Output:          None
*
* Side Effects:    None
*
* Return Value:    pointer to static private key
*
* Overview:        This function returns the pointer to the static private
*                   key of the device.
*
* Note:
*****************************************************************************/
BYTE* SE_GetStaticPrivateKey( void )
{
    return static_privateKey;
}

/******************************************************************************
* Function:        BYTE* SE_GetCAPublicKey( void )
*
* PreCondition:    None
*
* Input:           None
*
* Output:          None
*
* Side Effects:    None
*
* Return Value:    pointer to Certificate Authority's Public Key
*
* Overview:        This function returns the pointer to the CA Public key
*                    of the device.
*
* Note:
*****************************************************************************/
BYTE* SE_GetCAPublicKey( void )
{
    return ca_publicKey;
}
#endif /* I_SUPPORT_CBKE == 1*/

