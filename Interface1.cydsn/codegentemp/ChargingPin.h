/*******************************************************************************
* File Name: ChargingPin.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ChargingPin_H) /* Pins ChargingPin_H */
#define CY_PINS_ChargingPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ChargingPin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ChargingPin__PORT == 15 && ((ChargingPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ChargingPin_Write(uint8 value);
void    ChargingPin_SetDriveMode(uint8 mode);
uint8   ChargingPin_ReadDataReg(void);
uint8   ChargingPin_Read(void);
void    ChargingPin_SetInterruptMode(uint16 position, uint16 mode);
uint8   ChargingPin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ChargingPin_SetDriveMode() function.
     *  @{
     */
        #define ChargingPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ChargingPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ChargingPin_DM_RES_UP          PIN_DM_RES_UP
        #define ChargingPin_DM_RES_DWN         PIN_DM_RES_DWN
        #define ChargingPin_DM_OD_LO           PIN_DM_OD_LO
        #define ChargingPin_DM_OD_HI           PIN_DM_OD_HI
        #define ChargingPin_DM_STRONG          PIN_DM_STRONG
        #define ChargingPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ChargingPin_MASK               ChargingPin__MASK
#define ChargingPin_SHIFT              ChargingPin__SHIFT
#define ChargingPin_WIDTH              1u

/* Interrupt constants */
#if defined(ChargingPin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ChargingPin_SetInterruptMode() function.
     *  @{
     */
        #define ChargingPin_INTR_NONE      (uint16)(0x0000u)
        #define ChargingPin_INTR_RISING    (uint16)(0x0001u)
        #define ChargingPin_INTR_FALLING   (uint16)(0x0002u)
        #define ChargingPin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ChargingPin_INTR_MASK      (0x01u) 
#endif /* (ChargingPin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ChargingPin_PS                     (* (reg8 *) ChargingPin__PS)
/* Data Register */
#define ChargingPin_DR                     (* (reg8 *) ChargingPin__DR)
/* Port Number */
#define ChargingPin_PRT_NUM                (* (reg8 *) ChargingPin__PRT) 
/* Connect to Analog Globals */                                                  
#define ChargingPin_AG                     (* (reg8 *) ChargingPin__AG)                       
/* Analog MUX bux enable */
#define ChargingPin_AMUX                   (* (reg8 *) ChargingPin__AMUX) 
/* Bidirectional Enable */                                                        
#define ChargingPin_BIE                    (* (reg8 *) ChargingPin__BIE)
/* Bit-mask for Aliased Register Access */
#define ChargingPin_BIT_MASK               (* (reg8 *) ChargingPin__BIT_MASK)
/* Bypass Enable */
#define ChargingPin_BYP                    (* (reg8 *) ChargingPin__BYP)
/* Port wide control signals */                                                   
#define ChargingPin_CTL                    (* (reg8 *) ChargingPin__CTL)
/* Drive Modes */
#define ChargingPin_DM0                    (* (reg8 *) ChargingPin__DM0) 
#define ChargingPin_DM1                    (* (reg8 *) ChargingPin__DM1)
#define ChargingPin_DM2                    (* (reg8 *) ChargingPin__DM2) 
/* Input Buffer Disable Override */
#define ChargingPin_INP_DIS                (* (reg8 *) ChargingPin__INP_DIS)
/* LCD Common or Segment Drive */
#define ChargingPin_LCD_COM_SEG            (* (reg8 *) ChargingPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define ChargingPin_LCD_EN                 (* (reg8 *) ChargingPin__LCD_EN)
/* Slew Rate Control */
#define ChargingPin_SLW                    (* (reg8 *) ChargingPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ChargingPin_PRTDSI__CAPS_SEL       (* (reg8 *) ChargingPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ChargingPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ChargingPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ChargingPin_PRTDSI__OE_SEL0        (* (reg8 *) ChargingPin__PRTDSI__OE_SEL0) 
#define ChargingPin_PRTDSI__OE_SEL1        (* (reg8 *) ChargingPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ChargingPin_PRTDSI__OUT_SEL0       (* (reg8 *) ChargingPin__PRTDSI__OUT_SEL0) 
#define ChargingPin_PRTDSI__OUT_SEL1       (* (reg8 *) ChargingPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ChargingPin_PRTDSI__SYNC_OUT       (* (reg8 *) ChargingPin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ChargingPin__SIO_CFG)
    #define ChargingPin_SIO_HYST_EN        (* (reg8 *) ChargingPin__SIO_HYST_EN)
    #define ChargingPin_SIO_REG_HIFREQ     (* (reg8 *) ChargingPin__SIO_REG_HIFREQ)
    #define ChargingPin_SIO_CFG            (* (reg8 *) ChargingPin__SIO_CFG)
    #define ChargingPin_SIO_DIFF           (* (reg8 *) ChargingPin__SIO_DIFF)
#endif /* (ChargingPin__SIO_CFG) */

/* Interrupt Registers */
#if defined(ChargingPin__INTSTAT)
    #define ChargingPin_INTSTAT            (* (reg8 *) ChargingPin__INTSTAT)
    #define ChargingPin_SNAP               (* (reg8 *) ChargingPin__SNAP)
    
	#define ChargingPin_0_INTTYPE_REG 		(* (reg8 *) ChargingPin__0__INTTYPE)
#endif /* (ChargingPin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ChargingPin_H */


/* [] END OF FILE */
