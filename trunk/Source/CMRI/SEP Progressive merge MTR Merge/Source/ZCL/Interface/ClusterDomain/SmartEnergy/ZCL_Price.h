/******************************************************************************
 *
 *                  Price Cluster
 *
 ******************************************************************************
 * FileName:        ZCL_Price.h
 * Dependencies:
 * Processor:       PIC18 / PIC24 / PIC32
 * Complier:        MCC18 v3.00 or higher
 *                  MCC30 v2.05 or higher
 *                  MCC32 v2.05 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright � 2004-2007 Microchip Technology Inc.  All rights reserved.
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
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                      07/04/09

 *****************************************************************************/

#ifndef _ZCL_PRICE_H_
#define _ZCL_PRICE_H_

/*****************************************************************************
  Includes
 *****************************************************************************/


/*****************************************************************************
  Constants and Enumerations
 *****************************************************************************/
/*Price cluster Identifier as defined by SE specification*/
#define ZCL_PRICE_CLUSTER                       0x0700

/*Price Cluster Attributes*/
#define ZCL_PRICE_TIER1_ATTRIBUTE               0x0000
#define ZCL_PRICE_TIER2_ATTRIBUTE               0x0001
#define ZCL_PRICE_TIER3_ATTRIBUTE               0x0002
#define ZCL_PRICE_TIER4_ATTRIBUTE               0x0003
#define ZCL_PRICE_TIER5_ATTRIBUTE               0x0004
#define ZCL_PRICE_TIER6_ATTRIBUTE               0x0005

#define CURRENT_TIME                            0x00000000
#define DURATION_UNTIL_CHANGED                  0xFFFF

/*Commands generated by Server Side of the Price Cluster*/
enum Price_Cluster_Server_Side_Generated_Commands
{
    ZCL_Price_PublishPriceCmd                   = 0x00
};

/*Commands received by Server Side of the Price Cluster*/
enum Price_Cluster_Server_Side_Received_Commands
{
    ZCL_Price_GetCurrentPriceCmd                = 0x00,
    ZCL_Price_GetScheduledPriceCmd              = 0x01
};

/*Events handled by the application*/
enum Price_Cluster_Application_Events
{
    ZCL_Price_GetCurrentPriceEvent              = 0x60,
    ZCL_Price_GetScheduledPricesEvent           = 0x61,
    ZCL_Price_PublishPriceEvent                 = 0x62
};

/*****************************************************************************
 Customizable Macros
 *****************************************************************************/
#define PUBLISH_PRICE_CMD_LENGTH_FROM_ISSUER_EVENT_ID   35

 /*****************************************************************************
   Variable definitions
 *****************************************************************************/
extern ROM ZCL_ClusterDefinition zcl_PriceClusterServerDefinition;
extern ROM ZCL_ClusterDefinition zcl_PriceClusterClientDefinition;

extern ROM ZCL_ClusterInfo zcl_PriceClusterServerInfo;
extern ROM ZCL_ClusterInfo zcl_PriceClusterClientInfo;

/*****************************************************************************
  Data Structures
 *****************************************************************************/
/*Stucture for Price Cluster's Attributes*/
typedef struct ZCL_PriceClusterAttribute
{
#if I_SUPPORT_OPTIONAL_ZCL_ATTRIBUTES == 1
    BYTE tier1[12];
    BYTE tier2[12];
    BYTE tier3[12];
    BYTE tier4[12];
    BYTE tier5[12];
    BYTE tier6[12];
#endif /*I_SUPPORT_OPTIONAL_ZCL_ATTRIBUTES*/
}ZCL_PriceClusterAttribute;

typedef struct __attribute__((packed,aligned(1))) _ZCL_Price_PublishPriceInfo
{
    DWORD       ProviderId;                     /*Unsigned 32 bit Integer*/
    BYTE        RateLabel[12];                  /*Octet String*/
    DWORD       IssuerEventId;                  /*Unsigned 32 bit Integer*/
    DWORD       CurrentTime;                    /*Unsigned 32 bit Integer*/
    BYTE        UnitOfMeasure;                  /*8 bit Enumeration*/
    WORD        Currency;                       /*Unsigned 16 bit Interger*/
    BYTE        PriceTrailingDigitAndPriceTier; /*8 bit BitMap*/
    BYTE        NumOfPriceTiersAndRegisterTier; /*8 bit BitMap*/
    DWORD       StartTime;                      /*Unsigned 32 bit Integer*/
    WORD        DurationInMinutes;              /*Unsigned 16 bit Interger*/
    DWORD       Price;                          /*Unsigned 32 bit Integer*/
    BYTE        PriceRatio;                     /*Unsigned 8 bit Integer*/
    DWORD       GenerationPrice;                /*Unsigned 32 bit Integer*/
    BYTE        GenerationPriceRatio;           /*Unsigned 8 bit Integer*/
    DWORD       AlternateCostDelivered;         /*Unsigned 32 bit Integer*/
    BYTE        AlternateCostUnit;              /*8 bit Enumeration*/
    BYTE        AlternateCostTrailingDigit;     /*8 bit BitMap*/
}ZCL_Price_PublishPriceInfo;

