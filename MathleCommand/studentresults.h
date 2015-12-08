#ifndef STUDENTRESULTS
#define STUDENTRESULTS

#include <QString>

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
    void setLevelScore(int level, int value);
    void setLevelMisses(int level, int value);

    QString getUserName();
    bool getHasCompletedLevel(int level);
    int getLevelScore(int level);
    int getLevelMisses(int level);



private:
    bool levelOne;
    bool levelTwo;
    bool levelThree;

    int levelOneScore;
    int levelTwoScore;
    int levelThreeScore;

    int levelOneMisses;
    int levelTwoMisses;
    int levelThreeMisses;

    QString username;
};

#endif // STUDENTRESULTS

