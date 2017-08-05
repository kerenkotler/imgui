/*! \file imgui_style.h
 *  \brief Enter description here.
 *  \author Georgi Gerganov
 */

#pragma once

#include "imgui.h"

namespace ImGui {

    enum StyleId {
        IMGUI_STYLE_DEFAULT,
        IMGUI_STYLE_TEAL_AND_ORANGE,
    };

    template <StyleId S>
        static bool applyStyle();

    template <>
        bool applyStyle<IMGUI_STYLE_DEFAULT>() {
            const ImGuiStyle defaultStyle;

            ImGuiStyle * style = &ImGui::GetStyle();
            *style = defaultStyle;

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_TEAL_AND_ORANGE>() {
            ImGuiStyle & style = ImGui::GetStyle();

            style.WindowPadding = ImVec2(8, 8);
            style.WindowRounding = 5.0f;
            style.FramePadding = ImVec2(4, 3);
            style.FrameRounding = 0.0f;
            style.ItemSpacing = ImVec2(8, 4);
            style.ItemInnerSpacing = ImVec2(4, 4);
            style.IndentSpacing = 21.0f;
            style.ScrollbarSize = 16.0f;
            style.ScrollbarRounding = 9.0f;
            style.GrabMinSize = 10.0f;
			style.GrabRounding = 3.0f;

			style.Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.24f, 0.41f, 0.41f, 1.00f);
			style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.06f, 0.05f, 0.07f, 0.90f);
			style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style.Colors[ImGuiCol_Border]                = ImVec4(0.78f, 0.51f, 0.00f, 1.00f);
			style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.00f, 0.39f, 0.39f, 0.39f);
			style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
			style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.00f, 0.50f, 0.50f, 0.24f);
			style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.50f, 0.50f, 1.00f);
			style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.00f, 0.50f, 0.50f, 1.00f);
			style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.00f, 0.50f, 0.50f, 1.00f);
			style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.10f, 0.27f, 0.27f, 1.00f);
			style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
			style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
			style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.00f, 0.39f, 0.39f, 0.39f);
			style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.80f, 0.80f, 0.83f, 0.39f);
			style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.80f, 0.80f, 0.83f, 0.39f);
			style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_Button]                = ImVec4(0.00f, 0.29f, 0.29f, 1.00f);
			style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
			style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_Header]                = ImVec4(0.79f, 0.51f, 0.00f, 0.39f);
			style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_Column]                = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
			style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
			style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
			style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
			style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
			style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 0.65f, 0.38f, 0.67f);
			style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
			style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(1.00f, 0.65f, 0.38f, 0.67f);
			style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
			style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
			style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(1.00f, 0.98f, 0.95f, 0.78f);

			return true;
		}

	static void renderStyleSelectorMenu() {
		ImGui::MenuItem("Default") && applyStyle<IMGUI_STYLE_DEFAULT>();
		ImGui::MenuItem("Teal and Orange") && applyStyle<IMGUI_STYLE_TEAL_AND_ORANGE>();
	}
}
