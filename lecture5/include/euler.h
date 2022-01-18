double euler_step(double x, double t, double f, double dt);

void euler_solver(double* x, double* t, double dt, int steps);

void euler_solver_fp(double* x, double* t, double (*dxdt)(double,double,double*), 
		     double* dxdt_parameters, double dt, int steps);

double f(double N, double dt, double* parameters  );
