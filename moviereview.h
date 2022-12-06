#ifndef MOVIEREVIEW_H
#define MOVIEREVIEW_H

#include <string>
#include <iostream>

class MovieReview
{
private:
    std::string title;
    int day;
    int month;
    int year;
    std::string reviewer;
    int score;
    std::string publish;
    std::string review;

public:

    // Constructor
    MovieReview(std::string movieTitle, int movieDay, int movieMonth, int movieYear, std::string movieReviewer, int movieScore, std::string moviePublish, std::string movieReview);

    // Accessors
    std::string getTitle();
    int getDay();
    int getMonth();
    int getYear();
    std::string getReviewer();
    int getScore();
    std::string getPublish();
    std::string getReview();

    // Debugging
//    void print();
};
#endif // MOVIEREVIEW_H
