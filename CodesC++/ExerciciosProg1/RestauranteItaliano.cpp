#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void cardapio(string nomeItem[35], float precoItem[35]);

int fecharPedido(int mesa[25][36], int numMesa, string nomeItem[35], float precoItem[35]);

int main(){
    cout << fixed << setprecision(2);
    int cod;
    string nomeItem[35] = {"0", "Ravioli de Queijo", "Fettucine de Camarões", "Cappeleti Recheado", "Espaguete com frutos do mar", "0", "0", "0", "0", "0", "0", "Cerveja Artesanal", "Suco Organico Natural", "Vinho do Porto", "Grappa Italiana", "0", "0", "0", "0", "0", "0",
    "Mousse de Chocolate", "Doce de Nozes", "0", "0", "0", "0", "0", "0", "0", "0", "Espresso Machiato", "Caffe Latte", "Mocca", "Cappuccino"};
    
    float precoItem[35] = {0, 50, 80, 40, 87, 0, 0, 0, 0, 0, 0, 15, 12, 20, 17, 0, 0, 0, 0, 0, 0, 6, 9, 0, 0, 0, 0, 0, 0, 0, 0, 17, 2, 11, 13};
    
    int mesa[25][36] = {0};
    int opc = 1;
    int qtd;
    int outPed = 1;
    int numMesa;
    int teclaTot;
    int invad = 0;    
    char opcC, numMesaC, codC;

    while(opc != 3){
        cout << "1 - Anotar pedido \n 2 - Fechar pedido \n 3 - Finalizar Programa " << endl;
        
        cin >> opcC;
        opc = opcC - '0';
        
        if(opc > 3 || opc < 1){

            cout << "codigo errado" << endl;
            cin.ignore();
            continue;
        }
        
   
        
        
        if(opc == 3){
            return 0;
        }
        
        cout << endl << endl << endl;
        

        cout << "Voltar[-1]" << endl;
        cout << "Informe o numero da mesa: ";
            
        cin >> numMesaC;
        numMesa = numMesaC - '0';
        
        if(numMesa > 25 || numMesa == 0 || numMesa < -1 ){
  
            cout << "codigo errado" << endl;
            continue;
        }
        

        if(numMesa == -1){
            continue;
        }
        
            
        if(opc == 2){
            
            teclaTot = fecharPedido(mesa, numMesa, nomeItem, precoItem);
            
            
            
            if(teclaTot == 2){
                return 0;
            }
            

            for(int i = 0; i < 36; i++){
                mesa[numMesa][i] = 0;
            }
            
            
            
        } 
        
        else if(opc == 1){
            while(outPed == 1){

            cardapio(nomeItem, precoItem);
            
            cout << "Escolha o codigo do pedido: ";
            
            
            cin >> codC;
            cod = codC - '0';
            
            if(cod < 1 || (cod > 4 && cod < 11) || (cod > 14 && cod < 21) || (cod > 22 && cod < 31) || cod > 34 ){

                cout << "ENTRADA INVÁLIDA" << endl << endl;
                cout << "Continuar[1]" << endl;
                
                cin >> invad;
                
                continue;
            }
            
            
            cout << "Quantidade: ";
            
            cin >> qtd;
            
            mesa[numMesa][cod] += qtd;
            
            cout << "Anotar outro pedido? Sim [1]     Nao[2]" << endl;
            
            cin >> outPed;
            
            cout << endl << endl << endl;
            
     
            
            }
            
            outPed = 1;
            
            
        }  
            
    }
}

void cardapio(string nomeItem[35], float precoItem[35]){
    cout << fixed << setprecision(2);
    cout << "Comidas" << endl;
    cout << "** Codigo    Descricão            Valor(R$) **" << endl;
    cout << "** 01 - " << nomeItem[1] << "           - " << precoItem[1] << " **" << endl;
    cout << "** 02 - " << nomeItem[2] << "       - " << precoItem[2] << " **" << endl;
    cout << "** 03 - " << nomeItem[3] << "          - " << precoItem[3] << " **" << endl;
    cout << "** 04 - " << nomeItem[4] << " - " << precoItem[4] << " **" << endl;
    cout << "Bebidas" << endl;
    cout << "** Codigo    Descricao            Valor(R$) **" << endl;
    cout << "** 11 - " << nomeItem[11] << "           - " << precoItem[11] << " **" << endl;
    cout << "** 12 - " << nomeItem[12] << "       - " << precoItem[12] << " **" << endl;
    cout << "** 13 - " << nomeItem[13] << "              - " << precoItem[13] << " **" << endl;
    cout << "** 14 - " << nomeItem[14] << "             - " << precoItem[14] << " **" << endl;
    cout << "Sobremesas" << endl;
    cout << "** Codigo    Descricao            Valor(R$) **" << endl;
    cout << "** 21 - " << nomeItem[21] << "         -  " << precoItem[21] << " **" << endl;
    cout << "** 22 - " << nomeItem[22] << "               -  " << precoItem[22] << " **" << endl;
    cout << "Caffe Espresso" << endl;
    cout << "** Codigo    Descricao            Valor(R$) **" << endl;
    cout << "** 31 - " << nomeItem[31] << "           - " << precoItem[31] << " **" << endl;
    cout << "** 32 - " << nomeItem[32] << "                 -  " << precoItem[32] << " **" << endl;
    cout << "** 33 - " << nomeItem[33] << "                       - " << precoItem[33] << " **" << endl;
    cout << "** 34 - " << nomeItem[34] << "                  - " << precoItem[34] << " **" << endl;
    cout << "**********************************************" << endl;

    
}


