// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Mdv2AsciiContour
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'TriggerMode'
    // ctype is '_trigger_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("TriggerMode");
    tt->descr = tdrpStrDup("Trigger mode - synchronous or asynchronous");
    tt->help = tdrpStrDup("TRIGGER_ASYNC == process input data as they appear, ie. use latest_data_info\nTRIGGER_SYNC == strobe input at regular intervals.\nData are actually timestamped with processing time in TRIGGER_SYNC case.");
    tt->val_offset = (char *) &TriggerMode - &_start_;
    tt->enum_def.name = tdrpStrDup("trigger_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TRIGGER_ASYNC");
      tt->enum_def.fields[0].val = TRIGGER_ASYNC;
      tt->enum_def.fields[1].name = tdrpStrDup("TRIGGER_SYNC");
      tt->enum_def.fields[1].val = TRIGGER_SYNC;
    tt->single_val.e = TRIGGER_ASYNC;
    tt++;
    
    // Parameter 'TriggerTimeInterval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("TriggerTimeInterval");
    tt->descr = tdrpStrDup("Time interval in TimeTrigger mode, seconds.");
    tt->help = tdrpStrDup("Default is 6 minutes. TRIGGER_SYNC mode only. ");
    tt->val_offset = (char *) &TriggerTimeInterval - &_start_;
    tt->single_val.i = 360;
    tt++;
    
    // Parameter 'TriggerTimeLookBack'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("TriggerTimeLookBack");
    tt->descr = tdrpStrDup("Time to look back in TimeTrigger mode, seconds.");
    tt->help = tdrpStrDup("Default is 12 minutes. TRIGGER_SYNC mode only.\nShould be be greater than or equal to TriggerTimeInterval.");
    tt->val_offset = (char *) &TriggerTimeLookBack - &_start_;
    tt->single_val.i = 720;
    tt++;
    
    // Parameter 'InMdvURL'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("InMdvURL");
    tt->descr = tdrpStrDup("Input URL");
    tt->help = tdrpStrDup("Set to the URL for the input MDV files");
    tt->val_offset = (char *) &InMdvURL - &_start_;
    tt->single_val.s = tdrpStrDup("./");
    tt++;
    
    // Parameter 'OutDir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("OutDir");
    tt->descr = tdrpStrDup("Output directory");
    tt->help = tdrpStrDup("Set to the name of the output directory");
    tt->val_offset = (char *) &OutDir - &_start_;
    tt->single_val.s = tdrpStrDup("./");
    tt++;
    
    // Parameter 'Instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("Instance");
    tt->descr = tdrpStrDup("Instance to check into procmap with");
    tt->help = tdrpStrDup("Set as appropriate");
    tt->val_offset = (char *) &Instance - &_start_;
    tt->single_val.s = tdrpStrDup("primary");
    tt++;
    
    // Parameter 'ThreshAbove'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("ThreshAbove");
    tt->descr = tdrpStrDup("Set to true to pass values above the threshold.");
    tt->help = tdrpStrDup("If set to false, values below the threshold are passed.");
    tt->val_offset = (char *) &ThreshAbove - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Thresh'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("Thresh");
    tt->descr = tdrpStrDup("Set to the value to threshold at.");
    tt->help = tdrpStrDup("Values (above | below) this, inclusive, are accepted if ThreshAbove is (true | false)");
    tt->val_offset = (char *) &Thresh - &_start_;
    tt->single_val.f = 0.67;
    tt++;
    
    // Parameter 'UseFieldNumber'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("UseFieldNumber");
    tt->descr = tdrpStrDup("Set to true to use field number rather than name");
    tt->help = tdrpStrDup("Useful for the adjoint files which have no short field name.");
    tt->val_offset = (char *) &UseFieldNumber - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'FieldNumber'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("FieldNumber");
    tt->descr = tdrpStrDup("Number of desired field in MDV file");
    tt->help = tdrpStrDup("The PrintMdv utility may help in getting this.");
    tt->val_offset = (char *) &FieldNumber - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'FieldName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("FieldName");
    tt->descr = tdrpStrDup("Names of desired field in the MDV file");
    tt->help = tdrpStrDup("These are used for output even if FieldNumber is\nused to specify which fields are used.");
    tt->val_offset = (char *) &FieldName - &_start_;
    tt->single_val.s = tdrpStrDup("Forecast");
    tt++;
    
    // Parameter 'RealtimeMaxAge'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("RealtimeMaxAge");
    tt->descr = tdrpStrDup("Maximum age for file to be considered valid");
    tt->help = tdrpStrDup("In realtime mode only");
    tt->val_offset = (char *) &RealtimeMaxAge - &_start_;
    tt->single_val.i = 3600;
    tt++;
    
    // Parameter 'VarName'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("VarName");
    tt->descr = tdrpStrDup("Variable name for the output files.");
    tt->help = tdrpStrDup("Output files are named\nCONT_YYYYMMDDhhmmss_<VarName>.dat\n eg CONT_20001103123000_Forecast.dat\n");
    tt->val_offset = (char *) &VarName - &_start_;
    tt->single_val.s = tdrpStrDup("Forecast");
    tt++;
    
    // Parameter 'DoComposite'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("DoComposite");
    tt->descr = tdrpStrDup("Flag to set if doing compositing.");
    tt->help = tdrpStrDup("If set, composite is done between\nCompositeMin and CompositeMax. Set plane number to 0.");
    tt->val_offset = (char *) &DoComposite - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'CompositeMin'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("CompositeMin");
    tt->descr = tdrpStrDup("Minimum height to composite. Same units as MDV file.");
    tt->help = tdrpStrDup("Only used if DoComposite is true.");
    tt->val_offset = (char *) &CompositeMin - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'CompositeMax'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("CompositeMax");
    tt->descr = tdrpStrDup("Maximum height to composite. Same units as MDV file.");
    tt->help = tdrpStrDup("Only used if DoComposite is true.");
    tt->val_offset = (char *) &CompositeMax - &_start_;
    tt->single_val.f = 100000;
    tt++;
    
    // Parameter 'DoGridRemap'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("DoGridRemap");
    tt->descr = tdrpStrDup("Flag to set if data are to be remapped onto another grid.");
    tt->help = tdrpStrDup("If set, data are remapped onto the grid specified below.");
    tt->val_offset = (char *) &DoGridRemap - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup(" ------------ GRID PARAMETERS --------\nThe output grid, if DoGridRemap is TRUE.\nOtherwise the grid is take from the input file(s).");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'grid_origin_lat'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_origin_lat");
    tt->descr = tdrpStrDup("Latitude of grid origin");
    tt->help = tdrpStrDup("Must be specified.");
    tt->val_offset = (char *) &grid_origin_lat - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = -1000;
    tt->single_val.d = 34;
    tt++;
    
    // Parameter 'grid_origin_lon'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_origin_lon");
    tt->descr = tdrpStrDup("Longitude of grid origin");
    tt->help = tdrpStrDup("Must be specified.");
    tt->val_offset = (char *) &grid_origin_lon - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = -1000;
    tt->single_val.d = -77;
    tt++;
    
    // Parameter 'grid_rotation'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("grid_rotation");
    tt->descr = tdrpStrDup("Rotation (in degrees) of grid from true north");
    tt->help = tdrpStrDup("Usually 0 - applied to flat earth only");
    tt->val_offset = (char *) &grid_rotation - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = -360;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'grid_projection'
    // ctype is '_projection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("grid_projection");
    tt->descr = tdrpStrDup("Projection type of grid");
    tt->help = tdrpStrDup("Projections currently supported are FLAT, LATLON and LAMBERT");
    tt->val_offset = (char *) &grid_projection - &_start_;
    tt->enum_def.name = tdrpStrDup("projection_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("FLAT");
      tt->enum_def.fields[0].val = FLAT;
      tt->enum_def.fields[1].name = tdrpStrDup("LATLON");
      tt->enum_def.fields[1].val = LATLON;
    tt->single_val.e = FLAT;
    tt++;
    
    // Parameter 'grid_nx'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("grid_nx");
    tt->descr = tdrpStrDup("Number of cells in the grid in X");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_nx - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 100;
    tt++;
    
    // Parameter 'grid_ny'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("grid_ny");
    tt->descr = tdrpStrDup("Number of cells in the grid in Y");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_ny - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 100;
    tt++;
    
    // Parameter 'grid_nz'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("grid_nz");
    tt->descr = tdrpStrDup("Number of vertical levels in the output grid or to be composited.");
    tt->help = tdrpStrDup("See also grid_minz");
    tt->val_offset = (char *) &grid_nz - &_start_;
    tt->has_min = TRUE;
    tt->min_val.i = 1;
    tt->single_val.i = 1;
    tt++;
    
    // Parameter 'grid_dx'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dx");
    tt->descr = tdrpStrDup("Size of the cells in the output grid in X");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_dx - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_dy'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dy");
    tt->descr = tdrpStrDup("Size of the cells in the output grid in Y");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &grid_dy - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_dz'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_dz");
    tt->descr = tdrpStrDup("Change in altitude between vertical levels of the output grid");
    tt->help = tdrpStrDup("Applicable only when grid_nz > 1");
    tt->val_offset = (char *) &grid_dz - &_start_;
    tt->single_val.f = 1;
    tt++;
    
    // Parameter 'grid_minx'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_minx");
    tt->descr = tdrpStrDup("X at grid's lower left corner");
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection.");
    tt->val_offset = (char *) &grid_minx - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'grid_miny'
    // ctype is 'float'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = FLOAT_TYPE;
    tt->param_name = tdrpStrDup("grid_miny");
    tt->descr = tdrpStrDup("Y at grid's lower left corner");
    tt->help = tdrpStrDup("Units for this parameter will depend upon the output grid_projection.");
    tt->val_offset = (char *) &grid_miny - &_start_;
    tt->single_val.f = 0;
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("------ End of grid parameters. ");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Clump'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("Clump");
    tt->descr = tdrpStrDup("To do clumping or not.");
    tt->help = tdrpStrDup("If set to TRUE then clumps with less than\nMinClumpPixels will be removed.");
    tt->val_offset = (char *) &Clump - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'MinClumpPixels'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("MinClumpPixels");
    tt->descr = tdrpStrDup("Clump threshold, in pixels.");
    tt->help = tdrpStrDup("If Clump is TRUE then storms with less than\nMinClumpPixels will be removed.");
    tt->val_offset = (char *) &MinClumpPixels - &_start_;
    tt->single_val.i = 10;
    tt++;
    
    // Parameter 'doSpdb'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("doSpdb");
    tt->descr = tdrpStrDup("Set to TRUE to output SPDB GenPoly structures.");
    tt->help = tdrpStrDup("Allows CIDD display.");
    tt->val_offset = (char *) &doSpdb - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'spdbUrl'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdbUrl");
    tt->descr = tdrpStrDup("Where to put SPDB GenPoly structures.");
    tt->help = tdrpStrDup("Relevant only if doSpdb is TRUE");
    tt->val_offset = (char *) &spdbUrl - &_start_;
    tt->single_val.s = tdrpStrDup("spdbp:://localhost::./spdb/GenPoly");
    tt++;
    
    // Parameter 'spdbExpiry'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("spdbExpiry");
    tt->descr = tdrpStrDup("How long SPDB data last, seconds.");
    tt->help = tdrpStrDup("Relevant only if doSpdb is TRUE");
    tt->val_offset = (char *) &spdbExpiry - &_start_;
    tt->single_val.i = 60;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
