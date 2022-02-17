#!/bin/sh

# output data file is identical for weight/noweight, it's just the generated data 
./bin/main_fit_exp_NLLS_GSL.exe | grep data | sed -e 's,.*:,,' > odata/exp_NLLS_GSL.dat
./bin/main_fit_exp_NLLS_GSL.exe weight| grep data | sed -e 's,.*:,,' > odata/exp_NLLS_GSL.dat
