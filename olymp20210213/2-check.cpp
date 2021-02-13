#include <vector>
#include <iostream>

void CountCombinationsToGetPlaces(std::vector<bool>& places, int& combinations) {
    size_t start_segment = 0;
    size_t finish_segment = 0;
    bool no_choices = true;
    while (true) {
        while (start_segment < places.size() && !places[start_segment]) {
            ++start_segment;
        }
        if (start_segment == places.size()) {
            break;
        }
        finish_segment = start_segment + 1;
        while (finish_segment < places.size() && places[finish_segment]) {
            ++finish_segment;
        }
        std::vector<size_t> choices;
        if (start_segment < finish_segment) {
            choices.push_back(start_segment);
        }
        if (start_segment + 1 < finish_segment) {
            choices.push_back(finish_segment - 1);
        }
        if (start_segment + 2 < finish_segment) {
            choices.push_back((start_segment + finish_segment - 1) / 2);
        }
        for (size_t choice : choices) {
            no_choices = false;
            places[choice] = false;
            CountCombinationsToGetPlaces(places, combinations);
            places[choice] = true;
        }
        start_segment = finish_segment;
    }
    if (no_choices) {
        ++combinations;
    }
}

int main() {
    for (size_t places_count : std::vector<size_t>{4, 5, 9, 10}) {
        int combinations = 0;
        std::vector<bool> places(places_count, true);
        CountCombinationsToGetPlaces(places, combinations);
        std::cout << "answer for " << places_count << " is " << combinations << std::endl;
    }
    return 0;
}
