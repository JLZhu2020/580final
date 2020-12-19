#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>

#include <random>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#include "make_sandpile.h"


// define a function for generating a random sandpile given a size and count
Sandpile make_sandpile::generateSandpile(int S,int N){
    Sandpile sp;
    for(int i=0;i<S;i++){
        Row r(S,0);
        sp.push_back(r);

    }
    mt19937_64 engine(1337);
    uniform_int_distribution<int> gener(0,S-1);
    for(int i=0;i<N;i++){
        int x=gener(engine);
        int y=gener(engine);
        sp[x][y]++;
    }
    return sp;
}
// define a function for reading a sandpile from a file given its filename
Sandpile make_sandpile::readASandpile(ifstream &file){
    Sandpile sp;
    string buffer="";
    while(getline(file,buffer)){
        istringstream ss(buffer);
        std::copy(std::istream_iterator<int>(ss), {}, std::back_inserter(sp.emplace_back()));
    }
    
    return sp;
}