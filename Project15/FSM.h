#pragma once
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

template<typename T>
class FSM {
public:
    std::unordered_set<int> states;
    int start_state;
    int cur_state;
    std::unordered_set<int> final_states;
    std::set<T> alphabet;
    std::map<std::pair<T, int>, int> transitions;

    FSM(std::unordered_set<int> _states,
        int _start_state,
        std::unordered_set<int> _final_states,
        std::set<T> _alphabet,
        std::map<std::pair<T, int>, int> _transitions) {

        states = _states;
        start_state = _start_state;
        final_states = _final_states;
        alphabet = _alphabet;
        transitions = _transitions;
    };

    bool run(std::vector<T> str) {
        cur_state = start_state;
        for (int i = 0; i < str.size(); i++) {
            if (alphabet.count(str[i]) == 0) {
                return false;
            }
            std::pair<T, int> state_and_symbol{ str[i], cur_state };
            auto n = transitions.find(state_and_symbol);
            if (n != transitions.end()) {
                cur_state = n->second;
            }
            else {
                return false;
            }

        }
        if (final_states.count(cur_state) == 0) {
            return false;
        }
        return true;
    };
};