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

	float4x4 GetTransform() const;
	float3 GetPosition()const;
	float3 GetScale()const;

	void SetPosition(float3 position);
	void SetScale(float3 scale);
	void RecalculateMatrix();

private:

	float4x4 transform;
	float3 position;
	float3 scale;
	Quat rotation;

};