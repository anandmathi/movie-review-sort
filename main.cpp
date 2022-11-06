#include <iostream>

int main() {
    // Add code here to load CSV into a data structure. Still need to decide on which to use - possibly a map (int reviewID, Node reviewNode);

    std::string input;
    bool run = true;

    // Add code here to go through CSV and store matching reviews in a vector (maybe 2, one for each sorting algorithm)

    while (run) {
        std::cout << "Please enter a movie title name." << std::endl;
        std::getline(std::cin, input);

        // Add code here to get all matching nodes from the map and insert into a vector (can use STL structures for this according to project FAQ)

        // Get user input for attribute to sort by
        std::cout << "How would you like to sort the reviews?\n1. By date, ascending\n2. By date, descending\n3. By reviewer name, ascending\n4. By reviewer name, descending\n5. By review score, ascending\n6. By review score, descending" << std::endl;
        std::getline(std::cin, input);
        try {
            switch (std::stoi(input)) {
                case 1:
                    // Call functions here to sort by date (ascending)
                    break;
                case 2:
                    // Call functions here to sort by date (descending)
                    break;
                case 3:
                    // Call functions here to sort by reviewer name (ascending)
                    break;
                case 4:
                    // Call functions here to sort by reviewer name (descending)
                    break;
                case 5:
                    // Call functions here to sort by review score (ascending)
                    break;
                case 6:
                    // Call functions here to sort by review score (descending)
                    break;
                default:
                    std::cout << "Invalid input" << std::endl;
                    return 0;
            }
        }
        catch (std::invalid_argument& e) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        }

        /* Basic pseudocode - will change depending on implementation of the sorting algorithms
        std::cout << "Data has been sorted. Printing the first 20 reviews:\n";
        for (int i = 0; i < 20; i++) {
            Node review = vec[i];
            std::cout << ... print all relevant attributes
        }
        std::cout << "Total number of reviews: " << vec.size(); << "\nMean score of reviews: " << meanScore << std::endl;
        std::cout << "Time taken for Quicksort: " << qsTime << "\nTime taken for Merge Sort: " << msTime << std::endl;
        */


        // Get user input for next step
        std::cout << "How would you like to proceed?\n1. Search another movie\n2. Bookmark this movie\n3. View my bookmarks\n4. Exit" << std::endl;
        std::cin >> input;
        switch(std::stoi(input)) {
            case 1:
                std::cin.ignore(1000,'\n');
                continue;
            case 2:
                // Add code here to push review node to vector of bookmarks
                break;
            case 3:
                // Add code here to print vector of bookmarks w/ relevant info
                break;
            case 4:
                run = false;
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                return 0;
        }
    }
}
