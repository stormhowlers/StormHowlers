#ifndef __Entity_H__
#define __Entity_H__

#include "Log.h"
#include "Animation.h"
#include "Map.h"
#include "App.h"

class Entity
{
public:
	enum entityType
	{
		TOWNHALL = 1,
		MAIN_DEFENSE,
		COMMAND_CENTER,
		WALLS,
		DEFENSE_AOE,
		DEFENSE_TARGET,
		MINES,
		BARRACKS
	};

public:
	Entity();
	Entity(entityType type);
	~Entity();
	virtual bool Awake(pugi::xml_node & config) { return true; };
	virtual bool Start() { return true; };
	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt) { return true; };
	virtual bool PostUpdate() { return true; };

	virtual void CleanUp() {};
	virtual void Save(pugi::xml_node& file) const {};
	virtual void Load(pugi::xml_node& file) {};
	virtual void Restart() {};
	virtual void LoadAnimations() {};
	virtual void ChangeAnimation() {};

	pair<int, int> GetSize(Entity* entity) { return entity->size; };
	pair<int, int> GetPos(Entity* entity) { return entity->position; };

	void Collider_Overlay();
	void PositionCollider();

public:
	Animation* Current_Animation = nullptr;
	entityType type;

	bool fromPlayer1;
	
	pair<int, int> position;
	pair<int,int> size;

	SDL_Rect Collider;
	SDL_Rect SightCollider;
	
	bool flip = false;
	int frame = 0;

};

#endif