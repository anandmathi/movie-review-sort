#include "mainwindow.h"
#include "listdelegate.h"
#include "./ui_mainwindow.h"
#include <QScrollBar>
#include <chrono>
#include <thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->attributes->hide();
    ui->results->hide();
    ui->favorites->hide();
    ui->resList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {height: 0px;}");
    ui->favList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {height: 0px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Sorts
void MainWindow::mergeSortDate(std::vector<MovieReview*> &reviews, bool asc, int low, int high) {
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortDate(reviews, asc, low, mid);
    mergeSortDate(reviews, asc, mid + 1, high);
    mergeDates(reviews, asc, low, mid, high);
}
void MainWindow::mergeDates(std::vector<MovieReview*> &reviews, bool asc, int low, int mid, int high) {
    //Create temporary vectors
    std::vector<MovieReview*> left, right;

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
        else if (rightIndex < right.size())
        {
            reviews.at(i) = right.at(rightIndex);
            rightIndex++;
        }
    }
}
void MainWindow::quickSortDate(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    if (left < right)
    {

        int pivot = partionDate(reviews, left, right, asc);

        quickSortDate(reviews, left, pivot - 1, asc);
        quickSortDate(reviews, pivot + 1, right, asc);
    }
    else
    {
        return;
    }
}
int MainWindow::partionDate(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    int leftIndex = left;
    int pivot = right;

    for (int i = left; i < right; i++)
    {
        if (asc)
        {
            if (reviews.at(i)->getYear() < reviews.at(pivot)->getYear())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
            else if (reviews.at(i)->getYear() == reviews.at(pivot)->getYear())
            {
                if (reviews.at(i)->getMonth() < reviews.at(pivot)->getMonth())
                {
                    MovieReview* temp = reviews.at(leftIndex);
                    reviews.at(leftIndex) = reviews.at(i);
                    reviews.at(i) = temp;

                    leftIndex++;
                }
                else if (reviews.at(i)->getMonth() == reviews.at(pivot)->getMonth())
                {
                    if (reviews.at(i)->getDay() < reviews.at(pivot)->getDay())
                    {
                        MovieReview* temp = reviews.at(leftIndex);
                        reviews.at(leftIndex) = reviews.at(i);
                        reviews.at(i) = temp;

                        leftIndex++;
                    }
                }
            }
        }
        else
        {
            if (reviews.at(i)->getYear() > reviews.at(pivot)->getYear())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
            else if (reviews.at(i)->getYear() == reviews.at(pivot)->getYear())
            {
                if (reviews.at(i)->getMonth() > reviews.at(pivot)->getMonth())
                {
                    MovieReview* temp = reviews.at(leftIndex);
                    reviews.at(leftIndex) = reviews.at(i);
                    reviews.at(i) = temp;

                    leftIndex++;
                }
                else if (reviews.at(i)->getMonth() == reviews.at(pivot)->getMonth())
                {
                    if (reviews.at(i)->getDay() > reviews.at(pivot)->getDay())
                    {
                        MovieReview* temp = reviews.at(leftIndex);
                        reviews.at(leftIndex) = reviews.at(i);
                        reviews.at(i) = temp;

                        leftIndex++;
                    }
                }
            }
        }
    }

    leftIndex;

    MovieReview* temp = reviews.at(leftIndex);
    reviews.at(leftIndex) = reviews.at(pivot);
    reviews.at(pivot) = temp;

    return leftIndex;
}

