#ifndef __EntityManager_H__
#define __EntityManager_H__

#include "Module.h"
#include "Entity.h"
#include "Walls.h"

class Entity;

class EntityManager : public Module
{
public:
	EntityManager();
	~EntityManager();

	bool Awake(pugi::xml_node & config);
	bool LoadSamples();
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	bool Draw(float dt);

	Entity* AddEntity(bool player1, Entity::entityType type, pair<int, int> position, Collider collider, Animation* animation = nullptr);
	char * GetName(Entity::entityType type);
	void DeleteAllEntities();

	list<Entity*> EntityManager::OrderEntities(list<Entity*> List);
	int EntityManager::GetDepth(Entity* entity);


	Entity * findEntity(pair<int, int> pos, bool fromplayer1, int attackrange);

	//bool Is_inRange(pair<int, int> pos, int distance, pair<int, int> position, int range);

	bool Is_inRange(pair<int, int> pos, int & distance, pair<int, int> position, int range);

	//void Remove_fromList(Entity * entity);

	//void Erase_fromList(list<Entity*>::iterator tmp);

	bool FindInList(list<Entity*> List, pair<int, int> pos, bool fromplayer1, Entity::entityType type);




public:
	//Soldier			soldierSample;

	string			folder;
	string			texture_path;
	SDL_Texture*	texture = nullptr;

	list<Entity*>	entity_list;
	vector<SDL_Texture*> entitiesTextures;

	bool draw_path = false;
	bool godmode = false;
	bool pathfinding = false;
	bool pathfinding2 = false;
};

#endif //