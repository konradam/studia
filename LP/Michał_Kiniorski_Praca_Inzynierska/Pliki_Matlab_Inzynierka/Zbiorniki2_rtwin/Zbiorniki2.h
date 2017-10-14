/*
 * Zbiorniki2.h
 *
 * Real-Time Workshop code generation for Simulink model "Zbiorniki2.mdl".
 *
 * Model Version              : 1.134
 * Real-Time Workshop version : 7.1  (R2008a)  23-Jan-2008
 * C source code generated on : Wed Nov 11 14:54:15 2015
 */
#ifndef RTW_HEADER_Zbiorniki2_h_
#define RTW_HEADER_Zbiorniki2_h_
#ifndef Zbiorniki2_COMMON_INCLUDES_
# define Zbiorniki2_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rtwintgt.h"
#include "rt_nonfinite.h"
#endif                                 /* Zbiorniki2_COMMON_INCLUDES_ */

#include "Zbiorniki2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Zbiorniki2_rtModel             RT_MODEL_Zbiorniki2

/* Block signals (auto storage) */
typedef struct {
  real_T RTDACAnalogInputs[3];         /* '<S11>/RT-DAC Analog Inputs' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T SliderGain;                   /* '<S1>/Slider Gain' */
  real_T SliderGain_g;                 /* '<S4>/Slider Gain' */
  real_T SliderGain_c;                 /* '<S5>/Slider Gain' */
  real_T SliderGain_o;                 /* '<S6>/Slider Gain' */
} BlockIO_Zbiorniki2;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */
} D_Work_Zbiorniki2;

/* Backward compatible GRT Identifiers */
#define rtB                            Zbiorniki2_B
#define BlockIO                        BlockIO_Zbiorniki2
#define rtXdot                         Zbiorniki2_Xdot
#define StateDerivatives               StateDerivatives_Zbiorniki2
#define tXdis                          Zbiorniki2_Xdis
#define StateDisabled                  StateDisabled_Zbiorniki2
#define rtP                            Zbiorniki2_P
#define Parameters                     Parameters_Zbiorniki2
#define rtDWork                        Zbiorniki2_DWork
#define D_Work                         D_Work_Zbiorniki2

