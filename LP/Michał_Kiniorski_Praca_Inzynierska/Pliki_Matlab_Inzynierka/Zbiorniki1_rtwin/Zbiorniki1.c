/*
 * Zbiorniki1.c
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki1.mdl".
 *
 * Model Version              : 1.121
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Thu Nov 05 17:15:12 2015
 */

#include "Zbiorniki1.h"
#include "Zbiorniki1_private.h"
#include <stdio.h>
#include "Zbiorniki1_dt.h"

/* Block signals (auto storage) */
BlockIO_Zbiorniki1 Zbiorniki1_B;

/* Block states (auto storage) */
D_Work_Zbiorniki1 Zbiorniki1_DWork;

/* Real-time model */
RT_MODEL_Zbiorniki1 Zbiorniki1_M_;
RT_MODEL_Zbiorniki1 *Zbiorniki1_M = &Zbiorniki1_M_;

/* Model output function */
void Zbiorniki1_output(int_T tid)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  Zbiorniki1_B.Gain = (Zbiorniki1_B.RTDACAnalogInputs[0] -
                       Zbiorniki1_P.Constant_Value) * Zbiorniki1_P.Gain_Gain;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Sum: '<Root>/Sum1'
   */
  Zbiorniki1_B.Gain1 = (Zbiorniki1_B.RTDACAnalogInputs[1] -
                        Zbiorniki1_P.Constant5_Value) * Zbiorniki1_P.Gain1_Gain;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Sum: '<Root>/Sum2'
   */
  Zbiorniki1_B.Gain2 = (Zbiorniki1_B.RTDACAnalogInputs[2] -
                        Zbiorniki1_P.Constant6_Value) * Zbiorniki1_P.Gain2_Gain;

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S1>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  Zbiorniki1_B.SliderGain = Zbiorniki1_P.SliderGain_Gain *
    Zbiorniki1_P.Constant4_Value;

  /* Gain: '<S4>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  Zbiorniki1_B.SliderGain_h = Zbiorniki1_P.SliderGain_Gain_i *
    Zbiorniki1_P.Constant3_Value;

  /* Gain: '<S5>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Zbiorniki1_B.SliderGain_o = Zbiorniki1_P.SliderGain_Gain_l *
    Zbiorniki1_P.Constant1_Value;

  /* Gain: '<S6>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Zbiorniki1_B.SliderGain_j = Zbiorniki1_P.SliderGain_Gain_b *
    Zbiorniki1_P.Constant2_Value;
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Zbiorniki1_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Zbiorniki1_M->Timing.clockTick0))
    ++Zbiorniki1_M->Timing.clockTickH0;
  Zbiorniki1_M->Timing.t[0] = Zbiorniki1_M->Timing.clockTick0 *
    Zbiorniki1_M->Timing.stepSize0 + Zbiorniki1_M->Timing.clockTickH0 *
    Zbiorniki1_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Zbiorniki1_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((char_T *)Zbiorniki1_M,0,
                sizeof(RT_MODEL_Zbiorniki1));
  rtsiSetSolverName(&Zbiorniki1_M->solverInfo,"FixedStepDiscrete");
  Zbiorniki1_M->solverInfoPtr = (&Zbiorniki1_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Zbiorniki1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Zbiorniki1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Zbiorniki1_M->Timing.sampleTimes = (&Zbiorniki1_M->Timing.sampleTimesArray[0]);
    Zbiorniki1_M->Timing.offsetTimes = (&Zbiorniki1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Zbiorniki1_M->Timing.sampleTimes[0] = (0.05);

    /* task offsets */
    Zbiorniki1_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Zbiorniki1_M, &Zbiorniki1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Zbiorniki1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Zbiorniki1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Zbiorniki1_M, 999.0);
  Zbiorniki1_M->Timing.stepSize0 = 0.05;

  /* external mode info */
  Zbiorniki1_M->Sizes.checksums[0] = (3203836843U);
  Zbiorniki1_M->Sizes.checksums[1] = (2263144379U);
  Zbiorniki1_M->Sizes.checksums[2] = (191951179U);
  Zbiorniki1_M->Sizes.checksums[3] = (434565771U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Zbiorniki1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Zbiorniki1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Zbiorniki1_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Zbiorniki1_M));
  }

  Zbiorniki1_M->solverInfoPtr = (&Zbiorniki1_M->solverInfo);
  Zbiorniki1_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&Zbiorniki1_M->solverInfo, 0.05);
  rtsiSetSolverMode(&Zbiorniki1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Zbiorniki1_M->ModelData.blockIO = ((void *) &Zbiorniki1_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Zbiorniki1_B.RTDACAnalogInputs[0]);
    for (i = 0; i < 10; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Zbiorniki1_M->ModelData.defaultParam = ((real_T *) &Zbiorniki1_P);

  /* states (dwork) */
  Zbiorniki1_M->Work.dwork = ((void *) &Zbiorniki1_DWork);
  (void) memset((char_T *) &Zbiorniki1_DWork,0,
                sizeof(D_Work_Zbiorniki1));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Zbiorniki1_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Zbiorniki1_M->NonInlinedSFcns.sfcnInfo;
    Zbiorniki1_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Zbiorniki1_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Zbiorniki1_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(Zbiorniki1_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Zbiorniki1_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Zbiorniki1_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Zbiorniki1_M));
    rtssSetStepSizePtr(sfcnInfo, &Zbiorniki1_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Zbiorniki1_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki1_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Zbiorniki1_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Zbiorniki1_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Zbiorniki1_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Zbiorniki1_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Zbiorniki1_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Zbiorniki1_M->solverInfoPtr);
  }

  Zbiorniki1_M->Sizes.numSFcns = (5);

  /* register each child */
  {
    (void) memset((void *)&Zbiorniki1_M->NonInlinedSFcns.childSFunctions[0],0,
                  5*sizeof(SimStruct));
    Zbiorniki1_M->childSfunctions =
      (&Zbiorniki1_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        Zbiorniki1_M->childSfunctions[i] =
          (&Zbiorniki1_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Zbiorniki1/<S11>/RT-DAC Analog Inputs (rtdacpci_analoginputs) */
    {
      SimStruct *rts = Zbiorniki1_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki1_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki1_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki1_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki1_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, Zbiorniki1_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki1_M->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Zbiorniki1_B.RTDACAnalogInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs");
      ssSetPath(rts,
                "Zbiorniki1/The Levels of Tanks/RT-DAC Analog Inputs/RT-DAC Analog Inputs");
      ssSetRTModel(rts,Zbiorniki1_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &Zbiorniki1_P.RTDACAnalogInputs_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &Zbiorniki1_P.RTDACAnalogInputs_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &Zbiorniki1_P.RTDACAnalogInputs_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &Zbiorniki1_P.RTDACAnalogInputs_P4_Size[0]);
      }

      /* registration */
      rtdacpci_analoginputs(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Zbiorniki1/<S8>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki1_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki1_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki1_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki1_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki1_M->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, Zbiorniki1_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki1_M->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki1_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki1_B.SliderGain_o;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki1/Power Output/VALVE Down PWM 2/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki1_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P7_Size[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki1/<S9>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki1_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki1_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki1_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki1_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki1_M->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, Zbiorniki1_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki1_M->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki1_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki1_B.SliderGain_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts,
                "Zbiorniki1/Power Output/VALVE Middle PWM 1/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki1_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P1_Size_k[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P2_Size_c[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P3_Size_a[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P4_Size_c[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P5_Size_j[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P6_Size_o[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P7_Size_l[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki1/<S10>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki1_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki1_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki1_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki1_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki1_M->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, Zbiorniki1_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki1_M->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki1_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki1_B.SliderGain_h;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki1/Power Output/VALVE Upper PWM 0/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki1_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P1_Size_j[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P2_Size_g[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P3_Size_o[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P4_Size_d[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P5_Size_h[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P6_Size_g[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P7_Size_a[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Zbiorniki1/<S7>/RT-DAC PCI PWM  (rtdacpci_pwm) */
    {
      SimStruct *rts = Zbiorniki1_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Zbiorniki1_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Zbiorniki1_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Zbiorniki1_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Zbiorniki1_M->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, Zbiorniki1_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Zbiorniki1_M->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Zbiorniki1_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Zbiorniki1_B.SliderGain;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC PCI\nPWM\n");
      ssSetPath(rts, "Zbiorniki1/Power Output/POMP PWM 3/RT-DAC PCI PWM ");
      ssSetRTModel(rts,Zbiorniki1_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Zbiorniki1_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P1_Size_n[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P2_Size_e[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P3_Size_n[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P4_Size_l[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P5_Size_i[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P6_Size_d[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Zbiorniki1_P.RTDACPCIPWM_P7_Size_c[0]);
      }

      /* registration */
      rtdacpci_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
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
void Zbiorniki1_terminate(void)
{
  /* Level2 S-Function Block: '<S11>/RT-DAC Analog Inputs' (rtdacpci_analoginputs) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/RT-DAC PCI PWM ' (rtdacpci_pwm) */
  {
    SimStruct *rts = Zbiorniki1_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* External mode */
  rtExtModeShutdown(1);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Zbiorniki1_output(tid);
}

void MdlUpdate(int_T tid)
{
  Zbiorniki1_update(tid);
}

void MdlInitializeSizes(void)
{
  Zbiorniki1_M->Sizes.numContStates = (0);/* Number of continuous states */
  Zbiorniki1_M->Sizes.numY = (0);      /* Number of model outputs */
  Zbiorniki1_M->Sizes.numU = (0);      /* Number of model inputs */
  Zbiorniki1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Zbiorniki1_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Zbiorniki1_M->Sizes.numBlocks = (26);/* Number of blocks */
  Zbiorniki1_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  Zbiorniki1_M->Sizes.numBlockPrms = (114);/* Sum of parameter "widths" */
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

RT_MODEL_Zbiorniki1 *Zbiorniki1(void)
{
  Zbiorniki1_initialize(1);
  return Zbiorniki1_M;
}

void MdlTerminate(void)
{
  Zbiorniki1_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
