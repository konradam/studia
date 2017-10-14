/*
 * Zbiorniki_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki.mdl".
 *
 * Model Version              : 1.125
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Nov 11 14:02:42 2015
 */

#include "Zbiorniki.h"
#include "Zbiorniki_private.h"

/* Block parameters (auto storage) */
Parameters_Zbiorniki Zbiorniki_P = {
  /*  RTDACAnalogInputs_P1_Size : '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACAnalogInputs_P1 : '<S11>/RT-DAC Analog Inputs'
                                        */

  /*  RTDACAnalogInputs_P2_Size : '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 3.0 },

  /*  RTDACAnalogInputs_P2 : '<S11>/RT-DAC Analog Inputs'
   */
  { 0.0, 1.0, 2.0 },

  /*  RTDACAnalogInputs_P3_Size : '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 3.0 },

  /*  RTDACAnalogInputs_P3 : '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0, 1.0 },

  /*  RTDACAnalogInputs_P4_Size : '<S11>/RT-DAC Analog Inputs'
   */
  { 1.0, 1.0 },
  0.05,                                /* RTDACAnalogInputs_P4 : '<S11>/RT-DAC Analog Inputs'
                                        */
  1.5623728537716664E+001,             /* Gain_Gain : '<Root>/Gain'
                                        */
  -5.0451623403051087E-002,            /* Constant_Value : '<Root>/Constant'
                                        */
  1.5383401704007568E+001,             /* Gain1_Gain : '<Root>/Gain1'
                                        */
  2.8360681603030746E-001,             /* Constant5_Value : '<Root>/Constant5'
                                        */
  3.0756462096836199E+001,             /* Gain2_Gain : '<Root>/Gain2'
                                        */
  -4.1029022523348821E+001,            /* Constant6_Value : '<Root>/Constant6'
                                        */

  /*  RTDACPCIPWM_P1_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  3.0,                                 /* RTDACPCIPWM_P2 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size : '<S8>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_l : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_i : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_h : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P2_p : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_a : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_j : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_g : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_i : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_l : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_a : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_l : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_g : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_g : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_l : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_g : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_k : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_p : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P2_k : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_h : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_a : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_i : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_p : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_b : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_o : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_g : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_b : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_d : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_h : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_f : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_d : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_he : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  4.0,                                 /* RTDACPCIPWM_P2_i : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_ay : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_p : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_gk : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_a : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_g : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_j : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_i : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_c : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_p : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_lw : '<S7>/RT-DAC PCI PWM '
                                        */
  1.0,                                 /* Constant1_Value : '<Root>/Constant1'
                                        */
  1.0,                                 /* Constant2_Value : '<Root>/Constant2'
                                        */
  1.0,                                 /* Constant3_Value : '<Root>/Constant3'
                                        */
  1.0,                                 /* Constant4_Value : '<Root>/Constant4'
                                        */
  0.0,                                 /* SliderGain_Gain : '<S1>/Slider Gain'
                                        */
  0.0,                                 /* SliderGain_Gain_k : '<S4>/Slider Gain'
                                        */
  0.0,                                 /* SliderGain_Gain_p : '<S5>/Slider Gain'
                                        */
  0.0                                  /* SliderGain_Gain_f : '<S6>/Slider Gain'
                                        */
};
