/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *header;
    QFrame *header_2;
    QFrame *entry;
    QLineEdit *lineEdit;
    QFrame *attributes;
    QFrame *attSelection;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *ascButton;
    QPushButton *descButton;
    QFrame *results;
    QFrame *resultsView;
    QLabel *sortType;
    QListWidget *resList;
    QPushButton *searchAgainButton;
    QPushButton *viewListButton;
    QFrame *frame;
    QLabel *title;
    QPushButton *pushButton;
    QLabel *stats;
    QLabel *stats_2;
    QFrame *favorites;
    QFrame *favView;
    QListWidget *favList;
    QPushButton *searchButton;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QStringLiteral(".AppleSystemUIFont"));
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #1c1d22;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        header = new QFrame(centralwidget);
        header->setObjectName(QStringLiteral("header"));
        header->setGeometry(QRect(0, 0, 800, 46));
        header->setMinimumSize(QSize(800, 46));
        header->setMaximumSize(QSize(800, 46));
        header->setAutoFillBackground(false);
        header->setStyleSheet(QStringLiteral("background-color: #121116;"));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        header->setLineWidth(0);
        header_2 = new QFrame(centralwidget);
        header_2->setObjectName(QStringLiteral("header_2"));
        header_2->setGeometry(QRect(0, 46, 800, 3));
        header_2->setMinimumSize(QSize(800, 3));
        header_2->setMaximumSize(QSize(800, 3));
        header_2->setAutoFillBackground(false);
        header_2->setStyleSheet(QStringLiteral("background-color: #3f5ca7;"));
        header_2->setFrameShape(QFrame::StyledPanel);
        header_2->setFrameShadow(QFrame::Raised);
        header_2->setLineWidth(0);
        entry = new QFrame(centralwidget);
        entry->setObjectName(QStringLiteral("entry"));
        entry->setEnabled(true);
        entry->setGeometry(QRect(125, 250, 550, 100));
        entry->setMinimumSize(QSize(550, 100));
        entry->setMaximumSize(QSize(550, 100));
        entry->setAutoFillBackground(false);
        entry->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-radius: 3px;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        entry->setFrameShape(QFrame::StyledPanel);
        entry->setFrameShadow(QFrame::Raised);
        entry->setLineWidth(0);
        lineEdit = new QLineEdit(entry);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(38, 25, 504, 50));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(false);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QStringLiteral("border-width: 0px;"));
        attributes = new QFrame(centralwidget);
        attributes->setObjectName(QStringLiteral("attributes"));
        attributes->setGeometry(QRect(0, 50, 800, 550));
        attributes->setFrameShape(QFrame::StyledPanel);
        attributes->setFrameShadow(QFrame::Raised);
        attSelection = new QFrame(attributes);
        attSelection->setObjectName(QStringLiteral("attSelection"));
        attSelection->setGeometry(QRect(225, 130, 350, 300));
        attSelection->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-radius: 3px;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        attSelection->setFrameShape(QFrame::StyledPanel);
        attSelection->setFrameShadow(QFrame::Raised);
        radioButton = new QRadioButton(attSelection);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 0, 320, 100));
        QFont font2;
        font2.setPointSize(20);
        radioButton->setFont(font2);
        radioButton->setStyleSheet(QLatin1String("border-bottom: 0px;\n"
"border-left: 0px;"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(attSelection);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 100, 320, 100));
        radioButton_2->setFont(font2);
        radioButton_2->setStyleSheet(QLatin1String("border-top: 0px;\n"
"border-bottom: 0px;\n"
"border-left: 0px;"));
        radioButton_3 = new QRadioButton(attSelection);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 200, 320, 100));
        radioButton_3->setFont(font2);
        radioButton_3->setStyleSheet(QLatin1String("border-top: 0px;\n"
"border-left: 0px;"));
        ascButton = new QPushButton(attributes);
        ascButton->setObjectName(QStringLiteral("ascButton"));
        ascButton->setGeometry(QRect(250, 470, 140, 35));
        QFont font3;
        font3.setPointSize(14);
        ascButton->setFont(font3);
        ascButton->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        ascButton->setFlat(true);
        descButton = new QPushButton(attributes);
        descButton->setObjectName(QStringLiteral("descButton"));
        descButton->setGeometry(QRect(410, 470, 140, 35));
        descButton->setFont(font3);
        descButton->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        descButton->setFlat(true);
        results = new QFrame(centralwidget);
        results->setObjectName(QStringLiteral("results"));
        results->setGeometry(QRect(0, 50, 800, 550));
        results->setFrameShape(QFrame::StyledPanel);
        results->setFrameShadow(QFrame::Raised);
        resultsView = new QFrame(results);
        resultsView->setObjectName(QStringLiteral("resultsView"));
        resultsView->setGeometry(QRect(75, 170, 650, 300));
        resultsView->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-radius: 3px;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        resultsView->setFrameShape(QFrame::StyledPanel);
        resultsView->setFrameShadow(QFrame::Raised);
        sortType = new QLabel(resultsView);
        sortType->setObjectName(QStringLiteral("sortType"));
        sortType->setGeometry(QRect(11, 1, 626, 30));
        QFont font4;
        font4.setPointSize(13);
        sortType->setFont(font4);
        sortType->setStyleSheet(QLatin1String("border-top: 0px;\n"
"border-right: 0px;\n"
"border-left: 0px;"));
        resList = new QListWidget(resultsView);
        resList->setObjectName(QStringLiteral("resList"));
        resList->setGeometry(QRect(11, 31, 626, 268));
        resList->setFocusPolicy(Qt::NoFocus);
        resList->setStyleSheet(QStringLiteral("border: 0px;"));
        resList->setFrameShape(QFrame::NoFrame);
        resList->setFrameShadow(QFrame::Plain);
        resList->setLineWidth(0);
        resList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        resList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        resList->setAutoScroll(false);
        resList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        resList->setProperty("showDropIndicator", QVariant(false));
        searchAgainButton = new QPushButton(results);
        searchAgainButton->setObjectName(QStringLiteral("searchAgainButton"));
        searchAgainButton->setGeometry(QRect(585, 120, 140, 35));
        searchAgainButton->setFont(font3);
        searchAgainButton->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        searchAgainButton->setFlat(false);
        viewListButton = new QPushButton(results);
        viewListButton->setObjectName(QStringLiteral("viewListButton"));
        viewListButton->setGeometry(QRect(585, 70, 140, 35));
        viewListButton->setFont(font3);
        viewListButton->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        viewListButton->setFlat(true);
        frame = new QFrame(results);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(75, 39, 450, 111));
        frame->setStyleSheet(QStringLiteral("border: 0px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        title = new QLabel(frame);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(42, 8, 400, 32));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        title->setFont(font5);
        title->setTextFormat(Qt::PlainText);
        title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 8, 32, 32));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(24);
        pushButton->setFont(font6);
        pushButton->setIconSize(QSize(32, 32));
        pushButton->setFlat(true);
        stats = new QLabel(frame);
        stats->setObjectName(QStringLiteral("stats"));
        stats->setGeometry(QRect(0, 42, 401, 38));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(false);
        stats->setFont(font7);
        stats->setTextFormat(Qt::PlainText);
        stats->setWordWrap(false);
        stats_2 = new QLabel(frame);
        stats_2->setObjectName(QStringLiteral("stats_2"));
        stats_2->setGeometry(QRect(0, 70, 401, 38));
        stats_2->setFont(font7);
        stats_2->setTextFormat(Qt::PlainText);
        stats_2->setWordWrap(false);
        favorites = new QFrame(centralwidget);
        favorites->setObjectName(QStringLiteral("favorites"));
        favorites->setGeometry(QRect(0, 50, 800, 550));
        favorites->setFrameShape(QFrame::StyledPanel);
        favorites->setFrameShadow(QFrame::Raised);
        favView = new QFrame(favorites);
        favView->setObjectName(QStringLiteral("favView"));
        favView->setGeometry(QRect(225, 130, 350, 300));
        favView->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-radius: 3px;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        favView->setFrameShape(QFrame::StyledPanel);
        favView->setFrameShadow(QFrame::Raised);
        favList = new QListWidget(favView);
        favList->setObjectName(QStringLiteral("favList"));
        favList->setGeometry(QRect(1, 1, 348, 298));
        favList->setFocusPolicy(Qt::NoFocus);
        favList->setStyleSheet(QStringLiteral("border: 0px;"));
        favList->setFrameShape(QFrame::NoFrame);
        favList->setFrameShadow(QFrame::Plain);
        favList->setLineWidth(0);
        favList->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        favList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        favList->setAutoScroll(false);
        favList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        favList->setProperty("showDropIndicator", QVariant(false));
        searchButton = new QPushButton(favorites);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(325, 470, 140, 35));
        searchButton->setFont(font3);
        searchButton->setStyleSheet(QLatin1String("background-color: #121116;\n"
"border-color: #7e7e7e;\n"
"border-width: 1px;\n"
"border-style: solid;"));
        searchButton->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        header->raise();
        header_2->raise();
        attributes->raise();
        entry->raise();
        results->raise();
        favorites->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Enter a movie name", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "      Sort by recency", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "      Sort by normalized score", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "      Sort by reviewer name", Q_NULLPTR));
        ascButton->setText(QApplication::translate("MainWindow", "Sort ascending", Q_NULLPTR));
        descButton->setText(QApplication::translate("MainWindow", "Sort descending", Q_NULLPTR));
        sortType->setText(QApplication::translate("MainWindow", "Sorted by normalized score (descending)", Q_NULLPTR));
        searchAgainButton->setText(QApplication::translate("MainWindow", "Search again", Q_NULLPTR));
        viewListButton->setText(QApplication::translate("MainWindow", "View my list", Q_NULLPTR));
        title->setText(QApplication::translate("MainWindow", "Example Movie Title Here", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\342\231\241", Q_NULLPTR));
        stats->setText(QApplication::translate("MainWindow", "Total Score: 5,535 | Mean Score: 52.8", Q_NULLPTR));
        stats_2->setText(QApplication::translate("MainWindow", "QS: ms | MS: ms", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "Search again", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
