/*
 * Zbiorniki.c
 *
 * Code generation for model "Zbiorniki".
 *
 * Model version              : 1.122
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed Apr 26 12:05:57 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Zbiorniki.h"
#include "Zbiorniki_private.h"
#include "Zbiorniki_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Zbiorniki_T Zbiorniki_B;

/* Continuous states */
X_Zbiorniki_T Zbiorniki_X;

/* Block states (auto storage) */
DW_Zbiorniki_T Zbiorniki_DW;

/* Real-time model */
RT_MODEL_Zbiorniki_T Zbiorniki_M_;
RT_MODEL_Zbiorniki_T *const Zbiorniki_M = &Zbiorniki_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Zbiorniki_M->Timing.TaskCounters.TID[2])++;
  if ((Zbiorniki_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.05s, 0.0s] */
    Zbiorniki_M->Timing.TaskCounters.TID[2] = 0;
  }

  Zbiorniki_M->Timing.sampleHits[2] = (Zbiorniki_M->Timing.TaskCounters.TID[2] ==
    0);
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Zbiorniki_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Zbiorniki_output();
  Zbiorniki_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Zbiorniki_output();
  Zbiorniki_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Zbiorniki_output();
  Zbiorniki_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  Zbiorniki_output();
  Zbiorniki_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  Zbiorniki_output();
  Zbiorniki_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Zbiorniki_output(void)
{
  real_T rtb_Sum3;
  real_T u0;
  if (rtmIsMajorTimeStep(Zbiorniki_M)) {
    /* set solver stop time */
    if (!(Zbiorniki_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Zbiorniki_M->solverInfo,
                            ((Zbiorniki_M->Timing.clockTickH0 + 1) *
        Zbiorniki_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Zbiorniki_M->solverInfo,
                            ((Zbiorniki_M->Timing.clockTick0 + 1) *
        Zbiorniki_M->Timing.stepSize0 + Zbiorniki_M->Timing.clockTickH0 *
        Zbiorniki_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Zbiorniki_M)) {
    Zbiorniki_M->Timing.t[0] = rtsiGetT(&Zbiorniki_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Zbiorniki_M) &&
      Zbiorniki_M->Timing.TaskCounters.TID[2] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (rtmIsMajorTimeStep(Zbiorniki_M) &&
      Zbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    Zbiorniki_B.Gain = (Zbiorniki_B.RTDACAnalogInputs[0] -
                        Zbiorniki_P.Constant_Value) * Zbiorniki_P.Gain_Gain;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Sum: '<Root>/Sum1'
     */
    Zbiorniki_B.Gain1 = (Zbiorniki_B.RTDACAnalogInputs[1] -
                         Zbiorniki_P.Constant5_Value) * Zbiorniki_P.Gain1_Gain;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum2'
     */
    Zbiorniki_B.Gain2 = (Zbiorniki_B.RTDACAnalogInputs[2] -
                         Zbiorniki_P.Constant6_Value) * Zbiorniki_P.Gain2_Gain;

    /* Gain: '<S5>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Zbiorniki_B.SliderGain = Zbiorniki_P.ZaworGORA_gain *
      Zbiorniki_P.Constant1_Value;

    /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S6>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Zbiorniki_B.SliderGain_a = Zbiorniki_P.ZaworSRODEK_gain *
      Zbiorniki_P.Constant2_Value;

    /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Zbiorniki_B.SliderGain_ap = Zbiorniki_P.ZaworDOL_gain *
      Zbiorniki_P.Constant3_Value;

    /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  Zbiorniki_B.TransferFcn2 = 0.0;
  Zbiorniki_B.TransferFcn2 += Zbiorniki_P.TransferFcn2_C *
    Zbiorniki_X.TransferFcn2_CSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  rtb_Sum3 = Zbiorniki_P.Constant7_Value - Zbiorniki_B.TransferFcn2;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  Zbiorniki_B.FilterCoefficient = (Zbiorniki_P.PIDController1_D * rtb_Sum3 -
    Zbiorniki_X.Filter_CSTATE) * Zbiorniki_P.PIDController1_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = (Zbiorniki_P.PIDController1_P * rtb_Sum3 + Zbiorniki_X.Integrator_CSTATE)
    + Zbiorniki_B.FilterCoefficient;

  /* Saturate: '<S1>/Saturate' */
  if (u0 > Zbiorniki_P.PIDController1_UpperSaturationL) {
    Zbiorniki_B.Saturate = Zbiorniki_P.PIDController1_UpperSaturationL;
  } else if (u0 < Zbiorniki_P.PIDController1_LowerSaturationL) {
    Zbiorniki_B.Saturate = Zbiorniki_P.PIDController1_LowerSaturationL;
  } else {
    Zbiorniki_B.Saturate = u0;
  }

  /* End of Saturate: '<S1>/Saturate' */

  /* Gain: '<Root>/Gain3' */
  Zbiorniki_B.Gain3 = Zbiorniki_P.Gain3_Gain * Zbiorniki_B.Saturate;
  if (rtmIsMajorTimeStep(Zbiorniki_M) &&
      Zbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Zbiorniki_B.TransferFcn = 0.0;
  Zbiorniki_B.TransferFcn += Zbiorniki_P.TransferFcn_C *
    Zbiorniki_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Zbiorniki_B.TransferFcn1 = 0.0;
  Zbiorniki_B.TransferFcn1 += Zbiorniki_P.TransferFcn1_C *
    Zbiorniki_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(Zbiorniki_M) &&
      Zbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S1>/Integral Gain' */
  Zbiorniki_B.IntegralGain = Zbiorniki_P.PIDController1_I * rtb_Sum3;
}

/* Model update function */
void Zbiorniki_update(void)
{
  if (rtmIsMajorTimeStep(Zbiorniki_M)) {
    rt_ertODEUpdateContinuousStates(&Zbiorniki_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Zbiorniki_M->Timing.clockTick0)) {
    ++Zbiorniki_M->Timing.clockTickH0;
  }

  Zbiorniki_M->Timing.t[0] = rtsiGetSolverStopTime(&Zbiorniki_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Zbiorniki_M->Timing.clockTick1)) {
      ++Zbiorniki_M->Timing.clockTickH1;
    }

    Zbiorniki_M->Timing.t[1] = Zbiorniki_M->Timing.clockTick1 *
      Zbiorniki_M->Timing.stepSize1 + Zbiorniki_M->Timing.clockTickH1 *
      Zbiorniki_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Zbiorniki_M) &&
      Zbiorniki_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Zbiorniki_M->Timing.clockTick2)) {
      ++Zbiorniki_M->Timing.clockTickH2;
    }

    Zbiorniki_M->Timing.t[2] = Zbiorniki_M->Timing.clockTick2 *
      Zbiorniki_M->Timing.stepSize2 + Zbiorniki_M->Timing.clockTickH2 *
      Zbiorniki_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Zbiorniki_derivatives(void)
{
  XDot_Zbiorniki_T *_rtXdot;
  _rtXdot = ((XDot_Zbiorniki_T *) Zbiorniki_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += Zbiorniki_P.TransferFcn2_A *
    Zbiorniki_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += Zbiorniki_B.Gain2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Zbiorniki_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = Zbiorniki_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Zbiorniki_P.TransferFcn_A *
    Zbiorniki_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Zbiorniki_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += Zbiorniki_P.TransferFcn1_A *
    Zbiorniki_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Zbiorniki_B.Gain1;
}

/* Model initialize function */
void Zbiorniki_initialize(void)
{
  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  Zbiorniki_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Zbiorniki_X.Integrator_CSTATE = Zbiorniki_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  Zbiorniki_X.Filter_CSTATE = Zbiorniki_P.Filter_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Zbiorniki_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Zbiorniki_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void Zbiorniki_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[4];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Zbiorniki_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Zbiorniki_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Zbiorniki_initialize();
}

void MdlTerminate(void)
{
  Zbiorniki_terminate();
}

/* Registration function */
RT_MODEL_Zbiorniki_T *Zbiorniki(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Zbiorniki_M, 0,
                sizeof(RT_MODEL_Zbiorniki_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Zbiorniki_M->solverInfo,
                          &Zbiorniki_M->Timing.simTimeStep);
    rtsiSetTPtr(&Zbiorniki_M->solverInfo, &rtmGetTPtr(Zbiorniki_M));
    rtsiSetStepSizePtr(&Zbiorniki_M->solverInfo, &Zbiorniki_M->Timing.stepSize0);
    rtsiSetdXPtr(&Zbiorniki_M->solverInfo, &Zbiorniki_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Zbiorniki_M->solverInfo, (real_T **)
                         &Zbiorniki_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Zbiorniki_M->solverInfo,
      &Zbiorniki_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Zbiorniki_M->solverInfo, (&rtmGetErrorStatus
      (Zbiorniki_M)));
    rtsiSetRTModelPtr(&Zbiorniki_M->solverInfo, Zbiorniki_M);
  }

  rtsiSetSimTimeStep(&Zbiorniki_M->solverInfo, MAJOR_TIME_STEP);
  Zbiorniki_M->ModelData.intgData.y = Zbiorniki_M->ModelData.odeY;
  Zbiorniki_M->ModelData.intgData.f[0] = Zbiorniki_M->ModelData.odeF[0];
  Zbiorniki_M->ModelData.intgData.f[1] = Zbiorniki_M->ModelData.odeF[1];
  Zbiorniki_M->ModelData.intgData.f[2] = Zbiorniki_M->ModelData.odeF[2];
  Zbiorniki_M->ModelData.intgData.f[3] = Zbiorniki_M->ModelData.odeF[3];
  Zbiorniki_M->ModelData.intgData.f[4] = Zbiorniki_M->ModelData.odeF[4];
  Zbiorniki_M->ModelData.intgData.f[5] = Zbiorniki_M->ModelData.odeF[5];
  Zbiorniki_M->ModelData.contStates = ((real_T *) &Zbiorniki_X);
  rtsiSetSolverData(&Zbiorniki_M->solverInfo, (void *)
                    &Zbiorniki_M->ModelData.intgData);
  rtsiSetSolverName(&Zbiorniki_M->solverInfo,"ode5");
  Zbiorniki_M->solverInfoPtr = (&Zbiorniki_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Zbiorniki_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Zbiorniki_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Zbiorniki_M->Timing.sampleTimes = (&Zbiorniki_M->Timing.sampleTimesArray[0]);
    Zbiorniki_M->Timing.offsetTimes = (&Zbiorniki_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Zbiorniki_M->Timing.sampleTimes[0] = (0.0);
    Zbiorniki_M->Timing.sampleTimes[1] = (0.01);
    Zbiorniki_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    Zbiorniki_M->Timing.offsetTimes[0] = (0.0);
    Zbiorniki_M->Timing.offsetTimes[1] = (0.0);
    Zbiorniki_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Zbiorniki_M, &Zbiorniki_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Zbiorniki_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Zbiorniki_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Zbiorniki_M, 999.0);
  Zbiorniki_M->Timing.stepSize0 = 0.01;
  Zbiorniki_M->Timing.stepSize1 = 0.01;
  Zbiorniki_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  Zbiorniki_M->Sizes.checksums[0] = (3685186358U);
  Zbiorniki_M->Sizes.checksums[1] = (3947578571U);
  Zbiorniki_M->Sizes.checksums[2] = (2399762872U);
  Zbiorniki_M->Sizes.checksums[3] = (3245159297U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Zbiorniki_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Zbiorniki_M->extModeInfo,
      &Zbiorniki_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Zbiorniki_M->extModeInfo, Zbiorniki_M->Sizes.checksums);
    rteiSetTPtr(Zbiorniki_M->extModeInfo, rtmGetTPtr(Zbiorniki_M));
  }

  Zbiorniki_M->solverInfoPtr = (&Zbiorniki_M->solverInfo);
  Zbiorniki_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Zbiorniki_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Zbiorniki_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Zbiorniki_M->ModelData.blockIO = ((void *) &Zbiorniki_B);

  {
    Zbiorniki_B.RTDACAnalogInputs[0] = 0.0;
    Zbiorniki_B.RTDACAnalogInputs[1] = 0.0;
    Zbiorniki_B.RTDACAnalogInputs[2] = 0.0;
    Zbiorniki_B.Gain = 0.0;
    Zbiorniki_B.Gain1 = 0.0;
    Zbiorniki_B.Gain2 = 0.0;
    Zbiorniki_B.SliderGain = 0.0;
    Zbiorniki_B.SliderGain_a = 0.0;
    Zbiorniki_B.SliderGain_ap = 0.0;
    Zbiorniki_B.TransferFcn2 = 0.0;
    Zbiorniki_B.FilterCoefficient = 0.0;
    Zbiorniki_B.Saturate = 0.0;
    Zbiorniki_B.Gain3 = 0.0;
    Zbiorniki_B.TransferFcn = 0.0;
    Zbiorniki_B.TransferFcn1 = 0.0;
    Zbiorniki_B.IntegralGain = 0.0;
  }

  /* parameters */
  Zbiorniki_M->ModelData.defaultParam = ((real_T *)&Zbiorniki_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Zbiorniki_X;
    Zbiorniki_M->ModelData.contStates = (x);
    (void) memset((void *)&Zbiorniki_X, 0,
                  sizeof(X_Zbiorniki_T));
  }

  /* states (dwork) */
  Zbiorniki_M->ModelData.dwork = ((void *) &Zbiorniki_DW);
  (void) memset((void *)&Zbiorniki_DW, 0,
                sizeof(DW_Zbiorniki_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Zbiorniki_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Zbiorniki_M->NonInlinedSFcns.sfcnInfo;
    Zbiorniki_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Zbiorniki_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Zbiorniki_M->Sizes.numSampTimes);
    Zbiorniki_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Zbiorniki_M)[0]);
    Zbiorniki_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Zbiorniki_M)[1]);
    Zbiorniki_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(Zbiorniki_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,Zbiorniki_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Zbiorniki_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Zbiorniki_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Zbiorniki_M));
    rtssSetStepSizePtr(sfcnInfo, &Zbiorniki_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Zbiorniki_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Zbiorniki_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Zbiorniki_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Zbiorniki_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Zbiorniki_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Zbiorniki_M->solverInfoPtr);
  }

  Zbiorniki_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&Zbiorniki_M->NonInlinedSFcns.childSFunctions[0], 0,
                  5*sizeof(SimStruct));
    Zbiorniki_M->childSfunctions =
      (&Zbiorniki_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Zbiorniki_M->childSfunctions[i] =
          (&Zbiorniki_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Zbiorniki/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Zbiorniki_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Zbiorniki_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Zbiorniki_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Zbiorniki_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "Zbiorniki/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Zbiorniki_P.RTDACAnalogInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Zbiorniki_P.RTDACAnalogInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Zbiorniki_P.RTDACAnalogInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Zbiorniki_P.RTDACAnalogInputs_P4_Size);
      }

      /* registration */
      rtdacpci_analoginputs(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Zbiorniki/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Zbiorniki_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Zbiorniki_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Zbiorniki_P.pooled1);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Zbiorniki_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Zbiorniki_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P5_Size_h);
        ssSetSFcnParam(rts, 5, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)Zbiorniki_P.pooled1);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Zbiorniki_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Zbiorniki_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain_ap;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P6_Size_l);
        ssSetSFcnParam(rts, 6, (mxArray*)Zbiorniki_P.pooled1);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Zbiorniki_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Zbiorniki_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki_B.Gain3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)Zbiorniki_P.RTDACPCIPWM_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)Zbiorniki_P.pooled1);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  Zbiorniki_M->Sizes.numContStates = (5);/* Number of continuous states */
  Zbiorniki_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Zbiorniki_M->Sizes.numY = (0);       /* Number of model outputs */
  Zbiorniki_M->Sizes.numU = (0);       /* Number of model inputs */
  Zbiorniki_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Zbiorniki_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Zbiorniki_M->Sizes.numBlocks = (39); /* Number of blocks */
  Zbiorniki_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  Zbiorniki_M->Sizes.numBlockPrms = (119);/* Sum of parameter "widths" */
  return Zbiorniki_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
