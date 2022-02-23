#!/bin/bash
#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --output=./slurm/logs/%A_%a.out   # Path for output must already exist
#SBATCH --error=./slurm/logs/%A_%a.err    # Path for errors must already exist
#SBATCH --job-name="circleInt"  # Name of job
#SBATCH --array 0-99            # Job array 



# the job ...
NTrials=1000000000
id=${SLURM_ARRAY_TASK_ID}
seed=`echo "${id}*${RANDOM}" | bc`
./circleInt.exe ${Ntrials} ${seed} >& ./slurm/output/circle_${id}.dat

