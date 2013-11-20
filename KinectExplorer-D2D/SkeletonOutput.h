#pragma once
#include <iostream>
#include <fstream>

void writeHeader(std::ofstream* filehandle);
void writeSkeletonData(const NUI_SKELETON_FRAME* frame, std::ofstream* skeleton_out);