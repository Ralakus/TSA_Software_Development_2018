#pragma once

#include "Typedef.hpp"
#include <string>
#include <vector>

class Choice {

    std::string m_Content;
    std::vector<uint8> m_Weights;

public:

    Choice(const std::string& Content) : m_Content(Content) {}
    ~Choice() {}

    const std::vector<uint8>& GetWeights() const { return m_Weights; }

    void AddWeight(uint8 Weight){
        m_Weights.push_back(Weight);
    }

    const std::string& GetContent() const { return m_Content; }


};
