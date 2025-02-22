/*******************************************************************************
* File Name: TimerOutput.h  
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

#if !defined(CY_PINS_TimerOutput_H) /* Pins TimerOutput_H */
#define CY_PINS_TimerOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TimerOutput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TimerOutput__PORT == 15 && ((TimerOutput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TimerOutput_Write(uint8 value);
void    TimerOutput_SetDriveMode(uint8 mode);
uint8   TimerOutput_ReadDataReg(void);
uint8   TimerOutput_Read(void);
void    TimerOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   TimerOutput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TimerOutput_SetDriveMode() function.
     *  @{
     */
        #define TimerOutput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TimerOutput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TimerOutput_DM_RES_UP          PIN_DM_RES_UP
        #define TimerOutput_DM_RES_DWN         PIN_DM_RES_DWN
        #define TimerOutput_DM_OD_LO           PIN_DM_OD_LO
        #define TimerOutput_DM_OD_HI           PIN_DM_OD_HI
        #define TimerOutput_DM_STRONG          PIN_DM_STRONG
        #define TimerOutput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TimerOutput_MASK               TimerOutput__MASK
#define TimerOutput_SHIFT              TimerOutput__SHIFT
#define TimerOutput_WIDTH              1u

/* Interrupt constants */
#if defined(TimerOutput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TimerOutput_SetInterruptMode() function.
     *  @{
     */
        #define TimerOutput_INTR_NONE      (uint16)(0x0000u)
        #define TimerOutput_INTR_RISING    (uint16)(0x0001u)
        #define TimerOutput_INTR_FALLING   (uint16)(0x0002u)
        #define TimerOutput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TimerOutput_INTR_MASK      (0x01u) 
#endif /* (TimerOutput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TimerOutput_PS                     (* (reg8 *) TimerOutput__PS)
/* Data Register */
#define TimerOutput_DR                     (* (reg8 *) TimerOutput__DR)
/* Port Number */
#define TimerOutput_PRT_NUM                (* (reg8 *) TimerOutput__PRT) 
/* Connect to Analog Globals */                                                  
#define TimerOutput_AG                     (* (reg8 *) TimerOutput__AG)                       
/* Analog MUX bux enable */
#define TimerOutput_AMUX                   (* (reg8 *) TimerOutput__AMUX) 
/* Bidirectional Enable */                                                        
#define TimerOutput_BIE                    (* (reg8 *) TimerOutput__BIE)
/* Bit-mask for Aliased Register Access */
#define TimerOutput_BIT_MASK               (* (reg8 *) TimerOutput__BIT_MASK)
/* Bypass Enable */
#define TimerOutput_BYP                    (* (reg8 *) TimerOutput__BYP)
/* Port wide control signals */                                                   
#define TimerOutput_CTL                    (* (reg8 *) TimerOutput__CTL)
/* Drive Modes */
#define TimerOutput_DM0                    (* (reg8 *) TimerOutput__DM0) 
#define TimerOutput_DM1                    (* (reg8 *) TimerOutput__DM1)
#define TimerOutput_DM2                    (* (reg8 *) TimerOutput__DM2) 
/* Input Buffer Disable Override */
#define TimerOutput_INP_DIS                (* (reg8 *) TimerOutput__INP_DIS)
/* LCD Common or Segment Drive */
#define TimerOutput_LCD_COM_SEG            (* (reg8 *) TimerOutput__LCD_COM_SEG)
/* Enable Segment LCD */
#define TimerOutput_LCD_EN                 (* (reg8 *) TimerOutput__LCD_EN)
/* Slew Rate Control */
#define TimerOutput_SLW                    (* (reg8 *) TimerOutput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TimerOutput_PRTDSI__CAPS_SEL       (* (reg8 *) TimerOutput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TimerOutput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TimerOutput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TimerOutput_PRTDSI__OE_SEL0        (* (reg8 *) TimerOutput__PRTDSI__OE_SEL0) 
#define TimerOutput_PRTDSI__OE_SEL1        (* (reg8 *) TimerOutput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TimerOutput_PRTDSI__OUT_SEL0       (* (reg8 *) TimerOutput__PRTDSI__OUT_SEL0) 
#define TimerOutput_PRTDSI__OUT_SEL1       (* (reg8 *) TimerOutput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TimerOutput_PRTDSI__SYNC_OUT       (* (reg8 *) TimerOutput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TimerOutput__SIO_CFG)
    #define TimerOutput_SIO_HYST_EN        (* (reg8 *) TimerOutput__SIO_HYST_EN)
    #define TimerOutput_SIO_REG_HIFREQ     (* (reg8 *) TimerOutput__SIO_REG_HIFREQ)
    #define TimerOutput_SIO_CFG            (* (reg8 *) TimerOutput__SIO_CFG)
    #define TimerOutput_SIO_DIFF           (* (reg8 *) TimerOutput__SIO_DIFF)
#endif /* (TimerOutput__SIO_CFG) */

/* Interrupt Registers */
#if defined(TimerOutput__INTSTAT)
    #define TimerOutput_INTSTAT            (* (reg8 *) TimerOutput__INTSTAT)
    #define TimerOutput_SNAP               (* (reg8 *) TimerOutput__SNAP)
    
	#define TimerOutput_0_INTTYPE_REG 		(* (reg8 *) TimerOutput__0__INTTYPE)
#endif /* (TimerOutput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TimerOutput_H */


/* [] END OF FILE */
