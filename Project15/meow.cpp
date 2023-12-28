#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <iostream>
#include <map>
#include "FSM.h"



int main() {


    std::unordered_set<int> states({ 0,1 });
    int start_state = 0;
    std::unordered_set<int> final_states({ 1 });

    std::pair<int, int> a{ 1,1 };
    std::pair<int, int> b{ 2,2 };

    std::set<std::pair<int, int>> alphabet({ a, b });
    std::map<std::pair<std::pair<int, int>, int>, int> transitions;

    transitions.emplace(std::pair<std::pair<int, int>, int>(a, 0), 1);
    transitions.emplace(std::pair<std::pair<int, int>, int>(a, 1), 0);
    transitions.emplace(std::pair<std::pair<int, int>, int>(b, 0), 1);
    transitions.emplace(std::pair<std::pair<int, int>, int>(b, 1), 0);

    FSM<std::pair<int, int>> fsm(states, start_state, final_states, alphabet, transitions);
    std::vector<std::pair<int, int>> _str1{ b, b, a, a, a };

    if (fsm.run(_str1)) {
        std::cout << "1st True\n\n";
    }
    else {
        std::cout << "1st False\n\n";
    }



    std::unordered_set<int> states2({ 0, 1, 2, 3, 4, 5 });
    int start_state2 = 0;
    std::unordered_set<int> final_states2({ 3 });

    char one = '1';
    char nul = '0';
    char div = '/';

    std::set<char> alphabet2({ one, nul, div });
    std::map<std::pair<char, int>, int> transitions2;



    transitions2.emplace(std::pair<char, int>(nul, 0), 1);
    transitions2.emplace(std::pair<char, int>(one, 0), 1);
    transitions2.emplace(std::pair<char, int>(div, 0), 5);

    transitions2.emplace(std::pair<char, int>(nul, 1), 1);
    transitions2.emplace(std::pair<char, int>(one, 1), 1);
    transitions2.emplace(std::pair<char, int>(div, 1), 4);

    transitions2.emplace(std::pair<char, int>(one, 2), 3);
    transitions2.emplace(std::pair<char, int>(nul, 2), 4);
    transitions2.emplace(std::pair<char, int>(div, 2), 5);

    transitions2.emplace(std::pair<char, int>(nul, 3), 3);
    transitions2.emplace(std::pair<char, int>(one, 3), 5);
    transitions2.emplace(std::pair<char, int>(div, 3), 5);

    transitions2.emplace(std::pair<char, int>(one, 4), 3);
    transitions2.emplace(std::pair<char, int>(nul, 4), 4);
    transitions2.emplace(std::pair<char, int>(div, 4), 5);

    FSM<char> fsm2(states2, start_state2, final_states2, alphabet2, transitions2);
    std::vector<char> _str2{ '0', '1', '0', '/', '0', '1', '0' };

    if (fsm2.run(_str2)) {
        std::cout << "2nd True\n\n";
    }
    else {
        std::cout << "2nd False\n\n";
    }
}
