#include "split.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h> 
const double PI = 3.1415926536;
const double R  = 6372.795477598;
    int vez = 0;
using namespace std;
void calcInd();
string acharCidade(int);
// string acharCoord(string cidade);
void acharCoordenadas(string cidade);
void calculoDistancia(string x, string y);
int main(){
    int opc = 0;
    do{
        do{
            cout << "SELECIONE UMA OPÇÃO" << endl;
            cin >> opc;
            if(opc != 1 && opc != 2 && opc != 3){
                cout << "OPÇÃO INVALIDA" << endl;
            }
        }while(opc != 1 && opc != 2 && opc != 3);
        if(opc == 1){
            calcInd();
        }else if(opc == 2){   
        }
    }while(opc != 3);
    return 0;
}

void calcInd(){        //---------CALCULO INDIVIDUAL-------------------
    int cep1, cep2;
    string cidade1, cidade2, coord1, coord2;
    cout << "INFORME O CEP DAS DUAS CIDADES" << endl;
    do{
        cout << "CEP 1: ";
        //cin >> cep1;
        cep1=86350000;
        cidade1 = acharCidade(cep1);
        if(cidade1 == "1"){
            cout << "CEP INVALIDO" << endl;
        }
    }while(cidade1 == "1");
    do{
        cout << "CEP 2: ";
        //cin >> cep2;
        cep2=86300000;
        cidade2 = acharCidade(cep2);
        if(cidade2 == "1"){
            cout << "CEP INVALIDO" << endl;
        }
    }while(cidade2 == "1");   
    cout << cidade1 << " -> " << cidade2;
    // coord1 = acharCoord(cidade1);
    // coord2 = acharCoord(cidade2);
    acharCoordenadas(cidade1);
    acharCoordenadas(cidade2);
    //cout << coord1 << endl << coord2;
}
string acharCidade(int cep){
    fstream arq;
    string aux;
    char minCHAR[50] = {0};
    char maxCHAR[50] = {0};
    char cidadeCHAR[50] = {0};
    arq.open("cep.txt", ios :: in | ios::out);
        while(!arq.eof()){
            getline(arq,aux);
            for(int povi = 0, i = 0, count = 0;povi < 3; i++){
                if(aux[i] == ';'){
                    povi++;
                    count = 0;
                }else if(povi == 1){
                    minCHAR[count] = aux[i];
                    count++;
                }else if(povi == 2){
                    maxCHAR[count] = aux[i];
                    count++;
                }
            }
            int minINT = atoi(minCHAR);
            int maxINT = atoi(maxCHAR);
            if(cep >= minINT && cep <= maxINT){
                for (int i = 0; ;i++){
                    if(aux[i] == ';'){
                        break;
                    }
                    cidadeCHAR[i] = aux[i];
                }
                string str(cidadeCHAR);
                arq.close();
                return str;   
            }   
        }
    arq.close();
    return "1";
}
void acharCoordenadas(string cidade){
    string linha;
    bool encontrei = false;
    
    fstream arqCoordenadas;
    arqCoordenadas.open("coord.txt", ios::in);
    while (arqCoordenadas.good()){
        getline(arqCoordenadas, linha);
        if (linha.size()==0)
            continue;
        vector<string> campos = split(linha, ';');
        string nome = campos[3].c_str();
        if (cidade == nome){
            cout << campos[1] << " " << campos[2] << endl;
            calculoDistancia(campos[1],campos[2]);
            //string cidade = campos[0];
    //return cidade;
            
            encontrei = true;
            break;
        }
    }
    arqCoordenadas.close();
    if (!encontrei){
        cout << "Não encontrei as cordenadas desta cidade." << endl;
    }
}
void calculoDistancia(string x, string y){
    float x0 = stof(x);
    float y0 = stof(y);
    x0 = x0*(PI/180);
    y0 = y0*(PI/180);
    double x1,x2;
    double y1,y2;
    if(vez==0){vez++;
        x1=x0;
        y1=y0;
    }else{
        x2=x0;
        y2=y0;
    double alpha = sin(x1)*sin(x2);
    double beta  = cos(x1)*cos(x2);
    double gamma = cos(y1 - y2);
    double dist = R*(acos(alpha+beta*gamma));
    cout << dist/10 <<" Km"<<endl;
    }
}
// string acharCoord(string cidade){
//     fstream arq;
//     string coord;
//     char coordCHAR[50] = {0};
//     char cidadeCHAR[50] = {0};
//     string cidadeAUX;
//     string aux;
//     arq.open("coord.txt", ios :: in | ios::out);
    
//         while(!arq.eof()){
            
//             getline(arq,aux);
//             for(int povi = 0, i = 0, count = 0;povi < 4; i++){
                
//                 if(aux[i] == ';'){
//                     povi++;
//                 }    
                
//                 else if(povi >= 3 && povi < 4){
//                     cidadeCHAR[count] = aux[i];
//                     count++;
//                 }
//             }
//             string str(cidadeCHAR);
//             cidadeAUX = str;
//             if(cidade == str){
//                 cout << "GOOOO " << endl;
//                 cout << cidade << endl << cidadeAUX << endl;
                
//                 for(int povi = 0, i = 0, count = 0;povi <= 2; i++){
//                     if(aux[i] == ';'){
//                         povi++;
//                     }
//                     else if(povi >= 1 && povi <= 2){
//                         coordCHAR[count] = aux[i];
//                         count++;
//                     }
//                     else if(povi > 2){
//                         break;
//                     }
//                 }     
//             }
//     }
//     cout << coordCHAR << endl;
//     string atr(coordCHAR);
//     arq.close();
//     return atr;
// }