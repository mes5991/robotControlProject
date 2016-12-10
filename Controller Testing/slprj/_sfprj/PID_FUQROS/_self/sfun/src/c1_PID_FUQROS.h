#ifndef __c1_PID_FUQROS_h__
#define __c1_PID_FUQROS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_PID_FUQROSInstanceStruct
#define typedef_SFc1_PID_FUQROSInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_PID_FUQROS;
  real_T *c1_e;
  real_T *c1_x;
  real_T *c1_y;
  real_T (*c1_pathV)[900];
  real_T *c1_phipath;
  real_T *c1_xpathOut;
  real_T *c1_ypathOut;
} SFc1_PID_FUQROSInstanceStruct;

#endif                                 /*typedef_SFc1_PID_FUQROSInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_PID_FUQROS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_PID_FUQROS_get_check_sum(mxArray *plhs[]);
extern void c1_PID_FUQROS_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
