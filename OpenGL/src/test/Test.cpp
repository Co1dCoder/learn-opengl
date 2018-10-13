#include "test.h"
#include "imgui/imgui.h"

Test::TestMenu::TestMenu(Test *& currentTestPointer)
    : m_CurrentTest(currentTestPointer)
{
}

void Test::TestMenu::OnImGuiRender()
{
    for (auto& test : m_Tests) {
        if (ImGui::Button(test.first.c_str()))
            m_CurrentTest = test.second();
    }
}
