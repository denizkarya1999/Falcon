#ifndef WEEKLY_BULLETIN_H
#define WEEKLY_BULLETIN_H

#include "pch.h"
#include <afx.h> // For CString
#include <vector>
#include <string>
#include <map>
#include <ctime>

enum Load {
    NoLoad,
    LessLoad,
    NormalLoad,
    HighLoad
};

struct SubTask {
    CString description;
    std::time_t dueDate;
    std::vector<CString> warnings;
};

struct Task {
    int taskId;
    CString description;
    std::time_t dueDate;
    std::vector<SubTask> subTasks;
    std::vector<CString> warnings;
};

struct Branch {
    CString name;
    Load predictedLoad;
    CString customIndicator;
    std::vector<CString> warnings;
    std::map<CString, std::vector<Task>> categories;
};

class WeeklyBulletin {
private:
    std::time_t startDate;
    std::time_t endDate;
    std::vector<Branch> branches;

    CString formatDate(std::time_t date) const;

public:
    int nextTaskId;

    WeeklyBulletin() : nextTaskId(1) {}

    void setDates(std::time_t start, std::time_t end);

    void addBranch(const CString& name, Load load, const CString& customIndicator = _T(""));

    void addWarningToBranch(const CString& branchName, const CString& warning);

    void addTaskToBranch(const CString& branchName, const CString& category, Task& task);

    void addSubTaskToTask(const CString& branchName, const CString& category, int taskId, const SubTask& subTask);

    CString printBulletin() const;
};

#endif // WEEKLY_BULLETIN_H
