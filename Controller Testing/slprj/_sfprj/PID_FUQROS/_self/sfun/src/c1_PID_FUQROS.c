/* Include files */

#include "PID_FUQROS_sfun.h"
#include "c1_PID_FUQROS.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "PID_FUQROS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[21] = { "path", "x1", "y1", "phi1",
  "etmp", "index", "i", "ex1", "ey1", "ex2", "ey2", "sinnnn", "nargin",
  "nargout", "x", "y", "pathV", "e", "phipath", "xpathOut", "ypathOut" };

/* Function Declarations */
static void initialize_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static void initialize_params_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static void enable_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void disable_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *
  chartInstance);
static void set_sim_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void sf_gateway_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static void mdl_start_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void c1_chartstep_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static void initSimStructsc1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_b_ypathOut, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_b_y[900]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static real_T c1_mpower(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
  c1_a);
static void c1_scalarEg(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void c1_dimagree(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void c1_error(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static real_T c1_sqrt(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      c1_b_x);
static void c1_b_error(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static real_T c1_cos(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T c1_b_x);
static real_T c1_sin(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T c1_b_x);
static real_T c1_sign(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      c1_b_x);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_PID_FUQROS, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      *c1_b_x);
static void c1_b_cos(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                     *c1_b_x);
static void c1_b_sin(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                     *c1_b_x);
static void c1_b_sign(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      *c1_b_x);
static void init_dsm_address_info(SFc1_PID_FUQROSInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_PID_FUQROSInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_PID_FUQROS(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_PID_FUQROS = 0U;
}

static void initialize_params_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *
  chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_b_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_g_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createcellmatrix(5, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_e;
  c1_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 0, c1_c_y);
  c1_b_hoistedGlobal = *chartInstance->c1_phipath;
  c1_b_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 1, c1_d_y);
  c1_c_hoistedGlobal = *chartInstance->c1_xpathOut;
  c1_c_u = c1_c_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 2, c1_e_y);
  c1_d_hoistedGlobal = *chartInstance->c1_ypathOut;
  c1_d_u = c1_d_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 3, c1_f_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_c1_PID_FUQROS;
  c1_e_u = c1_e_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_b_y, 4, c1_g_y);
  sf_mex_assign(&c1_st, c1_b_y, false);
  return c1_st;
}

static void set_sim_state_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_e = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("e", c1_u, 0)), "e");
  *chartInstance->c1_phipath = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("phipath", c1_u, 1)), "phipath");
  *chartInstance->c1_xpathOut = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xpathOut", c1_u, 2)), "xpathOut");
  *chartInstance->c1_ypathOut = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ypathOut", c1_u, 3)), "ypathOut");
  chartInstance->c1_is_active_c1_PID_FUQROS = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c1_PID_FUQROS", c1_u, 4)),
     "is_active_c1_PID_FUQROS");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_PID_FUQROS(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 900; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_pathV)[c1_i0], 2U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_y, 1U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_x, 0U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_PID_FUQROS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_PID_FUQROSMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_e, 3U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_phipath, 4U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_xpathOut, 5U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_ypathOut, 6U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
}

