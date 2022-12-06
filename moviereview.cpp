#include "moviereview.h"

MovieReview::MovieReview(std::string movieTitle, int movieDay, int movieMonth, int movieYear, std::string movieReviewer, int movieScore, std::string moviePublish, std::string movieReview) {
    title = movieTitle;
    day = movieDay;
    month = movieMonth;
    year = movieYear;
    reviewer = movieReviewer;
    score = movieScore;
    publish = moviePublish;
    review = movieReview;
}

// Accessors
std::string MovieReview::getTitle() {
    return title;
}

int MovieReview::getDay() {
    return day;
}

int MovieReview::getMonth() {
    return month;
}

int MovieReview::getYear() {
    return year;
}

std::string MovieReview::getReviewer() {
    return reviewer;
}

int MovieReview::getScore() {
    return score;
}

std::string MovieReview::getPublish() {
    return publish;
}

std::string MovieReview::getReview() {
    return review;
}

// Debugging
//void MovieReview::print() {
//    std::cout << "Title: " << title + " | Date: " << month << "/" << day << "/" << year << " | Reviewer: " << reviewer << " | Score: " << score << std::endl;
//}
