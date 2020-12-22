#include <string>
#include <vector>
#include <ruc-sci-comp/animate.hpp>

#include "sandpile.h"
#include "make_sandpile.h"


int main(int argc, char **argv)
{
    make_sandpile maker;
    Sandpile sp;

//     if(atoi(argv[1])==1){
//         if(argc!=4){
//             cout<<"invalid parameter!"<<endl;
//             return 0;
//         }else{          
//             sp=maker.generateSandpile(atoi(argv[2]),atoi(argv[3]));
//         }
//     }else if(atoi(argv[1])==2){
//         if(argc!=3){
//             cout<<"invalid parameter!"<<endl;
//             return 0;
//         }else{
//             ifstream file(argv[2]);
//             sp=maker.readASandpile(file);
//             file.close();
//         }
//     }else{
//         cout<<"invalid parameter!"<<endl;
//         return 0;
//     }

    if(argc==3){
        sp=maker.generateSandpile(atoi(argv[1]),atoi(argv[2]));
    }else if(argc==2){
        ifstream file(argv[1]);
        sp=maker.readASandpile(file);
    }else return 0;
    
    Animation an;
    an.push_back(sp);
    int s=sp.size();
    sandpile sdp;
    while(!sdp.ifStable(sp)){
        Sandpile newSandpile;
        for(int i=0;i<s;i++){
            Row r(s,0);
            newSandpile.push_back(r);
        }
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(sp[i][j]<4){
                    newSandpile[i][j]+=sp[i][j];
                }else{
                    newSandpile[i][j]+=(sp[i][j]-4);
                    if(i>0)newSandpile[i-1][j]++;
                    if(j>0)newSandpile[i][j-1]++;
                    if(i<s-1)newSandpile[i+1][j]++;
                    if(j<s-1)newSandpile[i][j+1]++;
                }
            }
        }
        an.push_back(newSandpile);
        sp=newSandpile;
    }
    animate(an);
}
