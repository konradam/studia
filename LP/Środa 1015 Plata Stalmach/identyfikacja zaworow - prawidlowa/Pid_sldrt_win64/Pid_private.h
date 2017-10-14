/*
 * Pid_private.h
 *
 * Code generation for model "Pid".
 *
 * Model version              : 1.129
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed Apr 05 12:14:16 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pid_private_h_
#define RTW_HEADER_Pid_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void rtdacpci_analoginputs(SimStruct *rts);
extern void rtdacpci_pwm(SimStruct *rts);

/* private model entry point functions */
extern void Pid_derivatives(void);

#endif                                 /* RTW_HEADER_Pid_private_h_ */