static void mdl_start_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_x;
  real_T c1_b_y;
  int32_T c1_i1;
  uint32_T c1_debug_family_var_map[21];
  real_T c1_b_pathV[900];
  real_T c1_path[900];
  real_T c1_x1;
  real_T c1_y1;
  real_T c1_phi1;
  real_T c1_etmp;
  real_T c1_index;
  real_T c1_i;
  real_T c1_ex1;
  real_T c1_ey1;
  real_T c1_ex2;
  real_T c1_ey2;
  real_T c1_sinnnn;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 4.0;
  real_T c1_b_e;
  real_T c1_b_phipath;
  real_T c1_b_xpathOut;
  real_T c1_b_ypathOut;
  int32_T c1_i2;
  int32_T c1_k;
  real_T c1_c_x[900];
  int32_T c1_b_k;
  int32_T c1_b_i;
  real_T c1_d0;
  real_T c1_d1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_x;
  c1_b_hoistedGlobal = *chartInstance->c1_y;
  c1_b_x = c1_hoistedGlobal;
  c1_b_y = c1_b_hoistedGlobal;
  for (c1_i1 = 0; c1_i1 < 900; c1_i1++) {
    c1_b_pathV[c1_i1] = (*chartInstance->c1_pathV)[c1_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_path, 0U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_x1, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_y1, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_phi1, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_etmp, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_index, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ex1, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ey1, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ex2, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ey2, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinnnn, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_x, 14U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_y, 15U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_pathV, 16U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_e, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_phipath, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_xpathOut, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_ypathOut, 20U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i2 = 0; c1_i2 < 900; c1_i2++) {
    c1_c_x[c1_i2] = c1_b_pathV[c1_i2];
  }

  for (c1_k = 1; c1_k < 901; c1_k++) {
    c1_b_k = c1_k - 1;
    c1_path[c1_b_k] = c1_c_x[c1_b_k];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_x1 = c1_path[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_y1 = c1_path[300];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_phi1 = c1_path[600];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_etmp = rtInf;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_b_e = rtInf;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_index = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_i = 1.0;
  c1_b_i = 0;
  while (c1_b_i < 300) {
    c1_i = 1.0 + (real_T)c1_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    c1_d0 = c1_mpower(chartInstance, c1_b_x - c1_path[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 237, 1,
                       MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S,
      1U, 237U, 1U, c1_i), 1, 300) - 1]) + c1_mpower(chartInstance, c1_b_y -
      c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 253, 1, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 253U, 1U, c1_i), 1, 300) + 299]);
    c1_b_sqrt(chartInstance, &c1_d0);
    c1_etmp = c1_d0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c1_etmp, c1_b_e, -1, 2U,
          c1_etmp < c1_b_e))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
      c1_b_e = c1_etmp;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
      c1_index = c1_i;
    }

    c1_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  c1_b_xpathOut = c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 340, 5, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 340U, 5U, c1_index), 1, 300) - 1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_b_ypathOut = c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 364, 5, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 364U, 5U, c1_index), 1, 300) + 299];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_b_phipath = c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 387, 5, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 387U, 5U, c1_index), 1, 300) + 599];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_ex1 = c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 410, 5, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 410U, 5U, c1_index), 1, 300) - 1] - c1_b_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_ey1 = c1_path[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 435, 5, MAX_uint32_T, (int32_T)sf_integer_check
    (chartInstance->S, 1U, 435U, 5U, c1_index), 1, 300) + 299] - c1_b_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_d0 = c1_b_phipath;
  c1_b_cos(chartInstance, &c1_d0);
  c1_ex2 = c1_d0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_d0 = c1_b_phipath;
  c1_b_sin(chartInstance, &c1_d0);
  c1_ey2 = c1_d0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_sinnnn = c1_ex1 * c1_ey2 - c1_ey1 * c1_ex2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_d1 = c1_sinnnn;
  c1_b_sign(chartInstance, &c1_d1);
  c1_b_e *= c1_d1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c1_e = c1_b_e;
  *chartInstance->c1_phipath = c1_b_phipath;
  *chartInstance->c1_xpathOut = c1_b_xpathOut;
  *chartInstance->c1_ypathOut = c1_b_ypathOut;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_PID_FUQROS(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_b_ypathOut, const char_T *c1_identifier)
{
  real_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ypathOut),
    &c1_thisId);
  sf_mex_destroy(&c1_b_ypathOut);
  return c1_b_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_y;
  real_T c1_d2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_b_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_ypathOut;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_b_ypathOut = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ypathOut),
    &c1_thisId);
  sf_mex_destroy(&c1_b_ypathOut);
  *(real_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i3;
  const mxArray *c1_b_y = NULL;
  real_T c1_u[900];
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i3 = 0; c1_i3 < 900; c1_i3++) {
    c1_u[c1_i3] = (*(real_T (*)[900])c1_inData)[c1_i3];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 900),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i4;
  int32_T c1_i5;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i6;
  real_T c1_u[900];
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i4 = 0;
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    for (c1_i6 = 0; c1_i6 < 300; c1_i6++) {
      c1_u[c1_i6 + c1_i4] = (*(real_T (*)[900])c1_inData)[c1_i6 + c1_i4];
    }

    c1_i4 += 300;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 300, 3),
                false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_b_y[900])
{
  real_T c1_dv0[900];
  int32_T c1_i7;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 300,
                3);
  for (c1_i7 = 0; c1_i7 < 900; c1_i7++) {
    c1_b_y[c1_i7] = c1_dv0[c1_i7];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_path;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[900];
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_path = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_path), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_path);
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    for (c1_i10 = 0; c1_i10 < 300; c1_i10++) {
      (*(real_T (*)[900])c1_outData)[c1_i10 + c1_i8] = c1_b_y[c1_i10 + c1_i8];
    }

    c1_i8 += 300;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_PID_FUQROS_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static real_T c1_mpower(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_c;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_b_x;
  real_T c1_d_a;
  boolean_T c1_p;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_b_x = c1_c_a;
  c1_d_a = c1_b_x;
  c1_c = c1_d_a * c1_d_a;
  c1_p = false;
  if (c1_p) {
    c1_error(chartInstance);
  }

  return c1_c;
}

