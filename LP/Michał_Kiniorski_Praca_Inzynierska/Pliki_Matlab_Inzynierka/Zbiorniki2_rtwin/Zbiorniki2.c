/*
 * Zbiorniki2.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki2.mdl".
 *
 * Model Version              : 1.134
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Nov 11 14:54:15 2015
 */

#include "Zbiorniki2.h"
#include "Zbiorniki2_private.h"
#include <stdio.h>
#include "Zbiorniki2_dt.h"

/* Block signals (auto storage) */
BlockIO_Zbiorniki2 Zbiorniki2_B;

/* Block states (auto storage) */
D_Work_Zbiorniki2 Zbiorniki2_DWork;

/* Real-time model */
RT_MODEL_Zbiorniki2 Zbiorniki2_M_;
RT_MODEL_Zbiorniki2 *Zbiorniki2_M = &Zbiorniki2_M_;
static void rate_scheduler(void);

/*
 * This function updates active task flag for each subrate.
 * The function must be is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++Zbiorniki2_M->Timing.TaskCounters.TID[1] == 5) {/* Sample time: [0.05s, 0.0s] */
    Zbiorniki2_M->Timing.TaskCounters.TID[1] = 0;
  }

  Zbiorniki2_M->Timing.sampleHits[1] = (Zbiorniki2_M->Timing.TaskCounters.TID[1]
    == 0);
}

