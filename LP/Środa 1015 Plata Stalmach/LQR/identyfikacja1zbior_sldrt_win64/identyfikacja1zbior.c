/*
 * identyfikacja1zbior.c
 *
 * Code generation for model "identyfikacja1zbior".
 *
 * Model version              : 1.128
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed May 24 10:53:26 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "identyfikacja1zbior.h"
#include "identyfikacja1zbior_private.h"
#include "identyfikacja1zbior_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_identyfikacja1zbior_T identyfikacja1zbior_B;

/* Continuous states */
X_identyfikacja1zbior_T identyfikacja1zbior_X;

/* Block states (auto storage) */
DW_identyfikacja1zbior_T identyfikacja1zbior_DW;

/* Real-time model */
RT_MODEL_identyfikacja1zbior_T identyfikacja1zbior_M_;
RT_MODEL_identyfikacja1zbior_T *const identyfikacja1zbior_M =
  &identyfikacja1zbior_M_;
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
  (identyfikacja1zbior_M->Timing.TaskCounters.TID[2])++;
  if ((identyfikacja1zbior_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.05s, 0.0s] */
    identyfikacja1zbior_M->Timing.TaskCounters.TID[2] = 0;
  }

  identyfikacja1zbior_M->Timing.sampleHits[2] =
    (identyfikacja1zbior_M->Timing.TaskCounters.TID[2] == 0);
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  identyfikacja1zbior_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  identyfikacja1zbior_output();
  identyfikacja1zbior_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  identyfikacja1zbior_output();
  identyfikacja1zbior_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  identyfikacja1zbior_output();
  identyfikacja1zbior_derivatives();

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
  identyfikacja1zbior_output();
  identyfikacja1zbior_derivatives();

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
  identyfikacja1zbior_output();
  identyfikacja1zbior_derivatives();

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
void identyfikacja1zbior_output(void)
{
  if (rtmIsMajorTimeStep(identyfikacja1zbior_M)) {
    /* set solver stop time */
    if (!(identyfikacja1zbior_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&identyfikacja1zbior_M->solverInfo,
                            ((identyfikacja1zbior_M->Timing.clockTickH0 + 1) *
        identyfikacja1zbior_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&identyfikacja1zbior_M->solverInfo,
                            ((identyfikacja1zbior_M->Timing.clockTick0 + 1) *
        identyfikacja1zbior_M->Timing.stepSize0 +
        identyfikacja1zbior_M->Timing.clockTickH0 *
        identyfikacja1zbior_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(identyfikacja1zbior_M)) {
    identyfikacja1zbior_M->Timing.t[0] = rtsiGetT
      (&identyfikacja1zbior_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(identyfikacja1zbior_M) &&
      identyfikacja1zbior_M->Timing.TaskCounters.TID[2] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (rtmIsMajorTimeStep(identyfikacja1zbior_M) &&
      identyfikacja1zbior_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    identyfikacja1zbior_B.Gain = (identyfikacja1zbior_B.RTDACAnalogInputs[0] -
      identyfikacja1zbior_P.Constant_Value) * identyfikacja1zbior_P.Gain_Gain;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Sum: '<Root>/Sum1'
     */
    identyfikacja1zbior_B.Gain1 = (identyfikacja1zbior_B.RTDACAnalogInputs[1] -
      identyfikacja1zbior_P.Constant5_Value) * identyfikacja1zbior_P.Gain1_Gain;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum2'
     */
    identyfikacja1zbior_B.Gain2 = (identyfikacja1zbior_B.RTDACAnalogInputs[2] -
      identyfikacja1zbior_P.Constant6_Value) * identyfikacja1zbior_P.Gain2_Gain;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  identyfikacja1zbior_B.TransferFcn = 0.0;
  identyfikacja1zbior_B.TransferFcn += identyfikacja1zbior_P.TransferFcn_C *
    identyfikacja1zbior_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  identyfikacja1zbior_B.TransferFcn1 = 0.0;
  identyfikacja1zbior_B.TransferFcn1 += identyfikacja1zbior_P.TransferFcn1_C *
    identyfikacja1zbior_X.TransferFcn1_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  identyfikacja1zbior_B.TransferFcn2 = 0.0;
  identyfikacja1zbior_B.TransferFcn2 += identyfikacja1zbior_P.TransferFcn2_C *
    identyfikacja1zbior_X.TransferFcn2_CSTATE;
  if (rtmIsMajorTimeStep(identyfikacja1zbior_M) &&
      identyfikacja1zbior_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S5>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    identyfikacja1zbior_B.SliderGain = identyfikacja1zbior_P.ZaworGORA_gain *
      identyfikacja1zbior_P.Constant1_Value;

    /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S6>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    identyfikacja1zbior_B.SliderGain_a = identyfikacja1zbior_P.ZaworSRODEK_gain *
      identyfikacja1zbior_P.Constant2_Value;

    /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    identyfikacja1zbior_B.SliderGain_ap = identyfikacja1zbior_P.ZaworDOL_gain *
      identyfikacja1zbior_P.Constant3_Value;

    /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S1>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    identyfikacja1zbior_B.SliderGain_ay = identyfikacja1zbior_P.Pompa_gain *
      identyfikacja1zbior_P.Constant4_Value;

    /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }
  }
}

/* Model update function */
void identyfikacja1zbior_update(void)
{
  if (rtmIsMajorTimeStep(identyfikacja1zbior_M)) {
    rt_ertODEUpdateContinuousStates(&identyfikacja1zbior_M->solverInfo);
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
  if (!(++identyfikacja1zbior_M->Timing.clockTick0)) {
    ++identyfikacja1zbior_M->Timing.clockTickH0;
  }

  identyfikacja1zbior_M->Timing.t[0] = rtsiGetSolverStopTime
    (&identyfikacja1zbior_M->solverInfo);

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
    if (!(++identyfikacja1zbior_M->Timing.clockTick1)) {
      ++identyfikacja1zbior_M->Timing.clockTickH1;
    }

    identyfikacja1zbior_M->Timing.t[1] =
      identyfikacja1zbior_M->Timing.clockTick1 *
      identyfikacja1zbior_M->Timing.stepSize1 +
      identyfikacja1zbior_M->Timing.clockTickH1 *
      identyfikacja1zbior_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(identyfikacja1zbior_M) &&
      identyfikacja1zbior_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++identyfikacja1zbior_M->Timing.clockTick2)) {
      ++identyfikacja1zbior_M->Timing.clockTickH2;
    }

    identyfikacja1zbior_M->Timing.t[2] =
      identyfikacja1zbior_M->Timing.clockTick2 *
      identyfikacja1zbior_M->Timing.stepSize2 +
      identyfikacja1zbior_M->Timing.clockTickH2 *
      identyfikacja1zbior_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void identyfikacja1zbior_derivatives(void)
{
  XDot_identyfikacja1zbior_T *_rtXdot;
  _rtXdot = ((XDot_identyfikacja1zbior_T *)
             identyfikacja1zbior_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += identyfikacja1zbior_P.TransferFcn_A *
    identyfikacja1zbior_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += identyfikacja1zbior_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += identyfikacja1zbior_P.TransferFcn1_A *
    identyfikacja1zbior_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += identyfikacja1zbior_B.Gain1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += identyfikacja1zbior_P.TransferFcn2_A *
    identyfikacja1zbior_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += identyfikacja1zbior_B.Gain2;
}

/* Model initialize function */
void identyfikacja1zbior_initialize(void)
{
  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  identyfikacja1zbior_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  identyfikacja1zbior_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  identyfikacja1zbior_X.TransferFcn2_CSTATE = 0.0;
}

/* Model terminate function */
void identyfikacja1zbior_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = identyfikacja1zbior_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = identyfikacja1zbior_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = identyfikacja1zbior_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = identyfikacja1zbior_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = identyfikacja1zbior_M->childSfunctions[4];
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
  identyfikacja1zbior_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  identyfikacja1zbior_update();
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
  identyfikacja1zbior_initialize();
}

void MdlTerminate(void)
{
  identyfikacja1zbior_terminate();
}

/* Registration function */
RT_MODEL_identyfikacja1zbior_T *identyfikacja1zbior(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)identyfikacja1zbior_M, 0,
                sizeof(RT_MODEL_identyfikacja1zbior_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&identyfikacja1zbior_M->solverInfo,
                          &identyfikacja1zbior_M->Timing.simTimeStep);
    rtsiSetTPtr(&identyfikacja1zbior_M->solverInfo, &rtmGetTPtr
                (identyfikacja1zbior_M));
    rtsiSetStepSizePtr(&identyfikacja1zbior_M->solverInfo,
                       &identyfikacja1zbior_M->Timing.stepSize0);
    rtsiSetdXPtr(&identyfikacja1zbior_M->solverInfo,
                 &identyfikacja1zbior_M->ModelData.derivs);
    rtsiSetContStatesPtr(&identyfikacja1zbior_M->solverInfo, (real_T **)
                         &identyfikacja1zbior_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&identyfikacja1zbior_M->solverInfo,
      &identyfikacja1zbior_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&identyfikacja1zbior_M->solverInfo,
                          (&rtmGetErrorStatus(identyfikacja1zbior_M)));
    rtsiSetRTModelPtr(&identyfikacja1zbior_M->solverInfo, identyfikacja1zbior_M);
  }

  rtsiSetSimTimeStep(&identyfikacja1zbior_M->solverInfo, MAJOR_TIME_STEP);
  identyfikacja1zbior_M->ModelData.intgData.y =
    identyfikacja1zbior_M->ModelData.odeY;
  identyfikacja1zbior_M->ModelData.intgData.f[0] =
    identyfikacja1zbior_M->ModelData.odeF[0];
  identyfikacja1zbior_M->ModelData.intgData.f[1] =
    identyfikacja1zbior_M->ModelData.odeF[1];
  identyfikacja1zbior_M->ModelData.intgData.f[2] =
    identyfikacja1zbior_M->ModelData.odeF[2];
  identyfikacja1zbior_M->ModelData.intgData.f[3] =
    identyfikacja1zbior_M->ModelData.odeF[3];
  identyfikacja1zbior_M->ModelData.intgData.f[4] =
    identyfikacja1zbior_M->ModelData.odeF[4];
  identyfikacja1zbior_M->ModelData.intgData.f[5] =
    identyfikacja1zbior_M->ModelData.odeF[5];
  identyfikacja1zbior_M->ModelData.contStates = ((real_T *)
    &identyfikacja1zbior_X);
  rtsiSetSolverData(&identyfikacja1zbior_M->solverInfo, (void *)
                    &identyfikacja1zbior_M->ModelData.intgData);
  rtsiSetSolverName(&identyfikacja1zbior_M->solverInfo,"ode5");
  identyfikacja1zbior_M->solverInfoPtr = (&identyfikacja1zbior_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = identyfikacja1zbior_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    identyfikacja1zbior_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    identyfikacja1zbior_M->Timing.sampleTimes =
      (&identyfikacja1zbior_M->Timing.sampleTimesArray[0]);
    identyfikacja1zbior_M->Timing.offsetTimes =
      (&identyfikacja1zbior_M->Timing.offsetTimesArray[0]);

    /* task periods */
    identyfikacja1zbior_M->Timing.sampleTimes[0] = (0.0);
    identyfikacja1zbior_M->Timing.sampleTimes[1] = (0.01);
    identyfikacja1zbior_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    identyfikacja1zbior_M->Timing.offsetTimes[0] = (0.0);
    identyfikacja1zbior_M->Timing.offsetTimes[1] = (0.0);
    identyfikacja1zbior_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(identyfikacja1zbior_M, &identyfikacja1zbior_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = identyfikacja1zbior_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    identyfikacja1zbior_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(identyfikacja1zbior_M, 999.0);
  identyfikacja1zbior_M->Timing.stepSize0 = 0.01;
  identyfikacja1zbior_M->Timing.stepSize1 = 0.01;
  identyfikacja1zbior_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  identyfikacja1zbior_M->Sizes.checksums[0] = (312861672U);
  identyfikacja1zbior_M->Sizes.checksums[1] = (3819598170U);
  identyfikacja1zbior_M->Sizes.checksums[2] = (578613060U);
  identyfikacja1zbior_M->Sizes.checksums[3] = (3411473503U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    identyfikacja1zbior_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(identyfikacja1zbior_M->extModeInfo,
      &identyfikacja1zbior_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(identyfikacja1zbior_M->extModeInfo,
                        identyfikacja1zbior_M->Sizes.checksums);
    rteiSetTPtr(identyfikacja1zbior_M->extModeInfo, rtmGetTPtr
                (identyfikacja1zbior_M));
  }

  identyfikacja1zbior_M->solverInfoPtr = (&identyfikacja1zbior_M->solverInfo);
  identyfikacja1zbior_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&identyfikacja1zbior_M->solverInfo, 0.01);
  rtsiSetSolverMode(&identyfikacja1zbior_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  identyfikacja1zbior_M->ModelData.blockIO = ((void *) &identyfikacja1zbior_B);

  {
    identyfikacja1zbior_B.RTDACAnalogInputs[0] = 0.0;
    identyfikacja1zbior_B.RTDACAnalogInputs[1] = 0.0;
    identyfikacja1zbior_B.RTDACAnalogInputs[2] = 0.0;
    identyfikacja1zbior_B.Gain = 0.0;
    identyfikacja1zbior_B.Gain1 = 0.0;
    identyfikacja1zbior_B.Gain2 = 0.0;
    identyfikacja1zbior_B.TransferFcn = 0.0;
    identyfikacja1zbior_B.TransferFcn1 = 0.0;
    identyfikacja1zbior_B.TransferFcn2 = 0.0;
    identyfikacja1zbior_B.SliderGain = 0.0;
    identyfikacja1zbior_B.SliderGain_a = 0.0;
    identyfikacja1zbior_B.SliderGain_ap = 0.0;
    identyfikacja1zbior_B.SliderGain_ay = 0.0;
  }

  /* parameters */
  identyfikacja1zbior_M->ModelData.defaultParam = ((real_T *)
    &identyfikacja1zbior_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &identyfikacja1zbior_X;
    identyfikacja1zbior_M->ModelData.contStates = (x);
    (void) memset((void *)&identyfikacja1zbior_X, 0,
                  sizeof(X_identyfikacja1zbior_T));
  }

  /* states (dwork) */
  identyfikacja1zbior_M->ModelData.dwork = ((void *) &identyfikacja1zbior_DW);
  (void) memset((void *)&identyfikacja1zbior_DW, 0,
                sizeof(DW_identyfikacja1zbior_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    identyfikacja1zbior_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &identyfikacja1zbior_M->NonInlinedSFcns.sfcnInfo;
    identyfikacja1zbior_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(identyfikacja1zbior_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &identyfikacja1zbior_M->Sizes.numSampTimes);
    identyfikacja1zbior_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (identyfikacja1zbior_M)[0]);
    identyfikacja1zbior_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (identyfikacja1zbior_M)[1]);
    identyfikacja1zbior_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (identyfikacja1zbior_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,identyfikacja1zbior_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(identyfikacja1zbior_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(identyfikacja1zbior_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (identyfikacja1zbior_M));
    rtssSetStepSizePtr(sfcnInfo, &identyfikacja1zbior_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(identyfikacja1zbior_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &identyfikacja1zbior_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &identyfikacja1zbior_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &identyfikacja1zbior_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &identyfikacja1zbior_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &identyfikacja1zbior_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &identyfikacja1zbior_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &identyfikacja1zbior_M->solverInfoPtr);
  }

  identyfikacja1zbior_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)
                  &identyfikacja1zbior_M->NonInlinedSFcns.childSFunctions[0], 0,
                  5*sizeof(SimStruct));
    identyfikacja1zbior_M->childSfunctions =
      (&identyfikacja1zbior_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        identyfikacja1zbior_M->childSfunctions[i] =
          (&identyfikacja1zbior_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: identyfikacja1zbior/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = identyfikacja1zbior_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &identyfikacja1zbior_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, identyfikacja1zbior_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &identyfikacja1zbior_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            identyfikacja1zbior_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "identyfikacja1zbior/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,identyfikacja1zbior_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       identyfikacja1zbior_P.RTDACAnalogInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       identyfikacja1zbior_P.RTDACAnalogInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       identyfikacja1zbior_P.RTDACAnalogInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       identyfikacja1zbior_P.RTDACAnalogInputs_P4_Size);
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

    /* Level2 S-Function Block: identyfikacja1zbior/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &identyfikacja1zbior_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, identyfikacja1zbior_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &identyfikacja1zbior_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &identyfikacja1zbior_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "identyfikacja1zbior/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,identyfikacja1zbior_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)identyfikacja1zbior_P.pooled1);
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

    /* Level2 S-Function Block: identyfikacja1zbior/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &identyfikacja1zbior_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, identyfikacja1zbior_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &identyfikacja1zbior_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &identyfikacja1zbior_B.SliderGain_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "identyfikacja1zbior/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,identyfikacja1zbior_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P5_Size_h);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)identyfikacja1zbior_P.pooled1);
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

    /* Level2 S-Function Block: identyfikacja1zbior/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &identyfikacja1zbior_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, identyfikacja1zbior_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &identyfikacja1zbior_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &identyfikacja1zbior_B.SliderGain_ap;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "identyfikacja1zbior/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,identyfikacja1zbior_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P6_Size_l);
        ssSetSFcnParam(rts, 6, (mxArray*)identyfikacja1zbior_P.pooled1);
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

    /* Level2 S-Function Block: identyfikacja1zbior/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = identyfikacja1zbior_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &identyfikacja1zbior_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, identyfikacja1zbior_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &identyfikacja1zbior_M->
                           NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &identyfikacja1zbior_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &identyfikacja1zbior_B.SliderGain_ay;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "identyfikacja1zbior/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,identyfikacja1zbior_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &identyfikacja1zbior_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       identyfikacja1zbior_P.RTDACPCIPWM_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)identyfikacja1zbior_P.pooled1);
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
  identyfikacja1zbior_M->Sizes.numContStates = (3);/* Number of continuous states */
  identyfikacja1zbior_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  identyfikacja1zbior_M->Sizes.numY = (0);/* Number of model outputs */
  identyfikacja1zbior_M->Sizes.numU = (0);/* Number of model inputs */
  identyfikacja1zbior_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  identyfikacja1zbior_M->Sizes.numSampTimes = (3);/* Number of sample times */
  identyfikacja1zbior_M->Sizes.numBlocks = (29);/* Number of blocks */
  identyfikacja1zbior_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  identyfikacja1zbior_M->Sizes.numBlockPrms = (111);/* Sum of parameter "widths" */
  return identyfikacja1zbior_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
