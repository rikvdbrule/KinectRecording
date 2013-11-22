#include "RecordFunctions.h"
#include <string>

#define BUFFER_SIZE 80
#define TIMESTAMP_FORMAT "%Y%m%d-%H.%M.%S"

tm * CreateTimeStruct()
{
	time_t now = time(0);
    return localtime(&now);
}

std::string CreateDateTimeStamp()
{
    char buff[BUFFER_SIZE];
	struct tm * loctime = CreateTimeStruct();
    strftime(buff, BUFFER_SIZE, TIMESTAMP_FORMAT, loctime);
    std::string timestamp = buff;
	return timestamp;
}

std::string GenerateSkeletonOutputFileName()
{
	const std::string prefix = "skeleton_out_";
	const std::string affix = ".data";
	return prefix + CreateDateTimeStamp() + affix;
}
