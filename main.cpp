#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   

using namespace std;

const int LINHAS = 20;
const int COLUNAS = 20;

int main() {
    srand(time(0));

    cout << "    BEM-VINDO AO MINECRAFT: MUNDO QUADRADO " << endl;
    cout << "\nEscolha o seu objetivo para esta partida:\n";
    cout << "1 - Luz e calor (Coletar 4 gravetos e 2 pedras)\n";
    cout << "2 - Corrida (Coletar 1 fruta e 3 animais)\n";
    cout << "3 - Construcao (Coletar 3 pedras e 4 arvores)\n";
    cout << "Digite o numero da sua escolha: ";
    
    int escolhaObjetivo;
    cin >> escolhaObjetivo;

    int metaGravetos = 0;
    int metaPedras = 0;
    int metaFrutas = 0;
    int metaAnimais = 0;
    int metaArvores = 0;

    switch (escolhaObjetivo) {
        case 1:
            metaGravetos = 4; 
            metaPedras = 2;
            cout << "\nObjetivo selecionado: Luz e calor!\n";
            break;
        case 2:
            metaFrutas = 1; 
            metaAnimais = 3;
            cout << "\nObjetivo selecionado: Corrida!\n";
            break;
        case 3:
            metaPedras = 3; 
            metaArvores = 4;
            cout << "\nObjetivo selecionado: Construcao!\n";
            break;
        default:
            metaGravetos = 4; 
            metaPedras = 2;
            cout << "\nOpcao invalida! Iniciando com o objetivo padrao: Luz e calor.\n";
            break;
    }

    int mapa[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            int sorteio = rand() % 100;

            if (sorteio < 10) {
                mapa[i][j] = 1; 
            } else if (sorteio < 25) {
                mapa[i][j] = 2; 
            } else if (sorteio < 35) {
                mapa[i][j] = 3; 
            } else if (sorteio < 45) {
                mapa[i][j] = 4; 
            } else if (sorteio < 60) {
                mapa[i][j] = 5; 
            } else {
                mapa[i][j] = 0; 
            }
        }
    }

    int jogadorX = 0; 
    int jogadorY = 0; 
    mapa[jogadorX][jogadorY] = 0; 

    int invGravetos = 0;
    int invPedras = 0;
    int invFrutas = 0;
    int invAnimais = 0;
    int invArvores = 0;
    
    int jogoAtivo = 1; 

    while (jogoAtivo == 1) {
        cout << "\n=========================================" << endl;
        cout << " Posicao Atual no Mapa: [" << jogadorX << "][" << jogadorY << "]" << endl;
        cout << " INVENTARIO ATUAL:" << endl;
        cout << " Gravetos: " << invGravetos << " / " << metaGravetos << endl;
        cout << " Pedras:   " << invPedras << " / " << metaPedras << endl;
        cout << " Frutas:   " << invFrutas << " / " << metaFrutas << endl;
        cout << " Animais:  " << invAnimais << " / " << metaAnimais << endl;
        cout << " Arvores:  " << invArvores << " / " << metaArvores << endl;
        cout << "=========================================" << endl;

        cout << "Movimente-se (W: Cima, S: Baixo, A: Esquerda, D: Direita): ";
        char movimento;
        cin >> movimento;

        int proxX = jogadorX;
        int proxY = jogadorY;

        if (movimento == 'w' || movimento == 'W') {
            proxX = proxX - 1;
        } else if (movimento == 's' || movimento == 'S') {
            proxX = proxX + 1;
        } else if (movimento == 'a' || movimento == 'A') {
            proxY = proxY - 1;
        } else if (movimento == 'd' || movimiento == 'D') {
            proxY = proxY + 1;
        } else {
            cout << "Comando invalido! Escolha apenas entre W, A, S ou D." << endl;
        }

        if (proxX >= 0 && proxX < LINHAS && proxY >= 0 && proxY < COLUNAS) {
            jogadorX = proxX;
            jogadorY = proxY;
        } else {
            cout << "Barreira atingida! Nao pode ultrapassar as bordas do world quadrado." << endl;
        }

        int itemAtual = mapa[jogadorX][jogadorY];
        
        if (itemAtual != 0) {
            if (itemAtual == 1) {
                cout << "\n[Encontrado] Voce avistou um Graveto!" << endl;
            } else if (itemAtual == 2) {
                cout << "\n[Encontrado] Voce avistou uma Pedra!" << endl;
            } else if (itemAtual == 3) {
                cout << "\n[Encontrado] Voce avistou uma Fruta!" << endl;
            } else if (itemAtual == 4) {
                cout << "\n[Encontrado] Voce avistou um Animal!" << endl;
            } else if (itemAtual == 5) {
                cout << "\n[Encontrado] Voce avistou uma Arvore!" << endl;
            }

            cout << "Deseja recolher este item para o inventario? (S - Sim / N - Nao): ";
            char coletar;
            cin >> coletar;

            if (coletar == 's' || coletar == 'S') {
                if (itemAtual == 1) {
                    invGravetos = invGravetos + 1;
                } else if (itemAtual == 2) {
                    invPedras = invPedras + 1;
                } else if (itemAtual == 3) {
                    invFrutas = invFrutas + 1;
                } else if (itemAtual == 4) {
                    invAnimais = invAnimais + 1;
                } else if (itemAtual == 5) {
                    invArvores = invArvores + 1;
                }

                mapa[jogadorX][jogadorY] = 0; 
                cout << "Item recolhido com sucesso!" << endl;
            }
        }

        if (invGravetos >= metaGravetos && invPedras >= metaPedras && 
            invFrutas >= metaFrutas && invAnimais >= metaAnimais && 
            invArvores >= metaArvores) {
            
            jogoAtivo = 0; 
        }
    }

    cout << " PARABENS! TODOS OS OBJETIVOS FORAM CUMPRIDOS! " << endl;

    return 0;
}