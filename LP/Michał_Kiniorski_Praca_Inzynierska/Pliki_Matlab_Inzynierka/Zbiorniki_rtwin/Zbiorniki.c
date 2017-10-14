/*
 * Zbiorniki.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki.mdl".
 *
 * Model Version              : 1.125
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Nov 11 14:02:42 2015
 */

#include "Zbiorniki.h"
#include "Zbiorniki_private.h"
#include <stdio.h>
#include "Zbiorniki_dt.h"

/* Block signals (auto storage) */
BlockIO_Zbiorniki Zbiorniki_B;

/* Block states (auto storage) */
D_Work_Zbiorniki Zbiorniki_DWork;

/* Real-time model */
RT_MODEL_Zbiorniki Zbiorniki_M_;
RT_MODEL_Zbiorniki *Zbiorniki_M = &Zbiorniki_M_;
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
  if (++Zbiorniki_M->Timing.TaskCounters.TID[1] == 5) {/* Sample time: [0.05s, 0.0s] */
    Zbiorniki_M->Timing.TaskCounters.TID[1] = 0;
  }

  Zbiorniki_M->Timing.sampleHits[1] = (Zbiorniki_M->Timing.TaskCounters.TID[1] ==
    0);
}

/* Model output function */
void Zbiorniki_output(int_T tid)
{
  if (Zbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain'
     */
    Zbiorniki_B.Sum = Zbiorniki_P.Gain_Gain * Zbiorniki_B.RTDACAnalogInputs[0] +
      Zbiorniki_P.Constant_Value;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Gain: '<Root>/Gain1'
     */
    Zbiorniki_B.Sum1 = Zbiorniki_P.Gain1_Gain * Zbiorniki_B.RTDACAnalogInputs[1]
      - Zbiorniki_P.Constant5_Value;

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Gain: '<Root>/Gain2'
     */
    Zbiorniki_B.Sum2 = Zbiorniki_P.Gain2_Gain * Zbiorniki_B.RTDACAnalogInputs[2]
      - Zbiorniki_P.Constant6_Value;
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Zbiorniki_B.SliderGain = Zbiorniki_P.SliderGain_Gain *
    Zbiorniki_P.Constant4_Value;

  /* Gain: '<S4>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  Zbiorniki_B.SliderGain_n = Zbiorniki_P.SliderGain_Gain_k *
    Zbiorniki_P.Constant3_Value;

  /* Gain: '<S5>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Zbiorniki_B.SliderGain_k = Zbiorniki_P.SliderGain_Gain_p *
    Zbiorniki_P.Constant1_Value;

  /* Gain: '<S6>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Zbiorniki_B.SliderGain_g = Zbiorniki_P.SliderGain_Gain_f *
    Zbiorniki_P.Constant2_Value;
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Zbiorniki_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Zbiorniki_M->Timing.clockTick0))
    ++Zbiorniki_M->Timing.clockTickH0;
  Zbiorniki_M->Timing.t[0] = Zbiorniki_M->Timing.clockTick0 *
    Zbiorniki_M->Timing.stepSize0 + Zbiorniki_M->Timing.clockTickH0 *
    Zbiorniki_M->Timing.stepSize0 * 4294967296.0;
  if (Zbiorniki_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    if (!(++Zbiorniki_M->Timing.clockTick1))
      ++Zbiorniki_M->Timing.clockTickH1;
    Zbiorniki_M->Timing.t[1] = Zbiorniki_M->Timing.clockTick1 *
      Zbiorniki_M->Timing.stepSize1 + Zbiorniki_M->Timing.clockTickH1 *
      Zbiorniki_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Zbiorniki_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((char_T *)Zbiorniki_M,0,
                sizeof(RT_MODEL_Zbiorniki));
  rtsiSetSolverName(&Zbiorniki_M->solverInfo,"FixedStepDiscrete");
  Zbiorniki_M->solverInfoPtr = (&Zbiorniki_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Zbiorniki_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Zbiorniki_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Zbiorniki_M->Timing.sampleTimes = (&Zbiorniki_M->Timing.sampleTimesArray[0]);
    Zbiorniki_M->Timing.offsetTimes = (&Zbiorniki_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Zbiorniki_M->Timing.sampleTimes[0] = (0.01);
    Zbiorniki_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    Zbiorniki_M->Timing.offsetTimes[0] = (0.0);
    Zbiorniki_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Zbiorniki_M, &Zbiorniki_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Zbiorniki_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Zbiorniki_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Zbiorniki_M, 999.0);
  Zbiorniki_M->Timing.stepSize0 = 0.01;
  Zbiorniki_M->Timing.stepSize1 = 0.05;

  /* external mode info */
  Zbiorniki_M->Sizes.checksums[0] = (1638376822U);
  Zbiorniki_M->Sizes.checksums[1] = (518889857U);
  Zbiorniki_M->Sizes.checksums[2] = (4125492789U);
  Zbiorniki_M->Sizes.checksums[3] = (915015207U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Zbiorniki_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Zbiorniki_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Zbiorniki_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Zbiorniki_M));
  }

  Zbiorniki_M->solverInfoPtr = (&Zbiorniki_M->solverInfo);
  Zbiorniki_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Zbiorniki_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Zbiorniki_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Zbiorniki_M->ModelData.blockIO = ((void *) &Zbiorniki_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Zbiorniki_B.RTDACAnalogInputs[0]);
    for (i = 0; i < 10; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Zbiorniki_M->ModelData.defaultParam = ((real_T *) &Zbiorniki_P);

  /* states (dwork) */
  Zbiorniki_M->Work.dwork = ((void *) &Zbiorniki_DWork);
  (void) memset((char_T *) &Zbiorniki_DWork,0,
                sizeof(D_Work_Zbiorniki));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
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
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(Zbiorniki_M));
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
    (void) memset((void *)&Zbiorniki_M->NonInlinedSFcns.childSFunctions[0],0,
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
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[0]);
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
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki_P.RTDACAnalogInputs_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki_P.RTDACAnalogInputs_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki_P.RTDACAnalogInputs_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki_P.RTDACAnalogInputs_P4_Size
                       [0]);
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

    /* Level2 S-Function Block: Zbiorniki/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[1]);
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
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain_k;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P7_Size[0]);
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

    /* Level2 S-Function Block: Zbiorniki/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[2]);
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
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P1_Size_l[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P2_Size_h[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P3_Size_a[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P4_Size_g[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P5_Size_l[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P6_Size_l[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P7_Size_g[0]);
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

    /* Level2 S-Function Block: Zbiorniki/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[3]);
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
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P1_Size_g[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P2_Size_p[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P3_Size_h[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P4_Size_i[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P5_Size_b[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P6_Size_g[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P7_Size_d[0]);
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

    /* Level2 S-Function Block: Zbiorniki/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, Zbiorniki_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki_M->NonInlinedSFcns.methods2[4]);
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
          sfcnUPtrs[0] = &Zbiorniki_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P1_Size_f[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P2_Size_he[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P3_Size_ay[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P4_Size_gk[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P5_Size_g[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P6_Size_i[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki_P.RTDACPCIPWM_P7_Size_p[0]);
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

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Zbiorniki_output(tid);
}

void MdlUpdate(int_T tid)
{
  Zbiorniki_update(tid);
}

void MdlInitializeSizes(void)
{
  Zbiorniki_M->Sizes.numContStates = (0);/* Number of continuous states */
  Zbiorniki_M->Sizes.numY = (0);       /* Number of model outputs */
  Zbiorniki_M->Sizes.numU = (0);       /* Number of model inputs */
  Zbiorniki_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Zbiorniki_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Zbiorniki_M->Sizes.numBlocks = (24); /* Number of blocks */
  Zbiorniki_M->Sizes.numBlockIO = (8); /* Number of block outputs */
  Zbiorniki_M->Sizes.numBlockPrms = (114);/* Sum of parameter "widths" */
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

RT_MODEL_Zbiorniki *Zbiorniki(void)
{
  Zbiorniki_initialize(1);
  return Zbiorniki_M;
}

void MdlTerminate(void)
{
  Zbiorniki_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
