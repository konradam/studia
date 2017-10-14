/*
 * Zbiorniki1_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki1.mdl".
 *
 * Model Version              : 1.121
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Thu Nov 05 17:15:12 2015
 */

#include "Zbiorniki1.h"
#include "Zbiorniki1_private.h"

/* Block parameters (auto storage) */
Parameters_Zbiorniki1 Zbiorniki1_P = {
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
  0.05,                                /* Constant_Value : '<Root>/Constant'
                                        */
  16.4,                                /* Gain_Gain : '<Root>/Gain'
                                        */
  0.05,                                /* Constant5_Value : '<Root>/Constant5'
                                        */
  15.9,                                /* Gain1_Gain : '<Root>/Gain1'
                                        */
  1.04,                                /* Constant6_Value : '<Root>/Constant6'
                                        */
  26.0,                                /* Gain2_Gain : '<Root>/Gain2'
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
  0.05,                                /* RTDACPCIPWM_P7 : '<S8>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_k : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_a : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_c : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P2_a : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_a : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_h : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_c : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_g : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_j : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_o : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_o : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_m : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_l : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.05,                                /* RTDACPCIPWM_P7_a : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_j : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_j : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_g : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P2_d : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_o : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_o : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_d : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_a : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_h : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_l : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_g : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_b : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_a : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.05,                                /* RTDACPCIPWM_P7_e : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_n : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_e : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_e : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  4.0,                                 /* RTDACPCIPWM_P2_i : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_n : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_g : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_l : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_n : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_i : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_h : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_d : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_h : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_c : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.05,                                /* RTDACPCIPWM_P7_l : '<S7>/RT-DAC PCI PWM '
                                        */
  1.0,                                 /* Constant4_Value : '<Root>/Constant4'
                                        */
  0.3,                                 /* SliderGain_Gain : '<S1>/Slider Gain'
                                        */
  1.0,                                 /* Constant1_Value : '<Root>/Constant1'
                                        */
  1.0,                                 /* Constant2_Value : '<Root>/Constant2'
                                        */
  1.0,                                 /* Constant3_Value : '<Root>/Constant3'
                                        */
  0.65,                                /* SliderGain_Gain_i : '<S4>/Slider Gain'
                                        */
  0.0,                                 /* SliderGain_Gain_l : '<S5>/Slider Gain'
                                        */
  0.0                                  /* SliderGain_Gain_b : '<S6>/Slider Gain'
                                        */
};
