#include "TwoComponent.h"
#include "FourComponent.h"

double fx(TwoComponent* n, double dt, double* parameters  ); 
double fvx(TwoComponent* n, double dt, double* parameters  );
double fy(TwoComponent* n, double dt, double* parameters  );
double fvy(TwoComponent* n, double dt, double* parameters  );


double fx_drag(FourComponent* n, double dt, double* parameters  ); 
double fy_drag(FourComponent* n, double dt, double* parameters  ); 
double fvx_drag(FourComponent* c, double dt, double* parameters  );
double fvy_drag(FourComponent* x, double dt, double* parameters  );

double fvx_drag_adiabatic(FourComponent* x, double dt, double* parameters  );
double fvy_drag_adiabatic(FourComponent* x, double dt, double* parameters  );
