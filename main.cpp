
#include <iostream>
#include <string>
#include <vector>


using namespace std;

float evaluaPostfija(string &ex){
    vector<float> datos;
    int i=0;
    while(ex[i]!='\0'){
        
        if((ex[i]!='*') && (ex[i]!='+') && (ex[i]!='-') && (ex[i]!='/') && (ex[i]!=' '))
            datos.push_back((float) (ex[i]-48));
        else{
            if(ex[i]=='*'){
               float oper2=datos.back();
               datos.pop_back();
               float oper1=datos.back();
               datos.pop_back();
               datos.push_back(oper1*oper2);
            }
            if(ex[i]=='/'){
               float oper2=datos.back();
               datos.pop_back();
               float oper1=datos.back();
               datos.pop_back();
               datos.push_back(oper1/oper2);
            }            
            if(ex[i]=='+'){
               float oper2=datos.back();
               datos.pop_back();
               float oper1=datos.back();
               datos.pop_back();
               datos.push_back(oper1+oper2);
            }     
            if(ex[i]=='-'){
               float oper2=datos.back();
               datos.pop_back();
               float oper1=datos.back();
               datos.pop_back();
               datos.push_back(oper1-oper2);
            }                 
        }
        i++;
    }
    float valor=datos.back();
    datos.pop_back();
    return valor;

    return 0;
}


int main(int argc, char** argv) {
    string ex="2 2 3 4 * + *";
    string ex1="2 3 4 * +";
    cout<<evaluaPostfija(ex)<<endl;
    cout<<evaluaPostfija(ex1);

    return 0;
}