static void c1_scalarEg(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_dimagree(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_error(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  static char_T c1_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_b_y));
}

static real_T c1_sqrt(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      c1_b_x)
{
  real_T c1_c_x;
  c1_c_x = c1_b_x;
  c1_b_sqrt(chartInstance, &c1_c_x);
  return c1_c_x;
}

static void c1_b_error(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  const mxArray *c1_b_y = NULL;
  static char_T c1_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c1_c_y = NULL;
  static char_T c1_b_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_b_y, 14, c1_c_y));
}

static real_T c1_cos(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T c1_b_x)
{
  real_T c1_c_x;
  c1_c_x = c1_b_x;
  c1_b_cos(chartInstance, &c1_c_x);
  return c1_c_x;
}

static real_T c1_sin(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T c1_b_x)
{
  real_T c1_c_x;
  c1_c_x = c1_b_x;
  c1_b_sin(chartInstance, &c1_c_x);
  return c1_c_x;
}

static real_T c1_sign(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      c1_b_x)
{
  real_T c1_c_x;
  c1_c_x = c1_b_x;
  c1_b_sign(chartInstance, &c1_c_x);
  return c1_c_x;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_b_y = NULL;
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_b_y;
  int32_T c1_i11;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i11, 1, 6, 0U, 0, 0U, 0);
  c1_b_y = c1_i11;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_b_y;
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_PID_FUQROS, const char_T
  *c1_identifier)
{
  uint8_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_PID_FUQROS), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_PID_FUQROS);
  return c1_b_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_PID_FUQROSInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_b_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_b_sqrt(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      *c1_b_x)
{
  real_T c1_c_x;
  boolean_T c1_b0;
  boolean_T c1_p;
  c1_c_x = *c1_b_x;
  c1_b0 = (c1_c_x < 0.0);
  c1_p = c1_b0;
  if (c1_p) {
    c1_b_error(chartInstance);
  }

  *c1_b_x = muDoubleScalarSqrt(*c1_b_x);
}

static void c1_b_cos(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                     *c1_b_x)
{
  (void)chartInstance;
  *c1_b_x = muDoubleScalarCos(*c1_b_x);
}

static void c1_b_sin(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                     *c1_b_x)
{
  (void)chartInstance;
  *c1_b_x = muDoubleScalarSin(*c1_b_x);
}

