#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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
    string publish;
    string review;
    
public:

    MovieReview(string movieTitle, int movieDay, int movieMonth, int movieYear, string movieReviewer, int movieScore, string moviePublish, string movieReview)
    {
        title = movieTitle;
        day = movieDay;
        month = movieMonth;
        year = movieYear;
        reviewer = movieReviewer;
        score = movieScore;
        publish = moviePublish;
        review = movieReview;
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

    string getPublish()
    {
        return publish;
    }
    
    string getReview()
    {
        return review;
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
    ifstream inputFile;
    inputFile.open("rottentomatoes-400k.csv");

    string fileData;

    //clear header line
    getline(inputFile, fileData);
    fileData = "";

    while(getline(inputFile, fileData)){

        int index = 0;
        string titleCSV = "";
        string date = "";
        int dayCSV = 0;
        int monthCSV = 0;
        int yearCSV = 0;
        string reviewerCSV = "";
        int scoreCSV = 0;
        string publishCSV = "";
        string reviewCSV = "";
        string temp = "";

        istringstream line(fileData);

        //Getting the index and not storing it
        getline(line, temp, ',');

        //Getting the title
        getline(line, titleCSV, ',');

        //Getting the reviewer
        getline(line, reviewerCSV, ',');

        //Getting the publisher
        getline(line, publishCSV, ',');

        //Getting the review
        string comment;

        getline(line, comment);
        int quotePosOne = comment.find_first_of('"');
        int quotePosTwo = comment.find_last_of('"');
        string newReview = "";

        //if there are quotes around the review
        if(quotePosOne != string::npos){
            reviewCSV = comment.substr(1, quotePosTwo - 1);
            newReview = comment.substr(quotePosTwo + 2);

            istringstream newLine(newReview);

            //Getting the date
            getline(newLine, date, ',');

            int slashOne = date.find_first_of("/");
            int slashTwo = date.find_last_of("/");
        
            //Splitting the date DD/MM/YYYY into day, month, and year
            dayCSV = atoi(date.substr(0, slashOne).c_str());
            monthCSV = atoi(date.substr(slashOne + 1, slashTwo - 1).c_str());
            yearCSV = atoi(date.substr(slashTwo + 1).c_str());

            //Getting the score
            getline(newLine, temp);
            scoreCSV = atoi(temp.c_str());
        }

        //If there aren't quotes around the reviews -> meaning there are no commas in the reviews
        else{
            int comma = comment.find(',');
            reviewCSV = comment.substr(0, comma);
            newReview = comment.substr(comma + 1);

            istringstream newLine(newReview);

            //Getting the date
            getline(newLine, date, ',');

            int posOne = date.find_first_of("/");
            int posTwo = date.find_last_of("/");
        
            //Splitting the date into day, month, and year
            dayCSV = atoi(date.substr(0, posOne).c_str());
            monthCSV = atoi(date.substr(posOne + 1, posTwo - 1).c_str());
            yearCSV = atoi(date.substr(posTwo + 1).c_str());

            //Getting the score
            getline(newLine, temp);
            scoreCSV = atoi(temp.c_str());
        }

        //Movie Review Constructor is MovieReview (string movieTitle, int movieDay, int movieMonth, int movieYear, string movieReviewer, int movieScore, string moviePublish, string movieReview)
        //Example: allReviews.push_back(new MovieReview("Big Bang", 12, 2, 2013, "Alejandro", 10));
        allReviews.push_back(new MovieReview(titleCSV, dayCSV, monthCSV, yearCSV, reviewerCSV, scoreCSV, publishCSV, reviewCSV));
    }

    string input;
    bool run = true;

    // Add code here to go through CSV and store matching reviews in a vector (maybe 2, one for each sorting algorithm)
    vector<MovieReview*> selectedReviews;

    //Add these for merge sort time and quick sort time
    double msTime;
    double qsTime;

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
        try {
            switch (stoi(input)) {
                case 1:
                    // Call functions here to sort by date (ascending)
                    mergeSortDate(selectedReviews, true, 0, selectedReviews.size()-1);
                    break;
                case 2:
                    // Call functions here to sort by date (descending)
                    mergeSortDate(selectedReviews, false, 0, selectedReviews.size() - 1);
                    break;
                case 3:
                    // Call functions here to sort by reviewer name (ascending)
                    mergeSortReviewer(selectedReviews, true, 0, selectedReviews.size() - 1);
                    break;
                case 4:
                    // Call functions here to sort by reviewer name (descending)
                    mergeSortReviewer(selectedReviews, false, 0, selectedReviews.size() - 1);
                    break;
                case 5:
                    // Call functions here to sort by review score (ascending)
                    mergeSortScore(selectedReviews, true, 0, selectedReviews.size() - 1);
                    break;
                case 6:
                    // Call functions here to sort by review score (descending)
                    mergeSortScore(selectedReviews, false, 0, selectedReviews.size() - 1);
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
