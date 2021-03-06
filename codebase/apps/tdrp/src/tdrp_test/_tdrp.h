/*******************************************
 * _tdrp.h
 *
 * TDRP header file.
 *
 * Code for program tdrp_test
 *
 * This header file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#ifndef __tdrp_h
#define __tdrp_h

#ifdef __cplusplus
extern "C" {
#endif

#include <tdrp/tdrp.h>

/*
 * typedefs
 */

typedef enum {
  ETI = 1,
  GEONOR = 2,
  CAMPBELL = 3
} _gauge_t;

typedef enum {
  BOTLEFT = 0,
  TOPLEFT = 1,
  BOTRIGHT = 2,
  TOPRIGHT = 3
} _origin_t;

typedef enum {
  REALTIME = 0,
  ARCHIVE = 1,
  OTHER = 2
} _mode_t;

typedef struct {
  long nx;
  long ny;
  double minx;
  double miny;
  double dx;
  double dy;
} _grid_t;

typedef struct {
  double lat;
  double lon;
  double wind_sensor_ht;
  _gauge_t gauge_make;
  tdrp_bool_t has_humidity;
} _surface_station_t;

typedef struct {
  double scale;
  double bias;
  long nplanes;
  char* name;
  char* units;
  _origin_t origin;
} _data_field_t;

/*
 * typedef for main struct - _tdrp_struct
 */

typedef struct {

  size_t struct_size;

  /***** your_age *****/

  int your_age;

  /***** our_ages *****/

  struct {
    int *val;
    int len;
  } our_ages;
  int *_our_ages;
  int our_ages_n;

  /***** icon *****/

  struct {
    int *val;
    int len;
  } icon;
  int *_icon;
  int icon_n;
  int **__icon;
  int icon_n1;
  int icon_n2;

  /***** number_of_radars *****/

  long number_of_radars;

  /***** days_in_month *****/

  struct {
    long *val;
    int len;
  } days_in_month;
  long *_days_in_month;
  int days_in_month_n;

  /***** item_count *****/

  struct {
    long *val;
    int len;
  } item_count;
  long *_item_count;
  int item_count_n;
  long **__item_count;
  int item_count_n1;
  int item_count_n2;

  /***** speed *****/

  float speed;

  /***** storm_volume *****/

  struct {
    float *val;
    int len;
  } storm_volume;
  float *_storm_volume;
  int storm_volume_n;

  /***** rain_accumulation *****/

  struct {
    float *val;
    int len;
  } rain_accumulation;
  float *_rain_accumulation;
  int rain_accumulation_n;
  float **__rain_accumulation;
  int rain_accumulation_n1;
  int rain_accumulation_n2;

  /***** mass_coefficient *****/

  double mass_coefficient;

  /***** speed_of_light *****/

  double speed_of_light;

  /***** storm_mass *****/

  struct {
    double *val;
    int len;
  } storm_mass;
  double *_storm_mass;
  int storm_mass_n;

  /***** length_factor *****/

  struct {
    double *val;
    int len;
  } length_factor;
  double *_length_factor;
  int length_factor_n;
  double **__length_factor;
  int length_factor_n1;
  int length_factor_n2;

  /***** use_data *****/

  tdrp_bool_t use_data;

  /***** allow_outliers *****/

  struct {
    tdrp_bool_t *val;
    int len;
  } allow_outliers;
  tdrp_bool_t *_allow_outliers;
  int allow_outliers_n;

  /***** compute_length *****/

  struct {
    tdrp_bool_t *val;
    int len;
  } compute_length;
  tdrp_bool_t *_compute_length;
  int compute_length_n;
  tdrp_bool_t **__compute_length;
  int compute_length_n1;
  int compute_length_n2;

  /***** debug *****/

  tdrp_bool_t debug;

  /***** flags *****/

  struct {
    tdrp_bool_t *val;
    int len;
  } flags;
  tdrp_bool_t *_flags;
  int flags_n;

  /***** path_delim *****/

  char* path_delim;

  /***** input_file_ext *****/

  char* input_file_ext;

  /***** input_file_paths *****/

  struct {
    char* *val;
    int len;
  } input_file_paths;
  char* *_input_file_paths;
  int input_file_paths_n;

  /***** output_file_paths *****/

  struct {
    char* *val;
    int len;
  } output_file_paths;
  char* *_output_file_paths;
  int output_file_paths_n;
  char* **__output_file_paths;
  int output_file_paths_n1;
  int output_file_paths_n2;

  /***** input_dir *****/

  char* input_dir;

  /***** data_origin *****/

  struct {
    _origin_t *val;
    int len;
  } data_origin;
  _origin_t *_data_origin;
  int data_origin_n;

  /***** mode *****/

  struct {
    _mode_t *val;
    int len;
  } mode;
  _mode_t *_mode;
  int mode_n;
  _mode_t **__mode;
  int mode_n1;
  int mode_n2;

  /***** grid *****/

  _grid_t grid;

  /***** surface_stations *****/

  struct {
    _surface_station_t *val;
    int len;
  } surface_stations;
  _surface_station_t *_surface_stations;
  int surface_stations_n;

  /***** data_field *****/

  struct {
    _data_field_t *val;
    int len;
  } data_field;
  _data_field_t *_data_field;
  int data_field_n;

} _tdrp_struct;

/*
 * function prototypes
 */

/*************************************************************
 * _tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   _tdrp_struct *params: loads up this struct
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

extern int _tdrp_load_from_args(int argc, char **argv,
                                _tdrp_struct *params,
                                char **override_list,
                                char **params_path_p);

/*************************************************************
 * _tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than _tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   _tdrp_struct *params: loads up this struct
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

extern int _tdrp_load(char *param_file_path,
                      _tdrp_struct *params,
                      char **override_list,
                      int expand_env, int debug);

/*************************************************************
 * _tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See _tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

extern int _tdrp_load_defaults(_tdrp_struct *params,
                               int expand_env);

/*************************************************************
 * _tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

extern void _tdrp_sync(void);

/*************************************************************
 * _tdrp_print()
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

extern void _tdrp_print(FILE *out, tdrp_print_mode_t mode);

/*************************************************************
 * _tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

extern void _tdrp_free_all(void);

/*************************************************************
 * _tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

extern int _tdrp_check_all_set(FILE *out);

/*************************************************************
 * _tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

extern int _tdrp_check_is_set(char *param_name);

/*************************************************************
 * _tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int _tdrp_array_realloc(char *param_name,
                              int new_array_n);

/*************************************************************
 * _tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

extern int _tdrp_array2D_realloc(char *param_name,
                                 int new_array_n1,
                                 int new_array_n2);

/*************************************************************
 * _tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *_tdrp_table(void);

/*************************************************************
 * _tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

extern TDRPtable *_tdrp_init(_tdrp_struct *params);

#ifdef __cplusplus
}
#endif

#endif

