#ifndef __c2_regulatorlq_zmieny_h__
#define __c2_regulatorlq_zmieny_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_regulatorlq_zmienyInstanceStruct
#define typedef_SFc2_regulatorlq_zmienyInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_regulatorlq_zmieny;
  real_T *c2_H3pp;
  real_T *c2_q;
  real_T *c2_H1pp;
  real_T *c2_H2pp;
  real_T (*c2_A)[9];
  real_T (*c2_B)[3];
} SFc2_regulatorlq_zmienyInstanceStruct;

#endif                                 /*typedef_SFc2_regulatorlq_zmienyInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_regulatorlq_zmieny_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_regulatorlq_zmieny_get_check_sum(mxArray *plhs[]);
extern void c2_regulatorlq_zmieny_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
