#pragma once

#include "entity.h"
#include <glm/glm.hpp>
#include <vector>

using namespace glm;

namespace ngn {

	class GameObject;
	class Message;

	class Component : public Entity
	{
	public:
		virtual void update(GameObject &obj) = 0;
		virtual void sendMessage(Message &msg) = 0;
		virtual void handleChanged();

		Component(Handle parent):Entity(), mParent(parent){};
		virtual ~Component(){};

	private:
		Handle mParent;
	};


	class LocationComponent : public Component
	{
	public:
		void update(GameObject &obj) = 0;
		void sendMessage(Message &msg) = 0;

		LocationComponent(Handle parent):Component(parent){};
		virtual ~LocationComponent(){};

		vec3 position;
		vec3 velocity;
	};


	class GameObject : public Entity
	{
	public:
		std::vector<Handle> mComponents;

		void addComponent(Handle handle);
		Component* getComponent(ComponentType type);
		void update();

		GameObject();
		~GameObject();
	};

} // namespace ngn