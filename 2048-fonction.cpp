#include <vector>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "2048.h"
#include "color.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define esc 27
using namespace std;
typedef vector<vector<int> > Plateau;
int score(int a) {
    vector<int> n(a + 1);
    n[4] = 4;
    for (int i = 8; i <= a; i = i * 2) {
        n[i] = 2 * n[i / 2] + i;
    }
    return n[a];
}
int scorePlat(const Plateau& plateau) {
    int SCORE = 0;
    for (const auto& i : plateau) {
        for (auto v : i) {
            if (v == 0 or v == 2) {
                SCORE = SCORE + 0;
            }
            else {
                SCORE = SCORE + score(v);
            }
        }
    }
    return SCORE;
}
int aleaint(int a, int b) {
    return rand() % (b - a + 1) + a;
}
Plateau plateauVide() {
    Plateau PlatVide;
    PlatVide = Plateau(4);
    for (auto & i : PlatVide) {
        i = { 0,0,0,0 };
    }
    return PlatVide;
}
int tireDeuxOuQuatre() {
    vector<int> D;
    D = { 2,2,2,2,2,2,2,2,2,4 };
    int v = D[aleaint(0, 9)];
    return v;
}
Plateau plateauInitial() {
    Plateau platInitial = plateauVide();
    int v = aleaint(0, 3);
    int u = aleaint(0, 3);
    platInitial[v][u] = tireDeuxOuQuatre();
    int c = aleaint(0, 3);
    int k = aleaint(0, 3);
    while (v == c and u == k) {
        c = aleaint(0, 3);
        k = aleaint(0, 3);
    }
    platInitial[c][k] = tireDeuxOuQuatre();
    return platInitial;
}
Plateau deplacementGauche(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size(); i++) {
            for (int v = 0; v < plateau[0].size() - 1; v++) {
                if (plateau[i][v] == 0 and plateau[i][v + 1] != 0) {
                    plateau[i][v] = plateau[i][v + 1];
                    plateau[i][v + 1] = 0;
                }
            }
        }
    }
    for (int g = 0; g < plateau.size(); g++) {
        for (int q = 0; q < plateau[0].size() - 1; q++) {
            if (plateau[g][q] == plateau[g][q + 1]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g][q + 1] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 0; v < plateau[0].size() - 1; v++) {
            if (plateau[i][v] == 0 and plateau[i][v + 1] != 0) {
                plateau[i][v] = plateau[i][v + 1];
                plateau[i][v + 1] = 0;
            }
        }
    }
    return plateau;
}
Plateau deplacementDroite(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size(); i++) {
            for (int v = 3; v > 0; v--) {
                if (plateau[i][v] == 0 and plateau[i][v - 1] != 0) {
                    plateau[i][v] = plateau[i][v - 1];
                    plateau[i][v - 1] = 0;
                }
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 3; v > 0; v--) {
            if (plateau[i][v] == plateau[i][v - 1]) {
                plateau[i][v] = 2 * plateau[i][v];
                plateau[i][v - 1] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 3; v > 0; v--) {
            if (plateau[i][v] == 0 and plateau[i][v - 1] != 0) {
                plateau[i][v] = plateau[i][v - 1];
                plateau[i][v - 1] = 0;
            }
        }
    }
    return plateau;
}
Plateau deplacementHaut(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size() - 1; i++) {
            for (int v = 0; v < plateau[0].size(); v++) {
                if (plateau[i][v] == 0 and plateau[i + 1][v] != 0) {
                    plateau[i][v] = plateau[i + 1][v];
                    plateau[i + 1][v] = 0;
                }
            }
        }
    }
    for (int g = 0; g < plateau.size() - 1; g++) {
        for (int q = 0; q < plateau[0].size(); q++) {
            if (plateau[g][q] == plateau[g + 1][q]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g + 1][q] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size() - 1; i++) {
        for (int v = 0; v < plateau[0].size(); v++) {
            if (plateau[i][v] == 0 and plateau[i + 1][v] != 0) {
                plateau[i][v] = plateau[i + 1][v];
                plateau[i + 1][v] = 0;
            }
        }
    }
    return plateau;
}
Plateau deplacementBas(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 3; i > 0; i--) {
            for (int v = 0; v < plateau[0].size(); v++) {
                if (plateau[i][v] == 0 and plateau[i - 1][v] != 0) {
                    plateau[i][v] = plateau[i - 1][v];
                    plateau[i - 1][v] = 0;
                }
            }
        }
    }
    for (int g = 3; g > 0; g--) {
        for (int q = 0; q < plateau[0].size(); q++) {
            if (plateau[g][q] == plateau[g - 1][q]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g - 1][q] = 0;
            }
        }
    }
    for (int i = 3; i > 0; i--) {
        for (int v = 0; v < plateau[0].size(); v++) {
            if (plateau[i][v] == 0 and plateau[i - 1][v] != 0) {
                plateau[i][v] = plateau[i - 1][v];
                plateau[i - 1][v] = 0;
            }
        }
    }
    return plateau;
}
Plateau deplacement(const Plateau& plateau) {
    int c = 0;
    while(true)
    {
        switch((c=getch())) {
            case KEY_UP:
                return deplacementHaut(plateau);
            case KEY_DOWN:
                return deplacementBas(plateau);
            case KEY_LEFT:
                return deplacementGauche(plateau);
            case KEY_RIGHT:
                return deplacementDroite(plateau);
            case esc:
                exit(-1);
            default:
                break;
        }
    }

}
void afficheScore(int a){
    console::sp sp = console::sp();
    sp.output(to_string(a), console::WHITE, console::PURPLE);
}
void afficheString(string s){
    console::sp sp = console::sp();
    sp.output(s, console::WHITE, console::PURPLE);
}
void dessine( Plateau p) {
    console::sp sp = console::sp();
    int max = 0;
    string lettre;
    string NombreEtoile;
    for (const auto& i : p) {
        for (int d : i) {
            if (max < d) {
                max = d;
            }
        }
    }
    lettre = to_string(max);
    int ChiffreMax = lettre.size();
    for (int i = 0; i < 1 + ((ChiffreMax + 3) * 4); i = i + 1) {
        NombreEtoile += "*";
        cout << "*";
    }
    cout << endl;
    for (const auto& i : p) {
        cout << "* ";
        for (auto d : i) {
            if(d == 0){
                cout << setw(ChiffreMax) << " " << " * ";
            }
            if(d == 2) {
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::SNOW, console::RED);
                cout << " * ";
            }else if( d == 4){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::SNOW, console::BLUE);
                cout << " * ";
            }else if(d == 8){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::SNOW, console::GREEN);
                cout << " * ";
            }else if (d == 16){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::BLACK, console::BEIGE);
                cout << " * ";
            }else if (d == 32){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::BLACK, console::PINK);
                cout << " * ";
            }else if (d == 64){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::BLACK, console::CYAN);
                cout << " * ";
            }
            else if( d >64){
                cout << setw(ChiffreMax);
                sp.output(to_string(d), console::BLACK, console::WHITE);
                cout << " * ";
            }
        }
        cout << endl;
        cout << NombreEtoile << endl;
    }
}
bool estTermine(const Plateau& plateau) {
    Plateau droit = deplacementDroite(plateau);
    Plateau gauche = deplacementGauche(plateau);
    Plateau bas = deplacementBas(plateau);
    Plateau haut = deplacementHaut(plateau);

    if (plateau == droit and plateau == gauche and plateau == haut and plateau ==bas) {
        return true;
    }
    return false;
}
bool estGagnant(Plateau plateau) {
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            if (plateau[i][k] == 2048) {
                return true;
            }
        }
    }
    return false;
}
bool continueajouer(){
    int c;
    c = getch();
    if(c == 121){
        return true;
    }else{
        return false;
    }
}
Plateau deplacementAleatoire(Plateau plateau1){
    int x;
    x = aleaint(0,3);
    switch(x){
        case 0 :
            plateau1 = deplacementGauche(plateau1);
            break;
        case 1 :
            plateau1 = deplacementDroite(plateau1);
            break;
        case 2 :
            plateau1 = deplacementBas(plateau1);
            break;
        case 3 :
            plateau1 = deplacementHaut(plateau1);
            break;
        default :
            exit(-1);
    }
    return plateau1;
}
bool estPlein(Plateau plateau1) {
    for (auto i: plateau1) {
        for (auto v: i)
            if (v == 0) {
                return true;
            }
    }
    return false;
}
void iaplateau(Plateau plateau1) {
    while (not estTermine(plateau1)) {
        dessine(plateau1) ;
        Plateau gauche = deplacementGauche(plateau1);
        Plateau droite = deplacementDroite(plateau1);
        Plateau haut = deplacementHaut(plateau1);
        Plateau bas = deplacementBas(plateau1);
        int scoredroite = 0;
        int scoregauche = 0;
        int scorebas = 0;
        int scorehaut = 0;
        for (int i = 0; i < 300; i++) {
            while (not estTermine(gauche)) {
                Plateau Bis = gauche;
                gauche = deplacementAleatoire(gauche);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (gauche != Bis ) {
                    while (gauche[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    gauche[p][y] = w;
                }
            }
            scoregauche = scoregauche + scorePlat(gauche);
            gauche = deplacementGauche(plateau1);
        }
        for (int i2 = 0; i2 < 300; i2++) {
            while (not estTermine(droite)) {
                Plateau Bis = droite;
                droite = deplacementAleatoire(droite);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (droite != Bis ) {
                    while (droite[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    droite[p][y] = w;
                }
            }
            scoredroite = scoredroite+ scorePlat(droite);
            droite = deplacementDroite(plateau1);
        }
        for (int i3 = 0; i3 < 300; i3++) {
            while (not estTermine(bas)) {
                Plateau Bis = bas;
                bas = deplacementAleatoire(bas);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (bas != Bis ) {
                    while (bas[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    bas[p][y] = w;
                }
            }
            scorebas= scorebas + scorePlat(bas);
            bas = deplacementBas(plateau1);
        }
        for (int i4 = 0; i4 < 300; i4++) {
            while (not estTermine(haut)) {
                Plateau Bis = haut;
                haut = deplacementAleatoire(haut);
                int w = tireDeuxOuQuatre();
                int p = aleaint(0, 3);
                int y = aleaint(0, 3);
                if (haut != Bis ) {
                    while (haut[p][y] != 0) {
                        p = aleaint(0, 3);
                        y = aleaint(0, 3);
                    }
                    haut[p][y] = w;
                }
            }
            scorehaut= scorehaut + scorePlat(haut);
            haut = deplacementHaut(plateau1);

        }
        if (scorehaut >= scoregauche and scorehaut >= scorebas and scorehaut >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau  p5 = plateau1;
            plateau1 = deplacementHaut(plateau1);
            if (p5 == plateau1){
                if(scoredroite >= scoregauche and scoredroite >= scorebas){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorebas >= scoregauche and scorebas >= scoredroite){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scoregauche >= scorebas and scoregauche >= scoredroite){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scorebas >= scoregauche and scorebas >= scorehaut and scorebas >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p = plateau1;
            plateau1 = deplacementBas(plateau1);
            if (p == plateau1){
                if(scoredroite >= scorehaut and scoredroite >= scoregauche){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorehaut >= scoregauche and scorehaut >= scoredroite){
                    plateau1 = deplacementHaut(plateau1);
                }else if ( scoregauche >= scorehaut and scoregauche >= scoredroite){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scoregauche >= scorehaut and scoregauche >= scorebas and scoregauche >= scoredroite) {
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau  p2 = plateau1;
            plateau1 = deplacementGauche(plateau1);
            if (p2 == plateau1){
                if(scoredroite >= scorehaut and scoredroite >= scorebas){
                    plateau1 = deplacementDroite(plateau1);
                }else if (scorebas >= scorehaut and scorebas >= scoredroite){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scorehaut >= scorebas and scorehaut >= scoredroite){
                    plateau1 = deplacementHaut(plateau1);
                }
            }
            if(estTermine(plateau1)){
                exit(-1);
            }
            while (plateau1[s][c] != 0) {
                if(not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        } else if (scoredroite >= scoregauche and scoredroite >= scorebas and scoredroite >= scorehaut){
            int q = tireDeuxOuQuatre();
            int s = aleaint(0, 3);
            int c = aleaint(0, 3);
            Plateau p3 = plateau1;
            plateau1 = deplacementDroite(plateau1);
            if (p3 == plateau1){
                if(scorehaut >= scoregauche and scorehaut >= scorebas){
                    plateau1 = deplacementHaut(plateau1);
                }else if (scorebas >= scoregauche and scorebas >= scorehaut){
                    plateau1 = deplacementBas(plateau1);
                }else if ( scoregauche >= scorebas and scoregauche >= scorehaut){
                    plateau1 = deplacementGauche(plateau1);
                }
            }
            while (plateau1[s][c] != 0) {
                if( not estPlein(plateau1)){
                    break;
                }
                s = aleaint(0, 3);
                c = aleaint(0, 3);
            }
            plateau1[s][c] = q;
        }
    }
}