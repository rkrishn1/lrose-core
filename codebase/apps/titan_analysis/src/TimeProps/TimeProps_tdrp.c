/*******************************************
 * TimeProps_tdrp.c
 *
 * TDRP C code file 'TimeProps' module.
 *
 * Code for program TimeProps
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "TimeProps_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[24];
static TimeProps_tdrp_struct *Params;
static char *Module = "TimeProps";

/*************************************************************
 * TimeProps_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   TimeProps_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

int TimeProps_tdrp_load_from_args(int argc, char **argv,
                         TimeProps_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  TimeProps_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * TimeProps_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than TimeProps_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   TimeProps_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

int TimeProps_tdrp_load(char *param_file_path,
               TimeProps_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  TimeProps_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * TimeProps_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See TimeProps_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int TimeProps_tdrp_load_defaults(TimeProps_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  TimeProps_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * TimeProps_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void TimeProps_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * TimeProps_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

void TimeProps_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * TimeProps_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int TimeProps_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * TimeProps_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int TimeProps_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * TimeProps_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void TimeProps_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * TimeProps_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int TimeProps_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * TimeProps_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int TimeProps_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * TimeProps_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *TimeProps_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * TimeProps_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *TimeProps_tdrp_init(TimeProps_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  TimeProps_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(TimeProps_tdrp_struct));
  params->struct_size = sizeof(TimeProps_tdrp_struct);

  /* Parameter 'Comment 0' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = COMMENT_TYPE;
  tt->param_name = tdrpStrDup("Comment 0");
  tt->comment_hdr = tdrpStrDup("Computes activity stats.");
  tt->comment_text = tdrpStrDup("");
  tt++;
  
  /* Parameter 'debug' */
  /* ctype is 'TimeProps_debug' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug option");
  tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("debug");
  tt->enum_def.nfields = 3;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
    tt->enum_def.fields[0].val = DEBUG_OFF;
    tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
    tt->enum_def.fields[1].val = DEBUG_NORM;
    tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
    tt->enum_def.fields[2].val = DEBUG_VERBOSE;
  tt->single_val.e = DEBUG_OFF;
  tt++;
  
  /* Parameter 'malloc_debug_level' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("malloc_debug_level");
  tt->descr = tdrpStrDup("Malloc debug level");
  tt->help = tdrpStrDup("0 - none, 1 - corruption checking, 2 - records all malloc blocks and checks, 3 - printout of all mallocs etc.");
  tt->val_offset = (char *) &(pp.malloc_debug_level) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = 0;
  tt->max_val.l = 3;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'instance' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("instance");
  tt->descr = tdrpStrDup("Process instance");
  tt->help = tdrpStrDup("Used for registration with procmap.");
  tt->val_offset = (char *) &(pp.instance) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("Test");
  tt++;
  
  /* Parameter 'mode' */
  /* ctype is 'TimeProps_distribution_class' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = ENUM_TYPE;
  tt->param_name = tdrpStrDup("mode");
  tt->descr = tdrpStrDup("Mode of operation");
  tt->help = tdrpStrDup("If DELTA_TIME, output is a list of time differences between storm starts in a period of activity. In ACTIVITY mode, the output list contains start times, durations for and times between periods of activity. The system is considered active if at least one entry is active at the time. A period of activity will span the activity_gap_max, but no greater gap.");
  tt->val_offset = (char *) &(pp.mode) - (char *) &pp;
  tt->enum_def.name = tdrpStrDup("distribution_class");
  tt->enum_def.nfields = 2;
  tt->enum_def.fields = (enum_field_t *)
      tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
    tt->enum_def.fields[0].name = tdrpStrDup("DELTA_TIME_MODE");
    tt->enum_def.fields[0].val = DELTA_TIME_MODE;
    tt->enum_def.fields[1].name = tdrpStrDup("ACTIVITY_MODE");
    tt->enum_def.fields[1].val = ACTIVITY_MODE;
  tt->single_val.e = DELTA_TIME_MODE;
  tt++;
  
  /* Parameter 'activity_nstorms_min' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("activity_nstorms_min");
  tt->descr = tdrpStrDup("Min number of storms to define an activity period.");
  tt->help = tdrpStrDup("If the number of storms in an active period is less than this number, the period is discarded.");
  tt->val_offset = (char *) &(pp.activity_nstorms_min) - (char *) &pp;
  tt->single_val.l = 1;
  tt++;
  
  /* Parameter 'activity_gap_max' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("activity_gap_max");
  tt->descr = tdrpStrDup("Max value for activity gap (secs).");
  tt->help = tdrpStrDup("An active period will end if there is a gap in excess of this time.");
  tt->val_offset = (char *) &(pp.activity_gap_max) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'activity_time_of_day_offet' */
  /* ctype is 'long' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = LONG_TYPE;
  tt->param_name = tdrpStrDup("activity_time_of_day_offet");
  tt->descr = tdrpStrDup("Offset (hr) applied when computing activity relative to the time of day.");
  tt->help = tdrpStrDup("When the end of the day in UCT tends to occur during periods of activity, the histogram for time_of_day will be bimodal. To remove this effect, an offset is added to the times so that the mode of the histogram occurs somewhere in the middle of the day, which makes the fitting of a statistical distribution meaningful.");
  tt->val_offset = (char *) &(pp.activity_time_of_day_offet) - (char *) &pp;
  tt->has_min = TRUE;
  tt->has_max = TRUE;
  tt->min_val.l = -24;
  tt->max_val.l = 24;
  tt->single_val.l = 0;
  tt++;
  
  /* Parameter 'time_label' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("time_label");
  tt->descr = tdrpStrDup("Label for time data");
  tt->help = tdrpStrDup("Used to identify column for time data.");
  tt->val_offset = (char *) &(pp.time_label) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("time");
  tt++;
  
  /* Parameter 'dur_label' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("dur_label");
  tt->descr = tdrpStrDup("Label for duration data");
  tt->help = tdrpStrDup("Used to identify column for duration data.");
  tt->val_offset = (char *) &(pp.dur_label) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("duration");
  tt++;
  
  /* Parameter 'condition_input_data' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("condition_input_data");
  tt->descr = tdrpStrDup("Apply conditions to input data.");
  tt->help = tdrpStrDup("If TRUE, the input data values are conditioned on a given field, which lie in a given intervals - see cond_min, cond_max.");
  tt->val_offset = (char *) &(pp.condition_input_data) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'conditional_label' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("conditional_label");
  tt->descr = tdrpStrDup("Label for conditional data");
  tt->help = tdrpStrDup("Used to identify column for conditional data.");
  tt->val_offset = (char *) &(pp.conditional_label) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("cond");
  tt++;
  
  /* Parameter 'cond_min' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("cond_min");
  tt->descr = tdrpStrDup("Min value for conditional field.");
  tt->help = tdrpStrDup("See condition_input_data.");
  tt->val_offset = (char *) &(pp.cond_min) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'cond_max' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("cond_max");
  tt->descr = tdrpStrDup("Max value for conditional field.");
  tt->help = tdrpStrDup("See condition_input_data.");
  tt->val_offset = (char *) &(pp.cond_max) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'limit_time_data' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("limit_time_data");
  tt->descr = tdrpStrDup("Apply limits to time data.");
  tt->help = tdrpStrDup("If TRUE, the input data values are limited to between time_min and time_max.");
  tt->val_offset = (char *) &(pp.limit_time_data) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'time_min' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("time_min");
  tt->descr = tdrpStrDup("Min value for time field.");
  tt->help = tdrpStrDup("See limit_time_data.");
  tt->val_offset = (char *) &(pp.time_min) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'time_max' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("time_max");
  tt->descr = tdrpStrDup("Max value for time field.");
  tt->help = tdrpStrDup("See limit_time_data.");
  tt->val_offset = (char *) &(pp.time_max) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'limit_dur_data' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("limit_dur_data");
  tt->descr = tdrpStrDup("Apply limits to dur data.");
  tt->help = tdrpStrDup("If TRUE, the input data values are limited to between dur_min and dur_max.");
  tt->val_offset = (char *) &(pp.limit_dur_data) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'dur_min' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dur_min");
  tt->descr = tdrpStrDup("Min value for dur field.");
  tt->help = tdrpStrDup("See limit_dur_data.");
  tt->val_offset = (char *) &(pp.dur_min) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'dur_max' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dur_max");
  tt->descr = tdrpStrDup("Max value for dur field.");
  tt->help = tdrpStrDup("See limit_dur_data.");
  tt->val_offset = (char *) &(pp.dur_max) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'limit_dtime_data' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("limit_dtime_data");
  tt->descr = tdrpStrDup("In DELTA_TIME mode, Apply limits to delta time data.");
  tt->help = tdrpStrDup("If TRUE, the delta time values are limited to between dtime_min and dtime_max.");
  tt->val_offset = (char *) &(pp.limit_dtime_data) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'dtime_min' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dtime_min");
  tt->descr = tdrpStrDup("Min value for dtime field.");
  tt->help = tdrpStrDup("See limit_dtime_data.");
  tt->val_offset = (char *) &(pp.dtime_min) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* Parameter 'dtime_max' */
  /* ctype is 'double' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = DOUBLE_TYPE;
  tt->param_name = tdrpStrDup("dtime_max");
  tt->descr = tdrpStrDup("Max value for dtime field.");
  tt->help = tdrpStrDup("See limit_dtime_data.");
  tt->val_offset = (char *) &(pp.dtime_max) - (char *) &pp;
  tt->single_val.d = 0;
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
