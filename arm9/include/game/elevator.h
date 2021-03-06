#ifndef ELEVATOR_H
#define ELEVATOR_H

#define ELEVATOR_UPDOWNBIT (4)
#define ELEVATOR_SIZE (TILESIZE*3)

typedef enum
{
	ELEVATOR_ARRIVING,
	ELEVATOR_OPENING,
	ELEVATOR_OPEN,
	ELEVATOR_CLOSING,
	ELEVATOR_LEAVING
}elevatorState_type;

typedef struct
{
	vect3D position, realPosition;
	rectangle_struct* doorSurface;
	int32 progress;
	u8 direction;
	modelInstance_struct modelInstance;
	elevatorState_type state;
	rectangle_struct* floor;
}elevator_struct;

void initElevators(void);
void freeElevators(void);
void initElevator(elevator_struct* ev, room_struct* r, vect3D position, u8 direction, bool up);
void setElevatorArriving(elevator_struct* ev, int32 distance);
void closeElevator(elevator_struct* ev);
void updateElevator(elevator_struct* ev);
void drawElevator(elevator_struct* ev);

#endif