/* Model output function */
void Zbiorniki2_output(int_T tid)
{
  if (Zbiorniki2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain'
     */
    Zbiorniki2_B.Sum = Zbiorniki2_P.Gain_Gain * Zbiorniki2_B.RTDACAnalogInputs[0]
      + Zbiorniki2_P.Constant_Value;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Gain: '<Root>/Gain1'
     */
    Zbiorniki2_B.Sum1 = Zbiorniki2_P.Gain1_Gain *
      Zbiorniki2_B.RTDACAnalogInputs[1] - Zbiorniki2_P.Constant5_Value;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Gain: '<Root>/Gain2'
     */
    Zbiorniki2_B.Sum2 = Zbiorniki2_P.Gain2_Gain *
      Zbiorniki2_B.RTDACAnalogInputs[2] + Zbiorniki2_P.Constant6_Value;
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Zbiorniki2_B.SliderGain = Zbiorniki2_P.SliderGain_Gain *
    Zbiorniki2_P.Constant4_Value;

  /* Gain: '<S4>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  Zbiorniki2_B.SliderGain_g = Zbiorniki2_P.SliderGain_Gain_k *
    Zbiorniki2_P.Constant3_Value;

  /* Gain: '<S5>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Zbiorniki2_B.SliderGain_c = Zbiorniki2_P.SliderGain_Gain_c *
    Zbiorniki2_P.Constant1_Value;

  /* Gain: '<S6>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Zbiorniki2_B.SliderGain_o = Zbiorniki2_P.SliderGain_Gain_o *
    Zbiorniki2_P.Constant2_Value;
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Zbiorniki2_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Zbiorniki2_M->Timing.clockTick0))
    ++Zbiorniki2_M->Timing.clockTickH0;
  Zbiorniki2_M->Timing.t[0] = Zbiorniki2_M->Timing.clockTick0 *
    Zbiorniki2_M->Timing.stepSize0 + Zbiorniki2_M->Timing.clockTickH0 *
    Zbiorniki2_M->Timing.stepSize0 * 4294967296.0;
  if (Zbiorniki2_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    if (!(++Zbiorniki2_M->Timing.clockTick1))
      ++Zbiorniki2_M->Timing.clockTickH1;
    Zbiorniki2_M->Timing.t[1] = Zbiorniki2_M->Timing.clockTick1 *
      Zbiorniki2_M->Timing.stepSize1 + Zbiorniki2_M->Timing.clockTickH1 *
      Zbiorniki2_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Zbiorniki2_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((char_T *)Zbiorniki2_M,0,
                sizeof(RT_MODEL_Zbiorniki2));
  rtsiSetSolverName(&Zbiorniki2_M->solverInfo,"FixedStepDiscrete");
  Zbiorniki2_M->solverInfoPtr = (&Zbiorniki2_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Zbiorniki2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Zbiorniki2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Zbiorniki2_M->Timing.sampleTimes = (&Zbiorniki2_M->Timing.sampleTimesArray[0]);
    Zbiorniki2_M->Timing.offsetTimes = (&Zbiorniki2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Zbiorniki2_M->Timing.sampleTimes[0] = (0.01);
    Zbiorniki2_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    Zbiorniki2_M->Timing.offsetTimes[0] = (0.0);
    Zbiorniki2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Zbiorniki2_M, &Zbiorniki2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Zbiorniki2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Zbiorniki2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Zbiorniki2_M, 999.0);
  Zbiorniki2_M->Timing.stepSize0 = 0.01;
  Zbiorniki2_M->Timing.stepSize1 = 0.05;

  /* external mode info */
  Zbiorniki2_M->Sizes.checksums[0] = (908698808U);
  Zbiorniki2_M->Sizes.checksums[1] = (885104627U);
  Zbiorniki2_M->Sizes.checksums[2] = (1171431480U);
  Zbiorniki2_M->Sizes.checksums[3] = (2665281104U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Zbiorniki2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Zbiorniki2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Zbiorniki2_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Zbiorniki2_M));
  }

  Zbiorniki2_M->solverInfoPtr = (&Zbiorniki2_M->solverInfo);
  Zbiorniki2_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Zbiorniki2_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Zbiorniki2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Zbiorniki2_M->ModelData.blockIO = ((void *) &Zbiorniki2_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Zbiorniki2_B.RTDACAnalogInputs[0]);
    for (i = 0; i < 10; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Zbiorniki2_M->ModelData.defaultParam = ((real_T *) &Zbiorniki2_P);

  /* states (dwork) */
  Zbiorniki2_M->Work.dwork = ((void *) &Zbiorniki2_DWork);
  (void) memset((char_T *) &Zbiorniki2_DWork,0,
                sizeof(D_Work_Zbiorniki2));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Zbiorniki2_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Zbiorniki2_M->NonInlinedSFcns.sfcnInfo;
    Zbiorniki2_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Zbiorniki2_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Zbiorniki2_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(Zbiorniki2_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Zbiorniki2_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Zbiorniki2_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Zbiorniki2_M));
    rtssSetStepSizePtr(sfcnInfo, &Zbiorniki2_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Zbiorniki2_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki2_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki2_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Zbiorniki2_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Zbiorniki2_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Zbiorniki2_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Zbiorniki2_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Zbiorniki2_M->solverInfoPtr);
  }

  Zbiorniki2_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&Zbiorniki2_M->NonInlinedSFcns.childSFunctions[0],0,
                  5*sizeof(SimStruct));
    Zbiorniki2_M->childSfunctions =
      (&Zbiorniki2_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Zbiorniki2_M->childSfunctions[i] =
          (&Zbiorniki2_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Zbiorniki2/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki2_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki2_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki2_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki2_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, Zbiorniki2_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki2_M->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Zbiorniki2_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "Zbiorniki2/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,Zbiorniki2_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &Zbiorniki2_P.RTDACAnalogInputs_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &Zbiorniki2_P.RTDACAnalogInputs_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &Zbiorniki2_P.RTDACAnalogInputs_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &Zbiorniki2_P.RTDACAnalogInputs_P4_Size[0]);
      }

      /* registration */
      rtdacpci_analoginputs(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Zbiorniki2/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki2_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki2_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki2_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki2_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, Zbiorniki2_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki2_M->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki2_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki2_B.SliderGain_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki2/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki2_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P7_Size[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki2/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki2_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki2_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki2_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki2_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, Zbiorniki2_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki2_M->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki2_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki2_B.SliderGain_o;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "Zbiorniki2/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki2_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P1_Size_l[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P2_Size_o[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P3_Size_k[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P4_Size_n[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P5_Size_p[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P6_Size_a[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P7_Size_l[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki2/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki2_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki2_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki2_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki2_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, Zbiorniki2_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki2_M->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki2_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki2_B.SliderGain_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki2/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki2_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P1_Size_b[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P2_Size_h[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P3_Size_l[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P4_Size_e[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P5_Size_h[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P6_Size_d[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P7_Size_ly[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki2/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki2_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki2_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki2_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki2_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki2_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, Zbiorniki2_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki2_M->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki2_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki2_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki2/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki2_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki2_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P1_Size_p[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P2_Size_d[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P3_Size_c[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P4_Size_o[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P5_Size_g[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P6_Size_m[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki2_P.RTDACPCIPWM_P7_Size_a[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }
}

/* Model terminate function */
void Zbiorniki2_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki2_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Zbiorniki2_output(tid);
}

void MdlUpdate(int_T tid)
{
  Zbiorniki2_update(tid);
}

void MdlInitializeSizes(void)
{
  Zbiorniki2_M->Sizes.numContStates = (0);/* Number of continuous states */
  Zbiorniki2_M->Sizes.numY = (0);      /* Number of model outputs */
  Zbiorniki2_M->Sizes.numU = (0);      /* Number of model inputs */
  Zbiorniki2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Zbiorniki2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Zbiorniki2_M->Sizes.numBlocks = (27);/* Number of blocks */
  Zbiorniki2_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  Zbiorniki2_M->Sizes.numBlockPrms = (114);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  MdlInitialize();
}

RT_MODEL_Zbiorniki2 *Zbiorniki2(void)
{
  Zbiorniki2_initialize(1);
  return Zbiorniki2_M;
}

void MdlTerminate(void)
{
  Zbiorniki2_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
