
xmaxi=100
tsteps="0.05 0.01 0.005 0.001 0.0005 0.0001"

# run once to get error
for t in ${tsteps[*]}; do
    xmax=`echo "$xmaxi*0.05/$t" | bc`
    ./bin/main_decay.exe $xmax $t euler > ./data/decay_euler_tstep_${t}_opt.dat
    ./bin/main_decay.exe $xmax $t rkO2  > ./data/decay_rkO2_tstep_${t}_opt.dat
    ./bin/main_decay.exe $xmax $t rkO4  > ./data/decay_rkO4_tstep_${t}_opt.dat
done 

rm ./data/decay_*_perf_opt.dat
# run again to get perf
for t in ${tsteps[*]}; do
    xmax=`echo "$xmaxi*0.05/$t" | bc`

    perf stat ./bin/main_decay.exe $xmax $t euler quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_euler_tstep_${t}_opt.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_euler_perf_opt.dat

    perf stat ./bin/main_decay.exe $xmax $t rkO2 quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_rkO2_tstep_${t}_opt.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_rkO2_perf_opt.dat

    perf stat ./bin/main_decay.exe $xmax $t rkO4 quiet >& ./data/tmp
    ninst=`grep instru ./data/tmp  | awk '{print $1}' | sed -e 's/,//g'`
    errline=`tail -1 ./data/decay_rkO4_tstep_${t}_opt.dat | sed -e 's/#//'`
    echo "$errline instr: $ninst" >> ./data/decay_rkO4_perf_opt.dat

done 