static void c1_b_sign(SFc1_PID_FUQROSInstanceStruct *chartInstance, real_T
                      *c1_b_x)
{
  (void)chartInstance;
  *c1_b_x = muDoubleScalarSign(*c1_b_x);
}

static void init_dsm_address_info(SFc1_PID_FUQROSInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_PID_FUQROSInstanceStruct
  *chartInstance)
{
  chartInstance->c1_e = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c1_x = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c1_y = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c1_pathV = (real_T (*)[900])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_phipath = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_xpathOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_ypathOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_PID_FUQROS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1782586418U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(487462586U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3779097073U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2977209737U);
}

mxArray* sf_c1_PID_FUQROS_get_post_codegen_info(void);
mxArray *sf_c1_PID_FUQROS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Bqql72OX2je08gK0Z0oKDC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(900);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_PID_FUQROS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_PID_FUQROS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_PID_FUQROS_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_PID_FUQROS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_PID_FUQROS_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_PID_FUQROS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"e\",},{M[1],M[11],T\"phipath\",},{M[1],M[12],T\"xpathOut\",},{M[1],M[13],T\"ypathOut\",},{M[8],M[0],T\"is_active_c1_PID_FUQROS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_PID_FUQROS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_PID_FUQROSInstanceStruct *chartInstance =
      (SFc1_PID_FUQROSInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _PID_FUQROSMachineNumber_,
           1,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_PID_FUQROSMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_PID_FUQROSMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _PID_FUQROSMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pathV");
          _SFD_SET_DATA_PROPS(3,2,0,1,"e");
          _SFD_SET_DATA_PROPS(4,2,0,1,"phipath");
          _SFD_SET_DATA_PROPS(5,2,0,1,"xpathOut");
          _SFD_SET_DATA_PROPS(6,2,0,1,"ypathOut");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,534);
        _SFD_CV_INIT_EML_IF(0,1,0,266,278,-1,320);
        _SFD_CV_INIT_EML_FOR(0,1,0,193,214,324);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,270,278,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 900U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _PID_FUQROSMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_PID_FUQROSInstanceStruct *chartInstance =
      (SFc1_PID_FUQROSInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_e);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_x);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_y);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c1_pathV);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_phipath);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_xpathOut);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_ypathOut);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sGycpHSgEJ118T5WyH8588F";
}

static void sf_opaque_initialize_c1_PID_FUQROS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*)
    chartInstanceVar);
  initialize_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_PID_FUQROS(void *chartInstanceVar)
{
  enable_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_PID_FUQROS(void *chartInstanceVar)
{
  disable_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_PID_FUQROS(void *chartInstanceVar)
{
  sf_gateway_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_PID_FUQROS(SimStruct* S)
{
  return get_sim_state_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_PID_FUQROS(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_PID_FUQROS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_PID_FUQROS_optimization_info();
    }

    finalize_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_PID_FUQROS(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_PID_FUQROS((SFc1_PID_FUQROSInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_PID_FUQROS(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_PID_FUQROS_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(354512560U));
  ssSetChecksum1(S,(4024587480U));
  ssSetChecksum2(S,(3523845058U));
  ssSetChecksum3(S,(1874973565U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_PID_FUQROS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_PID_FUQROS(SimStruct *S)
{
  SFc1_PID_FUQROSInstanceStruct *chartInstance;
  chartInstance = (SFc1_PID_FUQROSInstanceStruct *)utMalloc(sizeof
    (SFc1_PID_FUQROSInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_PID_FUQROSInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_PID_FUQROS;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_PID_FUQROS;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_PID_FUQROS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_PID_FUQROS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_PID_FUQROS;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_PID_FUQROS;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_PID_FUQROS;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_PID_FUQROS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_PID_FUQROS;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_PID_FUQROS;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_PID_FUQROS;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_PID_FUQROS(chartInstance);
}

void c1_PID_FUQROS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_PID_FUQROS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_PID_FUQROS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_PID_FUQROS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_PID_FUQROS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
