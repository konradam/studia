/*
 * Pidzbiorniki.c
 *
 * Code generation for model "Pidzbiorniki".
 *
 * Model version              : 1.131
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed May 24 11:54:06 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pidzbiorniki.h"
#include "Pidzbiorniki_private.h"
#include "Pidzbiorniki_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Pidzbiorniki_T Pidzbiorniki_B;

/* Continuous states */
X_Pidzbiorniki_T Pidzbiorniki_X;

/* Block states (auto storage) */
DW_Pidzbiorniki_T Pidzbiorniki_DW;

/* Real-time model */
RT_MODEL_Pidzbiorniki_T Pidzbiorniki_M_;
RT_MODEL_Pidzbiorniki_T *const Pidzbiorniki_M = &Pidzbiorniki_M_;
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
  (Pidzbiorniki_M->Timing.TaskCounters.TID[2])++;
  if ((Pidzbiorniki_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.05s, 0.0s] */
    Pidzbiorniki_M->Timing.TaskCounters.TID[2] = 0;
  }

  Pidzbiorniki_M->Timing.sampleHits[2] =
    (Pidzbiorniki_M->Timing.TaskCounters.TID[2] == 0);
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Pidzbiorniki_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Pidzbiorniki_output();
  Pidzbiorniki_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Pidzbiorniki_output();
  Pidzbiorniki_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Pidzbiorniki_output();
  Pidzbiorniki_derivatives();

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
  Pidzbiorniki_output();
  Pidzbiorniki_derivatives();

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
  Pidzbiorniki_output();
  Pidzbiorniki_derivatives();

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
void Pidzbiorniki_output(void)
{
  real_T rtb_Sum3;
  real_T u0;
  if (rtmIsMajorTimeStep(Pidzbiorniki_M)) {
    /* set solver stop time */
    if (!(Pidzbiorniki_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Pidzbiorniki_M->solverInfo,
                            ((Pidzbiorniki_M->Timing.clockTickH0 + 1) *
        Pidzbiorniki_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Pidzbiorniki_M->solverInfo,
                            ((Pidzbiorniki_M->Timing.clockTick0 + 1) *
        Pidzbiorniki_M->Timing.stepSize0 + Pidzbiorniki_M->Timing.clockTickH0 *
        Pidzbiorniki_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Pidzbiorniki_M)) {
    Pidzbiorniki_M->Timing.t[0] = rtsiGetT(&Pidzbiorniki_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[2] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    Pidzbiorniki_B.Gain = (Pidzbiorniki_B.RTDACAnalogInputs[0] -
      Pidzbiorniki_P.Constant_Value) * Pidzbiorniki_P.Gain_Gain;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Sum: '<Root>/Sum1'
     */
    Pidzbiorniki_B.Gain1 = (Pidzbiorniki_B.RTDACAnalogInputs[1] -
      Pidzbiorniki_P.Constant5_Value) * Pidzbiorniki_P.Gain1_Gain;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum2'
     */
    Pidzbiorniki_B.Gain2 = (Pidzbiorniki_B.RTDACAnalogInputs[2] -
      Pidzbiorniki_P.Constant6_Value) * Pidzbiorniki_P.Gain2_Gain;

    /* Gain: '<S5>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Pidzbiorniki_B.SliderGain = Pidzbiorniki_P.ZaworGORA_gain *
      Pidzbiorniki_P.Constant1_Value;

    /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S6>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Pidzbiorniki_B.SliderGain_a = Pidzbiorniki_P.ZaworSRODEK_gain *
      Pidzbiorniki_P.Constant2_Value;

    /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Pidzbiorniki_B.SliderGain_ap = Pidzbiorniki_P.ZaworDOL_gain *
      Pidzbiorniki_P.Constant3_Value;

    /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  Pidzbiorniki_B.TransferFcn2 = 0.0;
  Pidzbiorniki_B.TransferFcn2 += Pidzbiorniki_P.TransferFcn2_C *
    Pidzbiorniki_X.TransferFcn2_CSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn3'
   */
  rtb_Sum3 = Pidzbiorniki_P.TransferFcn3_C * Pidzbiorniki_X.TransferFcn3_CSTATE
    - Pidzbiorniki_B.TransferFcn2;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  Pidzbiorniki_B.FilterCoefficient = (Pidzbiorniki_P.PIDController4_D * rtb_Sum3
    - Pidzbiorniki_X.Filter_CSTATE) * Pidzbiorniki_P.PIDController4_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = (Pidzbiorniki_P.PIDController4_P * rtb_Sum3 +
        Pidzbiorniki_X.Integrator_CSTATE) + Pidzbiorniki_B.FilterCoefficient;

  /* Saturate: '<S1>/Saturate' */
  if (u0 > Pidzbiorniki_P.PIDController4_UpperSaturationL) {
    u0 = Pidzbiorniki_P.PIDController4_UpperSaturationL;
  } else {
    if (u0 < Pidzbiorniki_P.PIDController4_LowerSaturationL) {
      u0 = Pidzbiorniki_P.PIDController4_LowerSaturationL;
    }
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Saturate: '<S1>/Saturate'
   */
  Pidzbiorniki_B.Gain3 = Pidzbiorniki_P.Gain3_Gain * u0;
  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Pidzbiorniki_B.TransferFcn = 0.0;
  Pidzbiorniki_B.TransferFcn += Pidzbiorniki_P.TransferFcn_C *
    Pidzbiorniki_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Pidzbiorniki_B.TransferFcn1 = 0.0;
  Pidzbiorniki_B.TransferFcn1 += Pidzbiorniki_P.TransferFcn1_C *
    Pidzbiorniki_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S1>/Integral Gain' */
  Pidzbiorniki_B.IntegralGain = Pidzbiorniki_P.PIDController4_I * rtb_Sum3;
  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
  }
}

/* Model update function */
void Pidzbiorniki_update(void)
{
  if (rtmIsMajorTimeStep(Pidzbiorniki_M)) {
    rt_ertODEUpdateContinuousStates(&Pidzbiorniki_M->solverInfo);
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
  if (!(++Pidzbiorniki_M->Timing.clockTick0)) {
    ++Pidzbiorniki_M->Timing.clockTickH0;
  }

  Pidzbiorniki_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Pidzbiorniki_M->solverInfo);

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
    if (!(++Pidzbiorniki_M->Timing.clockTick1)) {
      ++Pidzbiorniki_M->Timing.clockTickH1;
    }

    Pidzbiorniki_M->Timing.t[1] = Pidzbiorniki_M->Timing.clockTick1 *
      Pidzbiorniki_M->Timing.stepSize1 + Pidzbiorniki_M->Timing.clockTickH1 *
      Pidzbiorniki_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Pidzbiorniki_M) &&
      Pidzbiorniki_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Pidzbiorniki_M->Timing.clockTick2)) {
      ++Pidzbiorniki_M->Timing.clockTickH2;
    }

    Pidzbiorniki_M->Timing.t[2] = Pidzbiorniki_M->Timing.clockTick2 *
      Pidzbiorniki_M->Timing.stepSize2 + Pidzbiorniki_M->Timing.clockTickH2 *
      Pidzbiorniki_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Pidzbiorniki_derivatives(void)
{
  XDot_Pidzbiorniki_T *_rtXdot;
  _rtXdot = ((XDot_Pidzbiorniki_T *) Pidzbiorniki_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += Pidzbiorniki_P.TransferFcn3_A *
    Pidzbiorniki_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += Pidzbiorniki_P.Constant4_Value;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += Pidzbiorniki_P.TransferFcn2_A *
    Pidzbiorniki_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += Pidzbiorniki_B.Gain2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Pidzbiorniki_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = Pidzbiorniki_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Pidzbiorniki_P.TransferFcn_A *
    Pidzbiorniki_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Pidzbiorniki_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += Pidzbiorniki_P.TransferFcn1_A *
    Pidzbiorniki_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Pidzbiorniki_B.Gain1;
}

/* Model initialize function */
void Pidzbiorniki_initialize(void)
{
  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  Pidzbiorniki_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  Pidzbiorniki_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Pidzbiorniki_X.Integrator_CSTATE = Pidzbiorniki_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  Pidzbiorniki_X.Filter_CSTATE = Pidzbiorniki_P.Filter_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Pidzbiorniki_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Pidzbiorniki_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void Pidzbiorniki_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Pidzbiorniki_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pidzbiorniki_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pidzbiorniki_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pidzbiorniki_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pidzbiorniki_M->childSfunctions[4];
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
  Pidzbiorniki_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pidzbiorniki_update();
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
  Pidzbiorniki_initialize();
}

void MdlTerminate(void)
{
  Pidzbiorniki_terminate();
}

/* Registration function */
RT_MODEL_Pidzbiorniki_T *Pidzbiorniki(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Pidzbiorniki_P.PIDController4_UpperSaturationL = rtInf;

  /* initialize real-time model */
  (void) memset((void *)Pidzbiorniki_M, 0,
                sizeof(RT_MODEL_Pidzbiorniki_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pidzbiorniki_M->solverInfo,
                          &Pidzbiorniki_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pidzbiorniki_M->solverInfo, &rtmGetTPtr(Pidzbiorniki_M));
    rtsiSetStepSizePtr(&Pidzbiorniki_M->solverInfo,
                       &Pidzbiorniki_M->Timing.stepSize0);
    rtsiSetdXPtr(&Pidzbiorniki_M->solverInfo, &Pidzbiorniki_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Pidzbiorniki_M->solverInfo, (real_T **)
                         &Pidzbiorniki_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Pidzbiorniki_M->solverInfo,
      &Pidzbiorniki_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Pidzbiorniki_M->solverInfo, (&rtmGetErrorStatus
      (Pidzbiorniki_M)));
    rtsiSetRTModelPtr(&Pidzbiorniki_M->solverInfo, Pidzbiorniki_M);
  }

  rtsiSetSimTimeStep(&Pidzbiorniki_M->solverInfo, MAJOR_TIME_STEP);
  Pidzbiorniki_M->ModelData.intgData.y = Pidzbiorniki_M->ModelData.odeY;
  Pidzbiorniki_M->ModelData.intgData.f[0] = Pidzbiorniki_M->ModelData.odeF[0];
  Pidzbiorniki_M->ModelData.intgData.f[1] = Pidzbiorniki_M->ModelData.odeF[1];
  Pidzbiorniki_M->ModelData.intgData.f[2] = Pidzbiorniki_M->ModelData.odeF[2];
  Pidzbiorniki_M->ModelData.intgData.f[3] = Pidzbiorniki_M->ModelData.odeF[3];
  Pidzbiorniki_M->ModelData.intgData.f[4] = Pidzbiorniki_M->ModelData.odeF[4];
  Pidzbiorniki_M->ModelData.intgData.f[5] = Pidzbiorniki_M->ModelData.odeF[5];
  Pidzbiorniki_M->ModelData.contStates = ((real_T *) &Pidzbiorniki_X);
  rtsiSetSolverData(&Pidzbiorniki_M->solverInfo, (void *)
                    &Pidzbiorniki_M->ModelData.intgData);
  rtsiSetSolverName(&Pidzbiorniki_M->solverInfo,"ode5");
  Pidzbiorniki_M->solverInfoPtr = (&Pidzbiorniki_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pidzbiorniki_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Pidzbiorniki_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pidzbiorniki_M->Timing.sampleTimes =
      (&Pidzbiorniki_M->Timing.sampleTimesArray[0]);
    Pidzbiorniki_M->Timing.offsetTimes =
      (&Pidzbiorniki_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pidzbiorniki_M->Timing.sampleTimes[0] = (0.0);
    Pidzbiorniki_M->Timing.sampleTimes[1] = (0.01);
    Pidzbiorniki_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    Pidzbiorniki_M->Timing.offsetTimes[0] = (0.0);
    Pidzbiorniki_M->Timing.offsetTimes[1] = (0.0);
    Pidzbiorniki_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Pidzbiorniki_M, &Pidzbiorniki_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pidzbiorniki_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Pidzbiorniki_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pidzbiorniki_M, 999.0);
  Pidzbiorniki_M->Timing.stepSize0 = 0.01;
  Pidzbiorniki_M->Timing.stepSize1 = 0.01;
  Pidzbiorniki_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  Pidzbiorniki_M->Sizes.checksums[0] = (4049100544U);
  Pidzbiorniki_M->Sizes.checksums[1] = (2115925076U);
  Pidzbiorniki_M->Sizes.checksums[2] = (1390645455U);
  Pidzbiorniki_M->Sizes.checksums[3] = (414745005U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Pidzbiorniki_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Pidzbiorniki_M->extModeInfo,
      &Pidzbiorniki_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Pidzbiorniki_M->extModeInfo,
                        Pidzbiorniki_M->Sizes.checksums);
    rteiSetTPtr(Pidzbiorniki_M->extModeInfo, rtmGetTPtr(Pidzbiorniki_M));
  }

  Pidzbiorniki_M->solverInfoPtr = (&Pidzbiorniki_M->solverInfo);
  Pidzbiorniki_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Pidzbiorniki_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Pidzbiorniki_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Pidzbiorniki_M->ModelData.blockIO = ((void *) &Pidzbiorniki_B);

  {
    Pidzbiorniki_B.RTDACAnalogInputs[0] = 0.0;
    Pidzbiorniki_B.RTDACAnalogInputs[1] = 0.0;
    Pidzbiorniki_B.RTDACAnalogInputs[2] = 0.0;
    Pidzbiorniki_B.Gain = 0.0;
    Pidzbiorniki_B.Gain1 = 0.0;
    Pidzbiorniki_B.Gain2 = 0.0;
    Pidzbiorniki_B.SliderGain = 0.0;
    Pidzbiorniki_B.SliderGain_a = 0.0;
    Pidzbiorniki_B.SliderGain_ap = 0.0;
    Pidzbiorniki_B.TransferFcn2 = 0.0;
    Pidzbiorniki_B.FilterCoefficient = 0.0;
    Pidzbiorniki_B.Gain3 = 0.0;
    Pidzbiorniki_B.TransferFcn = 0.0;
    Pidzbiorniki_B.TransferFcn1 = 0.0;
    Pidzbiorniki_B.IntegralGain = 0.0;
  }

  /* parameters */
  Pidzbiorniki_M->ModelData.defaultParam = ((real_T *)&Pidzbiorniki_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Pidzbiorniki_X;
    Pidzbiorniki_M->ModelData.contStates = (x);
    (void) memset((void *)&Pidzbiorniki_X, 0,
                  sizeof(X_Pidzbiorniki_T));
  }

  /* states (dwork) */
  Pidzbiorniki_M->ModelData.dwork = ((void *) &Pidzbiorniki_DW);
  (void) memset((void *)&Pidzbiorniki_DW, 0,
                sizeof(DW_Pidzbiorniki_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Pidzbiorniki_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Pidzbiorniki_M->NonInlinedSFcns.sfcnInfo;
    Pidzbiorniki_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Pidzbiorniki_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Pidzbiorniki_M->Sizes.numSampTimes);
    Pidzbiorniki_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Pidzbiorniki_M)[0]);
    Pidzbiorniki_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Pidzbiorniki_M)[1]);
    Pidzbiorniki_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (Pidzbiorniki_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,Pidzbiorniki_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Pidzbiorniki_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Pidzbiorniki_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Pidzbiorniki_M));
    rtssSetStepSizePtr(sfcnInfo, &Pidzbiorniki_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Pidzbiorniki_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Pidzbiorniki_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Pidzbiorniki_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Pidzbiorniki_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Pidzbiorniki_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Pidzbiorniki_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Pidzbiorniki_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Pidzbiorniki_M->solverInfoPtr);
  }

  Pidzbiorniki_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&Pidzbiorniki_M->NonInlinedSFcns.childSFunctions[0], 0,
                  5*sizeof(SimStruct));
    Pidzbiorniki_M->childSfunctions =
      (&Pidzbiorniki_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Pidzbiorniki_M->childSfunctions[i] =
          (&Pidzbiorniki_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Pidzbiorniki/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Pidzbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Pidzbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Pidzbiorniki_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pidzbiorniki_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Pidzbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pidzbiorniki_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Pidzbiorniki_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "Pidzbiorniki/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,Pidzbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Pidzbiorniki_P.RTDACAnalogInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Pidzbiorniki_P.RTDACAnalogInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Pidzbiorniki_P.RTDACAnalogInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Pidzbiorniki_P.RTDACAnalogInputs_P4_Size);
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

    /* Level2 S-Function Block: Pidzbiorniki/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pidzbiorniki_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Pidzbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pidzbiorniki_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Pidzbiorniki_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "Pidzbiorniki/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pidzbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Pidzbiorniki_P.pooled1);
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

    /* Level2 S-Function Block: Pidzbiorniki/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pidzbiorniki_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Pidzbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pidzbiorniki_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Pidzbiorniki_B.SliderGain_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "Pidzbiorniki/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pidzbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P5_Size_h);
        ssSetSFcnParam(rts, 5, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)Pidzbiorniki_P.pooled1);
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

    /* Level2 S-Function Block: Pidzbiorniki/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pidzbiorniki_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Pidzbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pidzbiorniki_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Pidzbiorniki_B.SliderGain_ap;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "Pidzbiorniki/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pidzbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P6_Size_l);
        ssSetSFcnParam(rts, 6, (mxArray*)Pidzbiorniki_P.pooled1);
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

    /* Level2 S-Function Block: Pidzbiorniki/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pidzbiorniki_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pidzbiorniki_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Pidzbiorniki_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pidzbiorniki_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pidzbiorniki_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Pidzbiorniki_B.Gain3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Pidzbiorniki/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pidzbiorniki_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pidzbiorniki_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)Pidzbiorniki_P.RTDACPCIPWM_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)Pidzbiorniki_P.pooled1);
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
  Pidzbiorniki_M->Sizes.numContStates = (6);/* Number of continuous states */
  Pidzbiorniki_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Pidzbiorniki_M->Sizes.numY = (0);    /* Number of model outputs */
  Pidzbiorniki_M->Sizes.numU = (0);    /* Number of model inputs */
  Pidzbiorniki_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Pidzbiorniki_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Pidzbiorniki_M->Sizes.numBlocks = (41);/* Number of blocks */
  Pidzbiorniki_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  Pidzbiorniki_M->Sizes.numBlockPrms = (121);/* Sum of parameter "widths" */
  return Pidzbiorniki_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
