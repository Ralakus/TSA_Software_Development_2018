#include <iostream>
#include <algorithm>

#include "DecisionMaker.hpp"

int main(){

    std::string InStr;
    std::string WorkingStr;
    uint32 IteratorVar = 0;
    uint8 WorkingUint8 = 0;

    std::cout << "Enter your problem: ";

    std::getline(std::cin, InStr);

    DecisionMaker::Instance().SetProblem(InStr);

    std::cout << "Problem is: \"" << InStr << "\"" << std::endl;

    std::cout << std::endl << "Enter your list of criteria that the problem has" << std::endl << "Type \"done\" when you're finished entering your criteria" << std::endl << std::endl;

    InStr.clear();

    while(![&]() -> bool {

        IteratorVar++;

        std::cout << "Criteria " << IteratorVar << ":" << std::endl;

        std::getline(std::cin, InStr);

        WorkingStr = InStr;

        std::transform(WorkingStr.begin(), WorkingStr.end(), WorkingStr.begin(), ::tolower);

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

        std::transform(WorkingStr.begin(), WorkingStr.end(), WorkingStr.begin(), ::tolower);

        if(WorkingStr == "done" && DecisionMaker::Instance().GetChoices().size() > 0){
            return true;
        }
        else{
            std::string ChoiceString = InStr;
            for(size_t i = 0; i < DecisionMaker::Instance().GetCriteria().size(); i++){
                DecisionMaker::Instance().AddChoice(InStr).AddWeight([&]() -> uint8 {

                    std::cout << "Enter how well \"" << ChoiceString << "\" fits criteria \"" << DecisionMaker::Instance().GetCriteria()[i] << "\"" << std::endl;

                    while(![&]()->bool{
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

    std::cout << std::endl << "Best choice is \"" << DecisionMaker::Instance().GetBestChoice()->GetContent() << "\" for \"" << DecisionMaker::Instance().GetProblem() << "\"" << std::endl;

    return 0;

}
