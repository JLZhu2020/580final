#include "sandpile.h"

// define a function that takes a Sandpile by reference and returns a bool (to indicate if the Sandpile is stable)
bool sandpile::ifStable(Sandpile sp){
    int s=sp.size();
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(sp[i][j]>3)return false;
        }
    }
    return true;

}