/*******************************************************************************
* File Name: Capacitance.h  
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

#if !defined(CY_PINS_Capacitance_H) /* Pins Capacitance_H */
#define CY_PINS_Capacitance_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Capacitance_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Capacitance__PORT == 15 && ((Capacitance__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Capacitance_Write(uint8 value);
void    Capacitance_SetDriveMode(uint8 mode);
uint8   Capacitance_ReadDataReg(void);
uint8   Capacitance_Read(void);
void    Capacitance_SetInterruptMode(uint16 position, uint16 mode);
uint8   Capacitance_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Capacitance_SetDriveMode() function.
     *  @{
     */
        #define Capacitance_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Capacitance_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Capacitance_DM_RES_UP          PIN_DM_RES_UP
        #define Capacitance_DM_RES_DWN         PIN_DM_RES_DWN
        #define Capacitance_DM_OD_LO           PIN_DM_OD_LO
        #define Capacitance_DM_OD_HI           PIN_DM_OD_HI
        #define Capacitance_DM_STRONG          PIN_DM_STRONG
        #define Capacitance_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Capacitance_MASK               Capacitance__MASK
#define Capacitance_SHIFT              Capacitance__SHIFT
#define Capacitance_WIDTH              1u

/* Interrupt constants */
#if defined(Capacitance__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Capacitance_SetInterruptMode() function.
     *  @{
     */
        #define Capacitance_INTR_NONE      (uint16)(0x0000u)
        #define Capacitance_INTR_RISING    (uint16)(0x0001u)
        #define Capacitance_INTR_FALLING   (uint16)(0x0002u)
        #define Capacitance_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Capacitance_INTR_MASK      (0x01u) 
#endif /* (Capacitance__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Capacitance_PS                     (* (reg8 *) Capacitance__PS)
/* Data Register */
#define Capacitance_DR                     (* (reg8 *) Capacitance__DR)
/* Port Number */
#define Capacitance_PRT_NUM                (* (reg8 *) Capacitance__PRT) 
/* Connect to Analog Globals */                                                  
#define Capacitance_AG                     (* (reg8 *) Capacitance__AG)                       
/* Analog MUX bux enable */
#define Capacitance_AMUX                   (* (reg8 *) Capacitance__AMUX) 
/* Bidirectional Enable */                                                        
#define Capacitance_BIE                    (* (reg8 *) Capacitance__BIE)
/* Bit-mask for Aliased Register Access */
#define Capacitance_BIT_MASK               (* (reg8 *) Capacitance__BIT_MASK)
/* Bypass Enable */
#define Capacitance_BYP                    (* (reg8 *) Capacitance__BYP)
/* Port wide control signals */                                                   
#define Capacitance_CTL                    (* (reg8 *) Capacitance__CTL)
/* Drive Modes */
#define Capacitance_DM0                    (* (reg8 *) Capacitance__DM0) 
#define Capacitance_DM1                    (* (reg8 *) Capacitance__DM1)
#define Capacitance_DM2                    (* (reg8 *) Capacitance__DM2) 
/* Input Buffer Disable Override */
#define Capacitance_INP_DIS                (* (reg8 *) Capacitance__INP_DIS)
/* LCD Common or Segment Drive */
#define Capacitance_LCD_COM_SEG            (* (reg8 *) Capacitance__LCD_COM_SEG)
/* Enable Segment LCD */
#define Capacitance_LCD_EN                 (* (reg8 *) Capacitance__LCD_EN)
/* Slew Rate Control */
#define Capacitance_SLW                    (* (reg8 *) Capacitance__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Capacitance_PRTDSI__CAPS_SEL       (* (reg8 *) Capacitance__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Capacitance_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Capacitance__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Capacitance_PRTDSI__OE_SEL0        (* (reg8 *) Capacitance__PRTDSI__OE_SEL0) 
#define Capacitance_PRTDSI__OE_SEL1        (* (reg8 *) Capacitance__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Capacitance_PRTDSI__OUT_SEL0       (* (reg8 *) Capacitance__PRTDSI__OUT_SEL0) 
#define Capacitance_PRTDSI__OUT_SEL1       (* (reg8 *) Capacitance__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Capacitance_PRTDSI__SYNC_OUT       (* (reg8 *) Capacitance__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Capacitance__SIO_CFG)
    #define Capacitance_SIO_HYST_EN        (* (reg8 *) Capacitance__SIO_HYST_EN)
    #define Capacitance_SIO_REG_HIFREQ     (* (reg8 *) Capacitance__SIO_REG_HIFREQ)
    #define Capacitance_SIO_CFG            (* (reg8 *) Capacitance__SIO_CFG)
    #define Capacitance_SIO_DIFF           (* (reg8 *) Capacitance__SIO_DIFF)
#endif /* (Capacitance__SIO_CFG) */

/* Interrupt Registers */
#if defined(Capacitance__INTSTAT)
    #define Capacitance_INTSTAT            (* (reg8 *) Capacitance__INTSTAT)
    #define Capacitance_SNAP               (* (reg8 *) Capacitance__SNAP)
    
	#define Capacitance_0_INTTYPE_REG 		(* (reg8 *) Capacitance__0__INTTYPE)
#endif /* (Capacitance__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Capacitance_H */


/* [] END OF FILE */
