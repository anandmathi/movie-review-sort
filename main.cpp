#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MovieReview
{
private:
    string title;
    int day;
    int month;
    int year;
    string reviewer;
    int score;

public:

    MovieReview(string movieTitle, int movieDay, int movieMonth, int movieYear, string movieReviewer, int movieScore)
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

    int getScore()
    {
        return score;
    }

    void print()
    {
        cout << "Title: " << title + " | Date: " << month << "/" << day << "/" << year << " | Reviewer: " << reviewer << " | Score: " << score << endl;
    }
};

//Debug method
void printReviews(vector<MovieReview*> reviews);

//SortingMethods

//for merge sort, call mergeSortDate. asc is true when the list should be sorted ascending. set low to 0 and high to reviews size - 1
void mergeSortDate(vector<MovieReview*> &reviews, bool asc, int low, int high);
void mergeDates(vector<MovieReview*> &reviews, bool asc, int low, int mid, int high);
void quickSortDate(vector<MovieReview*> reviews, bool asc);

void mergeSortReviewer(vector<MovieReview*>& reviews, bool asc, int low, int high);
void mergeReviewers(vector<MovieReview*>& reviews, bool asc, int low, int mid, int high);
void quickSortReviewer(vector<MovieReview*> reviews, bool asc);

void mergeSortScore(vector<MovieReview*>& reviews, bool asc, int low, int high);
void mergeScores(vector<MovieReview*>& reviews, bool asc, int low, int mid, int high);
void quickSortScore(vector<MovieReview*> reviews, bool asc);

