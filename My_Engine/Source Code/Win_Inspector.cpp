#include "Application.h"
#include "Window.h"
#include "Win_Inspector.h"
#include "ImGui.h"
#include "ModuleRenderer3D.h"

#include "GameObject.h"
#include "Component.h"
#include "ComponentTransform.h"

#include "Dependencies/mmgr/mmgr.h"


Win_Inspector::Win_Inspector(bool _active) : Window(_active)
{

}

Win_Inspector::~Win_Inspector()
{

}

void Win_Inspector::Draw()
{
	if (!active)
		return;

	if (ImGui::Begin("Inspector", &active))
	{
		if (App->renderer3D->selectedObject != nullptr)
		{
			std::vector<Component*> vector = App->renderer3D->selectedObject->GetComponents();
			std::vector<Component*>::iterator item = vector.begin();
			for (; item != vector.end(); ++item)
			{
				(*item)->DrawInspector();
			}
		}
		ImGui::End();
	}
}

void Win_Inspector::CleanUp()
{

}