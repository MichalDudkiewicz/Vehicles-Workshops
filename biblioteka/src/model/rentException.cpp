#include "model/rentException.h"

RentException::RentException(const string& arg) : logic_error(arg)
{}

const string RentException::exceptionClientNullPtr = "INVALID CLIENT (NULL)";
const string RentException::exceptionVehicleNullPtr = "INVALID VEHICLE (NULL)";
const string RentException::exceptionDays = "INVALID NUMBER OF DAYS TO SUBSTRACT (NEGATIVE VALUE)";
const string RentException::exceptionRentalPeriod = "RENTAL DATE IS LATER THAN END DATE OF RENTAL";
