#include "pch.h" // Include precompiled headers
#include "Weekly_Bulletin.h"
#include <fstream>

CString WeeklyBulletin::formatDate(std::time_t date) const {
    char buffer[80];
    struct tm timeinfo;
    localtime_s(&timeinfo, &date); // Use localtime_s for safety
    strftime(buffer, 80, "%B %d, %Y", &timeinfo);
    return CString(buffer);
}

void WeeklyBulletin::setDates(std::time_t start, std::time_t end) {
    startDate = start;
    endDate = end;
}

void WeeklyBulletin::addBranch(const CString& name, Load load, const CString& customIndicator) {
    Branch branch;
    branch.name = name;
    branch.predictedLoad = load;
    branch.customIndicator = customIndicator;
    branches.push_back(branch);
}

void WeeklyBulletin::addWarningToBranch(const CString& branchName, const CString& warning) {
    for (auto& branch : branches) {
        if (branch.name == branchName) {
            branch.warnings.push_back(warning);
            break;
        }
    }
}

void WeeklyBulletin::addTaskToBranch(const CString& branchName, const CString& category, Task& task) {
    task.taskId = nextTaskId++; // Assign the next available task ID as an int
    for (auto& branch : branches) {
        if (branch.name == branchName) {
            branch.categories[category].push_back(task);
            return;
        }
    }
    // Optionally handle the case where the branch isn't found.
}

void WeeklyBulletin::addSubTaskToTask(const CString& branchName, const CString& category, int taskId, const SubTask& subTask) {
    for (auto& branch : branches) {
        if (branch.name == branchName) {
            auto& tasks = branch.categories[category];
            for (auto& task : tasks) {
                if (task.taskId == taskId) {
                    task.subTasks.push_back(subTask);
                    return;
                }
            }
        }
    }
    // Optionally handle the case where the branch, category, or task isn't found.
}

CString WeeklyBulletin::printBulletin() const {
    CString result_Display;

    CString line;
    line.Format(_T("Weekly Bulletin (%s to %s):\r\n"), formatDate(startDate), formatDate(endDate));
    result_Display += line;

    for (const auto& branch : branches) {
        line.Format(_T(" %s ("), branch.name);
        result_Display += line;
        switch (branch.predictedLoad) {
        case NoLoad:
            line = _T("No load has been established");
            break;
        case LessLoad:
            line = _T("Less load has been established");
            break;
        case NormalLoad:
            line = _T("Normal load has been established");
            break;
        case HighLoad:
            line = _T("High load has been established");
            break;
        }
        if (!branch.customIndicator.IsEmpty()) {
            line.AppendFormat(_T(", %s"), branch.customIndicator);
        }
        line += _T("):\r\n");
        result_Display += line;

        for (const auto& warning : branch.warnings) {
            line.Format(_T("  Warning: %s\r\n"), warning);
            result_Display += line;
        }

        for (const auto& category : branch.categories) {
            line.Format(_T("  %s:\r\n"), category.first);
            result_Display += line;
            for (const auto& task : category.second) {
                // Including task ID in the printout
                line.Format(_T("   #%d - %s (Due %s)\r\n"), task.taskId, task.description, formatDate(task.dueDate));
                result_Display += line;
                for (const auto& subtask : task.subTasks) {
                    line.Format(_T("     * %s (Due %s)\r\n"), subtask.description, formatDate(subtask.dueDate));
                    result_Display += line;
                }
                for (const auto& warning : task.warnings) {
                    line.Format(_T("     Warning: %s\r\n"), warning);
                    result_Display += line;
                }
            }
        }
    }

    return result_Display;
}
