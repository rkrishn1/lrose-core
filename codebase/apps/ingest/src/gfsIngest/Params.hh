// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program gfsIngest
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    TIMESTAMP_GEN_TIME = 0,
    TIMESTAMP_FCAST_TIME = 1
  } timestamp_t;

  typedef enum {
    OUTPUT_PROJ_FLAT = 0,
    OUTPUT_PROJ_LATLON = 1,
    OUTPUT_PROJ_LAMBERT_CONF = 2,
    OUTPUT_PROJ_NATIVE = 3
  } projection_t;

  typedef enum {
    UNKNOWN = 0,
    PRES = 1,
    PRMSL = 2,
    PRESSURE_TENDENCY = 3,
    HGT = 7,
    CLOUD_HEIGHT = 8,
    TOZNE = 10,
    TMP = 11,
    POT = 13,
    EQUIVALENT_POTENTIAL_TEMP = 14,
    MAX_TEMP = 15,
    MIN_TEMP = 16,
    DEW_POINT_TEMPERATURE = 17,
    DEW_POINT_DEPRESSION = 18,
    VISIBILITY = 20,
    GPA = 27,
    UGRD = 33,
    VGRD = 34,
    VVEL = 39,
    ABSV = 41,
    SPFH = 51,
    RH = 52,
    HUMIDITY_MIXING_RATIO = 53,
    PWAT = 54,
    PRECIPITATION_RATE = 59,
    TOTAL_PRECIPITATION = 61,
    LARGE_SCALE_PRECIPITATION = 62,
    CONVECTIVE_PRECIPITATION = 63,
    WEASD = 65,
    SNOW_DEPTH = 66,
    TCDC = 71,
    LOW_CLOUD_COVER = 73,
    MED_CLOUD_COVER = 74,
    HIGH_CLOUD_COVER = 75,
    CWAT = 76,
    BEST_LIFTED_INDEX = 77,
    LAND = 81,
    ALBEDO = 84,
    SOIL_TEMPERATURE = 85,
    SOIL_MOISTURE_CONTENT = 86,
    WATER_RUNOFF = 90,
    SNOW_MELT = 99,
    SHORTWAVE_RAD_AT_SURFACE = 111,
    LONGWAVE_RAD_AT_SURFACE = 112,
    ICEC = 91,
    SHORTWAVE_RAD_AT_TOP = 113,
    LONGWAVE_RAD_AT_TOP = 114,
    LATENT_HEAT_FLUX = 121,
    SENSIBLE_HEAT_FLUX = 122,
    ZONAL_MOMENTUM_FLUX = 124,
    MEAN_SEA_LEVEL_PRESS_SAR = 128,
    MEAN_SEA_LEVEL_PRESS_MAPS = 129,
    LFTX = 131,
    FOUR_LFTX = 132,
    HORZ_MOISTURE_CONVERGENCE = 135,
    VWSH = 136,
    CATEGORICAL_RAIN = 140,
    CATEGORICAL_FREEZING_RAIN = 141,
    CATEGORICAL_ICE_PELLETS = 142,
    CATEGORICAL_SNOW = 143,
    SOILW = 144,
    POTENTIAL_EVAP_RATE = 145,
    CLD_WORK_FUNC = 146,
    ZONAL_GRAVITY_WAVE_STRESS = 147,
    POTENTIAL_VORTICITY = 149,
    CLWMR = 153,
    O3MR = 154,
    GND_HEAT_FLUX = 155,
    CIN = 156,
    CAPE = 157,
    TURBULENT_KINETIC_ENERGY = 158,
    RAIN_WATER_MIXING_RATIO = 170,
    SNOW_MIXING_RATIO = 171,
    MOMENTUM_FLUX = 172,
    ICE_MIXING_RATIO = 178,
    GRAUPEL_MIXING_RATIO = 179,
    TURB_SIGMET_AIRMET = 185,
    ICING_SIGMET_AIRMET = 186,
    LIGHTNING = 187,
    RATE_WATER_CANOPY2GROUND = 188,
    VIRTUAL_POTENTIAL_TEMP = 189,
    STORM_RELATIVE_HELICITY = 190,
    U_STORM_MOTION = 196,
    V_STORM_MOTION = 197,
    NUM_CONCEN_ICE_PARTICLES = 198,
    DIRECT_EVAPORATION_BARE_SOIL = 199,
    DOWN_SHORTWAVE_RAD_FLUX = 204,
    DOWN_LONGWAVE_RAD_FLUX = 205,
    UP_SHORTWAVE_RAD_FLUX = 211,
    UP_LONGWAVE_RAD_FLUX = 212,
    CONV_PRECP_RATE = 214,
    HPBL = 221,
    FIVE_WAVH = 222,
    PLANT_CANOPY_SURFACE_WATER = 223,
    SOIL_TYPE = 224,
    VEGETATION_TYPE = 225,
    SNOW_PHASE_CHANGE_HEAT_FLUX = 229,
    FIVE_WAVA = 230,
    BASEFLOW_GRDWATER_RUNOFF = 234,
    STORM_SURFACE_RUNOFF = 235,
    SNOW_TEMPERATURE = 239,
    DRAG_COEFFICIENT = 253,
    GUST_WIND_SPEED = 255
  } param_id_t;

  // struct typedefs

  typedef struct {
    double lat;
    double lon;
  } output_origin_t;

  typedef struct {
    double lat1;
    double lat2;
  } output_parallel_t;

  typedef struct {
    int nx;
    int ny;
    int nz;
    double minx;
    double miny;
    double minz;
    double dx;
    double dy;
    double dz;
  } output_grid_t;

  typedef struct {
    param_id_t param_id;
    int level_id;
  } out_field_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

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

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

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

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

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

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

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

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

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

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

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

  int arrayRealloc(const char *param_name,
                   int new_array_n);

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

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  tdrp_bool_t debug;

  char* instance;

  char* input_dir;

  char* input_suffix;

  long max_input_data_age;

  tdrp_bool_t write_forecast;

  char* forecast_mdv_url;

  tdrp_bool_t write_non_forecast;

  char* non_forecast_mdv_url;

  timestamp_t non_forecast_timestamp;

  char* data_set_info;

  char* data_set_name;

  char* data_set_source;

  projection_t mdv_proj_type;

  output_origin_t output_origin;

  float output_rotation;

  output_parallel_t output_parallel;

  int num_forecasts;

  output_grid_t output_grid;

  tdrp_bool_t process_everything;

  out_field_t *_output_fields;
  int output_fields_n;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[25];

  const char *_className;

  bool _exitDeferred;

};

#endif

