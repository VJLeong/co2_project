/*******************************************************************************
* File Name: Vdischarge.h  
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

#if !defined(CY_PINS_Vdischarge_H) /* Pins Vdischarge_H */
#define CY_PINS_Vdischarge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vdischarge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vdischarge__PORT == 15 && ((Vdischarge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Vdischarge_Write(uint8 value);
void    Vdischarge_SetDriveMode(uint8 mode);
uint8   Vdischarge_ReadDataReg(void);
uint8   Vdischarge_Read(void);
void    Vdischarge_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vdischarge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Vdischarge_SetDriveMode() function.
     *  @{
     */
        #define Vdischarge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Vdischarge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Vdischarge_DM_RES_UP          PIN_DM_RES_UP
        #define Vdischarge_DM_RES_DWN         PIN_DM_RES_DWN
        #define Vdischarge_DM_OD_LO           PIN_DM_OD_LO
        #define Vdischarge_DM_OD_HI           PIN_DM_OD_HI
        #define Vdischarge_DM_STRONG          PIN_DM_STRONG
        #define Vdischarge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Vdischarge_MASK               Vdischarge__MASK
#define Vdischarge_SHIFT              Vdischarge__SHIFT
#define Vdischarge_WIDTH              1u

/* Interrupt constants */
#if defined(Vdischarge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vdischarge_SetInterruptMode() function.
     *  @{
     */
        #define Vdischarge_INTR_NONE      (uint16)(0x0000u)
        #define Vdischarge_INTR_RISING    (uint16)(0x0001u)
        #define Vdischarge_INTR_FALLING   (uint16)(0x0002u)
        #define Vdischarge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Vdischarge_INTR_MASK      (0x01u) 
#endif /* (Vdischarge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vdischarge_PS                     (* (reg8 *) Vdischarge__PS)
/* Data Register */
#define Vdischarge_DR                     (* (reg8 *) Vdischarge__DR)
/* Port Number */
#define Vdischarge_PRT_NUM                (* (reg8 *) Vdischarge__PRT) 
/* Connect to Analog Globals */                                                  
#define Vdischarge_AG                     (* (reg8 *) Vdischarge__AG)                       
/* Analog MUX bux enable */
#define Vdischarge_AMUX                   (* (reg8 *) Vdischarge__AMUX) 
/* Bidirectional Enable */                                                        
#define Vdischarge_BIE                    (* (reg8 *) Vdischarge__BIE)
/* Bit-mask for Aliased Register Access */
#define Vdischarge_BIT_MASK               (* (reg8 *) Vdischarge__BIT_MASK)
/* Bypass Enable */
#define Vdischarge_BYP                    (* (reg8 *) Vdischarge__BYP)
/* Port wide control signals */                                                   
#define Vdischarge_CTL                    (* (reg8 *) Vdischarge__CTL)
/* Drive Modes */
#define Vdischarge_DM0                    (* (reg8 *) Vdischarge__DM0) 
#define Vdischarge_DM1                    (* (reg8 *) Vdischarge__DM1)
#define Vdischarge_DM2                    (* (reg8 *) Vdischarge__DM2) 
/* Input Buffer Disable Override */
#define Vdischarge_INP_DIS                (* (reg8 *) Vdischarge__INP_DIS)
/* LCD Common or Segment Drive */
#define Vdischarge_LCD_COM_SEG            (* (reg8 *) Vdischarge__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vdischarge_LCD_EN                 (* (reg8 *) Vdischarge__LCD_EN)
/* Slew Rate Control */
#define Vdischarge_SLW                    (* (reg8 *) Vdischarge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vdischarge_PRTDSI__CAPS_SEL       (* (reg8 *) Vdischarge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vdischarge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vdischarge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vdischarge_PRTDSI__OE_SEL0        (* (reg8 *) Vdischarge__PRTDSI__OE_SEL0) 
#define Vdischarge_PRTDSI__OE_SEL1        (* (reg8 *) Vdischarge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vdischarge_PRTDSI__OUT_SEL0       (* (reg8 *) Vdischarge__PRTDSI__OUT_SEL0) 
#define Vdischarge_PRTDSI__OUT_SEL1       (* (reg8 *) Vdischarge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vdischarge_PRTDSI__SYNC_OUT       (* (reg8 *) Vdischarge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Vdischarge__SIO_CFG)
    #define Vdischarge_SIO_HYST_EN        (* (reg8 *) Vdischarge__SIO_HYST_EN)
    #define Vdischarge_SIO_REG_HIFREQ     (* (reg8 *) Vdischarge__SIO_REG_HIFREQ)
    #define Vdischarge_SIO_CFG            (* (reg8 *) Vdischarge__SIO_CFG)
    #define Vdischarge_SIO_DIFF           (* (reg8 *) Vdischarge__SIO_DIFF)
#endif /* (Vdischarge__SIO_CFG) */

/* Interrupt Registers */
#if defined(Vdischarge__INTSTAT)
    #define Vdischarge_INTSTAT            (* (reg8 *) Vdischarge__INTSTAT)
    #define Vdischarge_SNAP               (* (reg8 *) Vdischarge__SNAP)
    
	#define Vdischarge_0_INTTYPE_REG 		(* (reg8 *) Vdischarge__0__INTTYPE)
#endif /* (Vdischarge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vdischarge_H */


/* [] END OF FILE */
