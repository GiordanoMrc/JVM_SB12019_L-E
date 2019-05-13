#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "leitor.h"
//#include "exibidor.h"

using namespace std;


int main(int argc,char *argv[]){

    string mode, name;

    if(argc<3){
        cout << "numero de args invalido";


    } else {
        mode = argv[1];
        name = argv[2];     
    }

    if(mode == "-le"){
        cout << mode << "\n" << name ; 
    }
    return 0;
}