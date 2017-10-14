/*
 * Zbiorniki2_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki2.mdl".
 *
 * Model Version              : 1.134
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Nov 11 14:54:15 2015
 */

#include "Zbiorniki2.h"
#include "Zbiorniki2_private.h"

/* Block parameters (auto storage) */
Parameters_Zbiorniki2 Zbiorniki2_P = {
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
  1.5644543616099167E+001,             /* Gain_Gain : '<Root>/Gain'
                                        */
  -2.2526791704034815E-001,            /* Constant_Value : '<Root>/Constant'
                                        */
  1.5383401704007568E+001,             /* Gain1_Gain : '<Root>/Gain1'
                                        */
  2.8360681603030746E-001,             /* Constant5_Value : '<Root>/Constant5'
                                        */
  1.0,                                 /* Gain2_Gain : '<Root>/Gain2'
                                        */
  0.0,                                 /* Constant6_Value : '<Root>/Constant6'
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
  59392.0,                             /* RTDACPCIPWM_P1_g : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_o : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P2_e : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_k : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_d : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_n : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_i : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_p : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_d : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_a : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_g : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_l : '<S9>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_i : '<S9>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_b : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_e : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_h : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P2_j : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_l : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_j : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_e : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_f : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_h : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_m : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_d : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_e : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_ly : '<S10>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_d : '<S10>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P1_Size_p : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  59392.0,                             /* RTDACPCIPWM_P1_n : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P2_Size_d : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  4.0,                                 /* RTDACPCIPWM_P2_jq : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P3_Size_c : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  2.0,                                 /* RTDACPCIPWM_P3_dn : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P4_Size_o : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  30.0,                                /* RTDACPCIPWM_P4_a : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P5_Size_g : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  1.0,                                 /* RTDACPCIPWM_P5_c : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P6_Size_m : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.0,                                 /* RTDACPCIPWM_P6_g1 : '<S7>/RT-DAC PCI PWM '
                                        */

  /*  RTDACPCIPWM_P7_Size_a : '<S7>/RT-DAC PCI PWM '
   */
  { 1.0, 1.0 },
  0.01,                                /* RTDACPCIPWM_P7_p : '<S7>/RT-DAC PCI PWM '
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
  0.0,                                 /* SliderGain_Gain_c : '<S5>/Slider Gain'
                                        */
  0.0                                  /* SliderGain_Gain_o : '<S6>/Slider Gain'
                                        */
};
