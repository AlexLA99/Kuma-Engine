#include "Application.h"
#include "Window.h"
#include "Win_Hierarchy.h"
#include "ImGui.h"
#include "ModuleSceneIntro.h"
#include "GameObject.h"

#include "Dependencies/mmgr/mmgr.h"


Win_Hierarchy::Win_Hierarchy(bool _active) : Window(_active)
{

}

Win_Hierarchy::~Win_Hierarchy()
{

}

void Win_Hierarchy::Draw()
{
	if (!active)
		return;

	if (ImGui::Begin("Hierarchy", &active))
	{
		ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
		std::vector<GameObject*>::iterator item = App->renderer3D->gameObjects.begin();
		for (; item != App->renderer3D->gameObjects.end(); ++item)
		{
			bool node_open = ImGui::TreeNodeEx((*item)->GetName(), base_flags);

			if (ImGui::IsItemClicked())
			{
				App->renderer3D->SetSelectedObject((*item));
			}

			if (node_open)
			{
				if (!(*item)->children.empty())
				{
					std::vector<GameObject*>::iterator child = (*item)->children.begin();
					for (; child != (*item)->children.end(); ++child)
					{
						ImGui::Button((*child)->GetName());
						if (ImGui::IsItemClicked())
							App->renderer3D->SetSelectedObject((*child));
					}
				}
				ImGui::TreePop();
			}
		}
		ImGui::End();
	}
}

void Win_Hierarchy::CleanUp()
{

}