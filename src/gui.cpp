#include "gui.hpp"

GUI::GUI()
{
    workspaceTableFlags = ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders;
    active_tab = 0;
    active_response = "If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them";
    Tab t;
    tabs.push_back(t);
    Tab t2;
    t2.title = "Title2";
    tabs.push_back(t2);
}
void GUI::responseArea()
{

    if (ImGui::BeginTabBar("ResponseBar"))
    {
        if (ImGui::BeginTabItem("Body"))
        {

            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Headers"))
        {

            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Cookies"))
        {

            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Test Results"))
        {

            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::TextWrapped("%s", active_response.c_str());
}

void GUI::workspaceBar()
{
    if (ImGui::Button("Preferences"))
    {
        ImGui::OpenPopup("Edit Preferences");
    }
    auto f_settings_popup = pool.enqueue(&GUI::settingsPopup, this);
    // settingsPopup();
    ImGui::SameLine();
    if (ImGui::Button("History"))
    {
    }

    f_settings_popup.get();
}

void GUI::settingsPopup()
{
    centerModal();

    if (ImGui::BeginPopupModal("Edit Preferences", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Changes will be saved automatically");
        ImGui::Separator();

        ImGui::InputInt("URL Max Size", &constants->MAX_URL_SIZE);

        ImGui::Separator();
        if (ImGui::Button("OK", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

void GUI::centerModal()
{
    ImVec2 center(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f);
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
}

void GUI::tabConfig()
{
    if (ImGui::BeginTabBar("TabItemConfig"))
    {

        if (ImGui::BeginTabItem("Params"))
        {
            if (ImGui::BeginTable("##table1", 3, workspaceTableFlags))
            {
                ImGui::TableSetupColumn("One");
                ImGui::TableSetupColumn("Two");
                ImGui::TableSetupColumn("Three");
                ImGui::TableHeadersRow();

                for (int row = 0; row < 5; row++)
                {
                    ImGui::TableNextRow();
                    for (int column = 0; column < 3; column++)
                    {
                        ImGui::TableSetColumnIndex(column);
                        char buf[32];
                        sprintf(buf, "Hello %d,%d", column, row);
                        ImGui::TextUnformatted(buf);
                        ImGui::Separator();
                    }
                }
                ImGui::EndTable();
            }
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Authorization"))
        {
            ImGui::Text("Authorization goes here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Headers"))
        {
            ImGui::Text("headers go here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Body"))
        {
            ImGui::Text("Body goes here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Pre-Request Script"))
        {
            ImGui::Text("Pre-Requests Script goes here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Tests"))
        {
            ImGui::Text("Tests go here");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Settings"))
        {
            ImGui::Text("Settings go here");
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }
}

void GUI::render()
{
    // Main Workspace
    ImGui::BeginGroup();
    this->workspaceBar();
    ImGui::EndGroup();

    ImGui::NewLine();
    // Left Vertical
    ImGui::BeginGroup();
    {

        workspaceArea();

        // ImGui::Separator();
        // ImGui::SameLine();
    }

    ImGui::EndGroup();

    // pool.enqueue(&GUI::responseArea, this).get();
    ImGui::NewLine();
    responseArea();
}
void GUI::workspaceArea()
{
    if (ImGui::BeginTabBar("TabItem"))
    {
        if (ImGui::TabItemButton("+", ImGuiTabItemFlags_Trailing | ImGuiTabItemFlags_NoTooltip))
        {
            Tab t;
            tabs.push_back(t);
        }
        for (size_t n = 0; n < tabs.size(); n++)
        {
            if (ImGui::BeginTabItem(tabs.at(n).title.c_str(), &tabs.at(n).isOpen, ImGuiTabItemFlags_None))
            {
                active_tab = n;
                ImGui::InputText("URL", (char *)tabs.at(n).getUrl(), constants->MAX_URL_SIZE);
                ImGui::SameLine();
                if (ImGui::Button("Send"))
                {
                }
                ImGui::NewLine();
                this->tabConfig();
                ImGui::EndTabItem();
            }

            if (!tabs.at(n).isOpen)
            {
                tabs.erase(tabs.begin() + n);
            }
        }
        ImGui::EndTabBar();
    }
    
}