/* Parameters (auto storage) */
struct Parameters_Zbiorniki2 {
  real_T RTDACAnalogInputs_P1_Size[2]; /* Computed Parameter: P1Size
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P1;         /* Expression: BaseAddress
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P2_Size[2]; /* Computed Parameter: P2Size
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P2[3];      /* Expression: Chan
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P3_Size[2]; /* Computed Parameter: P3Size
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P3[3];      /* Expression: Gain
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P4_Size[2]; /* Computed Parameter: P4Size
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T RTDACAnalogInputs_P4;         /* Expression: T0
                                        * '<S11>/RT-DAC Analog Inputs'
                                        */
  real_T Gain_Gain;                    /* Expression: p1(1)
                                        * '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: p1(2)
                                        * '<Root>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: p2(1)
                                        * '<Root>/Gain1'
                                        */
  real_T Constant5_Value;              /* Expression: p2(2)
                                        * '<Root>/Constant5'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * '<Root>/Gain2'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * '<Root>/Constant6'
                                        */
  real_T RTDACPCIPWM_P1_Size[2];       /* Computed Parameter: P1Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1;               /* Expression: BaseAddress
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_Size[2];       /* Computed Parameter: P2Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2;               /* Expression: ChanIdx
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_Size[2];       /* Computed Parameter: P3Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3;               /* Expression: ChanMode
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_Size[2];       /* Computed Parameter: P4Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4;               /* Expression: ChanPresc
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_Size[2];       /* Computed Parameter: P5Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5;               /* Expression: SetOutputsFlag
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_Size[2];       /* Computed Parameter: P6Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6;               /* Expression: SetOutputsValue
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_Size[2];       /* Computed Parameter: P7Size
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7;               /* Expression: T0
                                        * '<S8>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_Size_l[2];     /* Computed Parameter: P1Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_g;             /* Expression: BaseAddress
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_Size_o[2];     /* Computed Parameter: P2Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_e;             /* Expression: ChanIdx
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_Size_k[2];     /* Computed Parameter: P3Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_d;             /* Expression: ChanMode
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_Size_n[2];     /* Computed Parameter: P4Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_i;             /* Expression: ChanPresc
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_Size_p[2];     /* Computed Parameter: P5Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_d;             /* Expression: SetOutputsFlag
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_Size_a[2];     /* Computed Parameter: P6Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_g;             /* Expression: SetOutputsValue
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_Size_l[2];     /* Computed Parameter: P7Size
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_i;             /* Expression: T0
                                        * '<S9>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_Size_b[2];     /* Computed Parameter: P1Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_e;             /* Expression: BaseAddress
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_Size_h[2];     /* Computed Parameter: P2Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_j;             /* Expression: ChanIdx
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_Size_l[2];     /* Computed Parameter: P3Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_j;             /* Expression: ChanMode
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_Size_e[2];     /* Computed Parameter: P4Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_f;             /* Expression: ChanPresc
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_Size_h[2];     /* Computed Parameter: P5Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_m;             /* Expression: SetOutputsFlag
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_Size_d[2];     /* Computed Parameter: P6Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_e;             /* Expression: SetOutputsValue
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_Size_ly[2];    /* Computed Parameter: P7Size
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_d;             /* Expression: T0
                                        * '<S10>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_Size_p[2];     /* Computed Parameter: P1Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P1_n;             /* Expression: BaseAddress
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_Size_d[2];     /* Computed Parameter: P2Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P2_jq;            /* Expression: ChanIdx
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_Size_c[2];     /* Computed Parameter: P3Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P3_dn;            /* Expression: ChanMode
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_Size_o[2];     /* Computed Parameter: P4Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P4_a;             /* Expression: ChanPresc
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_Size_g[2];     /* Computed Parameter: P5Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P5_c;             /* Expression: SetOutputsFlag
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_Size_m[2];     /* Computed Parameter: P6Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P6_g1;            /* Expression: SetOutputsValue
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_Size_a[2];     /* Computed Parameter: P7Size
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T RTDACPCIPWM_P7_p;             /* Expression: T0
                                        * '<S7>/RT-DAC PCI PWM '
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * '<Root>/Constant4'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * '<S1>/Slider Gain'
                                        */
  real_T SliderGain_Gain_k;            /* Expression: gain
                                        * '<S4>/Slider Gain'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * '<S5>/Slider Gain'
                                        */
  real_T SliderGain_Gain_o;            /* Expression: gain
                                        * '<S6>/Slider Gain'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_Zbiorniki2 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    SimStruct childSFunctions[5];
    SimStruct *childSFunctionPtrs[5];
    struct _ssBlkInfo2 blkInfo2[5];
    struct _ssSFcnModelMethods2 methods2[5];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn4;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_Zbiorniki2 Zbiorniki2_P;

/* Block signals (auto storage) */
extern BlockIO_Zbiorniki2 Zbiorniki2_B;

/* Block states (auto storage) */
extern D_Work_Zbiorniki2 Zbiorniki2_DWork;

/* Model entry point functions */
extern void Zbiorniki2_initialize(boolean_T firstTime);
extern void Zbiorniki2_output(int_T tid);
extern void Zbiorniki2_update(int_T tid);
extern void Zbiorniki2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Zbiorniki2 *Zbiorniki2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : Zbiorniki2
 * '<S1>'   : Zbiorniki2/Pompa
 * '<S2>'   : Zbiorniki2/Power Output
 * '<S3>'   : Zbiorniki2/The Levels of Tanks
 * '<S4>'   : Zbiorniki2/Zawor - DOL
 * '<S5>'   : Zbiorniki2/Zawor - GORA
 * '<S6>'   : Zbiorniki2/Zawor - SRODEK
 * '<S7>'   : Zbiorniki2/Power Output/POMP PWM 3
 * '<S8>'   : Zbiorniki2/Power Output/VALVE Down PWM 2
 * '<S9>'   : Zbiorniki2/Power Output/VALVE Middle PWM 1
 * '<S10>'  : Zbiorniki2/Power Output/VALVE Upper PWM 0
 * '<S11>'  : Zbiorniki2/The Levels of Tanks/RT-DAC Analog Inputs
 */
#endif                                 /* RTW_HEADER_Zbiorniki2_h_ */
