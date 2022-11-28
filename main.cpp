#include <iostream>
#include <string>

using namespace std;

class MovieReview
{
private:
    string title;
    int day;
    int month;
    int year;
    string reviewer;
    string score;

public:

    MovieReview(string movieTitle, int movieDay, int movieMonth, int movieYear, string movieReviewer, string movieScore)
    {
        title = movieTitle;
        day = movieDay;
        month = movieMonth;
        year = movieYear;
        reviewer = movieReviewer;
        score = movieScore;
    }

    string getTitle()
    {
        return title;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    string getReviewer()
    {
        return reviewer;
    }

    string getScore()
    {
        return score;
    }
};

int main() {

    // Add code here to load CSV into a data structure. Still need to decide on which to use - possibly a map (int reviewID, Node reviewNode);

    string input;
    bool run = true;

    // Add code here to go through CSV and store matching reviews in a vector (maybe 2, one for each sorting algorithm)

    while (run) {
        cout << "Please enter a movie title name." << endl;
        getline(cin, input);

        // Add code here to get all matching nodes from the map and insert into a vector (can use STL structures for this according to project FAQ)

        // Get user input for attribute to sort by
        cout << "How would you like to sort the reviews?\n1. By date, ascending\n2. By date, descending\n3. By reviewer name, ascending\n4. By reviewer name, descending\n5. By review score, ascending\n6. By review score, descending" << std::endl;
        getline(cin, input);
        try {
            switch (stoi(input)) {
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
                    cout << "Invalid input" << endl;
                    return 0;
            }
        }
        catch (invalid_argument& e) {
            cout << "Invalid input" << endl;
            return 0;
        }

        /* Basic pseudocode - will change depending on implementation of the sorting algorithms
        cout << "Data has been sorted. Printing the first 20 reviews:\n";
        for (int i = 0; i < 20; i++) {
            Node review = vec[i];
            cout << ... print all relevant attributes
        }
        cout << "Total number of reviews: " << vec.size(); << "\nMean score of reviews: " << meanScore << endl;
        cout << "Time taken for Quicksort: " << qsTime << "\nTime taken for Merge Sort: " << msTime << endl;
        */


        // Get user input for next step
        cout << "How would you like to proceed?\n1. Search another movie\n2. Bookmark this movie\n3. View my bookmarks\n4. Exit" << endl;
        cin >> input;
        switch(stoi(input)) {
            case 1:
                cin.ignore(1000,'\n');
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
                cout << "Invalid input" << endl;
                return 0;
        }
    }
}
