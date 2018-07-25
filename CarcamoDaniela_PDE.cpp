#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cmath>


using namespace std;
//using std::cout;
//using std::cout;


int main(){

  double rangoL=1.0;
  double rangot=0.3;
  double dx=0.01;
  double dy=0.01;
  int nx=rangoL/dx;
  int ny=rangoL/dy;


  double c=300;
  double dt=(1/2.0)*dx/c;
  double ti=0.0;
  int nt=rangot/dt;
//Construyo el vector de tiempo
  int i,j,k;
  double tiempo[nt];
// abro el archivo del tiempo 0
  double u_inicial[nx];
  double matrizinicial[nx][ny]	;
  std::ifstream file;
  file.open("init.dat"); 
       if(!file.is_open()){
            cout<<"error";
            return 0;
        }
for(i=0;i<(ny*nx);i++)
	    {
		file>>u_inicial[i];
	    }  


double fonda[nx][ny];
double fpresente[nx][ny];
int contador=0;
for (i=0;i<nx;i++){
for (j=0;j<ny;j++){
fonda[i][j]=u_inicial[contador];
fpresente[i][j]=u_inicial[contador];
contador=contador+1;
}
}
file.close();
int b,n,m;
	for(b=0;b<nt;b++)
    {
	  	tiempo[b]=dt*b;
    }  

std::ofstream tiempocero("tiempocero.txt");
for (n=0;n<nx;n++){
for (m=0;m<ny;m++){
		tiempocero<< fonda[n][m]<<endl;
	    }}
tiempocero.close();
std::cout<< fonda[99][99]<<u_inicial[9999]<< std::endl;
std::cout<< nt<< std::endl;
double ffuturo[nx][ny];
double fsesenta[nx][ny];

int a,l;
for (a=0;a<nx;a++){
for (l=0;l<ny;l++){
ffuturo[a][l]=((dt*dt)*(fonda[a][l])) + ((c*c)/(dx*dx))*(fonda[a+2][l]-2*fonda[a+1][l]+(fonda[a][l])) + ((c*c)/(dy*dy))*((fonda[a][l+2])-2*(fonda[a][l+1])+(fonda[a][l]));
}
}
int cont=0;
while(cont<=3599)
{
for (a=0;a<nx;a++){
for (l=0;l<ny;l++){
fsesenta[a][l]=(dt*dt)*((2*(ffuturo[a][l])-(fpresente[a][l]))) + ((c*c)/(dx*dx))*(fpresente[a+2][l]-2*fpresente[a+1][l]+(fpresente[a][l])) + ((c*c)/(dy*dy))*((fpresente[a][l+2])-2*(fpresente[a][l+1])+(fpresente[a][l]));

fpresente[a][l]=ffuturo[a][l];
ffuturo[a][l]=fsesenta[a][l];
cont=cont+1;
}
}
}
std::ofstream tiemposesenta("tiempo60.txt");
for (n=0;n<nx;n++){
for (m=0;m<ny;m++){
		tiemposesenta<< ffuturo[n][m]<<endl;
	    }}
tiemposesenta.close();

 return 0;
}


