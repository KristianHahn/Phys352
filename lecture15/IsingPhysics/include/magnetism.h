#ifndef MAGNETISM
#define MAGNETISM

#define kB 1.
#define J  1.
#define mu 1.




/* spin-spin & spin-field interactions */
double energyFunction(IsingSpin * obj, IsingLattice2D* lptr );


/* evaluated for each spin to determine wheter 
   to flip.  This is the "flipfunction" we pass
   to sweep
*/
void boltzmannFlip(IsingSpin* obj, IsingLattice2D* lptr );

/* property averaging */
double getMagnetization(IsingLattice2D* );
double getMagnetizationForMPI(IsingLattice2D* );
double getEnergyPerSpin(IsingLattice2D* );
double getEnergySquaredPerSpin(IsingLattice2D* );
//void getCorrelationInfo(IsingLattice2D*, CorrelationInfo* );

#endif
