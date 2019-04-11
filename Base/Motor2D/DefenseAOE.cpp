#include "DefenseAoe.h"
#include "Brofiler\Brofiler.h"
#include "Player.h"
#include "Render.h"
#include "Log.h"

DefenseAoe::DefenseAoe()
{
}

DefenseAoe::~DefenseAoe()
{
}

DefenseAoe::DefenseAoe(bool isPlayer1, pair<int, int> pos) : Entity(entityType::DEFENSE_TARGET, isPlayer1, pos)
{

	collider = { 0,0,64,32 };
	tex = App->tex->Load("maps/meta.png");

}

bool DefenseAoe::Start()
{


	return true;
}

bool DefenseAoe::PreUpdate()
{
	BROFILER_CATEGORY("DefenseAoe PreUpdate", Profiler::Color::SandyBrown);


	return true;
}

bool DefenseAoe::Update(float dt)
{
	BROFILER_CATEGORY("DefenseAoe Update", Profiler::Color::SandyBrown);

	
	return true;
}

void DefenseAoe::CleanUp()
{
	// Its needed or the super class is always called?
	this->Entity::CleanUp();
}



bool DefenseAoe::Is_inRange(pair<int, int> pos, int &distance) {

	pair <int, int> vector_distance = { position.first - pos.first, position.second - pos.second };
	distance = (int)(sqrt(pow(vector_distance.first, 2) + pow(vector_distance.second, 2)));

	return distance <= range;
}

