#include "model/clientException.h"

ClientException::ClientException(const string &arg) : logic_error(arg)
{}

const string ClientException::exceptionFirstName = "INVALID FIRST NAME";
const string ClientException::exceptionLastName = "INVALID LAST NAME";
const string ClientException::exceptionPersonalID = "INVALID PERSONAL ID";
const string ClientException::exceptionAddress = "INVALID ADDRESS";
const string ClientException::exceptionRegisteredAddress = "INVALID REGISTERED ADDRESS";
