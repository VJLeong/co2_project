/*******************************************************************************
* File Name: Vcharge.h  
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

#if !defined(CY_PINS_Vcharge_H) /* Pins Vcharge_H */
#define CY_PINS_Vcharge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vcharge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vcharge__PORT == 15 && ((Vcharge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Vcharge_Write(uint8 value);
void    Vcharge_SetDriveMode(uint8 mode);
uint8   Vcharge_ReadDataReg(void);
uint8   Vcharge_Read(void);
void    Vcharge_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vcharge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Vcharge_SetDriveMode() function.
     *  @{
     */
        #define Vcharge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Vcharge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Vcharge_DM_RES_UP          PIN_DM_RES_UP
        #define Vcharge_DM_RES_DWN         PIN_DM_RES_DWN
        #define Vcharge_DM_OD_LO           PIN_DM_OD_LO
        #define Vcharge_DM_OD_HI           PIN_DM_OD_HI
        #define Vcharge_DM_STRONG          PIN_DM_STRONG
        #define Vcharge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Vcharge_MASK               Vcharge__MASK
#define Vcharge_SHIFT              Vcharge__SHIFT
#define Vcharge_WIDTH              1u

/* Interrupt constants */
#if defined(Vcharge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vcharge_SetInterruptMode() function.
     *  @{
     */
        #define Vcharge_INTR_NONE      (uint16)(0x0000u)
        #define Vcharge_INTR_RISING    (uint16)(0x0001u)
        #define Vcharge_INTR_FALLING   (uint16)(0x0002u)
        #define Vcharge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Vcharge_INTR_MASK      (0x01u) 
#endif /* (Vcharge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vcharge_PS                     (* (reg8 *) Vcharge__PS)
/* Data Register */
#define Vcharge_DR                     (* (reg8 *) Vcharge__DR)
/* Port Number */
#define Vcharge_PRT_NUM                (* (reg8 *) Vcharge__PRT) 
/* Connect to Analog Globals */                                                  
#define Vcharge_AG                     (* (reg8 *) Vcharge__AG)                       
/* Analog MUX bux enable */
#define Vcharge_AMUX                   (* (reg8 *) Vcharge__AMUX) 
/* Bidirectional Enable */                                                        
#define Vcharge_BIE                    (* (reg8 *) Vcharge__BIE)
/* Bit-mask for Aliased Register Access */
#define Vcharge_BIT_MASK               (* (reg8 *) Vcharge__BIT_MASK)
/* Bypass Enable */
#define Vcharge_BYP                    (* (reg8 *) Vcharge__BYP)
/* Port wide control signals */                                                   
#define Vcharge_CTL                    (* (reg8 *) Vcharge__CTL)
/* Drive Modes */
#define Vcharge_DM0                    (* (reg8 *) Vcharge__DM0) 
#define Vcharge_DM1                    (* (reg8 *) Vcharge__DM1)
#define Vcharge_DM2                    (* (reg8 *) Vcharge__DM2) 
/* Input Buffer Disable Override */
#define Vcharge_INP_DIS                (* (reg8 *) Vcharge__INP_DIS)
/* LCD Common or Segment Drive */
#define Vcharge_LCD_COM_SEG            (* (reg8 *) Vcharge__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vcharge_LCD_EN                 (* (reg8 *) Vcharge__LCD_EN)
/* Slew Rate Control */
#define Vcharge_SLW                    (* (reg8 *) Vcharge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vcharge_PRTDSI__CAPS_SEL       (* (reg8 *) Vcharge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vcharge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vcharge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vcharge_PRTDSI__OE_SEL0        (* (reg8 *) Vcharge__PRTDSI__OE_SEL0) 
#define Vcharge_PRTDSI__OE_SEL1        (* (reg8 *) Vcharge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vcharge_PRTDSI__OUT_SEL0       (* (reg8 *) Vcharge__PRTDSI__OUT_SEL0) 
#define Vcharge_PRTDSI__OUT_SEL1       (* (reg8 *) Vcharge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vcharge_PRTDSI__SYNC_OUT       (* (reg8 *) Vcharge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Vcharge__SIO_CFG)
    #define Vcharge_SIO_HYST_EN        (* (reg8 *) Vcharge__SIO_HYST_EN)
    #define Vcharge_SIO_REG_HIFREQ     (* (reg8 *) Vcharge__SIO_REG_HIFREQ)
    #define Vcharge_SIO_CFG            (* (reg8 *) Vcharge__SIO_CFG)
    #define Vcharge_SIO_DIFF           (* (reg8 *) Vcharge__SIO_DIFF)
#endif /* (Vcharge__SIO_CFG) */

/* Interrupt Registers */
#if defined(Vcharge__INTSTAT)
    #define Vcharge_INTSTAT            (* (reg8 *) Vcharge__INTSTAT)
    #define Vcharge_SNAP               (* (reg8 *) Vcharge__SNAP)
    
	#define Vcharge_0_INTTYPE_REG 		(* (reg8 *) Vcharge__0__INTTYPE)
#endif /* (Vcharge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vcharge_H */


/* [] END OF FILE */
