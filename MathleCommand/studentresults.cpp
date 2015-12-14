
#include "studentresults.h"


StudentResults::StudentResults()
{
    levelOne = false;
    levelTwo = false;
    levelThree = false;

    levelOneScores = QVector<int>();
    levelTwoScores = QVector<int>();
    levelThreeScores = QVector<int>();

    levelOneMisses = QVector<int>();
    levelTwoMisses = QVector<int>();
    levelThreeMisses = QVector<int>();

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

void StudentResults::addLevelScore(int level, int value)
{
    switch(level)
    {
    case 1:
        levelOneScores.append(value);
        break;
    case 2:
        levelTwoScores.append(value);
        break;
    case 3:
        levelThreeScores.append(value);
        break;
    }
}

void StudentResults::addLevelMiss(int level, int value)
{
    switch(level)
    {
    case 1:
        levelOneMisses.append(value);
        break;
    case 2:
        levelTwoMisses.append(value);
        break;
    case 3:
        levelThreeMisses.append(value);
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

float StudentResults::getLevelAverageScore(int level)
{
    int average = 0;
    int entries = 0;
    switch(level)
    {
    case 1:
        entries = levelOneScores.size();
        for (const int &value : levelOneScores)
        {
            average += value;
        }
        break;
    case 2:
        entries = levelTwoScores.size();
        for (const int &value : levelTwoScores)
        {
            average += value;
        }
        break;
    case 3:
        entries = levelThreeScores.size();
        for (const int &value : levelThreeScores)
        {
            average += value;
        }
        break;
    }

    return (entries != 0) ? float(average) / float(entries) : 0;
}

float StudentResults::getLevelAverageMisses(int level)
{
    int average = 0;
    int entries = 0;
    switch(level)
    {
    case 1:
        entries = levelOneMisses.size();
        for (const int &value : levelOneMisses)
        {
            average += value;
        }
        break;
    case 2:
        entries = levelTwoMisses.size();
        for (const int &value : levelTwoMisses)
        {
            average += value;
        }
        break;
    case 3:
        entries = levelThreeMisses.size();
        for (const int &value : levelThreeMisses)
        {
            average += value;
        }
        break;
    }

    return (entries != 0) ? float(average) / float(entries) : 0;
}

int StudentResults::getLevelMaxScore(int level)
{
    int max = 0;
    switch(level)
    {
    case 1:
        for (const int &value : levelOneScores)
        {
            if (value > max)
            {
                max = value;
            }
        }
        break;
    case 2:
        for (const int &value : levelTwoScores)
        {
            if (value > max)
            {
                max = value;
            }
        }
        break;
    case 3:
        for (const int &value : levelThreeScores)
        {
            if (value > max)
            {
                max = value;
            }
        }
        break;
    }

    return max;
}
