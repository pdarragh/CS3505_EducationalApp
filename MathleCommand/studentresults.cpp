
#include "studentresults.h"


StudentResults::StudentResults()
{
    levelOne = false;
    levelTwo = false;
    levelThree = false;

    levelOneScore = 0;
    levelTwoScore = 0;
    levelThreeScore = 0;

    levelOneMisses = 0;
    levelTwoMisses = 0;
    levelThreeMisses = 0;

    username = "";
}

StudentResults::~StudentResults(){}

void StudentResults::setUserName(QString name)
{
    username = name;
}

void StudentResults::setLevelComplete(int level, bool value)
{
    switch(level)
    {
    case 1:
        levelOne = value;
        break;
    case 2:
        levelTwo = value;
        break;
    case 3:
        levelThree = value;
        break;
    }
}

void StudentResults::setLevelScore(int level, int value)
{
    switch(level)
    {
    case 1:
        levelOneScore = value;
        break;
    case 2:
        levelTwoScore = value;
        break;
    case 3:
        levelThreeScore = value;
        break;
    }

}

void StudentResults::setLevelMisses(int level, int value)
{
    switch(level)
    {
    case 1:
        levelOneMisses = value;
        break;
    case 2:
        levelTwoMisses = value;
        break;
    case 3:
        levelThreeMisses = value;
        break;
    }
}

QString StudentResults::getUserName()
{
    return username;
}

bool StudentResults::getHasCompletedLevel(int level)
{
    switch(level)
    {
    case 1:
        return levelOne;
        break;
    case 2:
        return levelTwo;
        break;
    case 3:
        return levelThree;
        break;
    }
}

int StudentResults::getLevelScore(int level)
{
    switch(level)
    {
    case 1:
        return levelOneScore;
        break;
    case 2:
        return levelTwoScore;
        break;
    case 3:
        return levelThreeScore;
        break;
    }
}

int StudentResults::getLevelMisses(int level)
{
    switch(level)
    {
    case 1:
        return levelOneMisses;
        break;
    case 2:
        return levelTwoMisses;
        break;
    case 3:
        return levelThreeMisses;
        break;
    }
}
