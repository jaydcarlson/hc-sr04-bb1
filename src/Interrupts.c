//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

uint8_t count = 0;
//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{
	P0_B2 = true;
	TMR2CN0_TF2H = 0;
	TMR2CN0_TF2L = 0;
	PCA0CN0_CR = true;
	P0_B2 = false;
}

//-----------------------------------------------------------------------------
// PCA0_ISR
//-----------------------------------------------------------------------------
//
// PCA0 ISR Content goes here. Remember to clear flag bits:
// PCA0CN0::CCF0 (PCA Module 0 Capture/Compare Flag)
// PCA0CN0::CCF1 (PCA Module 1 Capture/Compare Flag)
// PCA0CN0::CCF2 (PCA Module 2 Capture/Compare Flag)
// PCA0CN0::CF (PCA Counter/Timer Overflow Flag)
// PCA0PWM::COVF (Cycle Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (PCA0_ISR, PCA0_IRQn)
{
	P0_B3 = true;
	PCA0CN0_CCF0 = false;
	PCA0CN0_CF = 0;
	PCA0PWM &= ~PCA0PWM_COVF__OVERFLOW;
	count++;
	if(count == 6)
	{
		PCA0CN0_CR = false;
		PCA0 = 0;
		count = 0;
	}

	P0_B3 = false;
}

//-----------------------------------------------------------------------------
// CMP1_ISR
//-----------------------------------------------------------------------------
//
// CMP1 ISR Content goes here. Remember to clear flag bits:
// CMP1CN0::CPFIF (Comparator Falling-Edge Flag)
// CMP1CN0::CPRIF (Comparator Rising-Edge Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (CMP1_ISR, CMP1_IRQn)
{
//	P0_B3 = true;
	CMP1CN0 &= ~CMP1CN0_CPRIF__BMASK;
//	P0_B3 = false;
}

