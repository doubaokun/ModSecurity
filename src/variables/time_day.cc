/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "variables/time_day.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

#include "modsecurity/assay.h"

namespace ModSecurity {
namespace Variables {

std::list<transaction::Variable *> *
    TimeDay::evaluate(Assay *assay) {
    std::list<transaction::Variable *> *resl =
        new std::list<transaction::Variable *>();

    char tstr[200];
    struct tm timeinfo;
    time_t timer;

    time(&timer);
    memset(tstr, '\0', 200);

    localtime_r(&timer, &timeinfo);
    strftime(tstr, 200, "%d", &timeinfo);

    resl->push_back(new transaction::Variable("TIME_DAY",  std::string(tstr)));

    return resl;
}


}  // namespace Variables
}  // namespace ModSecurity
