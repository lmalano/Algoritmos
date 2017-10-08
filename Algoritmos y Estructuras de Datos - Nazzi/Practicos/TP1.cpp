#include <iostream>
using namespace std;

class motor 
{     public:
             motor(int a){setPotencia(a);}
             int getPotencia(){return potencia;}
             void setPotencia(int a){potencia=a;}
             void toPrint(){cout<<"potencia: "<<potencia<<" watt."<<endl;}
      private:
              int potencia;
};

class motorElectrico : motor
{     
      public:
             motorElectrico(int a,int b):motor(a){setAmperaje(b);}
             void setAmperaje(int a)  {amperaje=a;}
             int getAmperaje(){return amperaje;}
             void toPrint(){motor::toPrint();cout<<"amperaje: "<<amperaje<<" Amperes."<<endl;}
      private:
              int amperaje;   
};
       
class motorACombustion : motor
{
      public:
             motorACombustion(int a, int b, int c):motor(a) {setCilindrada (b); setRPM (c);}
             void setCilindrada(int a){cilindrada=a;}
             void setRPM(int a){rpm=a;}
             int getCilindrada(){return cilindrada;}
             int getRPM(){return rpm;}
             void toPrint(){motor::toPrint(); cout<<"cilindrada: "<<cilindrada<<" cc."<<endl<<"rpm: "<<rpm<<endl;}
      private:
              int cilindrada;
              int rpm;     
};     
       
class motorInyeccion : motorACombustion
{
      public:
             motorInyeccion(int a, int b, int c, int d):motorACombustion(a, b, c){setnumInyect(d);}
             void setnumInyect(int a){num_inyectores=a;}
             int getnumInyect (){return num_inyectores;}
             void toPrint(){motorACombustion::toPrint(); cout<<"numero de inyectores: "<<num_inyectores<<endl;}
      private:
              int num_inyectores;      
};   
       
main()
{
      motor M(400);
      motorElectrico A(500,300);
      motorACombustion B(200, 3200, 4000);
      motorInyeccion C(140, 4500, 5000, 4);
      
      cout<<"Motor."<<endl;
      M.toPrint();
      cout<<"\nMotor Electrico."<<endl;
      A.toPrint();
      cout<<"\nMotor a Combustion."<<endl;
      B.toPrint();
      cout<<"\nMotor Inyeccion."<<endl;
      C.toPrint();
      system("pause");
}