typedef struct PACKED _ZCL_Price_GetCurrentPriceInfo
{
    BYTE        CommandOptions;                 /*Unsigned 8 bit Integer*/
}ZCL_Price_GetCurrentPriceInfo;

typedef struct __attribute__((packed,aligned(1))) _ZCL_Price_GetScheduledPriceInfo
{
    DWORD       StartTime;                      /*UTC Time - Unsigned 32 bit Integer*/
    BYTE        NumberOfEvents;                 /*Unsigned 8 bit Integer*/
}ZCL_Price_GetScheduledPriceInfo;

/*****************************************************************************
  Function Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function:        BYTE ZCL_HandlePriceClusterCommand
 *                  (
 *                      BYTE endPointId,
 *                      BYTE asduLength,
 *                      BYTE* pReceivedAsdu,
 *                      BYTE* pResponseAsduStartLocation,
 *                      ZCL_ActionHandler* pActionHandler,
 *                      ROM ZCL_ClusterInfo* pZCLClusterInfo
 *                  );
 *
 * PreCondition:    None
 *
 * Input:           endPointId - EndPoint on which the Price Cluster command needs
 *                               to be processed
 *                  asduLength - Asdu Length of the received frame
 *                  pReceivedAsdu - This point to the actual data received.
 *                                  This consists of ZCL header and Payload.
 *                  pZCLClusterInfo - Pointer pointing to the Price Cluster info
 *
 * Output:          pResponseAsduStartLocation - Pointer pointing to the start
 *                                               location of asdu for which the
 *                                               response frame needs to be created
 *                  pActionHandler -   This is used to notify the application that a
 *                                     response frame is generated or not.
 *                                     It also holds the information of the type event
 *                                     to be handled by the application and has the
 *                                     payload of the recevied data
 *
 * Return :         Returns the length of the response frame created
 *
 * Side Effects:    None
 *
 * Overview:        This function is called when a Price Cluster command is received.
 *                  This function process the Price Cluster command and notifies the
 *                  application about the action to be taken.
 *
 * Note:            None
 *****************************************************************************/
BYTE ZCL_HandlePriceClusterCommand
(
    BYTE endPointId,
    BYTE asduLength,
    BYTE* pReceivedAsdu,
    BYTE* pResponseAsduStartLocation,
    ZCL_ActionHandler *pActionHandler,
    ROM ZCL_ClusterInfo *pZCLClusterInfo
);

/******************************************************************************
 * Function:        void ZCL_Price_CreatePublishPriceCmd
 *                  (
 *                      BYTE transactionSeqNum,
 *                      BYTE* pResponseAsduStartLocation,
 *                      ZCL_Price_PublishPriceInfo *PublishPriceCommandPayloadDefaultValue
 *                  );
 *
 * PreCondition:    None
 *
 * Input:           transactionSeqNum - Transaction Sequence Number that needs
 *                                      to be put in the Publish Price Cmd
 *                  length - Length of the Publish Price Command that needs to
 *                           be created. (Length includes ZCL Header and
 *                           ZCL Payload)
 *                  PublishPriceCommandPayloadDefaultValue - Structure pointing
 *                           to the location where Payload for Publish Price cmd
 *                           information is present and this information needs to
 *                           be updated in the Publish Price Command Payload.
 *
 * Output:          pResponseAsduStartLocation - Specifies the start location
 *                                               from where the Publish Price
 *                                               command needs to be created
 *
 * Return :         dataLength - returns the length of the actual publish price command
 *                  payload
 *
 * Side Effects:    None
 *
 * Overview:        This function is called by the application when it wants to send
 *                  Publish Price Command (either upon receipt of GetCurrentPrice or
 *                  GetScheduledPrice or upon receipt of the update from utility).
 *                  This function is used to create the Publish Price Command by
 *                  using the values passed as an argument.
 *
 * Note:            None
 *****************************************************************************/
BYTE ZCL_Price_CreatePublishPriceCmd
(
    BYTE transactionSeqNum,
    BYTE* pResponseAsduStartLocation,
    ZCL_Price_PublishPriceInfo *PublishPriceCommandPayloadDefaultValue
);
#endif /* _ZCL_PRICE_H_ */
