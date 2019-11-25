#include "model/clientRepositoryException.h"

ClientRepositoryException::ClientRepositoryException(const string &arg) : logic_error(arg)
{}

const string ClientRepositoryException::exceptionClientNotExist = "THIS CLIENT DOESN'T EXIST IN REPOSITORY";
const string ClientRepositoryException::exceptionClientNullPtr = "INVALID CLIENT (NULL)";
const string ClientRepositoryException::exceptionClientExist = "THIS CLIENT ALREADY EXISTS IN REPOSITORY";