int fecharPedido(int mesa[25][36],int numMesa, string nomeItem[35], float precoItem[35]){
    int teclaTot;
    float total = 0;
    
    cout << "NOTA: " << endl << endl;
    
    
    if(mesa[numMesa][1] != 0){
        cout << " " << nomeItem[1] <<" R$" << precoItem[1]  << "             x" << mesa[numMesa][1] << endl;
        total += mesa[numMesa][1] * precoItem[1];
    }
    
    if(mesa[numMesa][2] != 0){
        cout << " " << nomeItem[2] <<" R$" << precoItem[2]  << "         x" << mesa[numMesa][2] << endl;
        total += mesa[numMesa][2] * precoItem[2];
    }    
    
    if(mesa[numMesa][3] != 0){
        cout << " " << nomeItem[3] <<" R$" << precoItem[3]  << "            x" << mesa[numMesa][3] << endl;
        total += mesa[numMesa][3] * precoItem[3];
    }    

    if(mesa[numMesa][4] != 0){
        cout << " " << nomeItem[4] <<" R$" << precoItem[4]  << "   x" << mesa[numMesa][4] << endl;
        total += mesa[numMesa][4] * precoItem[4];
    }
    
    if(mesa[numMesa][11] != 0){
        cout << " " << nomeItem[11] <<" R$" << precoItem[11]  << "             x" << mesa[numMesa][11] << endl;
        total += mesa[numMesa][11] * precoItem[11];
    }    
    
    if(mesa[numMesa][12] != 0){
        cout << " " << nomeItem[12] <<" R$" << precoItem[12]  << "         x" << mesa[numMesa][12] << endl;
        total += mesa[numMesa][12] * precoItem[12];
    }    
    
    if(mesa[numMesa][13] != 0){
        cout << " " << nomeItem[13] <<" R$" << precoItem[13]  << "                x" << mesa[numMesa][13] << endl;
        total += mesa[numMesa][13] * precoItem[13];
    }    
    
    if(mesa[numMesa][14] != 0){
        cout << " " << nomeItem[14] <<" R$" << precoItem[14]  << "               x" << mesa[numMesa][14] << endl;
        total += mesa[numMesa][14] * precoItem[14];
    }    

    if(mesa[numMesa][21] != 0){
        cout << " " << nomeItem[21] <<" R$" << precoItem[21]  << "            x" << mesa[numMesa][21] << endl;
        total += mesa[numMesa][21] * precoItem[21];
    } 
    
    if(mesa[numMesa][22] != 0){
        cout << " " << nomeItem[22] <<" R$" << precoItem[22]  << "                  x" << mesa[numMesa][22] << endl;
        total += mesa[numMesa][22] * precoItem[22];
    }    
    
    if(mesa[numMesa][31] != 0){
        cout << " " << nomeItem[31] <<" R$" << precoItem[31]  << "             x" << mesa[numMesa][31] << endl;
        total += mesa[numMesa][31] * precoItem[31];
    }    
    
    if(mesa[numMesa][32] != 0){
        cout << " " << nomeItem[32] <<" R$" << precoItem[32]  << "                    x" << mesa[numMesa][32] << endl;
        total += mesa[numMesa][32] * precoItem[32];
    }     

    if(mesa[numMesa][33] != 0){
        cout << " " << nomeItem[33] <<" R$" << precoItem[33]  << "                         x" << mesa[numMesa][33] << endl;
        total += mesa[numMesa][33] * precoItem[33];
    }     
    
    if(mesa[numMesa][34] != 0){
        cout << " " << nomeItem[34] <<" R$" << precoItem[34]  << "                    x" << mesa[numMesa][34] << endl;
        total += mesa[numMesa][34] * precoItem[34];
    }     
    cout << endl;
    
    cout << " TOTAL:R$" << total << endl;

    cout << endl << "continuar [1]        sair[2]" << endl;
    cin >> teclaTot;    
        
    return teclaTot;
    
}