void MainWindow::mergeSortReviewer(std::vector<MovieReview*>& reviews, bool asc, int low, int high) {
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortReviewer(reviews, asc, low, mid);
    mergeSortReviewer(reviews, asc, mid + 1, high);
    mergeReviewers(reviews, asc, low, mid, high);
}
void MainWindow::mergeReviewers(std::vector<MovieReview*>& reviews, bool asc, int low, int mid, int high) {
    //Create temporary vectors
    std::vector<MovieReview*> left, right;

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
void MainWindow::quickSortReviewer(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    if (left < right)
    {

        int pivot = partionReviewer(reviews, left, right, asc);

        quickSortReviewer(reviews, left, pivot - 1, asc);
        quickSortReviewer(reviews, pivot + 1, right, asc);
    }
    else
    {
        return;
    }
}
int MainWindow::partionReviewer(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    int leftIndex = left;
    int pivot = right;

    for (int i = left; i < right; i++)
    {
        if (asc)
        {
            if (reviews.at(i)->getReviewer() < reviews.at(pivot)->getReviewer())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
        }
        else
        {
            if (reviews.at(i)->getReviewer() > reviews.at(pivot)->getReviewer())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
        }
    }

    leftIndex;

    MovieReview* temp = reviews.at(leftIndex);
    reviews.at(leftIndex) = reviews.at(pivot);
    reviews.at(pivot) = temp;

    return leftIndex;
}

void MainWindow::mergeSortScore(std::vector<MovieReview*>& reviews, bool asc, int low, int high) {
    if (high <= low)
    {
        return;
    }

    int mid = (low + high) / 2;
    mergeSortScore(reviews, asc, low, mid);
    mergeSortScore(reviews, asc, mid + 1, high);
    mergeScores(reviews, asc, low, mid, high);
}
void MainWindow::mergeScores(std::vector<MovieReview*>& reviews, bool asc, int low, int mid, int high) {
    //Create temporary vectors
    std::vector<MovieReview*> left, right;

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
void MainWindow::quickSortScore(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    if (left < right)
    {

        int pivot = partionScore(reviews, left, right, asc);

        quickSortScore(reviews, left, pivot - 1, asc);
        quickSortScore(reviews, pivot + 1, right, asc);
    }
    else
    {
        return;
    }
}
int MainWindow::partionScore(std::vector<MovieReview*>& reviews, int left, int right, bool asc) {
    int leftIndex = left;
    int pivot = right;

    for (int i = left; i < right; i++)
    {
        if (asc)
        {
            if (reviews.at(i)->getScore() < reviews.at(pivot)->getScore())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
        }
        else
        {
            if (reviews.at(i)->getScore() > reviews.at(pivot)->getScore())
            {
                MovieReview* temp = reviews.at(leftIndex);
                reviews.at(leftIndex) = reviews.at(i);
                reviews.at(i) = temp;

                leftIndex++;
            }
        }
    }

    leftIndex;

    MovieReview* temp = reviews.at(leftIndex);
    reviews.at(leftIndex) = reviews.at(pivot);
    reviews.at(pivot) = temp;

    return leftIndex;
}

// Data structure + visuals management

void MainWindow::setAllReviews(std::vector<MovieReview*>& revList) {
    this->allReviews = revList;
}

void MainWindow::on_lineEdit_returnPressed()
{
    title = ui->lineEdit->text();
    updVectors(title.toUpper());
    if (selectedReviewsMerge.empty()) {
        ui->lineEdit->setText("ERROR: Title not found");
        return;
    }
    // Convert to title case for display
    QStringList parts = title.toLower().split(' ', Qt::SkipEmptyParts);
    for (int i = 0; i < parts.size(); ++i) {
        parts[i].replace(0, 1, parts[i][0].toUpper());
    }
    title = parts.join(" ");
    ui->entry->hide();
    ui->lineEdit->setDisabled(true);
    ui->attributes->show();
    ui->title->setText(title);
}

void MainWindow::updVectors(QString title) {
    // Clear the vectors, then fill with matching titles
    selectedReviewsMerge.clear();
    selectedReviewsQuick.clear();
    for (int i = 0; i < allReviews.size(); i++) {
        if (allReviews[i]->getTitle() == title.toStdString()) {
            selectedReviewsMerge.push_back(allReviews[i]);
            selectedReviewsQuick.push_back(allReviews[i]);
        }
    }
//    std::cout << selectedReviewsMerge.size() << std::endl;
//    std::cout << selectedReviewsQuick.size() << std::endl;
}

// Button slot handling

void MainWindow::on_ascButton_clicked()
{
    ui->attributes->hide();
    // Initialize start/stop for measuring execution time
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    if (ui->buttonGroup->checkedId() == -2) { // Sort by recency
        ui->sortType->setText("Sorted by recency (ascending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortDate(selectedReviewsMerge, true, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortDate(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, true);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    if (ui->buttonGroup->checkedId() == -3) { // Sort by score
        ui->sortType->setText("Sorted by normalized score (ascending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortScore(selectedReviewsMerge, true, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortScore(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, true);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    if (ui->buttonGroup->checkedId() == -4) { // Sort by reviewer name
        ui->sortType->setText("Sorted by reviewer name (ascending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortReviewer(selectedReviewsMerge, true, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortReviewer(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, true);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    totalScore = 0;
    for (int i = 0; i < selectedReviewsMerge.size(); i++) {
        totalScore += selectedReviewsMerge[i]->getScore();
    }
    meanScore = float(totalScore)/selectedReviewsMerge.size();
    for (int i = 0; i < 20; i++) {
        // Present results
        if (i >= selectedReviewsMerge.size()) { // break if index exceeds array size
            break;
        }
        // Create delegate elements to populate the ListView
        ui->resList->setItemDelegate(new ListDelegate(ui->resList));
        ui->resList->setWordWrap(true);
        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
        item->setFlags(item->flags() & Qt::TextWrapAnywhere);
        item->setData(Qt::DisplayRole, "Review by " + QString::fromStdString(selectedReviewsMerge[i]->getReviewer()) + " | " + QString::number(selectedReviewsMerge[i]->getScore()) + "/100 | " + QString::number(selectedReviewsMerge[i]->getMonth()) + "/" + QString::number(selectedReviewsMerge[i]->getDay()) + "/" + QString::number(selectedReviewsMerge[i]->getYear()));
        item->setData(Qt::UserRole + 1, "\"" + QString::fromStdString(selectedReviewsMerge[i]->getReview()) + "\"");
        ui->resList->addItem(item);
    }
    // Display stats
    QString stats = "Total Score: " + QLocale(QLocale::English).toString(totalScore) + " | Mean Score: " + QString::number(meanScore, 'f', 2);
    ui->stats->setText(stats);
    QString stats2 = "QS: " + QLocale(QLocale::English).toString(qsTime) + "ms | MS: " + QLocale(QLocale::English).toString(msTime) + "ms";
    ui->stats_2->setText(stats2);
    ui->results->show();
}

void MainWindow::on_descButton_clicked()
{
    ui->attributes->hide();
    auto start = std::chrono::high_resolution_clock::now();
    auto stop = std::chrono::high_resolution_clock::now();
    if (ui->buttonGroup->checkedId() == -2) { // Sort by recency
        ui->sortType->setText("Sorted by recency (descending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortDate(selectedReviewsMerge, false, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortDate(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, false);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    if (ui->buttonGroup->checkedId() == -3) { // Sort by score
        ui->sortType->setText("Sorted by normalized score (descending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortScore(selectedReviewsMerge, false, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortScore(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, false);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    if (ui->buttonGroup->checkedId() == -4) { // Sort by reviewer name
        ui->sortType->setText("Sorted by reviewer name (descending)");
        start = std::chrono::high_resolution_clock::now();
        mergeSortReviewer(selectedReviewsMerge, false, 0, selectedReviewsMerge.size()-1);
        stop = std::chrono::high_resolution_clock::now();
        msTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
        start = std::chrono::high_resolution_clock::now();
        quickSortReviewer(selectedReviewsQuick, 0, selectedReviewsQuick.size()-1, false);
        stop = std::chrono::high_resolution_clock::now();
        qsTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    }
    totalScore = 0;
    for (int i = 0; i < selectedReviewsMerge.size(); i++) {
        totalScore += selectedReviewsMerge[i]->getScore();
    }
    meanScore = float(totalScore)/selectedReviewsMerge.size();
    for (int i = 0; i < 20; i++) {
        // Present results
        if (i >= selectedReviewsMerge.size()) { // break if index exceeds array size
            break;
        }
        ui->resList->setItemDelegate(new ListDelegate(ui->resList));
        ui->resList->setWordWrap(true);
        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
        item->setFlags(item->flags() & Qt::TextWrapAnywhere);
        item->setSizeHint(QSize(0, 80));
        item->setData(Qt::DisplayRole, "Review by " + QString::fromStdString(selectedReviewsMerge[i]->getReviewer()) + " | " + QString::number(selectedReviewsMerge[i]->getScore()) + "/100 | " + QString::number(selectedReviewsMerge[i]->getMonth()) + "/" + QString::number(selectedReviewsMerge[i]->getDay()) + "/" + QString::number(selectedReviewsMerge[i]->getYear()));
        item->setData(Qt::UserRole + 1, "\"" + QString::fromStdString(selectedReviewsMerge[i]->getReview()) + "\"");
        ui->resList->addItem(item);
    }
    QString stats = "Total Score: " + QLocale(QLocale::English).toString(totalScore) + " | Mean Score: " + QString::number(meanScore, 'f', 2);
    ui->stats->setText(stats);
    // Execution time
    QString stats2 = "QS: " + QLocale(QLocale::English).toString(qsTime) + "ms | MS: " + QLocale(QLocale::English).toString(msTime) + "ms";
    ui->stats_2->setText(stats2);
    ui->results->show();
}

void MainWindow::on_searchAgainButton_clicked()
{
    // Resets every element on the screen
    // Can combine this with the other search button but not a huge deal
    ui->pushButton->setText("♡");
    ui->resList->clear();
    ui->favList->clear();
    ui->results->hide();
    std::vector<MovieReview*> temp;
    selectedReviewsMerge = temp;
    selectedReviewsQuick = temp;
    ui->lineEdit->setDisabled(false);
    ui->entry->show();
}


void MainWindow::on_searchButton_clicked()
{
    // Resets every element on the screen
    ui->pushButton->setText("♡");
    ui->resList->clear();
    ui->favList->clear();
    ui->favorites->hide();
    std::vector<MovieReview*> temp;
    selectedReviewsMerge = temp;
    selectedReviewsQuick = temp;
    ui->lineEdit->setDisabled(false);
    ui->entry->show();
}


void MainWindow::on_viewListButton_clicked()
{
    ui->favorites->show();
    ui->results->hide();
    for (auto iter = favoriteList.begin(); iter != favoriteList.end(); iter++) {
        // Create list item delegates for the ListView and use the map iterator to access relevant data
        ui->favList->setItemDelegate(new ListDelegate(ui->resList));
        ui->favList->setWordWrap(true);
        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
        item->setSizeHint(QSize(0, 40));
        item->setData(Qt::DisplayRole, "  " + iter->first);
        item->setData(Qt::UserRole + 1, "  Mean Score: " + QString::number(iter->second, 'f', 2));
        ui->favList->addItem(item);
    }
}


void MainWindow::on_pushButton_clicked()
{
    // Update the text to "fill in" the heart button
    // Maybe change from vector to map to avoid duplicates?
    ui->pushButton->setText("♥");
    favoriteList[title] = meanScore;
}

