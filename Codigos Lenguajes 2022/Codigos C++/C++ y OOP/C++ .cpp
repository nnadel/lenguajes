#include <iostream>
#include <fstream>
using namespace std;

int peso_fut, peso_falta, peso_sobre;

class Persona{
    public:
    int peso;
    string nombre;
    void entrenar (void);
    void Comer (void);
    Persona(string name, int kg){
        nombre = name;
        peso = kg;
    };
};
void Persona::entrenar (){
    peso--;
}
void Persona::Comer (){
    peso++;
}

int main(){
    ofstream archivo("datos.txt");
    string name;
    int peso,cEntrenar,cComer;
    cout << "¿Como se llama?\n";
    cin >> name;
    cout << "¿Cuanto pesa en kg?\n";
    cin >> peso;
    Persona user1(name,peso);
    cout<<"¿Cuantas veces vas a entrenar en la semana?\n";
    cin>>cEntrenar;
    cout<<"¿Cuantas veces vas a comer por día?\n";
    cin>>cComer;
    cComer=cComer*7;
    cout<<"¿A que peso quiere llegar?\n";
    cin>>peso_fut;
    for(int i = 0; i<cEntrenar; i++){
        user1.entrenar();
    }
    for(int i = 0; i<cComer; i++){
        user1.Comer();
    }
    
    archivo<<"Usuario: " << name <<"\nSu peso sera: " << user1.peso<<endl;
    
    if(peso_fut > user1.peso){
        peso_falta = peso_fut - user1.peso;
        archivo<<"Para llegar a su peso ideal debe comer: " << peso_falta << " veces mas\n";
    }
    else if (peso_fut == user1.peso){
        archivo<<"Esta en su peso ideal \n";
    }
    else if(peso_fut < user1.peso){
        peso_sobre =  user1.peso - peso_fut;
        archivo<<"Para llegar a su peso ideal debe entrenar: " << peso_sobre << " veces mas\n";
    }
}