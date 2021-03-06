/*
 * Pidzbiorniki_data.c
 *
 * Code generation for model "Pidzbiorniki".
 *
 * Model version              : 1.130
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed May 10 11:07:12 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pidzbiorniki.h"
#include "Pidzbiorniki_private.h"

/* Block parameters (auto storage) */
P_Pidzbiorniki_T Pidzbiorniki_P = {
  /*  Computed Parameter: pooled1
   * Referenced by:
   *   '<S7>/RT-DAC PCI PWM '
   *   '<S8>/RT-DAC PCI PWM '
   *   '<S9>/RT-DAC PCI PWM '
   *   '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* Variable: T0
                                        * Referenced by:
                                        *   '<S7>/RT-DAC PCI PWM '
                                        *   '<S8>/RT-DAC PCI PWM '
                                        *   '<S9>/RT-DAC PCI PWM '
                                        *   '<S10>/RT-DAC PCI PWM '
                                        */
  427.5,                               /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S1>/Derivative Gain'
                                        */
  0.71052631578947367,                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S1>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: PIDController_LowerSaturationLi
                                        * Referenced by: '<S1>/Saturate'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S1>/Filter Coefficient'
                                        */
  27.0,                                /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  0.0,                                 /* Mask Parameter: PIDController_UpperSaturationLi
                                        * Referenced by: '<S1>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: ZaworGORA_gain
                                        * Referenced by: '<S5>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: ZaworSRODEK_gain
                                        * Referenced by: '<S6>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: ZaworDOL_gain
                                        * Referenced by: '<S4>/Slider Gain'
                                        */

  /*  Computed Parameter: RTDACAnalogInputs_P1_Size
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S11>/RT-DAC Analog Inputs'
                                        */

  /*  Computed Parameter: RTDACAnalogInputs_P2_Size
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 3.0 },

  /*  Expression: Chan
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 0.0, 1.0, 2.0 },

  /*  Computed Parameter: RTDACAnalogInputs_P3_Size
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 3.0 },

  /*  Expression: Gain
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0, 1.0 },

  /*  Computed Parameter: RTDACAnalogInputs_P4_Size
   * Referenced by: '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0 },
  0.05,                                /* Expression: T0
                                        * Referenced by: '<S11>/RT-DAC Analog Inputs'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant'
                                        */
  15.15151515151515,                   /* Expression: 1/0.066
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.06,                                /* Expression: 0.06
                                        * Referenced by: '<Root>/Constant5'
                                        */
  15.625,                              /* Expression: 1/0.064
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.04,                                /* Expression: 1.04
                                        * Referenced by: '<Root>/Constant6'
                                        */
  26.315789473684212,                  /* Expression: 1/0.038
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P1_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P2_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: ChanIdx
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P3_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: ChanMode
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P4_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* Expression: ChanPresc
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P5_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: SetOutputsFlag
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P6_Size
   * Referenced by: '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: SetOutputsValue
                                        * Referenced by: '<S8>/RT-DAC PCI PWM '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P1_Size_o
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P2_Size_o
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: ChanIdx
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P3_Size_k
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: ChanMode
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P4_Size_m
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* Expression: ChanPresc
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P5_Size_h
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: SetOutputsFlag
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P6_Size_j
   * Referenced by: '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: SetOutputsValue
                                        * Referenced by: '<S9>/RT-DAC PCI PWM '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P1_Size_d
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P2_Size_g
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: ChanIdx
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P3_Size_g
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: ChanMode
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P4_Size_f
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* Expression: ChanPresc
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P5_Size_e
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: SetOutputsFlag
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P6_Size_l
   * Referenced by: '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: SetOutputsValue
                                        * Referenced by: '<S10>/RT-DAC PCI PWM '
                                        */
  -0.026315789473684209,               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  0.026315789473684209,                /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  -2.0,                                /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  2.0,                                 /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S1>/Filter'
                                        */
  0.0066666666666666671,               /* Expression: 1/150
                                        * Referenced by: '<Root>/Gain3'
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P1_Size_e
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P2_Size_b
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: ChanIdx
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P3_Size_f
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: ChanMode
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P4_Size_p
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* Expression: ChanPresc
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P5_Size_g
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: SetOutputsFlag
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */

  /*  Computed Parameter: RTDACPCIPWM_P6_Size_n
   * Referenced by: '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: SetOutputsValue
                                        * Referenced by: '<S7>/RT-DAC PCI PWM '
                                        */
  -2.0,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  2.0,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  -2.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  2.0,                                 /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  10.0                                 /* Expression: 10
                                        * Referenced by: '<Root>/Constant4'
                                        */
};
