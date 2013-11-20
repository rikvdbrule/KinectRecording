#include "SkeletonOutput.h"

tm* createTimeStamp()
{
	time_t now = time(0);
	return localtime(&now);
}

void writeVector4Header(ofstream* filehandle, char* name)
{
	*filehandle << name << '_' << 'x' << SEPARATOR
		<< name << '_' << 'y' << SEPARATOR
		<< name << '_' << 'z' << SEPARATOR
		<< name << '_' << 'w' << SEPARATOR;
}

void writeDepthPointHeader(ofstream* filehandle, char* name)
{
	*filehandle << name << '_' << 'x' << SEPARATOR
		<< name << '_' << 'y' << SEPARATOR
		<< name << '_' << "depth" << SEPARATOR;
}

void writeBoneHeader(ofstream* filehandle, char* boneName)
{
	*filehandle << boneName << '_' << "trackState" << SEPARATOR;
	writeVector4Header(filehandle, boneName);
	writeDepthPointHeader(filehandle, boneName);
}

void writeHeader(ofstream* filehandle)
{
	*filehandle << "time" << SEPARATOR
		<< "millisec" << SEPARATOR
		<< "frame" << SEPARATOR
		<< "Skeleton_trackState" << SEPARATOR;
	writeVector4Header(filehandle, "Skeleton");
	writeBoneHeader(filehandle, "hip_center");
	writeBoneHeader(filehandle, "spine");
	writeBoneHeader(filehandle, "shoulder_center");
	writeBoneHeader(filehandle, "head");
	writeBoneHeader(filehandle, "shoulder_left");
	writeBoneHeader(filehandle, "elbow_left");
	writeBoneHeader(filehandle, "wrist_left");
	writeBoneHeader(filehandle, "hand_left");
	writeBoneHeader(filehandle, "shoulder_right");
	writeBoneHeader(filehandle, "elbow_right");
	writeBoneHeader(filehandle, "wrist_right");
	writeBoneHeader(filehandle, "hand_right");
	writeBoneHeader(filehandle, "hip_left");
	writeBoneHeader(filehandle, "knee_left");
	writeBoneHeader(filehandle, "ankle_left");
	writeBoneHeader(filehandle, "foot_left");	
	writeBoneHeader(filehandle, "hip_right");
	writeBoneHeader(filehandle, "knee_right");
	writeBoneHeader(filehandle, "ankle_right");
	writeBoneHeader(filehandle, "foot_right");
}

void writeVector4toFile(ofstream* filehandle, const Vector4 vec)
{
	*filehandle << vec.x << SEPARATOR << vec.y << 
		SEPARATOR << vec.z << SEPARATOR << vec.w;
}

void writeSkeletonJointsToFile(ofstream* filehandle, const _NUI_SKELETON_DATA data)
{
	for(int i = 0; i < NUI_SKELETON_POSITION_COUNT; i ++)
	{
		NUI_SKELETON_POSITION_TRACKING_STATE boneTrackingState = data.eSkeletonPositionTrackingState[i];
		Vector4 bonePosition = data.SkeletonPositions[i];
		LONG x, y;
		USHORT depth;
		NuiTransformSkeletonToDepthImage(bonePosition, &x, &y, &depth);
		*filehandle << boneTrackingState << SEPARATOR;
		//bone position in skeleton space
		writeVector4toFile(filehandle, bonePosition);
		//bone position in depth space
		*filehandle << x << SEPARATOR << y << SEPARATOR << depth << SEPARATOR;
	}    
}

void writeSkeletonData(const NUI_SKELETON_FRAME* frame, ofstream* skeleton_out)
{
	tm *timestamp = createTimeStamp();
	DWORD millisecs = GetTickCount();
	*skeleton_out << timestamp->tm_hour << ':' << timestamp->tm_min << ':' << timestamp->tm_sec << SEPARATOR
		<< millisecs << SEPARATOR << frame->dwFrameNumber << SEPARATOR;
	//loop through tracked skeletons
	for(int i  = 0; i < NUI_SKELETON_COUNT; i +=1)
	{
		_NUI_SKELETON_DATA data = frame->SkeletonData[i];
		if(NUI_SKELETON_TRACKED == data.eTrackingState || NUI_SKELETON_POSITION_ONLY == data.eTrackingState)
		{
			*skeleton_out << data.eTrackingState << SEPARATOR
				<< data.dwTrackingID << SEPARATOR;
			writeVector4toFile(skeleton_out, data.Position);
		}
		if(NUI_SKELETON_TRACKED == data.eTrackingState) 
		{
			writeSkeletonJointsToFile(skeleton_out, data);
		}
		//ignore untracked skeletons
	}

	*skeleton_out << endl;
	
}