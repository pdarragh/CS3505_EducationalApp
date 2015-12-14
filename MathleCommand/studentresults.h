#ifndef STUDENTRESULTS
#define STUDENTRESULTS

#include <QString>
#include <QVector>

/*
 * This is purely a data model used to contain
 * data from the database.
 */

class StudentResults
{
public:
    // constructors
    StudentResults();
    ~StudentResults();

    // getters/setters
    void setUserName(QString name);
    void setLevelComplete(int level, bool value);
    void addLevelScore(int level, int value);
    void addLevelMiss(int level, int value);

    QString getUserName();
    bool getHasCompletedLevel(int level);
    float getLevelAverageScore(int level);
    float getLevelAverageMisses(int level);
    int getLevelMaxScore(int level);



private:
    bool levelOne;
    bool levelTwo;
    bool levelThree;

    QVector<int> levelOneScores;
    QVector<int> levelTwoScores;
    QVector<int> levelThreeScores;

    QVector<int> levelOneMisses;
    QVector<int> levelTwoMisses;
    QVector<int> levelThreeMisses;

    QString username;
};

#endif // STUDENTRESULTS

