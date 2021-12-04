#include <iostream>
#include <vector>
#include "2048.h"
typedef vector<vector<int> > Plateau;
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl
void TestPlatVide() {
    CHECK(plateauVide() == Plateau({{ 0, 0, 0,0 }, { 0, 0, 0 ,0}, { 0, 0, 0,0 }, {0,0,0,0}}) );
}
void TestScore() {
    CHECK(score(16) == 32);
    CHECK(score(0) == 0);
    CHECK(score (2) != 2);
}
void TestScorePlat(){
    CHECK(scorePlat({{4,4,4,2},{8,16,32,2},{4,8,4,32},{4,8,4,2}}) == 172);
    CHECK(scorePlat({{ 0, 0, 0,0 }, { 0, 0, 0 ,0}, { 0, 0, 0,0 }, {0,0,0,0}}) == 0 );
}
void deplacementTest(){
    CHECK(deplacementGauche({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{8,4,2,0},{8,16,32,2},{32,32,0,0},{4,4,0,0}}));
    CHECK(deplacementHaut({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{4,4,4,4},{8,32,32,16},{32,2,2,2},{2,0,0,0}}));
    CHECK(deplacementDroite({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{0,4,8,2},{8,16,32,2},{0,0,32,32},{0,0,4,4}}));
    CHECK(deplacementBas({{4,4,4,2},{8,16,32,2},{32,16,0,16},{2,2,2,2}}) == Plateau({{4,0,0,0},{8,4,4,2},{32,32,32,16},{2,2,2,2}}));
}
