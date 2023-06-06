#include <iostream>
#include <vector>
#include <algorithm>

int NUM = 3;

struct Candidato {
    std::string nome;
    int posizione;
};

bool confrontaCandidati(const Candidato& a, const Candidato& b) {
    return a.nome < b.nome;
}

void inserisciCandidato(std::vector<Candidato>& elenco, const Candidato& nuovoCandidato) {
    auto posizioneInserimento = std::lower_bound(elenco.begin(), elenco.end(), nuovoCandidato, confrontaCandidati);
    std::cout << " posizione inserimento\n" << nuovoCandidato.posizione << std::endl;
    elenco.insert(posizioneInserimento, nuovoCandidato);
}

void aggiungiCandidato(std::vector<Candidato>& elenco){
    std::string nomeCandidato;
    std::cout << "Inserisci nome candidato: ";
    std::cin >> nomeCandidato;
    inserisciCandidato(elenco, {nomeCandidato, NUM + 1});
    aggiornaPosizioni(elenco);
}

void aggiornaPosizioni(std::vector<Candidato>& elenco){
    for(int i = 0; i <= NUM; i++){
        std::cout << elenco[i];
    }
}

void stampaElenco(const std::vector<Candidato>& elenco) {
    for (const auto& candidato : elenco) {
        std::cout << "Posizione: " << candidato.posizione << ", Nome: " << candidato.nome << std::endl;
    }
}

int schermoMenu(){
    std::cout << "**************************\n";
    std::cout << "* 1. Mostra candidati    *\n";
    std::cout << "* 2. Inserisci candidati *\n";
    std::cout << "*                        *\n";
    std::cout << "* 0. Esci                +\n";
    std::cout << "**************************\n";
    std::cout << "Scelta--> ";
    int scelta;
    std::cin >> scelta;
    return scelta;
}

int main() {
    std::vector<Candidato> elenco;

    // Esempio di elenco iniziale
    elenco.push_back({"Alice", 1});
    elenco.push_back({"Bob", 2});
    elenco.push_back({"Charlie", 3});
    
    int scelta;
    while(true){
        scelta = schermoMenu();
        if(scelta == 1){
            std::cout << "Elenco candidati: " << std::endl;
            stampaElenco(elenco);
        }
        if(scelta == 2){
            aggiungiCandidato(elenco);
        }
        if(scelta == 0){
            break;
        }
        
    }

    
    

    // Aggiunta di nuovi candidati
    /*
    inserisciCandidato(elenco, {"David", 2});
    inserisciCandidato(elenco, {"Eve", 4});
    inserisciCandidato(elenco, {"Frank", 1});

    std::cout << "\nElenco aggiornato:" << std::endl;
    stampaElenco(elenco);*/

    return 0;
}
