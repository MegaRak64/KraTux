#include "custommodelchanger.h"

bool CustomModelChanger::showWindow = false;

void CustomModelChanger::RenderWindow()
{
	if( Settings::UI::Windows::Custommodel::reload )
	{
		ImGui::SetNextWindowPos(ImVec2(Settings::UI::Windows::Custommodel::posX, Settings::UI::Windows::Custommodel::posY), ImGuiSetCond_Always);
		ImGui::SetNextWindowSize(ImVec2(Settings::UI::Windows::Custommodel::sizeX, Settings::UI::Windows::Custommodel::sizeY), ImGuiSetCond_Always);
		Settings::UI::Windows::Custommodel::reload = false;
		CustomModelChanger::showWindow = Settings::UI::Windows::Custommodel::open;
	}
	else
	{
		ImGui::SetNextWindowPos(ImVec2(Settings::UI::Windows::Custommodel::posX, Settings::UI::Windows::Custommodel::posY), ImGuiSetCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(Settings::UI::Windows::Custommodel::sizeX, Settings::UI::Windows::Custommodel::sizeY), ImGuiSetCond_FirstUseEver);
	}
	if (!CustomModelChanger::showWindow)
	{
		Settings::UI::Windows::Custommodel::open = false;
		return;
	}

	if (ImGui::Begin(XORSTR("Custom model changer"), &CustomModelChanger::showWindow, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_ShowBorders))
	{
		Settings::UI::Windows::Custommodel::open = true;
		ImVec2 temp = ImGui::GetWindowSize();
		Settings::UI::Windows::Custommodel::sizeX = (int)temp.x;
		Settings::UI::Windows::Custommodel::sizeY = (int)temp.y;
		temp = ImGui::GetWindowPos();
		Settings::UI::Windows::Custommodel::posX = (int)temp.x;
		Settings::UI::Windows::Custommodel::posY = (int)temp.y;
		ImGui::Separator();
		ImGui::Checkbox(XORSTR("Player model change enable"), &Settings::Skinchanger::Models::Players::enabled);
		
			ImGui::Checkbox(XORSTR("Enemy team enable"), &Settings::Skinchanger::Models::Players::enemyteam::enabled);
			ImGui::InputText(XORSTR("##PZDCh"), Settings::Skinchanger::Models::Players::enemyteam::colgate, 120);

			ImGui::Checkbox(XORSTR("Your team enable"), &Settings::Skinchanger::Models::Players::yourteam::enabled);
			ImGui::InputText(XORSTR("##NAHUY"), Settings::Skinchanger::Models::Players::yourteam::colgate, 120);

		//ImGui::InputText(XORSTR("##CLANTAG"), Settings::ClanTagChanger::value, 30)
		ImGui::End();
	}
};
