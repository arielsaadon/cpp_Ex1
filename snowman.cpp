#include "snowman.hpp"

#include <iostream>
#include <string>
#include <array>
#include <stdexcept>
#include <vector>

constexpr int LAST_DIGIT = 10;
constexpr int NUM_OF_PARTS = 8;
constexpr int NUM_OF_OPTION = 4;
constexpr int FIRST_OPTION = 1;

using namespace std;

enum parts {
    Hat,
    Nose,
    LEye,
    REye,
    LArm,
    RArm,
    Torso,
    Base
};

namespace ariel{
    string AddLeftArm(string& snowman,vector<string>& vParts) {
        string LArmPos;
        if (vParts.at(LArm) == "\\") {
            LArmPos += vParts.at(Hat);
            snowman.replace(LArmPos.size(), 1, vParts.at(LArm));
        } else {
            LArmPos += vParts.at(Hat) + vParts.at(LEye) + vParts.at(Nose) + vParts.at(REye);
            snowman.replace(LArmPos.size(), 1, vParts.at(LArm));
        }
        return snowman;
    }

    string AddRightArm(string& snowman,vector<string>& vParts){
        string RArmPos;
        if(vParts.at(RArm) == "/"){
            RArmPos += vParts.at(Hat) + vParts.at(LEye) + vParts.at(Nose) + vParts.at(REye);
            snowman.replace(RArmPos.size() - 2, 1, vParts.at(RArm));
        }else{
            RArmPos += vParts.at(Hat) + vParts.at(LEye) + vParts.at(Nose) + vParts.at(REye) + vParts.at(Torso);
            snowman.replace(RArmPos.size() - 2, 1, vParts.at(RArm));
        }
        return snowman;
    }

    string snowman(int number){
        string snowman;
        vector<int> vNumber;
        vector<string> vParts;

        while (number > 0){
            int digit = number%LAST_DIGIT;
            if(digit > NUM_OF_OPTION || digit < FIRST_OPTION){
                throw invalid_argument("Invalid code " + to_string(digit));
            }
            number /= LAST_DIGIT;
            vNumber.insert(vNumber.begin(), digit);
        }

        if(vNumber.size() != NUM_OF_PARTS){
            throw out_of_range("more or less 8 arguments");
        }

        array<array<string, NUM_OF_OPTION>, NUM_OF_PARTS> snowmanParts = {{
            {" _===_ \n","  ___ \n"" .....\n","   _  \n""  /_\\ \n","  ___ \n"" (_*_) \n"},
            {",",".","_"," "},
            {" (."," (o"," (O"," (-"},
            {".) \n","o) \n","O) \n","-) \n"},
            {"<","\\","/"," "},
            {">","/","\\"," "},
            {" ( : ) \n"," (] [) \n"," (> <) \n"," (   ) \n"},
            {" ( : ) "," (\" \") "," (___) "," (   ) "}
        }};

        //initialization snowman parts to vector
        int pos = 0;
        array<string, NUM_OF_OPTION> PartType;
        for (int& num : vNumber){
            PartType = snowmanParts.at(pos);
            vParts.insert(vParts.end(), PartType.at(num - 1));
            pos++;
        }
        // clang-tidy problem :
        // for(int i = 0 ; i < vNumber.size(); i++){
        //     vParts.insert(vParts.end(), snowmanParts[i][vNumber.at(i)-1]);
        // }

        //Snowman base
        snowman += vParts.at(Hat)+vParts.at(LEye)+vParts.at(Nose)+vParts.at(REye)+vParts.at(Torso)+vParts.at(Base);

        //Options for hands
        snowman = AddLeftArm(snowman,vParts);
        snowman = AddRightArm(snowman,vParts);

        return snowman;
    }
}
