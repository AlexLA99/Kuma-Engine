#pragma once

#include "Dependencies/MathGeoLib/include/MathGeoLib.h"
#include "glmath.h"

class Component;

class ComponentTransform : public Component
{
public:
	ComponentTransform(GameObject* owner);
	~ComponentTransform();

	void Update() override;
	void DrawInspector() override;

	//float4x4 GetTransform() const;
	vec3 GetPosition()const;
	vec3 GetScale()const;

	void SetPosition(vec3 position);
	void SetScale(vec3 scale);
	//void RecalculateMatrix();

private:

	//float4x4 transform;
	vec3 position;
	vec3 scale;
	//Quat rotation;

};