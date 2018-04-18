#include <iostream>
#include <algorithm>
#include <string>

#include "DecisionMaker.hpp"

int main(){

    //Create variables that will be used quite commonly
    std::string InStr;
    std::string WorkingStr;
    uint32 IteratorVar = 0;
    uint8 WorkingUint8 = 0;
    //==========================

    //Takes in and repeats problem
    std::cout << "Enter your problem: ";

    std::getline(std::cin, InStr);

    DecisionMaker::Instance().SetProblem(InStr);

    std::cout << "Problem is: \"" << InStr << "\"" << std::endl;
    //==========================

    std::cout << std::endl << "Enter your list of criteria that the problem has" << std::endl << "Type \"done\" when you're finished entering your criteria" << std::endl << std::endl;

    InStr.clear();

    while(![&]() -> bool { //Boolean lambda that takes in input for each criteria

        IteratorVar++;

        std::cout << "Criteria " << IteratorVar << ":" << std::endl;

        std::getline(std::cin, InStr);

        WorkingStr = InStr;

        std::transform(WorkingStr.begin(), WorkingStr.end(), WorkingStr.begin(), ::tolower); //Makes all characters in WorkingStr lowercase to decasesensitize it

        if(WorkingStr == "done" && DecisionMaker::Instance().GetCriteria().size() > 0){
            return true;
        }
        else{
            DecisionMaker::Instance().AddCriteria(InStr);
        }


        return false;

    }());

    std::cout << std::endl << "Enter your choices and how well they meet each criteria on a scale of 1 to 100" << std::endl << "Type \"done\" when you're finished entering your choices" << std::endl << std::endl;

    IteratorVar = 0;

    while(![&]() -> bool {

        IteratorVar++;

        std::cout << "Choice " << IteratorVar << ":" << std::endl;

        std::getline(std::cin, InStr);

        WorkingStr = InStr;

        std::transform(WorkingStr.begin(), WorkingStr.end(), WorkingStr.begin(), ::tolower);//Makes all characters in WorkingStr lowercase to decasesensitize it

        if(WorkingStr == "done" && DecisionMaker::Instance().GetChoices().size() > 0){
            return true;
        }
        else{
            std::string ChoiceString = InStr;
            DecisionMaker::Instance().AddChoice(InStr);
            for(size_t i = 0; i < DecisionMaker::Instance().GetCriteria().size(); i++){ //Loop that loops through all the criteria after entering a choice to get the weights
                DecisionMaker::Instance().GetChoices().back().AddWeight([&]() -> uint8 { //uint8 Lambda that gets weight value

                    std::cout << "Enter how well \"" << ChoiceString << "\" fits criteria \"" << DecisionMaker::Instance().GetCriteria()[i] << "\"" << std::endl;

                    while(![&]()->bool{ //Boolean Lambda that gets input
                        std::getline(std::cin, InStr);
                        try {
                            WorkingUint8 = std::stoul(InStr);
                            if (WorkingUint8 > 100) {
                                std::cout << "Enter a number between 0 - 100" << std::endl;
                                return false;
                            }
                            else if(WorkingUint8 < 0){
                                std::cout << "Enter a number between 0 - 100" << std::endl;
                                return false;
                            }
                            else {
                                return true;
                            }
                        }
                        catch (...) {
                            std::cout << "Enter an integer." << std::endl;
                            return false;
                        }
                    }());

                    return WorkingUint8;

                }());
            }
            return false;
        }

        return false;

    }());

    std::cout << std::endl << "Best choice is \"" << DecisionMaker::Instance().GetBestChoice()->GetContent() << "\" for \"" << DecisionMaker::Instance().GetProblem() << "\"" << std::endl << "Press enter to close..." << std::endl;

    std::cin.get();

    return 0;

}
