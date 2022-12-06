/*
 * References
 * [1] T. Salhin, "Rotten Tomatoes 400k Movie Reviews," Kaggle.com. Available: https://www.kaggle.com/datasets/talha002/rottentomatoes-400k-review
 * [2] "Numbers with comma format," QTCentre.org. Available: https://www.qtcentre.org/threads/9822-Numbers-with-comma-format
 * [3] S. Mahapatra, "Measure execution time of a function in C++," GeeksForGeeks.org. Available: https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
 * [4] "Customize QtListWidgetItem," QTCentre.org. Available: https://www.qtcentre.org/threads/27777-Customize-QListWidgetItem-how-to
 * [5] QT Wiki, "Converting Strings from and to Camel Case," Wiki.QT.io. Available: https://wiki.qt.io/Converting_Strings_from_and_to_Camel_Case
 * [6] University of Florida, "Slides from Module 6: Sorting."
 */

#include "mainwindow.h"
#include <vector>
#include <sstream>
#include <fstream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Add code here to pull everything from CSV and load into vector
    std::vector<MovieReview*> allReviews;

    std::ifstream inputFile;
    inputFile.open("rottentomatoes-400k.csv");
    if (inputFile.good()) {
        std::cout << "open" << std::endl;
    }
    else std::cout << "not open" << std::endl;

    std::string fileData;

    //clear header line
    getline(inputFile, fileData);
    fileData = "";

    while(getline(inputFile, fileData)) {

        int index = 0;
        std::string titleCSV = "";
        std::string date = "";
        int dayCSV = 0;
        int monthCSV = 0;
        int yearCSV = 0;
        std::string reviewerCSV = "";
        int scoreCSV = 0;
        std::string publishCSV = "";
        std::string reviewCSV = "";
        std::string temp = "";

        std::istringstream line(fileData);

        //Getting the index and not storing it
        getline(line, temp, ',');

        //Getting the title
        getline(line, titleCSV, ',');

        //Getting the reviewer
        getline(line, reviewerCSV, ',');

        //Getting the publisher
        getline(line, publishCSV, ',');

        //Getting the review
        std::string comment;

        getline(line, comment);
        int quotePosOne = comment.find_first_of('"');
        int quotePosTwo = comment.find_last_of('"');
        std::string newReview = "";

        //if there are quotes around the review
        if(quotePosOne != std::string::npos){
            reviewCSV = comment.substr(1, quotePosTwo - 1);
            newReview = comment.substr(quotePosTwo + 2);

            std::istringstream newLine(newReview);

            //Getting the date
            getline(newLine, date, ',');

            int slashOne = date.find_first_of("/");
            int slashTwo = date.find_last_of("/");

            //Splitting the date into day, month, and year
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

            std::istringstream newLine(newReview);

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

//    std::cout << allReviews.size();

    w.setAllReviews(allReviews);

    w.show();

    return a.exec();
}
