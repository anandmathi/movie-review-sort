# movie-review-sort
Movie Review Sort - COP3530 Final Project

[Demo Video](https://www.youtube.com/watch?v=yOYwv4kjbNo)

## Extended and Refined Proposal
### Problem:
When searching for a movie, it can help to have some sort of reference through other people's opinions, so this application seeks to solve that problem. Also, this will allow people to find movies they would have never considered watching.
### Motivation:
Sometimes people take a while to pick a movie they would like. This program aims to allow people to find the movies they would enjoy faster by looking through reviews and having the choice to bookmark/heart for future reference. 
### Features:
The application will allow the user to automatically sort through movie review data to easily find the reviews that they are looking for. The user can specify the title of the movie to get all reviews made for that movie. The user then has the option to sort the reviews by either relevancy, reviewer name, or score. The sorted results are then displayed to the user where the user can easily navigate through the results. The duration for merge sort and quick sort are also displayed at the top of the screen.
### Data Description:
We plan to get our data from this dataset: https://www.kaggle.com/datasets/talha002/rottentomatoes-400k-review. It shows the movie title, reviewer’s name, publisher, review, date, and score in that order, which can all be used to sort the data accordingly and present the review text content in an organized fashion. The file is downloaded as a CSV file so that all the elements of the data are separated by commas unless there are commas within the element. If the elements have commas within them then quotes are put around that specific element. 
### Tools/Languages/APIs/Libraries:
For this project, we used C++ to handle all coding aspects of the project. To create and render the GUI on the screen, we used QT, a cross-platform C++ GUI framework. For planning, sketching, and wireframing the GUI, we used Figma. Finally, to allow for easy collaboration we stored our code in a GitHub repository.
### Implemented Algorithms:
We compared the efficiency of the Merge Sort and Quicksort algorithms in our project. When the user chooses to sort by either score, date, or reviewer name, the speed of both algorithms will be recorded and displayed. Once the movie title is searched, all reviews that correspond to the movie title will be pushed into a vector to be sorted by the user-selected attribute.
### Additional Data Structures/Algorithms:
For this project, we created a MovieReview class to store all of the relevant info from the CSV like the date, reviewer name, review text content, and normalized score. We used vectors to house the full list of movie reviews as well as for the specific reviews that matched the requested title. For the favorites list, we used an unordered map with the key as the movie title and the value as the mean score to avoid duplicates.
