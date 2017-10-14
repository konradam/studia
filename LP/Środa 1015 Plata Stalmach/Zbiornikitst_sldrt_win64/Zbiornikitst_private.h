/*
 * Zbiornikitst_private.h
 *
 * Code generation for model "Zbiornikitst".
 *
 * Model version              : 1.123
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed Apr 12 11:33:30 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Zbiornikitst_private_h_
#define RTW_HEADER_Zbiornikitst_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void rtdacpci_analoginputs(SimStruct *rts);
extern void rtdacpci_pwm(SimStruct *rts);

/* private model entry point functions */
extern void Zbiornikitst_derivatives(void);

#endif                                 /* RTW_HEADER_Zbiornikitst_private_h_ */
