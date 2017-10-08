#include <iostream>

using namespace std;

class Triangulo {
protected:
    int lado1;
    int lado2;
    int lado3;
public:
    Triangulo (int i1,int i2,int i3) // constructor
    {
        lado1=i1;
        lado2=i2;
        lado3=i3;
    }
    void setLado1(int i) { lado1=i; }
    int getLado1(){ return lado1;}
    void setLado2(int i) { lado2=i; }
    int getLado2() {return lado2;}
    void setLado3(int i) { lado3=i; }
    int getLado3() {return lado3;}
    int perimetro() {return lado1+lado2+lado3;}
    virtual float base() {return 1.0;}
    virtual float altura() {return 1.0;}
    float superficie() {return base()*altura()/2;}
};

//las definiciones de base y altura son solo a los
//efectos demostrativos. no son los valores correctos

class Equilatero : public Triangulo{
public:
    Equilatero(int i): Triangulo(i,i,i){}
    float base(){ return (float) lado1;}
    float altura() {return (float) lado1;}
};

class Isosceles : public Triangulo{
public: 
    Isosceles(int i, int j): Triangulo(i,i,j){
    }
    float base(){ return (float) lado1;}
    float altura() {return (float) lado3;}
};

int main(int argc, char *argv[]){
    Triangulo t1(2,2,2);
    Equilatero e1(2);
    Isosceles i1(1,2);
    cout<<t1.perimetro()<<"\n";
    cout<<t1.superficie()<<"\n";
    cout<<e1.perimetro()<<"\n";
    cout<<e1.superficie()<<"\n";
    cout<<i1.perimetro()<<"\n";
    cout<<i1.superficie()<<"\n";
    
    system("PAUSE");
    return 0;
}
