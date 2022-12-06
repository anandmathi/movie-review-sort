#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <unordered_map>
#include "moviereview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setAllReviews(std::vector<MovieReview*>& revList);

private slots:
    void on_lineEdit_returnPressed();
    void on_ascButton_clicked();
    void on_descButton_clicked();
    void on_searchAgainButton_clicked();

    void on_searchButton_clicked();

    void on_viewListButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void updVectors(QString title);

    // Display info
    QString title;
    int totalScore;
    float meanScore;
    int msTime;
    int qsTime;

    // Sort info
    bool asc; // 1 = ascending, 0 = descending
    enum attribute { recency, name, score };

    // Data structures
    std::vector<MovieReview*> allReviews; // Stores every review from the CSV
    std::vector<MovieReview*> selectedReviewsMerge;
    std::vector<MovieReview*> selectedReviewsQuick;
    std::unordered_map<QString, float> favoriteList;


    // Sorts
    void mergeSortDate(std::vector<MovieReview*> &reviews, bool asc, int low, int high);
    void mergeDates(std::vector<MovieReview*> &reviews, bool asc, int low, int mid, int high);
    void quickSortDate(std::vector<MovieReview*>& reviews, int left, int right, bool asc);
    int partionDate(std::vector<MovieReview*>& reviews, int left, int right, bool asc);

    void mergeSortReviewer(std::vector<MovieReview*>& reviews, bool asc, int low, int high);
    void mergeReviewers(std::vector<MovieReview*>& reviews, bool asc, int low, int mid, int high);
    void quickSortReviewer(std::vector<MovieReview*>& reviews, int left, int right, bool asc);
    int partionReviewer(std::vector<MovieReview*>& reviews, int left, int right, bool asc);

    void mergeSortScore(std::vector<MovieReview*>& reviews, bool asc, int low, int high);
    void mergeScores(std::vector<MovieReview*>& reviews, bool asc, int low, int mid, int high);
    void quickSortScore(std::vector<MovieReview*>& reviews, int left, int right, bool asc);
    int partionScore(std::vector<MovieReview*>& reviews, int left, int right, bool asc);
};

#endif // MAINWINDOW_H
