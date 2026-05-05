#include "Zombie_task.cpp"
//createHorde() function
Zombie* createHorde(int numZombies, IntRect arena)
{
	//array of objects of type Zombie
	Zombie *zombies=new Zombie[numZombies];
	//arena wall-boundary to spawn zombies minX,maxX,minY,maxY
	
	//place each zombie in the arena
	for (int i = 0; i < numZombies; i++)
	{

		// Which side should the zombie spawn
		srand((int)time(0) * i);
		int side =  
		float x, y;

		switch (side)
		{
		case 0:
			// left
			x = 
			y = 
			break;

		case 1:
			// right
			x = 
			y = 
			break;

		case 2:
			// top
			x = 
			y = 
			break;

		case 3:
			// bottom
			x = 
			y = 
			break;
		}

		// Bloater, crawler or runner
		srand((int)time(0) * i * 2);
		int type = 

		// Spawn the new zombie into the array
		

	}
	return zombies;
}
