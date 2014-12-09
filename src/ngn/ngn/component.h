#pragma once

#include "entity.h"
#include "pool.h"
#include <glm/glm.hpp>
#include <unordered_map>
#include <initializer_list>

using namespace glm;

namespace ngn {

	class GameObject;
	class Message;

	class Component : public Entity
	{
	public:
		virtual void update(GameObject &obj) = 0;
		virtual void sendMessage(Message &msg) = 0;
		virtual void handleChanged(Handle handle);

		Component(Handle parent):Entity(), mParent(parent){};
		virtual ~Component(){};

	private:
		Handle mParent;
	};


	class LocationComponent : public Component
	{
	public:
		void update(GameObject &obj){printf("I have position <%f, %f, %f>\n", position.x, position.y, position.z);};
		void sendMessage(Message &msg){};

		LocationComponent(Handle parent):Component(parent)
		{
			handle = Handle(0, 0, TYPE_LOCATION);
		};

		LocationComponent():Component(nullHandle)
		{
			handle = Handle(0, 0, TYPE_LOCATION);
		};

		virtual ~LocationComponent(){};

		vec3 position;
		vec3 velocity;
	};


	class GameObject : public Entity
	{
	public:
		std::unordered_map<ComponentType, Handle> mComponents;

		void addComponent(Handle handle);
		Component* getComponentByType(ComponentType type);
		void update();
		void handleChanged(Handle handle){ this->handle = handle; };

		Component* operator[] (ComponentType type) { return this->getComponentByType(type); };

		GameObject();
		GameObject( std::initializer_list<ComponentType> componentTypes );
		GameObject( std::initializer_list<Component**> componentPtrs );
		~GameObject();
	};


	class ContentManager
	{
	public:
		Component *getComponent(Handle handle);
		Handle addComponent(Component *component, Handle parent);
		Handle createComponent(ComponentType type, Handle parent);

		// Game objects in the current game
		std::vector<GameObject> mGameObjects;

		// All of the associated components
		Pool<LocationComponent> mLocationComponents;

	};

} // namespace ngn