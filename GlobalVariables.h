#pragma once
#include "Weekly_Bulletin.h"
#include <afxstr.h>
#include <ctime>

class GlobalVariables
{
public:
    // Instance of the Weekly Bulletin
    WeeklyBulletin bulletin;

    // Warning
    CString warning;

    // Task
    CString description;

    // Branch
    CString name;
    CString load;
    CString indicator;
    CString category;
    CString customCategory;

    // Dates
    time_t startDate;
    time_t endDate;
    time_t dueDate;
};