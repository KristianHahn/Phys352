#ifndef LORENZ
#define LORENZ

double fx_lorenz(FourComponent* e, double dt, double* parameters  );

double fy_lorenz(FourComponent* e, double dt, double* parameters  );

double fz_lorenz(FourComponent* e, double dt, double* parameters  );

double noop_lorenz(FourComponent* e, double dt, double* parameters  );

#endif 
