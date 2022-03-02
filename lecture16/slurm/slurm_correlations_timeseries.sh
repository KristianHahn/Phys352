
# submit with : sbatch ./slurm/slurm_correlations_timeseries.sh ./data ./img


#!/bin/sh
#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --output=./slurm/logs/%A_%a.out   # Path for output must already exist
#SBATCH --error=./slurm/logs/%A_%a.err    # Path for errors must already exist
#SBATCH --job-name="ising"  # Name of job
#SBATCH --array 0-9            # Job array (temperature) 


temps=( 1.00 1.50 2.00 2.25 2.26 2.27 2.28 2.5 3.00 5.00 )

T=${temps[${SLURM_ARRAY_TASK_ID}]}

datdir=$1
datdir="$datdir/timeseries_T_${T}"
if [ -e $datdir ]; then rm -rf $datdir; fi 
mkdir $datdir

imgdir=$1
imgdir="$imgdir/timeseries_T_${T}"
if [ -e $imgdir ]; then rm -rf $imgdir; fi 
mkdir $imgdir

./bin/main_correlations_timeseries.exe $RANDOM $T 0 200 200 $datdir | grep 'i:' > $datdir/MvsTime.dat
./scripts/make_timeseries_plots.sh $datdir $imgdir 
