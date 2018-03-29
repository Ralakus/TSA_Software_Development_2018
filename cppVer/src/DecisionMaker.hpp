#pragma once

#include "Singleton.hpp"
#include "Typedef.hpp"
#include "Choice.hpp"

#include <vector>

class DecisionMaker : public Singleton < DecisionMaker > {

    std::vector<Choice> m_Choices;

    std::vector<std::string> m_Criteria;

    std::string m_Problem;

public:

    DecisionMaker()   {}
    ~DecisionMaker() {}

    void SetProblem(const std::string& Problem) { m_Problem = Problem; }

    const std::string& GetProblem() const { return m_Problem; }




    Choice& AddChoice(const std::string Content){
        m_Choices.emplace_back(Content);
        return m_Choices.back();
    }

    const std::vector<Choice>& GetChoices() const {
        return m_Choices;
    }




    void AddCriteria(const std::string& Criteria){
        m_Criteria.push_back(Criteria);
    }

    const std::vector<std::string>& GetCriteria() const{
        return m_Criteria;
    }



    Choice* GetBestChoice() {
        size_t Index = 0;
        uint32 Highest = 0;
        Choice* Best = nullptr;

        size_t i = 0;
        for(auto&& Choice : m_Choices){
            i++;
            uint32 Total = 0;
            for(auto Weight : Choice.GetWeights()){
                Total += Weight;
            }
            if(Total > Highest){
                Highest = Total;
                Best = &Choice;
                Index = i;
            }
        }

        return Best;


    }


};
