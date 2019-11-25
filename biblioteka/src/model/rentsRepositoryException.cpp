#include "model/rentsRepositoryException.h"

RentsRepositoryException::RentsRepositoryException(const string& arg) : logic_error(arg)
{}

const string RentsRepositoryException::exceptionRentNotExist = "THIS RENT DOESN'T EXIST IN REPOSITORY";
const string RentsRepositoryException::exceptionRentNullPtr = "INVALID RENT (NULL)";
const string RentsRepositoryException::exceptionRentExist = "RENT OF THIS UUID ALREADY EXISTS IN THE REPOSITORY";
const string RentsRepositoryException::exceptionLimitExceeded = "CLIENT EXCEEDED HIS LIMIT";
const string RentsRepositoryException::exceptionVehicleRented = "THE VEHICLE IS ALREADY RENTED";