int main() {

    vector<MovieReview*> allReviews;
    // Add code here to load CSV into allReviews
    //Movie Review Constructor is MovieReview(string movieTitle, int movieDay, int movieMonth, int movieYear, string movieReviewer, string movieScore)
    //Example: allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2013, "Alejandro", 10));

    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 213, "A", 100));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 25463, "A", 1000));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 213, "A", 7));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 20435313, "A", 6));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2013, "D", 509));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2014563, "D", 10));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2013, "C", 10));
    allReviews.push_back(new MovieReview("Big Bang", 11, 2, 2013, "A", 10));
    allReviews.push_back(new MovieReview("Big Bang", 10, 4, 2013, "A", 10));
    allReviews.push_back(new MovieReview("Big Bang", 12, 3, 2013, "B", 500));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2013, "G", 10));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 23413, "H", 470));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 201, "E", 470));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2, "A", 10));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 213, "Z", 10));
    allReviews.push_back(new MovieReview("Big Bang", 12, 2, 23, "ZE", 10));

    string input;
    bool run = true;

    // Add code here to go through CSV and store matching reviews in a vector (maybe 2, one for each sorting algorithm)
    vector<MovieReview*> selectedReviews;

    while (run) {
        cout << "Please enter a movie title name." << endl;
        getline(std::cin, input);

        // Add code here to get all matching nodes from the map and insert into a vector (can use STL structures for this according to project FAQ)
        selectedReviews.clear();
        for (int i = 0; i < allReviews.size(); i++)
        {
            if (allReviews.at(i)->getTitle() == input)
            {
                selectedReviews.push_back(allReviews.at(i));
            }
        }

        // Get user input for attribute to sort by
        cout << "How would you like to sort the reviews?\n1. By date, ascending\n2. By date, descending\n3. By reviewer name, ascending\n4. By reviewer name, descending\n5. By review score, ascending\n6. By review score, descending" << endl;
        getline(std::cin, input);
        double msTime;
        double qsTime;
        try {
            switch (stoi(input)) {
                case 1:
                    // Call functions here to sort by date (ascending)
                    mergeSortDate(selectedReviews, true, 0, selectedReviews.size()-1);
                    break;
                case 2:
                    // Call functions here to sort by date (descending)
                    break;
                case 3:
                    // Call functions here to sort by reviewer name (ascending)
                    mergeSortReviewer(selectedReviews, true, 0, selectedReviews.size() - 1);
                    break;
                case 4:
                    // Call functions here to sort by reviewer name (descending)
                    break;
                case 5:
                    // Call functions here to sort by review score (ascending)
                    mergeSortScore(selectedReviews, true, 0, selectedReviews.size() - 1);
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

        cout << "Data has been sorted. Printing the first 20 reviews:\n";
        for (int i = 0; (i < 20) && (i<selectedReviews.size()); i++) {
            selectedReviews.at(i)->print();
        }

        // Get user input for next step
        cout << "How would you like to proceed?\n1. Search another movie\n2. Bookmark this movie\n3. View my bookmarks\n4. Exit" << endl;
        std::cin >> input;
        switch(stoi(input)) {
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
                cout << "Invalid input" << endl;
                return 0;
        }
    }
}

void printReviews(vector<MovieReview*> reviews)
{
    for (int i = 0; i < reviews.size(); i++)
    {
        reviews.at(i)->print();
    }
}

void mergeSortDate(vector<MovieReview*> &reviews, bool asc, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortDate(reviews, asc, low, mid);
    mergeSortDate(reviews, asc, mid + 1, high);
    mergeDates(reviews, asc, low, mid, high);
}

void mergeDates(vector<MovieReview*> &reviews, bool asc, int low, int mid, int high)
{
    //Create temporary vectors
    vector<MovieReview*> left, right;

    //Add corresponding values into vectors
    for (int i = 0; i < mid - low + 1; i++)
    {
        left.push_back(reviews.at(low + i));
    }

    for (int i = 0; i < high-mid; i++)
    {
        right.push_back(reviews.at(mid+i+1));
    }

    int leftIndex = 0, rightIndex = 0;

    //Copy from left and right vectors back into initial vector
    for (int i = low; i < high + 1; i++)
    {
        if ((leftIndex < left.size()) && (rightIndex < right.size()))
        {
            if (left.at(leftIndex)->getYear() < right.at(rightIndex)->getYear())
            {
                if (asc)
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
                else
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
            }
            else if (left.at(leftIndex)->getYear() > right.at(rightIndex)->getYear())
            {
                if (asc)
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
                else
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
            }
            else
            {
                if (left.at(leftIndex)->getMonth() < right.at(rightIndex)->getMonth())
                {
                    if (asc)
                    {
                        reviews.at(i) = left.at(leftIndex);
                        leftIndex++;
                    }
                    else
                    {
                        reviews.at(i) = right.at(rightIndex);
                        rightIndex++;
                    }
                }
                else if (left.at(leftIndex)->getMonth() > right.at(rightIndex)->getMonth())
                {
                    if (asc)
                    {
                        reviews.at(i) = right.at(rightIndex);
                        rightIndex++;
                    }
                    else
                    {
                        reviews.at(i) = left.at(leftIndex);
                        leftIndex++;
                    }
                }
                else
                {
                    if (left.at(leftIndex)->getDay() < right.at(rightIndex)->getDay())
                    {
                        if (asc)
                        {
                            reviews.at(i) = left.at(leftIndex);
                            leftIndex++;
                        }
                        else
                        {
                            reviews.at(i) = right.at(rightIndex);
                            rightIndex++;
                        }
                    }
                    else if (left.at(leftIndex)->getDay() > right.at(rightIndex)->getDay())
                    {
                        if (asc)
                        {
                            reviews.at(i) = right.at(rightIndex);
                            rightIndex++;
                        }
                        else
                        {
                            reviews.at(i) = left.at(leftIndex);
                            leftIndex++;
                        }
                    }
                    else
                    {
                        reviews.at(i) = left.at(leftIndex);
                        leftIndex++;
                    }
                }
            }
        }
        else if (leftIndex < left.size())
        {
            reviews.at(i) = left.at(leftIndex);
            leftIndex++;
        }
        else if(rightIndex < right.size())
        {
            reviews.at(i) = right.at(rightIndex);
            rightIndex++;
        }
    }
}

void quickSortDate(vector<MovieReview*> reviews, bool asc)
{

}

void mergeSortReviewer(vector<MovieReview*>& reviews, bool asc, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortReviewer(reviews, asc, low, mid);
    mergeSortReviewer(reviews, asc, mid + 1, high);
    mergeReviewers(reviews, asc, low, mid, high);
}

void mergeReviewers(vector<MovieReview*>& reviews, bool asc, int low, int mid, int high)
{
    //Create temporary vectors
    vector<MovieReview*> left, right;

    //Add corresponding values into vectors
    for (int i = 0; i < mid - low + 1; i++)
    {
        left.push_back(reviews.at(low + i));
    }

    for (int i = 0; i < high - mid; i++)
    {
        right.push_back(reviews.at(mid + i + 1));
    }

    int leftIndex = 0, rightIndex = 0;

    //Copy from left and right vectors back into initial vector
    for (int i = low; i < high + 1; i++)
    {
        if ((leftIndex < left.size()) && (rightIndex < right.size()))
        {
            if (left.at(leftIndex)->getReviewer() < right.at(rightIndex)->getReviewer())
            {
                if (asc)
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
                else
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
            }
            else if (left.at(leftIndex)->getReviewer() > right.at(rightIndex)->getReviewer())
            {
                if (asc)
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
                else
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
            }
            else
            {
                reviews.at(i) = left.at(leftIndex);
                leftIndex++;
            }
        }
        else if (leftIndex < left.size())
        {
            reviews.at(i) = left.at(leftIndex);
            leftIndex++;
        }
        else if (rightIndex < right.size())
        {
            reviews.at(i) = right.at(rightIndex);
            rightIndex++;
        }
    }
}

void mergeSortScore(vector<MovieReview*>& reviews, bool asc, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortScore(reviews, asc, low, mid);
    mergeSortScore(reviews, asc, mid + 1, high);
    mergeScores(reviews, asc, low, mid, high);
}

void mergeScores(vector<MovieReview*>& reviews, bool asc, int low, int mid, int high)
{
    //Create temporary vectors
    vector<MovieReview*> left, right;

    //Add corresponding values into vectors
    for (int i = 0; i < mid - low + 1; i++)
    {
        left.push_back(reviews.at(low + i));
    }

    for (int i = 0; i < high - mid; i++)
    {
        right.push_back(reviews.at(mid + i + 1));
    }

    int leftIndex = 0, rightIndex = 0;

    //Copy from left and right vectors back into initial vector
    for (int i = low; i < high + 1; i++)
    {
        if ((leftIndex < left.size()) && (rightIndex < right.size()))
        {
            if (left.at(leftIndex)->getScore() < right.at(rightIndex)->getScore())
            {
                if (asc)
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
                else
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
            }
            else if (left.at(leftIndex)->getScore() > right.at(rightIndex)->getScore())
            {
                if (asc)
                {
                    reviews.at(i) = right.at(rightIndex);
                    rightIndex++;
                }
                else
                {
                    reviews.at(i) = left.at(leftIndex);
                    leftIndex++;
                }
            }
            else
            {
                reviews.at(i) = left.at(leftIndex);
                leftIndex++;
            }
        }
        else if (leftIndex < left.size())
        {
            reviews.at(i) = left.at(leftIndex);
            leftIndex++;
        }
        else if (rightIndex < right.size())
        {
            reviews.at(i) = right.at(rightIndex);
            rightIndex++;
        }
    }
}
