#!/bin/bash
#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --mail-user=kristian.hahn@northwestern.edu  # Designate email address for job communications
#SBATCH --mail-type=NONE        # Events options are job BEGIN, END, NONE, FAIL, REQUEUE
#SBATCH --output=/home/kah704/slurm.out    # Path for output must already exist
#SBATCH --error=/home/kah704/slurm.err     # Path for errors must already exist
#SBATCH --job-name="test"       # Name of job


# check number of args
if [ "$#" -le 2 ]; then
	echo "need to pass a job label and path as arguments"
fi;

# first arg is a label, and is output path
./bin/writehello.exe $1 $HOME

