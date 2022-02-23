#!/bin/bash
#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --mail-user=<my_email>  # Designate email address for job communications
#SBATCH --mail-type=<event>     # Events options are job BEGIN, END, NONE, FAIL, REQUEUE
#SBATCH --output=<file_path>    # Path for output must already exist
#SBATCH --error=<file_path>     # Path for errors must already exist
#SBATCH --job-name="test"       # Name of job
#SBATCH --array 0-99            # Job array 



# the job ...
NTrails=1000000000
id=${SLURM_ARRAY_TASK_ID}
seed=`echo "${id}*${RANDOM}" | bc`
./circleInt.exe ${Ntrials} ${seed} >& ./slurm/output/circle_${id}.dat

