/*
 * Pid.c
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

#include "Pid.h"
#include "Pid_private.h"
#include "Pid_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Pid_T Pid_B;

/* Continuous states */
X_Pid_T Pid_X;

/* Block states (auto storage) */
DW_Pid_T Pid_DW;

/* Real-time model */
RT_MODEL_Pid_T Pid_M_;
RT_MODEL_Pid_T *const Pid_M = &Pid_M_;
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
  (Pid_M->Timing.TaskCounters.TID[2])++;
  if ((Pid_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.05s, 0.0s] */
    Pid_M->Timing.TaskCounters.TID[2] = 0;
  }

  Pid_M->Timing.sampleHits[2] = (Pid_M->Timing.TaskCounters.TID[2] == 0);
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
  Pid_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Pid_output();
  Pid_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Pid_output();
  Pid_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Pid_output();
  Pid_derivatives();

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
  Pid_output();
  Pid_derivatives();

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
  Pid_output();
  Pid_derivatives();

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
void Pid_output(void)
{
  real_T rtb_Sum3;
  real_T u0;
  if (rtmIsMajorTimeStep(Pid_M)) {
    /* set solver stop time */
    if (!(Pid_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Pid_M->solverInfo, ((Pid_M->Timing.clockTickH0 + 1)
        * Pid_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Pid_M->solverInfo, ((Pid_M->Timing.clockTick0 + 1) *
        Pid_M->Timing.stepSize0 + Pid_M->Timing.clockTickH0 *
        Pid_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Pid_M)) {
    Pid_M->Timing.t[0] = rtsiGetT(&Pid_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[2] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Pid_M->childSfunctions[0];
      sfcnOutputs(rts, 2);
    }
  }

  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    Pid_B.Gain = (Pid_B.RTDACAnalogInputs[0] - Pid_P.Constant_Value) *
      Pid_P.Gain_Gain;

    /* Gain: '<Root>/Gain1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Sum: '<Root>/Sum1'
     */
    Pid_B.Gain1 = (Pid_B.RTDACAnalogInputs[1] - Pid_P.Constant5_Value) *
      Pid_P.Gain1_Gain;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum2'
     */
    Pid_B.Gain2 = (Pid_B.RTDACAnalogInputs[2] - Pid_P.Constant6_Value) *
      Pid_P.Gain2_Gain;

    /* Gain: '<S5>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Pid_B.SliderGain = Pid_P.ZaworGORA_gain * Pid_P.Constant1_Value;

    /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S6>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Pid_B.SliderGain_a = Pid_P.ZaworSRODEK_gain * Pid_P.Constant2_Value;

    /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Pid_B.SliderGain_ap = Pid_P.ZaworDOL_gain * Pid_P.Constant3_Value;

    /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  Pid_B.TransferFcn2 = 0.0;
  Pid_B.TransferFcn2 += Pid_P.TransferFcn2_C * Pid_X.TransferFcn2_CSTATE;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  rtb_Sum3 = Pid_P.Constant4_Value - Pid_B.TransferFcn2;

  /* Gain: '<S1>/Filter Coefficient' incorporates:
   *  Gain: '<S1>/Derivative Gain'
   *  Integrator: '<S1>/Filter'
   *  Sum: '<S1>/SumD'
   */
  Pid_B.FilterCoefficient = (Pid_P.PIDController_D * rtb_Sum3 -
    Pid_X.Filter_CSTATE) * Pid_P.PIDController_N;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Proportional Gain'
   *  Integrator: '<S1>/Integrator'
   */
  u0 = (Pid_P.PIDController_P * rtb_Sum3 + Pid_X.Integrator_CSTATE) +
    Pid_B.FilterCoefficient;

  /* Saturate: '<S1>/Saturate' */
  if (u0 > Pid_P.PIDController_UpperSaturationLi) {
    u0 = Pid_P.PIDController_UpperSaturationLi;
  } else {
    if (u0 < Pid_P.PIDController_LowerSaturationLi) {
      u0 = Pid_P.PIDController_LowerSaturationLi;
    }
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Saturate: '<S1>/Saturate'
   */
  Pid_B.Gain3 = Pid_P.Gain3_Gain * u0;
  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Pid_B.TransferFcn = 0.0;
  Pid_B.TransferFcn += Pid_P.TransferFcn_C * Pid_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Pid_B.TransferFcn1 = 0.0;
  Pid_B.TransferFcn1 += Pid_P.TransferFcn1_C * Pid_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S1>/Integral Gain' */
  Pid_B.IntegralGain = Pid_P.PIDController_I * rtb_Sum3;
  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[1] == 0) {
  }
}

/* Model update function */
void Pid_update(void)
{
  if (rtmIsMajorTimeStep(Pid_M)) {
    rt_ertODEUpdateContinuousStates(&Pid_M->solverInfo);
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
  if (!(++Pid_M->Timing.clockTick0)) {
    ++Pid_M->Timing.clockTickH0;
  }

  Pid_M->Timing.t[0] = rtsiGetSolverStopTime(&Pid_M->solverInfo);

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
    if (!(++Pid_M->Timing.clockTick1)) {
      ++Pid_M->Timing.clockTickH1;
    }

    Pid_M->Timing.t[1] = Pid_M->Timing.clockTick1 * Pid_M->Timing.stepSize1 +
      Pid_M->Timing.clockTickH1 * Pid_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Pid_M) &&
      Pid_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Pid_M->Timing.clockTick2)) {
      ++Pid_M->Timing.clockTickH2;
    }

    Pid_M->Timing.t[2] = Pid_M->Timing.clockTick2 * Pid_M->Timing.stepSize2 +
      Pid_M->Timing.clockTickH2 * Pid_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Pid_derivatives(void)
{
  XDot_Pid_T *_rtXdot;
  _rtXdot = ((XDot_Pid_T *) Pid_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += Pid_P.TransferFcn2_A *
    Pid_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += Pid_B.Gain2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Pid_B.IntegralGain;

  /* Derivatives for Integrator: '<S1>/Filter' */
  _rtXdot->Filter_CSTATE = Pid_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Pid_P.TransferFcn_A * Pid_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Pid_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += Pid_P.TransferFcn1_A *
    Pid_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Pid_B.Gain1;
}

/* Model initialize function */
void Pid_initialize(void)
{
  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  Pid_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Pid_X.Integrator_CSTATE = Pid_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Filter' */
  Pid_X.Filter_CSTATE = Pid_P.Filter_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Pid_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Pid_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void Pid_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Pid_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pid_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pid_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pid_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Pid_M->childSfunctions[4];
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
  Pid_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pid_update();
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
  Pid_initialize();
}

void MdlTerminate(void)
{
  Pid_terminate();
}

/* Registration function */
RT_MODEL_Pid_T *Pid(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Pid_M, 0,
                sizeof(RT_MODEL_Pid_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pid_M->solverInfo, &Pid_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pid_M->solverInfo, &rtmGetTPtr(Pid_M));
    rtsiSetStepSizePtr(&Pid_M->solverInfo, &Pid_M->Timing.stepSize0);
    rtsiSetdXPtr(&Pid_M->solverInfo, &Pid_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Pid_M->solverInfo, (real_T **)
                         &Pid_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Pid_M->solverInfo, &Pid_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Pid_M->solverInfo, (&rtmGetErrorStatus(Pid_M)));
    rtsiSetRTModelPtr(&Pid_M->solverInfo, Pid_M);
  }

  rtsiSetSimTimeStep(&Pid_M->solverInfo, MAJOR_TIME_STEP);
  Pid_M->ModelData.intgData.y = Pid_M->ModelData.odeY;
  Pid_M->ModelData.intgData.f[0] = Pid_M->ModelData.odeF[0];
  Pid_M->ModelData.intgData.f[1] = Pid_M->ModelData.odeF[1];
  Pid_M->ModelData.intgData.f[2] = Pid_M->ModelData.odeF[2];
  Pid_M->ModelData.intgData.f[3] = Pid_M->ModelData.odeF[3];
  Pid_M->ModelData.intgData.f[4] = Pid_M->ModelData.odeF[4];
  Pid_M->ModelData.intgData.f[5] = Pid_M->ModelData.odeF[5];
  Pid_M->ModelData.contStates = ((real_T *) &Pid_X);
  rtsiSetSolverData(&Pid_M->solverInfo, (void *)&Pid_M->ModelData.intgData);
  rtsiSetSolverName(&Pid_M->solverInfo,"ode5");
  Pid_M->solverInfoPtr = (&Pid_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pid_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Pid_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pid_M->Timing.sampleTimes = (&Pid_M->Timing.sampleTimesArray[0]);
    Pid_M->Timing.offsetTimes = (&Pid_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pid_M->Timing.sampleTimes[0] = (0.0);
    Pid_M->Timing.sampleTimes[1] = (0.01);
    Pid_M->Timing.sampleTimes[2] = (0.05);

    /* task offsets */
    Pid_M->Timing.offsetTimes[0] = (0.0);
    Pid_M->Timing.offsetTimes[1] = (0.0);
    Pid_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Pid_M, &Pid_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pid_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Pid_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pid_M, 999.0);
  Pid_M->Timing.stepSize0 = 0.01;
  Pid_M->Timing.stepSize1 = 0.01;
  Pid_M->Timing.stepSize2 = 0.05;

  /* External mode info */
  Pid_M->Sizes.checksums[0] = (3344005174U);
  Pid_M->Sizes.checksums[1] = (1923773845U);
  Pid_M->Sizes.checksums[2] = (4120447284U);
  Pid_M->Sizes.checksums[3] = (1532527456U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Pid_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Pid_M->extModeInfo,
      &Pid_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Pid_M->extModeInfo, Pid_M->Sizes.checksums);
    rteiSetTPtr(Pid_M->extModeInfo, rtmGetTPtr(Pid_M));
  }

  Pid_M->solverInfoPtr = (&Pid_M->solverInfo);
  Pid_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Pid_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Pid_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Pid_M->ModelData.blockIO = ((void *) &Pid_B);

  {
    Pid_B.RTDACAnalogInputs[0] = 0.0;
    Pid_B.RTDACAnalogInputs[1] = 0.0;
    Pid_B.RTDACAnalogInputs[2] = 0.0;
    Pid_B.Gain = 0.0;
    Pid_B.Gain1 = 0.0;
    Pid_B.Gain2 = 0.0;
    Pid_B.SliderGain = 0.0;
    Pid_B.SliderGain_a = 0.0;
    Pid_B.SliderGain_ap = 0.0;
    Pid_B.TransferFcn2 = 0.0;
    Pid_B.FilterCoefficient = 0.0;
    Pid_B.Gain3 = 0.0;
    Pid_B.TransferFcn = 0.0;
    Pid_B.TransferFcn1 = 0.0;
    Pid_B.IntegralGain = 0.0;
  }

  /* parameters */
  Pid_M->ModelData.defaultParam = ((real_T *)&Pid_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Pid_X;
    Pid_M->ModelData.contStates = (x);
    (void) memset((void *)&Pid_X, 0,
                  sizeof(X_Pid_T));
  }

  /* states (dwork) */
  Pid_M->ModelData.dwork = ((void *) &Pid_DW);
  (void) memset((void *)&Pid_DW, 0,
                sizeof(DW_Pid_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Pid_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Pid_M->NonInlinedSFcns.sfcnInfo;
    Pid_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Pid_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Pid_M->Sizes.numSampTimes);
    Pid_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Pid_M)[0]);
    Pid_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Pid_M)[1]);
    Pid_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(Pid_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,Pid_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Pid_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Pid_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Pid_M));
    rtssSetStepSizePtr(sfcnInfo, &Pid_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Pid_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Pid_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Pid_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Pid_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Pid_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Pid_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Pid_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Pid_M->solverInfoPtr);
  }

  Pid_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&Pid_M->NonInlinedSFcns.childSFunctions[0], 0,
                  5*sizeof(SimStruct));
    Pid_M->childSfunctions = (&Pid_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Pid_M->childSfunctions[i] = (&Pid_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Pid/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Pid_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Pid_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Pid_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Pid_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pid_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Pid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pid_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pid_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pid_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Pid_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Pid_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "Pid/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,Pid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &Pid_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pid_P.RTDACAnalogInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Pid_P.RTDACAnalogInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Pid_P.RTDACAnalogInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Pid_P.RTDACAnalogInputs_P4_Size);
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

    /* Level2 S-Function Block: Pid/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Pid_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Pid_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Pid_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pid_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Pid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pid_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pid_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pid_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &Pid_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pid_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Pid_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Pid/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &Pid_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pid_P.RTDACPCIPWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Pid_P.RTDACPCIPWM_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Pid_P.RTDACPCIPWM_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Pid_P.RTDACPCIPWM_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Pid_P.RTDACPCIPWM_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Pid_P.RTDACPCIPWM_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Pid_P.pooled1);
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

    /* Level2 S-Function Block: Pid/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Pid_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Pid_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Pid_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pid_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Pid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pid_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pid_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pid_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &Pid_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pid_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Pid_B.SliderGain_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Pid/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &Pid_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pid_P.RTDACPCIPWM_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)Pid_P.RTDACPCIPWM_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)Pid_P.RTDACPCIPWM_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)Pid_P.RTDACPCIPWM_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)Pid_P.RTDACPCIPWM_P5_Size_h);
        ssSetSFcnParam(rts, 5, (mxArray*)Pid_P.RTDACPCIPWM_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)Pid_P.pooled1);
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

    /* Level2 S-Function Block: Pid/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Pid_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Pid_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Pid_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pid_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Pid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pid_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pid_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pid_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &Pid_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pid_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Pid_B.SliderGain_ap;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Pid/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &Pid_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pid_P.RTDACPCIPWM_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)Pid_P.RTDACPCIPWM_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)Pid_P.RTDACPCIPWM_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)Pid_P.RTDACPCIPWM_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)Pid_P.RTDACPCIPWM_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)Pid_P.RTDACPCIPWM_P6_Size_l);
        ssSetSFcnParam(rts, 6, (mxArray*)Pid_P.pooled1);
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

    /* Level2 S-Function Block: Pid/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Pid_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Pid_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Pid_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Pid_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pid_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Pid_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pid_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pid_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pid_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &Pid_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pid_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Pid_B.Gain3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Pid/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Pid_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &Pid_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pid_P.RTDACPCIPWM_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)Pid_P.RTDACPCIPWM_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)Pid_P.RTDACPCIPWM_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)Pid_P.RTDACPCIPWM_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)Pid_P.RTDACPCIPWM_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)Pid_P.RTDACPCIPWM_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)Pid_P.pooled1);
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
  Pid_M->Sizes.numContStates = (5);    /* Number of continuous states */
  Pid_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Pid_M->Sizes.numY = (0);             /* Number of model outputs */
  Pid_M->Sizes.numU = (0);             /* Number of model inputs */
  Pid_M->Sizes.sysDirFeedThru = (0);   /* The model is not direct feedthrough */
  Pid_M->Sizes.numSampTimes = (3);     /* Number of sample times */
  Pid_M->Sizes.numBlocks = (39);       /* Number of blocks */
  Pid_M->Sizes.numBlockIO = (13);      /* Number of block outputs */
  Pid_M->Sizes.numBlockPrms = (119);   /* Sum of parameter "widths" */
  return Pid_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
