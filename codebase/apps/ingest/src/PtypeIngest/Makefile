# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
# ** Copyright UCAR (c) 1990 - 2016                                         
# ** University Corporation for Atmospheric Research (UCAR)                 
# ** National Center for Atmospheric Research (NCAR)                        
# ** Boulder, Colorado, USA                                                 
# ** BSD licence applies - redistribution and use in source and binary      
# ** forms, with or without modification, are permitted provided that       
# ** the following conditions are met:                                      
# ** 1) If the software is modified to produce derivative works,            
# ** such modified software should be clearly marked, so as not             
# ** to confuse it with the version available from UCAR.                    
# ** 2) Redistributions of source code must retain the above copyright      
# ** notice, this list of conditions and the following disclaimer.          
# ** 3) Redistributions in binary form must reproduce the above copyright   
# ** notice, this list of conditions and the following disclaimer in the    
# ** documentation and/or other materials provided with the distribution.   
# ** 4) Neither the name of UCAR nor the names of its contributors,         
# ** if any, may be used to endorse or promote products derived from        
# ** this software without specific prior written permission.               
# ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
# ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
# ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
###########################################################################
#
# Makefile for PtypeIngest
#
# December 2009
#
###########################################################################

include $(RAP_MAKE_INC_DIR)/rap_make_macros

MODULE_TYPE=progcpp

TARGET_FILE = PtypeIngest

LOC_INCLUDES = $(NETCDF_INCS) $(NETCDF4_INCS)

LOC_LIBS = -ldsdata -lMdv -lRadx -lNcxx -lSpdb \
	-ldsserver -ldidss -lrapformats -leuclid \
	-lphysics -ltoolsa -ldataport -ltdrp \
	-lnetcdf_c++ -lnetcdf $(NETCDF4_LIBS) -lbz2 \
	-lz

LOC_LDFLAGS = $(NETCDF_LDFLAGS) $(NETCDF4_LDFLAGS)

LOC_CFLAGS = 
LOC_CPPC_CFLAGS = 

HDRS = \
	Params.hh \
	Args.hh \
	PtypeIngest.hh \
	NetcdfField.hh \
	NetcdfFile.hh

CPPC_SRCS = \
	Params.cc \
	Args.cc \
	PtypeIngest.cc \
	Main.cc \
	NetcdfField.cc \
	NetcdfFile.cc

#
# standard targets
#

include $(RAP_MAKE_INC_DIR)/rap_make_c++_targets

#
# local targets
#

depend: depend_generic

#
# TDRP support
#

Params.cc: paramdef.$(TARGET_FILE)
	tdrp_gen -f paramdef.$(TARGET_FILE) -c++ \
		-prog $(TARGET_FILE)

clean_tdrp:
	$(RM) Params.hh Params.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

