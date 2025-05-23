/*******************************************************************************
* File Name: Heater_IN2.h  
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

#if !defined(CY_PINS_Heater_IN2_H) /* Pins Heater_IN2_H */
#define CY_PINS_Heater_IN2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Heater_IN2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Heater_IN2__PORT == 15 && ((Heater_IN2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Heater_IN2_Write(uint8 value);
void    Heater_IN2_SetDriveMode(uint8 mode);
uint8   Heater_IN2_ReadDataReg(void);
uint8   Heater_IN2_Read(void);
void    Heater_IN2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Heater_IN2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Heater_IN2_SetDriveMode() function.
     *  @{
     */
        #define Heater_IN2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Heater_IN2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Heater_IN2_DM_RES_UP          PIN_DM_RES_UP
        #define Heater_IN2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Heater_IN2_DM_OD_LO           PIN_DM_OD_LO
        #define Heater_IN2_DM_OD_HI           PIN_DM_OD_HI
        #define Heater_IN2_DM_STRONG          PIN_DM_STRONG
        #define Heater_IN2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Heater_IN2_MASK               Heater_IN2__MASK
#define Heater_IN2_SHIFT              Heater_IN2__SHIFT
#define Heater_IN2_WIDTH              1u

/* Interrupt constants */
#if defined(Heater_IN2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Heater_IN2_SetInterruptMode() function.
     *  @{
     */
        #define Heater_IN2_INTR_NONE      (uint16)(0x0000u)
        #define Heater_IN2_INTR_RISING    (uint16)(0x0001u)
        #define Heater_IN2_INTR_FALLING   (uint16)(0x0002u)
        #define Heater_IN2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Heater_IN2_INTR_MASK      (0x01u) 
#endif /* (Heater_IN2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Heater_IN2_PS                     (* (reg8 *) Heater_IN2__PS)
/* Data Register */
#define Heater_IN2_DR                     (* (reg8 *) Heater_IN2__DR)
/* Port Number */
#define Heater_IN2_PRT_NUM                (* (reg8 *) Heater_IN2__PRT) 
/* Connect to Analog Globals */                                                  
#define Heater_IN2_AG                     (* (reg8 *) Heater_IN2__AG)                       
/* Analog MUX bux enable */
#define Heater_IN2_AMUX                   (* (reg8 *) Heater_IN2__AMUX) 
/* Bidirectional Enable */                                                        
#define Heater_IN2_BIE                    (* (reg8 *) Heater_IN2__BIE)
/* Bit-mask for Aliased Register Access */
#define Heater_IN2_BIT_MASK               (* (reg8 *) Heater_IN2__BIT_MASK)
/* Bypass Enable */
#define Heater_IN2_BYP                    (* (reg8 *) Heater_IN2__BYP)
/* Port wide control signals */                                                   
#define Heater_IN2_CTL                    (* (reg8 *) Heater_IN2__CTL)
/* Drive Modes */
#define Heater_IN2_DM0                    (* (reg8 *) Heater_IN2__DM0) 
#define Heater_IN2_DM1                    (* (reg8 *) Heater_IN2__DM1)
#define Heater_IN2_DM2                    (* (reg8 *) Heater_IN2__DM2) 
/* Input Buffer Disable Override */
#define Heater_IN2_INP_DIS                (* (reg8 *) Heater_IN2__INP_DIS)
/* LCD Common or Segment Drive */
#define Heater_IN2_LCD_COM_SEG            (* (reg8 *) Heater_IN2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Heater_IN2_LCD_EN                 (* (reg8 *) Heater_IN2__LCD_EN)
/* Slew Rate Control */
#define Heater_IN2_SLW                    (* (reg8 *) Heater_IN2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Heater_IN2_PRTDSI__CAPS_SEL       (* (reg8 *) Heater_IN2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Heater_IN2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Heater_IN2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Heater_IN2_PRTDSI__OE_SEL0        (* (reg8 *) Heater_IN2__PRTDSI__OE_SEL0) 
#define Heater_IN2_PRTDSI__OE_SEL1        (* (reg8 *) Heater_IN2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Heater_IN2_PRTDSI__OUT_SEL0       (* (reg8 *) Heater_IN2__PRTDSI__OUT_SEL0) 
#define Heater_IN2_PRTDSI__OUT_SEL1       (* (reg8 *) Heater_IN2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Heater_IN2_PRTDSI__SYNC_OUT       (* (reg8 *) Heater_IN2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Heater_IN2__SIO_CFG)
    #define Heater_IN2_SIO_HYST_EN        (* (reg8 *) Heater_IN2__SIO_HYST_EN)
    #define Heater_IN2_SIO_REG_HIFREQ     (* (reg8 *) Heater_IN2__SIO_REG_HIFREQ)
    #define Heater_IN2_SIO_CFG            (* (reg8 *) Heater_IN2__SIO_CFG)
    #define Heater_IN2_SIO_DIFF           (* (reg8 *) Heater_IN2__SIO_DIFF)
#endif /* (Heater_IN2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Heater_IN2__INTSTAT)
    #define Heater_IN2_INTSTAT            (* (reg8 *) Heater_IN2__INTSTAT)
    #define Heater_IN2_SNAP               (* (reg8 *) Heater_IN2__SNAP)
    
	#define Heater_IN2_0_INTTYPE_REG 		(* (reg8 *) Heater_IN2__0__INTTYPE)
#endif /* (Heater_IN2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Heater_IN2_H */


/* [] END OF FILE */
