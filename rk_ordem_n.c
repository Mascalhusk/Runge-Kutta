#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef double(*sistefunc)();

double gt(double t, double z)
{
	return z;
}

double ft(double t, double y, double z)
{
	return 3*z - 2*y + 6*exp(-t);
}

double rk(sistefunc func[], double y, double t, double h)
{	int i;
	double k[M];
	
	for(i=0; i<N; i++)
	{	fprintf(saida, "%lf \t %lf\n",t, y);
	
	for(i=0; i<N; i++)
	{
		l1[i] = gt(t, z);
	}
	for(i=0; i<N; i++)
	{	k1[i] = ft(t, y, z);
	}
	
	for(i=0; i<N; i++)
	{	l2[i] = gt(t + 0.5*h, z + 0.5*h*l1);
	}	
	for(i=0; i<N; i++)
	{	k2[i] = ft(t + 0.5*h, y + 0.5*h*k1, z + 0.5*h*l1);
	}
	for(i=0; i<N; i++)
	{	l3[i] = gt(t + 0.5*h, z+ 0.5*h*l2);
	}	
	for(i=0; i<N; i++)
	{	k3[i] = ft(t + 0.5*h, y+ 0.5*h*k2, z + 0.5*h*l2);
	}	
	for(i=0; i<N; i++)
	{	l4[i] = gt(t + h, z + h*l3);
	}
	for(i=0; i<N; i++)
	{	k4[i] = ft(t + h, y+h*k3, z + h*l3);
	}		
		
		y = y + (h*(k1 + 2*k2 + 2*k3 + k4))/6.0;
		t=t+h;	
	}	
}

int main()
{	int i, N, L, M
	double y, dy, z, dz, h, t, a, b;
	sistefunc equacoes[N]={ft, gt};
	FILE *saida;
	
	saida=fopen("saida.dat", "w");
	
	printf("Informe o intervalo (a,b); tempo inicial (t); o número de equações (L) e a ordem (M) e o: \n");
	scanf("%lf, %lf, %lf, %d, %d",&a, &b, &t,&L, &M);
	
	N=L*M;
	h=(b-a)/10.;
	double y[M];
		 
	yt=rk(equacoes, y, t, h);
	
	fclose(saida);

}
