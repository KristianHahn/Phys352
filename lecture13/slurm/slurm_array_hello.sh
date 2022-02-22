#!/bin/bash                                                                                                                                                                      
#SBATCH -A e20271               # Allocation                                                                                                                                     
#SBATCH -p short                # Queue                                                                                                                                          
#SBATCH -t 04:00:00             # Walltime/duration of the job                                                                                                                   
#SBATCH -N 1                    # Number of Nodes                                                                                                                                
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu                                                                                 
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)                                                                                                                   
#SBATCH --mail-user=kristian.hahn@northwestern.edu  # Designate email address for job communications                                                                             
#SBATCH --mail-type=NONE        # Events options are job BEGIN, END, NONE, FAIL, REQUEUE                                                                                         
#SBATCH --output=/home/kah704/2022/Phys352/lecture13/slurm/log/slurm_%A_%a.out    # Path for output must already exist                                                           
#SBATCH --error=/home/kah704/2022/Phys352/lecture13/slurm/log/slurm_%A_%a.err     # Path for errors must already exist                                                           
#SBATCH --job-name="test"       # Name of job                                                                                                                                    
#SBATCH --array 0-9                                                                                                                                                              

if [ "$#" -lt 1 ]; then
    echo "need to pass a path as an argument"
    exit
fi;
path=$1;

# check number of args                                                                                                                                                           
echo "I was called as an array job ..."
echo "SLURM_JOB_ID:  ${SLURM_JOB_ID}"
echo "SLURM_ARRAY_JOB_ID: ${SLURM_ARRAY_JOB_ID}"
echo "SLURM_ARRAY_TASK_ID: ${SLURM_ARRAY_TASK_ID}"
echo "SLURM_ARRAY_TASK_COUNT: ${SLURM_ARRAY_TASK_COUNT}"
echo "SLURM_ARRAY_TASK_MAX: ${SLURM_ARRAY_TASK_MAX}"
echo "SLURM_ARRAY_TASK_MIN: ${SLURM_ARRAY_TASK_MIN}"

# first arg is a label, and is output path
# this script should be runs as:
# sbatch ./slurm/slurm_array_job.sh $PWD/slurm/output                                                                                                                
./bin/writehello.exe ${SLURM_ARRAY_TASK_ID} $path
